/******************************************************************************
* File Name          : stm_regs.h
* Author             : P Acco/ S DI Mercurio/ ST semiconductors
* Version            : V1.0.0
* Date               : 24/02/2010
* Description        : This file contains all the peripheral register's definitions
*                      and memory mapping + Bits definitions
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM_REGS_H__
#define __STM_REGS_H__

#ifndef EXT
  #define EXT extern
#endif /* EXT */

/* Includes ------------------------------------------------------------------*/
#include "standard_types.h"
#include "stm32f10x_conf.h"
#include "cortexm3_macro.h"
#include "stm32f10x_type.h"
/* Exported types ------------------------------------------------------------*/
/******************************************************************************/
/*                         Peripheral registers structures                    */
/******************************************************************************/

/*------------------------ Analog to Digital Converter -----------------------*/
typedef struct
{
  vu32 SR;
  vu32 CR1;
  vu32 CR2;
  vu32 SMPR1;
  vu32 SMPR2;
  vu32 JOFR1;
  vu32 JOFR2;
  vu32 JOFR3;
  vu32 JOFR4;
  vu32 HTR;
  vu32 LTR;
  vu32 SQR1;
  vu32 SQR2;
  vu32 SQR3;
  vu32 JSQR;
  vu32 JDR1;
  vu32 JDR2;
  vu32 JDR3;
  vu32 JDR4;
  vu32 DR;
} ADC_TypeDef;

//ADC1->CR1 bit description
#define ADC_AWDCH_MASK	0x1F
#define ADC_EOCIE 	(1<<5)
#define ADC_AWDIE 	(1<<6)
#define ADC_JEOCIE 	(1<<7)
#define ADC_SCAN 	(1<<8)
#define ADC_AWDSGL 	(1<<9)
#define ADC_JAUTO 	(1<<10)
#define ADC_DISCEN 	(1<<11)
#define ADC_JDISCEN (1<<12)
#define ADC_DISCNUM_SHIFT (13)
#define ADC_DUALMOD_SHIFT (16)
#define ADC_JAWDEN  (1<<22)
#define ADC_AWDEN  	(1<<23)

// Values definition for CR1 fields
// Values for DISCNUM field
#define ADC_DISCNUM_IS_1_CHANNEL	(0<<ADC_DISCNUM_SHIFT)
#define ADC_DISCNUM_IS_2_CHANNELS	(1<<ADC_DISCNUM_SHIFT)
#define ADC_DISCNUM_IS_3_CHANNELS	(2<<ADC_DISCNUM_SHIFT)
#define ADC_DISCNUM_IS_4_CHANNELS	(3<<ADC_DISCNUM_SHIFT)
#define ADC_DISCNUM_IS_5_CHANNELS	(4<<ADC_DISCNUM_SHIFT)
#define ADC_DISCNUM_IS_6_CHANNELS	(5<<ADC_DISCNUM_SHIFT)
#define ADC_DISCNUM_IS_7_CHANNELS	(6<<ADC_DISCNUM_SHIFT)
#define ADC_DISCNUM_IS_8_CHANNELS	(7<<ADC_DISCNUM_SHIFT)

// Values for DUALMOD field
#define ADC_DUALMOD_IS_INDEPENDANT 	(0<<ADC_DUALMOD_SHIFT)
#define ADC_DUALMOD_IS_COMBINED_1 	(1<<ADC_DUALMOD_SHIFT)
#define ADC_DUALMOD_IS_COMBINED_2 	(2<<ADC_DUALMOD_SHIFT)
#define ADC_DUALMOD_IS_COMBINED_3 	(3<<ADC_DUALMOD_SHIFT)
#define ADC_DUALMOD_IS_COMBINED_4 	(4<<ADC_DUALMOD_SHIFT)
#define ADC_DUALMOD_IS_INJECTED 	(5<<ADC_DUALMOD_SHIFT)
#define ADC_DUALMOD_IS_REGULAR 		(6<<ADC_DUALMOD_SHIFT)
#define ADC_DUALMOD_IS_FAST 		(7<<ADC_DUALMOD_SHIFT)
#define ADC_DUALMOD_IS_SLOW 		(8<<ADC_DUALMOD_SHIFT)
#define ADC_DUALMOD_IS_ALTERNATE 	(9<<ADC_DUALMOD_SHIFT)

//ADC1->CR2 bit description
#define ADC_ADON 		(1<<0)
#define ADC_CONT 		(1<<1)
#define ADC_CAL 		(1<<2)
#define ADC_RSTCAL 		(1<<3)
#define ADC_DMA 		(1<<8)
#define ADC_ALIGN 		(1<<11)
#define ADC_JEXTSEL_SHIFT 	(12)
#define ADC_JEXTTRIG 	(1<<15)
#define ADC_EXTSEL_SHIFT (17)
#define ADC_EXTSEL_ON_SWSTART (7<<ADC_EXTSEL_SHIFT)
#define ADC_EXTTRIG  	(1<<20)
#define ADC_JSWSTART 	(1<<21)
#define ADC_SWSTART  	(1<<22)
#define ADC_TSVREFE  	(1<<23)

// Values definition for CR2 fields
// Values for JEXTSEL field
#define ADC_JEXTSEL_IS_TIM1_TRGO	(0<<ADC_JEXTSEL_SHIFT)
#define ADC_JEXTSEL_IS_TIM1_CC4		(1<<ADC_JEXTSEL_SHIFT)
#define ADC_JEXTSEL_IS_TIM2_TRGO	(2<<ADC_JEXTSEL_SHIFT)
#define ADC_JEXTSEL_IS_TIM2_CC1		(3<<ADC_JEXTSEL_SHIFT)
#define ADC_JEXTSEL_IS_TIM3_CC4		(4<<ADC_JEXTSEL_SHIFT)
#define ADC_JEXTSEL_IS_TIM4_TRGO	(5<<ADC_JEXTSEL_SHIFT)
#define ADC_JEXTSEL_IS_EXTI			(6<<ADC_JEXTSEL_SHIFT)
#define ADC_JEXTSEL_IS_JSWSTART		(7<<ADC_JEXTSEL_SHIFT)

// Values for EXTSEL field
#define ADC_JEXTSEL_IS_TIM1_CC1		(0<<ADC_JEXTSEL_SHIFT)
#define ADC_JEXTSEL_IS_TIM1_CC2		(1<<ADC_JEXTSEL_SHIFT)
#define ADC_JEXTSEL_IS_TIM1_CC3		(2<<ADC_JEXTSEL_SHIFT)
#define ADC_JEXTSEL_IS_TIM2_CC2		(3<<ADC_JEXTSEL_SHIFT)
#define ADC_JEXTSEL_IS_TIM3_TRGO	(4<<ADC_JEXTSEL_SHIFT)
#define ADC_JEXTSEL_IS_TIM4_CC4		(5<<ADC_JEXTSEL_SHIFT)
#define ADC_JEXTSEL_IS_EXTI			(6<<ADC_JEXTSEL_SHIFT)
#define ADC_JEXTSEL_IS_SWSTART		(7<<ADC_JEXTSEL_SHIFT)

//ADC1->SQR1 bit description
#define ADC_SQ13_SHIFT (0)
#define ADC_SQ14_SHIFT (5)
#define ADC_SQ15_SHIFT (10)
#define ADC_SQ16_SHIFT (15)
#define ADC_L_SHIFT (20)

// Values definition for SQR1 fields
// Values for L field
#define ADC_L_IS_1_CONVERSION		(0<<ADC_L_SHIFT)
#define ADC_L_IS_2_CONVERSIONS		(1<<ADC_L_SHIFT)
#define ADC_L_IS_3_CONVERSIONS		(2<<ADC_L_SHIFT)
#define ADC_L_IS_4_CONVERSIONS		(3<<ADC_L_SHIFT)
#define ADC_L_IS_5_CONVERSIONS		(4<<ADC_L_SHIFT)
#define ADC_L_IS_6_CONVERSIONS		(5<<ADC_L_SHIFT)
#define ADC_L_IS_7_CONVERSIONS		(6<<ADC_L_SHIFT)
#define ADC_L_IS_8_CONVERSIONS		(7<<ADC_L_SHIFT)
#define ADC_L_IS_9_CONVERSIONS		(8<<ADC_L_SHIFT)
#define ADC_L_IS_10_CONVERSIONS		(9<<ADC_L_SHIFT)
#define ADC_L_IS_11_CONVERSIONS		(10<<ADC_L_SHIFT)
#define ADC_L_IS_12_CONVERSIONS		(11<<ADC_L_SHIFT)
#define ADC_L_IS_13_CONVERSIONS		(12<<ADC_L_SHIFT)
#define ADC_L_IS_14_CONVERSIONS		(13<<ADC_L_SHIFT)
#define ADC_L_IS_15_CONVERSIONS		(14<<ADC_L_SHIFT)
#define ADC_L_IS_16_CONVERSIONS		(15<<ADC_L_SHIFT)

//ADC1->SQR2 bit description
#define ADC_SQ7_SHIFT 	(0)
#define ADC_SQ8_SHIFT 	(5)
#define ADC_SQ9_SHIFT 	(10)
#define ADC_SQ10_SHIFT 	(15)
#define ADC_SQ11_SHIFT 	(20)
#define ADC_SQ12_SHIFT 	(25)

//ADC1->SQR3 bit description
#define ADC_SQ1_SHIFT (0)
#define ADC_SQ2_SHIFT (5)
#define ADC_SQ3_SHIFT (10)
#define ADC_SQ4_SHIFT (15)
#define ADC_SQ5_SHIFT (20)
#define ADC_SQ6_SHIFT (25)

//ADC1->JSQR bit description
#define ADC_JSQ1_SHIFT 	(0)
#define ADC_JSQ2_SHIFT 	(5)
#define ADC_JSQ3_SHIFT 	(10)
#define ADC_JSQ4_SHIFT 	(15)
#define ADC_JL_SHIFT 	(20)

// Values definition for JSQR register
// Values for JL field
#define	ADC_JL_IS_1_CONVERSION		(0<<ADC_JL_SHIFT)
#define	ADC_JL_IS_2_CONVERSIONS		(1<<ADC_JL_SHIFT)
#define	ADC_JL_IS_3_CONVERSIONS		(2<<ADC_JL_SHIFT)
#define	ADC_JL_IS_4_CONVERSIONS		(3<<ADC_JL_SHIFT)

//ADC1->SMPR1 bit description
#define ADC_SMP10_SHIFT	(0)
#define ADC_SMP11_SHIFT	(3)
#define ADC_SMP12_SHIFT	(6)
#define ADC_SMP13_SHIFT	(9)
#define ADC_SMP14_SHIFT	(12)
#define ADC_SMP15_SHIFT	(15)
#define ADC_SMP16_SHIFT	(18)
#define ADC_SMP17_SHIFT	(21)

//ADC1->SMPR2 bit description
#define ADC_SMP0_SHIFT	(0)
#define ADC_SMP1_SHIFT	(3)
#define ADC_SMP2_SHIFT	(6)
#define ADC_SMP3_SHIFT	(9)
#define ADC_SMP4_SHIFT	(12)
#define ADC_SMP5_SHIFT	(15)
#define ADC_SMP6_SHIFT	(18)
#define ADC_SMP7_SHIFT	(21)
#define ADC_SMP8_SHIFT	(24)
#define ADC_SMP9_SHIFT	(27)
#define ADC_SMPx_VAL(smpx,val) 	(val<<smpx)

// Values definition for SMPRx register 
// Values for SMPx field (to be shifted with correct SMPx_SHIFT constant)
#define ADC_SMPx_IS_1_5_CYCLE	(0)
#define ADC_SMPx_IS_7_5_CYCLE	(1)
#define ADC_SMPx_IS_13_5_CYCLE	(2)
#define ADC_SMPx_IS_28_5_CYCLE	(3)
#define ADC_SMPx_IS_41_5_CYCLE	(4)
#define ADC_SMPx_IS_55_5_CYCLE	(5)
#define ADC_SMPx_IS_71_5_CYCLE	(6)
#define ADC_SMPx_IS_239_5_CYCLE	(7)

//ADC1->SR bit description
#define ADC_AWD    (1<<0)
#define ADC_EOC    (1<<1)
#define ADC_JEOC   (1<<2)
#define ADC_JSTRT  (1<<3)
#define ADC_STRT   (1<<4)

