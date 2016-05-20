		/*=============================================================================
**                                 SEE4SYS
**                           Copyright (C) 2011
**=============================================================================
** Copyright (c) IRCCyN, ESEO and See4Sys 2005-2011
** MPC5674F port - copyright(c) 2016 propriété de l'IRT Saint Exupery, tous droits reservés
** This software is distributed under the the BSD licence.
** This version is supported by See4Sys, for any problem please contact the
** See4Sys hotline.
**-----------------------------------------------------------------------------
** Supported MCUs      : Freescale MPC5xxx
** Supported Compilers : independant
**-----------------------------------------------------------------------------
** File name         : tpl_app_config.h
**
** Module name       : OS
**
** Requirement specification : AUTOSAR_SWS_OS.pdf
**                             Specification OSEK OS 2.2.3
**
** Summary: This file contains various defines used by Os
**          for conditional compiling.
**
**= History ===================================================================
** Generation date: Mon Nov 21 12:48:01 CET 2011
**=============================================================================
**
**                 AUTOMATICALLY GENERATED FILE : DO NOT EDIT
**
=============================================================================*/
		
#ifndef TPL_REGISTERS_H
#define TPL_REGISTERS_H

/*=============================================================================
 * MPU registers
 */
/* Base address of the MPU */

#define MPUBase 0xFFF14000 


/* MPU control/error status register */
#define MPU_CESR  0x00
#define MPU_CESR_SPERR_MASK 0xE0000000

/* MPU error address register, slave port 0 */
#define MPU_EAR0  0x10

/* MPU error detail register, slave port 0 */
#define MPU_EDR0  0x14

/* MPU error address register, slave port 1 */
#define MPU_EAR1  0x18

/* MPU error detail register, slave port 1 */
#define MPU_EDR1  0x1C

/* MPU error address register, slave port 2 */
#define MPU_EAR2  0x20

/* MPU error detail register, slave port 2 */
#define MPU_EDR2  0x24

/*
 * MPU Region descriptor 0
 */
#define MPU_RGD0_start  0x400
#define MPU_RGD0_end    0x404
#define MPU_RGD0_access 0x408
#define MPU_RGD0_pid    0x40C
/*
 * MPU Region descriptor 1
 */
#define MPU_RGD1_start  0x410
#define MPU_RGD1_end    0x414
#define MPU_RGD1_access 0x418
#define MPU_RGD1_pid    0x41C
/*
 * MPU Region descriptor 2
 */
#define MPU_RGD2_start  0x420
#define MPU_RGD2_end    0x424
#define MPU_RGD2_access 0x428
#define MPU_RGD2_pid    0x42C
/*
 * MPU Region descriptor 3
 */
#define MPU_RGD3_start  0x430
#define MPU_RGD3_end    0x434
#define MPU_RGD3_access 0x438
#define MPU_RGD3_pid    0x43C

/*
 * MPU Region descriptor 4
 */
#define MPU_RGD4_start  0x440
#define MPU_RGD4_end    0x444
#define MPU_RGD4_access 0x448
#define MPU_RGD4_pid    0x44C

/*=============================================================================
 * IVPR / IVORx
 */
#define IVPR_VECBASE  0x00010000
#define IVOR0_OFFSET  0x1000
#define IVOR1_OFFSET  0x1010
#define IVOR2_OFFSET  0x1020
#define IVOR3_OFFSET  0x1030
#define IVOR4_OFFSET  0x1040
#define IVOR5_OFFSET  0x1050
#define IVOR6_OFFSET  0x1060
#define IVOR7_OFFSET  0x1070
#define IVOR8_OFFSET  0x1080
#define IVOR9_OFFSET  0x1090
#define IVOR10_OFFSET 0x10A0
#define IVOR11_OFFSET 0x10B0
#define IVOR12_OFFSET 0x10C0
#define IVOR13_OFFSET 0x10D0
#define IVOR14_OFFSET 0x10E0
#define IVOR15_OFFSET 0x10F0

#define IVOR32_OFFSET 0x1100
#define IVOR33_OFFSET 0x1110
#define IVOR34_OFFSET 0x1120

/*=============================================================================
 * Interrupts registers 
 */
/* Base address of the INTC */
#define INTCBase         0xFFF48000 

/* MPC5674F_Porting_Modif : Add this register address to configure it in interrupt initialization */
/*
 * INTC module configuration register
 */
#define INTC_MCR    (INTCBase + 0x00)

/*
 * INTC current priority register
 */
#define INTC_CPR    (INTCBase + 0x08)

/*
 * INTC interrupt acknowledge register
 */
#define INTC_IACKR  (INTCBase + 0x10)

/*
 * INTC end of interrupt register
 */
#define INTC_EOIR   (INTCBase + 0x18)

/*
 * INTC priority select register
 */
#define INTC_PSR    (INTCBase + 0x40)

#endif


		
