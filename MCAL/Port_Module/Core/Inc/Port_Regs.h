 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Regs.h
 *
 * Description: Header file for Port Module Registers.
 *
 * Author: Eslam - Taha - Sara
 ******************************************************************************/

#ifndef INC_PORT_REGS_H_
#define INC_PORT_REGS_H_
#include <Std_Types.h>

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

typedef struct
{
	_32_BIT_REGISTER MODER;    /* GPIO port mode register               */
	_32_BIT_REGISTER OTYPER;   /* GPIO port output type register        */
	_32_BIT_REGISTER OSPEEDR;  /* GPIO port output speed register       */
	_32_BIT_REGISTER PUPDR;    /* GPIO port pull-up/pull-down register  */
	_32_BIT_REGISTER IDR;      /* GPIO port input data register         */
	_32_BIT_REGISTER ODR;      /* GPIO port output data register        */
	_32_BIT_REGISTER BSRR;     /* GPIO port bit set/reset register      */
	_32_BIT_REGISTER LCKR;     /* GPIO port configuration lock register */
	_32_BIT_REGISTER AFRL;     /* GPIO alternate function low register  */
	_32_BIT_REGISTER AFRH;     /* GPIO alternate function high register */
}GPIO_RegDef;

#define PERIPH_BASE           0x40000000

#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000)

#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASE            (AHB1PERIPH_BASE + 0x1000)
#define GPIOF_BASE            (AHB1PERIPH_BASE + 0x1400)
#define GPIOG_BASE            (AHB1PERIPH_BASE + 0x1800)
#define GPIOH_BASE            (AHB1PERIPH_BASE + 0x1C00)
#define GPIOI_BASE            (AHB1PERIPH_BASE + 0x2000)
#define GPIOJ_BASE            (AHB1PERIPH_BASE + 0x2400)
#define GPIOK_BASE            (AHB1PERIPH_BASE + 0x2800)

#define GPIOA                 ((GPIO_RegDef *) GPIOA_BASE)
#define GPIOB                 ((GPIO_RegDef *) GPIOB_BASE)
#define GPIOC                 ((GPIO_RegDef *) GPIOC_BASE)
#define GPIOD                 ((GPIO_RegDef *) GPIOD_BASE)
#define GPIOE                 ((GPIO_RegDef *) GPIOE_BASE)
#define GPIOF                 ((GPIO_RegDef *) GPIOF_BASE)
#define GPIOG                 ((GPIO_RegDef *) GPIOG_BASE)
#define GPIOH                 ((GPIO_RegDef *) GPIOH_BASE)
#define GPIOI                 ((GPIO_RegDef *) GPIOI_BASE)
#define GPIOJ                 ((GPIO_RegDef *) GPIOJ_BASE)
#define GPIOK                 ((GPIO_RegDef *) GPIOK_BASE)

///* Definition for GPIO clock Register */
//#define RCC_AHB1ENR			((uint32 *)0x40023830)
typedef struct
{
	_32_BIT_REGISTER RCC_CR;
	_32_BIT_REGISTER RCC_PLLCFGR;
	_32_BIT_REGISTER RCC_CFGR;
	_32_BIT_REGISTER RCC_CIR;
	_32_BIT_REGISTER RCC_AHB1RSTR;
	_32_BIT_REGISTER RCC_AHB2RSTR;
	_32_BIT_REGISTER RCC_AHB3RSTR;
	_32_BIT_REGISTER RCC_APB1RSTR;
	_32_BIT_REGISTER RCC_APB2RSTR;
	_32_BIT_REGISTER RCC_AHB1ENR;
	_32_BIT_REGISTER RCC_AHB2ENR;
	_32_BIT_REGISTER RCC_AHB3ENR;
	_32_BIT_REGISTER RCC_APB1ENR;
	_32_BIT_REGISTER RCC_APB2ENR;
	_32_BIT_REGISTER RCC_AHB1LPENR;
	_32_BIT_REGISTER RCC_AHB2LPENR;
	_32_BIT_REGISTER RCC_AHB3LPENR;
	_32_BIT_REGISTER RCC_APB1LPENR;
	_32_BIT_REGISTER RCC_APB2LPENR;
	_32_BIT_REGISTER RCC_BDCR;
	_32_BIT_REGISTER RCC_CSR;
	_32_BIT_REGISTER RCC_SSCGR;
	_32_BIT_REGISTER RCC_PLLI2SCFGR;
	_32_BIT_REGISTER RCC_PLLSAICFGR;
	_32_BIT_REGISTER RCC_DCKCFGR;
}RCC_RegDef;

#define RCC_BASE (AHB1PERIPH_BASE + 3800 )
#define RCC		 ((RCC_RegDef *) RCC_BASE)
#endif /* INC_PORT_REGS_H_ */
