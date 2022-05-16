/******************************************************************************
 * Module: BMP085
 *
 * File Name: BMP085.h
 *
 * Description: Header file for BMP085 module.
 *
 * Author: Eslam - Taha - Sara
 ******************************************************************************/

#ifndef INC_BMP085_H_
#define INC_BMP085_H_


/******************************************************************************
 *                                INCLUDES                                    *
 ******************************************************************************/

#include "Std_Types.h"
#include "BMP085_Regs.h"
#include "BMP085_Cfg.h"

/*BMP085 module address*/
#define BMP085_ADDRESS (uint8)(0x77)

/*
 *  Control registers values for different internal oversampling_setting (osrs)
 *   according to the mode
 *  Ultra low power
 *  standard
 *  high resolution
 *  ultra high resolution
 */
#define BMP085_TEMPERATURE_MEASUREMENT_CONTROL_REG_VALUE 	(uint8)(0x2E)
#define BMP085_PRESSURE_OSRS0_MEASUREMENT_CONTROL_REG_VALUE (uint8)(0x34)
#define BMP085_PRESSURE_OSRS1_MEASUREMENT_CONTROL_REG_VALUE (uint8)(0x74)
#define BMP085_PRESSURE_OSRS2_MEASUREMENT_CONTROL_REG_VALUE (uint8)(0xB4)
#define BMP085_PRESSURE_OSRS3_MEASUREMENT_CONTROL_REG_VALUE (uint8)(0xF4)

/*
 *  Definition for calibration factors index in BMP085_Get_Cal_Parm array in BMP085 APIs
 */
#define AC1 (0U)
#define AC2 (1U)
#define AC3 (2U)
#define AC4 (3U)
#define AC5 (4U)
#define AC6 (5U)
#define B1  (6U)
#define B2  (7U)
#define MB  (8U)
#define MC  (9U)
#define MD  (10U)

/*
 *  Definition for uncompensated temp register index in  BMP085_Read_UT_Values in BMP085 APIs
 */
#define UT_MSB (0U)
#define UT_LSB (1U)

/*
 *  Definition for uncompensated pressure register index in BMP085_Read_UP_Values in BMP085 APIs
 */
#define UP_MSB  (0U)
#define UP_LSB  (1U)
#define UP_XLSB (3U)

/*
 *  Definition for calculation factors index in BMP085_Calc_Factors array used to calibrate uncompensated values in BMP085 APIs
 */
#define X1 (0U)
#define X2 (1U)
#define X3 (3U)
#define B3 (4U)
#define B4 (5U)
#define B5 (6U)
#define B6 (7U)
#define B7 (8U)

/* Definition for 0 and 1*/
#define ONE (1U)
#define ZERO (0U)

#define NUMBER_OF_CALIBRATION_PARAM 	(11U) /*calibration parmeters*/
#define NUMBER_OF_8BIT_EEPROM_REGS  	(22U) /*calibration parmeters registers*/
#define NUMBER_OF_8BIT_UT_REGS			(2U) /*uncompensated temp registers*/
#define NUMBER_OF_8BIT_UP_REGS			(3U) /*uncompensated pressure registers*/
#define NUMBER_OF_CALCULATION_FACTORS   (9U) /*calculation factors*/

/*Definition for BMP085 Initialization State*/
#define BMP085_INITIALIZED                (1U)
#define BMP085_NOT_INITIALIZED            (0U)

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
/* Type definition for BMP085_ChannelIdTypee used by the BMP085 Module APIs */
typedef enum
{
	BMP085_BAROMETER_1
}BMP085_ChannelIdType;

/* Type definition for BMP085_ChannelType used by the  BMP085 Module APIs */
typedef enum{
	BMP085_BAROMETER_TWI_CH_1 ,
	BMP085_BAROMETER_TWI_CH_2 ,
	BMP085_BAROMETER_TWI_CH_3
}BMP085_ChannelType;

/* Type definition for BMP085_oversampling_settingType used by the  BMP085 Module APIs */
typedef enum{
	BMP085_OSRS_0,
	BMP085_OSRS_1,
	BMP085_OSRS_2,
	BMP085_OSRS_3
}BMP085_oversampling_settingType;

/* Type definition for BMP085_AddressType used by the BMP085 module APIs */
typedef uint8 BMP085_AddressType ;

/* Type definition for BMP085_DataType used by the BMP085 module APIs */
typedef uint16 BMP085_DataType ;

/* Type definition for BMP085_DataSizeType used by the BMP085 module APIs */
typedef uint8 BMP085_DataSizeType ;

/* Type definition for BMP085_DataType used by the BMP085 module APIs */
typedef float32 BMP085_ValueType ;


typedef struct
{
	/* barometer  ID */
	BMP085_ChannelIdType Barometer_Id;
	/* barometer channel configured */
	BMP085_ChannelType Barometer_Channel;
	/* barometer oversampling_settingType */
	BMP085_oversampling_settingType Barometer_Oversampling_Setting_Channel;

}BMP085_ConfigChannel;

/* Structure used in BMP085 Module init */
typedef struct {
	BMP085_ConfigChannel BMP085_Channels[NUMBER_OF_BMP085_BAROMETERS];
} BMP085_ConfigType;
/*****************************************************************************************
 *					Function Prototypes
 ******************************************************************************************/
void BMP085_Init(const BMP085_ConfigType* ConfigPtr);

sint32 BMP085_Get_Temp(BMP085_ChannelIdType BarometerId);

sint32 BMP085_Get_Pressure(BMP085_ChannelIdType BarometerId);

float32 BMP085_Get_Altitude(BMP085_ChannelIdType BarometerId, BMP085_ValueType SeaLevel_Pressure);

float32 BMP085_Get_SeaLevel_Pressure(BMP085_ChannelIdType BarometerId, BMP085_ValueType Absolute_Altitude);
/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by BMP085 */
extern const BMP085_ConfigType BMP085_Configuration;

#endif /* INC_BMP085_H_ */
