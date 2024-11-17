/*
 * bit.h
 *
 *  Created on: Nov 5, 2024
 *      Author: Lenovo
 */

#ifndef INC_BIT_H_
#define INC_BIT_H_

#include "main.h"

typedef union BitStatus_u
{
	struct bitValues_s
	{
		uint8_t isIMot;
		uint8_t isISol;
		uint8_t isEEPROM;
	}bitValues_s;
	uint8_t bitValues_a[3];
}
BitStatus;


uint8_t startBit();
uint8_t concurrentBit();

#endif /* INC_BIT_H_ */
