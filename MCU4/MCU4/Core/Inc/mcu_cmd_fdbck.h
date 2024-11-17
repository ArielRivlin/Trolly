/*
 * mcu_cmd_fdbck.h
 *
 *  Created on: Sep 2, 2024
 *      Author: Lenovo
 */

#ifndef APPLICATION_USER_MCU_CMD_FDBCK_H_
#define APPLICATION_USER_MCU_CMD_FDBCK_H_

#include "main.h"

HAL_StatusTypeDef Decode_MCU1_msg(uint8_t *buf);
uint8_t SendAckMCU1(uint8_t ack, uint8_t res);

#endif /* APPLICATION_USER_MCU_CMD_FDBCK_H_ */
