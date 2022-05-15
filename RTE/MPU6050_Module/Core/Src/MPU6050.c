/******************************************************************************
 * Module: MPU6050
 *
 * File Name: MPU6050.c
 *
 * Description: Source file for MPU6050 module.
 *
 * Author: Eslam EL-Naggar
 ******************************************************************************/

/******************************************************************************
 *                                INCLUDES                                    *
 ******************************************************************************/
#include "TWI.h"
#include "MPU6050.h"

/******************************************************************************
 *                            GLOBAL VARIABLES                                *
 ******************************************************************************/
/* Variable for MPU6050 Initialization Status */
STATIC uint8 MPU6050_Status = MPU6050_NOT_INITIALIZED;

/* Variable for MPU6050 Channel Initialization Status */
STATIC uint8 MPU6050_ChannelStatus[MPU6050_NUMBER_MODULES_CONNECTED] = {
		MPU6050_NOT_INITIALIZED };

/* Variable for holding the address of the configuration struct */
STATIC Mpu6050_ConfigChannel *Mpu6050_ConfigChannelPtr = NULL_PTR;

/******************************************************************************
 *                       Private Functions Prototypes                         *
 ******************************************************************************/

STATIC void Mpu6050_getAccReadings(Mpu6050_TypeDef *Mpu6050_dataStruct,
		Mpu6050_channelID Channel);
STATIC void Mpu6050_getGyroReadings(Mpu6050_TypeDef *Mpu6050_dataStruct,
		Mpu6050_channelID Channel);
STATIC void Mpu6050_getTempReadings(Mpu6050_TypeDef *Mpu6050_dataStruct,
		Mpu6050_channelID Channel);

/******************************************************************************
 *                        Functions Definitions                               *
 ******************************************************************************/

/************************************************************************************
 * Service Name: Mpu6050_Init
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): ConfigPtr - Pointer to the address of the CFG Struct
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Initialize the MPU6050 Module.
 ************************************************************************************/

