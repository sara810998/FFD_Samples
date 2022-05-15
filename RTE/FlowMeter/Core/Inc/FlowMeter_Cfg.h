/******************************************************************************
 *
 * Module: Flow Meter
 *
 * File Name: FlowMeter_cfg.h
 *
 * Description: Header file for flow meter configuration.
 *
 * Author: Eslam - Taha - Sara
 ******************************************************************************/

#ifndef INC_FLOWMETER_CFG_H_
#define INC_FLOWMETER_CFG_H_

#include "Std_Types.h"
/* method of reading the output current value from the Flow meter*/
/*method one reading the voltage across resistance and so know the current value*/
#define RESISTANCE_METHOD (0U)
/*using current sensor to read its output analog voltage and so know the current value*/
#define CURRENT_SENSOR_METHOD (1U)

#define NUMBER_OF_FLOWMETERS (1U)  /*number of flow meters in the system*/
#define GET_VALUE_METHOD RESISTANCE_METHOD /*specify the method used to calculate the flowrate*/

#define ADC_FLOWMETER_1_RESISTANCE_VALUE			(uint16(150U)) 		/*value of resistance to convert the current output as ADC measure voltage*/
#define ADC_FLOWMETER_1_MAX_OUTPUT_CURRENT			(uint16(20U))  		/*max output current from the sensor which is proportional to the flow*/
#define ADC_FLOWMETER_1_MIN_OUTPUT_CURRENT			(uint16(4U))   		/*min output current from the sensor which is proportional to the flow*/
#define ADC_FLOWMETER_1_REFERENCE					(uint16(3U))   		/*max output voltage by microcontroller*/


#define ADC_FLOWMETER_1_ID FLOWMETER_1 /*flow meter index */
#define ADC_FLOWMETER_1_GROUP_INDEX FLOWMETER_1_INJECTED_GROUP /*flow meter group in the adc module*/
#define FLOWMETER_CHANNEL_INDEX FLOWMETER_CH_0   /*id of cahnnel connected to the flow meter*/
#define FLOWMETER_CHANNEL_SEQUENCE FLOWMETER_SQ_4  /*flow meter index in the buffer array of the group*/
#define ADC_FLOWMETER_1_HW_SIGNAL_TYPE FLOWMETER_SW_TRIG  /*flow meter start  conversion signal hardware or software trig.*/
#define ADC_FLOWMETER_1_RESOLUTION 					FLOWMETER_12_BIT		/*resolution of the unit connected to flow meter*/
#define ADC_FLOWMETER_1_MIN_FLOW					(uint16(0U))   		/*min flow can be measured by sensor*/
#define ADC_FLOWMETER_1_MAX_FLOW					(uint16(82U))  		/*max flow can be measured by sensor*/
#define ADC_FLOWMETER_BUFFER_ADRESS 





#endif /* INC_FLOWMETER_CFG_H_ */
