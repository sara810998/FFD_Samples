/******************************************************************************
 *
 * Module: Flow Meter
 *
 * File Name: FlowMeter.c
 *
 * Description: Source file for flow meter .
 *
 * Author: Eslam - Taha - Sara
 ******************************************************************************/
#include "FlowMeter.h"
#include "Adc.h"
/*initialize flow meter status as not initialized*/
STATIC uint8 FlowMeter_Status = FLOWMETER_NOT_INITIALIZED;
STATIC FlowMeter_ConfigChannel* FlowMeter_Ptr = NULL_PTR;
/************************************************************************************
 * Service Name: FlowMeter_Init
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): ConfigPtr - Pointer to a selected configuration structure
 * Parameters (inout): None
 * Parameters (out): uint8 flow meter status type
 * Return value: None
 * Description: Function to Initialize the flow meter Module.
 ************************************************************************************/
uint8 FlowMeter_Init(const FlowMeter_ConfigType* ConfigPtr)
{ 
	/* pointer to motor PWM channels structure */
	FlowMeter_Ptr = ConfigPtr->FlowMeter_Channels;
	/* loop counter */
	for(uint8 counter = 0; conter < NUMBER_OF_FLOWMETERS; counter++ )
	{  
		/*check if buffer size is ok "function return std type ok or not ok" */
		if (Adc_SetupResultBuffer(FlowMeter_Ptr->FlowMeter_Group, FlowMeter_Ptr->FlowMeter_Buffer))
		{
			/*check if software or hardware triggered*/
		switch(FlowMeter_Ptr->Trigger_Signal){
		case FLOWMETER_SW_TRIG:
		Adc_StartGroupConversion( FlowMeter_Ptr->FlowMeter_Group);
		break;
		case FLOWMETER_HW_TRIG:
		Adc_EnableHardwareTrigger( FlowMeter_Ptr->FlowMeter_Group);
		break;
		default: 
		break;
		}
		}
			else
			{
				FlowMeter_Status = FLOWMETER_NOT_INITIALIZED;
				return FlowMeter_Status;
			}
		/* increment pointer t0 intialize the next motor */
		FlowMeter_Ptr++;
	}
	/* Set address of the first structure to FlowMeter_Channel*/
	FlowMeter_Ptr = ConfigPtr->FlowMeter_Channels;
	/*set FlowMeter status to initialized*/
	FlowMeter_Status = FLOWMETER_INITIALIZED;

	return FlowMeter_Status;
}

/************************************************************************************
 * Service Name: FlowMeter_Read
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): FlowMeter ID
 * Parameters (inout): None
 * Parameters (out): float32 flow liter/min
 * Return value: None
 * Description: Function to read flow from the flow meter.
 ************************************************************************************/
float32 FlowMeter_Read(FlowMeter_ChannelType FlowMeter_Id)
{ 
	float32 value;
	float32 Q;
	uint16 *ptr = FlowMeter_Ptr[FlowMeter_Id].FlowMeter_Buffer;
	/*store the read voltage value in the data buffer*/
	Adc_ReadGroup(FlowMeter_Ptr[FlowMeter_Id].FlowMeter_Group, FlowMeter_Ptr[FlowMeter_Id].FlowMeter_Buffer);
  /*check the method of calculating voltage*/
#if (GET_VALUE_METHOD == RESISTANCE_METHOD)
  /*calculate current corosponding to the measured volt*/
  value = ptr[FlowMeter_Ptr[FlowMeter_Id].FlowMeter_ChannelSequence]* ADC_FLOWMETER_1_REFERENCE*1000.0 /(FlowMeter_Ptr[FlowMeter_Id].FlowMeter_Resolution * ADC_FLOWMETER_1_RESISTANCE_VALUE);
  /*eqn for calculating q as it is linarly propotional with I*/
  Q =  FlowMeter_Ptr[FlowMeter_Id].MinFlow + ((FlowMeter_Ptr[FlowMeter_Id].MaxFlow - FlowMeter_Ptr[FlowMeter_Id].MinFlow)*(value - ADC_FLOWMETER_1_MIN_OUTPUT_CURRENT)/(ADC_FLOWMETER_1_MAX_OUTPUT_CURRENT-ADC_FLOWMETER_1_MIN_OUTPUT_CURRENT));
#else
  /*not defined*/
#endif
  return Q;
}
/************************************************************************************
 * Service Name: FlowMeter_Stop
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): FlowMeter ID
 * Parameters (inout): None
 * Parameters (out): none
 * Return value: None
 * Description: Function to stop group from the flow meter.
 ************************************************************************************/
void FlowMeter_Stop(FlowMeter_ChannelType FlowMeter_Id)
{	
		/*check if software or hardware triggered*/
		switch(FlowMeter_Ptr->Trigger_Signal){
		case FLOWMETER_SW_TRIG:
		Adc_StopGroupConversion( FlowMeter_Ptr[FlowMeter_Id].FlowMeter_Group  );
		break;
		case FLOWMETER_HW_TRIG:
		Adc_DisableHardwareTrigger( FlowMeter_Ptr[FlowMeter_Id].FlowMeter_Group  );
		break;
		default: 
		break;
		}
	FlowMeter_Status = FLOWMETER_NOT_INITIALIZED;	
}
