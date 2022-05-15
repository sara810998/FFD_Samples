/******************************************************************************
 *
 * Module: Gpt
 *
 * File Name: Gpt.h
 *
 * Description: Header file for GPT Module.
 *
 * Author: Eslam - Taha - Sara
 ******************************************************************************/

#ifndef GPT_H_
#define GPT_H_

/* Id for the company in the AUTOSAR  */
#define GPT_VENDOR_ID    (1000U)

/* Gpt Module Id */
#define GPT_MODULE_ID    (120U)

/* Gpt Instance Id */
#define GPT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define GPT_SW_MAJOR_VERSION           (1U)
#define GPT_SW_MINOR_VERSION           (0U)
#define GPT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define GPT_AR_RELEASE_MAJOR_VERSION   (4U)
#define GPT_AR_RELEASE_MINOR_VERSION   (0U)
#define GPT_AR_RELEASE_PATCH_VERSION   (3U)


/*
 * Macros for Gpt default none mode
 */
#define GPT_NONE                       (0U)

#define NUMBER_OF_GPT_CHANNELS 14

/* Standard AUTOSAR types */
#include "Std_Types.h"
/* AUTOSAR checking between Std Types and Gpt Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != GPT_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Gpt Pre-Compile Configuration Header file */
#include"Gpt_Cfg.h"
/* AUTOSAR Version checking between Gpt_Cfg.h and Gpt.h files */
#if ((GPT_CFG_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION)\
 ||  (GPT_CFG_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION)\
 ||  (GPT_CFG_AR_RELEASE_PATCH_VERSION != GPT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Gpt_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Gpt_Cfg.h and Gpt.h files */
#if ((GPT_CFG_SW_MAJOR_VERSION != GPT_SW_MAJOR_VERSION)\
 ||  (GPT_CFG_SW_MINOR_VERSION != GPT_SW_MINOR_VERSION)\
 ||  (GPT_CFG_SW_PATCH_VERSION != GPT_SW_PATCH_VERSION))
  #error "The SW version of Gpt_Cfg.h does not match the expected version"
#endif

/* Non AUTOSAR files */
#include "Common_Macros.h"

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for GPT Init */
#define GPT_INIT_SID 					(uint8)0x01

/* Service ID for GPT DeInit */
#define GPT_DEINIT_SID 					(uint8)0x02

/* Service ID for GPT get time elapsed */
#define GPT_GET_TIME_ELAPSED_SID		(uint8)0x03

/* Service ID for GPT get time remaining */
#define GPT_GET_TIME_REMAINING_SID		(uint8)0x04

/* Service ID for GPT get version info */
#define GPT_GET_VERSION_INFO_SID		(uint8)0x00

/* Service ID for GPT start timer */
#define GPT_START_TIMER_SID				(uint8)0x05

/* Service ID for GPT stop timer */
#define GPT_STOP_TIMER_SID				(uint8)0x06

/* Service ID for GPT enable notification */
#define GPT_ENABLE_NOTIFICATION_SID		(uint8)0x07

/* Service ID for GPT disable notification */
#define GPT_DISABLE_NOTIFICATION_SID	(uint8)0x08

/* Service ID for GPT set mode */
#define GPT_SET_MODE_SID				(uint8)0x09

/* Service ID for GPT disable wake up */
#define GPT_DISABLE_WAKEUP_SID			(uint8)0x0A

/* Service ID for GPT disable wake up */
#define GPT_ENABLE_WAKEUP_SID			(uint8)0x0A

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* DET code for API service called without module initialization */
#define GPT_E_UNINIT 					(uint8)0x0A

/* DET code for API service when timer channel is busy */
#define GPT_E_BUSY 						(uint8)0x0B

/* DET code for API service called when already initialized */
#define GPT_E_ALREADY_INITIALIZED 		(uint8)0x0D

/* DET code for API service called with wrong parameter */
#define GPT_E_PARAM_CHANNEL				(uint8)0x14

/* DET code for API service called with invalid value */
#define GPT_E_PARAM_VALUE				(uint8)0x15

/* DET code for APIs called with a Null Pointer */
#define GPT_E_PARAM_POINTER 			(uint8)0x16

/* DET code for APIs called with a invalid mode */
#define GPT_E_PARAM_MODE 				(uint8)0x1F


/*******************************************************************************
 *                      Default Configurations                                 *
 *******************************************************************************/

