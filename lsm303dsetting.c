#include "lsm303dsetting.h"

void SG_lsm303d_init(){ //checking if the sensor is on the line
	volatile uint8_t regData;
	I2C1->CR1 |= I2C_CR1_PE;
	// start signal generation
	I2C1->CR1 |= I2C_CR1_START;
	while (!(I2C1->SR1 & I2C_SR1_SB)){}
	(void) I2C1->SR1;
	I2C1->DR = LSM303D_WRITE_ADDRESS;
	while (!(I2C1->SR1 & I2C_SR1_ADDR))
	{
	  if (I2C1->SR1 & I2C_SR1_AF){
		  //Huston, this sensor is not present!!!
		  break;
		}
	}
	if (I2C1->SR1 & I2C_SR1_AF){
		  while(1); //we have nothing left to do here
	}
	(void) I2C1->SR1;
	(void) I2C1->SR2;
	I2C1->DR = LSM303D_WHO_AM_I;
	while (!(I2C1->SR1 & I2C_SR1_BTF));
	I2C1->CR1 |= I2C_CR1_STOP;
	I2C1->CR1 |= I2C_CR1_START;
	// We are waiting for the end of the formation of the signal "Restart"
	while (!(I2C1->SR1 & I2C_SR1_SB));
	// pass slave address + read
	I2C1->DR = LSM303D_READ_ADDRESS;
	// waiting for the end of the transfer of the address
	while (!(I2C1->SR1 & I2C_SR1_ADDR));
	(void) I2C1->SR1;
	(void) I2C1->SR2;
	// waiting for the end of data reception
	while (!(I2C1->SR1 & I2C_SR1_RXNE));
	// read received value
	regData = I2C1->DR;
	I2C1->CR1 |= I2C_CR1_STOP;
}

void SG_Configure_LSM303D(void){ //sensor setting
	SG_I2C_Write_Register(LSM303D_WRITE_ADDRESS,LSM303D_CTRL2,LSM303D_CLTR2_OPT);
	HAL_Delay(1);
	SG_I2C_Write_Register(LSM303D_WRITE_ADDRESS,LSM303D_CTRL1,LSM303D_CTRL1_OPT);
	HAL_Delay(1);
	SG_I2C_Write_Register(LSM303D_WRITE_ADDRESS,LSM303D_CTRL5,LSM303D_CTRL5_OPT);
	HAL_Delay(1);
	SG_I2C_Write_Register(LSM303D_WRITE_ADDRESS,LSM303D_CTRL6,LSM303D_CTRL6_OPT);
	HAL_Delay(1);
	SG_I2C_Write_Register(LSM303D_WRITE_ADDRESS,LSM303D_CTRL7,LSM303D_CTRL7_OPT);
}

void SG_Get_ValueLSM303D(uint8_t *data){ //pointer to array to write data
	data[0]=0xAA;
	data[1]=0xBB;
//Temperature
	data[2]=SG_I2C_Read_Register(LSM303D_READ_ADDRESS,LSM303D_TEMP_OUT_L);
	data[3]=SG_I2C_Read_Register(LSM303D_READ_ADDRESS,LSM303D_TEMP_OUT_H);
//Accelerom
	data[4]=SG_I2C_Read_Register(LSM303D_READ_ADDRESS,LSM303D_OUT_X_L_A);
	data[5]=SG_I2C_Read_Register(LSM303D_READ_ADDRESS,LSM303D_OUT_X_H_A);
	data[6]=SG_I2C_Read_Register(LSM303D_READ_ADDRESS,LSM303D_OUT_Y_L_A);
	data[7]=SG_I2C_Read_Register(LSM303D_READ_ADDRESS,LSM303D_OUT_Y_H_A);
	data[8]=SG_I2C_Read_Register(LSM303D_READ_ADDRESS,LSM303D_OUT_Z_L_A);
	data[9]=SG_I2C_Read_Register(LSM303D_READ_ADDRESS,LSM303D_OUT_Z_H_A);
//Magnetom
	data[10]=SG_I2C_Read_Register(LSM303D_READ_ADDRESS,LSM303D_OUT_X_H_M);
	data[11]=SG_I2C_Read_Register(LSM303D_READ_ADDRESS,LSM303D_OUT_X_L_M);
	data[12]=SG_I2C_Read_Register(LSM303D_READ_ADDRESS,LSM303D_OUT_Y_H_M);
	data[13]=SG_I2C_Read_Register(LSM303D_READ_ADDRESS,LSM303D_OUT_Y_L_M);
	data[14]=SG_I2C_Read_Register(LSM303D_READ_ADDRESS,LSM303D_OUT_Z_H_M);
	data[15]=SG_I2C_Read_Register(LSM303D_READ_ADDRESS,LSM303D_OUT_Z_L_M);
}