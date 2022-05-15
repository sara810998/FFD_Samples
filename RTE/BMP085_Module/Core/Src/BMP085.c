/******************************************************************************
 * Module: BMP085
 *
 * File Name: BMP085.c
 *
 * Description: Source file for BMP085 module.
 *
 * Author: Eslam - Taha - Sara
 ******************************************************************************/
#include "math.h"
#include "BMP085.h"
#include "Twi.h"

/*initialize flow meter status as not initialized*/
STATIC uint8 Barometer_Status = BMP085_NOT_INITIALIZED;
STATIC BMP085_ConfigChannel* Barometer_Ptr = NULL_PTR;

/************************************************************************************
 * Service Name: BMP085_Init
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): ConfigPtr - Pointer to a selected configuration structure
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Initialize the BMP085 Module.
 ************************************************************************************/
void BMP085_Init(const BMP085_ConfigType* ConfigPtr){
	/* pointer to motor PWM channels structure */
		Barometer_Ptr = ConfigPtr->BMP085_Channels;
		/* loop counter */
		uint8 Counter = 0;
		for(Counter ; Counter < NUMBER_OF_BMP085_BAROMETERS; Counter++ )
		{
			/*no initialization*/

			/* increment pointer to intialize the next barometer */
			Barometer_Ptr++;
		}
		/* Set address of the first structure to BMP085_Channel*/
		Barometer_Ptr = ConfigPtr->BMP085_Channels;
		/*set barometer status to initialized*/
		Barometer_Status = BMP085_INITIALIZED;

}
/************************************************************************************
 * Service Name: BMP085_Get_Temp
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in):BarometerId
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: uint32 temp
 * Description: Function to read the temp value
 ************************************************************************************/
#if (ENABLE_GET_TEMP_API == STD_ON)
sint32 BMP085_Get_Temp(BMP085_ChannelIdType BarometerId){

		 sint32 T;

		 /*Calibration parmeters used {AC1,AC2,AC3,AC4,AC5,AC6,B1,B2,MB,MC,MD}*/
		 sint16 BMP085_Get_Cal_Parm[NUMBER_OF_CALIBRATION_PARAM];

		 /*Uncompensated temprature and pressure values*/
		 sint32 BMP085_Uncompensated_Temp_Value;
		 sint32 BMP085_Uncompensated_Pressure_Value;

		 /*
		  * factors used to calculate calibrated temp and pressure
		  * {X1,X2,X3,B3,B4,B5,B6,B7}
		  */
		 sint32 BMP085_Calc_Factors[NUMBER_OF_CALCULATION_FACTORS];

		 /* read the calibration parameters*/
		 BMP085_Get_Cal_Parm(BarometerId, &BMP085_Get_Cal_Parm);

		 /* read the uncompensated temp value*/
		 BMP085_Get_UT(BarometerId, &BMP085_Uncompensated_Temp_Value);

		 /* calculate the calibrated temp value*/
		 T = BMP085_Calc_Temp(&BMP085_Get_Cal_Parm, &BMP085_Uncompensated_Temp_Value, &BMP085_Calc_Factors );

		 return T;
}
#endif
/************************************************************************************
 * Service Name: BMP085_Get_Pressure
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): BarometerId
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: uint32 pressure
 * Description: Function to read pressure.
 ************************************************************************************/
