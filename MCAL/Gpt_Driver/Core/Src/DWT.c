/******************************************************************************
 *
 * Module: DWT
 *
 * File Name: DWT.c
 *
 * Description: Source file for DWT Module.
 *
 * Author: Eslam - Taha - Sara
 ******************************************************************************/


#include <DWT.h>

void DWT_Init(void)
{
    if (!(CoreDebug->DEMCR & CoreDebug_DEMCR_TRCENA_Msk)) {
        CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
        DWT->CYCCNT = 0;
        DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
    }
}


uint32 DWT_currentClock(void)
{
    return DWT->CYCCNT;
}
