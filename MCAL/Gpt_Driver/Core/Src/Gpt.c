/******************************************************************************
 *
 * Module: Gpt
 *
 * File Name: Gpt.c
 *
 * Description: Source file for Gpt Module.
 *
 * Author: Eslam - Taha - Sara
 ******************************************************************************/

#include "Gpt.h"
#include "Gpt_Regs.h"

STATIC uint8 Gpt_Status = GPT_NOT_INITIALIZED;
STATIC Gpt_ConfigChannel *Gpt_PortChannels = NULL_PTR;


#if (GPT_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
/* AUTOSAR Version checking between Det and Port Modules */
#if ((DET_AR_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != GPT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Gpt.h does not match the expected version"
#endif

#endif
/*******************************************************************************
 *                       GPT notification function implemetation                  *
 *******************************************************************************/
void Gpt_Notification_Channel0 (void){

	uint8 channel, Counter;
	/*
	 *  counter loop to assign the (channel) index of channel
	 *  configured to channel 0
	 */
	for (Counter=0;Counter<NUMBER_OF_GPT_CHANNELS;Counter++){

		if(Gpt_PortChannels[Counter].channelIDConfig == GPT_0){
			channel = Counter;
			break;
		}
		else{
			/* no action*/
		}
	}
	/*
	 * check if the pointer of the configuration structure
	 * declared to address or to NULL
	 */
	if ( Gpt_PortChannels[channel].GptNotification != NULL_PTR)
	{	/*
		 * assigning the configured address of callback function
		 * in configuration structure to callback function pointer
		 */
	Gpt_Callback_Pointer[GPT_0] = Gpt_PortChannels[channel].GptNotification;
	}
	else{
		/*no action*/
	}
}
void Gpt_Notification_Channel1 (void){

	uint8 channel, Counter;
		/*
		 *  counter loop to assign the (channel) index of channel
		 *  configured to channel 1
		 */
		for (Counter=0;Counter<NUMBER_OF_GPT_CHANNELS;Counter++){

			if(Gpt_PortChannels[Counter].channelIDConfig == GPT_1){
				channel = Counter;
				break;
			}
			else{
				/* no action*/
			}
		}
		/*
		 * check if the pointer of the configuration structure
		 * declared to address or to NULL
		 */
		if ( Gpt_PortChannels[channel].GptNotification != NULL_PTR)
		{	/*
			 * assigning the configured address of callback function
			 * in configuration structure to callback function pointer
			 */
		Gpt_Callback_Pointer[GPT_1] = Gpt_PortChannels[channel].GptNotification;
		}
		else{
			/*no action*/
		}

}
void Gpt_Notification_Channel2 (void){
	uint8 channel, Counter;
		/*
		 *  counter loop to assign the (channel) index of channel
		 *  configured to channel 2
		 */
		for (Counter=0;Counter<NUMBER_OF_GPT_CHANNELS;Counter++){

			if(Gpt_PortChannels[Counter].channelIDConfig == GPT_2){
				channel = Counter;
				break;
			}
			else{
				/* no action*/
			}
		}
		/*
		 * check if the pointer of the configuration structure
		 * declared to address or to NULL
		 */
		if ( Gpt_PortChannels[channel].GptNotification != NULL_PTR)
		{	/*
			 * assigning the configured address of callback function
			 * in configuration structure to callback function pointer
			 */
		Gpt_Callback_Pointer[GPT_2] = Gpt_PortChannels[channel].GptNotification;
		}
		else{
			/*no action*/
		}
}
void Gpt_Notification_Channel3 (void){

	uint8 channel, Counter;
		/*
		 *  counter loop to assign the (channel) index of channel
		 *  configured to channel 3
		 */
		for (Counter=0;Counter<NUMBER_OF_GPT_CHANNELS;Counter++){

			if(Gpt_PortChannels[Counter].channelIDConfig == GPT_3){
				channel = Counter;
				break;
			}
			else{
				/* no action*/
			}
		}
		/*
		 * check if the pointer of the configuration structure
		 * declared to address or to NULL
		 */
		if ( Gpt_PortChannels[channel].GptNotification != NULL_PTR)
		{	/*
			 * assigning the configured address of callback function
			 * in configuration structure to callback function pointer
			 */
		Gpt_Callback_Pointer[GPT_3] = Gpt_PortChannels[channel].GptNotification;
		}
		else{
			/*no action*/
		}

}
void Gpt_Notification_Channel4 (void){
	uint8 channel, Counter;
		/*
		 *  counter loop to assign the (channel) index of channel
		 *  configured to channel 4
		 */
		for (Counter=0;Counter<NUMBER_OF_GPT_CHANNELS;Counter++){

			if(Gpt_PortChannels[Counter].channelIDConfig == GPT_4){
				channel = Counter;
				break;
			}
			else{
				/* no action*/
			}
		}
		/*
		 * check if the pointer of the configuration structure
		 * declared to address or to NULL
		 */
		if ( Gpt_PortChannels[channel].GptNotification != NULL_PTR)
		{	/*
			 * assigning the configured address of callback function
			 * in configuration structure to callback function pointer
			 */
		Gpt_Callback_Pointer[GPT_4] = Gpt_PortChannels[channel].GptNotification;
		}
		else{
			/*no action*/
		}
}
void Gpt_Notification_Channel5 (void){
	uint8 channel, Counter;
		/*
		 *  counter loop to assign the (channel) index of channel
		 *  configured to channel 5
		 */
		for (Counter=0;Counter<NUMBER_OF_GPT_CHANNELS;Counter++){

			if(Gpt_PortChannels[Counter].channelIDConfig == GPT_5){
				channel = Counter;
				break;
			}
			else{
				/* no action*/
			}
		}
		/*
		 * check if the pointer of the configuration structure
		 * declared to address or to NULL
		 */
		if ( Gpt_PortChannels[channel].GptNotification != NULL_PTR)
		{	/*
			 * assigning the configured address of callback function
			 * in configuration structure to callback function pointer
			 */
		Gpt_Callback_Pointer[GPT_5] = Gpt_PortChannels[channel].GptNotification;
		}
		else{
			/*no action*/
		}

}
void Gpt_Notification_Channel6 (void){
	uint8 channel, Counter;
		/*
		 *  counter loop to assign the (channel) index of channel
		 *  configured to channel 6
		 */
		for (Counter=0;Counter<NUMBER_OF_GPT_CHANNELS;Counter++){

			if(Gpt_PortChannels[Counter].channelIDConfig == GPT_6){
				channel = Counter;
				break;
			}
			else{
				/* no action*/
			}
		}
		/*
		 * check if the pointer of the configuration structure
		 * declared to address or to NULL
		 */
		if ( Gpt_PortChannels[channel].GptNotification != NULL_PTR)
		{	/*
			 * assigning the configured address of callback function
			 * in configuration structure to callback function pointer
			 */
		Gpt_Callback_Pointer[GPT_6] = Gpt_PortChannels[channel].GptNotification;
		}
		else{
			/*no action*/
		}
}
void Gpt_Notification_Channel7 (void){
	uint8 channel, Counter;
		/*
		 *  counter loop to assign the (channel) index of channel
		 *  configured to channel 7
		 */
		for (Counter=0;Counter<NUMBER_OF_GPT_CHANNELS;Counter++){

			if(Gpt_PortChannels[Counter].channelIDConfig == GPT_7){
				channel = Counter;
				break;
			}
			else{
				/* no action*/
			}
		}
		/*
		 * check if the pointer of the configuration structure
		 * declared to address or to NULL
		 */
		if ( Gpt_PortChannels[channel].GptNotification != NULL_PTR)
		{	/*
			 * assigning the configured address of callback function
			 * in configuration structure to callback function pointer
			 */
		Gpt_Callback_Pointer[GPT_7] = Gpt_PortChannels[channel].GptNotification;
		}
		else{
			/*no action*/
		}
}
void Gpt_Notification_Channel8 (void){
	uint8 channel, Counter;
		/*
		 *  counter loop to assign the (channel) index of channel
		 *  configured to channel 8
		 */
		for (Counter=0;Counter<NUMBER_OF_GPT_CHANNELS;Counter++){

			if(Gpt_PortChannels[Counter].channelIDConfig == GPT_8){
				channel = Counter;
				break;
			}
			else{
				/* no action*/
			}
		}
		/*
		 * check if the pointer of the configuration structure
		 * declared to address or to NULL
		 */
		if ( Gpt_PortChannels[channel].GptNotification != NULL_PTR)
		{	/*
			 * assigning the configured address of callback function
			 * in configuration structure to callback function pointer
			 */
		Gpt_Callback_Pointer[GPT_8] = Gpt_PortChannels[channel].GptNotification;
		}
		else{
			/*no action*/
		}

}
void Gpt_Notification_Channel9 (void){
	uint8 channel, Counter;
		/*
		 *  counter loop to assign the (channel) index of channel
		 *  configured to channel 9
		 */
		for (Counter=0;Counter<NUMBER_OF_GPT_CHANNELS;Counter++){

			if(Gpt_PortChannels[Counter].channelIDConfig == GPT_9){
				channel = Counter;
				break;
			}
			else{
				/* no action*/
			}
		}
		/*
		 * check if the pointer of the configuration structure
		 * declared to address or to NULL
		 */
		if ( Gpt_PortChannels[channel].GptNotification != NULL_PTR)
		{	/*
			 * assigning the configured address of callback function
			 * in configuration structure to callback function pointer
			 */
		Gpt_Callback_Pointer[GPT_9] = Gpt_PortChannels[channel].GptNotification;
		}
		else{
			/*no action*/
		}

}
void Gpt_Notification_Channel10 (void){
	uint8 channel, Counter;
		/*
		 *  counter loop to assign the (channel) index of channel
		 *  configured to channel 10
		 */
		for (Counter=0;Counter<NUMBER_OF_GPT_CHANNELS;Counter++){

			if(Gpt_PortChannels[Counter].channelIDConfig == GPT_10){
				channel = Counter;
				break;
			}
			else{
				/* no action*/
			}
		}
		/*
		 * check if the pointer of the configuration structure
		 * declared to address or to NULL
		 */
		if ( Gpt_PortChannels[channel].GptNotification != NULL_PTR)
		{	/*
			 * assigning the configured address of callback function
			 * in configuration structure to callback function pointer
			 */
		Gpt_Callback_Pointer[GPT_10] = Gpt_PortChannels[channel].GptNotification;
		}
		else{
			/*no action*/
		}

}
void Gpt_Notification_Channel11 (void){
	uint8 channel, Counter;
		/*
		 *  counter loop to assign the (channel) index of channel
		 *  configured to channel 11
		 */
		for (Counter=0;Counter<NUMBER_OF_GPT_CHANNELS;Counter++){

			if(Gpt_PortChannels[Counter].channelIDConfig == GPT_11){
				channel = Counter;
				break;
			}
			else{
				/* no action*/
			}
		}
		/*
		 * check if the pointer of the configuration structure
		 * declared to address or to NULL
		 */
		if ( Gpt_PortChannels[channel].GptNotification != NULL_PTR)
		{	/*
			 * assigning the configured address of callback function
			 * in configuration structure to callback function pointer
			 */
		Gpt_Callback_Pointer[GPT_11] = Gpt_PortChannels[channel].GptNotification;
		}
		else{
			/*no action*/
		}

}
void Gpt_Notification_Channel12 (void){
	uint8 channel, Counter;
		/*
		 *  counter loop to assign the (channel) index of channel
		 *  configured to channel 12
		 */
		for (Counter=0;Counter<NUMBER_OF_GPT_CHANNELS;Counter++){

			if(Gpt_PortChannels[Counter].channelIDConfig == GPT_12){
				channel = Counter;
				break;
			}
			else{
				/* no action*/
			}
		}
		/*
		 * check if the pointer of the configuration structure
		 * declared to address or to NULL
		 */
		if ( Gpt_PortChannels[channel].GptNotification != NULL_PTR)
		{	/*
			 * assigning the configured address of callback function
			 * in configuration structure to callback function pointer
			 */
		Gpt_Callback_Pointer[GPT_12] = Gpt_PortChannels[channel].GptNotification;
		}
		else{
			/*no action*/
		}

}
void Gpt_Notification_Channel13 (void){
	uint8 channel, Counter;
		/*
		 *  counter loop to assign the (channel) index of channel
		 *  configured to channel 13
		 */
		for (Counter=0;Counter<NUMBER_OF_GPT_CHANNELS;Counter++){

			if(Gpt_PortChannels[Counter].channelIDConfig == GPT_13){
				channel = Counter;
				break;
			}
			else{
				/* no action*/
			}
		}
		/*
		 * check if the pointer of the configuration structure
		 * declared to address or to NULL
		 */
		if ( Gpt_PortChannels[channel].GptNotification != NULL_PTR)
		{	/*
			 * assigning the configured address of callback function
			 * in configuration structure to callback function pointer
			 */
		Gpt_Callback_Pointer[GPT_13] = Gpt_PortChannels[channel].GptNotification;
		}
		else{
			/*no action*/
		}

}