#if (ENABLE_GET_PRESSURE_API == STD_ON)
sint32 BMP085_Get_Pressure(BMP085_ChannelIdType BarometerId){

	 sint32 P;

	 /*Calibration parmeters used {AC1,AC2,AC3,AC4,AC5,AC6,B1,B2,MB,MC,MD}*/
	 sint16 BMP085_Get_Cal_Parm[NUMBER_OF_CALIBRATION_PARAM];

	 /*Uncompensated temprature and pressure values*/
	 sint32 BMP085_Uncompensated_Temp_Value;
	 sint32 BMP085_Uncompensated_Pressure_Value;

	 /*
	  * factors used to calculate calibrated temp and pressure
	  * {X1,X2,X3,B3,B4,B5,B6,B7}
	  */
	 sint32 BMP085_Calc_Factors[NUMBER_OF_CALCULATION_FACTORS];

	 /* read the calibration parameters*/
	 BMP085_Get_Cal_Parm(BarometerId, &BMP085_Get_Cal_Parm);

	 /* read the uncompensated temp value*/
	 BMP085_Get_UT(BarometerId, &BMP085_Uncompensated_Temp_Value);

	 /* read the uncompensated pressure value*/
	 BMP085_Get_UP(BarometerId, &BMP085_Uncompensated_Pressure_Value);

	 /* calculate the calibrated temp value*/
	 BMP085_Calc_Temp(&BMP085_Get_Cal_Parm, &BMP085_Uncompensated_Temp_Value, &BMP085_Calc_Factors );

	 /* calculate the calibrated pressure value*/
	 P = BMP085_Calc_Pressure(&BMP085_Get_Cal_Parm, &BMP085_Uncompensated_Pressure_Value, &BMP085_Calc_Factors ,Barometer_Ptr[BarometerId].Barometer_Oversampling_Setting_Channel);
	 return P;
}
#endif
/************************************************************************************
 * Service Name: BMP085_Get_Altitude
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): BarometerId
 * 					SeaLevel_Pressure - pressure at sea level in Pa
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: float32 altitude
 * Description: Function to calc altitude.
 ************************************************************************************/
#if (ENABLE_GET_ALTITUDE_API == STD_ON)
float32 BMP085_Get_Altitude(BMP085_ChannelIdType BarometerId, BMP085_ValueType SeaLevel_Pressure){

		 sint32 P;
		 float32 Altitude;

		 /*Calibration parmeters used {AC1,AC2,AC3,AC4,AC5,AC6,B1,B2,MB,MC,MD}*/
		 sint16 BMP085_Get_Cal_Parm[NUMBER_OF_CALIBRATION_PARAM];

		 /*Uncompensated temprature and pressure values*/
		 sint32 BMP085_Uncompensated_Temp_Value;
		 sint32 BMP085_Uncompensated_Pressure_Value;

		 /*
		  * factors used to calculate calibrated temp and pressure
		  * {X1,X2,X3,B3,B4,B5,B6,B7}
		  */
		 sint32 BMP085_Calc_Factors[NUMBER_OF_CALCULATION_FACTORS];

		 /* read the calibration parameters*/
		 BMP085_Get_Cal_Parm(BarometerId, &BMP085_Get_Cal_Parm);

		 /* read the uncompensated temp value*/
		 BMP085_Get_UT(BarometerId, &BMP085_Uncompensated_Temp_Value);

		 /* read the uncompensated pressure value*/
		 BMP085_Get_UP(BarometerId, &BMP085_Uncompensated_Pressure_Value);

		 /* calculate the calibrated  temp value*/
		 BMP085_Calc_Temp(&BMP085_Get_Cal_Parm, &BMP085_Uncompensated_Temp_Value, &BMP085_Calc_Factors );

		 /* calculate the calibrated  temp value*/
		 P = BMP085_Calc_Pressure(&BMP085_Get_Cal_Parm, &BMP085_Uncompensated_Pressure_Value, &BMP085_Calc_Factors ,Barometer_Ptr[BarometerId].Barometer_Oversampling_Setting_Channel);

		 /* calculate the altitude value*/
		 Altitude = 44330.0 * ( 1.0 - pow (P/SeaLevel_Pressure , 1/5.255));

		 return Altitude;
}
#endif
/************************************************************************************
 * Service Name: BMP085_SeaLevel_Pressure_Calculation
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): ConfigPtr - Pointer to a selected configuration structure
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Initialize the BMP085 Module.
 ************************************************************************************/
