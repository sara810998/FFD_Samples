/******************************************************************************
 *
 * Module: Motors Pwm
 *
 * File Name: Motors_Pwm_PBcfg.c
 *
 * Description: Post Build Configuration Source file for Motors Pwm.
 *
 * Author: Eslam - Taha - Sara
 ******************************************************************************/
#include "FlowMeter.h"

const FlowMeter_ConfigType FlowMeter_Configuration =
{
  ADC_FLOWMETER_1_ID,ADC_FLOWMETER_1_GROUP_INDEX,FLOWMETER_CHANNEL_INDEX,FLOWMETER_CHANNEL_SEQUENCE,ADC_FLOWMETER_1_HW_SIGNAL,ADC_FLOWMETER_1_RESOLUTION,ADC_FLOWMETER_1_MIN_FLOW,ADC_FLOWMETER_1_MAX_FLOW,ADC_FLOWMETER_BUFFER_ADRESS
};