/************************************************************************************
 * Service Name: Gpt_Init
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): ConfigPtr - Pointer to a selected configuration structure
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Initializes the hardware timer module.
 ************************************************************************************/
void Gpt_Init(const Gpt_ConfigType *ConfigPtr) {
	boolean error= FALSE;
#if (GPT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR*/
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_INIT_SID,
			GPT_E_PARAM_POINTER);
	}
	else
	{
		/* no action*/
	}
	/* check if the driver is already initialized */
	if (GPT_INITIALIZED == Gpt_Status){
		Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_INIT_SID,
				GPT_E_ALREADY_INITIALIZED);
	}else{
		/* no action*/
	}
#endif
	if ( FALSE == error) {

		/* pointer to GPT registers */
		Gpt_TypeDef *Gpt_TypeDef_Ptr = NULL_PTR;
		/* pointer to GPT channels structure */
		Gpt_PortChannels = ConfigPtr->Gpt_Channels;
		/* variable contain the channel group of the gpt channel */
		Gpt_ChannelGroup channelGroup;
		/* loop counter */
		uint8 channel = ZERO;
		for (channel = ZERO; channel < NUMBER_OF_GPT_CHANNELS; channel++) {
			/* Checking the gpt channel is configured or not*/
			if (Gpt_PortChannels->channelStatusConfig == GPT_CONFIGURED) {
				/*
				 * Assign the pointer to the required Gpt channel registers
				 * And the channel to its channel group
				 */
				switch (Gpt_PortChannels->channelIDConfig) {
				case GPT_0:
					Gpt_TypeDef_Ptr = TIM1_TypeDef;
					channelGroup = ADVANCED_CONTROL;
					break;
				case GPT_1:
					Gpt_TypeDef_Ptr = TIM2_TypeDef;
					channelGroup = GENERAL_PURPOSE;
					break;
				case GPT_2:
					Gpt_TypeDef_Ptr = TIM3_TypeDef;
					channelGroup = GENERAL_PURPOSE;
					break;
				case GPT_3:
					Gpt_TypeDef_Ptr = TIM4_TypeDef;
					channelGroup = GENERAL_PURPOSE;
					break;
				case GPT_4:
					Gpt_TypeDef_Ptr = TIM5_TypeDef;
					channelGroup = GENERAL_PURPOSE;
					break;
				case GPT_5:
					Gpt_TypeDef_Ptr = TIM6_TypeDef;
					channelGroup = BASIC;
					break;
				case GPT_6:
					Gpt_TypeDef_Ptr = TIM7_TypeDef;
					channelGroup = BASIC;
					break;
				case GPT_7:
					Gpt_TypeDef_Ptr = TIM8_TypeDef;
					channelGroup = GENERAL_PURPOSE;
					break;
				case GPT_8:
					Gpt_TypeDef_Ptr = TIM9_TypeDef;
					channelGroup = GENERAL_PURPOSE;
					break;
				case GPT_9:
					Gpt_TypeDef_Ptr = TIM10_TypeDef;
					channelGroup = GENERAL_PURPOSE;
					break;
				case GPT_10:
					Gpt_TypeDef_Ptr = TIM11_TypeDef;
					channelGroup = GENERAL_PURPOSE;
					break;
				case GPT_11:
					Gpt_TypeDef_Ptr = TIM12_TypeDef;
					channelGroup = GENERAL_PURPOSE;
					break;
				case GPT_12:
					Gpt_TypeDef_Ptr = TIM13_TypeDef;
					channelGroup = GENERAL_PURPOSE;
					break;
				case GPT_13:
					Gpt_TypeDef_Ptr = TIM14_TypeDef;
					channelGroup = GENERAL_PURPOSE;
					break;
				default:
					/* No Action Required */
					break;
				}

				/*
				 *
				 *  COMMON FEATURES
				 *
				 */

				/* disable gpt channel */

				CLEAR_BIT(Gpt_TypeDef_Ptr->CR1.val, CEN_BIT);

				/* setting one pulse mode */
				Gpt_TypeDef_Ptr->CR1.val =
						Gpt_TypeDef_Ptr->CR1.val & (~(0x0001 << (3)))
								| (((uint16) (Gpt_PortChannels->modeTypeConfig))
										<< (3));

				/* Set the target ticks */
				Gpt_TypeDef_Ptr->ARR.val =
						Gpt_PortChannels->channelTickValueMaxConfig;

				/* Setting the prescaler */
				Gpt_TypeDef_Ptr->PSC.val =
						Gpt_PortChannels->clockPrescalerConfig;

				/* Setting the value of counter */
				Gpt_TypeDef_Ptr->CNT.val = Gpt_PortChannels->valueTypeConfig;

				/*
				 *
				 *  SPECIFIC FEATURES to each group channel
				 *
				 */
				switch (channelGroup) {
				case ADVANCED_CONTROL:
					/* Setting the number of  repetition */
					Gpt_TypeDef_Ptr->RCR.val =
							Gpt_PortChannels->channelCountingRepetitionConfig;
					/******************************************************
					 * no break here
					 *****************************************************/
				case GENERAL_PURPOSE:
					/*
					 * setting the counting mode if the channel has this feature
					 * the default is edge aligned mode counting up
					 */
					if (Gpt_PortChannels->channelCountingModeConfig
							!= GPT_CHANNEL_COUNTING_MODE_NONE) {
						/* setting the counting mode in the two bits that control the channel  in CR1 register */
						Gpt_TypeDef_Ptr->CR1.val |=
								(0x0003 << (5))
										& (((uint16) (Gpt_PortChannels->channelCountingModeConfig))
												<< (5));
						if (Gpt_PortChannels->channelCountingModeConfig
								== EDGE_ALIGNED_MODE) {
							/* setting the counting direction up/down  in the bit that control the channel  in CR1 register */
							Gpt_TypeDef_Ptr->CR1.bits._4 =
									Gpt_PortChannels->channelCountingDirectionConfig;
						} else {
							/* No Action Required */
						}
					} else {
						/* No Action Required */
					}

					/*
					 * setting the clock selection if the channel has this feature
					 * the default is internal source
					 */
					if (Gpt_PortChannels->channelClockSourceConfig
							!= Gpt_CHANNEL_CLOCK_SOURCE_NONE) {
						/* setting the clock source  to ETI (external mode 2) by setting the ECE bit */
						if (Gpt_PortChannels->channelClockSourceConfig
								== EXTERNAL_TRIGGER_INPUT) {
							SET_BIT(Gpt_TypeDef_Ptr->SMCR.val, 14);
						} else {
							/*
							 * setting the clock source  to external mode 1  by setting the bits of SMS to 111
							 * OR
							 * setting the clock source  to internal clock source by setting the bits of SMS to 000
							 */
							Gpt_TypeDef_Ptr->SMCR.val &=
									(0xfff8 << (0))
											| (((uint16) (Gpt_PortChannels->channelClockSourceConfig))
													<< (0));
						}
					} else {
						/* No Action Required */
					}
					break;
				default:
					/* No Action Required */
					break;
				}
				/* Set the status of the channel to initialized */
				Gpt_PortChannels->channelStateConfig = GPT_INITIALIZED;
			} else {
				/* No Action Required */
			}

			/* point to the next gpt channel */
			Gpt_PortChannels++;
		}

		/* Set address of the first structure to Gpt_PortChannels for future uses */
		Gpt_PortChannels = ConfigPtr->Gpt_Channels;

		/* Set status of Gpt Module to initialized */
		Gpt_Status = GPT_INITIALIZED;
	}
}