#define DEFAULT_GPT_ChannelStatus_CONFIG GPT_NOT_CONFIGURED
#define DEFAULT_GPT_ChannelState_CONFIG GPT_NOT_INITIALIZED
#define DEFAULT_GPT_CHANNEL_TYPE_CONFIG GPT_NONE
#define DEFAULT_GPT_VALUE_TYPE_CONFIG GPT_NONE
#define DEFAULT_GPT_MODE_TYPE_CONFIG GPT_NONE
#define DEFAULT_GPT_TARGET_NUM_TICKS_CONFIG GPT_NONE
#define DEFAULT_GPT_COUNTER_REPETITION_TYPE_CONFIG GPT_NONE
#define DEFAULT_GPT_CLOCK_PRESCALER_CONFIG GPT_NONE
#define DEFAULT_GPT_CHANNEL_CLOCK_SOURCE_CONFIG GPT_NONE
#define DEFAULT_GPT_CHANNEL_COUNTING_MODE_CONFIG GPT_NONE
#define DEFAULT_GPT_CHANNEL_COUNTING_DIRECTION_CONFIG GPT_NONE
#define DEFAULT_GPT_CHANNEL_NOTIFICATION NONE


/*******************************************************************************
 *                         Numbers Definitions                                 *
 *******************************************************************************/

#define ZERO 0
#define ONE 1

/*
 * global array of pointers to callback function
 * used in notification function to store the address of callback function
 * configured in the configuration structure
 * to be used in function call back in ISR
 */
void (*Gpt_Callback_Pointer[14]) (void);

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
/* Type definition for Gpt_ChannelType used by the GPT APIs */
typedef uint8 Gpt_ChannelType;

/* Type definition for Gpt_ValueType used by the GPT APIs */
typedef uint32 Gpt_ValueType;

/* Type definition for Gpt_ModeType used by the GPT APIs */
typedef uint8 Gpt_ModeType;

/* Type definition for Gpt_CounterRepetitionType used by the GPT APIs */
typedef uint8 Gpt_CounterRepetitionType;

/* Type definition for GPT_ClockPrescaler used by the GPT APIs */
typedef uint16 GPT_ClockPrescaler;

/* Type definition for Gpt_ChannelTickValueMax used by the GPT APIs */
typedef uint32 Gpt_ChannelTickValueMax;

/* Type definition for Gpt_ChannelStatus used by the GPT APIs */
typedef enum{
	GPT_NOT_CONFIGURED,
	GPT_CONFIGURED
}Gpt_ChannelStatus;

/* Type definition for Gpt_ChannelGroup used by the GPT APIs */
typedef enum{
	ADVANCED_CONTROL,
	GENERAL_PURPOSE,
	BASIC
}Gpt_ChannelGroup;

/* Type definition for Gpt_ChannelId used by the GPT APIs */
typedef enum {
	GPT_0,
	GPT_1,
	GPT_2,
	GPT_3,
	GPT_4,
	GPT_5,
	GPT_6,
	GPT_7,
	GPT_8,
	GPT_9,
	GPT_10,
	GPT_11,
	GPT_12,
	GPT_13
} Gpt_ChannelId;

/* Type definition for Gpt_ChannelMode used by the GPT APIs */
typedef enum {
	GPT_CH_MODE_CONTINUOUS,
	GPT_CH_MODE_ONESHOT
} Gpt_ChannelMode;


/* Type definition for Gpt_ChannelMode used by the GPT APIs */
typedef enum {
	EDGE_ALIGNED_MODE,
	CENTER_ALIGNED_MODE_ONE,
	CENTER_ALIGNED_MODE_TWO,
	CENTER_ALIGNED_MODE_THREE,
	GPT_CHANNEL_COUNTING_MODE_NONE
} Gpt_ChannelCountingMode;

/* Type definition for Gpt_ChannelCountingDirection used by the GPT APIs */
typedef enum {
	GPT_UP_COUNTER,
	GPT_DOWN_COUNTER,
	GPT_CHANNEL_COUNTING_DIRECTION_NONE
} Gpt_ChannelCountingDirection;

/* Type definition for Gpt_ChannelClockSource used by the GPT APIs */
typedef enum {
	INTERNAL_CLOCK,
	EXTERNAL_TRIGGER_INPUT,
	EXTERNAL_INPUT_PIN = 7,
	INTERNAL_TRIGGER_INPUT,
	Gpt_CHANNEL_CLOCK_SOURCE_NONE
} Gpt_ChannelClockSource;

/* Type definition for Gpt_ChannelState used by the GPT APIs */
typedef enum {
	GPT_NOT_INITIALIZED,
	GPT_INITIALIZED,
	GPT_RUNNING,
	GPT_STOPPED,
	GPT_EXPIRED
} Gpt_ChannelState;


