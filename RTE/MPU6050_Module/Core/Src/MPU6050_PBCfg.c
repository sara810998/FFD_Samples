/******************************************************************************
 * Module: MPU6050
 *
 * File Name: MPU6050_PBCfg.h
 *
 * Description: Source file for MPU6050 Module PB Configurations.
 *
 * Author: Eslam EL-Naggar
 ******************************************************************************/

#include"MPU6050.h"

Mpu6050_ConfigType Mpu6050_Configuration = {

MPU6050_CHANNEL_ID_CONFIG, 0x68, MPU6050_CLOCK_SOURCE_CONFIG,
		MPU6050_TEMP_SENSOR_ENABLE_CONFIG, MPU6050_SAMPLE_RATE_CONFIG,
		MPU6050_GYRO_RANGE_CONFIG, MPU6050_ACCEL_RANGE_CONFIG,
		MPU6050_FSYNC_PIN_CONFIG, MPU6050_DLPF_CONFIG };
