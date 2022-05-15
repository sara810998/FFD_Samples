/******************************************************************************
 *
 * Module: DWT
 *
 * File Name: DWT.h
 *
 * Description: Header file for DWT Module.
 *
 * Author: Eslam - Taha - Sara
 ******************************************************************************/
 /*
  * used to get the excution time of the function 
  */

#ifndef INC_DWT_H_
#define INC_DWT_H_

#include "stm32f4xx_hal.h"
#include "std_types.h"

void DWT_Init(void);
uint32 DWT_currentClock(void);

#endif /* INC_DWT_H_ */
