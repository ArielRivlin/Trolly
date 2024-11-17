/*
 * m_ud_left_right.h
 *
 *  Created on: Sep 3, 2024
 *      Author: Lenovo
 */

#ifndef APPLICATION_USER_M_UD_LEFT_RIGHT_H_
#define APPLICATION_USER_M_UD_LEFT_RIGHT_H_

#include "main.h"

HAL_StatusTypeDef Init_TR_Electrodes_Motor();

/*
 * @brief		start left motor for up and down
 * @param[in]	none
 * @retval		HAL_OK = 0, HAL_ERROR = 1;
 */

HAL_StatusTypeDef Start_TR_Electrodes_Motor(uint32_t speed, uint8_t direction);

/*
 * @brief		stop left motor for up and down
 * @param[in]	none
 * @retval		HAL_OK = 0, HAL_ERROR = 1;
 */

HAL_StatusTypeDef Stop_TR_Electrodes_Motor();

/*
 * @brief		start right motor for up and down
 * @param[in]	none
 * @retval		HAL_OK = 0, HAL_ERROR = 1;
 */

HAL_StatusTypeDef TR_Open_Solenoid(uint8_t direction);

/*
 * @brief		stop right motor for up and down
 * @param[in]	none
 * @retval		HAL_OK = 0, HAL_ERROR = 1;
 */

HAL_StatusTypeDef TR_Close_Solenoid();


uint32_t Encoder_TR_Electrodes_Motor();


#endif /* APPLICATION_USER_M_UD_LEFT_RIGHT_H_ */
