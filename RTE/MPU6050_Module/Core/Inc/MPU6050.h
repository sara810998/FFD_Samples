/******************************************************************************
 * Module: MPU6050
 *
 * File Name: MPU6050.h
 *
 * Description: Header file for MPU6050 module.
 *
 * Author: Eslam - Taha - Sara
 ******************************************************************************/

#ifndef INC_MPU6050_H_
#define INC_MPU6050_H_

/******************************************************************************
 *                                INCLUDES                                    *
 ******************************************************************************/

#include "Std_Types.h"
#include "MPU6050_Regs.h"
#include "MPU6050_Cfg.h"

/******************************************************************************
 *                                DEFINES                                     *
 ******************************************************************************/

/*
 * Definition for Gyroscope Initialization State
 */

#define MPU6050_INITIALIZED                (1U)
#define MPU6050_NOT_INITIALIZED            (0U)

/*
 * Definition for 0 and 1
 */

#define ZERO 0
#define ONE 1

/*
 * Definition for the value of WHO_AM_I Register Value
 */
#define MPU6050_WHO_AM_I_REG_VALUE (0x68)

/*
 * Definition for Gyroscope Output Rate
 */
#if(MPU6050_DLPF_CONFIG == ZERO)
#define MPU6050_GYROSCOPE_OUTPUT_RATE_HZ 8000 /* 8 KHz */
#else
#define MPU6050_GYROSCOPE_OUTPUT_RATE_HZ 1000 /* 1 KHz */
#endif

/*
 * Definition for Gyro Sensitivity
 */
#if (MPU6050_GYRO_RANGE_CONFIG == MPU6050_GYRO_250_DEGREE_PER_SECOND_RANGE)
#define MPU6050_GYRO_SENSITIVITY 131.0
#elif(MPU6050_GYRO_RANGE_CONFIG == MPU6050_GYRO_500_DEGREE_PER_SECOND_RANGE)
#define MPU6050_GYRO_SENSITIVITY 65.5
#elif(MPU6050_GYRO_RANGE_CONFIG == MPU6050_GYRO_1000_DEGREE_PER_SECOND_RANGE)
#define MPU6050_GYRO_SENSITIVITY 32.8
#elif (MPU6050_GYRO_RANGE_CONFIG == MPU6050_GYRO_2000_DEGREE_PER_SECOND_RANGE)
#define MPU6050_GYRO_SENSITIVITY 16.4
#else
#error MPU6050_GYRO_RANGE_CONFIG Definition Error (Invalid Value)
#endif

/*
 * Definition for Accel Sensitivity
 */
#if (MPU6050_ACCEL_RANGE_CONFIG == MPU6050_ACCEL_2_G_RANGE)
#define MPU6050_ACC_SENSITIVITY 16384.0
#elif(MPU6050_ACCEL_RANGE_CONFIG == MPU6050_ACCEL_4_G_RANGE)
#define MPU6050_ACC_SENSITIVITY 8192.0
#elif(MPU6050_ACCEL_RANGE_CONFIG == MPU6050_ACCEL_8_G_RANGE)
#define MPU6050_ACC_SENSITIVITY 4096.0
#elif (MPU6050_ACCEL_RANGE_CONFIG == MPU6050_ACCEL_16_G_RANGE)
#define MPU6050_ACC_SENSITIVITY 2048.0
#else
#error MPU6050_ACCEL_RANGE_CONFIG Definition Error (Invalid Value)
#endif

/*
 * Definition for Temp Sensitivity
 */
#define MPU6050_TEMP_SENSITIVITY 340.0

/*
 * Definition for Temp Disable Bit
 */
#define MPU6050_TEMP_DIS_BIT	(3)

/*
 * Definition for DLPC Configuration Bit
 */
#define MPU6050_DLPF_CFG_0		(0)

/*
 * Definition for FSYNC Configuration Bit
 */
#define MPU6050_EXT_SYNC_SET_0		(3)

/*
 * Definition for Accel Range Configuration Bit
 */
#define MPU6050_ACCEL_FS_SEL_0		(3)

/*
 * Definition for Gyro Range Configuration Bit
 */
#define MPU6050_GYRO_FS_SEL_0		(3)

/*
 * Definition for Data Byte Numbers in the Data Buffer
 */
