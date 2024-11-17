/*
 * icd.h
 *
 *  Created on: Aug 27, 2024
 *      Author: Lenovo
 */

#ifndef INC_ICD_H_
#define INC_ICD_H_

#define START_BYTE	0x55
#define MCU1_MSG_LENGTH	8

typedef struct _cpr_msg
{
	uint8_t start_byte;
	uint8_t cmd;
	uint8_t crc;
	uint32_t param;
}CPR_MSG;


typedef enum _CPR_CMD
{
	EN_5_V = 0,
	EN_12_V,
	EN_DEF_V,
	GET_PWR_STATUS,
	SET_M_COMP_ON,
	SET_M_COMP_OFF,
	SET_M_COMP_HOME,
	SET_M_UP_DOWN_ON,
	SET_M_UP_DOWN_OFF,
	SET_M_ROT_LEG_ON,
	SET_M_ROT_LEG_OFF,
	SET_M_ELEVATOR_ON,
	SET_M_LEFT_RIGHT_ON,
	SET_M_LEFT_RIGHT_OFF,
	SET_M_ROT_FOOT_L_R_ON,
	SET_M_ROT_FOOT_L_R_OFF,
	SET_SOLENOID1_ON,
	SET_SOLENOID1_OFF,
	SET_SOLENOID2_ON,
	SET_SOLENOID2_OFF,
	SET_SOLENOID3_ON,
	SET_SOLENOID3_OFF,
	SET_SOLENOID4_ON,
	SET_SOLENOID4_OFF,
	SET_BLOWER_ON,
	SET_BLOWER_OFF,
	SET_AIR_PUMP_ON,
	SET_AIR_PUMP_OFF,
	TR_SET_M_ELECTRODES_ON,
	TR_SET_M_ELECTRODES_OFF,
	TR_SET_SOLENOID_ON,
	TR_SET_SOLENOID_OFF,
	TR_HEARTBEAT,
	ACK_TR_HEARTBEAT,
	ACK_TR_START_ELECTRODES,
	ACK_TR_ELECTRODES_ERROR,
	ACK_TR_ELECTRODES_DONE,
	ACK_TR_HANDLE_ON,
	ACK_TR_OUT,
	ACK_TR_BIT_ERROR,

}CPR_CMD;

#endif /* INC_ICD_H_ */