/************************************************************************************
 * Service Name: Gpt_DeInit
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NONE
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to deinitializes all hardware timer channels..
 ************************************************************************************/
#if(Gpt_DEINIT_API == STD_ON )
void Gpt_DeInit(void) {
	boolean error = FALSE;
	/* pointer to GPT registers struct */
	Gpt_TypeDef *Gpt_TypeDef_Ptr = NULL_PTR;
    Gpt_ConfigChannel *Gpt_ChannelsPtr = Gpt_PortChannels;
	Gpt_ChannelGroup channelGroup;
	uint8 channel = ZERO;
#if (GPT_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (GPT_NOT_INITIALIZED == Gpt_Status)
	{
		Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_DEINIT_SID,
				GPT_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* no action*/
	}
	/* Check if any GPT channel is running before using this function */
	for (channel = ZERO; channel < NUMBER_OF_GPT_CHANNELS || error == TRUE; channel++) {
		if (Gpt_ChannelsPtr->channelStateConfig == GPT_RUNNING) {
			Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_DEINIT_SID,
					GPT_E_BUSY);
			error = TRUE;
			/* point to the next gpt channel */
			Gpt_ChannelsPtr++;
		}
	}
	Gpt_ChannelsPtr = Gpt_PortChannels;
#endif
	if (FALSE == error) {
		for (channel = ZERO; channel < NUMBER_OF_GPT_CHANNELS; channel++) {
			/* Checking the gpt channel is configured or not*/
			if(Gpt_PortChannels->channelStatusConfig == GPT_CONFIGURED){
				/*
				 * Assign the pointer to the required Gpt channel registers
				 * And the channel to its channel group
				 */
				switch (Gpt_ChannelsPtr->channelIDConfig) {
				case GPT_0:
					Gpt_TypeDef_Ptr = TIM1_TypeDef;
					channelGroup = ADVANCED_CONTROL;
					break;
				case GPT_1:
					Gpt_TypeDef_Ptr = TIM2_TypeDef;
					channelGroup = GENERAL_PURPOSE;
					break;
				case GPT_2:
					Gpt_TypeDef_Ptr = TIM3_TypeDef;
					channelGroup = GENERAL_PURPOSE;
					break;
				case GPT_3:
					Gpt_TypeDef_Ptr = TIM4_TypeDef;
					channelGroup = GENERAL_PURPOSE;
					break;
				case GPT_4:
					Gpt_TypeDef_Ptr = TIM5_TypeDef;
					channelGroup = GENERAL_PURPOSE;
					break;
				case GPT_5:
					Gpt_TypeDef_Ptr = TIM6_TypeDef;
					channelGroup = BASIC;
					break;
				case GPT_6:
					Gpt_TypeDef_Ptr = TIM7_TypeDef;
					channelGroup = BASIC;
					break;
				case GPT_7:
					Gpt_TypeDef_Ptr = TIM8_TypeDef;
					channelGroup = GENERAL_PURPOSE;
					break;
				case GPT_8:
					Gpt_TypeDef_Ptr = TIM9_TypeDef;
					channelGroup = GENERAL_PURPOSE;
					break;
				case GPT_9:
					Gpt_TypeDef_Ptr = TIM10_TypeDef;
					channelGroup = GENERAL_PURPOSE;
					break;
				case GPT_10:
					Gpt_TypeDef_Ptr = TIM11_TypeDef;
					channelGroup = GENERAL_PURPOSE;
					break;
				case GPT_11:
					Gpt_TypeDef_Ptr = TIM12_TypeDef;
					channelGroup = GENERAL_PURPOSE;
					break;
				case GPT_12:
					Gpt_TypeDef_Ptr = TIM13_TypeDef;
					channelGroup = GENERAL_PURPOSE;
					break;
				case GPT_13:
					Gpt_TypeDef_Ptr = TIM14_TypeDef;
					channelGroup = GENERAL_PURPOSE;
					break;
				default:
					/* No Action Required */
					break;
				}


				/* Set common register to their reset values */
				Gpt_TypeDef_Ptr->DIER.words._0 = 0x0000;
				Gpt_TypeDef_Ptr->SR.words._0 = 0x0000;
				Gpt_TypeDef_Ptr->EGR.words._0 = 0x0000;
				Gpt_TypeDef_Ptr->CNT.words._0 = 0x0000;
				Gpt_TypeDef_Ptr->ARR.words._0 = 0xFFFF;
				Gpt_TypeDef_Ptr->PSC.words._0 = 0x0000;

				/* Set specific registers according to their group to their reset values */
				if(channel >= GPT_8){
					switch (channelGroup) {
					case ADVANCED_CONTROL:

						Gpt_TypeDef_Ptr->CNT.words._0 = 0x0000;
						Gpt_TypeDef_Ptr->CR2.words._0 = 0x0000;
						Gpt_TypeDef_Ptr->SMCR.words._0 = 0x0000;
						Gpt_TypeDef_Ptr->ARR.words._0 = 0xFFFF;
						Gpt_TypeDef_Ptr->RCR.words._0 = 0x0000;
						Gpt_TypeDef_Ptr->BDTR.words._0 = 0x00000;
						break;
					case GENERAL_PURPOSE:
						if(channel == GPT_1 || channel == GPT_4 ){
							Gpt_TypeDef_Ptr->CNT.val = 0x00000000;
							Gpt_TypeDef_Ptr->ARR.val = 0xFFFFFFFF;

						}
						else {
							Gpt_TypeDef_Ptr->CNT.words._0 = 0x0000;
							Gpt_TypeDef_Ptr->ARR.words._0 = 0xFFFF;
						}
						break;
					default:
						/* No Action Required */
						break;
					}
				}else{
					/* No Action Required */
				}
				Gpt_TypeDef_Ptr->CR1.words._0 = 0x0000;
			}else{
				/* No Action Required */
			}
			/* point to the next gpt channel */
			Gpt_ChannelsPtr++;
		}
		/* Set status of Gpt Module to not initialized */
		Gpt_Status = GPT_NOT_INITIALIZED;
	}
}
#endif
/************************************************************************************
 * Service Name: Gpt_GetTimeElapsed
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel- Numeric identifier of the GPT channel.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Gpt_ValueType - Elapsed timer value (in number of ticks)
 * Description: Function to returns the time already elapsed.
 ************************************************************************************/
