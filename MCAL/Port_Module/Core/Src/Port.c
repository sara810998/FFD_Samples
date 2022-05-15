/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for Port Module.
 *
 * Author: Eslam - Taha - Sara
 ******************************************************************************/

#include <Port.h>
#include <Port_Regs.h>
/* Variable for Port Status */
STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;
/* Pointer to configured Port channels */
STATIC Port_ConfigChannel *Port_Channels = NULL_PTR;
#if (PORT_DEV_ERROR_DETECT == STD_ON)
#include <Det.h>
/* AUTOSAR Version checking between Det and Port Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port.h does not match the expected version"
#endif

#endif

/************************************************************************************
 * Service Name: Port_Init
 * Service ID[hex]: 0x10
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): ConfigPtr - Pointer to post-build configuration data
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Initialize the Port module.
 ************************************************************************************/
void Port_Init(const Port_ConfigType *ConfigPtr) {
	boolean error = FALSE;
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR*/
	if (NULL_PTR == ConfigPtr) {
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
		PORT_E_PARAM_CONFIG);
		error = TRUE;
	} else {
		/* no action*/
	}
#endif
	if (FALSE == error) {
		/* pointers to GPIO registers and RCC register */
		GPIO_RegDef *GPIO_Ptr = NULL_PTR;
		Port_Channels = ConfigPtr->Pins;
		uint32 *rcc54 = 0x40023830;
		*(rcc54) |= 0x000001ff;
		for (uint8 Pin = 0; Pin < PORT_NUMBER_OF_PINS; Pin++) {
			/*
			 * choosing the port to enable its clock by setting the port`s bit in the clock control register.
			 * Assign the pointer to the required port registers
			 */
			switch (Pin / PINS_NUMBER) {
			case PORTA:
				GPIO_Ptr = GPIOA;
				break;
			case PORTB:
				GPIO_Ptr = GPIOB;
				break;
			case PORTC:
				GPIO_Ptr = GPIOC;
				break;
			case PORTD:
				GPIO_Ptr = GPIOD;
				break;
			case PORTE:
				GPIO_Ptr = GPIOE;
				break;
			case PORTF:
				GPIO_Ptr = GPIOF;
				break;
			case PORTG:
				GPIO_Ptr = GPIOG;
				break;
			case PORTH:
				GPIO_Ptr = GPIOH;
				break;
			case PORTI:
				GPIO_Ptr = GPIOI;
				break;
			case PORTJ:
				GPIO_Ptr = GPIOJ;
				break;
			case PORTK:
				GPIO_Ptr = GPIOK;
				break;
			default:
				/* No action required */
				break;
			}

			/*
			 * setting the pin direction
			 * first case Input setting the two bits of the required pin is 00 in MODE register
			 * second case Output setting the two bits of the required pin is 01 in MODE register
			 * third case Alternate function setting the two bits of the required pin is 10 in MODE register
			 * fourth case Analog setting the two bits of the required pin is 11 in MODE register
			 */
			GPIO_Ptr->MODER.val = (GPIO_Ptr->MODER.val
					& (~(0x00000003 << ((Pin % PINS_NUMBER) * 2))))
					| (((uint32) (Port_Channels[Pin].Pin_Direction))
							<< ((Pin % PINS_NUMBER) * 2));

			/*
			 * setting the internal resistor condition :
			 * disable the internal resistor the two bits of the required pin is 00 in PUPD register
			 * enable the pull up resistor the two bits of the required pin is 01 in PUPD register
			 * enable the pull down resistor the two bits of the required pin is 10 in PUPD register
			 */
			GPIO_Ptr->PUPDR.val = (GPIO_Ptr->PUPDR.val
					& (~(0x00000003 << ((Pin % PINS_NUMBER) * 2))))
					| (((uint32) (Port_Channels[Pin].Internal_Resistor))
							<< ((Pin % PINS_NUMBER) * 2));

			/*
			 * setting specific features for direction types
			 */
			switch (Port_Channels[Pin].Pin_Direction) {
			/*
			 * first case Alternate function
			 */
			case PORT_ALT_FUN:
				if ((Pin % PINS_NUMBER) < HALF_PINS_NUMBER) {
					/*
					 * setting the value of the required AF in the four bits that control the pin  in AFL register
					 */
					GPIO_Ptr->AFRL.val = (GPIO_Ptr->AFRL.val
							& (~(0x0000000F << ((Pin % PINS_NUMBER) * 4))))
							| (((uint32) (Port_Channels[Pin].Pin_Mode))
									<< ((Pin % PINS_NUMBER) * 4));
				} else if ((Pin % PINS_NUMBER) >= HALF_PINS_NUMBER) {
					/*
					 * setting the value of the required AF in the four bits that control the pin  in AFH register
					 */
					GPIO_Ptr->AFRH.val = (GPIO_Ptr->AFRH.val
							& (~(0x0000000F
									<< (((Pin - HALF_PINS_NUMBER) % PINS_NUMBER)
											* 4))))
							| (((uint32) (Port_Channels[Pin].Pin_Mode))
									<< (((Pin - HALF_PINS_NUMBER) % PINS_NUMBER)
											* 4));
				} else {
					/* */
				}
				/*
				 * setting the output type :
				 * first case Push-pull setting the bit of the required pin is 0 in OTYPE register
				 * second case Open Drain setting the bit of the required pin is 1 in OTYPE register
				 */
				GPIO_Ptr->OTYPER.val = (GPIO_Ptr->OTYPER.val
						& (~(0x0001 << ((Pin % PINS_NUMBER)))))
						| (((uint32) (Port_Channels[Pin].Pin_OutpotType))
								<< ((Pin % PINS_NUMBER)));
				/*
				 * setting the output speed
				 * setting speed as low the two  bits of the required pins is 00 in OSPEED register
				 * setting speed as medium the two  bits of the required pins is 01 in OSPEED register
				 * setting speed as high the two  bits of the required pins is 10 in OSPEED register
				 * setting speed as very high the two  bits of the required pins is 11 in OSPEED register
				 */
				GPIO_Ptr->OSPEEDR.val = (GPIO_Ptr->OSPEEDR.val
						& (~(0x00000003 << ((Pin % PINS_NUMBER) * 2))))
						| (((uint32) (Port_Channels[Pin].Pin_OutpotSpeed))
								<< ((Pin % PINS_NUMBER) * 2));
				break;
				/*
				 * second case Output
				 */
			case PORT_PIN_OUT:
				/*
				 * setting the initial value :
				 * setting value as High the bit of the required pin is 1 in BSSR register in the first 16 bits
				 * setting value as Low the bit of the required pin is 1 in BSSR register in the last 16 bits
				 */
				switch (Port_Channels[Pin].Pin_InitialValue) {
				case PORT_HIGH:
					GPIO_Ptr->BSRR.val = (0x00000001 << Pin % PINS_NUMBER);
					break;
				case PORT_LOW:
					GPIO_Ptr->BSRR.val = (0x00000001
							<< ((Pin % PINS_NUMBER) + PINS_NUMBER));
					break;
				default:
					/* No action required */
					break;
				}
				/*
				 * setting the output type :
				 * first case Push-pull setting the bit of the required pin is 0 in OTYPE register
				 * second case Open Drain setting the bit of the required pin is 1 in OTYPE register
				 */
				GPIO_Ptr->OTYPER.val = (GPIO_Ptr->OTYPER.val
						& (~(0x0001 << ((Pin % PINS_NUMBER)))))
						| (((uint32) (Port_Channels[Pin].Pin_OutpotType))
								<< ((Pin % PINS_NUMBER)));
				/*
				 * setting the output speed
				 * setting speed as low the two  bits of the required pins is 00 in OSPEED register
				 * setting speed as medium the two  bits of the required pins is 01 in OSPEED register
				 * setting speed as high the two  bits of the required pins is 10 in OSPEED register
				 * setting speed as very high the two  bits of the required pins is 11 in OSPEED register
				 */
				GPIO_Ptr->OSPEEDR.val = (GPIO_Ptr->OSPEEDR.val
						& (~(0x00000003 << ((Pin % PINS_NUMBER) * 2))))
						| (((uint32) (Port_Channels[Pin].Pin_OutpotSpeed))
								<< ((Pin % PINS_NUMBER) * 2));
				break;
			default:
				/* No Action Required */
				break;
			}
		}

		Port_Status = PORT_INITIALIZED;
	} else {
		/* No action required*/
	}
}