/*------------------------ Backup Registers ----------------------------------*/
typedef struct
{
  u32  RESERVED0;
  vu16 DR1;
  u16  RESERVED1;
  vu16 DR2;
  u16  RESERVED2;
  vu16 DR3;
  u16  RESERVED3;
  vu16 DR4;
  u16  RESERVED4;
  vu16 DR5;
  u16  RESERVED5;
  vu16 DR6;
  u16  RESERVED6;
  vu16 DR7;
  u16  RESERVED7;
  vu16 DR8;
  u16  RESERVED8;
  vu16 DR9;
  u16  RESERVED9;
  vu16 DR10;
  u16  RESERVED10; 
  vu16 RTCCR;
  u16  RESERVED11;
  vu16 CR;
  u16  RESERVED12;
  vu16 CSR;
  u16  RESERVED13[5];
  vu16 DR11;
  u16  RESERVED14;
  vu16 DR12;
  u16  RESERVED15;
  vu16 DR13;
  u16  RESERVED16;
  vu16 DR14;
  u16  RESERVED17;
  vu16 DR15;
  u16  RESERVED18;
  vu16 DR16;
  u16  RESERVED19;
  vu16 DR17;
  u16  RESERVED20;
  vu16 DR18;
  u16  RESERVED21;
  vu16 DR19;
  u16  RESERVED22;
  vu16 DR20;
  u16  RESERVED23;
  vu16 DR21;
  u16  RESERVED24;
  vu16 DR22;
  u16  RESERVED25;
  vu16 DR23;
  u16  RESERVED26;
  vu16 DR24;
  u16  RESERVED27;
  vu16 DR25;
  u16  RESERVED28;
  vu16 DR26;
  u16  RESERVED29;
  vu16 DR27;
  u16  RESERVED30;
  vu16 DR28;
  u16  RESERVED31;
  vu16 DR29;
  u16  RESERVED32;
  vu16 DR30;
  u16  RESERVED33; 
  vu16 DR31;
  u16  RESERVED34;
  vu16 DR32;
  u16  RESERVED35;
  vu16 DR33;
  u16  RESERVED36;
  vu16 DR34;
  u16  RESERVED37;
  vu16 DR35;
  u16  RESERVED38;
  vu16 DR36;
  u16  RESERVED39;
  vu16 DR37;
  u16  RESERVED40;
  vu16 DR38;
  u16  RESERVED41;
  vu16 DR39;
  u16  RESERVED42;
  vu16 DR40;
  u16  RESERVED43;
  vu16 DR41;
  u16  RESERVED44;
  vu16 DR42;
  u16  RESERVED45;    
} BKP_TypeDef;

/*------------------------ Controller Area Network ---------------------------*/
typedef struct
{
  vu32 TIR;
  vu32 TDTR;
  vu32 TDLR;
  vu32 TDHR;
} CAN_TxMailBox_TypeDef;

typedef struct
{
  vu32 RIR;
  vu32 RDTR;
  vu32 RDLR;
  vu32 RDHR;
} CAN_FIFOMailBox_TypeDef;

typedef struct
{
  vu32 FR1;
  vu32 FR2;
} CAN_FilterRegister_TypeDef;

typedef struct
{
  vu32 MCR;
  vu32 MSR;
  vu32 TSR;
  vu32 RF0R;
  vu32 RF1R;
  vu32 IER;
  vu32 ESR;
  vu32 BTR;
  u32  RESERVED0[88];
  CAN_TxMailBox_TypeDef sTxMailBox[3];
  CAN_FIFOMailBox_TypeDef sFIFOMailBox[2];
  u32  RESERVED1[12];
  vu32 FMR;
  vu32 FM1R;
  u32  RESERVED2;
  vu32 FS1R;
  u32  RESERVED3;
  vu32 FFA1R;
  u32  RESERVED4;
  vu32 FA1R;
  u32  RESERVED5[8];
  CAN_FilterRegister_TypeDef sFilterRegister[14];
} CAN_TypeDef;

/*------------------------ CRC calculation unit ------------------------------*/
typedef struct
{
  vu32 DR;
  vu8  IDR;
  u8   RESERVED0;
  u16  RESERVED1;
  vu32 CR;
} CRC_TypeDef;


/*------------------------ Digital to Analog Converter -----------------------*/
typedef struct
{
  vu32 CR;
  vu32 SWTRIGR;
  vu32 DHR12R1;
  vu32 DHR12L1;
  vu32 DHR8R1;
  vu32 DHR12R2;
  vu32 DHR12L2;
  vu32 DHR8R2;
  vu32 DHR12RD;
  vu32 DHR12LD;
  vu32 DHR8RD;
  vu32 DOR1;
  vu32 DOR2;
} DAC_TypeDef;

/*------------------------ Debug MCU -----------------------------------------*/
typedef struct
{
  vu32 IDCODE;
  vu32 CR;	
}DBGMCU_TypeDef;

/*------------------------ DMA Controller ------------------------------------*/
typedef struct
{
  vu32 CCR;
  vu32 CNDTR;
  vu32 CPAR;
  vu32 CMAR;
} DMA_Channel_TypeDef;

typedef struct
{
  vu32 ISR;
  vu32 IFCR;
} DMA_TypeDef;

//DMA->ISR bit description
#define DMA_GIF1	(1<<0)
#define DMA_TCIF1	(1<<1)
#define DMA_HTIF1	(1<<2)
#define DMA_TEIF1	(1<<3)
#define DMA_GIF2	(1<<4)
#define DMA_TCIF2	(1<<5)
#define DMA_HTIF2	(1<<6)
#define DMA_TEIF2	(1<<7)
#define DMA_GIF3	(1<<8)
#define DMA_TCIF3	(1<<9)
#define DMA_HTIF3	(1<<10)
#define DMA_TEIF3	(1<<11)
#define DMA_GIF4	(1<<12)
#define DMA_TCIF4	(1<<13)
#define DMA_HTIF4	(1<<14)
#define DMA_TEIF4	(1<<15)
#define DMA_GIF5	(1<<16)
#define DMA_TCIF5	(1<<17)
#define DMA_HTIF5	(1<<18)
#define DMA_TEIF5	(1<<19)
#define DMA_GIF6	(1<<20)
#define DMA_TCIF6	(1<<21)
#define DMA_HTIF6	(1<<22)
#define DMA_TEIF6	(1<<23)
#define DMA_GIF7	(1<<24)
#define DMA_TCIF7	(1<<25)
#define DMA_HTIF7	(1<<26)
#define DMA_TEIF7	(1<<27)

//DMA->IFCR bit description
#define DMA_CGIF1	(1<<0)
#define DMA_CTCIF1	(1<<1)
#define DMA_CHTIF1	(1<<2)
#define DMA_CTEIF1	(1<<3)
#define DMA_CGIF2	(1<<4)
#define DMA_CTCIF2	(1<<5)
#define DMA_CHTIF2	(1<<6)
#define DMA_CTEIF2	(1<<7)
#define DMA_CGIF3	(1<<8)
#define DMA_CTCIF3	(1<<9)
#define DMA_CHTIF3	(1<<10)
#define DMA_CTEIF3	(1<<11)
#define DMA_CGIF4	(1<<12)
#define DMA_CTCIF4	(1<<13)
#define DMA_CHTIF4	(1<<14)
#define DMA_CTEIF4	(1<<15)
#define DMA_CGIF5	(1<<16)
#define DMA_CTCIF5	(1<<17)
#define DMA_CHTIF5	(1<<18)
#define DMA_CTEIF5	(1<<19)
#define DMA_CGIF6	(1<<20)
#define DMA_CTCIF6	(1<<21)
#define DMA_CHTIF6	(1<<22)
#define DMA_CTEIF6	(1<<23)
#define DMA_CGIF7	(1<<24)
#define DMA_CTCIF7	(1<<25)
#define DMA_CHTIF7	(1<<26)
#define DMA_CTEIF7	(1<<27)

//DMA_Channelx->CCR bit description
#define DMA_EN	(1<<0)
#define DMA_TCIE	(1<<1)
#define DMA_HTIE	(1<<2)
#define DMA_TEIE	(1<<3)
#define DMA_DIR	    (1<<4)
#define DMA_DIR_IS_FROM_PERIPHERAL 	(0)
#define DMA_DIR_IS_FROM_MEMORY		DMA_DIR
#define DMA_CIRC	(1<<5)
#define DMA_PINC	(1<<6)
#define DMA_MINC	(1<<7)
#define DMA_PSIZE_SHIFT	(8)
#define DMA_PSIZE_IS_8BITS 		(0 << DMA_PSIZE_SHIFT)
#define DMA_PSIZE_IS_16BITS 	(1 << DMA_PSIZE_SHIFT)
#define DMA_PSIZE_IS_32BITS 	(2 << DMA_PSIZE_SHIFT)
#define DMA_MSIZE_SHIFT			(10)
#define DMA_MSIZE_IS_8BITS 		(0 << DMA_MSIZE_SHIFT)
#define DMA_MSIZE_IS_16BITS 	(1 << DMA_MSIZE_SHIFT)
#define DMA_MSIZE_IS_32BITS 	(2 << DMA_MSIZE_SHIFT)
#define DMA_PL_SHIFT		(12)
#define DMA_PL_IS_LOW   	(0<<DMA_PL_SHIFT)
#define DMA_PL_IS_MEDIUM   	(1<<DMA_PL_SHIFT)
#define DMA_PL_IS_HIGH   	(2<<DMA_PL_SHIFT)
#define DMA_PL_IS_VERYHIGH	(3<<DMA_PL_SHIFT)
#define DMA_MEM2MEM	(1<<14)

/*------------------------ External Interrupt/Event Controller ---------------*/
typedef struct
{
  vu32 IMR;
  vu32 EMR;
  vu32 RTSR;
  vu32 FTSR;
  vu32 SWIER;
  vu32 PR;
} EXTI_TypeDef;

/*------------------------ FLASH and Option Bytes Registers ------------------*/
typedef struct
{
  vu32 ACR;
  vu32 KEYR;
  vu32 OPTKEYR;
  vu32 SR;
  vu32 CR;
  vu32 AR;
  vu32 RESERVED;
  vu32 OBR;
  vu32 WRPR;
} FLASH_TypeDef;

typedef struct
{
  vu16 RDP;
  vu16 USER;
  vu16 Data0;
  vu16 Data1;
  vu16 WRP0;
  vu16 WRP1;
  vu16 WRP2;
  vu16 WRP3;
} OB_TypeDef;

//FLASH->ACR bit description
#define FLASH_HLFCYA	(1<<3)
#define FLASH_PRFTBE	(1<<4)
#define FLASH_PRFTBS	(1<<5)

// Values definition for ACR register 
// Values for LATENCY field 
#define FLASH_LATENCY_0_WS	(0)
#define FLASH_LATENCY_1_WS	(1)
#define FLASH_LATENCY_2_WS	(2)

//FLASH->SR bit description
#define FLASH_BSY		(1<<0)
#define FLASH_PGERR		(1<<2)
#define FLASH_WRPRTERR	(1<<4)
#define FLASH_EOP		(1<<5)

//FLASH->CR bit description
#define FLASH_PG		(1<<0)
#define FLASH_PER		(1<<1)
#define FLASH_MER		(1<<2)
#define FLASH_OPTPG		(1<<4)
#define FLASH_OPTER		(1<<5)
#define FLASH_STRT		(1<<6)
#define FLASH_LOCK		(1<<7)
#define FLASH_OPTWRE	(1<<9)
#define FLASH_ERRIE		(1<<10)
#define FLASH_EOPIE		(1<<12)

//FLASH Keys
#define FLASH_KEY_RDPRT	0x00A5
#define FLASH_KEY_KEY1	0x45670123
#define FLASH_KEY_KEY2	0xCDEF89AB

/*------------------------ Flexible Static Memory Controller -----------------*/
typedef struct
{
  vu32 BTCR[8];   
} FSMC_Bank1_TypeDef; 

typedef struct
{
  vu32 BWTR[7];
} FSMC_Bank1E_TypeDef;

typedef struct
{
  vu32 PCR2;
  vu32 SR2;
  vu32 PMEM2;
  vu32 PATT2;
  u32  RESERVED0;   
  vu32 ECCR2; 
} FSMC_Bank2_TypeDef;  

typedef struct
{
  vu32 PCR3;
  vu32 SR3;
  vu32 PMEM3;
  vu32 PATT3;
  u32  RESERVED0;   
  vu32 ECCR3; 
} FSMC_Bank3_TypeDef; 

typedef struct
{
  vu32 PCR4;
  vu32 SR4;
  vu32 PMEM4;
  vu32 PATT4;
  vu32 PIO4; 
} FSMC_Bank4_TypeDef; 