#if (ENABLE_GET_SEA_LEVEL_PRESSURE_API == STD_ON)
float32 BMP085_Get_SeaLevel_Pressure(BMP085_ChannelIdType BarometerId, BMP085_ValueType Absolute_Altitude){

			 sint32 P;
			 float32 SeaLevel_Pressure;

			 /*Calibration parmeters used {AC1,AC2,AC3,AC4,AC5,AC6,B1,B2,MB,MC,MD}*/
			 sint16 BMP085_Get_Cal_Parm[NUMBER_OF_CALIBRATION_PARAM];

			 /*Uncompensated temprature and pressure values*/
			 sint32 BMP085_Uncompensated_Temp_Value;
			 sint32 BMP085_Uncompensated_Pressure_Value;

			 /*
			  * factors used to calculate calibrated temp and pressure
			  * {X1,X2,X3,B3,B4,B5,B6,B7}
			  */
			 sint32 BMP085_Calc_Factors[NUMBER_OF_CALCULATION_FACTORS];

			 /* read the calibration parameters*/
			 BMP085_Get_Cal_Parm(BarometerId, &BMP085_Get_Cal_Parm);

			 /* read the uncompensated temp value*/
			 BMP085_Get_UT(BarometerId, &BMP085_Uncompensated_Temp_Value);

			 /* read the uncompensated pressure value*/
			 BMP085_Get_UP(BarometerId, &BMP085_Uncompensated_Pressure_Value);

			 /* calculate the calibrated  temp value*/
			 BMP085_Calc_Temp(&BMP085_Get_Cal_Parm, &BMP085_Uncompensated_Temp_Value, &BMP085_Calc_Factors );

			 /* calculate the calibrated  temp value*/
			 P = BMP085_Calc_Pressure(&BMP085_Get_Cal_Parm, &BMP085_Uncompensated_Pressure_Value, &BMP085_Calc_Factors ,Barometer_Ptr[BarometerId].Barometer_Oversampling_Setting_Channel);

			 /* calculate the sea level pressure value*/
			 SeaLevel_Pressure = P*1.0 / pow( 1 - (Absolute_Altitude/44330) , 5.255);

			 return SeaLevel_Pressure;
}
#endif

/******************************************************************************
 *                       Private APIs Prototypes                         *
 ******************************************************************************/
STATIC void BMP085_Get_Cal_Parm(BMP085_ChannelIdType BarometerId, BMP085_DataType *DataBufferPointer);

STATIC void BMP085_Get_UT(BMP085_ChannelIdType BarometerId, BMP085_DataType *DataBufferPointer);

STATIC void BMP085_Get_UP(BMP085_ChannelIdType BarometerId, BMP085_DataType *DataBufferPointer);

STATIC sint32 BMP085_Calc_Temp( BMP085_DataType *BMP085_Get_Cal_Parm, BMP085_DataType *BMP085_Uncompensated_Temp_Value, BMP085_DataType *BMP085_Calc_Factors );

STATIC sint32 BMP085_Calc_Pressure(BMP085_DataType *BMP085_Get_Cal_Parm, BMP085_DataType *BMP085_Uncompensated_Pressure_Value, BMP085_DataType *BMP085_Calc_Factors ,BMP085_oversampling_settingType OSS);

STATIC uint32 BMP085_Calc_Altitude(void);

/******************************************************************************
 *                     		  Private APIs                       *
 ******************************************************************************/

/************************************************************************************
 * Service Name: BMP085_Get_Cal_Parm
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): DataBufferPointer - Pointer to Calibration parmeters used {AC1,AC2,AC3,AC4,AC5,AC6,B1,B2,MB,MC,MD}
 * 					BarometerId
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to read the calibration parameters value.
 ************************************************************************************/