void Mpu6050_init(const Mpu6050_ConfigType *ConfigPtr) {

	uint8 data = ZERO;
	uint8 address = ZERO;
	uint8 counter = ZERO;
	Mpu6050_ConfigChannelPtr = ConfigPtr->Mpu6050_Channels;

	for (counter = ZERO; counter < MPU6050_NUMBER_MODULES_CONNECTED;
			counter++) {
		/*
		 * Getting the device address
		 */
		address = Mpu6050_ConfigChannelPtr->address;
		/*
		 * Checking the connection with MPU6050 by reading WHO AM I Register
		 */
//		Twi_Mem_Read(MPU6050_CHANNEL_ID_CONFIG, 0x68, MPU6050_WHO_AM_I_REG, &data,
//		MPU6050_N_READ_BYTES_ONE);
HAL_Delay(500);
		if (0x68 == 0x68) {
			/*
			 * Setting up the data frame of PWR_MGMT_1 Register
			 * Bit 7: When set to 1, this bit resets all internal registers to their default values.
			 * Bit 6: When set to 1, this bit puts the MPU-60X0 into sleep mode.
			 * Bit 5: When this bit is set to 1 and SLEEP is disabled,
			 * 		  the MPU-6050 will cycle between sleep mode and waking up
			 * 		  to take a single sample of data from active sensors at a rate of waking frequency.
			 * Bit 4: Reserved
			 * Bit 3: When set to 1, this bit disables the temperature sensor.
			 * Bits[0:2]: 3-bit unsigned value. Specifies the clock source of the device.
			 */
			data = (data & 0xF8)
					| (Mpu6050_ConfigChannelPtr->clockSoureConfig & 0x07);
			data = (data & 0xF7)
					| ((Mpu6050_ConfigChannelPtr->tempSensorConfig & 0x01)
							<< MPU6050_TEMP_DIS_BIT);
			/*
			 * Writing the data to the register
			 */
			Twi_Mem_Write(MPU6050_CHANNEL_ID_CONFIG, address, MPU6050_PWR_MGMT_1_REG,
					&data, MPU6050_N_WRITTEN_BYTES_ONE);
			data = ZERO;

			/*******************************************************************************************************************
			 *                              Setting Sleep Mode needs to be implemented                                         *
			 *******************************************************************************************************************/

			/*
			 * Setting the FSYNC Pin and DLPC_Cfg
			 * Bits[3:5] -> FSYNC Configuration
			 * Bits[0:2] -> DLPC Configuration
			 */
			data = (data & 0xC7)
					| ((Mpu6050_ConfigChannelPtr->FSYNC_pinConfig & 0x07)
							<< (MPU6050_EXT_SYNC_SET_0));
			data = (data & 0x07)
					| ((Mpu6050_ConfigChannelPtr->DLPF_config & 0x07)
							<< (MPU6050_DLPF_CFG_0));
			/*
			 * Writing the data to the register
			 */
			Twi_Mem_Write(MPU6050_CHANNEL_ID_CONFIG, address, MPU6050_CONFIG_REG,
					&data,
					MPU6050_N_WRITTEN_BYTES_ONE);
			data = ZERO;

			/*
			 * Setting up the sample rate in Hz
			 * The Sample Rate is generated by dividing the gyroscope output rate by SMPLRT_DIV:
			 * Sample Rate = Gyroscope Output Rate / (1 + SMPLRT_DIV)
			 * So, get SPLRT_DIV and write the value to SMPLRT_DIV register which is equal to our data
			 */
			data = (MPU6050_GYROSCOPE_OUTPUT_RATE_HZ
					/ Mpu6050_ConfigChannelPtr->sampleRateConfig) - ONE;
			/*
			 * Writing the data to the register
			 */
			Twi_Mem_Write(MPU6050_CHANNEL_ID_CONFIG, address, MPU6050_SMPLRT_DIV_REG,
					&data, MPU6050_N_WRITTEN_BYTES_ONE);
			data = ZERO;

			/*
			 * Getting the Gyro Range
			 */
			data = (data & 0xE7)
					| ((Mpu6050_ConfigChannelPtr->gyroRangeConfig & 0x07)
							<< MPU6050_GYRO_FS_SEL_0);
			/*
			 * Writing the data to the register
			 */
			Twi_Mem_Write(MPU6050_CHANNEL_ID_CONFIG, address,
					MPU6050_GYRO_CONFIG_REG, &data,
					MPU6050_N_WRITTEN_BYTES_ONE);
			data = ZERO;

			/*
			 * Getting the Accel Range
			 */
			data = (data & 0xE7)
					| ((Mpu6050_ConfigChannelPtr->accelRangeConfig & 0x07)
							<< MPU6050_ACCEL_FS_SEL_0);
			/*
			 * Writing the data to the register
			 */
			Twi_Mem_Write(MPU6050_CHANNEL_ID_CONFIG, address,
					MPU6050_ACCEL_CONFIG_REG, &data,
					MPU6050_N_WRITTEN_BYTES_ONE);
			data = ZERO;

			data = (data & 0xF8)
					| (Mpu6050_ConfigChannelPtr->clockSoureConfig & 0x07);
			data = (data & 0xF7)
					| ((Mpu6050_ConfigChannelPtr->tempSensorConfig & 0x01)
							<< MPU6050_TEMP_DIS_BIT);
			/*
			 * Writing the data to the register
			 */
			Twi_Mem_Write(MPU6050_CHANNEL_ID_CONFIG, address, MPU6050_PWR_MGMT_1_REG,
					&data, MPU6050_N_WRITTEN_BYTES_ONE);

			/*
			 * Set the state of MPU6050 Channel to initialized
			 */
			MPU6050_ChannelStatus[counter] = MPU6050_INITIALIZED;
		} else {
			/*
			 * Set the state of MPU6050 Channel to not initialized,
			 * due to WHO AM I Register Reading failure
			 */
			MPU6050_ChannelStatus[counter] = MPU6050_NOT_INITIALIZED;
		}
		/*
		 * point to the next channel
		 */
		Mpu6050_ConfigChannelPtr++;
	}
	Mpu6050_ConfigChannelPtr = ConfigPtr->Mpu6050_Channels;
	MPU6050_Status = MPU6050_INITIALIZED;
}

/************************************************************************************
 * Service Name: Mpu6050_getReadings
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): Mpu6050_dataStruct - struct where the updated readings
 * 										of MPU6050 will be stored in
 * 					Channel            - Module Channel ID
 * Parameters (inout): None
 * Parameters (out): readingState - Whether success reading operation or not
 * Return value: None
 * Description: Function to Initialize the MPU6050 Module.
 * 				AccX  - AccY  - AccZ
 * 			    GyroX - GyroY - GyroZ
 * 			    Temperature
 ************************************************************************************/