/************************************************************************************
 * Service Name: Port_SetPinDirection
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Pin - Port pin ID number
 * 				   Direction - Port Pin Direction
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Set all of Pins direction.
 ************************************************************************************/
#if(PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction) {
	GPIO_RegDef *GPIO_Ptr = NULL_PTR;
	boolean error = FALSE;
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (PORT_NOT_INITIALIZED == Port_Status) {
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
		PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_UNINIT);
		error = TRUE;
	} else {
		/* No Action Required */
	}
	/* Check if the Direction is Changeable before using this function */
	if (Port_Channels[Pin].Pin_DirectionChange == PORT_UNCHANGEABLE) {
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
		PORT_SET_PIN_DIRECTION_SID, PORT_E_DIRECTION_UNCHANGEABLE);
		error = TRUE;
	} else {
		/* No Action Required */
	}
	/* Check if the number of pin is invalid */
	if ((Pin < PA0 || Pin > PK15)) {
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
		PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_PIN);
		error = TRUE;
	} else {
		/* No Action Required */
	}
#endif
	if (FALSE == error) {
		/*
		 *  Assign the pointer to the required port registers
		 */
		switch (Pin / PINS_NUMBER) {
		case PORTA:
			GPIO_Ptr = GPIOA;
			break;
		case PORTB:
			GPIO_Ptr = GPIOB;
			break;
		case PORTC:
			GPIO_Ptr = GPIOC;
			break;
		case PORTD:
			GPIO_Ptr = GPIOD;
			break;
		case PORTE:
			GPIO_Ptr = GPIOE;
			break;
		case PORTF:
			GPIO_Ptr = GPIOF;
			break;
		case PORTG:
			GPIO_Ptr = GPIOG;
			break;
		case PORTH:
			GPIO_Ptr = GPIOH;
			break;
		case PORTI:
			GPIO_Ptr = GPIOI;
			break;
		case PORTJ:
			GPIO_Ptr = GPIOJ;
			break;
		case PORTK:
			GPIO_Ptr = GPIOK;
			break;
		}
		/*
		 * setting the pin direction
		 * first case Input setting the two bits of the required pin is 00 in MODE register
		 * second case Output setting the two bits of the required pin is 01 in MODE register
		 */
		GPIO_Ptr->MODER.val = (GPIO_Ptr->MODER.val
				& (~(0x00000003 << ((Pin % PINS_NUMBER) * 2))))
				| (((uint32) (Port_Channels[Pin].Pin_Direction))
						<< ((Pin % PINS_NUMBER) * 2));
		if (Port_Channels[Pin].Pin_Direction == PORT_PIN_OUT) {
			/*
			 * setting the initial value :
			 * setting value as High the bit of the required pin is 1 in BSSR register in the first 16 bits
			 * setting value as Low the bit of the required pin is 1 in BSSR register in the last 16 bits
			 */
			switch (Port_Channels[Pin].Pin_InitialValue) {
			case PORT_HIGH:
				GPIO_Ptr->BSRR.val = (0x00000001 << Pin % PINS_NUMBER);
				break;
			case PORT_LOW:
				GPIO_Ptr->BSRR.val = (0x00000001
						<< ((Pin % PINS_NUMBER) + PINS_NUMBER));
				break;
			default:
				/* No action required */
				break;
			}
		} else {
			/* No action required*/
		}
	} else {
		/* No Action Required */
	}
}
#endif
/************************************************************************************
 * Service Name: Port_RefreshPortDirection
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Refresh port direction.
 ************************************************************************************/

