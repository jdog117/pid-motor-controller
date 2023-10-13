/*
 * MC3630.c
 *
 *  Created on: Oct 8, 2023
 *      Author: Joey Casey
 *
 *      MC3630 Accelerometer I2C driver
 */

#include "MC3630.h"


HAL_StatusTypeDef MC3630_ReadRegiser(MC3630 *dev, uint8_t reg, uint8_t *data) {
	//DevAddress is the device address shifted by 1
	//reads 1 byte of data
	return HAL_I2C_Mem_Read(dev->i2cHandle, MC3630_I2C_ADDR, reg, I2C_MEMADD_SIZE_8BIT, data, 1, HAL_MAX_DELAY);
}

HAL_StatusTypeDef MC3630_ReadRegisers(MC3630 *dev, uint8_t reg, uint8_t *data, uint8_t length) {
	//DevAddress is the device address shifted by 1
	//reads 1 byte of data
	return HAL_I2C_Mem_Read(dev->i2cHandle, MC3630_I2C_ADDR, reg, I2C_MEMADD_SIZE_8BIT, data, length, HAL_MAX_DELAY);
}


HAL_StatusTypeDef MC3630_WriteRegiser(MC3630 *dev, uint8_t reg, uint8_t *data) {
	return HAL_I2C_Mem_Write(dev->i2cHandle, MC3630_I2C_ADDR, reg, I2C_MEMADD_SIZE_8BIT, data, 1, HAL_MAX_DELAY);
}
