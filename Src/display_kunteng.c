/*
 * display_kunteng.c
 *
 *  Created on: 25.09.2019
 *      Author: Admin
 */

#include "main.h"
#include "CAN-Registers.h"
#include "display_kunteng.h"
#include "stm32f1xx_hal.h"

uint8_t ui8_tx_buffer[12];
uint8_t ui8_j;
uint8_t ui8_crc;
uint16_t ui16_wheel_period_ms =4500;
uint32_t ui32_battery_volts= 36;
uint8_t ui8_battery_soc = 12;
uint8_t ui16_error;
uint8_t ui8_rx_buffer[13];
uint8_t ui8_rx_buffer_counter = 0;
uint8_t ui8_byte_received;
uint8_t ui8_moving_indication = 0;
uint8_t ui8_UARTCounter = 0;
uint8_t ui8_msg_received=0;
uint8_t ui8_InitFlag=0;
uint8_t ui8_Initial_Max_Speed=0;
uint8_t ui8_Initial_Wheel_Size=0;
uint8_t ui8_Initial_Number_of_cells=0;
uint8_t ui8_Initial_Battery_Current_Max=0;
uint16_t ui16_wheel_circumference = 2200;
uint8_t ui8_Number_of_Cells[6]={10,13,0,0,0,0};
uint16_t ui16_Battery_Current_Max[8]={10000,12000,14000,16000,18000,20000,25000,30000};
uint16_t BATTERY_PACK_VOLTS_100;
uint16_t BATTERY_PACK_VOLTS_80;
uint16_t BATTERY_PACK_VOLTS_60;
uint16_t BATTERY_PACK_VOLTS_40;
uint16_t BATTERY_PACK_VOLTS_20;
uint16_t BATTERY_PACK_VOLTS_0;

volatile struc_lcd_configuration_variables lcd_configuration_variables;

UART_HandleTypeDef huart1;

uint16_t GetWheelCircumference(uint8_t Size);
void SetVoltagePercentage(uint8_t cells);

uint8_t GetRXBuffer(){
	return ui8_rx_buffer[0];
}

void kunteng_init()
{
//Start UART with DMA

  if (HAL_UART_Receive_DMA(&huart1, (uint8_t *)ui8_rx_buffer, 13) != HAL_OK)
  {
	   Error_Handler();
  }


}
void display_update(MotorState_t* MS_U)
{

  // prepare moving indication info
	// B7: moving indication info
	// (1 << 0) : none
	// (1 << 1): throttle
	// (1 << 2): none
	// (1 << 3): cruise control
	// (1 << 4): PAS
	// (1 << 5): brake
	// (1 << 6): none
	// (1 << 7): none
  ui8_moving_indication = 0;
  if (!MS_U->Brake||MS_U->Perma_Regen) { ui8_moving_indication |= (1 << 5); }
  //if (ebike_app_cruise_control_is_set ()) { ui8_moving_indication |= (1 << 3); }
  //if (throttle_is_set ()) { ui8_moving_indication |= (1 << 1); }
  //if (pas_is_set ()) { ui8_moving_indication |= (1 << 4); }




  // calc battery pack state of charge (SOC)
  ui32_battery_volts =  (MS_U->Voltage<<8)/1000;  //Spannung kommt in mV vom Motor (*256 für bessere Auflösung)
  if (ui32_battery_volts > ((uint16_t) BATTERY_PACK_VOLTS_80)) { ui8_battery_soc = 16; } // 4 bars | full
  else if (ui32_battery_volts > ((uint16_t) BATTERY_PACK_VOLTS_60)) { ui8_battery_soc = 12; } // 3 bars
  else if (ui32_battery_volts > ((uint16_t) BATTERY_PACK_VOLTS_40)) { ui8_battery_soc = 8; } // 2 bars
  else if (ui32_battery_volts > ((uint16_t) BATTERY_PACK_VOLTS_20)) { ui8_battery_soc = 4; } // 1 bar
  else { ui8_battery_soc = 3; } // empty

  if(MS_U->Speed>0)ui16_wheel_period_ms = 6600/MS_U->Speed; //(1000*60/9,091)/value of REG_MOTOR_STATUS_SPEED.
  else ui16_wheel_period_ms = 13200;

ui8_tx_buffer [0] = 65;
  // B1: battery level
  ui8_tx_buffer [1] = ui8_battery_soc;
  // B2: 24V controller
  ui8_tx_buffer [2] = (uint8_t) COMMUNICATIONS_BATTERY_VOLTAGE;
  // B3: speed, wheel rotation period, ms; period(ms)=B3*256+B4;
  ui8_tx_buffer [3] = (ui16_wheel_period_ms >> 8) & 0xff;
  ui8_tx_buffer [4] = (ui16_wheel_period_ms) & 0xff;



  // B5: error info display
  ui8_tx_buffer [5] = ui16_error;
  // B6: CRC: xor B1,B2,B3,B4,B5,B7,B8,B9,B10,B11
  // 0 value so no effect on xor operation for now
  ui8_tx_buffer [6] = 0;
  // B7: moving mode indication, bit
  // throttle: 2
  ui8_tx_buffer [7] = ui8_moving_indication;
  // B8: 4x controller current
  // Vbat = 30V:
  // - B8 = 255, LCD shows 1912 watts
  // - B8 = 250, LCD shows 1875 watts
  // - B8 = 100, LCD shows 750 watts
  // each unit of B8 = 0.25A


  //ui8_tx_buffer [8] =  (uint8_t)(((ui16_BatteryCurrent-ui16_current_cal_b+1)<<2)/current_cal_a);
  ui8_tx_buffer [8] =  (uint8_t)(MS_U->Power);   //Kalibrierung muß angepasst werden 13W pro digit
  // B9: motor temperature
  ui8_tx_buffer [9] = MS_U->MotorTemperature-15; //according to documentation at endless sphere
  // B10 and B11: 0
  ui8_tx_buffer [10] = 0;
  ui8_tx_buffer [11] = 0;

  // calculate CRC xor
  ui8_crc = 0;
  for (ui8_j = 1; ui8_j <= 11; ui8_j++)
  {
    ui8_crc ^= ui8_tx_buffer[ui8_j];
  }
  ui8_tx_buffer [6] = ui8_crc;

  // send the package over UART
  HAL_UART_Transmit_DMA(&huart1, (uint8_t *)&ui8_tx_buffer, 12);
}

