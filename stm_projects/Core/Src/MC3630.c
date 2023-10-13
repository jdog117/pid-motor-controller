/*
 * MC3630.c
 *
 *  Created on: Oct 8, 2023
 *      Author: Joey Casey
 *
 *      MC3630 Accelerometer I2C driver
 */

#include "MC3630.h"
#include "stm32c0xx_hal.h"


HAL_StatusTypeDef MC3630_ReadRegiser(MC3630 *dev, uint8_t reg, uint8_t *data) {
	return HAL_I2C_Mem_Read(hi2c, DevAddress, MemAddress, MemAddSize, pData, Size, Timeout)
}