void Port_RefreshPortDirection(void) {
	boolean error = FALSE;
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (PORT_NOT_INITIALIZED == Port_Status) {
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
		PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_UNINIT);
		error = TRUE;
	} else {
		/* No Action Required */
	}
#endif
	if (FALSE == error) {
		GPIO_RegDef *GPIO_Ptr = NULL_PTR;
		/*using a variable to store the first value of MODER to refresh it */
		uint32 temp;
		/* refreshing Port A */
		GPIO_Ptr = GPIOA;
		temp = GPIO_Ptr->MODER.val;
		GPIO_Ptr->MODER.val = temp;
		/* refreshing Port B */
		GPIO_Ptr = GPIOB;
		temp = GPIO_Ptr->MODER.val;
		GPIO_Ptr->MODER.val = temp;
		/* refreshing Port C */
		GPIO_Ptr = GPIOC;
		temp = GPIO_Ptr->MODER.val;
		GPIO_Ptr->MODER.val = temp;
		/* refreshing Port D */
		GPIO_Ptr = GPIOD;
		temp = GPIO_Ptr->MODER.val;
		GPIO_Ptr->MODER.val = temp;
		/* refreshing Port E */
		GPIO_Ptr = GPIOE;
		temp = GPIO_Ptr->MODER.val;
		GPIO_Ptr->MODER.val = temp;
		/* refreshing Port F */
		GPIO_Ptr = GPIOF;
		temp = GPIO_Ptr->MODER.val;
		GPIO_Ptr->MODER.val = temp;
		/* refreshing Port G */
		GPIO_Ptr = GPIOG;
		temp = GPIO_Ptr->MODER.val;
		GPIO_Ptr->MODER.val = temp;
		/* refreshing Port H */
		GPIO_Ptr = GPIOH;
		temp = GPIO_Ptr->MODER.val;
		GPIO_Ptr->MODER.val = temp;
		/* refreshing Port I */
		GPIO_Ptr = GPIOI;
		temp = GPIO_Ptr->MODER.val;
		GPIO_Ptr->MODER.val = temp;
		/* refreshing Port J */
		GPIO_Ptr = GPIOJ;
		temp = GPIO_Ptr->MODER.val;
		GPIO_Ptr->MODER.val = temp;
		/* refreshing Port K */
		GPIO_Ptr = GPIOK;
		temp = GPIO_Ptr->MODER.val;
		GPIO_Ptr->MODER.val = temp;
	} else {
		/* No action required */
	}
}