void BMP085_Get_Cal_Parm(BMP085_ChannelIdType BarometerId, BMP085_DataType *DataBufferPointer){

	/*
	 * array used in memread function to read from 8 bit EEOROM registers directly
	 * {AC1_MSB,AC1_LSB,AC2_MSB,AC2_LSB,AC3_MSB,AC3_LSB,AC4_MSB,AC4_LSB,AC5_MSB,AC5_LSB,AC6_MSB,AC6_LSB,B1_MSB,B1_LSB,B2_MSB,B2_LSB,MB_MSB,MB_LSB,MC_MSB,MC_LSB,MD_MSB,MD_LSB}
	 */
	uint8 BMP085_Read_CalibrationData_Values[NUMBER_OF_8BIT_EEPROM_REGS];


	Twi_MemRead(Barometer_Ptr[BarometerId].Barometer_Channel, BMP085_ADDRESS, &BMP085_AC1_MSB_REG, &BMP085_Read_CalibrationData_Values, NUMBER_OF_8BIT_EEPROM_REGS);

	/*
	 * loop to get the actual value of the 11 calibration parameter
	 * Calibration parmeters used {AC1,AC2,AC3,AC4,AC5,AC6,B1,B2,MB,MC,MD}
	 */
	uint8 Counter = 0;
	for(Counter ; Counter < NUMBER_OF_CALIBRATION_PARAM; Counter++ ){

		/*
		 * cal_param = (uint16)cal_parm_MSB <<8 + cal_parm_LSB
		 */
		DataBufferPointer[Counter] = (uint16) BMP085_Read_CalibrationData_Values[Counter*2]<<8 + BMP085_Read_CalibrationData_Values[Counter*2 +1];
	}

}
/************************************************************************************
 * Service Name: BMP085_Get_UT
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): DataBufferPointer - Pointer to Uncompensated temprature value
 * 					BarometerId
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to read the uncompensated temperature value.
 ************************************************************************************/
void BMP085_Get_UT(BMP085_ChannelIdType BarometerId, BMP085_DataType *DataBufferPointer){

	/*
	 * array used in memread function to read UT registers
	 * {UT_MSB,UT_LSB}
	 */
	uint8 BMP085_Read_UT_Values[NUMBER_OF_8BIT_UT_REGS];


	uint8 Control_Reg_Value = BMP085_TEMPERATURE_MEASUREMENT_CONTROL_REG_VALUE;


	Twi_MemWrite(Barometer_Ptr[BarometerId].Barometer_Channel, BMP085_ADDRESS, &BMP085_CONTROL_REG , &Control_Reg_Value, ONE);


	Twi_MemRead(Barometer_Ptr[BarometerId].Barometer_Channel, BMP085_ADDRESS, &BMP085_UT_UP_MSB_REG, &BMP085_Read_UT_Values, NUMBER_OF_8BIT_UT_REGS);

	/*
	 * UT = MSB << 8 + LSB
	 */
	*DataBufferPointer = (uint16) BMP085_Read_UT_UP_Values[UT_MSB]<<8 + BMP085_Read_UT_Values[UT_LSB];


}
/************************************************************************************
 * Service Name: BMP085_Get_UP
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): DataBufferPointer - Pointer to Uncompensated pressure values
 * 					BarometerId
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to read the uncompensated pressure value.
 ************************************************************************************/