#if (GPT_TIME_ELAPSED_API == STD_ON)
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel) {
	boolean error = FALSE;
	/* pointer to GPT registers struct */
	Gpt_TypeDef *Gpt_TypeDef_Ptr = NULL_PTR;
    Gpt_ConfigChannel *Gpt_ChannelsPtr = Gpt_PortChannels;
	/* variable contain the return value of function  */
	Gpt_ValueType timeElapsed = 0;
#if (GPT_DEV_ERROR_DETECT == STD_ON)
	/*
	 * Check if the Driver is initialized before using this function
	 * Check if the channel is initialized before using this function
	 */
	if (GPT_NOT_INITIALIZED == Gpt_Status ||
			GPT_NOT_INITIALIZED == Gpt_ChannelsPtr[Channel]->channelStateConfig)
	{
		Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
				GPT_GET_TIME_ELAPSED_SID, GPT_E_UNINIT);
		error = TRUE;
		timeElapsed = 0;
	}
	else{
		/* no action*/
	}
	/* Check if the Channel is Valid before using this function */
	if(Channel< GPT_0 || Channel > GPT_13){
		Gpt_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
				GPT_GET_TIME_ELAPSED_SID, GPT_E_PARAM_CHANNEL);
		error = TRUE;
		timeElapsed = 0;
	}
	else{
		/* No Action Required */
	}