Mpu6050_readingState Mpu6050_getReadings(Mpu6050_TypeDef *Mpu6050_dataStruct,
		Mpu6050_channelID Channel) {
	Mpu6050_readingState readingState = MPU6050_ERROR;

	if (MPU6050_ChannelStatus[Channel] == MPU6050_INITIALIZED) {
		/*
		 * Update Acceleration Readings
		 */
		Mpu6050_getAccReadings(Mpu6050_dataStruct, Channel);
		/*
		 * Update Velocity Readings
		 */
		Mpu6050_getGyroReadings(Mpu6050_dataStruct, Channel);
//		/*
//		 * Update Temperature Reading
//		 */
//		Mpu6050_getTempReadings(Mpu6050_dataStruct, Channel);
		/*
		 * Set readingState to SUCCESS
		 */
		readingState = MPU6050_SUCCESS;
	} else {
		/*
		 * Set readingState to ERROR
		 */
		readingState = MPU6050_ERROR;
	}
	return readingState;
}

/************************************************************************************
 * Service Name: Mpu6050_getAccReadings
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): Mpu6050_dataStruct - struct where the updated readings
 * 										of MPU6050 will be stored in
 * 					Channel            - Module Channel ID
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to request the new acceleration readings.
 ************************************************************************************/

STATIC void Mpu6050_getAccReadings(Mpu6050_TypeDef *Mpu6050_dataStruct,
		Mpu6050_channelID Channel) {
	/*
	 * variables to hold the new acceleration readings
	 */
	sint16 accXReading = ZERO;
	sint16 accYReading = ZERO;
	sint16 accZReading = ZERO;
	/*
	 * External Buffer for TWI to hold the reading received
	 * dataBuffer:
	 * first element   : Eight MSBs of AccX
	 * second element  : Eight LSBs of AccX
	 * third element   : Eight MSBs of AccY
	 * fourth element  : Eight LSBs of AccY
	 * fifth element   : Eight MSBs of AccZ
	 * sixth element   : Eight LSBs of AccZ
	 */
	uint8 dataBuffer[MPU6050_N_READ_BYTES_SIX] = { ZERO };

	/*
	 * get the readings via TWI
	 */
	Twi_Mem_Read(MPU6050_CHANNEL_ID_CONFIG, 0x68,
			MPU6050_ACCEL_XOUT_H_REG, dataBuffer, 6);

	/*
	 * concatenate the values of Eight MSBs and Eight LSBs together for AccX, AccY and AccZ
	 */
	accXReading = (sint16) ((dataBuffer[MPU6050_ACCEL_X_H_DATA_BYTE_NUMBER]
			<< 8) + dataBuffer[MPU6050_ACCEL_X_L_DATA_BYTE_NUMBER]);
	accYReading = (sint16) ((dataBuffer[MPU6050_ACCEL_Y_H_DATA_BYTE_NUMBER]
			<< 8) + dataBuffer[MPU6050_ACCEL_Y_L_DATA_BYTE_NUMBER]);
	accZReading = ((sint16) (dataBuffer[MPU6050_ACCEL_Z_H_DATA_BYTE_NUMBER]
			<< 8) + dataBuffer[MPU6050_ACCEL_Z_L_DATA_BYTE_NUMBER]);
	/*
	 * getting the float g for AccX, AccY and AccZ
	 * then, updating the readings in the MPU6050 Data Struct
	 */
	Mpu6050_dataStruct->AccXReading = (Mpu6050_accX) (accXReading * 1.0
			/ MPU6050_ACC_SENSITIVITY);
	Mpu6050_dataStruct->AccYReading = (Mpu6050_accY) (accYReading * 1.0
			/ MPU6050_ACC_SENSITIVITY);
	Mpu6050_dataStruct->AccZReading = (Mpu6050_accZ) (accZReading * 1.0
			/ MPU6050_ACC_SENSITIVITY);
}

/************************************************************************************
 * Service Name: Mpu6050_getGyroReadings
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): Mpu6050_dataStruct - struct where the updated readings
 * 										of MPU6050 will be stored in
 * 					Channel            - Module Channel ID
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to request the new velocity readings.
 ************************************************************************************/