/************************************************************************************
 * Service Name: Port_GetVersionInfo
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): VersionInfo - Pointer to where to store the version information of this module.
 * Return value: None
 * Description: Function to get the version information of this module.
 ************************************************************************************/

#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not Null pointer */
	if(NULL_PTR == versioninfo)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
	}
	else
#endif
	{
		/* Copy the vendor Id */
		versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)PORT_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}
}
#endif

/************************************************************************************
 * Service Name: Port_SetPinMode
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): 	Pin : Port Pin ID number
 * 					Mode: New Port Pin mode to be set on port pin.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to set the port pin mode..
 ************************************************************************************/
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode) {
	boolean error = FALSE;
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (PORT_NOT_INITIALIZED == Port_Status) {
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
		PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_UNINIT);
		error = TRUE;
	} else {
		/* No Action Required */
	}
	/* Check if the number of pin is invalid */
	if ((Pin < PA0 || Pin > PK15)) {
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
		PORT_SET_PIN_MODE_SID, PORT_E_PARAM_PIN);
		error = TRUE;
	} else {
		/* No Action Required */
	}
	/* Check if the Mode is Changeable before using this function */
	if (Port_Channels[Pin].Pin_ModeChange == PORT_UNCHANGE) {
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
		PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
		error = TRUE;
	} else {
		/* No Action Required */
	}
	/* Check if the Mode is Valid before using this function */
	if (Mode < PORT_AF0 || Mode > PORT_AF_ANALOG_) {
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
		PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
		error = TRUE;
	} else {
		/* No Action Required */
	}
#endif
	if (FALSE == error) {
		GPIO_RegDef *GPIO_Ptr = NULL_PTR;
		/*
		 *  Assign the pointer to the required port registers
		 */
		switch (Pin / PINS_NUMBER) {
		case PORTA:
			GPIO_Ptr = GPIOA;
			break;
		case PORTB:
			GPIO_Ptr = GPIOB;
			break;
		case PORTC:
			GPIO_Ptr = GPIOC;
			break;
		case PORTD:
			GPIO_Ptr = GPIOD;
			break;
		case PORTE:
			GPIO_Ptr = GPIOE;
			break;
		case PORTF:
			GPIO_Ptr = GPIOF;
			break;
		case PORTG:
			GPIO_Ptr = GPIOG;
			break;
		case PORTH:
			GPIO_Ptr = GPIOH;
			break;
		case PORTI:
			GPIO_Ptr = GPIOI;
			break;
		case PORTJ:
			GPIO_Ptr = GPIOJ;
			break;
		case PORTK:
			GPIO_Ptr = GPIOK;
			break;
		}
		/*
		 * checking the mode if the it is analog or an alternate function
		 */
		switch (Mode) {
		case PORT_AF_ANALOG_:
			/*
			 * setting direction as  Alternate function  the two bits of the required pin is 11 in MODE register
			 */
			SET_BIT(GPIO_Ptr->MODER.val, (2*(Pin % PINS_NUMBER)));
			SET_BIT(GPIO_Ptr->MODER.val, (2*(Pin % PINS_NUMBER)+1));
			break;
		default:
			/*
			 * setting direction as  Alternate function  the two bits of the required pin is 10 in MODE register
			 */
			CLEAR_BIT(GPIO_Ptr->MODER.val, (2*(Pin % PINS_NUMBER)));
			SET_BIT(GPIO_Ptr->MODER.val, (2*(Pin % PINS_NUMBER)+1));
			/*
			 * checking the pin is controled by which register AFL or AFH
			 */
			if ((Pin % PINS_NUMBER) < HALF_PINS_NUMBER) {
				/*
				 * setting the value of the required AF in the four bits that control the pin  in AFL register
				 */
				GPIO_Ptr->AFRL.val = (GPIO_Ptr->AFRL.val
						& (~(0x0000000F << ((Pin % PINS_NUMBER) * 4))))
						| (((uint32) (Port_Channels[Pin].Pin_Mode))
								<< ((Pin % PINS_NUMBER) * 4));
			} else if ((Pin % PINS_NUMBER) >= HALF_PINS_NUMBER) {
				/*
				 * setting the value of the required AF in the four bits that control the pin  in AFH register
				 */
				GPIO_Ptr->AFRH.val =
						(GPIO_Ptr->AFRH.val
								& (~(0x0000000F
										<< (((Pin - HALF_PINS_NUMBER)
												% PINS_NUMBER) * 4))))
								| (((uint32) (Port_Channels[Pin].Pin_Mode))
										<< (((Pin - HALF_PINS_NUMBER)
												% PINS_NUMBER) * 4));
			} else {
				/* No action required */
			}
			break;
		}
	}

}
