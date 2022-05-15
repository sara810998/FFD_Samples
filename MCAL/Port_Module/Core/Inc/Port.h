 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for Port Module.
 *
 * Author: Eslam - Taha - Sara
 ******************************************************************************/

#ifndef INC_PORT_H_
#define INC_PORT_H_

/* Id for the company in the AUTOSAR  */
#define PORT_VENDOR_ID    (1000U)

/* Port Module Id */
#define PORT_MODULE_ID    (120U)

/* Port Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for Port Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)
/*
 * Number of pins on port
 */
#define PORT_NUMBER_OF_PINS 			(176U)

/* Standard AUTOSAR types */
#include <Std_Types.h>
/* AUTOSAR checking between Std Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Port Pre-Compile Configuration Header file */
#include<Port_Cfg.h>
/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif

/* Non AUTOSAR files */
#include <Common_Macros.h>


/*******************************************************************************
 *                      Definitions for Module                                *
 *******************************************************************************/

/* Number of pins in one port */
#define PINS_NUMBER								(16U)
#define HALF_PINS_NUMBER						(8U)

/* Definition for Ports */
#define	PORTA	(0U)
#define	PORTB	(1U)
#define	PORTC	(2U)
#define	PORTD	(3U)
#define	PORTE	(4U)
#define	PORTF	(5U)
#define	PORTG	(6U)
#define	PORTH	(7U)
#define	PORTI	(8U)
#define	PORTJ	(9U)
#define	PORTK	(10U)

/* Definition for PORTA Pins */
#define PA0			(0U)
#define PA1			(1U)
#define PA2			(2U)
#define PA3			(3U)
#define PA4			(4U)
#define PA5			(5U)
#define PA6			(6U)
#define PA7			(7U)
#define PA8			(8U)
#define PA9			(9U)
#define PA10		(10U)
#define PA11		(11U)
#define PA12		(12U)
#define PA13		(13U)
#define PA14		(14U)
#define PA15		(15U)
/* Definition for PORTB Pins */
#define PB0			(16U)
#define PB1			(17U)
#define PB2			(18U)
#define PB3			(19U)
#define PB4			(20U)
#define PB5			(21U)
#define PB6			(22U)
#define PB7			(23U)
#define PB8			(24U)
#define PB9			(25U)
#define PB10		(26U)
#define PB11		(27U)
#define PB12		(28U)
#define PB13		(29U)
#define PB14		(30U)
#define PB15		(31U)
/* Definition for PORTC Pins */
#define PC0			(32U)
#define PC1			(33U)
#define PC2			(34U)
#define PC3			(35U)
#define PC4			(36U)
#define PC5			(37U)
#define PC6			(38U)
#define PC7			(39U)
#define PC8			(40U)
#define PC9			(41U)
#define PC10		(42U)
#define PC11		(43U)
#define PC12		(44U)
#define PC13		(45U)
#define PC14		(46U)
#define PC15		(47U)
/* Definition for PORTD Pins */
#define PD0			(48U)
#define PD1			(49U)
#define PD2			(50U)
#define PD3			(51U)
#define PD4			(52U)
#define PD5			(53U)
#define PD6			(54U)
#define PD7			(55U)
#define PD8			(56U)
#define PD9			(57U)
#define PD10		(58U)
#define PD11		(59U)
#define PD12		(60U)
#define PD13		(61U)
#define PD14		(62U)
#define PD15		(63U)
/* Definition for PORTE Pins */
#define PE0			(64U)
#define PE1			(65U)
#define PE2			(66U)
#define PE3			(67U)
#define PE4			(68U)
#define PE5			(69U)
#define PE6			(70U)
#define PE7			(71U)
#define PE8			(72U)
#define PE9			(73U)
#define PE10		(74U)
#define PE11		(75U)
#define PE12		(76U)
#define PE13		(77U)
#define PE14		(78U)
#define PE15		(79U)
/* Definition for PORTF Pins */
#define PF0			(80U)
#define PF1			(81U)
#define PF2			(82U)
#define PF3			(83U)
#define PF4			(84U)
#define PF5			(85U)
#define PF6			(86U)
#define PF7			(87U)
#define PF8			(88U)
#define PF9			(89U)
#define PF10		(90U)
#define PF11		(91U)
#define PF12		(92U)
#define PF13		(93U)
#define PF14		(94U)
#define PF15		(95U)
/* Definition for PORTG Pins */
#define PG0			(96U)
#define PG1			(97U)
#define PG2			(98U)
#define PG3			(99U)
#define PG4			(100U)
#define PG5			(101U)
#define PG6			(102U)
#define PG7			(103U)
#define PG8			(104U)
#define PG9			(105U)
#define PG10		(106U)
#define PG11		(107U)
#define PG12		(108U)
#define PG13		(109U)
#define PG14		(110U)
#define PG15		(111U)
/* Definition for PORTH Pins */
#define PH0			(112U)
#define PH1			(113U)
#define PH2			(114U)
#define PH3			(115U)
#define PH4			(116U)
#define PH5			(117U)
#define PH6			(118U)
#define PH7			(119U)
#define PH8			(120U)
#define PH9			(121U)
#define PH10		(122U)
#define PH11		(123U)
#define PH12		(124U)
#define PH13		(125U)
#define PH14		(126U)
#define PH15		(127U)
/* Definition for PORTI Pins */
#define PI0			(128U)
#define PI1			(129U)
#define PI2			(130U)
#define PI3			(131U)
#define PI4			(132U)
#define PI5			(133U)
#define PI6			(134U)
#define PI7			(135U)
#define PI8			(136U)
#define PI9			(137U)
#define PI10		(138U)
#define PI11		(139U)
#define PI12		(140U)
#define PI13		(141U)
#define PI14		(142U)
#define PI15		(143U)
/* Definition for PORTJ Pins */
#define PJ0			(144U)
#define PJ1			(145U)
#define PJ2			(146U)
#define PJ3			(147U)
#define PJ4			(148U)
#define PJ5			(149U)
#define PJ6			(150U)
#define PJ7			(151U)
#define PJ8			(152U)
#define PJ9			(153U)
#define PJ10		(154U)
#define PJ11		(155U)
#define PJ12		(156U)
#define PJ13		(157U)
#define PJ14		(158U)
#define PJ15		(159U)
/* Definition for PORTK Pins */
#define PK0			(160U)
#define PK1			(161U)
#define PK2			(162U)
#define PK3			(163U)
#define PK4			(164U)
#define PK5			(165U)
#define PK6			(166U)
#define PK7			(167U)
#define PK8			(168U)
#define PK9			(169U)
#define PK10		(170U)
#define PK11		(171U)
#define PK12		(172U)
#define PK13		(173U)
#define PK14		(174U)
#define PK15		(175U)

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for PORT Init*/
#define PORT_INIT_SID 					(uint8)0x10