/*------------------------ General Purpose and Alternate Function IO ---------*/
typedef struct
{
  vu32 CRL;
  vu32 CRH;
  vu32 IDR;
  vu32 ODR;
  vu32 BSRR;
  vu32 BRR;
  vu32 LCKR;
} GPIO_TypeDef;

typedef struct
{
  vu32 EVCR;
  vu32 MAPR;
  vu32 EXTICR[4];
} AFIO_TypeDef;

//GPIOx->CRL and GPIOx->CRH bit description
#define GPIO_MODE_0_SHIFT	(0)
#define GPIO_CNF_0_SHIFT	(2)
#define GPIO_MODE_1_SHIFT	(4)
#define GPIO_CNF_1_SHIFT	(6)
#define GPIO_MODE_2_SHIFT	(8)
#define GPIO_CNF_2_SHIFT	(10)
#define GPIO_MODE_3_SHIFT	(12)
#define GPIO_CNF_3_SHIFT	(14)
#define GPIO_MODE_4_SHIFT	(16)
#define GPIO_CNF_4_SHIFT	(18)
#define GPIO_MODE_5_SHIFT	(20)
#define GPIO_CNF_5_SHIFT	(22)
#define GPIO_MODE_6_SHIFT	(24)
#define GPIO_CNF_6_SHIFT	(26)
#define GPIO_MODE_7_SHIFT	(28)
#define GPIO_CNF_7_SHIFT	(30)

#define GPIO_MODE_8_SHIFT	(0)
#define GPIO_CNF_8_SHIFT	(2)
#define GPIO_MODE_9_SHIFT	(4)
#define GPIO_CNF_9_SHIFT	(6)
#define GPIO_MODE_10_SHIFT	(8)
#define GPIO_CNF_10_SHIFT	(10)
#define GPIO_MODE_11_SHIFT	(12)
#define GPIO_CNF_11_SHIFT	(14)
#define GPIO_MODE_12_SHIFT	(16)
#define GPIO_CNF_12_SHIFT	(18)
#define GPIO_MODE_13_SHIFT	(20)
#define GPIO_CNF_13_SHIFT	(22)
#define GPIO_MODE_14_SHIFT	(24)
#define GPIO_CNF_14_SHIFT	(26)
#define GPIO_MODE_15_SHIFT	(28)
#define GPIO_CNF_15_SHIFT	(30)

// Values definition for CRL and CRH register 
// Values for MODEx field (to be shifted with correct GPIO_MODE_xx_SHIFT constant)
#define GPIO_MODE_INPUT			(0)
#define GPIO_MODE_OUTPUT_10_MHZ	(1)
#define GPIO_MODE_OUTPUT_2_MHZ	(2)
#define GPIO_MODE_OUTPUT_50_MHZ	(3)

// Values for CNFx field (to be shifted with correct GPIO_CNF_xx_SHIFT constant)
#define GPIO_CNF_ANALOG_INPUT	(0)
#define GPIO_CNF_FLOATING_INPUT	(1)
#define GPIO_CNF_DIGITAL_INPUT	(2)

#define GPIO_CNF_OUTPUT_PUSH_PULL		(0)
#define GPIO_CNF_OUTPUT_OPEN_DRAIN		(1)
#define GPIO_CNF_ALTERNATE_PUSH_PULL	(2)
#define GPIO_CNF_ALTERNATE_OPEN_DRAIN	(3)

//GPIOx->IDR, GPIOx->ODR and GPIOx->LCKR bit description
#define GPIO_PIN_0		(1<<0)
#define GPIO_PIN_1		(1<<1)
#define GPIO_PIN_2		(1<<2)
#define GPIO_PIN_3		(1<<3)
#define GPIO_PIN_4		(1<<4)
#define GPIO_PIN_5		(1<<5)
#define GPIO_PIN_6		(1<<6)
#define GPIO_PIN_7		(1<<7)
#define GPIO_PIN_8		(1<<8)
#define GPIO_PIN_9		(1<<9)
#define GPIO_PIN_10		(1<<10)
#define GPIO_PIN_11		(1<<11)
#define GPIO_PIN_12		(1<<12)
#define GPIO_PIN_13		(1<<13)
#define GPIO_PIN_14		(1<<14)
#define GPIO_PIN_15		(1<<15)

//GPIOx->BSRR bit description
//Note: we delibaretly not use BRR registers as they offer same functionalities as BSRR
#define GPIO_SET_PIN_0	(GPIO_PIN_0)
#define GPIO_SET_PIN_1	(GPIO_PIN_1)
#define GPIO_SET_PIN_2	(GPIO_PIN_2)
#define GPIO_SET_PIN_3	(GPIO_PIN_3)
#define GPIO_SET_PIN_4	(GPIO_PIN_4)
#define GPIO_SET_PIN_5	(GPIO_PIN_5)
#define GPIO_SET_PIN_6	(GPIO_PIN_6)
#define GPIO_SET_PIN_7	(GPIO_PIN_7)
#define GPIO_SET_PIN_8	(GPIO_PIN_8)
#define GPIO_SET_PIN_9	(GPIO_PIN_9)
#define GPIO_SET_PIN_10	(GPIO_PIN_10)
#define GPIO_SET_PIN_11	(GPIO_PIN_11)
#define GPIO_SET_PIN_12	(GPIO_PIN_12)
#define GPIO_SET_PIN_13	(GPIO_PIN_13)
#define GPIO_SET_PIN_14	(GPIO_PIN_14)
#define GPIO_SET_PIN_15	(GPIO_PIN_15)

#define GPIO_CLEAR_PIN_0	(GPIO_PIN_0<<16)
#define GPIO_CLEAR_PIN_1	(GPIO_PIN_1<<16)
#define GPIO_CLEAR_PIN_2	(GPIO_PIN_2<<16)
#define GPIO_CLEAR_PIN_3	(GPIO_PIN_3<<16)
#define GPIO_CLEAR_PIN_4	(GPIO_PIN_4<<16)
#define GPIO_CLEAR_PIN_5	(GPIO_PIN_5<<16)
#define GPIO_CLEAR_PIN_6	(GPIO_PIN_6<<16)
#define GPIO_CLEAR_PIN_7	(GPIO_PIN_7<<16)
#define GPIO_CLEAR_PIN_8	(GPIO_PIN_8<<16)
#define GPIO_CLEAR_PIN_9	(GPIO_PIN_9<<16)
#define GPIO_CLEAR_PIN_10	(GPIO_PIN_10<<16)
#define GPIO_CLEAR_PIN_11	(GPIO_PIN_11<<16)
#define GPIO_CLEAR_PIN_12	(GPIO_PIN_12<<16)
#define GPIO_CLEAR_PIN_13	(GPIO_PIN_13<<16)
#define GPIO_CLEAR_PIN_14	(GPIO_PIN_14<<16)
#define GPIO_CLEAR_PIN_15	(GPIO_PIN_15<<16)

//GPIOx->LCKR bit description
#define GPIO_LCKK		(1<<16)

//AFIO->EVCR bits definition
#define AFIO_PIN_SHIFT	(0)
#define AFIO_PORT_SHIFT	(4)
#define AFIO_EVOE		(1<<7)

//Values definition for EVCR register 
//Values for PIN field 
#define AFIO_PIN_0		(0)
#define AFIO_PIN_1		(1)
#define AFIO_PIN_2		(2)
#define AFIO_PIN_3		(3)
#define AFIO_PIN_4		(4)
#define AFIO_PIN_5		(5)
#define AFIO_PIN_6		(6)
#define AFIO_PIN_7		(7)
#define AFIO_PIN_8		(8)
#define AFIO_PIN_9		(9)
#define AFIO_PIN_10		(10)
#define AFIO_PIN_11		(11)
#define AFIO_PIN_12		(12)
#define AFIO_PIN_13		(13)
#define AFIO_PIN_14		(14)
#define AFIO_PIN_15		(15)

//Values for PORT field 
#define AFIO_PORT_A		(0<<AFIO_PORT_SHIFT)
#define AFIO_PORT_B		(1<<AFIO_PORT_SHIFT)
#define AFIO_PORT_C		(2<<AFIO_PORT_SHIFT)
#define AFIO_PORT_D		(3<<AFIO_PORT_SHIFT)
#define AFIO_PORT_E		(4<<AFIO_PORT_SHIFT)

//AFIO->MAPR bits definition
#define AFIO_SPI1_REMAP		(1<<0)
#define AFIO_I2C1_REMAP		(1<<1)
#define AFIO_USART1_REMAP	(1<<2)
#define AFIO_USART2_REMAP	(1<<3)
#define AFIO_USART3_REMAP_SHIFT	(4)
#define AFIO_TIM1_REMAP_SHIFT	(6)
#define AFIO_TIM2_REMAP_SHIFT	(8)
#define AFIO_TIM3_REMAP_SHIFT	(10)
#define AFIO_TIM4_REMAP		(1<<12)
#define AFIO_CAN_REMAP_SHIFT	(13)
#define AFIO_PD01_REMAP		(1<<15)
#define AFIO_TIM5CH4_REMAP		(1<<16)
#define AFIO_ADC1_ETRGINJ_REMAP	(1<<17)
#define AFIO_ADC1_ETRGREG_REMAP	(1<<18)
#define AFIO_ADC2_ETRGINJ_REMAP	(1<<19)
#define AFIO_ADC2_ETRGREG_REMAP	(1<<20)
#define AFIO_SWJ_CFG_SHIFT		(24)

//Values definition for MAPR register 
//Values for CAN field 
#define AFIO_CAN_REMAP_PA11_PA12	(0)
#define AFIO_CAN_REMAP_PB8_PB9		(2)
#define AFIO_CAN_REMAP_PD0_PD1		(3)

//Values for TIM3 field 
#define AFIO_TIM3_NO_REMAP			(0)
#define AFIO_TIM3_PARTIAL_REMAP		(2)
#define AFIO_TIM3_FULL_REMAP		(3)

//Values for TIM2 field 
#define AFIO_TIM2_NO_REMAP			(0)
#define AFIO_TIM2_REMAP_CH1_CH2		(1)
#define AFIO_TIM2_REMAP_CH3_CH4		(2)
#define AFIO_TIM2_FULL_REMAP		(3)

//Values for TIM1 field 
#define AFIO_TIM1_NO_REMAP			(0)
#define AFIO_TIM1_PARTIAL_REMAP		(1)
#define AFIO_TIM1_FULL_REMAP		(3)

//Values for USART3 field 
#define AFIO_USART3_NO_REMAP		(0)
#define AFIO_USART3_PARTIAL_REMAP	(1)
#define AFIO_USART3_FULL_REMAP		(3)

//AFIO->EXTICR1, AFIO->EXTICR2, AFIO->EXTICR3 and AFIO->EXTICR4 bits definition
#define AFIO_EXT0_SHIFT		(0)
#define AFIO_EXT1_SHIFT		(4)
#define AFIO_EXT2_SHIFT		(8)
#define AFIO_EXT3_SHIFT		(12)
#define AFIO_EXT4_SHIFT		(0)
#define AFIO_EXT5_SHIFT		(4)
#define AFIO_EXT6_SHIFT		(8)
#define AFIO_EXT7_SHIFT		(12)
#define AFIO_EXT8_SHIFT		(0)
#define AFIO_EXT9_SHIFT		(4)
#define AFIO_EXT10_SHIFT	(8)
#define AFIO_EXT11_SHIFT	(12)
#define AFIO_EXT12_SHIFT	(0)
#define AFIO_EXT13_SHIFT	(4)
#define AFIO_EXT14_SHIFT	(8)
#define AFIO_EXT15_SHIFT	(12)

//Values definition for EXTICR1, EXTICR2, EXTICR3 and EXTICR4 register 
//Values for EXTx field (to be used with corresponding AFIO_EXTx_SHIFT definition)
#define AFIO_EXT_PORT_PA		(0)
#define AFIO_EXT_PORT_PB		(1)
#define AFIO_EXT_PORT_PC		(2)
#define AFIO_EXT_PORT_PD		(3)
#define AFIO_EXT_PORT_PE		(4)
#define AFIO_EXT_PORT_PF		(5)
#define AFIO_EXT_PORT_PG		(6)

/*------------------------ Inter-integrated Circuit Interface ----------------*/
typedef struct
{
  vu16 CR1;
  u16  RESERVED0;
  vu16 CR2;
  u16  RESERVED1;
  vu16 OAR1;
  u16  RESERVED2;
  vu16 OAR2;
  u16  RESERVED3;
  vu16 DR;
  u16  RESERVED4;
  vu16 SR1;
  u16  RESERVED5;
  vu16 SR2;
  u16  RESERVED6;
  vu16 CCR;
  u16  RESERVED7;
  vu16 TRISE;
  u16  RESERVED8;
} I2C_TypeDef;