/********************************************************************************************/
 // Process received package from the LCD
 //

 // see if we have a received package to be processed
void check_message(MotorState_t* MS_D)
 {
  //printf("Byte recieved \r\n");
  // validation of the package data
   ui8_crc = 0;

   for (ui8_j = 0; ui8_j <= 12; ui8_j++)
   {
       //putchar (ui8_j);
       //putchar (ui8_rx_buffer[ui8_j]);
     if (ui8_j == 5) continue; // don't xor B5 (B7 in our case)
     ui8_crc ^= ui8_rx_buffer[ui8_j];
   }

   // see if CRC is ok
   if (((ui8_crc ^ 10) == ui8_rx_buffer [5]) 	|| // some versions of CRC LCD5 (??)
	((ui8_crc ^ 5) == ui8_rx_buffer [5]) 	|| // CRC LCD3 (tested with KT36/48SVPR, from PSWpower)
	((ui8_crc ^ 9) == ui8_rx_buffer [5]) 	|| // CRC LCD5
	((ui8_crc ^ 2) == ui8_rx_buffer [5])) 	   // CRC LCD3
   { //printf("message valid \r\n");
     lcd_configuration_variables.ui8_assist_level = ui8_rx_buffer [1] & 7;
     lcd_configuration_variables.ui8_light = ui8_rx_buffer [1]>>7 & 1;
     lcd_configuration_variables.ui8_motor_characteristic = ui8_rx_buffer [3];
     lcd_configuration_variables.ui8_wheel_size = ((ui8_rx_buffer [4] & 192) >> 6) | ((ui8_rx_buffer [2] & 7) << 2);
     lcd_configuration_variables.ui8_max_speed = (10 + ((ui8_rx_buffer [2] & 248) >> 3)) | (ui8_rx_buffer [4] & 32);
     lcd_configuration_variables.ui8_power_assist_control_mode = ui8_rx_buffer [4] & 8;
     lcd_configuration_variables.ui8_P2 = ui8_rx_buffer [4] & 0x07;
     lcd_configuration_variables.ui8_P3 = ui8_rx_buffer [4]>>3 & 1;
     lcd_configuration_variables.ui8_P4 = ui8_rx_buffer [4]>>4 & 1;
     lcd_configuration_variables.ui8_controller_max_current = (ui8_rx_buffer [7] & 15); //unterste 4 Bits nach https://endless-sphere.com/forums/download/file.php?id=197184
     lcd_configuration_variables.ui8_C1 = ((ui8_rx_buffer [6]>>3) & 7); //Bit 3,4,5
     lcd_configuration_variables.ui8_C2 = ((ui8_rx_buffer [6]) & 7); //Bit 0,1,2
     MS_D->Assist_Level=lcd_configuration_variables.ui8_assist_level;
     MS_D->Gauge_Factor=lcd_configuration_variables.ui8_motor_characteristic;
     MS_D->Regen_Factor=lcd_configuration_variables.ui8_C1;
     MS_D->Gauge_Ext_Torq_Flag=lcd_configuration_variables.ui8_P3;
     MS_D->Throttle_Function=lcd_configuration_variables.ui8_P4;
     if(lcd_configuration_variables.ui8_light){
    	HAL_GPIO_WritePin(Light_GPIO_Port, Light_Pin, GPIO_PIN_SET);
     }
     else{
    	 HAL_GPIO_WritePin(Light_GPIO_Port, Light_Pin, GPIO_PIN_RESET);
     }
     // Send new settings to Motor Controller, if changed

     if(!ui8_InitFlag){
    	ui8_Initial_Max_Speed = lcd_configuration_variables.ui8_max_speed;
    	ui8_Initial_Wheel_Size = lcd_configuration_variables.ui8_wheel_size;
    	ui8_Initial_Number_of_cells = lcd_configuration_variables.ui8_P2;
    	ui8_Initial_Battery_Current_Max = lcd_configuration_variables.ui8_C2;
    	ui16_wheel_circumference = GetWheelCircumference(lcd_configuration_variables.ui8_wheel_size);
    	SetVoltagePercentage(lcd_configuration_variables.ui8_P2);
    	ui8_InitFlag=1;
     }
     else{
    	 if(ui8_Initial_Max_Speed != lcd_configuration_variables.ui8_max_speed){
    		 Send_CAN_Command(REG_MOTOR_PROTECT_UNLOCK , MOTOR_PROTECT_UNLOCK_KEY);
    		 Send_CAN_Command(REG_MOTOR_ASSIST_MAXSPEED, lcd_configuration_variables.ui8_max_speed);
    		 ui8_Initial_Max_Speed = lcd_configuration_variables.ui8_max_speed;
    	 }
    	 if(ui8_Initial_Wheel_Size != lcd_configuration_variables.ui8_wheel_size){
    		 ui16_wheel_circumference = GetWheelCircumference(lcd_configuration_variables.ui8_wheel_size);
    		 Send_CAN_Command(REG_MOTOR_PROTECT_UNLOCK , MOTOR_PROTECT_UNLOCK_KEY);
    		 Send_CAN_Command(REG_MOTOR_GEOMETRY_CIRC_HI, (ui16_wheel_circumference>>8));
    		 Send_CAN_Command(REG_MOTOR_GEOMETRY_CIRC_LO, (ui16_wheel_circumference & 0xFF));
    		 ui8_Initial_Wheel_Size = lcd_configuration_variables.ui8_wheel_size;
    	 }
    	 if(ui8_Initial_Battery_Current_Max != lcd_configuration_variables.ui8_C2){
    		 Send_CAN_Command(REG_MOTOR_PROTECT_UNLOCK , MOTOR_PROTECT_UNLOCK_KEY);
    		 Send_CAN_Command(REG_MOTOR_CONFIG_MAX_DISCHARGE_HI, (ui16_Battery_Current_Max[lcd_configuration_variables.ui8_C2]>>8));
    		 Send_CAN_Command(REG_MOTOR_CONFIG_MAX_DISCHARGE_LO, (ui16_Battery_Current_Max[lcd_configuration_variables.ui8_C2] & 0xFF));
    		 ui8_Initial_Battery_Current_Max = lcd_configuration_variables.ui8_C2;
    	 }
    	 if(ui8_Initial_Number_of_cells != lcd_configuration_variables.ui8_P2){
    		 SetVoltagePercentage(lcd_configuration_variables.ui8_P2);
    		 ui8_Initial_Number_of_cells = lcd_configuration_variables.ui8_P2;
    	 }

     }
     display_update(MS_D);
   }

   //HAL_UART_Transmit_DMA(&huart1, (uint8_t *)&ui8_rx_buffer, 13);
 }

