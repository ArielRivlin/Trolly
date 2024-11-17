/*
 * m_ud_left_right.c
 *
 *  Created on: Sep 3, 2024
 *      Author: Lenovo
 */

#include "main.h"
#include "tr_m_electrodes.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim8;


HAL_StatusTypeDef Init_TR_Electrodes_Motor()
{
	uint8_t res = HAL_OK;

	  return res;
}

/*
 * @brief		start left motor for up and down
 * @param[in]	uint32_t speed
 * @retval		HAL_OK = 0, HAL_ERROR = 1;
 */

HAL_StatusTypeDef Start_TR_Electrodes_Motor(uint32_t speed, uint8_t direction)
{
	uint8_t res = HAL_OK;

  // ===== Left up down motor =====
//	HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL);

	// == set IN1 to 1 - forward rotation, 0 - reverse rotation ==
	res = HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);

	TIM1->CCR1 = 255; // left up down motor speed

  // == set IN2 to 0 - forward rotation, 1 - reverse rotation ==
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_SET);

  HAL_Delay(2);

  TIM1->CCR1 = speed; // left up down motor speed

  if(!direction)
  {
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_RESET);
  }
  else
  {
	  res = HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
  }



  // ===== end left up down motor =====

  return res;

}

/*
 * @brief		stop left motor for up and down
 * @param[in]	none
 * @retval		HAL_OK = 0, HAL_ERROR = 1;
 */

HAL_StatusTypeDef Stop_TR_Electrodes_Motor()
{
	uint8_t res = HAL_OK;

  // ===== Left up down motor =====
//  HAL_TIM_Encoder_Stop(&htim3, TIM_CHANNEL_ALL);

  // == set IN1 to 0 - Brake Low; Slow Decay ==

  TIM1->CCR1 = 255; // left up down motor speed

  // == set IN2 to 0 - Brake Low; Slow Decay ==
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_SET);

  HAL_Delay(100);

  HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_RESET);
  // ===== end left up down motor =====

  return res;
}

/*
 * @brief		start right motor for up and down
 * @param[in]	uint32_t speed
 * @retval		HAL_OK = 0, HAL_ERROR = 1;
 */

HAL_StatusTypeDef TR_Open_Solenoid(uint8_t direction)
{
	uint8_t res = HAL_OK;

  // ===== Right up down motor =====
//  HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);

  // == set IN1 to 1 - forward rotation ==
  res = HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_1);
  TIM8->CCR1 = 255; // left up down motor speed

  // == set IN2 to 0 - forward rotation ==
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);

  HAL_Delay(2);

  TIM8->CCR1 = 255; // left up down motor speed

  if(!direction)
  {
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
  }
  else
  {
	  res = HAL_TIM_PWM_Stop(&htim8, TIM_CHANNEL_1);
  }

  // ===== end right up down motor =====

  return res;

}

/*
 * @brief		stop right motor for up and down
 * @param[in]	none
 * @retval		HAL_OK = 0, HAL_ERROR = 1;
 */

HAL_StatusTypeDef TR_Close_Solenoid()
{
	uint8_t res = HAL_OK;

  // ===== Right up down motor =====
//  HAL_TIM_Encoder_Stop(&htim4, TIM_CHANNEL_ALL);

  // == set IN1 to 0 - Brake Low; Slow Decay ==
//  HAL_TIM_PWM_Start(&htim17, TIM_CHANNEL_1);
  TIM8->CCR1 = 255; // left up down motor speed

  // == set IN2 to 0 - Brake Low; Slow Decay ==
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);

  HAL_Delay(100);

  HAL_TIM_PWM_Stop(&htim8, TIM_CHANNEL_1);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);

  // ===== end right up down motor =====

  return res;
}

//uint32_t Encoder_TR_Electrodes_Motor()
//{
//	return ((TIM3->CNT)>>1);
//}