/*------------------------ Independent WATCHDOG ------------------------------*/
typedef struct
{
  vu32 KR;
  vu32 PR;
  vu32 RLR;
  vu32 SR;
} IWDG_TypeDef;

/*------------------------ SystemTick ----------------------------------------*/
typedef struct
{
  vu32 CTRL;
  vu32 LOAD;
  vu32 VAL;
  vuc32 CALIB;
} SysTick_TypeDef;

/*------------------------ Nested Vectored Interrupt Controller --------------*/
typedef struct
{
  vu32 ISER[2];
  u32  RESERVED0[30];
  vu32 ICER[2];
  u32  RSERVED1[30];
  vu32 ISPR[2];
  u32  RESERVED2[30];
  vu32 ICPR[2];
  u32  RESERVED3[30];
  vu32 IABR[2];
  u32  RESERVED4[62];
  vu32 IPR[15];
} NVIC_TypeDef;

typedef struct
{
  vuc32 CPUID;
  vu32 ICSR;
  vu32 VTOR;
  vu32 AIRCR;
  vu32 SCR;
  vu32 CCR;
  vu32 SHPR[3];
  vu32 SHCSR;
  vu32 CFSR;
  vu32 HFSR;
  vu32 DFSR;
  vu32 MMFAR;
  vu32 BFAR;
  vu32 AFSR;
} SCB_TypeDef;

// Registers bit definitions and macro for NVIC, SCB and Systick are made in 
// separate file stm_system.h (included at end of this file)

/*------------------------ Power Control -------------------------------------*/
typedef struct
{
  vu32 CR;
  vu32 CSR;
} PWR_TypeDef;

/*------------------------ Reset and Clock Control ---------------------------*/
typedef struct
{
  vu32 CR;
  vu32 CFGR;
  vu32 CIR;
  vu32 APB2RSTR;
  vu32 APB1RSTR;
  vu32 AHBENR;
  vu32 APB2ENR;
  vu32 APB1ENR;
  vu32 BDCR;
  vu32 CSR;
} RCC_TypeDef;

//RCC->CR bits definition
#define RCC_PLLRDY 	(1<<25)
#define RCC_PLLON 	(1<<24)
#define RCC_CSSON 	(1<<19)
#define RCC_HSEBYP 	(1<<18)
#define RCC_HSERDY 	(1<<17)
#define RCC_HSEON 	(1<<16)
#define RCC_HSICAL_SHIFT 	(8)
#define RCC_HSITRIM_SHIFT 	(3)
#define RCC_HSIRDY 	(1<<1)
#define RCC_HSION 	(1<<0)

//RCC->CFGR bits definition
#define RCC_MCO_SHIFT	(24)
#define RCC_MCO_IS_NO_CLOCK		(0<<RCC_MCO_SHIFT)
#define RCC_MCO_IS_SYSCLK		(4<<RCC_MCO_SHIFT)
#define RCC_MCO_IS_HSI			(5<<RCC_MCO_SHIFT)
#define RCC_MCO_IS_HSE			(6<<RCC_MCO_SHIFT)
#define RCC_MCO_IS_PLL			(7<<RCC_MCO_SHIFT)

#define RCC_USBPRE	(1<<22)

#define RCC_PLLMUL_SHIFT	(18)		 // PLL multiplication factor from 2 to 16
#define RCC_PLLMUL_IS_2		(0<<RCC_PLLMUL_SHIFT)
#define RCC_PLLMUL_IS_3		(1<<RCC_PLLMUL_SHIFT)
#define RCC_PLLMUL_IS_4		(2<<RCC_PLLMUL_SHIFT)
#define RCC_PLLMUL_IS_5		(3<<RCC_PLLMUL_SHIFT)
#define RCC_PLLMUL_IS_6		(4<<RCC_PLLMUL_SHIFT)
#define RCC_PLLMUL_IS_7		(5<<RCC_PLLMUL_SHIFT)
#define RCC_PLLMUL_IS_8		(6<<RCC_PLLMUL_SHIFT)
#define RCC_PLLMUL_IS_9		(7<<RCC_PLLMUL_SHIFT)
#define RCC_PLLMUL_IS_10	(8<<RCC_PLLMUL_SHIFT)
#define RCC_PLLMUL_IS_11	(9<<RCC_PLLMUL_SHIFT)
#define RCC_PLLMUL_IS_12	(10<<RCC_PLLMUL_SHIFT)
#define RCC_PLLMUL_IS_13	(11<<RCC_PLLMUL_SHIFT)
#define RCC_PLLMUL_IS_14	(12<<RCC_PLLMUL_SHIFT)
#define RCC_PLLMUL_IS_15	(13<<RCC_PLLMUL_SHIFT)
#define RCC_PLLMUL_IS_16	(14<<RCC_PLLMUL_SHIFT)
#define RCC_PLLMUL_VAL(mult) (((mult-2) & 0xF )<<RCC_PLLMUL_SHIFT)

#define RCC_PLLXTPRE 				(1<<17)
#define RCC_PLLXTPRE_IS_HSE			(0<<17)
#define RCC_PPLXTPRE_IS_HSE_DIV_2	(1<<17)

#define RCC_PLLSRC			(1<<16)	     // PLL entry clock source
#define RCC_PLLSRC_IS_HSI 	(0<<16)
#define RCC_PLLSRC_IS_HSE 	(1<<16)

#define RCC_ADCPRE_SHIFT			(14)
#define RCC_ADCPRE_IS_PCLK2_DIV_2	(0<<RCC_ADCPRE_SHIFT)
#define RCC_ADCPRE_IS_PCLK2_DIV_4	(1<<RCC_ADCPRE_SHIFT)
#define RCC_ADCPRE_IS_PCLK2_DIV_6	(2<<RCC_ADCPRE_SHIFT)
#define RCC_ADCPRE_IS_PCLK2_DIV_8	(3<<RCC_ADCPRE_SHIFT)
#define RCC_ADCPRE_VAL(pres) (((pres/2) & 0x3 )<<RCC_ADCPRE_SHIFT)

#define RCC_PPRE2_SHIFT				(11)		 // APB2 high speed prescaler=> PCLK2
#define RCC_PPRE2_IS_HCLK			(0<<RCC_PPRE2_SHIFT)
#define RCC_PPRE2_IS_HCLK_DIV_2 	(4<<RCC_PPRE2_SHIFT)
#define RCC_PPRE2_IS_HCLK_DIV_4 	(5<<RCC_PPRE2_SHIFT)
#define RCC_PPRE2_IS_HCLK_DIV_8 	(6<<RCC_PPRE2_SHIFT)
#define RCC_PPRE2_IS_HCLK_DIV_16 	(7<<RCC_PPRE2_SHIFT)
#define RCC_PPRE2_VAL(pre) ((pre==1) ? 0 : ((pre/2)-(pre/8)-2*(pre/16)+3)<<RCC_PPRE2_SHIFT)

#define RCC_PPRE1_SHIFT				(8)		 // APB1 low speed prescaler=> PCLK1
#define RCC_PPRE1_IS_HCLK 			(0<<RCC_PPRE1_SHIFT)
#define RCC_PPRE1_IS_HCLK_DIV_2 	(4<<RCC_PPRE1_SHIFT)
#define RCC_PPRE1_IS_HCLK_DIV_4 	(5<<RCC_PPRE1_SHIFT)
#define RCC_PPRE1_IS_HCLK_DIV_8 	(6<<RCC_PPRE1_SHIFT)
#define RCC_PPRE1_IS_HCLK_DIV_16 	(7<<RCC_PPRE1_SHIFT)
#define RCC_PPRE1_VAL(pre) ((pre==1) ? 0 : ((pre/2)-(pre/8)-2*(pre/16)+3)<<RCC_PPRE1_SHIFT)

#define RCC_HPRE_SHIFT				(4)		 //AHB prescaler just before APB1 and APB2 prescaler
#define RCC_HPRE_IS_SYSCLK 			(0<<RCC_HPRE_SHIFT)
#define RCC_HPRE_IS_SYSCLK_DIV_2 	(8<<RCC_HPRE_SHIFT)
#define RCC_HPRE_IS_SYSCLK_DIV_4 	(9<<RCC_HPRE_SHIFT)
#define RCC_HPRE_IS_SYSCLK_DIV_8 	(10<<RCC_HPRE_SHIFT)
#define RCC_HPRE_IS_SYSCLK_DIV_16 	(11<<RCC_HPRE_SHIFT)
#define RCC_HPRE_IS_SYSCLK_DIV_64 	(12<<RCC_HPRE_SHIFT)
#define RCC_HPRE_IS_SYSCLK_DIV_128 	(13<<RCC_HPRE_SHIFT)
#define RCC_HPRE_IS_SYSCLK_DIV_256 	(14<<RCC_HPRE_SHIFT)
#define RCC_HPRE_IS_SYSCLK_DIV_512 	(15<<RCC_HPRE_SHIFT)
#define RCC_HPRE_VAL(pre) ( (7+(pre>256)+(pre>128)+(pre>64)+(pre>16)+(pre>8)+(pre>4)+(pre>2)+(pre>1))<<RCC_HPRE_SHIFT )

#define RCC_SWS_SHIFT		(2)
#define RCC_SWS_IS_HSI		(0<<RCC_SWS_SHIFT)
#define RCC_SWS_IS_HSE		(1<<RCC_SWS_SHIFT)
#define RCC_SWS_IS_PLL		(2<<RCC_SWS_SHIFT)

#define RCC_SW_SHIFT		(0)	//System clock switch
#define RCC_SW_IS_HSI  		(0<<RCC_SW_SHIFT)	    // 8MHz  internal RC 
#define RCC_SW_IS_HSE  		(1<<RCC_SW_SHIFT)		// External crystal
#define RCC_SW_IS_PLL  		(2<<RCC_SW_SHIFT)		// PLL (on HSI or HSE)

//RCC->CIR bits definition
#define RCC_CSSC    	(1<<23) // clock security system interrupt clear
#define RCC_PLLRDYC 	(1<<20) //                                               interrupt clear
#define RCC_HSERDYC 	(1<<19)
#define RCC_HSIRDYC 	(1<<18)
#define RCC_LSERDYC 	(1<<17)         
#define RCC_LSIRDYC 	(1<<16)
#define RCC_PLLRDYIE 	(1<<12)        //interrupt enable
#define RCC_HSERDYIE 	(1<<11)
#define RCC_HSIRDYIE 	(1<<10)
#define RCC_LSERDYIE 	(1<<9)         
#define RCC_LSIRDYIE 	(1<<8)
#define RCC_CSSF    	(1<<7)  //clock security system interrupt flag
#define RCC_PLLRDYF 	(1<<4)  //                                                                flag
#define RCC_HSERDYF 	(1<<3)
#define RCC_HSIRDYF 	(1<<2)
#define RCC_LSERDYF 	(1<<1)          
#define RCC_LSIRDYF 	(1<<0)

//RCC->APB2RSTR bits definition
#define RCC_ADC3RST		(1<<15)
#define RCC_USART1RST	(1<<14)
#define RCC_TIM8RST		(1<<13)
#define RCC_SPI1RST		(1<<12)
#define RCC_TIM1RST		(1<<11)
#define RCC_ADC2RST		(1<<10)
#define RCC_ADC1RST		(1<<9)
#define RCC_IOPGRST		(1<<8)
#define RCC_IOPFRST		(1<<7)
#define RCC_IOPERST		(1<<6)
#define RCC_IOPDRST		(1<<5)
#define RCC_IOPCRST		(1<<4)
#define RCC_IOPBRST		(1<<3)
#define RCC_IOPARST		(1<<2)
#define RCC_AFIORST		(1<<0)

//RCC->APB1RSTR bits definition
#define RCC_DACRST		(1<<29)
#define RCC_PWRRST		(1<<28)
#define RCC_BKPRST		(1<<27)
#define RCC_CANRST		(1<<25)
#define RCC_USBRST		(1<<23)
#define RCC_I2C2RST		(1<<22)
#define RCC_I2C1RST		(1<<21)
#define RCC_UART5RST	(1<<20)
#define RCC_UART4RST	(1<<19)
#define RCC_USART3RST	(1<<18)
#define RCC_USART2RST	(1<<17)
#define RCC_SPI3RST		(1<<15)
#define RCC_SPI2RST		(1<<14)
#define RCC_WWDGRST		(1<<11)
#define RCC_TIM7RST		(1<<5)
#define RCC_TIM6RST		(1<<4)
#define RCC_TIM5RST		(1<<3)
#define RCC_TIM4RST		(1<<2)
#define RCC_TIM3RST		(1<<1)
#define RCC_TIM2RST		(1<<0)