void SetVoltagePercentage(uint8_t cells){
BATTERY_PACK_VOLTS_100 = (uint16_t)(LI_ION_CELL_VOLTS_100 * (float)ui8_Number_of_Cells[cells]*256.0);
BATTERY_PACK_VOLTS_80 =	(uint16_t)(LI_ION_CELL_VOLTS_80 * (float)ui8_Number_of_Cells[cells]*256.0);
BATTERY_PACK_VOLTS_60 = (uint16_t)(LI_ION_CELL_VOLTS_60 * (float)ui8_Number_of_Cells[cells]*256.0);
BATTERY_PACK_VOLTS_40 =	(uint16_t)(LI_ION_CELL_VOLTS_40 * (float)ui8_Number_of_Cells[cells]*256.0);
BATTERY_PACK_VOLTS_20 =	(uint16_t)(LI_ION_CELL_VOLTS_20 * (float)ui8_Number_of_Cells[cells]*256.0);
BATTERY_PACK_VOLTS_0 =	(uint16_t)(LI_ION_CELL_VOLTS_0 * (float)ui8_Number_of_Cells[cells]*256.0);
}

uint16_t GetWheelCircumference(uint8_t Size){
    /*
    wheel size:
    0x0e-10",	798
	0x02-12",	958
	0x06-14",	1117
    0x00-16",	1277
    0x04-18",	1436
    0x08-20",	1596
    0x0c-22",	1756
    0x10-24",	1915
    0x14"-26",	2075
    0x18-700c	2234
     */
	switch (Size) {

		case 0x0E:
			return 798;
			break;

		case 0x02:
			return 958;
			break;

		case 0x06:
			return 1117;
			break;

		case 0x00:
			return 1277;
			break;

		case 0x04:
			return 1436;
			break;

		case 0x08:
			return 1596;
			break;

		case 0x0C:
			return 1756;
			break;

		case 0x10:
			return 1915;
			break;

		case 0x14:
			return 2075;
			break;

		case 0x18:
			return 2234;
			break;

		default:
			return 2200;
			break;

	}
}