#endif
	if(FALSE == error){
		/* checking channel state  */
		switch(Gpt_ChannelsPtr[Channel].channelStateConfig){
		/* if channel state is initialized return 0 */
		case GPT_INITIALIZED :
			timeElapsed = 0;
			break;
			/* if channel state is expired , running or stopped */
		default:
			/*
			 * Assign the pointer to the required Gpt channel registers
			 */
			switch (Channel) {
			case GPT_0:
				Gpt_TypeDef_Ptr = TIM1_TypeDef;
				break;
			case GPT_1:
				Gpt_TypeDef_Ptr = TIM2_TypeDef;
				break;
			case GPT_2:
				Gpt_TypeDef_Ptr = TIM3_TypeDef;
				break;
			case GPT_3:
				Gpt_TypeDef_Ptr = TIM4_TypeDef;
				break;
			case GPT_4:
				Gpt_TypeDef_Ptr = TIM5_TypeDef;
				break;
			case GPT_5:
				Gpt_TypeDef_Ptr = TIM6_TypeDef;
				break;
			case GPT_6:
				Gpt_TypeDef_Ptr = TIM7_TypeDef;
				break;
			case GPT_7:
				Gpt_TypeDef_Ptr = TIM8_TypeDef;
				break;
			case GPT_8:
				Gpt_TypeDef_Ptr = TIM9_TypeDef;
				break;
			case GPT_9:
				Gpt_TypeDef_Ptr = TIM10_TypeDef;
				break;
			case GPT_10:
				Gpt_TypeDef_Ptr = TIM11_TypeDef;
				break;
			case GPT_11:
				Gpt_TypeDef_Ptr = TIM12_TypeDef;
				break;
			case GPT_12:
				Gpt_TypeDef_Ptr = TIM13_TypeDef;
				break;
			case GPT_13:
				Gpt_TypeDef_Ptr = TIM14_TypeDef;
				break;
			default:
				/* */
				break;
			}
			/*
			 * checking the direction of counting and calculating the time elapsed
			 */
			switch (Gpt_PortChannels[Channel].channelCountingDirectionConfig) {
			case GPT_UP_COUNTER:
				timeElapsed = Gpt_TypeDef_Ptr->CNT.val;
				break;
			case GPT_DOWN_COUNTER:
				timeElapsed = Gpt_TypeDef_Ptr->ARR.val - Gpt_TypeDef_Ptr->CNT.val;
				break;
			default:
				/* */
				break;
			}
			break;
		}

	}else{
		/* No action required */
	}
	return timeElapsed;
}
#endif

/************************************************************************************
 * Service Name: Gpt_GetTimeRemaining
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the GPT channel.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Gpt_ValueType - Remaining timer value (in number of ticks)
 * Description: Function to return the time remaining until the target time is reached.
 ************************************************************************************/

Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel) {
	boolean error = FALSE;
	/* pointer to GPT registers struct */
	Gpt_TypeDef *Gpt_TypeDef_Ptr = NULL_PTR;
    Gpt_ConfigChannel *Gpt_ChannelsPtr = Gpt_PortChannels;
	Gpt_ValueType timeRemaining = ZERO;
#if (GPT_DEV_ERROR_DETECT == STD_ON)
	/*
	 * Check if the Driver is initialized before using this function
	 * Check if the channel is initialized before using this function
	 */
	if (GPT_NOT_INITIALIZED == Gpt_Status ||
			GPT_NOT_INITIALIZED == Gpt_ChannelsPtr[Channel]->channelStateConfig)
	{
		Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
				GPT_GET_TIME_REMAINING_SID, GPT_E_UNINIT);
		error = TRUE;
		timeRemaining = 0;
	}else{
		/* no action*/
	}
	/* Check if the Channel is Valid before using this function */
	if(Channel< GPT_0 || Channel > GPT_13){
		Gpt_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
				GPT_GET_TIME_REMAINING_SID, GPT_E_PARAM_CHANNEL);
		error = TRUE;
		timeRemaining = 0;
	}else{
		/* No Action Required */
	}
