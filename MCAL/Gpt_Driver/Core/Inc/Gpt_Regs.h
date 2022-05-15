/******************************************************************************
 *
 * Module: Gpt
 *
 * File Name: Gpt_Regs.h
 *
 * Description: Header file for Gpt Module Registers.
 *
 * Author: Eslam - Taha - Sara
 ******************************************************************************/

#ifndef GPT_REGS_H
#define GPT_REGS_H

#include "Std_Types.h"

typedef union {
	uint32 val;
	struct {
		uint32 _0 :1;
		uint32 _1 :1;
		uint32 _2 :1;
		uint32 _3 :1;
		uint32 _4 :1;
		uint32 _5 :1;
		uint32 _6 :1;
		uint32 _7 :1;
		uint32 _8 :1;
		uint32 _9 :1;
		uint32 _10 :1;
		uint32 _11 :1;
		uint32 _12 :1;
		uint32 _13 :1;
		uint32 _14 :1;
		uint32 _15 :1;
		uint32 _16 :1;
		uint32 _17 :1;
		uint32 _18 :1;
		uint32 _19 :1;
		uint32 _20 :1;
		uint32 _21 :1;
		uint32 _22 :1;
		uint32 _23 :1;
		uint32 _24 :1;
		uint32 _25 :1;
		uint32 _26 :1;
		uint32 _27 :1;
		uint32 _28 :1;
		uint32 _29 :1;
		uint32 _30 :1;
		uint32 _31 :1;
	} bits;

	struct {
		uint32 _0 :4;
		uint32 _1 :4;
		uint32 _2 :4;
		uint32 _3 :4;
		uint32 _4 :4;
		uint32 _5 :4;
		uint32 _6 :4;
		uint32 _7 :4;
	} nibbles;

	struct {
		uint32 _0 :8;
		uint32 _1 :8;
		uint32 _2 :8;
		uint32 _3 :8;
	} bytes;

	struct {
		uint32 _0 :16;
		uint32 _1 :16;
	} words;

} _32_BIT_REGISTER;

typedef struct {
	_32_BIT_REGISTER CR1; /* GPT control register 1              */
	_32_BIT_REGISTER CR2; /* GPT control register 2              */
	_32_BIT_REGISTER SMCR; /* GPT slave mode control register     */
	_32_BIT_REGISTER DIER; /* GPT DMA/interrupt enable register   */
	_32_BIT_REGISTER SR; /* GPT status register                 */
	_32_BIT_REGISTER EGR; /* GPT event generation register       */
	_32_BIT_REGISTER CCMR1; /* GPT capture/compare mode register 1 */
	_32_BIT_REGISTER CCMR2; /* GPT capture/compare mode register 2 */
	_32_BIT_REGISTER CCER; /* GPT capture/compare enable register */
	_32_BIT_REGISTER CNT; /* GPT counter register                */
	_32_BIT_REGISTER PSC; /* GPT prescaler                       */
	_32_BIT_REGISTER ARR; /* GPT auto-reload register            */
	_32_BIT_REGISTER RCR; /* GPT repetition counter register     */
	_32_BIT_REGISTER CCR1; /* GPT capture/compare register 1      */
	_32_BIT_REGISTER CCR2; /* GPT capture/compare register 2      */
	_32_BIT_REGISTER CCR3; /* GPT capture/compare register 3      */
	_32_BIT_REGISTER CCR4; /* GPT capture/compare register 4      */
	_32_BIT_REGISTER BDTR; /* GPT break and dead-GPTe register    */
	_32_BIT_REGISTER DCR; /* GPT DMA control register            */
	_32_BIT_REGISTER DMAR; /* GPT DMA address for full transfer   */
	_32_BIT_REGISTER OR; /* GPT option register                 */
} Gpt_TypeDef;


typedef struct {
	_32_BIT_REGISTER ISER[8]; /* NVIC interrupt set enable register from NVIC_ISER0 to NVIC_ISER7*/
} Gpt_NVIC_ISER;

typedef struct {
	_32_BIT_REGISTER ICER[8]; /* NVIC interrupt clear enable register from NVIC_ICER0 to NVIC_ICER7*/
} Gpt_NVIC_ICER;

/* CR1 Reg Bits */
#define CEN_BIT 0

#define PERIPH_BASE           0x40000000

#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)

#define TIM1_BASE             (APB2PERIPH_BASE + 0x0000UL)
#define TIM2_BASE             (APB1PERIPH_BASE + 0x0000UL)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x0400UL)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x0800UL)
#define TIM5_BASE             (APB1PERIPH_BASE + 0x0C00UL)
#define TIM6_BASE             (APB1PERIPH_BASE + 0x1000UL)
#define TIM7_BASE             (APB1PERIPH_BASE + 0x1400UL)
#define TIM8_BASE             (APB2PERIPH_BASE + 0x0400UL)
#define TIM9_BASE             (APB2PERIPH_BASE + 0x4000UL)
#define TIM10_BASE            (APB2PERIPH_BASE + 0x4400UL)
#define TIM11_BASE            (APB2PERIPH_BASE + 0x4800UL)
#define TIM12_BASE            (APB1PERIPH_BASE + 0x1800UL)
#define TIM13_BASE            (APB1PERIPH_BASE + 0x1C00UL)
#define TIM14_BASE            (APB1PERIPH_BASE + 0x2000UL)

#define TIM1_TypeDef                ((Gpt_TypeDef *) TIM1_BASE)
#define TIM2_TypeDef                ((Gpt_TypeDef *) TIM2_BASE)
#define TIM3_TypeDef                ((Gpt_TypeDef *) TIM3_BASE)
#define TIM4_TypeDef                ((Gpt_TypeDef *) TIM4_BASE)
#define TIM5_TypeDef                ((Gpt_TypeDef *) TIM5_BASE)
#define TIM6_TypeDef                ((Gpt_TypeDef *) TIM6_BASE)
#define TIM7_TypeDef                ((Gpt_TypeDef *) TIM7_BASE)
#define TIM8_TypeDef                ((Gpt_TypeDef *) TIM8_BASE)
#define TIM9_TypeDef                ((Gpt_TypeDef *) TIM9_BASE)
#define TIM10_TypeDef               ((Gpt_TypeDef *) TIM10_BASE)
#define TIM11_TypeDef               ((Gpt_TypeDef *) TIM11_BASE)
#define TIM12_TypeDef               ((Gpt_TypeDef *) TIM12_BASE)
#define TIM13_TypeDef               ((Gpt_TypeDef *) TIM13_BASE)
#define TIM14_TypeDef               ((Gpt_TypeDef *) TIM14_BASE)

#define ISER_ADDRESS			(0xE000E100)
#define GPT_NVIC_ISER           ((Gpt_NVIC_ISER *) ISER_ADDRESS)

#define ICER_ADDRESS			(0xE000E100)
#define GPT_NVIC_ICER           ((Gpt_NVIC_ICER *) ICER_ADDRESS)

#endif /* GPT_REGS_H */
