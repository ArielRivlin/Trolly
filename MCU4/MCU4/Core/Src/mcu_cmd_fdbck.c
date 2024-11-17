/*
 * mcu_cmd_fdbck.c
 *
 *  Created on: Sep 2, 2024
 *      Author: Lenovo
 */

#include "mcu_cmd_fdbck.h"
#include "icd.h"
#include <string.h>
#include "tr_m_electrodes.h"


extern UART_HandleTypeDef huart1;
extern uint8_t direction;


/*
 * @brief		decode messages from MCU1
 * @param[in]	uint8_t *buf - buffer from MCU1
 * @retval		HAL_OK = 0, HAL_ERROR = 1;
 */

HAL_StatusTypeDef Decode_MCU1_msg(uint8_t *buf)
{
	uint8_t res = HAL_OK;

	CPR_MSG msg;
	uint8_t chksm = 0;

	chksm += buf[1];
	chksm += buf[3];
	chksm += buf[4];
	chksm += buf[5];
	chksm += buf[6];

	if(chksm == buf[2])
	{
		memcpy(&msg, buf, sizeof(msg));

		switch(msg.cmd)
		{
		case TR_SET_M_ELECTRODES_ON:
			if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10) == GPIO_PIN_SET)
			{
				res = Start_TR_Electrodes_Motor(0xFF, direction);

				res = SendAckMCU1(ACK_TR_START_ELECTRODES, 0);
			}
			break;

		case TR_SET_M_ELECTRODES_OFF:
			res = Stop_TR_Electrodes_Motor();
			break;

		case TR_SET_SOLENOID_ON:
			res = TR_Open_Solenoid(0);
			break;

		case TR_SET_SOLENOID_OFF:
			res = TR_Close_Solenoid();
			break;
		}

	}

	return res;
}


uint8_t SendAckMCU1(uint8_t ack, uint8_t res)
{
	  CPR_MSG tmsg;
	  tmsg.start_byte = START_BYTE;
	  tmsg.cmd = ack;
	  tmsg.param = res;
	  tmsg.crc = tmsg.cmd + ((tmsg.param & 0xFF000000)>>24) + ((tmsg.param & 0x00FF0000)>>16) +
			  ((tmsg.param & 0x0000FF00)>>8) + (tmsg.param & 0x000000FF);

	  uint8_t buf[MCU1_MSG_LENGTH] = {0};

	  buf[0] = tmsg.start_byte;
	  buf[1] = tmsg.cmd;
	  buf[2] = tmsg.crc;
	  buf[3] = (tmsg.param & 0xFF000000)>>24;
	  buf[4] = (tmsg.param & 0x00FF0000)>>16;
	  buf[5] = (tmsg.param & 0x0000FF00)>>8;
	  buf[6] = (tmsg.param & 0x000000FF);

	  res = HAL_UART_Transmit(&huart1, buf, sizeof(buf), 100);

	  return res;

}