void BMP085_Get_UP(BMP085_ChannelIdType BarometerId, BMP085_DataType *DataBufferPointer){

	/*
	 * array used in memread function to read UP registers
	 * {UP_MSB,UP_LSB,UP_XLSB}
	 */
	uint8 BMP085_Read_UP_Values[NUMBER_OF_8BIT_UP_REGS];

	uint8 Control_Reg_Value;

	/*set the control reg. value to be send according to the mode selected (osrs)*/
	switch(Barometer_Ptr[BarometerId].Barometer_Oversampling_Setting_Channel){

	case BMP085_OSRS_0:

		Control_Reg_Value = BMP085_PRESSURE_OSRS0_MEASUREMENT_CONTROL_REG_VALUE + BMP085_OSRS_0<<6;
		break;

	case BMP085_OSRS_1:

		Control_Reg_Value = BMP085_PRESSURE_OSRS1_MEASUREMENT_CONTROL_REG_VALUE + BMP085_OSRS_0<<6;
		break;

	case BMP085_OSRS_2:

		Control_Reg_Value = BMP085_PRESSURE_OSRS2_MEASUREMENT_CONTROL_REG_VALUE + BMP085_OSRS_0<<6;
		break;

	case BMP085_OSRS_3:

		Control_Reg_Value = BMP085_PRESSURE_OSRS3_MEASUREMENT_CONTROL_REG_VALUE + BMP085_OSRS_0<<6;
		break;
	}

	Twi_MemWrite(Barometer_Ptr[BarometerId].Barometer_Channel, BMP085_ADDRESS, &BMP085_CONTROL_REG , &Control_Reg_Value, ONE);


	Twi_MemRead(Barometer_Ptr[BarometerId].Barometer_Channel, BMP085_ADDRESS, &BMP085_UT_UP_MSB_REG, &BMP085_Read_UP_Values, NUMBER_OF_8BIT_UP_REGS);

	/*
	 * UP = (MSB<<16 + LSB<<8 + XLSB) >> (8-oss)
	 */
	*DataBufferPointer = ( (uint32)BMP085_Read_UP_Values[UP_MSB]<<16 + (uint16)BMP085_Read_UP_Values[UP_LSB]<<8 + BMP085_Read_UP_Values[UP_XLSB]) >> (8 - Barometer_Ptr[BarometerId].Barometer_Oversampling_Setting_Channel);

}
/************************************************************************************
 * Service Name:  BMP085_Calc_Temp
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): BMP085_Cal_Parm - Pointer to Calibration parmeters used {AC1,AC2,AC3,AC4,AC5,AC6,B1,B2,MB,MC,MD}
 * 					BMP085_Uncompensated_Temp_Value -Pointer to Uncompensated_Temp_Value
 * 					BMP085_Calc_Fact - Pointer to factors used to calculate calibrated temp and pressure {X1,X2,X3,B3,B4,B5,B6,B7}
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: sint32 temperature value in step 0.1 deg. celcius
 * Description: Function to calculate temperature.
 ************************************************************************************/
sint32 BMP085_Calc_Temp( BMP085_DataType *BMP085_Cal_Parm, BMP085_DataType *BMP085_Uncompensated_Temp_Value, BMP085_DataType *BMP085_Calc_Fact ){

	/*
	 * algorithm used in datasheet to Calculate the calibrated temp.
	 * X1 = (UT- AC6) * AC5 / 2^15 					X1 = 4743 long
	 * X2 = MC * 211 / (X1 + MD) 					X2 = -2344 long
	 * B5 = X1 + X2 								B5 = 2399 long
	 * T = (B5 + 8) / 2^4							T = 150
	 */
	sint32 T;
	BMP085_Calc_Fact[X1] = (BMP085_Uncompensated_Temp_Value - (uint16)BMP085_Cal_Parm[AC6] )*(uint16)BMP085_Cal_Parm[AC5] /32768;

	BMP085_Calc_Fact[X2] = (sint32)BMP085_Cal_Parm[MC]*2048 / (BMP085_Calc_Fact[X1] + (sint32)BMP085_Cal_Parm[MD]);

	BMP085_Calc_Fact[B5] = BMP085_Calc_Fact[X1] +BMP085_Calc_Fact[X2];

	T = (BMP085_Calc_Fact[B5] + 8) +16;

	return T;
}
/************************************************************************************
 * Service Name: BMP085_Calc_Pressure
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): BMP085_Cal_Parm - Pointer to Pointer to Calibration parmeters used {AC1,AC2,AC3,AC4,AC5,AC6,B1,B2,MB,MC,MD}
 *					BMP085_Uncompensated_Pressure_Value -Pointer to Uncompensated_pressure_Value
 *					BMP085_Calc_Fact -factors used to calculate calibrated temp and pressure {X1,X2,X3,B3,B4,B5,B6,B7}
 *					OSS - oversampling setting parameter
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: sint32 pressure value in Pa
 * Description: Function to Calculate the calibrated pressure.
 ************************************************************************************/