STATIC void Mpu6050_getGyroReadings(Mpu6050_TypeDef *Mpu6050_dataStruct,
		Mpu6050_channelID Channel) {
	/*
	 * variables to hold the new velocity readings
	 */
	sint16 gyroXReading;
	sint16 gyroYReading;
	sint16 gyroZReading;
	/*
	 * External Buffer for TWI to hold the reading received
	 * dataBuffer:
	 * first element   : Eight MSBs of GyroX
	 * second element  : Eight LSBs of GyroX
	 * third element   : Eight MSBs of GyroY
	 * fourth element  : Eight LSBs of GyroY
	 * fifth element   : Eight MSBs of GyroZ
	 * sixth element   : Eight LSBs of GyroZ
	 */
	uint8 dataBuffer[MPU6050_N_READ_BYTES_SIX] = { ZERO };

	/*
	 * get the readings via TWI
	 */
	Twi_Mem_Read(MPU6050_CHANNEL_ID_CONFIG, 0x68,
			MPU6050_GYRO_XOUT_H_REG, dataBuffer, MPU6050_N_READ_BYTES_SIX);

	/*
	 * concatenate the values of Eight MSBs and Eight LSBs together for GyroX, GyroY and GyroZ
	 */
	gyroXReading = (sint16) ((dataBuffer[MPU6050_GYRO_X_H_DATA_BYTE_NUMBER]
			<< 8) + dataBuffer[MPU6050_GYRO_X_L_DATA_BYTE_NUMBER]);
	gyroYReading = (sint16) ((dataBuffer[MPU6050_GYRO_Y_H_DATA_BYTE_NUMBER]
			<< 8) + dataBuffer[MPU6050_GYRO_Y_L_DATA_BYTE_NUMBER]);
	gyroZReading = (sint16) ((dataBuffer[MPU6050_GYRO_Z_H_DATA_BYTE_NUMBER]
			<< 8) + dataBuffer[MPU6050_GYRO_Z_L_DATA_BYTE_NUMBER]);
	/*
	 * getting the float dps for GyroX, GyroY and GyroZ
	 * then, updating the readings in the MPU6050 Data Struct
	 */
	Mpu6050_dataStruct->GyroXReading = (Mpu6050_gyroX) (gyroXReading * 1.0
			/ MPU6050_GYRO_SENSITIVITY);
	Mpu6050_dataStruct->GyroYReading = (Mpu6050_gyroY) (gyroYReading * 1.0
			/ MPU6050_GYRO_SENSITIVITY);
	Mpu6050_dataStruct->GyroZReading = (Mpu6050_gyroZ) (gyroZReading * 1.0
			/ MPU6050_GYRO_SENSITIVITY);
}

/************************************************************************************
 * Service Name: Mpu6050_getTempReading
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): Mpu6050_dataStruct - struct where the updated readings
 * 										of MPU6050 will be stored in
 * 					Channel            - Module Channel ID
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to request the new temperature reading.
 ************************************************************************************/

STATIC void Mpu6050_getTempReadings(Mpu6050_TypeDef *Mpu6050_dataStruct,
		Mpu6050_channelID Channel) {
	/*
	 * variables to hold the new temperature reading
	 */
	sint16 temperature;
	/*
	 * External Buffer for TWI to hold the reading received
	 * dataBuffer:
	 * second element  : Eight MSBs of Temp
	 * third element   : Eight LSBs of Temp
	 */
	uint8 dataBuffer[2] = { ZERO };

	/*
	 * get the reading via TWI
	 */
	Twi_Mem_Read(MPU6050_CHANNEL_ID_CONFIG, 0x68,
			MPU6050_TEMP_OUT_H_REG, dataBuffer, 2);

	/*
	 * concatenate the values of Eight MSBs and Eight LSBs together
	 */
	temperature = (sint16) ((dataBuffer[MPU6050_TEMP_H_DATA_BYTE_NUMBER]
			<< 8) + dataBuffer[MPU6050_TEMP_L_DATA_BYTE_NUMBER]);

	/*
	 * getting the float temperature
	 * then, updating the reading in the MPU6050 Data Struct
	 */
	Mpu6050_dataStruct->Temperature = (Mpu6050_temp) (((sint16) temperature)
			* 1.0 / MPU6050_TEMP_SENSITIVITY);
}