/* Service ID for PORT set pin direction*/
#define PORT_SET_PIN_DIRECTION_SID		(uint8)0x01

/* Service ID for PORT refresh direction*/
#define PORT_REFRESH_PORT_DIRECTION_SID	(uint8)0x02

/* Service ID for PORT get version info*/
#define PORT_GET_VERSION_INFO_SID		(uint8)0x03

/* Service ID for PORT set pin mode*/
#define PORT_SET_PIN_MODE_SID			(uint8)0x04
/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/*DET code for Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN 				(uint8)0x0A

/*DET code for Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE 	(uint8)0x0B

/*DET code for API Port_Init service called with wrong parameter */
#define PORT_E_PARAM_CONFIG 			(uint8)0x0C

/* DET code for API Port_SetPinMode service called when mode is unchangeable*/
#define PORT_E_PARAM_INVALID_MODE 		(uint8)0x0D
#define PORT_E_MODE_UNCHANGEABLE  		(uint8)0x0E

/* DET code for API service called without module initialization */
#define PORT_E_UNINIT 					(uint8)0x0F

/* DET code for APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER 			(uint8)0x010


/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
/* Type definition for Pin_PinType used by the PIN APIs */
 typedef uint8	Port_PinType;

 /* Type definition for Port_PinLevel used by the PIN APIs */
  typedef enum{
	  PORT_LOW,
	  PORT_HIGH
  }Port_PinLevel;