#endif
	if(FALSE == error){
		switch(Gpt_ChannelsPtr[Channel].channelStateConfig){
		/* if channel state is expired return 0 */
		case GPT_EXPIRED :
			timeRemaining = 0;
			break;
		/* if channel state is initialized return 0 */
		case GPT_INITIALIZED :
			timeRemaining = 0;
			break;
		/* channel is running or stopped */
		default:
			/* setting Gpt_TypeDef_Ptr with the required gpt channel struct */
			switch (Channel) {
			case GPT_0:
				Gpt_TypeDef_Ptr = TIM1_TypeDef;
				break;
			case GPT_1:
				Gpt_TypeDef_Ptr = TIM2_TypeDef;
				break;
			case GPT_2:
				Gpt_TypeDef_Ptr = TIM3_TypeDef;
				break;
			case GPT_3:
				Gpt_TypeDef_Ptr = TIM4_TypeDef;
				break;
			case GPT_4:
				Gpt_TypeDef_Ptr = TIM5_TypeDef;
				break;
			case GPT_5:
				Gpt_TypeDef_Ptr = TIM6_TypeDef;
				break;
			case GPT_6:
				Gpt_TypeDef_Ptr = TIM7_TypeDef;
				break;
			case GPT_7:
				Gpt_TypeDef_Ptr = TIM8_TypeDef;
				break;
			case GPT_8:
				Gpt_TypeDef_Ptr = TIM9_TypeDef;
				break;
			case GPT_9:
				Gpt_TypeDef_Ptr = TIM10_TypeDef;
				break;
			case GPT_10:
				Gpt_TypeDef_Ptr = TIM11_TypeDef;
				break;
			case GPT_11:
				Gpt_TypeDef_Ptr = TIM12_TypeDef;
				break;
			case GPT_12:
				Gpt_TypeDef_Ptr = TIM13_TypeDef;
				break;
			case GPT_13:
				Gpt_TypeDef_Ptr = TIM14_TypeDef;
				break;
			default:
				/* No Action Required */
				break;
			}
			/* determine the counting direction configuration for this channel and get time remaining till next counter overflow event */
			switch (Gpt_PortChannels[Channel].channelCountingDirectionConfig) {

			case GPT_UP_COUNTER:
				timeRemaining = Gpt_TypeDef_Ptr->ARR.val - Gpt_TypeDef_Ptr->CNT.val + ONE;
				break;
			case GPT_DOWN_COUNTER:
				timeRemaining = Gpt_TypeDef_Ptr->CNT.val;
				break;
			default:
				/* No Action Required */
				break;
			}
			break;
		}
	}else{
		/* No action required */
	}
	return timeRemaining;
}

/************************************************************************************
 * Service Name: Gpt_StartTimer
 * Service ID[hex]: 0x05
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the GPT channel.
 * 				   Value   - Target time in number of ticks.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to start a timer channel.
 ************************************************************************************/
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value) {
	boolean error = FALSE;
	/* pointer to GPT registers struct */
	Gpt_TypeDef *Gpt_TypeDef_Ptr = NULL_PTR;
    Gpt_ConfigChannel *Gpt_ChannelsPtr = Gpt_PortChannels;
#if (GPT_DEV_ERROR_DETECT == STD_ON)
	/*
	 * Check if the Driver is initialized before using this function
	 * Check if the channel is initialized before using this function
	 */
		if (GPT_NOT_INITIALIZED == Gpt_Status||
				GPT_NOT_INITIALIZED == Gpt_ChannelsPtr[Channel]->channelStateConfig){
			Gpt_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
					GPT_START_TIMER_SID, GPT_E_UNINIT);
			error = TRUE;
		}else{
			/* No Action Required */
		}
		/* Check if the Channel is Valid before using this function */
		if(Channel<GPT_0||Channel>GPT_13){
			Gpt_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
					GPT_START_TIMER_SID, GPT_E_PARAM_CHANNEL);
			error = TRUE;
		}else{
			/* No Action Required */
		}
		if(Gpt_ChannelsPtr[Channel]->channelStateConfig == GPT_RUNNING){
			Gpt_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
					GPT_START_TIMER_SID, GPT_E_BUSY);
			error = TRUE;
		}else{
			/* No Action Required */
		}
		/* Check if the value is valid */
		/*******************************************************
		 * Maximum not included
		 *******************************************************/
		if(ZERO == Value){
			Gpt_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
					GPT_START_TIMER_SID, GPT_E_PARAM);
			error = TRUE;
		}else{
			/* No Action Required */
		}
#endif
	if (FALSE == error) {
		/*
		 * Assign the pointer to the required Gpt channel registers
		 */
		switch (Channel) {
		case GPT_0:
			Gpt_TypeDef_Ptr = TIM1_TypeDef;
			break;
		case GPT_1:
			Gpt_TypeDef_Ptr = TIM2_TypeDef;
			break;
		case GPT_2:
			Gpt_TypeDef_Ptr = TIM3_TypeDef;
			break;
		case GPT_3:
			Gpt_TypeDef_Ptr = TIM4_TypeDef;
			break;
		case GPT_4:
			Gpt_TypeDef_Ptr = TIM5_TypeDef;
			break;
		case GPT_5:
			Gpt_TypeDef_Ptr = TIM6_TypeDef;
			break;
		case GPT_6:
			Gpt_TypeDef_Ptr = TIM7_TypeDef;
			break;
		case GPT_7:
			Gpt_TypeDef_Ptr = TIM8_TypeDef;
			break;
		case GPT_8:
			Gpt_TypeDef_Ptr = TIM9_TypeDef;
			break;
		case GPT_9:
			Gpt_TypeDef_Ptr = TIM10_TypeDef;
			break;
		case GPT_10:
			Gpt_TypeDef_Ptr = TIM11_TypeDef;
			break;
		case GPT_11:
			Gpt_TypeDef_Ptr = TIM12_TypeDef;
			break;
		case GPT_12:
			Gpt_TypeDef_Ptr = TIM13_TypeDef;
			break;
		case GPT_13:
			Gpt_TypeDef_Ptr = TIM14_TypeDef;
			break;
		default:
			/* */
			break;
		}
		/* Setting the value of counter */
		Gpt_TypeDef_Ptr->CNT.val = ZERO;
		Gpt_TypeDef_Ptr->ARR.val = Value;
		/* enable gpt channel */
		SET_BIT(Gpt_TypeDef_Ptr->CR1.val,CEN_BIT);
		/* Set the status of the channel to running */
		Gpt_ChannelsPtr[Channel].channelStateConfig = GPT_RUNNING;
	}else{
		/* No action required */
	}
}

/************************************************************************************
 * Service Name: Gpt_StopTimer
 * Service ID[hex]: 0x06
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the GPT channel.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to stop a timer channel.
 ************************************************************************************/
/*
 * needs to review
 */
void Gpt_StopTimer(Gpt_ChannelType Channel) {
	boolean error = FALSE;
	/* pointer to GPT registers */
	Gpt_TypeDef *Gpt_TypeDef_Ptr = NULL_PTR;
    Gpt_ConfigChannel *Gpt_ChannelsPtr = Gpt_PortChannels;
#if (GPT_DEV_ERROR_DETECT == STD_ON)
	/*
	 * Check if the Driver is initialized before using this function
	 * Check if the channel is initialized before using this function
	 */
		if (GPT_NOT_INITIALIZED == Gpt_Status||
				GPT_NOT_INITIALIZED == Gpt_ChannelsPtr[Channel]->channelStateConfig){
			Gpt_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
					GPT_STOP_TIMER_SID, GPT_E_UNINIT);
			error = TRUE;
		}
		else{
			/* No Action Required */
		}
		/* Check if the Channel is Valid before using this function */
		if(Channel<GPT_0||Channel>GPT_13){
			Gpt_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
					GPT_STOP_TIMER_SID, GPT_E_PARAM_CHANNEL);
			error = TRUE;
		}
		else{
			/* No Action Required */
		}