//RCC->AHBENR bits definition
#define RCC_SDIOEN		(1<<10)
#define RCC_FSMCEN		(1<<8)
#define RCC_CRCEN		(1<<6)
#define RCC_FLITFEN		(1<<4)
#define RCC_SRAMEN		(1<<2)
#define RCC_DMA2EN		(1<<2)
#define RCC_DMA1EN		(1<<0)

//RCC->APB2ENR bits definition
#define RCC_ADC3EN		(1<<15)
#define RCC_USART1EN	(1<<14)
#define RCC_TIM8EN		(1<<13)
#define RCC_SPI1EN		(1<<12)
#define RCC_TIM1EN		(1<<11)
#define RCC_ADC2EN		(1<<10)
#define RCC_ADC1EN 		(1<<9)
#define RCC_IOPGEN		(1<<8)
#define RCC_IOPFEN		(1<<7)
#define RCC_IOPEEN		(1<<6)
#define RCC_IOPDEN		(1<<5)
#define RCC_IOPCEN		(1<<4)
#define RCC_IOPBEN		(1<<3)
#define RCC_IOPAEN		(1<<2)
#define RCC_AFIOEN		(1<<0)

//RCC->APB1ENR bits definition
#define RCC_DACEN		(1<<29)
#define RCC_PWREN		(1<<28)
#define RCC_BKPEN		(1<<27)
#define RCC_CANEN		(1<<25)
#define RCC_USBEN		(1<<23)
#define RCC_I2C2EN		(1<<22)
#define RCC_I2C1EN		(1<<21)
#define RCC_UART5EN		(1<<20)
#define RCC_UART4EN		(1<<19)
#define RCC_USART3EN	(1<<18)
#define RCC_USART2EN	(1<<17)
#define RCC_SPI3EN		(1<<15)
#define RCC_SPI2EN		(1<<14)
#define RCC_WWDGEN		(1<<11)
#define RCC_TIM7EN		(1<<5)
#define RCC_TIM6EN		(1<<4)
#define RCC_TIM5EN		(1<<3)
#define RCC_TIM4EN		(1<<2)
#define RCC_TIM3EN		(1<<1)
#define RCC_TIM2EN		(1<<0)

//RCC->BDCR bits definition
#define RCC_BDRST		(1<<16)
#define RCC_RTCEN		(1<<15)
#define RCC_RTCSEL_SHIFT	(8)
#define RCC_RTCSEL_IS_NO_CLOCK	(0<<RCC_RTCSEL_SHIFT)
#define RCC_RTCSEL_IS_LSE		(1<<RCC_RTCSEL_SHIFT)
#define RCC_RTCSEL_IS_LSI		(2<<RCC_RTCSEL_SHIFT)
#define RCC_RTCSEL_IS_HSE		(3<<RCC_RTCSEL_SHIFT)
#define RCC_LSEBYP		(1<<2)
#define RCC_LSERDY		(1<<1)
#define RCC_LSEON		(1<<0)

//RCC->CSR bits definition	
#define RCC_LPWRRST		(1<<31)
#define RCC_WWDGRSTF	(1<<30)
#define RCC_IWDGRSTF	(1<<29)
#define RCC_SFTRSTF		(1<<28)
#define RCC_PORRSTF		(1<<27)
#define RCC_PINRSTF		(1<<26)
#define RCC_RMVF		(1<<24)
#define RCC_LSIRDY		(1<<1)
#define RCC_LSION		(1<<0)
/*------------------------ Real-Time Clock -----------------------------------*/
typedef struct
{
  vu16 CRH;
  u16  RESERVED0;
  vu16 CRL;
  u16  RESERVED1;
  vu16 PRLH;
  u16  RESERVED2;
  vu16 PRLL;
  u16  RESERVED3;
  vu16 DIVH;
  u16  RESERVED4;
  vu16 DIVL;
  u16  RESERVED5;
  vu16 CNTH;
  u16  RESERVED6;
  vu16 CNTL;
  u16  RESERVED7;
  vu16 ALRH;
  u16  RESERVED8;
  vu16 ALRL;
  u16  RESERVED9;
} RTC_TypeDef;

/*------------------------ SD host Interface ---------------------------------*/
typedef struct
{
  vu32 POWER;
  vu32 CLKCR;
  vu32 ARG;
  vu32 CMD;
  vuc32 RESPCMD;
  vuc32 RESP1;
  vuc32 RESP2;
  vuc32 RESP3;
  vuc32 RESP4;
  vu32 DTIMER;
  vu32 DLEN;
  vu32 DCTRL;
  vuc32 DCOUNT;
  vuc32 STA;
  vu32 ICR;
  vu32 MASK;
  u32  RESERVED0[2];
  vuc32 FIFOCNT;
  u32  RESERVED1[13];
  vu32 FIFO;
} SDIO_TypeDef;

/*------------------------ Serial Peripheral Interface -----------------------*/
typedef struct
{
  vu16 CR1;
  u16  RESERVED0;
  vu16 CR2;
  u16  RESERVED1;
  vu16 SR;
  u16  RESERVED2;
  vu16 DR;
  u16  RESERVED3;
  vu16 CRCPR;
  u16  RESERVED4;
  vu16 RXCRCR;
  u16  RESERVED5;
  vu16 TXCRCR;
  u16  RESERVED6;
  vu16 I2SCFGR;
  u16  RESERVED7;
  vu16 I2SPR;
  u16  RESERVED8;  
} SPI_TypeDef;

/*------------------------ TIM -----------------------------------------------*/
typedef struct
{
  vu16 CR1;
  u16  RESERVED0;
  vu16 CR2;
  u16  RESERVED1;
  vu16 SMCR;
  u16  RESERVED2;
  vu16 DIER;
  u16  RESERVED3;
  vu16 SR;
  u16  RESERVED4;
  vu16 EGR;
  u16  RESERVED5;
  vu16 CCMR1;
  u16  RESERVED6;
  vu16 CCMR2;
  u16  RESERVED7;
  vu16 CCER;
  u16  RESERVED8;
  vu16 CNT;
  u16  RESERVED9;
  vu16 PSC;
  u16  RESERVED10;
  vu16 ARR;
  u16  RESERVED11;
  vu16 RCR;
  u16  RESERVED12;
  vu16 CCR1;
  u16  RESERVED13;
  vu16 CCR2;
  u16  RESERVED14;
  vu16 CCR3;
  u16  RESERVED15;
  vu16 CCR4;
  u16  RESERVED16;
  vu16 BDTR;
  u16  RESERVED17;
  vu16 DCR;
  u16  RESERVED18;
  vu16 DMAR;
  u16  RESERVED19;
} TIM_TypeDef;

// TIM->CR1 bits definition
#define TIM_CKD_SHIFT	(8)
#define TIM_CKD_IS_TCK		(0<<TIM_CKD_SHIFT)
#define TIM_CKD_IS_2_TCK	(1<<TIM_CKD_SHIFT)
#define TIM_CKD_IS_4_TCK	(2<<TIM_CKD_SHIFT)
#define TIM_ARPE		(1<<7)
#define TIM_CMS_SHIFT	(6)
#define TIM_CMS_IS_EDGE_ALIGNED		(0<<TIM_CMS_SHIFT)
#define TIM_CMS_IS_CENTER_ALIGNED_1	(1<<TIM_CMS_SHIFT)
#define TIM_CMS_IS_CENTER_ALIGNED_2	(2<<TIM_CMS_SHIFT)
#define TIM_CMS_IS_CENTER_ALIGNED_3	(3<<TIM_CMS_SHIFT)
#define TIM_DIR			(1<<4)
#define TIM_OPM			(1<<3)
#define TIM_URS			(1<<2)
#define TIM_UDIS		(1<<1)
#define TIM_CEN			(1<<0)

// TIM->CR2 bits definition
#define TIM_OIS4		(1<<14)
#define TIM_OIS3N		(1<<13)
#define TIM_OIS3		(1<<12)
#define TIM_OIS2N		(1<<11)
#define TIM_OIS2		(1<<10)
#define TIM_OIS1N		(1<<9)
#define TIM_OIS1		(1<<8)
#define TIM_TI1S		(1<<7)
#define TIM_MMS_SHIFT	(4)
#define TIM_MMS_IS_RESET			(0<<TIM_MMS_SHIFT)
#define TIM_MMS_IS_ENABLE			(1<<TIM_MMS_SHIFT)
#define TIM_MMS_IS_UPDATE			(2<<TIM_MMS_SHIFT)
#define TIM_MMS_IS_COMPARE_PULSE	(3<<TIM_MMS_SHIFT)
#define TIM_MMS_IS_COMPARE_OC1REF	(4<<TIM_MMS_SHIFT)
#define TIM_MMS_IS_COMPARE_OC2REF	(5<<TIM_MMS_SHIFT)
#define TIM_MMS_IS_COMPARE_OC3REF	(6<<TIM_MMS_SHIFT)
#define TIM_MMS_IS_COMPARE_OC4REF	(7<<TIM_MMS_SHIFT)
#define TIM_CCDS		(1<<3)
#define TIM_CCUS		(1<<2)
#define TIM_CCPC		(1<<0)

// TIM->SMCR bits definition
#define TIM_ETP			(1<<15)
#define TIM_ECE			(1<<14)
#define TIM_ETPS_SHIFT	(12)
#define TIM_ETPS_IS_OFF			(0<<TIM_ETPS_SHIFT)
#define TIM_ETPS_IS_ETRP_DIV_2	(1<<TIM_ETPS_SHIFT)
#define TIM_ETPS_IS_ETRP_DIV_4	(2<<TIM_ETPS_SHIFT)
#define TIM_ETPS_IS_ETRP_DIV_8	(3<<TIM_ETPS_SHIFT)
#define TIM_ETF_SHIFT	(8)
#define TIM_ETF_IS_NO_FILTER			(0<<TIM_ETF_SHIFT)
#define TIM_ETF_IS_FDTS_N_2				(1<<TIM_ETF_SHIFT)
#define TIM_ETF_IS_FDTS_N_4				(2<<TIM_ETF_SHIFT)
#define TIM_ETF_IS_FDTS_N_8				(3<<TIM_ETF_SHIFT)
#define TIM_ETF_IS_FDTS_DIV_2_N_6		(4<<TIM_ETF_SHIFT)
#define TIM_ETF_IS_FDTS_DIV_2_N_8		(5<<TIM_ETF_SHIFT)
#define TIM_ETF_IS_FDTS_DIV_4_N_6		(6<<TIM_ETF_SHIFT)
#define TIM_ETF_IS_FDTS_DIV_4_N_8		(7<<TIM_ETF_SHIFT)
#define TIM_ETF_IS_FDTS_DIV_8_N_6		(8<<TIM_ETF_SHIFT)
#define TIM_ETF_IS_FDTS_DIV_8_N_8		(9<<TIM_ETF_SHIFT)
#define TIM_ETF_IS_FDTS_DIV_16_N_5		(10<<TIM_ETF_SHIFT)
#define TIM_ETF_IS_FDTS_DIV_16_N_6		(11<<TIM_ETF_SHIFT)
#define TIM_ETF_IS_FDTS_DIV_16_N_8		(12<<TIM_ETF_SHIFT)
#define TIM_ETF_IS_FDTS_DIV_32_N_5		(13<<TIM_ETF_SHIFT)
#define TIM_ETF_IS_FDTS_DIV_32_N_6		(14<<TIM_ETF_SHIFT)
#define TIM_ETF_IS_FDTS_DIV_32_N_8		(15<<TIM_ETF_SHIFT)
#define TIM_MSM			(1<<7)
#define TIM_TS_SHIFT	(4)
#define TIM_TS_IS_ITR0		(0<<TIM_TS_SHIFT)
#define TIM_TS_IS_ITR1		(1<<TIM_TS_SHIFT)
#define TIM_TS_IS_ITR2		(2<<TIM_TS_SHIFT)
#define TIM_TS_IS_ITR3		(3<<TIM_TS_SHIFT)
#define TIM_TS_IS_TI1F_ED	(4<<TIM_TS_SHIFT)
#define TIM_TS_IS_TI1FP1	(5<<TIM_TS_SHIFT)
#define TIM_TS_IS_TI2FP2	(6<<TIM_TS_SHIFT)
#define TIM_TS_IS_ETRF		(7<<TIM_TS_SHIFT)
#define TIM_SMS_SHIFT	(0)
#define TIM_SMS_IS_DISABLED		(0<<TIM_SMS_SHIFT)
#define TIM_SMS_IS_ENCODER_1	(1<<TIM_SMS_SHIFT)
#define TIM_SMS_IS_ENCODER_2	(2<<TIM_SMS_SHIFT)
#define TIM_SMS_IS_ENCODER_3	(3<<TIM_SMS_SHIFT)
#define TIM_SMS_IS_RESET		(4<<TIM_SMS_SHIFT)
#define TIM_SMS_IS_GATED		(5<<TIM_SMS_SHIFT)
#define TIM_SMS_IS_TRIGGER		(6<<TIM_SMS_SHIFT)
#define TIM_SMS_IS_EXTERNAL		(7<<TIM_SMS_SHIFT)