/* Type definition for Gpt_IRQ_Number used by the GPT APIs */
typedef enum {
	IRQn_TIM1 = 25, /*TIM1 Update Interrupt*/
	IRQn_TIM2 = 28, /*TIM2 global Interrupt*/
	IRQn_TIM3, /*TIM3 global Interrupt*/
	IRQn_TIM4, /*TIM4 global Interrupt*/
	IRQn_TIM5 =50, /*TIM2 global Interrupt*/
	IRQn_TIM6 =54, /*TIM6 global Interrupt*/
	IRQn_TIM7, /*TIM7 global Interrupt*/
	IRQn_TIM8 = 44, /*TIM1 Update Interrupt*/
	IRQn_TIM9 = 24, /*TIM9 global Interrupt*/
	IRQn_TIM10, /*TIM10 global Interrupt*/
	IRQn_TIM11, /*TIM11 global Interrupt*/
	IRQn_TIM12 = 43, /*TIM12 global Interrupt*/
	IRQn_TIM13,/*TIM13 global Interrupt*/
	IRQn_TIM14 /*TIM4 global Interrupt*/
} Gpt_IRQ_Number;


typedef struct {
	/*Member contains the status of the Gpt channel  */
	Gpt_ChannelStatus channelStatusConfig;
	/* Member contains the state of the Gpt channel */
	Gpt_ChannelState channelStateConfig;
	/* Member contains the ID of the Gpt channel */
	Gpt_ChannelType channelIDConfig;
	/* Member contains the Value of the Gpt */
	Gpt_ValueType valueTypeConfig;
	/* Member contains the Mode of the Gpt */
	Gpt_ModeType modeTypeConfig;
	/* Member contains the Max value of the Gpt */
	Gpt_ChannelTickValueMax channelTickValueMaxConfig;
	/* Member contains the clock prescaler of the Gpt */
	GPT_ClockPrescaler clockPrescalerConfig;
	/* Member contains the Clock source of the Gpt */
	Gpt_ChannelClockSource channelClockSourceConfig;
	/* Member contains the Mode of counting of the Gpt */
	Gpt_ChannelCountingMode channelCountingModeConfig;
	/* Member contains the Direction of counting of the Gpt */
	Gpt_ChannelCountingDirection channelCountingDirectionConfig;
	/* Member contains the number of Repetition of counting of the Gpt */
	Gpt_CounterRepetitionType channelCountingRepetitionConfig;
	/* Member is function pointer to the callback function of the Gpt channel */
	void (*GptNotification)(void);
} Gpt_ConfigChannel;

/* Data Structure required for initializing the Gpt Driver */
typedef struct {
	Gpt_ConfigChannel Gpt_Channels[NUMBER_OF_GPT_CHANNELS];
} Gpt_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
/* Function for GPT Initialization API */
void Gpt_Init(const Gpt_ConfigType *ConfigPtr);

/* Function for GPT DeInitialization API */
void Gpt_DeInit(void);

/* Function for GPT Get Time Elapsed API */
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel);

/* Function for GPT Get Time Remaining API */
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel);

/* Function for GPT Version API */
void Gpt_GetVersionInfo(Std_VersionInfoType *versioninfo);

/* Function for GPT Start Timer API */
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value);

/* Function for GPT Stop Timer API */
void Gpt_StopTimer(Gpt_ChannelType Channel);

/* Function for GPT Enable Notification API */
void Gpt_EnableNotification(Gpt_ChannelType Channel);

/* Function for GPT Disable Notification API */
void Gpt_DisableNotification(Gpt_ChannelType Channel);

/* Function for GPT Set Mode API */
void Gpt_SetMode(Gpt_ModeType Mode);

/* Function for GPT Disable Wake up API */
void Gpt_DisableWakeup(Gpt_ChannelType Channel);

/* Function for GPT Enable Wake up API */
void Gpt_EnableWakeup(Gpt_ChannelType Channel);

/**************************************************************
 * Gpt_CheckWakeup function prototype is not implemented yet
 **************************************************************/
/*******************************************************************************
 *                       GPT notification function prototypes                  *
 *******************************************************************************/
void Gpt_Notification_Channel0 (void);
void Gpt_Notification_Channel1 (void);
void Gpt_Notification_Channel2 (void);
void Gpt_Notification_Channel3 (void);
void Gpt_Notification_Channel4 (void);
void Gpt_Notification_Channel5 (void);
void Gpt_Notification_Channel6 (void);
void Gpt_Notification_Channel7 (void);
void Gpt_Notification_Channel8 (void);
void Gpt_Notification_Channel9 (void);
void Gpt_Notification_Channel10 (void);
void Gpt_Notification_Channel11 (void);
void Gpt_Notification_Channel12 (void);
void Gpt_Notification_Channel13 (void);

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Gpt and other modules */
extern const Gpt_ConfigType Gpt_Configuration;

#endif /* GPT_H_ */
