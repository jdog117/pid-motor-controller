/*
 * MC3630.c
 *
 *  Created on: Oct 8, 2023
 *      Author: Joey Casey
 *
 *      MC3630 Accelerometer I2C driver
 */
#include "MC3630.h"



uint8_t MC3630_Initialize(MC3630 *dev, I2C_HandleTypeDef *i2cHandle) {

	/* Set struct parameters */
	dev->i2cHandle   = i2cHandle;
	dev->acc_mps2[0] = 0.0f;
	dev->acc_mps2[1] = 0.0f;
	dev->acc_mps2[2] = 0.0f;

	//number of transaction errors
	uint8_t errNum = 0;
	HAL_StatusTypeDef status;

	uint8_t regData;

	/* Check device ID */
	status = MC3630_ReadRegiser(dev, MC3630_DEVID_AD, &regData); //store contents of register in regData
	errNum += (status != HAL_OK); //add 1 to errors if the status is not ok

	if (regData != MC3630_DEV_ID) {
		return 255; //can't find device
	}

}

/*
 * REGISTER FUCNTIONS
 */

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
