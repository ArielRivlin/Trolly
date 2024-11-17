/*
 * bit.c
 *
 *  Created on: 05.11.2024
 *      Author: Baych Igor
 */

#include <string.h>
#include <math.h>
#include "bit.h"

// == vbat ==
#define k_vbat	0.0886 // ((3.3/4095)*((100+10)/10)) *10
// == end vbat ==
// == isens ==
#define k_isens	0.134  // (((3.3/4095)/3000)*5000)  *100
// == end isens ==

__IO uint16_t adc_value[3];  // array to store the adc values

extern ADC_HandleTypeDef hadc1;

BitStatus bitStatus;

uint8_t VBat_err = 0;


uint8_t startBit()
{
	uint8_t ret = 0;

// ================ EEPROM ===================

//	ret = isEEPROMReady();
//	if(ret != HAL_OK)
//	{
//		// TODO EEPROM error handle
//		bitStatus.bitValues_s.isEEPROM = 1;
//	}
//	else if(ret == HAL_OK)
//    {
//    	ret = EEPROM_ReadByte(EEEPROM_TFLAG_ADDRESS, &r_flag);
//    	if(ret == HAL_OK && r_flag == 0x01)
//    	{
//    		ret = EEPROM_ReadBuffer(EEEPROM_TID_ADDRESS, r_data, sizeof(r_data), 100);
//    	}
//    }
// ============================================

// ================ Vbat ===================
	uint16_t Vbat = ceil(adc_value[0] * (float)k_vbat);

// ============================================

// ================ I_Sens_Motor ===================
	uint16_t IMot = ceil(adc_value[1] * (float)k_isens);

	if(IMot < 0)
	{
		bitStatus.bitValues_s.isIMot = 1;
	}

// ============================================

// ================ I_Sens_Solenoid ===================
	uint16_t ISol = ceil(adc_value[2] * (float)k_isens);

	if(ISol < 0)
	{
		bitStatus.bitValues_s.isISol = 1;
	}

// ============================================

	for(int i = sizeof(bitStatus.bitValues_s); i != 0; i-- )
	{
		if(bitStatus.bitValues_a[i] == 1)
		{
			ret = 1;
			break;
		}
	}


	return ret;
}

uint8_t concurrentBit()
{
	uint8_t ret = 0;

	memset(bitStatus.bitValues_a, 0, sizeof(bitStatus.bitValues_a));

	// ================ I_Sens_Motor ===================
		uint16_t IMot = ceil(adc_value[1] * (float)k_isens);

		if(IMot < 0)
		{
			bitStatus.bitValues_s.isIMot = 1;
		}

	// ============================================

	// ================ I_Sens_Solenoid ===================
		uint16_t ISol = ceil(adc_value[2] * (float)k_isens);

		if(ISol < 0)
		{
			bitStatus.bitValues_s.isISol = 1;
		}

	// ============================================

		for(int i = sizeof(bitStatus.bitValues_s); i != 0; i-- )
		{
			if(bitStatus.bitValues_a[i] == 1)
			{
				ret = 1;
				break;
			}
		}


	return ret;
}

