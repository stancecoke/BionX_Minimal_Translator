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
#define Board_LED_Pin GPIO_PIN_13
#define Board_LED_GPIO_Port GPIOC
#define BatteryVoltage_Pin GPIO_PIN_0
#define BatteryVoltage_GPIO_Port GPIOA
#define BatteryCurrent_Pin GPIO_PIN_1
#define BatteryCurrent_GPIO_Port GPIOA
#define TorqueFromExternalSensor_Pin GPIO_PIN_2
#define TorqueFromExternalSensor_GPIO_Port GPIOA
#define PASFromExternalSensor_Pin GPIO_PIN_3
#define PASFromExternalSensor_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

#include <stdint.h>
#define CAL_BAT_V 1
#define PULSES_PER_REVOLUTION 1

typedef struct
{

	uint32_t       	Voltage;
	uint32_t       	Speed;
	uint32_t          	i_d;
	uint32_t          	i_q;
	uint32_t          	u_d;
	uint32_t          	u_q;
	uint32_t          	u_abs;
	uint32_t          	Battery_Current;
	uint8_t 		hall_angle_detect_flag;
	uint8_t 		char_dyn_adc_state;
	uint8_t 		assist_level;

}MotorState_t;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
