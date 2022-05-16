/******************************************************************************
 * Module: MPU6050
 *
 * File Name: MPU6050_Regs.h
 *
 * Description: Header file for MPU6050 Registers Definitions.
 *
 * Author: Eslam - Taha - Sara
 ******************************************************************************/

#ifndef INC_MPU6050_REGS_H_
#define INC_MPU6050_REGS_H_

#include "Std_Types.h"

/*
 * Definitions for WHO AM I Register
 */

#define MPU6050_WHO_AM_I_REG            0x75


/*
 * Definitions for Self Tests Registers
 */
#define MPU6050_SELF_TEST_X_REG         0x0D
#define MPU6050_SELF_TEST_Y_REG         0x0E
#define MPU6050_SELF_TEST_Z_REG         0x0F
#define MPU6050_SELF_TEST_A_REG         0x10


/*
 * Definitions for MPU6050 Configuration Registers
 */
#define MPU6050_SMPLRT_DIV_REG          0x19
#define MPU6050_CONFIG_REG              0x1A
#define MPU6050_GYRO_CONFIG_REG         0x1B
#define MPU6050_ACCEL_CONFIG_REG        0x1C
#define MPU6050_USER_CTRL_REG           0x6A

/*
 * Definitions for FIFO Registers
 */
#define MPU6050_FIFO_EN_REG             0x23
#define MPU6050_FIFO_COUNTH_REG         0x72
#define MPU6050_FIFO_COUNTL_REG         0x73
#define MPU6050_FIFO_R_W_REG            0x74

/*
 * Definitions for I2C Interface Control Registers
 */


#define MPU6050_I2C_MST_CTRL_REG        0x24
#define MPU6050_I2C_MST_DELAY_CTRL_REG  0x67

#define MPU6050_I2C_SLV0_ADDR_REG       0x25
#define MPU6050_I2C_SLV0_REG_REG        0x26
#define MPU6050_I2C_SLV0_CTRL_REG       0x27

#define MPU6050_I2C_SLV1_ADDR_REG       0x28
#define MPU6050_I2C_SLV1_REG_REG        0x29
#define MPU6050_I2C_SLV1_CTRL_REG       0x2A

#define MPU6050_I2C_SLV2_ADDR_REG       0x2B
#define MPU6050_I2C_SLV2_REG_REG        0x2C
#define MPU6050_I2C_SLV2_CTRL_REG       0x2D

#define MPU6050_I2C_SLV3_ADDR_REG       0x2E
#define MPU6050_I2C_SLV3_REG_REG        0x2F
#define MPU6050_I2C_SLV3_CTRL_REG       0x30

#define MPU6050_I2C_SLV4_ADDR_REG       0x31
#define MPU6050_I2C_SLV4_REG_REG        0x32
#define MPU6050_I2C_SLV4_DO_REG         0x33
#define MPU6050_I2C_SLV4_CTRL_REG       0x34
#define MPU6050_I2C_SLV4_DI_REG         0x35

#define MPU6050_I2C_MST_STATUS_REG      0x36

/*
 * Definitions for MPU6050 Interrupts Configuration Registers
 */

#define MPU6050_INT_PIN_CFG_REG         0x37
#define MPU6050_INT_ENABLE_REG          0x38
#define MPU6050_INT_STATUS_REG          0x3A

/*
 * Definitions for MPU6050 Measurements Values Registers
 */

#define MPU6050_ACCEL_XOUT_H_REG        0x3B
#define MPU6050_ACCEL_XOUT_L_REG        0x3C

#define MPU6050_ACCEL_YOUT_H_REG        0x3D
#define MPU6050_ACCEL_YOUT_L_REG        0x3E

#define MPU6050_ACCEL_ZOUT_H_REG        0x3F
#define MPU6050_ACCEL_ZOUT_L_REG        0x40

#define MPU6050_TEMP_OUT_H_REG          0x41
#define MPU6050_TEMP_OUT_L_REG          0x42

#define MPU6050_GYRO_XOUT_H_REG         0x43
#define MPU6050_GYRO_XOUT_L_REG         0x44

#define MPU6050_GYRO_YOUT_H_REG         0x45
#define MPU6050_GYRO_YOUT_L_REG         0x46

#define MPU6050_GYRO_ZOUT_H_REG         0x47
#define MPU6050_GYRO_ZOUT_L_REG         0x48


#define MPU6050_EXT_SENS_DATA_00_REG    0x49
#define MPU6050_EXT_SENS_DATA_01_REG    0x4A
#define MPU6050_EXT_SENS_DATA_02_REG    0x4B
#define MPU6050_EXT_SENS_DATA_03_REG    0x4C
#define MPU6050_EXT_SENS_DATA_04_REG    0x4D
#define MPU6050_EXT_SENS_DATA_05_REG    0x4E
#define MPU6050_EXT_SENS_DATA_06_REG    0x4F
#define MPU6050_EXT_SENS_DATA_07_REG    0x50
#define MPU6050_EXT_SENS_DATA_08_REG    0x51
#define MPU6050_EXT_SENS_DATA_09_REG    0x52
#define MPU6050_EXT_SENS_DATA_10_REG    0x53
#define MPU6050_EXT_SENS_DATA_11_REG    0x54
#define MPU6050_EXT_SENS_DATA_12_REG    0x55
#define MPU6050_EXT_SENS_DATA_13_REG    0x56
#define MPU6050_EXT_SENS_DATA_14_REG    0x57
#define MPU6050_EXT_SENS_DATA_15_REG    0x58
#define MPU6050_EXT_SENS_DATA_16_REG    0x59
#define MPU6050_EXT_SENS_DATA_17_REG    0x5A
#define MPU6050_EXT_SENS_DATA_18_REG    0x5B
#define MPU6050_EXT_SENS_DATA_19_REG    0x5C
#define MPU6050_EXT_SENS_DATA_20_REG    0x5D
#define MPU6050_EXT_SENS_DATA_21_REG    0x5E
#define MPU6050_EXT_SENS_DATA_22_REG    0x5F
#define MPU6050_EXT_SENS_DATA_23_REG    0x60

/*
 * Definitions for I2C Slave DO Registers
 */
#define MPU6050_I2C_SLV0_DO_REG        0x63
#define MPU6050_I2C_SLV1_DO_REG        0x64
#define MPU6050_I2C_SLV2_DO_REG        0x65
#define MPU6050_I2C_SLV3_DO_REG        0x66


/*
 * Definition for Signal path reset register
 */
#define MPU6050_SIGNAL_PATH_RESET_REG  0x68



/*
 * Definition for power management registers
 */
#define MPU6050_PWR_MGMT_1_REG         0x6B
#define MPU6050_PWR_MGMT_2_REG         0x6C

#endif /* INC_MPU6050_REGS_H_ */