// TIM->DIER bits definition
#define TIM_TDE			(1<<14)
#define TIM_COMDE		(1<<13)
#define TIM_CC4DE		(1<<12)
#define TIM_CC3DE		(1<<11)
#define TIM_CC2DE		(1<<10)
#define TIM_CC1DE		(1<<9)
#define TIM_UDE			(1<<8)
#define TIM_BIE			(1<<7)
#define TIM_TIE			(1<<6)
#define TIM_COMIE		(1<<5)
#define TIM_CC4IE		(1<<4)
#define TIM_CC3IE		(1<<3)
#define TIM_CC2IE		(1<<2)
#define TIM_CC1IE		(1<<1)
#define TIM_UIE			(1<<0)

// TIM->SR bits definition
#define TIM_CC4OF		(1<<12)
#define TIM_CC3OF		(1<<11)
#define TIM_CC2OF		(1<<10)
#define TIM_CC1OF		(1<<9)
#define TIM_BIF			(1<<7)
#define TIM_TIF			(1<<6)
#define TIM_COMIF		(1<<5)
#define TIM_CC4IF		(1<<4)
#define TIM_CC3IF		(1<<3)
#define TIM_CC2IF		(1<<2)
#define TIM_CC1IF		(1<<1)
#define TIM_UIF			(1<<0)

// TIM->EGR bits definition
#define TIM_BG			(1<<7)
#define TIM_TG			(1<<6)
#define TIM_COMG		(1<<5)
#define TIM_CC4G		(1<<4)
#define TIM_CC3G		(1<<3)
#define TIM_CC2G		(1<<2)
#define TIM_CC1G		(1<<1)
#define TIM_UG			(1<<0)

// TIM->CCMR1 and TIM->CCMR2 common definition
// Field OCxM values
#define TIM_OCxM_FROZEN						(0)
#define TIM_OCxM_ACTIVE_LEVEL_ON_MATCH		(1)
#define TIM_OCxM_INACTIVE_LEVEL_ON_MATCH	(2)
#define TIM_OCxM_TOGGLE						(3)
#define TIM_OCxM_FORCE_INACTIVE_LEVEL		(4)
#define TIM_OCxM_FORCE_ACTIVE_LEVEL			(5)
#define TIM_OCxM_PWM_1						(6)
#define TIM_OCxM_PWM_2						(7)

// Field ICxF values
#define TIM_ICxF_NO_FILTER			(0)
#define TIM_ICxF_FDTS_N_2			(1)
#define TIM_ICxF_FDTS_N_4			(2)
#define TIM_ICxF_FDTS_N_8			(3)
#define TIM_ICxF_FDTS_DIV_2_N_6		(4)
#define TIM_ICxF_FDTS_DIV_2_N_8		(5)
#define TIM_ICxF_FDTS_DIV_4_N_6		(6)
#define TIM_ICxF_FDTS_DIV_4_N_8		(7)
#define TIM_ICxF_FDTS_DIV_8_N_6		(8)
#define TIM_ICxF_FDTS_DIV_8_N_8		(9)
#define TIM_ICxF_FDTS_DIV_16_N_5	(10)
#define TIM_ICxF_FDTS_DIV_16_N_6	(11)
#define TIM_ICxF_FDTS_DIV_16_N_8	(12)
#define TIM_ICxF_FDTS_DIV_32_N_5	(13)
#define TIM_ICxF_FDTS_DIV_32_N_6	(14)
#define TIM_ICxF_FDTS_DIV_32_N_8	(15)

// Field ICxPSC values
#define TIM_ICxPSC_NO_PRESCALER		(0)
#define TIM_ICxPSC_CAPTURE_DIV_2	(1)
#define TIM_ICxPSC_CAPTURE_DIV_4	(2)
#define TIM_ICxPSC_CAPTURE_DIV_8	(3)

// TIM->CCMR1 bits definition
// Output Compare mode
#define TIM_OC2CE		(1<<15)
#define TIM_OC2M_SHIFT	(12)
#define TIM_OC2M_VAL(val)		(val<<TIM_OC2M_SHIFT) // use values defined for field OCxM
#define TIM_OC2PE		(1<<11)
#define TIM_OC2FE		(1<<10)
#define TIM_CC2S_SHIFT	(8)
#define TIM_CC2S_IS_OUTPUT		(0<<TIM_CC2S_SHIFT)
#define TIM_CC2S_IS_INPUT_TI2	(1<<TIM_CC2S_SHIFT)
#define TIM_CC2S_IS_INPUT_TI1	(2<<TIM_CC2S_SHIFT)
#define TIM_CC2S_IS_INPUT_TRC	(3<<TIM_CC2S_SHIFT)
#define TIM_OC1CE		(1<<7)
#define TIM_OC1M_SHIFT	(4)
#define TIM_OC1M_VAL(val)		(val<<TIM_OC1M_SHIFT) // use values defined for field OCxM
#define TIM_OC1PE		(1<<3)
#define TIM_OC1FE		(1<<2)
#define TIM_CC1S_SHIFT	(0)
#define TIM_CC1S_IS_OUTPUT		(0<<TIM_CC1S_SHIFT)
#define TIM_CC1S_IS_INPUT_TI1	(1<<TIM_CC1S_SHIFT)
#define TIM_CC1S_IS_INPUT_TI2	(2<<TIM_CC1S_SHIFT)
#define TIM_CC1S_IS_INPUT_TRC	(3<<TIM_CC1S_SHIFT)

// Input Capture mode
#define TIM_IC2F_SHIFT		(12)
#define TIM_IC2F_VAL(val)	(val<<TIM_IC2F_SHIFT) 	// use values defined for field ICxF
#define TIM_IC2PSC_SHIFT	(10)
#define TIM_IC2PSC_VAL(val)	(val<<TIM_IC2PSC_SHIFT)	// use values defined for field ICxPSC
#define TIM_IC1F_SHIFT		(12)
#define TIM_IC1F_VAL(val)	(val<<TIM_IC1F_SHIFT)	// use values defined for field ICxF
#define TIM_IC1PSC_SHIFT	(10)
#define TIM_IC1PSC_VAL(val)	(val<<TIM_IC1PSC_SHIFT) // use values defined for field ICxPSC

// TIM->CCMR2 bits definition
// Output Compare mode
#define TIM_OC4CE		(1<<15)
#define TIM_OC4M_SHIFT	(12)
#define TIM_OC4M_VAL(val)		(val<<TIM_OC4M_SHIFT) // use values defined for field OCxM
#define TIM_OC4PE		(1<<11)
#define TIM_OC4FE		(1<<10)
#define TIM_CC4S_SHIFT	(8)
#define TIM_CC4S_IS_OUTPUT		(0<<TIM_CC4S_SHIFT)
#define TIM_CC4S_IS_INPUT_TI2	(1<<TIM_CC4S_SHIFT)
#define TIM_CC4S_IS_INPUT_TI1	(2<<TIM_CC4S_SHIFT)
#define TIM_CC4S_IS_INPUT_TRC	(3<<TIM_CC4S_SHIFT)
#define TIM_OC3CE		(1<<7)
#define TIM_OC3M_SHIFT	(4)
#define TIM_OC3M_VAL(val)		(val<<TIM_OC3M_SHIFT) // use values defined for field OCxM
#define TIM_OC3PE		(1<<3)
#define TIM_OC3FE		(1<<2)
#define TIM_CC3S_SHIFT	(0)
#define TIM_CC3S_IS_OUTPUT		(0<<TIM_CC3S_SHIFT)
#define TIM_CC3S_IS_INPUT_TI1	(1<<TIM_CC3S_SHIFT)
#define TIM_CC3S_IS_INPUT_TI2	(2<<TIM_CC3S_SHIFT)
#define TIM_CC3S_IS_INPUT_TRC	(3<<TIM_CC3S_SHIFT)

// Input Capture mode
#define TIM_IC4F_SHIFT		(12)
#define TIM_IC4F_VAL(val)	(val<<TIM_IC4F_SHIFT) 	// use values defined for field ICxF
#define TIM_IC4PSC_SHIFT	(10)
#define TIM_IC4PSC_VAL(val)	(val<<TIM_IC4PSC_SHIFT)	// use values defined for field ICxPSC
#define TIM_IC3F_SHIFT		(12)
#define TIM_IC3F_VAL(val)	(val<<TIM_IC3F_SHIFT)	// use values defined for field ICxF
#define TIM_IC3PSC_SHIFT	(10)
#define TIM_IC3PSC_VAL(val)	(val<<TIM_IC3PSC_SHIFT) // use values defined for field ICxPSC

// TIM->CCER bits definition
//A faire

// TIM->BDTR bits definition
#define TIM_MOE			(1<<15)
#define TIM_AOE			(1<<14)
#define TIM_BKP			(1<<13)
#define TIM_BKE			(1<<12)
#define TIM_OSSR		(1<<11)
#define TIM_OSSI		(1<<10)
#define TIM_LOCK_SHIFT	(8)
#define TIM_LOCK_IS_OFF		(0<<TIM_LOCK_SHIFT)
#define TIM_LOCK_IS_LOCK_1	(1<<TIM_LOCK_SHIFT)
#define TIM_LOCK_IS_LOCK_2	(2<<TIM_LOCK_SHIFT)
#define TIM_LOCK_IS_LOCK_3	(3<<TIM_LOCK_SHIFT)
#define TIM_DTG_SHIFT	(0)

// TIM->DCR bits definition
#define TIM_DBL_SHIFT		(8)
#define TIM_DBL_IS_1		(0<<TIM_DBL_SHIFT)
#define TIM_DBL_IS_2		(1<<TIM_DBL_SHIFT)
#define TIM_DBL_IS_3		(2<<TIM_DBL_SHIFT)
#define TIM_DBL_IS_4		(3<<TIM_DBL_SHIFT)
#define TIM_DBL_IS_5		(4<<TIM_DBL_SHIFT)
#define TIM_DBL_IS_6		(5<<TIM_DBL_SHIFT)
#define TIM_DBL_IS_7		(6<<TIM_DBL_SHIFT)
#define TIM_DBL_IS_8		(7<<TIM_DBL_SHIFT)
#define TIM_DBL_IS_9		(8<<TIM_DBL_SHIFT)
#define TIM_DBL_IS_10		(9<<TIM_DBL_SHIFT)
#define TIM_DBL_IS_11		(10<<TIM_DBL_SHIFT)
#define TIM_DBL_IS_12		(11<<TIM_DBL_SHIFT)
#define TIM_DBL_IS_13		(12<<TIM_DBL_SHIFT)
#define TIM_DBL_IS_14		(13<<TIM_DBL_SHIFT)
#define TIM_DBL_IS_15		(14<<TIM_DBL_SHIFT)
#define TIM_DBL_IS_16		(15<<TIM_DBL_SHIFT)
#define TIM_DBL_IS_17		(16<<TIM_DBL_SHIFT)
#define TIM_DBL_IS_18		(17<<TIM_DBL_SHIFT)

/*----------------- Universal Synchronous Asynchronous Receiver Transmitter --*/
typedef struct
{
  vu16 SR;
  u16  RESERVED0;
  vu16 DR;
  u16  RESERVED1;
  vu16 BRR;
  u16  RESERVED2;
  vu16 CR1;
  u16  RESERVED3;
  vu16 CR2;
  u16  RESERVED4;
  vu16 CR3;
  u16  RESERVED5;
  vu16 GTPR;
  u16  RESERVED6;
} USART_TypeDef;

//USART->SR bits definition	
#define USART_CTS	(1<<9)
#define USART_LBD	(1<<8)
#define USART_TXE	(1<<7)
#define USART_TC	(1<<6)
#define USART_RXNE	(1<<5)
#define USART_IDLE	(1<<4)
#define USART_ORE	(1<<3)
#define USART_NE	(1<<2)
#define USART_FE	(1<<1)
#define USART_PE	(1<<0)