#endif
	if(FALSE == error){
		/* checking state of channel */
		if(GPT_RUNNING == Gpt_ChannelsPtr[Channel].channelStateConfig){
			/*
			 * Assign the pointer to the required Gpt channel registers
			 */
			switch (Channel) {
			case GPT_0:
				Gpt_TypeDef_Ptr = TIM1_TypeDef;
				break;
			case GPT_1:
				Gpt_TypeDef_Ptr = TIM2_TypeDef;
				break;
			case GPT_2:
				Gpt_TypeDef_Ptr = TIM3_TypeDef;
				break;
			case GPT_3:
				Gpt_TypeDef_Ptr = TIM4_TypeDef;
				break;
			case GPT_4:
				Gpt_TypeDef_Ptr = TIM5_TypeDef;
				break;
			case GPT_5:
				Gpt_TypeDef_Ptr = TIM6_TypeDef;
				break;
			case GPT_6:
				Gpt_TypeDef_Ptr = TIM7_TypeDef;
				break;
			case GPT_7:
				Gpt_TypeDef_Ptr = TIM8_TypeDef;
				break;
			case GPT_8:
				Gpt_TypeDef_Ptr = TIM9_TypeDef;
				break;
			case GPT_9:
				Gpt_TypeDef_Ptr = TIM10_TypeDef;
				break;
			case GPT_10:
				Gpt_TypeDef_Ptr = TIM11_TypeDef;
				break;
			case GPT_11:
				Gpt_TypeDef_Ptr = TIM12_TypeDef;
				break;
			case GPT_12:
				Gpt_TypeDef_Ptr = TIM13_TypeDef;
				break;
			case GPT_13:
				Gpt_TypeDef_Ptr = TIM14_TypeDef;
				break;
			default:
				/* */
				break;
			}

			/* Clearing the value of the ARR register */
			Gpt_TypeDef_Ptr->ARR.val = ZERO;
			/* disable gpt channel */
			CLEAR_BIT(Gpt_TypeDef_Ptr->CR1.val,CEN_BIT);
			/* Set the status of the channel to stopped */
			Gpt_ChannelsPtr[Channel].channelStateConfig = GPT_STOPPED;
		}else{
			/* No action required */
		}

	}
}

/************************************************************************************
 * Service Name:  Gpt_EnableNotification
 * Service ID[hex]: 0x07
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the GPT channel.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Enables the interrupt notification for a channel (relevant in normal mode).
 ************************************************************************************/
void Gpt_EnableNotification(Gpt_ChannelType Channel){

#if (GPT_DEV_ERROR_DETECT == STD_ON)
	/*
	 * Check if the Driver is initialized before using this function
	 * Check if the channel is initialized before using this function
	 */
		if (GPT_NOT_INITIALIZED == Gpt_Status||
				GPT_NOT_INITIALIZED == Gpt_PortChannels[Channel]->channelStateConfig){
			Gpt_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
					GPT_STOP_TIMER_SID, GPT_E_UNINIT);
			error = TRUE;
		}
		else{
			/* No Action Required */
		}
		/* Check if the Channel is Valid before using this function */
		if(Channel<GPT_0||Channel>GPT_13){
			Gpt_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
					GPT_STOP_TIMER_SID, GPT_E_PARAM_CHANNEL);
			error = TRUE;
		}
		else{
			/* No Action Required */
		}
#endif
	/* pointer to GPT registers */
	Gpt_TypeDef *Gpt_TypeDef_Ptr = NULL_PTR;
	/*
	 * assigning pointers to NVIC registers
	 */
	Gpt_NVIC_ISER *Gpt_NVIC_ISER_Ptr = GPT_NVIC_ISER;
	Gpt_NVIC_ICER *Gpt_NVIC_ICER_Ptr = GPT_NVIC_ICER;
	/* variable to configure IRQ number, register number and bit number in the reg. */
	uint8 IRQn, reg_number, bit_number;
	/*
	 * Assign the pointer to the required Gpt channel registers
	 * and enable the interrupt notification
	 *  of the referenced channel configured for notification
	 *  and the IRQ number
	 */
	   switch (Channel) {
	   	    case GPT_0:
	   		   Gpt_TypeDef_Ptr = TIM1_TypeDef;
	   		   Gpt_Notification_Channel0 ();
	   		   IRQn = IRQn_TIM1;
			   break;
			case GPT_1:
				Gpt_TypeDef_Ptr = TIM2_TypeDef;
				Gpt_Notification_Channel1 ();
				IRQn = IRQn_TIM2;
				break;
			case GPT_2:
				Gpt_TypeDef_Ptr = TIM3_TypeDef;
				Gpt_Notification_Channel2 ();
				IRQn = IRQn_TIM3;
				break;
			case GPT_3:
				Gpt_TypeDef_Ptr = TIM4_TypeDef;
				Gpt_Notification_Channel3 ();
				IRQn = IRQn_TIM4;
				break;
			case GPT_4:
				Gpt_TypeDef_Ptr = TIM5_TypeDef;
				Gpt_Notification_Channel4 ();
				IRQn = IRQn_TIM5;
				break;
			case GPT_5:
				Gpt_TypeDef_Ptr = TIM6_TypeDef;
				Gpt_Notification_Channel5 ();
				IRQn = IRQn_TIM6;
		    	break;
			case GPT_6:
				Gpt_TypeDef_Ptr = TIM7_TypeDef;
				Gpt_Notification_Channel6 ();
				IRQn = IRQn_TIM7;
				break;
			case GPT_7:
				Gpt_TypeDef_Ptr = TIM8_TypeDef;
				Gpt_Notification_Channel7 ();
				IRQn = IRQn_TIM8;
				break;
			case GPT_8:
				Gpt_TypeDef_Ptr = TIM9_TypeDef;
				Gpt_Notification_Channel8 ();
				IRQn = IRQn_TIM9;
				break;
			case GPT_9:
				Gpt_TypeDef_Ptr = TIM10_TypeDef;
				Gpt_Notification_Channel9();
				IRQn = IRQn_TIM10;
				break;
			case GPT_10:
				Gpt_TypeDef_Ptr = TIM11_TypeDef;
				Gpt_Notification_Channel10();
				IRQn = IRQn_TIM12;
				break;
			case GPT_11:
				Gpt_TypeDef_Ptr = TIM12_TypeDef;
				Gpt_Notification_Channel11();
				IRQn = IRQn_TIM12;
				break;
			case GPT_12:
				Gpt_TypeDef_Ptr = TIM13_TypeDef;
				Gpt_Notification_Channel12();
				IRQn = IRQn_TIM13;
				break;
			case GPT_13:
				Gpt_TypeDef_Ptr = TIM14_TypeDef;
				Gpt_Notification_Channel13 ();
				IRQn = IRQn_TIM14;
				break;
			default:
					/*no action */
				break;
				}

	   reg_number = IRQn/32;
	   bit_number = IRQn - ( reg_number*32);
	   /*
	    * setting timer global interrupts or update interrupts
	    */
	  SET_BIT(Gpt_NVIC_ISER_Ptr->ISER[reg_number].val,bit_number );
	  CLEAR_BIT(Gpt_NVIC_ISER_Ptr->ISER[reg_number].val,bit_number );
	  /*
	   * setting timer prepheiral interrupts or update interrupts
	   */
	  CLEAR_BIT(Gpt_TypeDef_Ptr->CR1.val,1);

}

