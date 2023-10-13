/*
 * MC3630.h
 *
 *  Created on: Oct 8, 2023
 *      Author: jspca
 */
#ifndef MC3630_I2C_DRIVER_H
#define MC3630_I2C_DRIVER_H

#include "stm32c0xx_hal.h" //HAL functions needed for this driver




/*
 * After startup, the first first transaction must be to select the interface type, I2C
 *
 * Write to 0x1 into register 0x0D[6] for I2C (p.270)
 * The I2C device address depends upon the state of pin DOUT_A1 during power-up (GND for I2C which means 7-bit device id is Ox4C (0b1001100)) (p.27)
 */

#define MC3630_I2C_ADDR (Ox4C << 1) //this 8 bit packet is shifted to the left by 1 bit because the the MC3630 uses the 8th bit for read or write, address is only 7bits

/*
 *   p.34 for register map
 */
#define MC3630_DEVID_AD 0x18 //device id register address
#define MC3630_DEV_ID 0x71   //default value in register (POR)

/*
 * register addresses
 */

#define MC3630_REG_XOUT_LSB 0x02
#define MC3630_REG_XOUT_MSB 0x03
#define MC3630_REG_YOUT_LSB 0x04
#define MC3630_REG_YOUT_MSB 0x05
#define MC3630_REG_ZOUT_LSB 0x06
#define MC3630_REG_ZOUT_MSB 0x07


//mc3630 struct
typedef struct {

	//I2C_TypeDef contains configuration information for a specified I2C
	I2C_HandleTypeDef *i2cHandle;

	//acceleration data
	/* CHANGE */
	float acc_mps2[2]; //x, y, or z depending on orientation
} MC3630;


/*
 * INITIALIZATION
 * returns a uint8_t 0-255
 */

uint8_t MC3630_Initialize(MC3630 *dev, I2C_HandleTypeDef *i2cHandle); //passing the struct as a pointer and the I2C handle


/*
 * RETRIEVE DATA
 * return as HAL_StatusTypeDef
 */

HAL_StatusTypeDef MC3630_Read_Acc(MC3630 *dev);

/*
 * REGISTER ACCESS
 * */

// reg is the register, *data is the address where stored
HAL_StatusTypeDef MC3630_ReadRegiser(MC3630 *dev, uint8_t reg, uint8_t *data); // 1 byte
HAL_StatusTypeDef MC3630_ReadRegisers(MC3630 *dev, uint8_t reg, uint8_t *data, uint8_t length); //reads from multiple registers (multiple byte)

// *data is the byte to be written
HAL_StatusTypeDef MC3630_WriteRegister(MC3630 *dev, uint8_t reg, uint8_t *data);



#endif /* INC_MC3630_H_ */
