/**
 * @file apf27_aitc.h
 *
 * @section descr File description
 *
 * Driver for Interrupt controller (AITC) of ARM926EJ-S of APF27 board
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation and ARM port
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date: $
 * $Rev: $
 * $Author: $
 * $URL: $
 */
#ifndef APF27_AITC_H
#define APF27_AITC_H

#include "tpl_compiler.h"
#include "tpl_os_std_types.h"
#include "tpl_os_definitions.h"
#include "tpl_os_application_def.h"
#include "tpl_as_isr_kernel.h"
#include "tpl_os_kernel.h"
#include "tpl_os_it_kernel.h"

/**
 * Interrupt source number, see "MCIMX27 Multimedia
 * Applications Processor - Reference Manual" (MCIMX27RM rev 0.3),
 * starting at page 10-26.
 */
typedef enum
{
  INT_DPTC    = 63, /** Dynamic Process Temperature Compensate (DPTC) */
  INT_IIM      = 62, /** IC Identify Module (IIM) */
  INT_LCDC    = 61, /** LCD Controller (LCDC) */
  INT_SLCDC    = 60, /** Smart LCD Controller (SLCDC) */
  INT_SAHARA  = 59, /** Symmetric/Asymmetric Hashing and Random Accelerator */
  INT_SCM      = 58, /** SCC SCM */
  INT_SMN      = 57, /** SCC SMN */
  INT_USBOTG  = 56, /** USB OTG */
  INT_USBHS2  = 55, /** USB HOST2 */
  INT_USBHS1  = 54, /** USB HOST1 */
  INT_H264    = 53, /** H264 */
  INT_EMMAPP  = 52, /** eMMA Post Processor */
  INT_EMMAPRP  = 51, /** eMMA Pre Processor */
  INT_FEC      = 50, /** Fast Ethernet Controller */
  INT_UART5    = 49, /** UART5 */
  INT_UART6    = 48, /** UART6 */
  INT_DMACH15  = 47, /** DMA Channel 15 */
  INT_DMACH14  = 46, /** DMA Channel 14 */
  INT_DMACH13  = 45, /** DMA Channel 13 */
  INT_DMACH12  = 44, /** DMA Channel 12 */
  INT_DMACH11  = 43, /** DMA Channel 11 */
  INT_DMACH10  = 42, /** DMA Channel 10 */
  INT_DMACH9  = 41, /** DMA Channel 9 */
  INT_DMACH8  = 40, /** DMA Channel 8  */
  INT_DMACH7  = 39, /** DMA Channel 7 */
  INT_DMACH6  = 38, /** DMA Channel 6 */
  INT_DMACH5  = 37, /** DMA Channel 5 */
  INT_DMACH4  = 36, /** DMA Channel 4 */
  INT_DMACH3  = 35, /** DMA Channel 3 */
  INT_DMACH2  = 34, /** DMA Channel 2 */
  INT_DMACH1  = 33, /** DMA Channel 1 */
  INT_DMACH0  = 32, /** DMA Channel 0  */
  INT_CSI      = 31, /** CMOS Sensor Interface (CSI)  */
  INT_ATA      = 30, /** Advanced Technology Attachment (ATA)  */
  INT_NFC      = 29, /** NAND Flash Controller (NFC) */
  INT_PCMCIA  = 28, /** PCMCIA/CF Host Controller (PCMCIA) */
  INT_WDOG    = 27, /** Watchdog (WDOG) */
  INT_GPT1    = 26, /** General Purpose Timer (GPT1) */
  INT_GPT2    = 25, /** General Purpose Timer (GPT2) */
  INT_GPT3    = 24, /** General Purpose Timer (GPT3) */
  INT_PWM      = 23, /** Pulse Width Modulator (PWM) */
  INT_RTC      = 22, /** Real-Time Clock (RTC) */
  INT_KPP      = 21, /** Key Pad Port (KPP) */
  INT_UART1    = 20, /** UART1 */
  INT_UART2    = 19, /** UART2 */
  INT_UART3    = 18, /** UART3 */
  INT_UART4    = 17, /** UART4 */
  INT_CSPI1    = 16, /** Configurable SPI (CSPI1) */
  INT_CSPI2    = 15, /** Configurable SPI (CSPI2) */
  INT_SSI1    = 14, /** Synchronous Serial Interface (SSI1) */
  INT_SSI2    = 13, /** Synchronous Serial Interface (SSI2) */
  INT_I2C1    = 12, /** I2C Bus Controller - */
  INT_SDHC1    = 11, /** Secure Digital Host Controller (SDHC1) */
  INT_SDHC2    = 10, /** Secure Digital Host Controller (SDHC2) */
  INT_SDHC3    =  9, /** Secure Digital Host Controller (SDHC3) */
  INT_GPIO    =  8, /** General Purpose Input/Output (GPIO) */
  INT_MSHC    =  7, /** Memory Stick Host Controller (MSHC) */
  INT_CSPI3    =  6, /** Configurable SPI (CSPI3) */
  INT_RTIC    =  5, /** Real Time Integrity Checker (RTIC) */
  INT_GPT4    =  4, /** General Purpose Timer (GPT4) */
  INT_GPT5    =  3, /** General Purpose Timer (GPT5) */
  INT_GPT6    =  2, /** General Purpose Timer (GPT6) */
  INT_I2C2    =  1, /** I2C Bus Controller (I2C2) */
  Reserved    =  0  /** Reserved */
} IMX27_interrupt_source;

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/* TODO: replace this by a goil template which generates a declaration in .h */
extern CONST(tpl_it_vector_entry, OS_CONST) tpl_it_vector[64];

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/** initializes the interrupt controller */
void apf27_aitc_init ();

/**
 * Configures the priority level of an interrupt source.
 * 
 * @param source the interrupt source (see #IMX27_interrupt_source)
 * @param priority_level the priority level (0 the lowest, 7 the highest)
 *
 * @pre priority_level must be in range 0..7
 */
void apf27_aitc_set_source_int_level (IMX27_interrupt_source source, u32 priority_level);

/**
 * Raises a software interrupt on the specified source.
 */
void apf27_aitc_force_source_int (IMX27_interrupt_source source);

/**
 * returns the highest priority and highest source number interrupt, which is
 * the currently processed interrupt source
 *
 * @return Interrupt source (see #IMX27_interrupt_source)
 */
IMX27_interrupt_source apf27_aitc_get_source_int (void);

#endif /* APF27_AITC_H */