/************************************************************************************
 * Service Name:  Gpt_DisableNotification
 * Service ID[hex]: 0x07
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Channel - Numeric identifier of the GPT channel.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Enables the interrupt notification for a channel (relevant in normal mode).
 ************************************************************************************/
void Gpt_DisableNotification(Gpt_ChannelType Channel){

#if (GPT_DEV_ERROR_DETECT == STD_ON)
	/*
	 * Check if the Driver is initialized before using this function
	 * Check if the channel is initialized before using this function
	 */
		if (GPT_NOT_INITIALIZED == Gpt_Status||
				GPT_NOT_INITIALIZED == Gpt_PortChannels[Channel]->channelStateConfig){
			Gpt_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
					GPT_STOP_TIMER_SID, GPT_E_UNINIT);
			error = TRUE;
		}
		else{
			/* No Action Required */
		}
		/* Check if the Channel is Valid before using this function */
		if(Channel<GPT_0||Channel>GPT_13){
			Gpt_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
					GPT_STOP_TIMER_SID, GPT_E_PARAM_CHANNEL);
			error = TRUE;
		}
		else{
			/* No Action Required */
		}
#endif

	/* pointer to GPT registers */
	Gpt_TypeDef *Gpt_TypeDef_Ptr = NULL_PTR;
	/*
	 * assigning pointers to NVIC registers
	 */
	Gpt_NVIC_ISER *Gpt_NVIC_ISER_Ptr = GPT_NVIC_ISER;
	Gpt_NVIC_ICER *Gpt_NVIC_ICER_Ptr = GPT_NVIC_ICER;
	/* variable to configure IRQ number, register number and bit number in the reg. */
	uint8 IRQn, reg_number, bit_number;
	/*
	 * Assign the pointer to the required Gpt channel registers
	 *  and the IRQ number
	 */
	   switch (Channel) {
	   	    case GPT_0:
	   		   Gpt_TypeDef_Ptr = TIM1_TypeDef;
	   		   IRQn = IRQn_TIM1;
			   break;
			case GPT_1:
				Gpt_TypeDef_Ptr = TIM2_TypeDef;
				IRQn = IRQn_TIM2;
				break;
			case GPT_2:
				Gpt_TypeDef_Ptr = TIM3_TypeDef;
				IRQn = IRQn_TIM3;
				break;
			case GPT_3:
				Gpt_TypeDef_Ptr = TIM4_TypeDef;
				IRQn = IRQn_TIM4;
				break;
			case GPT_4:
				Gpt_TypeDef_Ptr = TIM5_TypeDef;
				IRQn = IRQn_TIM5;
				break;
			case GPT_5:
				Gpt_TypeDef_Ptr = TIM6_TypeDef;
				IRQn = IRQn_TIM6;
		    	break;
			case GPT_6:
				Gpt_TypeDef_Ptr = TIM7_TypeDef;
				IRQn = IRQn_TIM7;
				break;
			case GPT_7:
				Gpt_TypeDef_Ptr = TIM8_TypeDef;
				IRQn = IRQn_TIM8;
				break;
			case GPT_8:
				Gpt_TypeDef_Ptr = TIM9_TypeDef;
				IRQn = IRQn_TIM9;
				break;
			case GPT_9:
				Gpt_TypeDef_Ptr = TIM10_TypeDef;
				IRQn = IRQn_TIM10;
				break;
			case GPT_10:
				Gpt_TypeDef_Ptr = TIM11_TypeDef;
				IRQn = IRQn_TIM12;
				break;
			case GPT_11:
				Gpt_TypeDef_Ptr = TIM12_TypeDef;
				IRQn = IRQn_TIM12;
				break;
			case GPT_12:
				Gpt_TypeDef_Ptr = TIM13_TypeDef;
				IRQn = IRQn_TIM13;
				break;
			case GPT_13:
				Gpt_TypeDef_Ptr = TIM14_TypeDef;
				IRQn = IRQn_TIM14;
				break;
			default:
					/*no action */
				break;
				}

	   reg_number = IRQn/32;
	   bit_number = IRQn - ( reg_number*32);
	   /*
	    * disabling timer global interrupts or update interrupts
	    */
	  CLEAR_BIT(Gpt_NVIC_ISER_Ptr->ISER[reg_number].val,bit_number );
	  SET_BIT(Gpt_NVIC_ICER_Ptr->ICER[reg_number].val,bit_number );
	  /*
	   * Disabling timer prephieral interrupts or update interrupts
	   */
	  SET_BIT(Gpt_TypeDef_Ptr->CR1.val,1);

}
/************************************************************************************
 * Service Name: Gpt_GetVersionInfo
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): VersionInfo - Pointer to where to store the version information of this module.
 * Return value: None
 * Description: Function to get the version information of this module.
 ************************************************************************************/

#if (GPT_VERSION_INFO_API == STD_ON)
void Gpt_GetVersionInfo(Std_VersionInfoType *versioninfo) {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not Null pointer */
	if(NULL_PTR == versioninfo)
	{
		/* Report to DET  */
		Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID,
				GPT_GET_VERSION_INFO_SID, GPT_E_PARAM_POINTER);
	}
	else
#endif
	{
		/* Copy the vendor Id */
		versioninfo->vendorID = (uint16) GPT_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16) GPT_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8) GPT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8) GPT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8) GPT_SW_PATCH_VERSION;
	}
}
#endif
