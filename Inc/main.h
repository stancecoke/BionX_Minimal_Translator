/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Onboard_LED_Pin GPIO_PIN_13
#define Onboard_LED_GPIO_Port GPIOC

#define Throttle_Pin GPIO_PIN_3
#define Throttle_GPIO_Port GPIOA

#define Torque_Pin GPIO_PIN_1
#define Torque_GPIO_Port GPIOA

#define BatteryVoltage_Pin GPIO_PIN_0
#define BatteryVoltage_GPIO_Port GPIOA

#define BatteryCurrent_Pin GPIO_PIN_2
#define BatteryCurrent_GPIO_Port GPIOA

#define Light_Pin GPIO_PIN_3
#define Light_GPIO_Port GPIOB

#define Brake_Pin GPIO_PIN_1
#define Brake_GPIO_Port GPIOB

#define PAS_Pin GPIO_PIN_0 //for Exti0 interrupt. Px0 lines have to be considered, https://stm32f4-discovery.net/2014/08/stm32f4-external-interrupts-tutorial/
#define PAS_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
#define CAL_BAT_V 1
#define PULSES_PER_REVOLUTION 1

typedef struct
{

	uint32_t       	Voltage;
	uint16_t       	Speed;
	uint16_t        Power;
	uint32_t        Gauge_Factor;
	uint8_t         Brake;
	uint8_t         Throttle_Function;
	uint8_t         Perma_Regen;
	uint8_t         Regen_Factor;
	uint32_t        Battery_Current;
	uint8_t 		Gauge_Ext_Torq_Flag;
	uint8_t 		MotorTemperature;
	uint8_t 		Assist_Level;
	uint16_t 		Min_Voltage;
	uint16_t 		Max_Voltage;

}MotorState_t;

void Send_CAN_Request(uint8_t command);
void Send_CAN_Command(uint8_t function, uint16_t value);

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
