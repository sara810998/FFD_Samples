/******************************************************************************
 * Module: BMP085
 *
 * File Name: BMP085_Cfg.h
 *
 * Description: Header file for BMP085 Module Configurations.
 *
 * Author: Eslam - Taha - Sara
 ******************************************************************************/

#ifndef INC_BMP085_CFG_H_
#define INC_BMP085_CFG_H_

/*number of barometers connected*/
#define NUMBER_OF_BMP085_BAROMETERS (1U)

/*
 * enable or disable APIs according to the use of BMP085 Module
 * to measure temperature
 * to measure pressure in Pa
 * to measure altitude in meter
 * to measure pressure at sea level in pa
 */
#define ENABLE_GET_TEMP_API 			  (STD_OFF)
#define ENABLE_GET_PRESSURE_API			  (STD_OFF)
#define ENABLE_GET_ALTITUDE_API 		  (STD_ON)
#define ENABLE_GET_SEA_LEVEL_PRESSURE_API (STD_OFF)

/*enable EOC pin if connected to the MC to give high*/
#define BMP085_ENABLE_END_OF_CONVERSION_PIN (STD_OFF)

/*BMP085 configuration parameters*/
#define BMP085_1_CHANNEL_ID		BMP085_BAROMETER_1
#define BMP085_1_TWI_CHANNEL_ID	BMP085_BAROMETER_TWI_CH_1
#define BMP085_1_OVERSAMPLING_SETTING	BMP085_OSRS_0

/**/
#if (BMP085_ENABLE_END_OF_CONVERSION_PIN == STD_ON)
#define BMP085_END_OF_CONVERSION_PIN  BMP085_DEFAULT_END_OF_CONVERSION_PIN
#endif


#endif /* INC_BMP085_CFG_H_ */