//USART->BRR bits definition	
#define USART_DIV_MANTISSA_SHIFT	4
#define USART_DIV_FRACTION_SHIFT	0

//USART->CR1 bits definition	
#define USART_UE	(1<<13)
#define USART_M		(1<<12)
#define USART_WAKE	(1<<11)
#define USART_PCE	(1<<10)
#define USART_PS	(1<<9)
#define USART_PEIE	(1<<8)
#define USART_TXEIE	(1<<7)
#define USART_TCIE	(1<<6)
#define USART_RXNEIE 	(1<<5)
#define USART_IDLEIE	(1<<4)
#define USART_TE	(1<<3)
#define USART_RE	(1<<2)
#define USART_RWU	(1<<1)
#define USART_SBK	(1<<0)

//USART->CR2 bits definition	
#define USART_LINEN			(1<<14)
#define USART_STOP_SHIFT	(12)
#define USART_STOP_IS_1_BIT		(0<<USART_STOP_SHIFT)
#define USART_STOP_IS_0_5_BIT	(1<<USART_STOP_SHIFT)
#define USART_STOP_IS_2_BITS	(2<<USART_STOP_SHIFT)
#define USART_STOP_IS_1_5_BIT	(3<<USART_STOP_SHIFT)
#define USART_CLKEN			(1<<11)
#define USART_CPOL			(1<<10)
#define USART_CPHA			(1<<9)
#define USART_LBCL			(1<<8)
#define USART_LBDIE			(1<<6)
#define USART_LBDL			(1<<5)
#define USART_ADD_SHIFT		(0)

//USART->CR3 bits definition	
#define USART_CTSIE			(1<<10)
#define USART_CTSE			(1<<9)
#define USART_RTSE			(1<<8)
#define USART_DMAT			(1<<7)
#define USART_DMAR			(1<<6)
#define USART_SCEN			(1<<5)
#define USART_NACK			(1<<4)
#define USART_HDSEL			(1<<3)
#define USART_IRLP			(1<<2)
#define USART_IREN			(1<<1)
#define USART_EIE			(1<<0)

//USART->GTPR bits definition	
#define USART_GT_SHIFT		(8)
#define USART_PSC_SHIFT		(0)

/*------------------------ Window WATCHDOG -----------------------------------*/
typedef struct
{
  vu32 CR;
  vu32 CFR;
  vu32 SR;
} WWDG_TypeDef;

/******************************************************************************/
/*                         Peripheral memory map                              */
/******************************************************************************/
/* Peripheral and SRAM base address in the alias region */
#define PERIPH_BB_BASE        ((u32)0x42000000)
#define SRAM_BB_BASE          ((u32)0x22000000)

/* Peripheral and SRAM base address in the bit-band region */
#define SRAM_BASE             ((u32)0x20000000)
#define PERIPH_BASE           ((u32)0x40000000)

/* FSMC registers base address */
#define FSMC_R_BASE           ((u32)0xA0000000)

/* Peripheral memory map */
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)

#define TIM2_BASE             (APB1PERIPH_BASE + 0x0000)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x0400)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x0800)
#define TIM5_BASE             (APB1PERIPH_BASE + 0x0C00)
#define TIM6_BASE             (APB1PERIPH_BASE + 0x1000)
#define TIM7_BASE             (APB1PERIPH_BASE + 0x1400)
#define RTC_BASE              (APB1PERIPH_BASE + 0x2800)
#define WWDG_BASE             (APB1PERIPH_BASE + 0x2C00)
#define IWDG_BASE             (APB1PERIPH_BASE + 0x3000)
#define SPI2_BASE             (APB1PERIPH_BASE + 0x3800)
#define SPI3_BASE             (APB1PERIPH_BASE + 0x3C00)
#define USART2_BASE           (APB1PERIPH_BASE + 0x4400)
#define USART3_BASE           (APB1PERIPH_BASE + 0x4800)
#define UART4_BASE            (APB1PERIPH_BASE + 0x4C00)
#define UART5_BASE            (APB1PERIPH_BASE + 0x5000)
#define I2C1_BASE             (APB1PERIPH_BASE + 0x5400)
#define I2C2_BASE             (APB1PERIPH_BASE + 0x5800)
#define CAN_BASE              (APB1PERIPH_BASE + 0x6400)
#define BKP_BASE              (APB1PERIPH_BASE + 0x6C00)
#define PWR_BASE              (APB1PERIPH_BASE + 0x7000)
#define DAC_BASE              (APB1PERIPH_BASE + 0x7400)

#define AFIO_BASE             (APB2PERIPH_BASE + 0x0000)
#define EXTI_BASE             (APB2PERIPH_BASE + 0x0400)
#define GPIOA_BASE            (APB2PERIPH_BASE + 0x0800)
#define GPIOB_BASE            (APB2PERIPH_BASE + 0x0C00)
#define GPIOC_BASE            (APB2PERIPH_BASE + 0x1000)
#define GPIOD_BASE            (APB2PERIPH_BASE + 0x1400)
#define GPIOE_BASE            (APB2PERIPH_BASE + 0x1800)
#define GPIOF_BASE            (APB2PERIPH_BASE + 0x1C00)
#define GPIOG_BASE            (APB2PERIPH_BASE + 0x2000)
#define ADC1_BASE             (APB2PERIPH_BASE + 0x2400)
#define ADC2_BASE             (APB2PERIPH_BASE + 0x2800)
#define TIM1_BASE             (APB2PERIPH_BASE + 0x2C00)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x3000)
#define TIM8_BASE             (APB2PERIPH_BASE + 0x3400)
#define USART1_BASE           (APB2PERIPH_BASE + 0x3800)
#define ADC3_BASE             (APB2PERIPH_BASE + 0x3C00)

#define SDIO_BASE             (PERIPH_BASE + 0x18000)

#define DMA1_BASE             (AHBPERIPH_BASE + 0x0000)
#define DMA1_Channel1_BASE    (AHBPERIPH_BASE + 0x0008)
#define DMA1_Channel2_BASE    (AHBPERIPH_BASE + 0x001C)
#define DMA1_Channel3_BASE    (AHBPERIPH_BASE + 0x0030)
#define DMA1_Channel4_BASE    (AHBPERIPH_BASE + 0x0044)
#define DMA1_Channel5_BASE    (AHBPERIPH_BASE + 0x0058)
#define DMA1_Channel6_BASE    (AHBPERIPH_BASE + 0x006C)
#define DMA1_Channel7_BASE    (AHBPERIPH_BASE + 0x0080)
#define DMA2_BASE             (AHBPERIPH_BASE + 0x0400)
#define DMA2_Channel1_BASE    (AHBPERIPH_BASE + 0x0408)
#define DMA2_Channel2_BASE    (AHBPERIPH_BASE + 0x041C)
#define DMA2_Channel3_BASE    (AHBPERIPH_BASE + 0x0430)
#define DMA2_Channel4_BASE    (AHBPERIPH_BASE + 0x0444)
#define DMA2_Channel5_BASE    (AHBPERIPH_BASE + 0x0458)
#define RCC_BASE              (AHBPERIPH_BASE + 0x1000)
#define CRC_BASE              (AHBPERIPH_BASE + 0x3000)

/* Flash registers base address */
#define FLASH_R_BASE          (AHBPERIPH_BASE + 0x2000)
/* Flash Option Bytes base address */
#define OB_BASE               ((u32)0x1FFFF800)

/* FSMC Bankx registers base address */
#define FSMC_Bank1_R_BASE     (FSMC_R_BASE + 0x0000)
#define FSMC_Bank1E_R_BASE    (FSMC_R_BASE + 0x0104)
#define FSMC_Bank2_R_BASE     (FSMC_R_BASE + 0x0060)
#define FSMC_Bank3_R_BASE     (FSMC_R_BASE + 0x0080)
#define FSMC_Bank4_R_BASE     (FSMC_R_BASE + 0x00A0)

/* Debug MCU registers base address */
#define DBGMCU_BASE          ((u32)0xE0042000)

/* System Control Space memory map */
#define SCS_BASE              ((u32)0xE000E000)

#define SysTick_BASE          (SCS_BASE + 0x0010)
#define NVIC_BASE             (SCS_BASE + 0x0100)
#define SCB_BASE              (SCS_BASE + 0x0D00)

/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/

/*------------------------ Non Debug Mode ------------------------------------*/
#ifndef DEBUG
#ifdef _TIM2
  #define TIM2                ((TIM_TypeDef *) TIM2_BASE)
#endif /*_TIM2 */

#ifdef _TIM3
  #define TIM3                ((TIM_TypeDef *) TIM3_BASE)
#endif /*_TIM3 */

#ifdef _TIM4
  #define TIM4                ((TIM_TypeDef *) TIM4_BASE)
#endif /*_TIM4 */

#ifdef _TIM5
  #define TIM5                ((TIM_TypeDef *) TIM5_BASE)
#endif /*_TIM5 */

#ifdef _TIM6
  #define TIM6                ((TIM_TypeDef *) TIM6_BASE)
#endif /*_TIM6 */

#ifdef _TIM7
  #define TIM7                ((TIM_TypeDef *) TIM7_BASE)
#endif /*_TIM7 */

#ifdef _RTC
  #define RTC                 ((RTC_TypeDef *) RTC_BASE)
#endif /*_RTC */

#ifdef _WWDG
  #define WWDG                ((WWDG_TypeDef *) WWDG_BASE)
#endif /*_WWDG */

#ifdef _IWDG
  #define IWDG                ((IWDG_TypeDef *) IWDG_BASE)
#endif /*_IWDG */

#ifdef _SPI2
  #define SPI2                ((SPI_TypeDef *) SPI2_BASE)
#endif /*_SPI2 */

#ifdef _SPI3
  #define SPI3                ((SPI_TypeDef *) SPI3_BASE)
#endif /*_SPI3 */

#ifdef _USART2
  #define USART2              ((USART_TypeDef *) USART2_BASE)
#endif /*_USART2 */

#ifdef _USART3
  #define USART3              ((USART_TypeDef *) USART3_BASE)
#endif /*_USART3 */

#ifdef _UART4
  #define UART4              ((USART_TypeDef *) UART4_BASE)
#endif /*_UART4 */

#ifdef _UART5
  #define UART5              ((USART_TypeDef *) UART5_BASE)
#endif /*_USART5 */

#ifdef _I2C1
  #define I2C1                ((I2C_TypeDef *) I2C1_BASE)
#endif /*_I2C1 */

#ifdef _I2C2
  #define I2C2                ((I2C_TypeDef *) I2C2_BASE)
#endif /*_I2C2 */

#ifdef _CAN
  #define CAN                 ((CAN_TypeDef *) CAN_BASE)
#endif /*_CAN */

#ifdef _BKP
  #define BKP                 ((BKP_TypeDef *) BKP_BASE)
#endif /*_BKP */

#ifdef _PWR
  #define PWR                 ((PWR_TypeDef *) PWR_BASE)
#endif /*_PWR */

#ifdef _DAC
  #define DAC                 ((DAC_TypeDef *) DAC_BASE)
#endif /*_DAC */

#ifdef _AFIO
  #define AFIO                ((AFIO_TypeDef *) AFIO_BASE)
#endif /*_AFIO */

#ifdef _EXTI
  #define EXTI                ((EXTI_TypeDef *) EXTI_BASE)
#endif /*_EXTI */

#ifdef _GPIOA
  #define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#endif /*_GPIOA */

#ifdef _GPIOB
  #define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#endif /*_GPIOB */

#ifdef _GPIOC
  #define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#endif /*_GPIOC */

#ifdef _GPIOD
  #define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#endif /*_GPIOD */

#ifdef _GPIOE
  #define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#endif /*_GPIOE */

#ifdef _GPIOF
  #define GPIOF               ((GPIO_TypeDef *) GPIOF_BASE)
#endif /*_GPIOF */

#ifdef _GPIOG
  #define GPIOG               ((GPIO_TypeDef *) GPIOG_BASE)
#endif /*_GPIOG */

#ifdef _ADC1
  #define ADC1                ((ADC_TypeDef *) ADC1_BASE)
#endif /*_ADC1 */

#ifdef _ADC2
  #define ADC2                ((ADC_TypeDef *) ADC2_BASE)
#endif /*_ADC2 */

#ifdef _TIM1
  #define TIM1                ((TIM_TypeDef *) TIM1_BASE)
