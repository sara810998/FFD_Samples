/******************************************************************************
 *
 * Module: Flow Meter
 *
 * File Name: FlowMeter.h
 *
 * Description: Header file for flow meter .
 *
 * Author: Eslam - Taha - Sara
 ******************************************************************************/
#ifndef INC_FLOWMETER_H_
#define INC_FLOWMETER_H_

#include "Std_Types.h"
#include"FlowMeter_Cfg.h"

/* Flow meter status*/
#define FLOWMETER_NOT_INITIALIZED            (0U)
#define FLOWMETER_INITIALIZED                (1U)
/* buffer array for the group connecting flow meter*/
uint16 Adc_FlowMeterGroup[NUMBER_OF_FLOWMETERS];

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
/* Type definition for FlowMeter_ChannelType used by the flow meter APIs */
typedef enum
{
	FLOWMETER_1
}FlowMeter_ChannelIdType;

/* Type definition for FlowMeter_Resolution used by the flow meter APIs */
typedef enum
{
	FLOWMETER_6_BIT =64,
	FLOWMETER_8_BIT =256,
	FLOWMETER_10_BIT =1024,
	FLOWMETER_12_BIT = 4096
	
}FlowMeter_ResolutionType;

/* Type definition for FlowMeter_GroupType used by the flow meter APIs */
typedef enum{
	FLOWMETER_1_REGULAR_GROUP ,
	FLOWMETER_1_INJECTED_GROUP ,
	FLOWMETER_2_REGULAR_GROUP ,
	FLOWMETER_2_INJECTED_GROUP ,
	FLOWMETER_3_REGULAR_GROUP ,
	FLOWMETER_3_INJECTED_GROUP
}FlowMeter_GroupType;

/* Type definition for Adc_HwTriggerSignalType used by the flow meter APIs */
typedef enum {
	FLOWMETER_SW_TRIG,
	FLOWMETER_HW_TRIG
} FlowMeter_TriggerSignalType;

/* Type definition for lowMeter_ChannelType used by the flow meter APIs */
typedef enum{
	FLOWMETER_CH_0 ,
	FLOWMETER_CH_1 ,
	FLOWMETER_CH_2 ,
	FLOWMETER_CH_3 ,
	FLOWMETER_CH_4 ,
	FLOWMETER_CH_5 ,
	FLOWMETER_CH_6 ,
	FLOWMETER_CH_7 ,
	FLOWMETER_CH_8 ,
	FLOWMETER_CH_9 ,
	FLOWMETER_CH_10 ,
	FLOWMETER_CH_11 ,
	FLOWMETER_CH_12 ,
	FLOWMETER_CH_13 ,
	FLOWMETER_CH_14 ,
	FLOWMETER_CH_15 ,
	FLOWMETER_CH_16 
}FlowMeter_ChannelType;

/* Type definition for FlowMeter_RegularChannelSequenceTypee used by the  flow meter APIs */
typedef enum{
	FLOWMETER_SQ_1 ,
	FLOWMETER_SQ_2 ,
	FLOWMETER_SQ_3 ,
	FLOWMETER_SQ_4 ,
	FLOWMETER_SQ_5 ,
	FLOWMETER_SQ_6 ,
	FLOWMETER_SQ_7 ,
	FLOWMETER_SQ_8 ,
	FLOWMETER_SQ_9 ,
	FLOWMETER_SQ_10 ,
	FLOWMETER_SQ_11 ,
	FLOWMETER_SQ_12 ,
	FLOWMETER_SQ_13 ,
	FLOWMETER_SQ_14 ,
	FLOWMETER_SQ_15 ,
	FLOWMETER_SQ_16
}FlowMeter_RegularChannelSequenceType;

/* Type definition for FlowMeter_InjectedChannelSequenceType used by the  flow meter APIs */
typedef enum{
	FLOWMETER_SQ_4 ,
	FLOWMETER_SQ_3 ,
	FLOWMETER_SQ_2 ,
	FLOWMETER_SQ_1 
	
}FlowMeter_InjectedChannelSequenceType;

/* Type definition for FlowMeter_RangeType used by the  flow meter APIs */
typedef uint8 FlowMeter_RangeType;
/* Type definition for FlowMeter_BufferType used by the  flow meter APIs */
typedef uint16 FlowMeter_BufferType;
/* Type definition for FlowMeter_ChannelSequenceType used by the  flow meter APIs */
typedef uint8 FlowMeter_ChannelSequenceType;


typedef struct
{
	/* Flow meter  ID */
	FlowMeter_ChannelIdType FlowMeter_Id;
	/* flowmeter group configured */
	FlowMeter_GroupType FlowMeter_Group;
	/* Flow meter channel */
	FlowMeter_ChannelType FlowMeter_Channel;
	/* Flow meter channel sequence*/
	FlowMeter_ChannelSequenceType FlowMeter_ChannelSequence;
	/* flowmeter TriggerSignalType configured */
	FlowMeter_TriggerSignalType Trigger_Signal;
	/* flowmeter FlowMeter_ResolutionType  configured */
	FlowMeter_ResolutionType FlowMeter_Resolution;
	/* flowmeter FlowMeter MinFlow configured */
	FlowMeter_RangeType  MinFlow;
	/* flowmeter FlowMeter MaxFlow configured */
	FlowMeter_RangeType  MaxFlow;
	/* flowmeter buffer configured */
	FlowMeter_BufferType FlowMeter_Buffer;
	
}FlowMeter_ConfigChannel;

/* Structure used in flow meter init */
typedef struct {
	FlowMeter_ConfigChannel FlowMeter_Channels[NUMBER_OF_FLOWMETERS];
} FlowMeter_ConfigType;
/*****************************************************************************************
 *					Function Prototypes
 ******************************************************************************************/
uint8 FlowMeter_Init(const FlowMeter_ConfigType* ConfigPtr);

float32 FlowMeter_Read(FlowMeter_ChannelType FlowMeter_Id);

void FlowMeter_Stop(FlowMeter_ChannelType FlowMeter_Id);

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by flow meter */
extern const FlowMeter_ConfigType FlowMeter_Configuration;



#endif /* INC_FLOWMETER_H_ */
