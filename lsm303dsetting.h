#ifndef INC_LSM303DSETTING_H_
#define INC_LSM303DSETTING_H_

#include "stm32f1xx_hal.h"
#include "sg_stm32f1_i2c.h"
#include "SG_Delay.h"

#define LSM303D_PRD_ID          0x49  // LSM303D responds with 0x49
#define LSM303D_POWER_MODE_NORMAL    0x00  // sensor default power mode
#define LSM303D_TEMP_OUT_L      0x05    // Sensor temperature data register (read-only) LSB
#define LSM303D_TEMP_OUT_H      0x06    // Sensor temperature data register (read-only) MSB
#define LSM303D_STATUS_M        0x07    // Sensor magnetic status register (read-only)
#define LSM303D_OUT_X_L_M       0x08    // X-axis magnetic data register (read-only) LSB
#define LSM303D_OUT_X_H_M       0x09    // X-axis magnetic data register (read-only) MSB
#define LSM303D_OUT_Y_L_M       0x0A    // Y-axis magnetic register (read-only) LSB
#define LSM303D_OUT_Y_H_M       0x0B    // Y-axis magnetic data register (read-only) MSB
#define LSM303D_OUT_Z_L_M       0x0C    // Z-axis magnetic data register (read-only) LSB
#define LSM303D_OUT_Z_H_M       0x0D    // Z-axis magnetic data register (read-only) MSB
#define LSM303D_WHO_AM_I        0x0F    // Product ID register (read-only, aka WHO_AM_I)
#define LSM303D_CTRL0           0x1F    // rw
#define LSM303D_CTRL1           0x20    // rw
#define LSM303D_CTRL1_OPT       0x57    // 50Hz
#define LSM303D_CTRL2           0x21    // rw
#define LSM303D_CLTR2_OPT       0x20 //+-16g
#define LSM303D_CTRL3           0x22    // rw
#define LSM303D_CTRL4           0x23    // rw
#define LSM303D_CTRL5           0x24    // rw
#define LSM303D_CTRL5_OPT       0xE4    // temp on,modr 6,25Hz
#define LSM303D_CTRL6           0x25    // rw
#define LSM303D_CTRL6_OPT       0x40    // +-8g
#define LSM303D_CTRL7           0x26    // rw
#define LSM303D_CTRL7_OPT       0x00    // setting
#define LSM303D_STATUS_A        0x27    // Sensor acceleration status register (read-only)
#define LSM303D_OUT_X_L_A       0x28    // X-axis acceleration data register (read-only) LSB
#define LSM303D_OUT_X_H_A       0x29    // X-axis acceleration data register (read-only) MSB
#define LSM303D_OUT_Y_L_A       0x2A    // Y-axis acceleration data register (read-only) LSB
#define LSM303D_OUT_Y_H_A       0x2B    // Y-axis acceleration data register (read-only) MSB
#define LSM303D_OUT_Z_L_A       0x2C    // Z-axis acceleration data register (read-only) LSB
#define LSM303D_OUT_Z_H_A       0x2D    // Z-axis acceleration data register (read-only) MSB
#define LSM303D_WRITE_ADDRESS       0x3C    // device write address
#define LSM303D_READ_ADDRESS        0x3D    // device read address


void SG_lsm303d_init();
void SG_Configure_LSM303D(void);
void SG_Get_ValueLSM303D(uint8_t *data);
#endif /* INC_LSM303DSETTING_H_ */