#define MPU6050_ACCEL_X_H_DATA_BYTE_NUMBER (0)
#define MPU6050_ACCEL_X_L_DATA_BYTE_NUMBER (1)
#define MPU6050_ACCEL_Y_H_DATA_BYTE_NUMBER (2)
#define MPU6050_ACCEL_Y_L_DATA_BYTE_NUMBER (3)
#define MPU6050_ACCEL_Z_H_DATA_BYTE_NUMBER (4)
#define MPU6050_ACCEL_Z_L_DATA_BYTE_NUMBER (5)

#define MPU6050_GYRO_X_H_DATA_BYTE_NUMBER  (0)
#define MPU6050_GYRO_X_L_DATA_BYTE_NUMBER  (1)
#define MPU6050_GYRO_Y_H_DATA_BYTE_NUMBER  (2)
#define MPU6050_GYRO_Y_L_DATA_BYTE_NUMBER  (3)
#define MPU6050_GYRO_Z_H_DATA_BYTE_NUMBER  (4)
#define MPU6050_GYRO_Z_L_DATA_BYTE_NUMBER  (5)

#define MPU6050_TEMP_H_DATA_BYTE_NUMBER    (0)
#define MPU6050_TEMP_L_DATA_BYTE_NUMBER    (1)

/*
 * Definition for Number of Byte (Written and Read)
 */

#define MPU6050_N_WRITTEN_BYTES_ONE (1)
#define MPU6050_N_READ_BYTES_ONE    (1)
#define MPU6050_N_READ_BYTES_TWO    (2)
#define MPU6050_N_READ_BYTES_SIX    (6)


/******************************************************************************
 *                           DEFAULT CONFIGURATIONS                           *
 ******************************************************************************/
#define MPU6050_DEFAULT_CLOCK_SOURCE_CONFIG MPU6050_INTERNAL_8MHZ_OSC
#define MPU6050_DEFAULT_TEMP_SENSOR_ENABLE_CONFIG MPU_TEMP_SENSOR_ENABLE
#define MPU6050_DEFAULT_SAMPLE_RATE_CONFIG 1000   /* 1 KHz */
#define MPU6050_DEFAULT_GYRO_RANGE_CONFIG MPU6050_GYRO_250_DEGREE_PER_SECOND_RANGE
#define MPU6050_DEFAULT_ACCEL_RANGE_CONFIG MPU6050_ACCEL_2_G_RANGE
#define MPU6050_DEFAULT_FSYNC_PIN_CONFIG MPU6050_FSYNC_PIN_INPUT_DISABLED
#define MPU6050_DEFAULT_DLPF_CONFIG MPU6050_DLPF_CONFIG_MODE_0

/******************************************************************************
 *                           Module Data Types                                *
 ******************************************************************************/
/*
 * Data Type for MPU6050 address
 */
typedef uint8 Mpu6050_address;

/*
 * Data Type for MPU6050 Module Channel ID
 */
typedef uint8 Mpu6050_channelID;

/*
 * Data Type for MPU6050 Sample Rate
 */
typedef uint16 Mpu6050_sampleRateConfig;
/*
 * Data Type for MPU6050 acceleration in the direction of X-axis reading
 */
typedef float32 Mpu6050_accX;
/*
 * Data Type for MPU6050 acceleration in the direction of Y-axis reading
 */
typedef float32 Mpu6050_accY;
/*
 * Data Type for MPU6050 acceleration in the direction of Z-axis reading
 */
typedef float32 Mpu6050_accZ;
/*
 * Data Type for MPU6050 velocity in the direction of X-axis reading
 */
typedef float32 Mpu6050_gyroX;
/*
 * Data Type for MPU6050 velocity in the direction of Y-axis reading
 */
typedef float32 Mpu6050_gyroY;
/*
 * Data Type for MPU6050 velocity in the direction of Z-axis reading
 */
typedef float32 Mpu6050_gyroZ;
/*
 * Data Type for MPU6050 temperature reading
 */
typedef float32 Mpu6050_temp;

/*
 * Enum for MPU6050 Clock Source Configurations
 */
typedef enum {
	MPU6050_INTERNAL_8MHZ_OSC,
	MPU6050_PLL_X_AXIS_REFERENCE,
	MPU6050_PLL_Y_AXIS_REFERENCE,
	MPU6050_PLL_Z_AXIS_REFERENCE,
	MPU6050_PLL_EXT_32KHZ_REFERENCE,
	MPU6050_PLL_EXT_19KHZ_REFERENCE,
	MPU6050_STOP_CLOCK = 7
} Mpu6050_clockSourceConfig;

/*
 * Enum for MPU6050 Reading State
 */