#endif /*_TIM1 */

#ifdef _SPI1
  #define SPI1                ((SPI_TypeDef *) SPI1_BASE)
#endif /*_SPI1 */

#ifdef _TIM8
  #define TIM8                ((TIM_TypeDef *) TIM8_BASE)
#endif /*_TIM8 */

#ifdef _USART1
  #define USART1              ((USART_TypeDef *) USART1_BASE)
#endif /*_USART1 */

#ifdef _ADC3
  #define ADC3                ((ADC_TypeDef *) ADC3_BASE)
#endif /*_ADC3 */

#ifdef _SDIO
  #define SDIO                ((SDIO_TypeDef *) SDIO_BASE)
#endif /*_SDIO */

#ifdef _DMA
  #define DMA1                ((DMA_TypeDef *) DMA1_BASE)
  #define DMA2                ((DMA_TypeDef *) DMA2_BASE)
#endif /*_DMA */

#ifdef _DMA1_Channel1
  #define DMA1_Channel1       ((DMA_Channel_TypeDef *) DMA1_Channel1_BASE)
#endif /*_DMA1_Channel1 */

#ifdef _DMA1_Channel2
  #define DMA1_Channel2       ((DMA_Channel_TypeDef *) DMA1_Channel2_BASE)
#endif /*_DMA1_Channel2 */

#ifdef _DMA1_Channel3
  #define DMA1_Channel3       ((DMA_Channel_TypeDef *) DMA1_Channel3_BASE)
#endif /*_DMA1_Channel3 */

#ifdef _DMA1_Channel4
  #define DMA1_Channel4       ((DMA_Channel_TypeDef *) DMA1_Channel4_BASE)
#endif /*_DMA1_Channel4 */

#ifdef _DMA1_Channel5
  #define DMA1_Channel5       ((DMA_Channel_TypeDef *) DMA1_Channel5_BASE)
#endif /*_DMA1_Channel5 */

#ifdef _DMA1_Channel6
  #define DMA1_Channel6       ((DMA_Channel_TypeDef *) DMA1_Channel6_BASE)
#endif /*_DMA1_Channel6 */

#ifdef _DMA1_Channel7
  #define DMA1_Channel7       ((DMA_Channel_TypeDef *) DMA1_Channel7_BASE)
#endif /*_DMA1_Channel7 */

#ifdef _DMA2_Channel1
  #define DMA2_Channel1       ((DMA_Channel_TypeDef *) DMA2_Channel1_BASE)
#endif /*_DMA2_Channel1 */

#ifdef _DMA2_Channel2
  #define DMA2_Channel2       ((DMA_Channel_TypeDef *) DMA2_Channel2_BASE)
#endif /*_DMA2_Channel2 */

#ifdef _DMA2_Channel3
  #define DMA2_Channel3       ((DMA_Channel_TypeDef *) DMA2_Channel3_BASE)
#endif /*_DMA2_Channel3 */

#ifdef _DMA2_Channel4
  #define DMA2_Channel4       ((DMA_Channel_TypeDef *) DMA2_Channel4_BASE)
#endif /*_DMA2_Channel4 */

#ifdef _DMA2_Channel5
  #define DMA2_Channel5       ((DMA_Channel_TypeDef *) DMA2_Channel5_BASE)
#endif /*_DMA2_Channel5 */

#ifdef _RCC
  #define RCC                 ((RCC_TypeDef *) RCC_BASE)
#endif /*_RCC */

#ifdef _CRC
  #define CRC                 ((CRC_TypeDef *) CRC_BASE)
#endif /*_CRC */

#ifdef _FLASH
  #define FLASH               ((FLASH_TypeDef *) FLASH_R_BASE)
  #define OB                  ((OB_TypeDef *) OB_BASE) 
#endif /*_FLASH */

#ifdef _FSMC
  #define FSMC_Bank1          ((FSMC_Bank1_TypeDef *) FSMC_Bank1_R_BASE)
  #define FSMC_Bank1E         ((FSMC_Bank1E_TypeDef *) FSMC_Bank1E_R_BASE)
  #define FSMC_Bank2          ((FSMC_Bank2_TypeDef *) FSMC_Bank2_R_BASE)
  #define FSMC_Bank3          ((FSMC_Bank3_TypeDef *) FSMC_Bank3_R_BASE)
  #define FSMC_Bank4          ((FSMC_Bank4_TypeDef *) FSMC_Bank4_R_BASE)
#endif /*_FSMC */

#ifdef _DBGMCU
  #define DBGMCU              ((DBGMCU_TypeDef *) DBGMCU_BASE)
#endif /*_DBGMCU */

#ifdef _SysTick
  #define SysTick             ((SysTick_TypeDef *) SysTick_BASE)
#endif /*_SysTick */

#ifdef _NVIC
  #define NVIC                ((NVIC_TypeDef *) NVIC_BASE)
  #define SCB                 ((SCB_TypeDef *) SCB_BASE)  
#endif /*_NVIC */

/*------------------------ Debug Mode ----------------------------------------*/
#else   /* DEBUG */
#ifdef _TIM2
  EXT TIM_TypeDef             *TIM2;
#endif /*_TIM2 */

#ifdef _TIM3
  EXT TIM_TypeDef             *TIM3;
#endif /*_TIM3 */

#ifdef _TIM4
  EXT TIM_TypeDef             *TIM4;
#endif /*_TIM4 */

#ifdef _TIM5
  EXT TIM_TypeDef             *TIM5;
#endif /*_TIM5 */

#ifdef _TIM6
  EXT TIM_TypeDef             *TIM6;
#endif /*_TIM6 */

#ifdef _TIM7
  EXT TIM_TypeDef             *TIM7;
#endif /*_TIM7 */

#ifdef _RTC
  EXT RTC_TypeDef             *RTC;
#endif /*_RTC */

#ifdef _WWDG
  EXT WWDG_TypeDef            *WWDG;
#endif /*_WWDG */

#ifdef _IWDG
  EXT IWDG_TypeDef            *IWDG;
#endif /*_IWDG */

#ifdef _SPI2
  EXT SPI_TypeDef             *SPI2;
#endif /*_SPI2 */

#ifdef _SPI3
  EXT SPI_TypeDef             *SPI3;
#endif /*_SPI3 */

#ifdef _USART2
  EXT USART_TypeDef           *USART2;
#endif /*_USART2 */

#ifdef _USART3
  EXT USART_TypeDef           *USART3;
#endif /*_USART3 */

#ifdef _UART4
  EXT USART_TypeDef           *UART4;
#endif /*_UART4 */

#ifdef _UART5
  EXT USART_TypeDef           *UART5;
#endif /*_UART5 */

#ifdef _I2C1
  EXT I2C_TypeDef             *I2C1;
#endif /*_I2C1 */

#ifdef _I2C2
  EXT I2C_TypeDef             *I2C2;
#endif /*_I2C2 */

#ifdef _CAN
  EXT CAN_TypeDef             *CAN;
#endif /*_CAN */

#ifdef _BKP
  EXT BKP_TypeDef             *BKP;
#endif /*_BKP */

#ifdef _PWR
  EXT PWR_TypeDef             *PWR;
#endif /*_PWR */

#ifdef _DAC
  EXT DAC_TypeDef             *DAC;
#endif /*_DAC */

#ifdef _AFIO
  EXT AFIO_TypeDef            *AFIO;
#endif /*_AFIO */

#ifdef _EXTI
  EXT EXTI_TypeDef            *EXTI;
#endif /*_EXTI */

#ifdef _GPIOA
  EXT GPIO_TypeDef            *GPIOA;
#endif /*_GPIOA */

#ifdef _GPIOB
  EXT GPIO_TypeDef            *GPIOB;
#endif /*_GPIOB */

#ifdef _GPIOC
  EXT GPIO_TypeDef            *GPIOC;
#endif /*_GPIOC */

#ifdef _GPIOD
  EXT GPIO_TypeDef            *GPIOD;
#endif /*_GPIOD */

#ifdef _GPIOE
  EXT GPIO_TypeDef            *GPIOE;
#endif /*_GPIOE */

#ifdef _GPIOF
  EXT GPIO_TypeDef            *GPIOF;
#endif /*_GPIOF */

#ifdef _GPIOG
  EXT GPIO_TypeDef            *GPIOG;
#endif /*_GPIOG */

#ifdef _ADC1
  EXT ADC_TypeDef             *ADC1;
#endif /*_ADC1 */

#ifdef _ADC2
  EXT ADC_TypeDef             *ADC2;
#endif /*_ADC2 */

#ifdef _TIM1
  EXT TIM_TypeDef             *TIM1;
#endif /*_TIM1 */

#ifdef _SPI1
  EXT SPI_TypeDef             *SPI1;
#endif /*_SPI1 */

#ifdef _TIM8
  EXT TIM_TypeDef             *TIM8;
#endif /*_TIM8 */

#ifdef _USART1
  EXT USART_TypeDef           *USART1;
#endif /*_USART1 */

#ifdef _ADC3
  EXT ADC_TypeDef             *ADC3;
#endif /*_ADC3 */

#ifdef _SDIO
  EXT SDIO_TypeDef            *SDIO;
#endif /*_SDIO */

#ifdef _DMA
  EXT DMA_TypeDef             *DMA1;
  EXT DMA_TypeDef             *DMA2;
#endif /*_DMA */

#ifdef _DMA1_Channel1
  EXT DMA_Channel_TypeDef     *DMA1_Channel1;
#endif /*_DMA1_Channel1 */

#ifdef _DMA1_Channel2
  EXT DMA_Channel_TypeDef     *DMA1_Channel2;
#endif /*_DMA1_Channel2 */

#ifdef _DMA1_Channel3
  EXT DMA_Channel_TypeDef     *DMA1_Channel3;
#endif /*_DMA1_Channel3 */

#ifdef _DMA1_Channel4
  EXT DMA_Channel_TypeDef     *DMA1_Channel4;
#endif /*_DMA1_Channel4 */

#ifdef _DMA1_Channel5
  EXT DMA_Channel_TypeDef     *DMA1_Channel5;
#endif /*_DMA1_Channel5 */

#ifdef _DMA1_Channel6
  EXT DMA_Channel_TypeDef     *DMA1_Channel6;
#endif /*_DMA1_Channel6 */

#ifdef _DMA1_Channel7
  EXT DMA_Channel_TypeDef     *DMA1_Channel7;
#endif /*_DMA1_Channel7 */

#ifdef _DMA2_Channel1
  EXT DMA_Channel_TypeDef     *DMA2_Channel1;
#endif /*_DMA2_Channel1 */

#ifdef _DMA2_Channel2
  EXT DMA_Channel_TypeDef     *DMA2_Channel2;
#endif /*_DMA2_Channel2 */

#ifdef _DMA2_Channel3
  EXT DMA_Channel_TypeDef     *DMA2_Channel3;
#endif /*_DMA2_Channel3 */

#ifdef _DMA2_Channel4
  EXT DMA_Channel_TypeDef     *DMA2_Channel4;
#endif /*_DMA2_Channel4 */

#ifdef _DMA2_Channel5
  EXT DMA_Channel_TypeDef     *DMA2_Channel5;
#endif /*_DMA2_Channel5 */

#ifdef _RCC
  EXT RCC_TypeDef             *RCC;
#endif /*_RCC */

#ifdef _CRC
  EXT CRC_TypeDef             *CRC;
#endif /*_CRC */

#ifdef _FLASH
  EXT FLASH_TypeDef            *FLASH;
  EXT OB_TypeDef               *OB;  
#endif /*_FLASH */

#ifdef _FSMC
  EXT FSMC_Bank1_TypeDef      *FSMC_Bank1;
  EXT FSMC_Bank1E_TypeDef     *FSMC_Bank1E;
  EXT FSMC_Bank2_TypeDef      *FSMC_Bank2;
  EXT FSMC_Bank3_TypeDef      *FSMC_Bank3;
  EXT FSMC_Bank4_TypeDef      *FSMC_Bank4;
#endif /*_FSMC */

#ifdef _DBGMCU
  EXT DBGMCU_TypeDef          *DBGMCU;
#endif /*_DBGMCU */

#ifdef _SysTick
  EXT SysTick_TypeDef         *SysTick;
#endif /*_SysTick */

#ifdef _NVIC
  EXT NVIC_TypeDef            *NVIC;
  EXT SCB_TypeDef             *SCB;
#endif /*_NVIC */

#endif  /* DEBUG */

// Include register bits definition and macro for NVIC, SCB and systick peripherals
#include "stm_system.h"

#endif /* __STM_REGS_H__ */