sint32 BMP085_Calc_Pressure(BMP085_DataType *BMP085_Cal_Parm, BMP085_DataType *BMP085_Uncompensated_Pressure_Value, BMP085_DataType *BMP085_Calc_Fact ,BMP085_oversampling_settingType OSS){

	sint32 P;

	/*
	 * algorithm used in datasheet to Calculate the calibrated pressure.
	 * B6 = B5 - 4000                                     B6 = -1601 long
	 * X1 = (B2 * (B6 * B6 / 2^12 )) / 2^11               X1 = 1 long
	 * X2 = AC2 * B6 / 2^11                               X2 = 56 long
	 * X3 = X1 + X2                                       X3 = 57 long
	 * B3 = ((AC1*4+X3) << oss + 2) / 4                   B3 = 422 long
	 * X1 = AC3 * B6 / 2^13                               X1 = 2810 long
	 * X2 = (B1 * (B6 * B6 / 2^12 )) / 2^16 			  X2 = 59 long
	 * X3 = ((X1 + X2) + 2) / 22 						  X3 = 717 long
	 * B4 = AC4 * (unsigend long)(X3 + 32768) / 215 	  B4 = 33457 unsigned long
	 * B7 = ((unsigned long)UP - B3) * (50000 >> oss) 	  B7 = 1171050000 unsigned long
	 * if (B7 < 0x80000000)
	 * { p = (B7 * 2) / B4 } 		 					  p = 70003 long
	 * else { p = (B7 / B4) * 2 } 								long
	 * X1 = (p / 28 ) * (p / 2^8 )						 X1 = 74529 long
	 * X1 = (X1 * 3038) / 2^16 							 X1 = 3454 long
	 * X2 = (-7357 * p) / 2^16 							 X2 = -7859 long
	 * p = p + (X1 + X2 + 3791) / 2^4
	 * 														p = 69964 press. in Pa long
	 */
	BMP085_Calc_Fact[B6] = BMP085_Calc_Fact[B5] - 4000;

	BMP085_Calc_Fact[X1] = (BMP085_Cal_Parm[B2]*(BMP085_Calc_Fact[B6]*BMP085_Calc_Fact[B6]/4096))/2048;

	BMP085_Calc_Fact[X2] = BMP085_Cal_Parm[AC2]*BMP085_Calc_Fact[B6]/2048;

	BMP085_Calc_Fact[X3] = BMP085_Calc_Fact[X1] + BMP085_Calc_Fact[X2];

	BMP085_Calc_Fact[B3] = ((BMP085_Cal_Parm[AC1]*4+X3)<<OSS +2)/4;

	BMP085_Calc_Fact[X1] = BMP085_Cal_Parm[AC3]*BMP085_Calc_Fact[B6]/8192;

	BMP085_Calc_Fact[X2] = (BMP085_Cal_Parm[B1]*(BMP085_Calc_Fact[B6]*BMP085_Calc_Fact[B6]/4096))/65536;

	BMP085_Calc_Fact[X3] = ((BMP085_Calc_Fact[X1]+BMP085_Calc_Fact[X2])+2)/4;

	BMP085_Calc_Fact[B4] = (uint16)BMP085_Cal_Parm[AC4]* (uint32)(BMP085_Calc_Fact[X3]+32768)/32768;

	BMP085_Calc_Fact[B7] = ((uint32)BMP085_Uncompensated_Pressure_Value - BMP085_Calc_Fact[B3])*(50000>>OSS);

	if ((uint32)BMP085_Calc_Fact[B7] > 0x80000000){

		P = (uint32)BMP085_Calc_Fact[B7]*2 / (uint32)BMP085_Calc_Fact[B4];
	}
	else
	{
		P = ((uint32)BMP085_Calc_Fact[B7] / (uint32)BMP085_Calc_Fact[B4])*2;
	}
	BMP085_Calc_Fact[X1] = (P/256)*(P/256);

	BMP085_Calc_Fact[X1] = (BMP085_Calc_Fact[X1]*3038)/65536;

	BMP085_Calc_Fact[X2] = (-7357*P)/65536;

	P = (BMP085_Calc_Fact[X1] + BMP085_Calc_Fact[X2] + 3791)/16;

	return P;
}