typedef enum {
	MPU6050_ERROR,
	MPU6050_SUCCESS
} Mpu6050_readingState;

/*
 * Enum for MPU6050 Temperature Sensor Enabling Configuration
 */
typedef enum {
	MPU_TEMP_SENSOR_ENABLE, MPU_TEMP_SENSOR_DISABLE
} Mpu6050_tempSensorEnable;

/*
 * Enum for MPU6050 Gyro Range Configuration
 */
typedef enum {
	MPU6050_GYRO_250_DEGREE_PER_SECOND_RANGE,
	MPU6050_GYRO_500_DEGREE_PER_SECOND_RANGE,
	MPU6050_GYRO_1000_DEGREE_PER_SECOND_RANGE,
	MPU6050_GYRO_2000_DEGREE_PER_SECOND_RANGE
} Mpu6050_GyroRangeConfig;

typedef enum {
	MPU6050_FSYNC_PIN_INPUT_DISABLED,
	MPU6050_FSYNC_PIN_TEMP_OUT_L_0,
	MPU6050_FSYNC_PIN_GYRO_XOUT_L_0,
	MPU6050_FSYNC_PIN_GYRO_YOUT_L_0,
	MPU6050_FSYNC_PIN_GYRO_ZOUT_L_0,
	MPU6050_FSYNC_PIN_ACCEL_XOUT_L_0,
	MPU6050_FSYNC_PIN_ACCEL_YOUT_L_0,
	MPU6050_FSYNC_PIN_ACCEL_ZOUT_L_0,
} Mpu6050_FSYNC_PinConfig;

typedef enum {
	MPU6050_DLPF_CONFIG_MODE_0,
	MPU6050_DLPF_CONFIG_MODE_1,
	MPU6050_DLPF_CONFIG_MODE_2,
	MPU6050_DLPF_CONFIG_MODE_3,
	MPU6050_DLPF_CONFIG_MODE_4,
	MPU6050_DLPF_CONFIG_MODE_5,
	MPU6050_DLPF_CONFIG_MODE_6
} Mpu6050_DLPF_Config;

/*
 * Enum for MPU6050 Acceleration Range Configuration
 */
typedef enum {
	MPU6050_ACCEL_2_G_RANGE,
	MPU6050_ACCEL_4_G_RANGE,
	MPU6050_ACCEL_8_G_RANGE,
	MPU6050_ACCEL_16_G_RANGE
} Mpu6050_AccelRangeConfig;

/*
 * Struct type for MPU6050 Module Data
 */
typedef struct {
	Mpu6050_accX AccXReading;
	Mpu6050_accY AccYReading;
	Mpu6050_accZ AccZReading;
	Mpu6050_gyroX GyroXReading;
	Mpu6050_gyroY GyroYReading;
	Mpu6050_gyroZ GyroZReading;
	Mpu6050_temp Temperature;
} Mpu6050_TypeDef;

/*
 * Struct type for MPU6050 One Module Configuration
 */

typedef struct {
	Mpu6050_channelID channelIDConfig;
	Mpu6050_address address;
	Mpu6050_clockSourceConfig clockSoureConfig;
	Mpu6050_tempSensorEnable tempSensorConfig;
	Mpu6050_sampleRateConfig sampleRateConfig;
	Mpu6050_GyroRangeConfig gyroRangeConfig;
	Mpu6050_AccelRangeConfig accelRangeConfig;
	Mpu6050_FSYNC_PinConfig FSYNC_pinConfig;
	Mpu6050_DLPF_Config DLPF_config;
} Mpu6050_ConfigChannel;

/*
 * Struct type for MPU6050 Module Configuration
 */
typedef struct {
	Mpu6050_ConfigChannel Mpu6050_Channels[MPU6050_NUMBER_MODULES_CONNECTED];
} Mpu6050_ConfigType;

/******************************************************************************
 *                           Functions Prototypes                             *
 ******************************************************************************/
/*
 *  Initialization Function Prototype
 */
void Mpu6050_init(const Mpu6050_ConfigType *ConfigPtr);
/*
 * Mpu6050_getReadings Prototype
 */
Mpu6050_readingState Mpu6050_getReadings(Mpu6050_TypeDef *Mpu6050_dataStruct, Mpu6050_channelID Channel);

/******************************************************************************
 *                                 Externs                                    *
 ******************************************************************************/

extern Mpu6050_ConfigType Mpu6050_Configuration;

#endif /* INC_MPU6050_H_ */
