/******************************************************************************
 * Module: BMP085
 *
 * File Name: BMP085_Regs.h
 *
 * Description: Header file for BMP085 Registers Definitions.
 *
 * Author: Eslam - Taha - Sara
 ******************************************************************************/

#ifndef INC_BMP085_REGS_H_
#define INC_BMP085_REGS_H_

/*control reg.*/
#define BMP085_CONTROL_REG            (*(volatile uint8 *)0xF4)

/* EEPROM calibration registers*/
#define BMP085_AC1_MSB_REG            (*(volatile uint8 *)0xAA)
#define BMP085_AC1_LSB_REG            (*(volatile uint8 *)0xAB)
#define BMP085_AC2_MSB_REG            (*(volatile uint8 *)0xAC)
#define BMP085_AC2_LSB_REG            (*(volatile uint8 *)0xAD)
#define BMP085_AC3_MSB_REG            (*(volatile uint8 *)0xAE)
#define BMP085_AC3_LSB_REG            (*(volatile uint8 *)0xAF)
#define BMP085_AC4_MSB_REG            (*(volatile uint8 *)0xB0)
#define BMP085_AC4_LSB_REG            (*(volatile uint8 *)0xB1)
#define BMP085_AC5_MSB_REG            (*(volatile uint8 *)0xB2)
#define BMP085_AC5_LSB_REG            (*(volatile uint8 *)0xB3)
#define BMP085_AC6_MSB_REG            (*(volatile uint8 *)0xB4)
#define BMP085_AC6_LSB_REG            (*(volatile uint8 *)0xB5)
#define BMP085_B1_MSB_REG             (*(volatile uint8 *)0xB6)
#define BMP085_B1_LSB_REG             (*(volatile uint8 *)0xB7)
#define BMP085_B2_MSB_REG             (*(volatile uint8 *)0xB8)
#define BMP085_B2_LSB_REG             (*(volatile uint8 *)0xB9)
#define BMP085_MB_MSB_REG             (*(volatile uint8 *)0xBA)
#define BMP085_MB_LSB_REG             (*(volatile uint8 *)0xBB)
#define BMP085_MC_MSB_REG             (*(volatile uint8 *)0xBC)
#define BMP085_MC_LSB_REG             (*(volatile uint8 *)0xBD)
#define BMP085_MD_MSB_REG             (*(volatile uint8 *)0xBE)
#define BMP085_MD_LSB_REG             (*(volatile uint8 *)0xBF)

/* uncompensated temp and pressure value registers*/
#define BMP085_UT_UP_MSB_REG          (*(volatile uint8 *)0xF6)
#define BMP085_UT_UP_LSB_REG          (*(volatile uint8 *)0xF7)
#define BMP085_UP_XLSB_REG         	  (*(volatile uint8 *)0xF8)

#endif /* INC_BMP085_REGS_H_ */