/* Type definition for Pin_DirectionType used by the PIN APIs */
 typedef enum
 {
	  PORT_PIN_IN,  PORT_PIN_OUT ,PORT_ALT_FUN , PORT_ANALOG
 }Port_PinDirectionType;

 /* Type definition for Pin_DirectionType used by the PIN APIs */
  typedef enum
  {
 	 PORT_NONE,PORT_PULL_UP,PORT_PULL_DOWN
  }Port_InternalResistor;

 /* Type definition for Port_PinDirectionChange used by the PIN APIs */
  typedef enum
  {
	  PORT_UNCHANGEABLE,PORT_CHANGEABLE
  }Port_PinDirectionChange;

 /* Type definition for Port_PinModeType used by the PIN APIs */
 typedef uint8 	Port_PinModeType;

 /* Type definition for Port_PinModeChange used by the PIN APIs */
 typedef enum
  {
 	 PORT_UNCHANGE,PORT_CHANGE
  }Port_PinModeChange;

  /* Type definition for Port_PinAF used by the PIN APIs */
   typedef enum
    {
   	 PORT_AF0,
	 PORT_AF1,
	 PORT_AF2,
	 PORT_AF3,
	 PORT_AF4,
	 PORT_AF5,
	 PORT_AF6,
	 PORT_AF7,
	 PORT_AF8,
	 PORT_AF9,
	 PORT_AF10,
	 PORT_AF11,
	 PORT_AF12,
	 PORT_AF13,
	 PORT_AF14,
	 PORT_AF15,
	 PORT_AF_ANALOG_
    }Port_PinMode;
  /* Type definition for Port_PinModeChange used by the PIN APIs */
  typedef enum
  {
	  PORT_PUSH_PULL,PORT_OPEN_DRAIN
  }Port_PinOutputType;

  /* Type definition for Port_PinOutputSpeed used by the PIN APIs */
  typedef enum
  {
	  PORT_LOW_SPEED,PORT_MEDIUM_SPEED,PORT_HIGH_SPEED,PORT_VERY_HIGH_SPEED
  }Port_PinOutputSpeed;

 /* Structure for Port_ConfigGroup */
 typedef struct
 {
	/* Member contains the ID of the Pin*/
	Port_PinType Pin_Id;
	/* Member contains the Direction of the Pin*/
	Port_PinDirectionType Pin_Direction;
	/* Member contains the Direction of the Pin*/
	Port_PinLevel Pin_InitialValue;
	/* Member contains the Change in direction of the Pin*/
	Port_PinDirectionChange Pin_DirectionChange;
	/* Member contains the Mode of the Pin*/
	Port_PinModeType Pin_Mode;
	/* Member contains the Change in Mode of the Pin*/
	Port_PinModeChange Pin_ModeChange;
	/* Member contains the value of internal resistor of the Pin*/
	Port_InternalResistor Internal_Resistor;
	/* Member contains the speed of the output of the Pin */
	Port_PinOutputSpeed Pin_OutpotSpeed;
	/* Member contains the type of the output of the Pin */
	Port_PinOutputType Pin_OutpotType;
 }Port_ConfigChannel;

/* Data Structure required for initializing the Port Driver */
typedef struct
{
	Port_ConfigChannel Pins[PORT_NUMBER_OF_PINS];
} Port_ConfigType;



/*******************************************************************************
 *                      Default Configurations                                 *
 *******************************************************************************/

#define DEFAULT_PORTCONF_DIRECTION 			PORT_PIN_OUT
#define DEFAULT_PORTCONF_INITIAL_VALUE 		PORT_HIGH
#define DEFAULT_PORTCONF_DIRECTION_CHANGE 	PORT_UNCHANGEABLE
#define DEFAULT_PORTCONF_MODE				PORT_AF0
#define DEFAULT_PORTCONF_MODE_CHANGE 		PORT_UNCHANGE
#define DEFAULT_PORTCONF_INTERNAL_RESISTOR 	PORT_NONE
#define DEFAULT_PORTCONF_OUTPOT_SPEED 		PORT_LOW_SPEED
#define DEFAULT_PORTCONF_OUTPOT_TYPE		PORT_PUSH_PULL


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
/* Function for PORT Initialization API */
void Port_Init( const Port_ConfigType* ConfigPtr );

/* Function for PORT Set Direction API */
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );

/* Function for PORT Refresh Direction API */
void Port_RefreshPortDirection( void );

/* Function for PORT Version API */
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo );

/* Function for PORT Set Pin Mode API */
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );


/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Port and other modules */
extern const Port_ConfigType Port_Configuration;


#endif /* INC_PORT_H_ */
