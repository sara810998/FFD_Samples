
/*****************************************************************************
 *
 * Module: Gpt
 *
 * File Name: Gpt_irq.c
 *
 * Description: Source file for irq Gpt Module.
 *
 * Author: Eslam - Taha - Sara
 *****************************************************************************/
#include "Gpt.h"

void IRQn_TIM1Handler (void);
void IRQn_TIM2Handler (void);
void IRQn_TIM3Handler (void);
void IRQn_TIM4Handler (void);
void IRQn_TIM5Handler (void);
void IRQn_TIM6Handler (void);
void IRQn_TIM7Handler (void);
void IRQn_TIM8Handler (void);
void IRQn_TIM9Handler (void);
void IRQn_TIM10Handler (void);
void IRQn_TIM11Handler (void);
void IRQn_TIM12Handler (void);
void IRQn_TIM13Handler (void);
void IRQn_TIM14Handler (void);

void IRQn_TIM1Handler (void){

	(*Gpt_Callback_Pointer[0])();

}

void IRQn_TIM2Handler (void){

	(*Gpt_Callback_Pointer[1]);

}

void IRQn_TIM3Handler (void){

	(*Gpt_Callback_Pointer[2]);

}

void IRQn_TIM4Handler (void){

	(*Gpt_Callback_Pointer[3]);

}
void IRQn_TIM5Handler (void){

	(*Gpt_Callback_Pointer[4]);

}
void IRQn_TIM6Handler (void){

	(*Gpt_Callback_Pointer[5]);

}
void IRQn_TIM7Handler (void){

	(*Gpt_Callback_Pointer[6]);

}
void IRQn_TIM8Handler (void){

	(*Gpt_Callback_Pointer[7]);

}
void IRQn_TIM9Handler (void){

	(*Gpt_Callback_Pointer[8]);

}
void IRQn_TIM10Handler (void){

	(*Gpt_Callback_Pointer[9]);

}
void IRQn_TIM11Handler (void){

	(*Gpt_Callback_Pointer[10]);

}
void IRQn_TIM12Handler (void){

	(*Gpt_Callback_Pointer[11]);

}
void IRQn_TIM13Handler (void){

	(*Gpt_Callback_Pointer[12]);

}
void IRQn_TIM14Handler (void){

	(*Gpt_Callback_Pointer[13]);

}

