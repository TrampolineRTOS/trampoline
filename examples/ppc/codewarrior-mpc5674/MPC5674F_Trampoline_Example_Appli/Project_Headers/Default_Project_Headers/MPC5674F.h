/**************************************************************************/
/* FILE NAME: mpc5674f.h                     COPYRIGHT (c) Freescale 2010 */
/* VERSION:  1.10                                 All Rights Reserved     */
/*                                                                        */
/* DESCRIPTION:                                                           */
/* This file contains all of the register and bit field definitions for   */
/* MPC5674F.                                                              */
/*========================================================================*/
/* UPDATE HISTORY                                                         */
/* REV      AUTHOR      DATE       DESCRIPTION OF CHANGE                  */
/* ---   -----------  ---------    ---------------------                  */
/* NOTE: Branch pulled at version 0.87 for mpc5674_c.h version 1.00       */  
/* 1.00  B. Terry                  Corrected DECFILT addresses and added  */
/*                                 4 additional filters for Rev. 2        */ 
/* 1.01  B. Terry     16/Nov/09    Corrected bit definitions in SIUDIV    */
/*                                 register.                              */
/* 1.02  B. Terry     19/Nov/09    Added ISEL8, ISEL9, ISEL10, and ISEL11 */
/*                                 regs to SIU tag. (Mamba 2 features)    */
/* 1.03  B. Terry     19/Nov/09    Renamed ISEL10 and ISEL11 to DECFIL1   */
/*                                 and DECFIL2 to match RM.               */
/* 1.04  B. Terry     22/Jan/10    Updated bitfields of MPU RGDx Word2    */
/*                                 register to reflect Mamba 2. Added     */
/*                                 MXCR and MXSR registers to DecFilt.    */
/*                                 Removed pre-release rev history.       */ 
/* 1.05  B. Terry     26/Feb/10    - Added FINTVAL, FINTCNT, CINTVAL, and */
/*                                 CINTCNT registers to DECFIL tag.       */
/*                                 - Added IDIS and SDIE bits to DECFIL   */
/*                                 MCR register.                          */  
/*                                 - Added missing ECSM RESR register.    */
/*                                 - Added new FMPLL SYNFMCR register.    */
/*                                 - Removed FMPLL.SYNSR CALDONE and      */
/*                                 CALPASS bits.                          */
/*                                 - Added new INTC PSR registers.        */
/* 1.06  B. Terry     19/Apr/10    - Corrected errors in DECFIL tag as    */
/*                                 per comments from Conti.               */
/* 1.07  B. Terry     28/Apr/10    Corrected bit ordering error in        */
/*                                 FlexCan frame header struct.           */
/* 1.08  B. Terry     25/May/10    Added SYMATOR typdef to FR frame.      */
/* 1.09  S. Zeidan    20/Aug/10    - Added FlexCAN RXFIFO structure.	  */
/*                                 - Added CLKCFG_DIS field to ESYNCR2    */
/* 1.10  D. Erazmus   09/Nov/10    - Removed SIU_IREER[IREE_NMI0] and     */
/*                                 SIU_IFEER[IFEER_NMI0].                 */
/*                                 - Added missing register types to      */
/*                                 eQADC module, various fixes            */
/**************************************************************************/

#ifndef _MPC5674F_H_
#define _MPC5674F_H_

#include "typedefs.h"

#ifdef  __cplusplus
extern "C" {
#endif

#ifdef __MWERKS__
#pragma push
#pragma ANSI_strict off
#endif

/****************************************************************************/
/*                          MODULE : PBRIDGE_A Peripheral Bridge            */
/****************************************************************************/

    struct PBRIDGE_A_tag {
    
        union {                 /* Master Privilege Control Register 0*/
            vuint32_t R;
            struct {
                vuint32_t MBW0:1;      /* z7 Core */
                vuint32_t MTR0:1;
                vuint32_t MTW0:1;
                vuint32_t MPL0:1;
                vuint32_t MBW1:1;      /* Nexus */
                vuint32_t MTR1:1;
                vuint32_t MTW1:1;
                vuint32_t MPL1:1;
                vuint32_t MBW2:1;      /* Reserved */
                vuint32_t MTR2:1;
                vuint32_t MTW2:1;
                vuint32_t MPL2:1;
                vuint32_t MBW3:1;      /* Reserved */
                vuint32_t MTR3:1;
                vuint32_t MTW3:1;
                vuint32_t MPL3:1;
                vuint32_t MBW4:1;       /* eDMA A */
                vuint32_t MTR4:1;
                vuint32_t MTW4:1;
                vuint32_t MPL4:1;
                vuint32_t MBW5:1;       /* eDMA B */
                vuint32_t MTR5:1;
                vuint32_t MTW5:1;
                vuint32_t MPL5:1;
                vuint32_t MBW6:1;       /* FLEXRAY */
                vuint32_t MTR6:1;
                vuint32_t MTW6:1;
                vuint32_t MPL6:1;
                vuint32_t MBW7:1;       /* EBI */
                vuint32_t MTR7:1;
                vuint32_t MTW7:1;
                vuint32_t MPL7:1;
            } B;
        } MPCR;
        
        union {                 /* Master Privilege Control Register 1 */
            vuint32_t R;
            struct {
            	vuint32_t:32;      /* reserved */
            } B;
        } MPCR1;
        
        uint32_t PBRIDGE_A_reserved0008[6];  /* 0x0008-0x001F */
        
        union {                 /* Peripheral Access Control Register 0 */
            vuint32_t R;
            struct {
                vuint32_t BW0:1;  /* PBRIDGE_A */
                vuint32_t SP0:1;
                vuint32_t WP0:1;
                vuint32_t TP0:1;
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
            } B;
        } PACR0;
        
        uint32_t PBRIDGE_A_reserved0024[7];  /* 0x0024-0x003F */
        
        union {                 /* Off-Platform Peripheral Access Control Register 0 */
            vuint32_t R;
            struct {
                vuint32_t BW0:1;  /* FMPLL */
                vuint32_t SP0:1;
                vuint32_t WP0:1;
                vuint32_t TP0:1;
                vuint32_t BW1:1;  /* EBI control */
                vuint32_t SP1:1; 
                vuint32_t WP1:1;
                vuint32_t TP1:1;
                vuint32_t BW2:1;  /* Flash A control */ 
                vuint32_t SP2:1;
                vuint32_t WP2:1;
                vuint32_t TP2:1;
                vuint32_t BW3:1;  /* Flash B control */ 
                vuint32_t SP3:1;
                vuint32_t WP3:1;
                vuint32_t TP3:1;
                vuint32_t BW4:1;  /* SIU */
                vuint32_t SP4:1;
                vuint32_t WP4:1;
                vuint32_t TP4:1;
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
            } B;
        } OPACR0;
        
        union {                 /* Off-Platform Peripheral Access Control Register 1 */
            vuint32_t R;
            struct {
                vuint32_t BW0:1;  /* EMIOS */
                vuint32_t SP0:1;
                vuint32_t WP0:1;
                vuint32_t TP0:1;
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t BW7:1;  /* PMC */
                vuint32_t SP7:1;
                vuint32_t WP7:1;
                vuint32_t TP7:1;
            } B;
        } OPACR1;
        
        union {                 /* Off-Platform Peripheral Access Control Register 2 */
            vuint32_t R;
            struct {
                vuint32_t BW0:1;  /* eTPU */
                vuint32_t SP0:1;
                vuint32_t WP0:1;
                vuint32_t TP0:1;
                vuint32_t:4;      /* Reserved */
                vuint32_t BW2:1;  /* eTPU PRAM */
                vuint32_t SP2:1;
                vuint32_t WP2:1;
                vuint32_t TP2:1;
                vuint32_t BW3:1;  /* eTPU PRAM mirror */
                vuint32_t SP3:1;
                vuint32_t WP3:1;
                vuint32_t TP3:1;
                vuint32_t BW4:1;  /* eTPU SCM */
                vuint32_t SP4:1;
                vuint32_t WP4:1;
                vuint32_t TP4:1;
                vuint32_t BW5:1;  /* eTPU SCM */
                vuint32_t SP5:1;
                vuint32_t WP5:1;
                vuint32_t TP5:1;
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
            } B;
        } OPACR2;
        
        union {                 /* Off-Platform Peripheral Access Control Register 3 */
            vuint32_t R;
            struct {
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t BW4:1;  /* PIT/RTI  */
                vuint32_t SP4:1;
                vuint32_t WP4:1;
                vuint32_t TP4:1;
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
            } B;
        } OPACR3;
        
        uint32_t PBRIDGE_A_reserved0050[4076];  /* 0x0050-0x3FFF */
    
    };

/****************************************************************************/
/*                          MODULE : PBRIDGE_B Peripheral Bridge            */
/****************************************************************************/

    struct PBRIDGE_B_tag {
    
        union {                 /* Master Privilege Control Register 0 */
            vuint32_t R;
            struct {
                vuint32_t MBW0:1;      /* z7 Core */
                vuint32_t MTR0:1;
                vuint32_t MTW0:1;
                vuint32_t MPL0:1;
                vuint32_t MBW1:1;      /* Nexus */
                vuint32_t MTR1:1;
                vuint32_t MTW1:1;
                vuint32_t MPL1:1;
                vuint32_t MBW2:1;      /* Reserved */
                vuint32_t MTR2:1;
                vuint32_t MTW2:1;
                vuint32_t MPL2:1;
                vuint32_t MBW3:1;      /* Reserved */
                vuint32_t MTR3:1;
                vuint32_t MTW3:1;
                vuint32_t MPL3:1;
                vuint32_t MBW4:1;      /* eDMA A */
                vuint32_t MTR4:1;
                vuint32_t MTW4:1;
                vuint32_t MPL4:1;
                vuint32_t MBW5:1;      /* eDMA B */
                vuint32_t MTR5:1;
                vuint32_t MTW5:1;
                vuint32_t MPL5:1;
                vuint32_t MBW6:1;      /* FLEXRAY */
                vuint32_t MTR6:1;
                vuint32_t MTW6:1;
                vuint32_t MPL6:1;
                vuint32_t MBW7:1;      /* EBI */
                vuint32_t MTR7:1;
                vuint32_t MTW7:1;
                vuint32_t MPL7:1;
            } B;
        } MPCR;
        
        union {                 /* Master Privilege Control Register 1 */
            vuint32_t R;
            struct {
               vuint32_t:32;     /* Reserved */
               
            } B;
        } MPCR1;
        
        uint32_t PBRIDGE_B_reserved0008[6];  /* 0x0008-0x001F */
        
        union {                 /* Peripheral Access Control Register 0 */
            vuint32_t R;
            struct {
                vuint32_t BW0:1;  /* PBRIDGE B */
                vuint32_t SP0:1;
                vuint32_t WP0:1;
                vuint32_t TP0:1;
                vuint32_t BW1:1;  /* XBAR  */
                vuint32_t SP1:1;
                vuint32_t WP1:1;
                vuint32_t TP1:1;
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t BW4:1;  /* MPU */
                vuint32_t SP4:1;
                vuint32_t WP4:1;
                vuint32_t TP4:1;
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
            } B;
        } PACR0;
        
        union {                 /* Peripheral Access Control Register 1 */
            vuint32_t R;
            struct {
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t BW6:1;  /* SWT */
                vuint32_t SP6:1;
                vuint32_t WP6:1;
                vuint32_t TP6:1;
                vuint32_t BW7:1;  /* STM */
                vuint32_t SP7:1;
                vuint32_t WP7:1;
                vuint32_t TP7:1;
            } B;
        } PACR1;
        
        union {                 /* Peripheral Access Control Register 2 */
            vuint32_t R;
            struct {
                vuint32_t BW0:1;  /* ECSM */
                vuint32_t SP0:1;
                vuint32_t WP0:1;
                vuint32_t TP0:1;
                vuint32_t BW1:1;  /* eDMA A */
                vuint32_t SP1:1;
                vuint32_t WP1:1;
                vuint32_t TP1:1;
                vuint32_t BW2:1;  /* INTC */
                vuint32_t SP2:1;
                vuint32_t WP2:1;
                vuint32_t TP2:1;
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t BW5:1;  /* eDMA B */
                vuint32_t SP5:1;
                vuint32_t WP5:1;
                vuint32_t TP5:1;
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
            } B;
        } PACR2;
        
        uint32_t PBRIDGE_B_reserved002C[5];  /* 0x002C-0x003F */
        
        union {                 /* Off-Platform Peripheral Access Control Register 0 */
            vuint32_t R;
            struct {
                vuint32_t BW0:1;  /* eQADC A */
                vuint32_t SP0:1;
                vuint32_t WP0:1;
                vuint32_t TP0:1;
                vuint32_t BW1:1;  /* eQADC B */
                vuint32_t SP1:1;
                vuint32_t WP1:1;
                vuint32_t TP1:1;
                vuint32_t BW2:1;  /* Decimation Filters A, B, C, D */
                vuint32_t SP2:1;
                vuint32_t WP2:1;
                vuint32_t TP2:1;
                vuint32_t:4;      /* Reserved */
                vuint32_t BW4:1;  /* DSPI_A */
                vuint32_t SP4:1;
                vuint32_t WP4:1;
                vuint32_t TP4:1;
                vuint32_t BW5:1;  /* DSPI_B */
                vuint32_t SP5:1;
                vuint32_t WP5:1;
                vuint32_t TP5:1;
                vuint32_t BW6:1;  /* DSPI_C */
                vuint32_t SP6:1;
                vuint32_t WP6:1;
                vuint32_t TP6:1;
                vuint32_t BW7:1;  /* DSPI_D */
                vuint32_t SP7:1;
                vuint32_t WP7:1;
                vuint32_t TP7:1;
            } B;
        } OPACR0;
        
        union {                 /* Off-Platform Peripheral Access Control Register 1 */
            vuint32_t R;
            struct {
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t BW4:1;  /* ESCI_A */
                vuint32_t SP4:1;
                vuint32_t WP4:1;
                vuint32_t TP4:1;
                vuint32_t BW5:1;  /* ESCI_B */
                vuint32_t SP5:1;
                vuint32_t WP5:1;
                vuint32_t TP5:1;
                vuint32_t BW6:1;  /* ESCI_C */
                vuint32_t SP6:1;
                vuint32_t WP6:1;
                vuint32_t TP6:1;
                vuint32_t:4;      /* Reserved */
            } B;
        } OPACR1;
        
        union {                 /* Off-Platform Peripheral Access Control Register 2 */
            vuint32_t R;
            struct {
                vuint32_t BW0:1;  /* FlexCAN_A */
                vuint32_t SP0:1;
                vuint32_t WP0:1;
                vuint32_t TP0:1;
                vuint32_t BW1:1;  /* FlexCAN_B */
                vuint32_t SP1:1;
                vuint32_t WP1:1;
                vuint32_t TP1:1;
                vuint32_t BW2:1;  /* FlexCAN_C */
                vuint32_t SP2:1;
                vuint32_t WP2:1;
                vuint32_t TP2:1;
                vuint32_t BW3:1;  /* FlexCAN_D */
                vuint32_t SP3:1;
                vuint32_t WP3:1;
                vuint32_t TP3:1;
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
            } B;
        } OPACR2;
        
        union {                 /* Off-Platform Peripheral Access Control Register 3 */
            vuint32_t R;
            struct {
                vuint32_t BW0:1;  /* FlexRAY */
                vuint32_t SP0:1;
                vuint32_t WP0:1;
                vuint32_t TP0:1;
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t BW3:1;  /* Temp Sensor */
                vuint32_t SP3:1;
                vuint32_t WP3:1;
                vuint32_t TP3:1;
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t:4;      /* Reserved */
                vuint32_t BW7:1;  /* BAM */
                vuint32_t SP7:1;
                vuint32_t WP7:1;
                vuint32_t TP7:1;
            } B;
        } OPACR3;
        
        uint32_t PBRIDGE_B_reserved0050[4076];  /* 0x0050-0x3FFF */
    
    };

/****************************************************************************/
/*                     MODULE : FMPLL                                       */
/****************************************************************************/

    struct FMPLL_tag {
    
        uint32_t FMPLL_reserved0000;  /* 0x0000-0x0003 */
        
        union {                 /* FMPLL Synthesizer Status Register */
            vuint32_t R;
            struct {
                vuint32_t:22;
                vuint32_t LOLF:1;
                vuint32_t LOC:1;
                vuint32_t MODE:1;
                vuint32_t PLLSEL:1;
                vuint32_t PLLREF:1;
                vuint32_t LOCKS:1;
                vuint32_t LOCK:1;
                vuint32_t LOCF:1;
                vuint32_t :2;
            } B;
        } SYNSR;
        
        union {                 /* FMPLL Enhanced Synthesizer Control Register 1 */
            vuint32_t R;
            struct {
                vuint32_t:1;
                vuint32_t CLKCFG:3;
                vuint32_t:8;
                vuint32_t EPREDIV:4;
                vuint32_t :8;
                vuint32_t EMFD:8;
            } B;
        } ESYNCR1;
        
        union {                 /* FMPLL Enhanced Synthesizer Control Register 2 */
            vuint32_t R;
            struct {
                vuint32_t:8;
                vuint32_t LOCEN:1;
                vuint32_t LOLRE:1;
                vuint32_t LOCRE:1;
                vuint32_t LOLIRQ:1;
                vuint32_t LOCIRQ:1;
                vuint32_t:1;
                vuint32_t ERATE:2;
				vuint32_t CLKCFG_DIS:1;
                vuint32_t:4;
                vuint32_t EDEPTH:3;
                vuint32_t:2;
                vuint32_t ERFD:6;
            } B;
        } ESYNCR2;
        
        uint32_t FMPLL_reserved0010[4];  /* 0x0010-0x001C */
        
		union {                 /* FMPLL Synthesizer FM Control Register */
            vuint32_t R;
            struct {
                vuint32_t:1;
                vuint32_t FMDAC_EN:1;
                vuint32_t:9;
                vuint32_t FMDAC_CTL:5;
                vuint32_t :16;
            } B;
        } SYNFMCR;
        
        uint32_t FMPLL_reserved0024[4090];  /* 0x0024-0x3FFF */
        
    
    };

/****************************************************************************/
/*                     MODULE : External Bus Interface (EBI)                */
/****************************************************************************/

    struct CAL_CS_tag {
        union {                 /* Calibration Base Register Bank */
            vuint32_t R;
            struct {
                vuint32_t BA:17;
                vuint32_t:3;
                vuint32_t PS:1;
                vuint32_t:3;
                vuint32_t AD_MUX:1;
                vuint32_t BL:1;
                vuint32_t WEBS:1;
                vuint32_t TBDIP:1;
                vuint32_t:1;
                vuint32_t SETA:1;
                vuint32_t BI:1;
                vuint32_t V:1;
            } B;
        } BR;
        
        union {                 /* Calibration Option Register Bank */
            vuint32_t R;
            struct {
                vuint32_t AM:17;
                vuint32_t:7;
                vuint32_t SCY:4;
                vuint32_t:1;
                vuint32_t BSCY:2;
                vuint32_t:1;
            } B;
        } OR;
    };

    struct EBI_tag {
    
        union {                 /* Module Configuration Register */
            vuint32_t R;
            struct {
                vuint32_t:16;
                vuint32_t ACGE:1;
                vuint32_t:8;
                vuint32_t MDIS:1;
                vuint32_t:3;
                vuint32_t D16_31:1;
                vuint32_t AD_MUX:1;
                vuint32_t DBM:1;
            } B;
        } MCR;
        
        uint32_t EBI_reserved0004;  /* 0x0004-0x0007 */
        
        union {                 /* Transfer Error Status Register */
            vuint32_t R;
            struct {
                vuint32_t:30;
                vuint32_t TEAF:1;
                vuint32_t BMTF:1;
            } B;
        } TESR;
        
        union {                 /* Bus Monitor Control Register */
            vuint32_t R;
            struct {
                vuint32_t:16;
                vuint32_t BMT:8;
                vuint32_t BME:1;
                  vuint32_t:7;
            } B;
        } BMCR;
        
        /* Base/Option registers */
        uint32_t EBI_reserved0010[8];  /* 0x0010-0x002F */
        
        uint32_t EBI_reserved0030[4];  /* 0x0030-0x003F */
        
        /* Calibration registers */
        struct CAL_CS_tag CS[4];
        
        uint32_t EBI_reserved0060[4000];  /* 0x0060-0x3FFF */
    
    };

/****************************************************************************/
/*                     MODULE : FLASH                                       */
/****************************************************************************/

    struct FLASH_tag {
    
        union {                 /* Module Configuration Register */
            vuint32_t R;
            struct {
                vuint32_t:5;
                vuint32_t SIZE:3;
                vuint32_t:1;
                vuint32_t LAS:3;
                vuint32_t:3;
                vuint32_t MAS:1;
                vuint32_t EER:1;
                vuint32_t RWE:1;
                vuint32_t SBC:1;
                vuint32_t:1;
                vuint32_t PEAS:1;
                vuint32_t DONE:1;
                vuint32_t PEG:1;
                vuint32_t:4;
                vuint32_t PGM:1;
                vuint32_t PSUS:1;
                vuint32_t ERS:1;
                vuint32_t ESUS:1;
                vuint32_t EHV:1;
            } B;
        } MCR;
        
        union {                 /* Low/Mid Address Space Block Locking Register */
            vuint32_t R;
            struct {
                vuint32_t LME:1;
                vuint32_t:10;
                vuint32_t SLOCK:1;
                vuint32_t:2;
                vuint32_t MLOCK:2;
                vuint32_t:6;
                vuint32_t LLOCK:10;
            } B;
        } LMLR; /* Legacy naming - refer to LML in Reference Manual */
        
        union {                 /* High Address Space Block Locking Register */
            vuint32_t R;
            struct {
                vuint32_t HBE:1;
                vuint32_t:25;
                vuint32_t HBLOCK:6; /* Legacy naming - refer to HLOCK in Reference Manual */
            } B;
        } HLR; /* Legacy naming - refer to HBL in Reference Manual */
        
        union {                 /* Secondary Low/Mid Block Locking Register */
            vuint32_t R;
            struct {
                vuint32_t SLE:1;
                vuint32_t:10;
                vuint32_t SSLOCK:1;
                vuint32_t:2;
                vuint32_t SMLOCK:2;
                vuint32_t:6;
                vuint32_t SLLOCK:10;
            } B;
        } SLMLR; /* Legacy naming - refer to SLL in Reference Manual */
        
        union {                 /* Low/Mid Address Space Block Select Register */
            vuint32_t R;
            struct {
                vuint32_t:14;
                vuint32_t MSEL:2;
                vuint32_t:6;
                vuint32_t LSEL:10;
            } B;
        } LMSR; /* Legacy naming - refer to LMS in Reference Manual */
        
        union {                 /* High Address Space Block Select Register */
            vuint32_t R;
            struct {
                vuint32_t:26;
                vuint32_t HBSEL:6; /* Legacy naming - refer to HSEL in Reference Manual */
            } B;
        } HSR; /* Legacy naming - refer to HBS in Reference Manual */
        
        union {                 /* Address Register */
            vuint32_t R;
            struct {
                vuint32_t SAD:1;
                vuint32_t:13;
                vuint32_t ADDR:15;
                vuint32_t:3;
            } B;
        } AR; /* Legacy naming - refer to ADR in Reference Manual */
        
        union {                 /* Platform Flash Configuration Register 1 */
            vuint32_t R;
            struct {
                vuint32_t:7;
                vuint32_t M8PFE:1;     /* z7 Nexus */
                vuint32_t:1;           /* EBI Testing - Reserved */
                vuint32_t M6PFE:1;     /* FlexRay  */
                vuint32_t M5PFE:1;     /* eDMA_B   */
                vuint32_t M4PFE:1;     /* eDMA_A   */
                vuint32_t:1;           /* Reserved */
                vuint32_t:1;           /* Reserved */
                vuint32_t:1;           /* Reserved */
                vuint32_t M0PFE:1;     /* z7 Core  */
                vuint32_t APC:3;
                vuint32_t WWSC:2;
                vuint32_t RWSC:3;
                vuint32_t:1;
                vuint32_t DPFEN:1;
                vuint32_t:1;
                vuint32_t IPFEN:1;
                vuint32_t:1;
                vuint32_t PFLIM:2;
                vuint32_t BFEN:1;
            } B;
        } BIUCR; /* Legacy naming - PFCR1 */
        
        union {                 /*Platform Flash Access Protection Register */
            vuint32_t R;
            struct {
                vuint32_t:14;
                vuint32_t M8AP:2;     /* z7 Nexus */
                vuint32_t:2;          /* EBI Testing - Reserved */
                vuint32_t M6AP:2;     /* FlexRay  */
                vuint32_t M5AP:2;     /* eDMA_B   */
                vuint32_t M4AP:2;     /* eDMA_A   */
                vuint32_t:2;          /* Reserved */
                vuint32_t:2;          /* Reserved */
                vuint32_t:2;          /* Reserved */
                vuint32_t M0AP:2;     /* z7 Core  */
            } B;
        } BIUAPR; /* Legacy naming - refer to PFAPR in Reference Manual */
        
        union {                 /* Platform Flash Configuration Register 2 */
            vuint32_t R;
            struct {
                vuint32_t LBCFG:2;
                vuint32_t:30;
            } B;
        } BIUCR2;
        
        uint32_t FLASH_reserved0028[4086];  /* 0x0028-0x3FFF */
    };

/****************************************************************************/
/*                     MODULE : SIU                                         */
/****************************************************************************/
    struct SIU_tag {
        int32_t SIU_reserved0000  /* 0x0000-0x0003 */;
        
        union {                 /* MCU ID Register */
            vuint32_t R;
            struct {
                vuint32_t PARTNUM:16;
                vuint32_t PKG:4;
                vuint32_t:4;
                vuint32_t MAJOR_REV:4;
                vuint32_t MINOR_REV:4;
            } B;
        } MIDR;
        
        int32_t SIU_reserved0008;  /* 0x0008-0x000B */
        
        union {                 /* Reset Status Register */
            vuint32_t R;
            struct {
                vuint32_t PORS:1;
                vuint32_t ERS:1;
                vuint32_t LLRS:1;
                vuint32_t LCRS:1;
                vuint32_t WDRS:1;
                vuint32_t CRS:1;
                vuint32_t SWTRS:1;
                vuint32_t:7;
                vuint32_t SSRS:1;
                vuint32_t SERF:1;
                vuint32_t WKPCFG:1;
                vuint32_t:11;
                vuint32_t ABR:1;
                vuint32_t BOOTCFG:2;
                vuint32_t RGF:1;
            } B;
        } RSR;
        
        union {                 /* System Reset Control Register */
            vuint32_t R;
            struct {
                vuint32_t SSR:1;
                vuint32_t SER:1;
                vuint32_t:30;   // Removed CRE bit
            } B;
        } SRCR;
        
        union {                 /* External Interrupt Status Register */
            vuint32_t R;
            struct {
            	vuint32_t NMI:1;
                vuint32_t:15;
                vuint32_t EIF15:1;
                vuint32_t EIF14:1;
                vuint32_t EIF13:1;
                vuint32_t EIF12:1;
                vuint32_t EIF11:1;
                vuint32_t EIF10:1;
                vuint32_t EIF9:1;
                vuint32_t EIF8:1;
                vuint32_t EIF7:1;
                vuint32_t EIF6:1;
                vuint32_t EIF5:1;
                vuint32_t EIF4:1;
                vuint32_t EIF3:1;
                vuint32_t EIF2:1;
                vuint32_t EIF1:1;
                vuint32_t EIF0:1;
            } B;
        } EISR;
        
        union {                 /* DMA/Interrupt Request Enable Register */
            vuint32_t R;
            struct {
                vuint32_t NMISEL8:1;
                vuint32_t:7;
                vuint32_t NMISEL0:1;
                vuint32_t:7;
                vuint32_t EIRE15:1;
                vuint32_t EIRE14:1;
                vuint32_t EIRE13:1;
                vuint32_t EIRE12:1;
                vuint32_t EIRE11:1;
                vuint32_t EIRE10:1;
                vuint32_t EIRE9:1;
                vuint32_t EIRE8:1;
                vuint32_t EIRE7:1;
                vuint32_t EIRE6:1;
                vuint32_t EIRE5:1;
                vuint32_t EIRE4:1;
                vuint32_t EIRE3:1;
                vuint32_t EIRE2:1;
                vuint32_t EIRE1:1;
                vuint32_t EIRE0:1;
            } B;
        } DIRER;
        
        union {                 /* DMA/Interrupt Request Select Register */
            vuint32_t R;
            struct {
                vuint32_t:28;
                vuint32_t DIRS3:1;
                vuint32_t DIRS2:1;
                vuint32_t DIRS1:1;
                vuint32_t DIRS0:1;
            } B;
        } DIRSR;
        
        union {                 /* Overrun Status Register */
            vuint32_t R;
            struct {
                vuint32_t:16;
                vuint32_t OVF15:1;
                vuint32_t OVF14:1;
                vuint32_t OVF13:1;
                vuint32_t OVF12:1;
                vuint32_t OVF11:1;
                vuint32_t OVF10:1;
                vuint32_t OVF9:1;
                vuint32_t OVF8:1;
                vuint32_t OVF7:1;
                vuint32_t OVF6:1;
                vuint32_t OVF5:1;
                vuint32_t OVF4:1;
                vuint32_t OVF3:1;
                vuint32_t OVF2:1;
                vuint32_t OVF1:1;
                vuint32_t OVF0:1;
            } B;
        } OSR;
        
        union {                 /* Overrun Request Enable Register */
            vuint32_t R;
            struct {
                vuint32_t:16;
                vuint32_t ORE15:1;
                vuint32_t ORE14:1;
                vuint32_t ORE13:1;
                vuint32_t ORE12:1;
                vuint32_t ORE11:1;
                vuint32_t ORE10:1;
                vuint32_t ORE9:1;
                vuint32_t ORE8:1;
                vuint32_t ORE7:1;
                vuint32_t ORE6:1;
                vuint32_t ORE5:1;
                vuint32_t ORE4:1;
                vuint32_t ORE3:1;
                vuint32_t ORE2:1;
                vuint32_t ORE1:1;
                vuint32_t ORE0:1;
            } B;
        } ORER;
        
        union {                 /* External IRQ Rising-Edge Event Enable Register */
            vuint32_t R;
            struct {
                vuint32_t IREE_NMI8:1;
                vuint32_t:15;
                vuint32_t IREE15:1;
                vuint32_t IREE14:1;
                vuint32_t IREE13:1;
                vuint32_t IREE12:1;
                vuint32_t IREE11:1;
                vuint32_t IREE10:1;
                vuint32_t IREE9:1;
                vuint32_t IREE8:1;
                vuint32_t IREE7:1;
                vuint32_t IREE6:1;
                vuint32_t IREE5:1;
                vuint32_t IREE4:1;
                vuint32_t IREE3:1;
                vuint32_t IREE2:1;
                vuint32_t IREE1:1;
                vuint32_t IREE0:1;
            } B;
        } IREER;
        
        union {                 /* External IRQ Falling-Edge Event Enable Register */
            vuint32_t R;
            struct {
                vuint32_t IFEE_NMI8:1;
                vuint32_t:15;
                vuint32_t IFEE15:1;
                vuint32_t IFEE14:1;
                vuint32_t IFEE13:1;
                vuint32_t IFEE12:1;
                vuint32_t IFEE11:1;
                vuint32_t IFEE10:1;
                vuint32_t IFEE9:1;
                vuint32_t IFEE8:1;
                vuint32_t IFEE7:1;
                vuint32_t IFEE6:1;
                vuint32_t IFEE5:1;
                vuint32_t IFEE4:1;
                vuint32_t IFEE3:1;
                vuint32_t IFEE2:1;
                vuint32_t IFEE1:1;
                vuint32_t IFEE0:1;
            } B;
        } IFEER;
        
        union {                 /* External IRQ Digital Filter Register */
            vuint32_t R;
            struct {
                vuint32_t:28;
                vuint32_t DFL:4;
            } B;
        } IDFR;
        
        union {                 /* External IRQ Filtered Input Register */
            vuint32_t R;
            struct {
                vuint32_t FI31:1;
                vuint32_t FI30:1;
                vuint32_t FI29:1;
                vuint32_t FI28:1;
                vuint32_t FI27:1;
                vuint32_t FI26:1;
                vuint32_t FI25:1;
                vuint32_t FI24:1;
                vuint32_t FI23:1;
                vuint32_t FI22:1;
                vuint32_t FI21:1;
                vuint32_t FI20:1;
                vuint32_t FI19:1;
                vuint32_t FI18:1;
                vuint32_t FI17:1;
                vuint32_t FI16:1;
                vuint32_t FI15:1;
                vuint32_t FI14:1;
                vuint32_t FI13:1;
                vuint32_t FI12:1;
                vuint32_t FI11:1;
                vuint32_t FI10:1;
                vuint32_t FI9:1;
                vuint32_t FI8:1;
                vuint32_t FI7:1;
                vuint32_t FI6:1;
                vuint32_t FI5:1;
                vuint32_t FI4:1;
                vuint32_t FI3:1;
                vuint32_t FI2:1;
                vuint32_t FI1:1;
                vuint32_t FI0:1;
            } B;
        } IFIR;
        
        int32_t SIU_reserved0038[2]; /* 0x0038-0x003F */
        
        union {                 /* Pad Configuration Registers */
            vuint16_t R;
            struct {
                vuint16_t:3;
                vuint16_t PA:3;
                vuint16_t OBE:1;
                vuint16_t IBE:1;
                vuint16_t DSC:2;
                vuint16_t ODE:1;
                vuint16_t HYS:1;
                vuint16_t SRC:2;
                vuint16_t WPE:1;
                vuint16_t WPS:1;
            } B;
        } PCR[512];
        
        int16_t SIU_reserved0440[224];  /* 0x0440-0x05FF */
        
        union {                 /* GPIO Pin Data Output Registers */
            vuint8_t R;
            struct {
                vuint8_t:7;
                vuint8_t PDO:1;
            } B;
        } GPDO[512];
        
        union {                 /* GPIO Pin Data Input Registers */
            vuint8_t R;
            struct {
                vuint8_t:7;
                vuint8_t PDI:1;
            } B;
        } GPDI[256];
        
        uint32_t SIU_reserved0900;  /* 0x0900-0x0903 */
        
        union {                 /* External IRQ Input Select Register */
            vuint32_t R;
            struct {
                vuint32_t ESEL15:2;
                vuint32_t ESEL14:2;
                vuint32_t ESEL13:2;
                vuint32_t ESEL12:2;
                vuint32_t ESEL11:2;
                vuint32_t ESEL10:2;
                vuint32_t ESEL9:2;
                vuint32_t ESEL8:2;
                vuint32_t ESEL7:2;
                vuint32_t ESEL6:2;
                vuint32_t ESEL5:2;
                vuint32_t ESEL4:2;
                vuint32_t ESEL3:2;
                vuint32_t ESEL2:2;
                vuint32_t ESEL1:2;
                vuint32_t ESEL0:2;
            } B;
        } EIISR;
        
        union {                 /* DSPI Input Select Register */
            vuint32_t R;
            struct {
                vuint32_t SINSELA:2;
                vuint32_t SSSELA:2;
                vuint32_t SCKSELA:2;
                vuint32_t TRIGSELA:2;
                vuint32_t SINSELB:2;
                vuint32_t SSSELB:2;
                vuint32_t SCKSELB:2;
                vuint32_t TRIGSELB:2;
                vuint32_t SINSELC:2;
                vuint32_t SSSELC:2;
                vuint32_t SCKSELC:2;
                vuint32_t TRIGSELC:2;
                vuint32_t SINSELD:2;
                vuint32_t SSSELD:2;
                vuint32_t SCKSELD:2;
                vuint32_t TRIGSELD:2;
            } B;
        } DISR;
        
        int32_t SIU_reserved090C;  /* 0x090C-0x090F */
        
        union {                 /* eQADC Command FIFO Trigger Source Select - IMUX Select Registers */
            vuint32_t R;
            struct {
                vuint32_t:1;
                vuint32_t CTSEL5_0:7;
                vuint32_t:1;
                vuint32_t CTSEL4_0:7;
                vuint32_t:1;
                vuint32_t CTSEL3_0:7;
                vuint32_t:1;
                vuint32_t CTSEL2_0:7;
            } B;
        } ISEL4;
        
        union {                 /* eQADC Command FIFO Trigger Source Select - IMUX Select Registers */
            vuint32_t R;
            struct {
                vuint32_t:1;
                vuint32_t CTSEL1_0:7;
                vuint32_t:1;
                vuint32_t CTSEL0_0:7;
                vuint32_t:16;
            } B;
        } ISEL5;
        
        union {                 /* eQADC Command FIFO Trigger Source Select - IMUX Select Registers */
            vuint32_t R;
            struct {
                vuint32_t:1;
                vuint32_t CTSEL5_1:7;
                vuint32_t:1;
                vuint32_t CTSEL4_1:7;
                vuint32_t:1;
                vuint32_t CTSEL3_1:7;
                vuint32_t:1;
                vuint32_t CTSEL2_1:7;
            } B;
        } ISEL6;
        
        union {                 /* eQADC Command FIFO Trigger Source Select - IMUX Select Registers */
            vuint32_t R;
            struct {
                vuint32_t:1;
                vuint32_t CTSEL1_1:7;
                vuint32_t:1;
                vuint32_t CTSEL0_1:7;
                vuint32_t:16;
            } B;
        } ISEL7;
        
        union {                 /* eTPU Input Select Register */
            vuint32_t R;
            struct {
                vuint32_t:11;
                vuint32_t ETPU29:1;
                vuint32_t:3;
                vuint32_t ETPU28:1;
                vuint32_t:3;
                vuint32_t ETPU27:1;
                vuint32_t:3;
                vuint32_t ETPU26:1;
                vuint32_t:3;
                vuint32_t ETPU25:1;
                vuint32_t:3;
                vuint32_t ETPU24:1;
             } B;
        } ISEL8;
        
        union {                 /* eQADC Advanced Trigger Select  */
            vuint32_t R;
            struct {
                vuint32_t:27;
                vuint32_t ETSEL0A:5;
            } B;
        } ISEL9;
        
        union {                 /* DecFilter Integrator Control  */
            vuint32_t R;
            struct {
                vuint32_t ZSELA:4;
                vuint32_t HSELA:4;
                vuint32_t ZSELB:4;
                vuint32_t HSELB:4;
                vuint32_t ZSELC:4;
                vuint32_t HSELC:4;
                vuint32_t ZSELD:4;
                vuint32_t HSELD:4;
            } B;
        } DECFIL1;
        
        union {                 /* DecFilter Integrator Control */
            vuint32_t R;
            struct {
                vuint32_t ZSELE:4;
                vuint32_t HSELE:4;
                vuint32_t ZSELF:4;
                vuint32_t HSELF:4;
                vuint32_t ZSELG:4;
                vuint32_t HSELG:4;
                vuint32_t ZSELH:4;
                vuint32_t HSELH:4;
            } B;
        } DECFIL2;
        
        
        int32_t SIU_reserved0920[20]; /* 0x0930-0x097F */
        
        union {                 /* Chip Configuration Register Register */
            vuint32_t R;
            struct {
                vuint32_t:14;
                vuint32_t MATCH:1;
                vuint32_t DISNEX:1;
                vuint32_t:16;
            } B;
        } CCR;
        
        union {                 /* External Clock Configuration Register Register */
            vuint32_t R;
            struct {
                vuint32_t:16;
                vuint32_t ENGDIV:8;
                vuint32_t ECSS:1;
                vuint32_t:3;
                vuint32_t EBTS:1;
                vuint32_t:1;
                vuint32_t EBDF:2;
            } B;
        } ECCR;
        
        union {                 /* Compare A Register High */
            vuint32_t R;
            struct {
                vuint32_t CMPAH:32;
            } B;
        } CARH;
        
        union {                 /* Compare A Register Low */
            vuint32_t R;
            struct {
                vuint32_t CMPAL:32;
            } B;
        } CARL;
        
        union {                 /* Compare B Register High */
            vuint32_t R;
            struct {
                vuint32_t CMPBH:32;
            } B;
        } CBRH;
        
        union {                 /* Compare B Register Low */
            vuint32_t R;
            struct {
                vuint32_t CMPBL:32;
            } B;
        } CBRL;
        
        int32_t SIU_reserved0998[2];  /* 0x0998-0x099F */
        
        union {                 /* System Clock Register */
            vuint32_t R;
            struct {
                vuint32_t:22;
                vuint32_t IPCLKDIV:2;
                vuint32_t:3;
                vuint32_t BYPASS:1;
                vuint32_t SYSCLKDIV:2;
                vuint32_t:2;
            } B;
        } SYSDIV;
        
        union {                 /* Halt Register */
            vuint32_t R;
            struct {
                vuint32_t CPUSTP:1;     /* CPU and Platform stop request  */
                vuint32_t:4;            /* Reserved */
                vuint32_t TPUSTP:1;     /* eTPU_A stop request */
                vuint32_t NPCSTP:1;     /* Nexus stop request */
                vuint32_t EBISTP:1;     /* EBI stop request*/
                vuint32_t ADCSTP:1;     /* eQADC stop request */
                vuint32_t:1;            /* Reserved */
                vuint32_t MIOSSTP:1;    /* eMIOS stop request */
                vuint32_t DFILSTP:1;    /* Decimation filter stop request */
                vuint32_t:1;            /* Reserved */
                vuint32_t PITSTP:1;     /* PIT stop request */
                vuint32_t:2;            /* Reserved */
                vuint32_t CNDSTP:1;     /* FlexCAN D stop request */
                vuint32_t CNCSTP:1;     /* FlexCAN C stop request */
                vuint32_t CNBSTP:1;     /* FlexCAN B stop request */
                vuint32_t CNASTP:1;     /* FlexCAN A stop request */
                vuint32_t SPIDSTP:1;    /* DSPI D stop request */
                vuint32_t SPICSTP:1;    /* DSPI C stop request */
                vuint32_t SPIBSTP:1;    /* DSPI B stop request */
                vuint32_t SPIASTP:1;    /* DSPI C stop request */
                vuint32_t:5;            /* Reserved */
				vuint32_t SCICSTP:1;    /* eSCI C stop request */
                vuint32_t SCIBSTP:1;    /* eSCI B stop request */
                vuint32_t SCIASTP:1;    /* eSCI A stop request */
            } B;
        } HLT;
        
        union {                 /* Halt Acknowledge Register */
            vuint32_t R;
            struct {
                vuint32_t CPUACK:1;     /* CPU and Platform stop acknowledge  */
                vuint32_t:4;            /* Reserved */
                vuint32_t TPUACK:1;     /* eTPU_A stop acknowledge */
                vuint32_t NPCACK:1;     /* Nexus stop acknowledge */
                vuint32_t EBIACK:1;     /* EBI stop acknowledge*/
                vuint32_t ADCACK:1;     /* eQADC stop acknowledge */
                vuint32_t:1;            /* Reserved */
                vuint32_t MIOSACK:1;    /* eMIOS stop acknowledge */
                vuint32_t DFILACK:1;    /* Decimation filter stop acknowledge */
                vuint32_t:1;            /* Reserved */
                vuint32_t PITACK:1;     /* PIT stop acknowledge */
                vuint32_t:2;            /* Reserved */
                vuint32_t CNDACK:1;     /* FlexCAN D stop acknowledge */
                vuint32_t CNCACK:1;     /* FlexCAN C stop acknowledge */
                vuint32_t CNBACK:1;     /* FlexCAN B stop acknowledge */
                vuint32_t CNAACK:1;     /* FlexCAN A stop acknowledge */
                vuint32_t SPIDACK:1;    /* DSPI D stop acknowledge */
                vuint32_t SPICACK:1;    /* DSPI C stop acknowledge */
                vuint32_t SPIBACK:1;    /* DSPI B stop acknowledge */
                vuint32_t SPIAACK:1;    /* DSPI C stop acknowledge */
                vuint32_t:5;            /* Reserved */
				vuint32_t SCICACK:1;    /* eSCI C stop acknowledge */
                vuint32_t SCIBACK:1;    /* eSCI B stop acknowledge */
                vuint32_t SCIAACK:1;    /* eSCI A stop acknowledge */
            } B;
        } HLTACK;
        
        int32_t SIU_reserved09AC[21]; /* 0x09AC-0x09FF */
        
        int32_t SIU_reserved0A00[128]; /* 0x0A00-0x0BFF */
        
        union {               /* Parallel GPIO Pin Data Output Register */
            vuint32_t R;
            struct {
                vuint32_t PGPDO0:1;
                vuint32_t PGPDO1:1;
                vuint32_t PGPDO2:1;
                vuint32_t PGPDO3:1;
                vuint32_t PGPDO4:1;
                vuint32_t PGPDO5:1;
                vuint32_t PGPDO6:1;
                vuint32_t PGPDO7:1;
                vuint32_t PGPDO8:1;
                vuint32_t PGPDO9:1;
                vuint32_t PGPDO10:1;
                vuint32_t PGPDO11:1;
                vuint32_t PGPDO12:1;
                vuint32_t PGPDO13:1;
                vuint32_t PGPDO14:1;
                vuint32_t PGPDO15:1;
                vuint32_t PGPDO16:1;
                vuint32_t PGPDO17:1;
                vuint32_t PGPDO18:1;
                vuint32_t PGPDO19:1;
                vuint32_t PGPDO20:1;
                vuint32_t PGPDO21:1;
                vuint32_t PGPDO22:1;
                vuint32_t PGPDO23:1;
                vuint32_t PGPDO24:1;
                vuint32_t PGPDO25:1;
                vuint32_t PGPDO26:1;
                vuint32_t PGPDO27:1;
                vuint32_t PGPDO28:1;
                vuint32_t PGPDO29:1;
                vuint32_t PGPDO30:1;
                vuint32_t PGPDO31:1;
            } B;
        } PGPDO[16];
        
        union {               /* Parallel GPIO Pin Data Input Register */
            vuint32_t R;
            struct {
                vuint32_t PGPDI0:1;
                vuint32_t PGPDI1:1;
                vuint32_t PGPDI2:1;
                vuint32_t PGPDI3:1;
                vuint32_t PGPDI4:1;
                vuint32_t PGPDI5:1;
                vuint32_t PGPDI6:1;
                vuint32_t PGPDI7:1;
                vuint32_t PGPDI8:1;
                vuint32_t PGPDI9:1;
                vuint32_t PGPDI10:1;
                vuint32_t PGPDI11:1;
                vuint32_t PGPDI12:1;
                vuint32_t PGPDI13:1;
                vuint32_t PGPDI14:1;
                vuint32_t PGPDI15:1;
                vuint32_t PGPDI16:1;
                vuint32_t PGPDI17:1;
                vuint32_t PGPDI18:1;
                vuint32_t PGPDI19:1;
                vuint32_t PGPDI20:1;
                vuint32_t PGPDI21:1;
                vuint32_t PGPDI22:1;
                vuint32_t PGPDI23:1;
                vuint32_t PGPDI24:1;
                vuint32_t PGPDI25:1;
                vuint32_t PGPDI26:1;
                vuint32_t PGPDI27:1;
                vuint32_t PGPDI28:1;
                vuint32_t PGPDI29:1;
                vuint32_t PGPDI30:1;
                vuint32_t PGPDI31:1;
            } B;
        } PGPDI[16];
        
        union {              /* Masked Parallel GPIO Pin Data Input Register */
            vuint32_t R;
            struct {
                vuint32_t MASK0:1;
                vuint32_t MASK1:1;
                vuint32_t MASK2:1;
                vuint32_t MASK3:1;
                vuint32_t MASK4:1;
                vuint32_t MASK5:1;
                vuint32_t MASK6:1;
                vuint32_t MASK7:1;
                vuint32_t MASK8:1;
                vuint32_t MASK9:1;
                vuint32_t MASK10:1;
                vuint32_t MASK11:1;
                vuint32_t MASK12:1;
                vuint32_t MASK13:1;
                vuint32_t MASK14:1;
                vuint32_t MASK15:1;
                vuint32_t DATA0:1;
                vuint32_t DATA1:1;
                vuint32_t DATA2:1;
                vuint32_t DATA3:1;
                vuint32_t DATA4:1;
                vuint32_t DATA5:1;
                vuint32_t DATA6:1;
                vuint32_t DATA7:1;
                vuint32_t DATA8:1;
                vuint32_t DATA9:1;
                vuint32_t DATA10:1;
                vuint32_t DATA11:1;
                vuint32_t DATA12:1;
                vuint32_t DATA13:1;
                vuint32_t DATA14:1;
                vuint32_t DATA15:1;
            } B;
        } MPGPDO[32];
        
        union {              /* DSPI_A Mask Output High Register */
            vuint32_t R;
            struct {
                vuint32_t MASK0:1;
                vuint32_t MASK1:1;
                vuint32_t MASK2:1;
                vuint32_t MASK3:1;
                vuint32_t MASK4:1;
                vuint32_t MASK5:1;
                vuint32_t MASK6:1;
                vuint32_t MASK7:1;
                vuint32_t MASK8:1;
                vuint32_t MASK9:1;
                vuint32_t MASK10:1;
                vuint32_t MASK11:1;
                vuint32_t MASK12:1;
                vuint32_t MASK13:1;
                vuint32_t MASK14:1;
                vuint32_t MASK15:1;
                vuint32_t DATA0:1;
                vuint32_t DATA1:1;
                vuint32_t DATA2:1;
                vuint32_t DATA3:1;
                vuint32_t DATA4:1;
                vuint32_t DATA5:1;
                vuint32_t DATA6:1;
                vuint32_t DATA7:1;
                vuint32_t DATA8:1;
                vuint32_t DATA9:1;
                vuint32_t DATA10:1;
                vuint32_t DATA11:1;
                vuint32_t DATA12:1;
                vuint32_t DATA13:1;
                vuint32_t DATA14:1;
                vuint32_t DATA15:1;
            } B;
        } DSPIAH;
        
        union {              /* DSPI_A Mask Output Low Register */
            vuint32_t R;
            struct {
                vuint32_t MASK16:1;
                vuint32_t MASK17:1;
                vuint32_t MASK18:1;
                vuint32_t MASK19:1;
                vuint32_t MASK20:1;
                vuint32_t MASK21:1;
                vuint32_t MASK22:1;
                vuint32_t MASK23:1;
                vuint32_t MASK24:1;
                vuint32_t MASK25:1;
                vuint32_t MASK26:1;
                vuint32_t MASK27:1;
                vuint32_t MASK28:1;
                vuint32_t MASK29:1;
                vuint32_t MASK30:1;
                vuint32_t MASK31:1;
                vuint32_t DATA16:1;
                vuint32_t DATA17:1;
                vuint32_t DATA18:1;
                vuint32_t DATA19:1;
                vuint32_t DATA20:1;
                vuint32_t DATA21:1;
                vuint32_t DATA22:1;
                vuint32_t DATA23:1;
                vuint32_t DATA24:1;
                vuint32_t DATA25:1;
                vuint32_t DATA26:1;
                vuint32_t DATA27:1;
                vuint32_t DATA28:1;
                vuint32_t DATA29:1;
                vuint32_t DATA30:1;
                vuint32_t DATA31:1;
            } B;
        } DSPIAL;
        
        union {              /* DSPI_B Mask Output High Register */
            vuint32_t R;
            struct {
                vuint32_t MASK0:1;
                vuint32_t MASK1:1;
                vuint32_t MASK2:1;
                vuint32_t MASK3:1;
                vuint32_t MASK4:1;
                vuint32_t MASK5:1;
                vuint32_t MASK6:1;
                vuint32_t MASK7:1;
                vuint32_t MASK8:1;
                vuint32_t MASK9:1;
                vuint32_t MASK10:1;
                vuint32_t MASK11:1;
                vuint32_t MASK12:1;
                vuint32_t MASK13:1;
                vuint32_t MASK14:1;
                vuint32_t MASK15:1;
                vuint32_t DATA0:1;
                vuint32_t DATA1:1;
                vuint32_t DATA2:1;
                vuint32_t DATA3:1;
                vuint32_t DATA4:1;
                vuint32_t DATA5:1;
                vuint32_t DATA6:1;
                vuint32_t DATA7:1;
                vuint32_t DATA8:1;
                vuint32_t DATA9:1;
                vuint32_t DATA10:1;
                vuint32_t DATA11:1;
                vuint32_t DATA12:1;
                vuint32_t DATA13:1;
                vuint32_t DATA14:1;
                vuint32_t DATA15:1;
            } B;
        } DSPIBH;
        
        union {              /* DSPI_B Mask Output Low Register */
            vuint32_t R;
            struct {
                vuint32_t MASK16:1;
                vuint32_t MASK17:1;
                vuint32_t MASK18:1;
                vuint32_t MASK19:1;
                vuint32_t MASK20:1;
                vuint32_t MASK21:1;
                vuint32_t MASK22:1;
                vuint32_t MASK23:1;
                vuint32_t MASK24:1;
                vuint32_t MASK25:1;
                vuint32_t MASK26:1;
                vuint32_t MASK27:1;
                vuint32_t MASK28:1;
                vuint32_t MASK29:1;
                vuint32_t MASK30:1;
                vuint32_t MASK31:1;
                vuint32_t DATA16:1;
                vuint32_t DATA17:1;
                vuint32_t DATA18:1;
                vuint32_t DATA19:1;
                vuint32_t DATA20:1;
                vuint32_t DATA21:1;
                vuint32_t DATA22:1;
                vuint32_t DATA23:1;
                vuint32_t DATA24:1;
                vuint32_t DATA25:1;
                vuint32_t DATA26:1;
                vuint32_t DATA27:1;
                vuint32_t DATA28:1;
                vuint32_t DATA29:1;
                vuint32_t DATA30:1;
                vuint32_t DATA31:1;
            } B;
        } DSPIBL;
        
        union {              /* DSPI_C Mask Output High Register */
            vuint32_t R;
            struct {
                vuint32_t MASK0:1;
                vuint32_t MASK1:1;
                vuint32_t MASK2:1;
                vuint32_t MASK3:1;
                vuint32_t MASK4:1;
                vuint32_t MASK5:1;
                vuint32_t MASK6:1;
                vuint32_t MASK7:1;
                vuint32_t MASK8:1;
                vuint32_t MASK9:1;
                vuint32_t MASK10:1;
                vuint32_t MASK11:1;
                vuint32_t MASK12:1;
                vuint32_t MASK13:1;
                vuint32_t MASK14:1;
                vuint32_t MASK15:1;
                vuint32_t DATA0:1;
                vuint32_t DATA1:1;
                vuint32_t DATA2:1;
                vuint32_t DATA3:1;
                vuint32_t DATA4:1;
                vuint32_t DATA5:1;
                vuint32_t DATA6:1;
                vuint32_t DATA7:1;
                vuint32_t DATA8:1;
                vuint32_t DATA9:1;
                vuint32_t DATA10:1;
                vuint32_t DATA11:1;
                vuint32_t DATA12:1;
                vuint32_t DATA13:1;
                vuint32_t DATA14:1;
                vuint32_t DATA15:1;
            } B;
        } DSPICH;
        
        union {              /* DSPI_C Mask Output Low Register */
            vuint32_t R;
            struct {
                vuint32_t MASK16:1;
                vuint32_t MASK17:1;
                vuint32_t MASK18:1;
                vuint32_t MASK19:1;
                vuint32_t MASK20:1;
                vuint32_t MASK21:1;
                vuint32_t MASK22:1;
                vuint32_t MASK23:1;
                vuint32_t MASK24:1;
                vuint32_t MASK25:1;
                vuint32_t MASK26:1;
                vuint32_t MASK27:1;
                vuint32_t MASK28:1;
                vuint32_t MASK29:1;
                vuint32_t MASK30:1;
                vuint32_t MASK31:1;
                vuint32_t DATA16:1;
                vuint32_t DATA17:1;
                vuint32_t DATA18:1;
                vuint32_t DATA19:1;
                vuint32_t DATA20:1;
                vuint32_t DATA21:1;
                vuint32_t DATA22:1;
                vuint32_t DATA23:1;
                vuint32_t DATA24:1;
                vuint32_t DATA25:1;
                vuint32_t DATA26:1;
                vuint32_t DATA27:1;
                vuint32_t DATA28:1;
                vuint32_t DATA29:1;
                vuint32_t DATA30:1;
                vuint32_t DATA31:1;
            } B;
        } DSPICL;
        
        union {              /* DSPI_D Mask Output High Register */
            vuint32_t R;
            struct {
                vuint32_t MASK0:1;
                vuint32_t MASK1:1;
                vuint32_t MASK2:1;
                vuint32_t MASK3:1;
                vuint32_t MASK4:1;
                vuint32_t MASK5:1;
                vuint32_t MASK6:1;
                vuint32_t MASK7:1;
                vuint32_t MASK8:1;
                vuint32_t MASK9:1;
                vuint32_t MASK10:1;
                vuint32_t MASK11:1;
                vuint32_t MASK12:1;
                vuint32_t MASK13:1;
                vuint32_t MASK14:1;
                vuint32_t MASK15:1;
                vuint32_t DATA0:1;
                vuint32_t DATA1:1;
                vuint32_t DATA2:1;
                vuint32_t DATA3:1;
                vuint32_t DATA4:1;
                vuint32_t DATA5:1;
                vuint32_t DATA6:1;
                vuint32_t DATA7:1;
                vuint32_t DATA8:1;
                vuint32_t DATA9:1;
                vuint32_t DATA10:1;
                vuint32_t DATA11:1;
                vuint32_t DATA12:1;
                vuint32_t DATA13:1;
                vuint32_t DATA14:1;
                vuint32_t DATA15:1;
            } B;
        } DSPIDH;
        
        union {              /* DSPI_D Mask Output Low Register */
            vuint32_t R;
            struct {
                vuint32_t MASK16:1;
                vuint32_t MASK17:1;
                vuint32_t MASK18:1;
                vuint32_t MASK19:1;
                vuint32_t MASK20:1;
                vuint32_t MASK21:1;
                vuint32_t MASK22:1;
                vuint32_t MASK23:1;
                vuint32_t MASK24:1;
                vuint32_t MASK25:1;
                vuint32_t MASK26:1;
                vuint32_t MASK27:1;
                vuint32_t MASK28:1;
                vuint32_t MASK29:1;
                vuint32_t MASK30:1;
                vuint32_t MASK31:1;
                vuint32_t DATA16:1;
                vuint32_t DATA17:1;
                vuint32_t DATA18:1;
                vuint32_t DATA19:1;
                vuint32_t DATA20:1;
                vuint32_t DATA21:1;
                vuint32_t DATA22:1;
                vuint32_t DATA23:1;
                vuint32_t DATA24:1;
                vuint32_t DATA25:1;
                vuint32_t DATA26:1;
                vuint32_t DATA27:1;
                vuint32_t DATA28:1;
                vuint32_t DATA29:1;
                vuint32_t DATA30:1;
                vuint32_t DATA31:1;
            } B;
        } DSPIDL;
        
        int32_t SIU_reserved0D20[8];  /* 0x0D20-0x0D3F */
        
        union {               /* ETPU B Select Register */
            vuint32_t R;
            struct {
                vuint32_t ETPUB15:1;
                vuint32_t ETPUB14:1;
                vuint32_t ETPUB13:1;
                vuint32_t ETPUB12:1;
                vuint32_t ETPUB11:1;
                vuint32_t ETPUB10:1;
                vuint32_t ETPUB9:1;
                vuint32_t ETPUB8:1;
                vuint32_t ETPUB7:1;
                vuint32_t ETPUB6:1;
                vuint32_t ETPUB5:1;
                vuint32_t ETPUB4:1;
                vuint32_t ETPUB3:1;
                vuint32_t ETPUB2:1;
                vuint32_t ETPUB1:1;
                vuint32_t ETPUB0:1;
                vuint32_t ETPUB31:1;
                vuint32_t ETPUB30:1;
                vuint32_t ETPUB29:1;
                vuint32_t ETPUB28:1;
                vuint32_t ETPUB27:1;
                vuint32_t ETPUB26:1;
                vuint32_t ETPUB25:1;
                vuint32_t ETPUB24:1;
                vuint32_t ETPUB23:1;
                vuint32_t ETPUB22:1;
                vuint32_t ETPUB21:1;
                vuint32_t ETPUB20:1;
                vuint32_t ETPUB19:1;
                vuint32_t ETPUB18:1;
                vuint32_t ETPUB17:1;
                vuint32_t ETPUB16:1;
            } B ;
        } ETPUBA;
        
        union {               /* EMIOS A Select Register */
            vuint32_t R;
            struct {
                vuint32_t EMIOS7:1;
                vuint32_t EMIOS6:1;
                vuint32_t EMIOS5:1;
                vuint32_t EMIOS4:1;
                vuint32_t EMIOS3:1;
                vuint32_t EMIOS2:1;
                vuint32_t EMIOS1:1;
                vuint32_t EMIOS0:1;
                vuint32_t EMIOS8:1;
                vuint32_t EMIOS9:1;
                vuint32_t EMIOS10:1;
                vuint32_t EMIOS11:1;
                vuint32_t EMIOS12:1;
                vuint32_t EMIOS13:1;
                vuint32_t EMIOS14:1;
                vuint32_t EMIOS15:1;
                vuint32_t EMIOS16:1;
                vuint32_t EMIOS17:1;
                vuint32_t EMIOS18:1;
                vuint32_t EMIOS19:1;
                vuint32_t EMIOS20:1;
                vuint32_t EMIOS21:1;
                vuint32_t EMIOS22:1;
                vuint32_t EMIOS23:1;
                vuint32_t EMIOS0_0:1;
                vuint32_t EMIOS1_1:1;
                vuint32_t EMIOS2_2:1;
                vuint32_t EMIOS3_3:1;
                vuint32_t EMIOS4_4:1;
                vuint32_t EMIOS5_5:1;
                vuint32_t EMIOS6_6:1;
                vuint32_t EMIOS7_7:1;
            } B;
        } EMIOSA;
        
        union {             /* DSPIAH/L Select Register for DSPI A */
            vuint32_t R;
            struct {
                vuint32_t DSPIAH0:1;
                vuint32_t DSPIAH1:1;
                vuint32_t DSPIAH2:1;
                vuint32_t DSPIAH3:1;
                vuint32_t DSPIAH4:1;
                vuint32_t DSPIAH5:1;
                vuint32_t DSPIAH6:1;
                vuint32_t DSPIAH7:1;
                vuint32_t DSPIAH8:1;
                vuint32_t DSPIAH9:1;
                vuint32_t DSPIAH10:1;
                vuint32_t DSPIAH11:1;
                vuint32_t DSPIAH12:1;
                vuint32_t DSPIAH13:1;
                vuint32_t DSPIAH14:1;
                vuint32_t DSPIAH15:1;
                vuint32_t DSPIAL16:1;
                vuint32_t DSPIAL17:1;
                vuint32_t DSPIAL18:1;
                vuint32_t DSPIAL19:1;
                vuint32_t DSPIAL20:1;
                vuint32_t DSPIAL21:1;
                vuint32_t DSPIAL22:1;
                vuint32_t DSPIAL23:1;
                vuint32_t DSPIAL24:1;
                vuint32_t DSPIAL25:1;
                vuint32_t DSPIAL26:1;
                vuint32_t DSPIAL27:1;
                vuint32_t DSPIAL28:1;
                vuint32_t DSPIAL29:1;
                vuint32_t DSPIAL30:1;
                vuint32_t DSPIAL31:1;
            } B;
        } DSPIAHLA;
        
        int32_t SIU_reserved0D4C;  /* 0x0D4C-0x0D4F */
        
        union {               /* ETPU A Select Register */
            vuint32_t R;
            struct {
                vuint32_t ETPUA23:1;
                vuint32_t ETPUA22:1;
                vuint32_t ETPUA21:1;
                vuint32_t ETPUA20:1;
                vuint32_t ETPUA19:1;
                vuint32_t ETPUA18:1;
                vuint32_t ETPUA17:1;
                vuint32_t ETPUA16:1;
                vuint32_t ETPUA29:1;
                vuint32_t ETPUA28:1;
                vuint32_t ETPUA27:1;
                vuint32_t ETPUA26:1;
                vuint32_t ETPUA25:1;
                vuint32_t ETPUA24:1;
                vuint32_t ETPUA31:1;
                vuint32_t ETPUA30:1;
                vuint32_t ETPUA12:1;
                vuint32_t ETPUA13:1;
                vuint32_t ETPUA14:1;
                vuint32_t ETPUA15:1;
                vuint32_t ETPUA0:1;
                vuint32_t ETPUA1:1;
                vuint32_t ETPUA2:1;
                vuint32_t ETPUA3:1;
                vuint32_t ETPUA4:1;
                vuint32_t ETPUA5:1;
                vuint32_t ETPUA6:1;
                vuint32_t ETPUA7:1;
                vuint32_t ETPUA8:1;
                vuint32_t ETPUA9:1;
                vuint32_t ETPUA10:1;
                vuint32_t ETPUA11:1;
            } B ;
        } ETPUAB;
        
        union {               /* EMIOS B Select Register */
            vuint32_t R;
            struct {
                vuint32_t EMIOS11:1;
                vuint32_t EMIOS10:1;
                vuint32_t EMIOS9:1;
                vuint32_t EMIOS8:1;
                vuint32_t EMIOS6:1;
                vuint32_t EMIOS5:1;
                vuint32_t EMIOS4:1;
                vuint32_t EMIOS3:1;
                vuint32_t EMIOS2:1;
                vuint32_t EMIOS1:1;
                vuint32_t EMIOS0:1;
                vuint32_t EMIOS23:1;
                vuint32_t EMIOS15:1;
                vuint32_t EMIOS14:1;
                vuint32_t EMIOS13:1;
                vuint32_t EMIOS12:1;
                vuint32_t EMIOS23_23:1;
                vuint32_t EMIOS15_15:1;
                vuint32_t EMIOS14_14:1;
                vuint32_t EMIOS13_13:1;
                vuint32_t EMIOS12_12:1;
                vuint32_t EMIOS11_11:1;
                vuint32_t EMIOS10_10:1;
                vuint32_t EMIOS9_9:1;
                vuint32_t EMIOS8_8:1;
                vuint32_t EMIOS6_6:1;
                vuint32_t EMIOS5_5:1;
                vuint32_t EMIOS4_4:1;
                vuint32_t EMIOS3_3:1;
                vuint32_t EMIOS2_2:1;
                vuint32_t EMIOS1_1:1;
                vuint32_t EMIOS0_0:1;
            } B;
        } EMIOSB;
        
        union {             /* DSPIBH/L Select Register for DSPI B */
            vuint32_t R;
            struct {
                vuint32_t DSPIBH0:1;
                vuint32_t DSPIBH1:1;
                vuint32_t DSPIBH2:1;
                vuint32_t DSPIBH3:1;
                vuint32_t DSPIBH4:1;
                vuint32_t DSPIBH5:1;
                vuint32_t DSPIBH6:1;
                vuint32_t DSPIBH7:1;
                vuint32_t DSPIBH8:1;
                vuint32_t DSPIBH9:1;
                vuint32_t DSPIBH10:1;
                vuint32_t DSPIBH11:1;
                vuint32_t DSPIBH12:1;
                vuint32_t DSPIBH13:1;
                vuint32_t DSPIBH14:1;
                vuint32_t DSPIBH15:1;
                vuint32_t DSPIBL16:1;
                vuint32_t DSPIBL17:1;
                vuint32_t DSPIBL18:1;
                vuint32_t DSPIBL19:1;
                vuint32_t DSPIBL20:1;
                vuint32_t DSPIBL21:1;
                vuint32_t DSPIBL22:1;
                vuint32_t DSPIBL23:1;
                vuint32_t DSPIBL24:1;
                vuint32_t DSPIBL25:1;
                vuint32_t DSPIBL26:1;
                vuint32_t DSPIBL27:1;
                vuint32_t DSPIBL28:1;
                vuint32_t DSPIBL29:1;
                vuint32_t DSPIBL30:1;
                vuint32_t DSPIBL31:1;
            } B;
        } DSPIBHLB;
        
        int32_t SIU_reserved0D5C;  /* 0x0D5C-0x0D5F */
        
        union {               /* ETPU A Select Register */
            vuint32_t R;
            struct {
                vuint32_t ETPUA12:1;
                vuint32_t ETPUA13:1;
                vuint32_t ETPUA14:1;
                vuint32_t ETPUA15:1;
                vuint32_t ETPUA0:1;
                vuint32_t ETPUA1:1;
                vuint32_t ETPUA2:1;
                vuint32_t ETPUA3:1;
                vuint32_t ETPUA4:1;
                vuint32_t ETPUA5:1;
                vuint32_t ETPUA6:1;
                vuint32_t ETPUA7:1;
                vuint32_t ETPUA8:1;
                vuint32_t ETPUA9:1;
                vuint32_t ETPUA10:1;
                vuint32_t ETPUA11:1;
                vuint32_t ETPUA23:1;
                vuint32_t ETPUA22:1;
                vuint32_t ETPUA21:1;
                vuint32_t ETPUA20:1;
                vuint32_t ETPUA19:1;
                vuint32_t ETPUA18:1;
                vuint32_t ETPUA17:1;
                vuint32_t ETPUA16:1;
                vuint32_t ETPUA29:1;
                vuint32_t ETPUA28:1;
                vuint32_t ETPUA27:1;
                vuint32_t ETPUA26:1;
                vuint32_t ETPUA25:1;
                vuint32_t ETPUA24:1;
                vuint32_t ETPUA31:1;
                vuint32_t ETPUA30:1;
            } B ;
        } ETPUAC;
        
        union {               /* EMIOS C Select Register */
            vuint32_t R;
            struct {
                vuint32_t EMIOS12:1;
                vuint32_t EMIOS13:1;
                vuint32_t EMIOS14:1;
                vuint32_t EMIOS15:1;
                vuint32_t EMIOS23:1;
                vuint32_t EMIOS0:1;
                vuint32_t EMIOS1:1;
                vuint32_t EMIOS2:1;
                vuint32_t EMIOS3:1;
                vuint32_t EMIOS4:1;
                vuint32_t EMIOS5:1;
                vuint32_t EMIOS6:1;
                vuint32_t EMIOS8:1;
                vuint32_t EMIOS9:1;
                vuint32_t EMIOS10:1;
                vuint32_t EMIOS11:1;
                vuint32_t EMIOS23_23:1;
                vuint32_t EMIOS22:1;
                vuint32_t EMIOS21:1;
                vuint32_t EMIOS20:1;
                vuint32_t EMIOS19:1;
                vuint32_t EMIOS18:1;
                vuint32_t EMIOS17:1;
                vuint32_t EMIOS16:1;
                vuint32_t EMIOS29:1;
                vuint32_t EMIOS28:1;
                vuint32_t EMIOS27:1;
                vuint32_t EMIOS26:1;
                vuint32_t EMIOS25:1;
                vuint32_t EMIOS24:1;
                vuint32_t EMIOS31:1;
                vuint32_t EMIOS30:1;
            } B;
        } EMIOSC;
        
        union {             /* DSPICH/L Select Register for DSPI C */
            vuint32_t R;
            struct {
                vuint32_t DSPICH0:1;
                vuint32_t DSPICH1:1;
                vuint32_t DSPICH2:1;
                vuint32_t DSPICH3:1;
                vuint32_t DSPICH4:1;
                vuint32_t DSPICH5:1;
                vuint32_t DSPICH6:1;
                vuint32_t DSPICH7:1;
                vuint32_t DSPICH8:1;
                vuint32_t DSPICH9:1;
                vuint32_t DSPICH10:1;
                vuint32_t DSPICH11:1;
                vuint32_t DSPICH12:1;
                vuint32_t DSPICH13:1;
                vuint32_t DSPICH14:1;
                vuint32_t DSPICH15:1;
                vuint32_t DSPICL16:1;
                vuint32_t DSPICL17:1;
                vuint32_t DSPICL18:1;
                vuint32_t DSPICL19:1;
                vuint32_t DSPICL20:1;
                vuint32_t DSPICL21:1;
                vuint32_t DSPICL22:1;
                vuint32_t DSPICL23:1;
                vuint32_t DSPICL24:1;
                vuint32_t DSPICL25:1;
                vuint32_t DSPICL26:1;
                vuint32_t DSPICL27:1;
                vuint32_t DSPICL28:1;
                vuint32_t DSPICL29:1;
                vuint32_t DSPICL30:1;
                vuint32_t DSPICL31:1;
            } B;
        } DSPICHLC;
        
        int32_t SIU_reserved0D6C;  /* 0x0D6C-0x0D6F */
        
        union {               /* ETPU B Select Register */
            vuint32_t R;
            struct {
                vuint32_t ETPUB21:1;
                vuint32_t ETPUB20:1;
                vuint32_t ETPUB19:1;
                vuint32_t ETPUB18:1;
                vuint32_t ETPUB17:1;
                vuint32_t ETPUB16:1;
                vuint32_t:4;
                vuint32_t ETPUB29:1;
                vuint32_t ETPUB28:1;
                vuint32_t ETPUB27:1;
                vuint32_t ETPUB26:1;
                vuint32_t ETPUB25:1;
                vuint32_t ETPUB24:1;
                vuint32_t:16;
            } B ;
        } ETPUBD;
        
        union {               /* EMIOS D Select Register */
            vuint32_t R;
            struct {
                vuint32_t:6;
                vuint32_t EMIOS11:1;
                vuint32_t EMIOS10:1;
                vuint32_t EMIOS13:1;
                vuint32_t EMIOS12:1;
                vuint32_t:22;
            } B;
        } EMIOSD;
        
        union {             /* DSPIDH/L Select Register for DSPI D */
            vuint32_t R;
            struct {
                vuint32_t:32;
            } B;
        } DSPIDHLD;
        
        int32_t SIU_reserved0D7C;  /* 0x0D7C-0x0D7F */
        
        int32_t SIU_reserved0D80[32];  /* 0x0D80-0x0DFF */
        
        union {                 /* GPIO Pin Data Input Registers */
            vuint8_t R;
            struct {
                vuint8_t:7;
                vuint8_t PDI:1;
            } B;
        } GPDI0_511[512];
        
        uint32_t SIU_reserved1000[3072];  /* 0x1000-0x3FFF */
    };

/****************************************************************************/
/*                          MODULE : EMIOS                                  */
/****************************************************************************/

    struct EMIOS_tag {
    
        union {                  /* Module Configuration Register */
            vuint32_t R;
            struct {
                vuint32_t:1;
                vuint32_t MDIS:1;
                vuint32_t FRZ:1;
                vuint32_t GTBE:1;
                vuint32_t ETB:1;
                vuint32_t GPREN:1;
                vuint32_t:6;
                vuint32_t SRV:4;
                vuint32_t GPRE:8;
                vuint32_t:8;
            } B;
        } MCR;
        
        union {                  /* Global FLAG Register */
            vuint32_t R;
            struct {
                vuint32_t F31:1;
                vuint32_t F30:1;
                vuint32_t F29:1;
                vuint32_t F28:1;
                vuint32_t F27:1;
                vuint32_t F26:1;
                vuint32_t F25:1;
                vuint32_t F24:1;
                vuint32_t F23:1;
                vuint32_t F22:1;
                vuint32_t F21:1;
                vuint32_t F20:1;
                vuint32_t F19:1;
                vuint32_t F18:1;
                vuint32_t F17:1;
                vuint32_t F16:1;
                vuint32_t F15:1;
                vuint32_t F14:1;
                vuint32_t F13:1;
                vuint32_t F12:1;
                vuint32_t F11:1;
                vuint32_t F10:1;
                vuint32_t F9:1;
                vuint32_t F8:1;
                vuint32_t F7:1;
                vuint32_t F6:1;
                vuint32_t F5:1;
                vuint32_t F4:1;
                vuint32_t F3:1;
                vuint32_t F2:1;
                vuint32_t F1:1;
                vuint32_t F0:1;
            } B;
        } GFR;
        
        union {                 /* Output Update Disable Register */
            vuint32_t R;
            struct {
                vuint32_t OU31:1;
                vuint32_t OU30:1;
                vuint32_t OU29:1;
                vuint32_t OU28:1;
                vuint32_t OU27:1;
                vuint32_t OU26:1;
                vuint32_t OU25:1;
                vuint32_t OU24:1;
                vuint32_t OU23:1;
                vuint32_t OU22:1;
                vuint32_t OU21:1;
                vuint32_t OU20:1;
                vuint32_t OU19:1;
                vuint32_t OU18:1;
                vuint32_t OU17:1;
                vuint32_t OU16:1;
                vuint32_t OU15:1;
                vuint32_t OU14:1;
                vuint32_t OU13:1;
                vuint32_t OU12:1;
                vuint32_t OU11:1;
                vuint32_t OU10:1;
                vuint32_t OU9:1;
                vuint32_t OU8:1;
                vuint32_t OU7:1;
                vuint32_t OU6:1;
                vuint32_t OU5:1;
                vuint32_t OU4:1;
                vuint32_t OU3:1;
                vuint32_t OU2:1;
                vuint32_t OU1:1;
                vuint32_t OU0:1;
            } B;
        } OUDR;
        
        uint32_t eMIOS_reserved000C[5]; /* 0x000C-0x001F */
        
        struct {
            union {              /* Channel A Data Register */
                vuint32_t R;
            } CADR;
            
            union {              /* Channel B Data Register */
                vuint32_t R;
            } CBDR;
            
            union {              /* Channel Counter Register */
                vuint32_t R;
            } CCNTR;
            
            union {              /* Channel Control Register */
                vuint32_t R;
                struct {
                    vuint32_t FREN:1;
                    vuint32_t ODIS:1;
                    vuint32_t ODISSL:2;
                    vuint32_t UCPRE:2;
                    vuint32_t UCPREN:1;
                    vuint32_t DMA:1;
                    vuint32_t:1;
                    vuint32_t IF:4;
                    vuint32_t FCK:1;
                    vuint32_t FEN:1;
                    vuint32_t:3;
                    vuint32_t FORCMA:1;
                    vuint32_t FORCMB:1;
                    vuint32_t:1;
                    vuint32_t BSL:2;
                    vuint32_t EDSEL:1;
                    vuint32_t EDPOL:1;
                    vuint32_t MODE:7;
                } B;
            } CCR;
            
            union {              /* Channel Status Register */
                vuint32_t R;
                struct {
                    vuint32_t OVR:1;
                    vuint32_t:15;
                    vuint32_t OVFL:1;
                    vuint32_t:12;
                    vuint32_t UCIN:1;
                    vuint32_t UCOUT:1;
                    vuint32_t FLAG:1;
                } B;
            } CSR;
            
            union {              /* Alternate Channel A Data Register */
                vuint32_t R;
            } ALTA;
            
            uint32_t eMIOS_channel_reserved0018[2];  /* 0x0018-0x001F */
            
        } CH[32];
        
        uint32_t eMIOS_reserved0420[3832];  /* 0x0420-0x3FFF */
    
    };

/****************************************************************************/
/*                          MODULE : PMC                                    */
/****************************************************************************/

    struct PMC_tag {
    
        union {
            vuint32_t R;
            struct {
                vuint32_t LVRER:1;
                vuint32_t LVREH:1;
                vuint32_t LVRE50:1;
                vuint32_t LVRE33:1;
                vuint32_t LVREC:1;
                vuint32_t LVREA:1;
                vuint32_t:1;
                vuint32_t:1;
                vuint32_t LVIER:1;
                vuint32_t LVIEH:1;
                vuint32_t LVIE50:1;
                vuint32_t LVIE33:1;
                vuint32_t LVIEC:1;
                vuint32_t LVIEA:1;
                vuint32_t:1;
                vuint32_t TLK:1;
                vuint32_t:16;
            } B;
        } MCR;                  /* Module Configuration Register */
        
        union {
            vuint32_t R;
            struct {
                vuint32_t :8;
                vuint32_t LVDATRIM:4;
                vuint32_t LVDREGTRIM:4;
                vuint32_t VDD33TRIM:4;
                vuint32_t LVD33TRIM:4;
                vuint32_t VDDCTRIM:4;
                vuint32_t LVDCTRIM:4;
            } B;
        } TRIMR;                /* Trimming register */
        
        union {
            vuint32_t R;
            struct {
                vuint32_t :5;
                vuint32_t LVFSTBY:1;
                vuint32_t BGRDY:1;
                vuint32_t BGTS:1;
                vuint32_t :5;
                vuint32_t LVFCSTBY:1;
                vuint32_t :2;
                vuint32_t LVFCR:1;
                vuint32_t LVFCH:1;
                vuint32_t LVFC50:1;
                vuint32_t LVFC33:1;
                vuint32_t LVFCC:1;
                vuint32_t LVFCA:1;
                vuint32_t :2;
                vuint32_t LVFR:1;
                vuint32_t LVFH:1;
                vuint32_t LVF50:1;
                vuint32_t LVF33:1;
                vuint32_t LVFC:1;
                vuint32_t LVFA:1;
                vuint32_t :2;
            } B;
        } SR;                /* status register */
        
        uint32_t PMC_reserved000C[4093];  /* 0x000C-0x3FFF */
    };

/****************************************************************************/
/*                              MODULE :ETPU                                */
/****************************************************************************/

/***************************Configuration Registers**************************/

    struct ETPU_tag {
        union {                 /* MODULE CONFIGURATION REGISTER */
            vuint32_t R;
            struct {
                vuint32_t GEC:1;        /* Global Exception Clear */
                vuint32_t SDMERR:1;     /* SDM Read Error */
                vuint32_t WDTOA:1;      /* Watchdog Timeout-eTPU_A */
                vuint32_t WDTOB:1;      /* Watchdog Timeout-eTPU_B */
                vuint32_t MGE1:1;       /* Microcode Global Exception-ETPU_A */
                vuint32_t MGE2:1;       /* Microcode Global Exception-ETPU_B */
                vuint32_t ILF1:1;       /* Illegal Instruction Flag-ETPU_A */
                vuint32_t ILF2:1;       /* Illegal Instruction Flag-ETPU_B */
                vuint32_t:3;
                vuint32_t SCMSIZE:5;    /* Shared Code Memory size */
                vuint32_t:4;
                vuint32_t SCMMISC:1;    /* SCM MISC Complete/Clear */
                vuint32_t SCMMISF:1;    /* SCM MISC Flag */
                vuint32_t SCMMISEN:1;   /* SCM MISC Enable */
                vuint32_t:2;
                vuint32_t VIS:1;        /* SCM Visability */
                vuint32_t:5;
                vuint32_t GTBE:1;       /* Global Time Base Enable */
            } B;
        } MCR;
        
        union {                 /* COHERENT DUAL-PARAMETER CONTROL */
            vuint32_t R;
            struct {
                vuint32_t STS:1;        /* Start Status bit */
                vuint32_t CTBASE:5;     /* Channel Transfer Base */
                vuint32_t PBASE:10;     /* Parameter Buffer Base Address */
                vuint32_t PWIDTH:1;     /* Parameter Width */
                vuint32_t PARAM0:7;     /* Channel Parameter 0 */
                vuint32_t WR:1;         /* Read/Write selection */
                vuint32_t PARAM1:7;     /* Channel Parameter 1 */
            } B;
        } CDCR;
        
        uint32_t eTPU_reserved0008;  /* 0x0008-0x000B */
        
        union {                 /* MISC Compare Register */
            uint32_t R;
            struct {
                vuint32_t ETPUMISCCMP:32;   
            } B;
        } MISCCMPR;
        
        union {                 /* SCM off-range Date Register */
            uint32_t R;
            struct {
                vuint32_t ETPUSCMOFFDATA:32;   
            } B;
        } SCMOFFDATAR;
        
        union {                 /* ETPU_A Configuration Register */
            vuint32_t R;
            struct {
                vuint32_t FEND:1;       /* Force END */
                vuint32_t MDIS:1;       /* Low power Stop */
                vuint32_t:1;
                vuint32_t STF:1;        /* Stop Flag */
                vuint32_t:4;
                vuint32_t HLTF:1;       /* Halt Mode Flag */
                vuint32_t:3;
                vuint32_t FCSS:1;       /* Filter Clock Source Select */
                vuint32_t FPSCK:3;      /* Filter Prescaler Clock Control */
                vuint32_t CDFC:2;
                vuint32_t:1;
                vuint32_t ERBA:5;       /* Engine Relative Base Address */
                vuint32_t SPPDIS:1;     /* Schedule Priority Passing Disable */
                vuint32_t:2;
                vuint32_t ETB:5;        /* Entry Table Base */
            } B;
        } ECR_A;
        
        union {                 /* ETPU_B Configuration Register */
            vuint32_t R;
            struct {
                vuint32_t FEND:1;       /* Force END */
                vuint32_t MDIS:1;       /* Low power Stop */
                vuint32_t:1;
                vuint32_t STF:1;        /* Stop Flag */
                vuint32_t:4;
                vuint32_t HLTF:1;       /* Halt Mode Flag */
                vuint32_t:3;
                vuint32_t FCSS:1;       /* Filter Clock Source Select */
                vuint32_t FPSCK:3;      /* Filter Prescaler Clock Control */
                vuint32_t CDFC:2;
                vuint32_t:1;
                vuint32_t ERBA:5;       /* Engine Relative Base Address */
                vuint32_t SPPDIS:1;     /* Schedule Priority Passing Disable */
                vuint32_t:2;
                vuint32_t ETB:5;        /* Entry Table Base */
            } B;
        } ECR_B;
        
        uint32_t eTPU_reserved001C;  /* 0x001C-0x001F */
        
        union {                 /* ETPU_A Timebase Configuration Register */
            uint32_t R;
            struct {
                vuint32_t TCR2CTL:3;     /* TCR2 Clock/Gate Control */
                vuint32_t TCRCF:2;       /* TCRCLK Signal Filter Control */
                vuint32_t AM:2;          /* Angle Mode */
                vuint32_t:3;
                vuint32_t TCR2P:6;       /* TCR2 Prescaler Control */
                vuint32_t TCR1CTL:2;     /* TCR1 Clock/Gate Control */
                vuint32_t TCR1CS:1;      /* TCR1 Clock Source */ 
                vuint32_t:5;
                vuint32_t TCR1P:8;       /* TCR1 Prescaler Control */
            } B;
        } TBCR_A;
        
        union {                 /* ETPU_A TCR1 Visibility Register */
            vuint32_t R;
            struct {
                vuint32_t:8;
                vuint32_t TCR1:24;
            } B;
        } TB1R_A;
        
        union {                 /* ETPU_A TCR2 Visibility Register */
            vuint32_t R;
            struct {
                vuint32_t:8;
                vuint32_t TCR2:24;
            } B;
        } TB2R_A;
        
        union {                 /* ETPU_A STAC Configuration Register */
            vuint32_t R;
            struct {
                vuint32_t REN1:1;       /* Resource Enable TCR1 */
                vuint32_t RSC1:1;       /* Resource Control TCR1 */
                vuint32_t:2;
                vuint32_t SERVER_ID1:4;   /* TCR1 Server ID */
                vuint32_t:4;
                vuint32_t SRV1:4;       /* Resource Server Slot */
                vuint32_t REN2:1;       /* Resource Enable TCR2 */
                vuint32_t RSC2:1;       /* Resource Control TCR2 */
                vuint32_t:2;
                vuint32_t SERVER_ID2:4;   /* TCR2 Server ID */
                vuint32_t:4;
                vuint32_t SRV2:4;       /* Resource Server Slot */
            } B;
        } REDCR_A;
        
        uint32_t eTPU_reserved0030[4];  /* 0x0030-0x003F */
        
        union {                 /* ETPU_B Timebase Configuration Register */
            uint32_t R;
            struct {
                vuint32_t TCR2CTL:3;     /* TCR2 Clock/Gate Control */
                vuint32_t TCRCF:2;       /* TCRCLK Signal Filter Control */
                vuint32_t AM:2;          /* Angle Mode */
                vuint32_t:3;
                vuint32_t TCR2P:6;       /* TCR2 Prescaler Control */
                vuint32_t TCR1CTL:2;     /* TCR1 Clock/Gate Control */
                vuint32_t TCR1CS:1;      /* TCR1 Clock Source */ 
                vuint32_t:5;
                vuint32_t TCR1P:8;       /* TCR1 Prescaler Control */
            } B;
        } TBCR_B;
        
        union {                 /* ETPU_B TCR1 Visibility Register */
            vuint32_t R;
            struct {
                vuint32_t:8;
                vuint32_t TCR1:24;
            } B;
        } TB1R_B;
        
        union {                 /* ETPU_B TCR2 Visibility Register */
            vuint32_t R;
            struct {
                vuint32_t:8;
                vuint32_t TCR2:24;
            } B;
        } TB2R_B;
        
        union {                 /* ETPU_B STAC Configuration Register */
            vuint32_t R;
            struct {
                vuint32_t REN1:1;       /* Resource Enable TCR1 */
                vuint32_t RSC1:1;       /* Resource Control TCR1 */
                vuint32_t:2;
                vuint32_t SERVER_ID1:4;   /* TCR1 Server ID */
                vuint32_t:4;
                vuint32_t SRV1:4;       /* Resource Server Slot */
                vuint32_t REN2:1;       /* Resource Enable TCR2 */
                vuint32_t RSC2:1;       /* Resource Control TCR2 */
                vuint32_t:2;
                vuint32_t SERVER_ID2:4;   /* TCR2 Server ID */
                vuint32_t:4;
                vuint32_t SRV2:4;       /* Resource Server Slot */
            } B;
        } REDCR_B;
        
        uint32_t eTPU_reserved0050[4];  /* 0x0050-0x005F */
        
        union {                 /* Watchdog Timer Register A */
            vuint32_t R;
            struct {
                vuint32_t WDM:2;          /* Watchdog Mode */
                vuint32_t:14;
                vuint32_t WDCNT:16;       /* Watchdog Count */
            } B;
        } WDTR_A;
        
        uint32_t eTPU_reserved0064;  /* 0x0064-0x0067 */
        
        union {                 /* Idle Counter Register A*/
            vuint32_t R;
            struct {
                vuint32_t IDLE_CNT:31;
                vuint32_t ICLR:1;       /* Idle Clear */
            } B;
            
        } IDLE_A;
        
        uint32_t eTPU_reserved006C;  /* 0x006C-0x006F */
        
        union {                 /* Watchdog Timer Register B */
            vuint32_t R;
            struct {
                vuint32_t WDM:2;          /* Watchdog Mode */
                vuint32_t:14;
                vuint32_t WDCNT:16;       /* Watchdog Count */
            } B;
        } WDTR_B;
        
        uint32_t eTPU_reserved0074;  /* 0x0074-0x0077 */
        
        union {                 /* Idle Counter Register B*/
            vuint32_t R;
            struct {
                vuint32_t IDLE_CNT:31;
                vuint32_t ICLR:1;       /* Idle Clear */
            } B;
        } IDLE_B;
        
        uint32_t eTPU_reserved007C;  /* 0x007C-0x007F */
        
        uint32_t eTPU_reserved0080[96];  /* 0x0080-0x01FF */

/*****************************Status and Control Registers**************************/

        union {                 /* ETPU_A Channel Interrut Status */
            vuint32_t R;
            struct {
                vuint32_t CIS31:1;      /* Channel 31 Interrut Status */
                vuint32_t CIS30:1;      /* Channel 30 Interrut Status */
                vuint32_t CIS29:1;      /* Channel 29 Interrut Status */
                vuint32_t CIS28:1;      /* Channel 28 Interrut Status */
                vuint32_t CIS27:1;      /* Channel 27 Interrut Status */
                vuint32_t CIS26:1;      /* Channel 26 Interrut Status */
                vuint32_t CIS25:1;      /* Channel 25 Interrut Status */
                vuint32_t CIS24:1;      /* Channel 24 Interrut Status */
                vuint32_t CIS23:1;      /* Channel 23 Interrut Status */
                vuint32_t CIS22:1;      /* Channel 22 Interrut Status */
                vuint32_t CIS21:1;      /* Channel 21 Interrut Status */
                vuint32_t CIS20:1;      /* Channel 20 Interrut Status */
                vuint32_t CIS19:1;      /* Channel 19 Interrut Status */
                vuint32_t CIS18:1;      /* Channel 18 Interrut Status */
                vuint32_t CIS17:1;      /* Channel 17 Interrut Status */
                vuint32_t CIS16:1;      /* Channel 16 Interrut Status */
                vuint32_t CIS15:1;      /* Channel 15 Interrut Status */
                vuint32_t CIS14:1;      /* Channel 14 Interrut Status */
                vuint32_t CIS13:1;      /* Channel 13 Interrut Status */
                vuint32_t CIS12:1;      /* Channel 12 Interrut Status */
                vuint32_t CIS11:1;      /* Channel 11 Interrut Status */
                vuint32_t CIS10:1;      /* Channel 10 Interrut Status */
                vuint32_t CIS9:1;       /* Channel 9 Interrut Status */
                vuint32_t CIS8:1;       /* Channel 8 Interrut Status */
                vuint32_t CIS7:1;       /* Channel 7 Interrut Status */
                vuint32_t CIS6:1;       /* Channel 6 Interrut Status */
                vuint32_t CIS5:1;       /* Channel 5 Interrut Status */
                vuint32_t CIS4:1;       /* Channel 4 Interrut Status */
                vuint32_t CIS3:1;       /* Channel 3 Interrut Status */
                vuint32_t CIS2:1;       /* Channel 2 Interrut Status */
                vuint32_t CIS1:1;       /* Channel 1 Interrut Status */
                vuint32_t CIS0:1;       /* Channel 0 Interrut Status */
            } B;
        } CISR_A;
        
        union {                 /* ETPU_B Channel Interruput Status */
            vuint32_t R;
            struct {
                vuint32_t CIS31:1;      /* Channel 31 Interrut Status */
                vuint32_t CIS30:1;      /* Channel 30 Interrut Status */
                vuint32_t CIS29:1;      /* Channel 29 Interrut Status */
                vuint32_t CIS28:1;      /* Channel 28 Interrut Status */
                vuint32_t CIS27:1;      /* Channel 27 Interrut Status */
                vuint32_t CIS26:1;      /* Channel 26 Interrut Status */
                vuint32_t CIS25:1;      /* Channel 25 Interrut Status */
                vuint32_t CIS24:1;      /* Channel 24 Interrut Status */
                vuint32_t CIS23:1;      /* Channel 23 Interrut Status */
                vuint32_t CIS22:1;      /* Channel 22 Interrut Status */
                vuint32_t CIS21:1;      /* Channel 21 Interrut Status */
                vuint32_t CIS20:1;      /* Channel 20 Interrut Status */
                vuint32_t CIS19:1;      /* Channel 19 Interrut Status */
                vuint32_t CIS18:1;      /* Channel 18 Interrut Status */
                vuint32_t CIS17:1;      /* Channel 17 Interrut Status */
                vuint32_t CIS16:1;      /* Channel 16 Interrut Status */
                vuint32_t CIS15:1;      /* Channel 15 Interrut Status */
                vuint32_t CIS14:1;      /* Channel 14 Interrut Status */
                vuint32_t CIS13:1;      /* Channel 13 Interrut Status */
                vuint32_t CIS12:1;      /* Channel 12 Interrut Status */
                vuint32_t CIS11:1;      /* Channel 11 Interrut Status */
                vuint32_t CIS10:1;      /* Channel 10 Interrut Status */
                vuint32_t CIS9:1;       /* Channel 9 Interrut Status */
                vuint32_t CIS8:1;       /* Channel 8 Interrut Status */
                vuint32_t CIS7:1;       /* Channel 7 Interrut Status */
                vuint32_t CIS6:1;       /* Channel 6 Interrut Status */
                vuint32_t CIS5:1;       /* Channel 5 Interrut Status */
                vuint32_t CIS4:1;       /* Channel 4 Interrut Status */
                vuint32_t CIS3:1;       /* Channel 3 Interrut Status */
                vuint32_t CIS2:1;       /* Channel 2 Interrut Status */
                vuint32_t CIS1:1;       /* Channel 1 Interrupt Status */
                vuint32_t CIS0:1;       /* Channel 0 Interrupt Status */
            } B;
        } CISR_B;
        
        uint32_t eTPU_reserved0208[2];  /* 0x0208-0x020F */
        
        union {                 /* ETPU_A Data Transfer Request Status */
            vuint32_t R;
            struct {
                vuint32_t DTRS31:1;     /* Channel 31 Data Transfer Request Status */
                vuint32_t DTRS30:1;     /* Channel 30 Data Transfer Request Status */
                vuint32_t DTRS29:1;     /* Channel 29 Data Transfer Request Status */
                vuint32_t DTRS28:1;     /* Channel 28 Data Transfer Request Status */
                vuint32_t DTRS27:1;     /* Channel 27 Data Transfer Request Status */
                vuint32_t DTRS26:1;     /* Channel 26 Data Transfer Request Status */
                vuint32_t DTRS25:1;     /* Channel 25 Data Transfer Request Status */
                vuint32_t DTRS24:1;     /* Channel 24 Data Transfer Request Status */
                vuint32_t DTRS23:1;     /* Channel 23 Data Transfer Request Status */
                vuint32_t DTRS22:1;     /* Channel 22 Data Transfer Request Status */
                vuint32_t DTRS21:1;     /* Channel 21 Data Transfer Request Status */
                vuint32_t DTRS20:1;     /* Channel 20 Data Transfer Request Status */
                vuint32_t DTRS19:1;     /* Channel 19 Data Transfer Request Status */
                vuint32_t DTRS18:1;     /* Channel 18 Data Transfer Request Status */
                vuint32_t DTRS17:1;     /* Channel 17 Data Transfer Request Status */
                vuint32_t DTRS16:1;     /* Channel 16 Data Transfer Request Status */
                vuint32_t DTRS15:1;     /* Channel 15 Data Transfer Request Status */
                vuint32_t DTRS14:1;     /* Channel 14 Data Transfer Request Status */
                vuint32_t DTRS13:1;     /* Channel 13 Data Transfer Request Status */
                vuint32_t DTRS12:1;     /* Channel 12 Data Transfer Request Status */
                vuint32_t DTRS11:1;     /* Channel 11 Data Transfer Request Status */
                vuint32_t DTRS10:1;     /* Channel 10 Data Transfer Request Status */
                vuint32_t DTRS9:1;      /* Channel 9 Data Transfer Request Status */
                vuint32_t DTRS8:1;      /* Channel 8 Data Transfer Request Status */
                vuint32_t DTRS7:1;      /* Channel 7 Data Transfer Request Status */
                vuint32_t DTRS6:1;      /* Channel 6 Data Transfer Request Status */
                vuint32_t DTRS5:1;      /* Channel 5 Data Transfer Request Status */
                vuint32_t DTRS4:1;      /* Channel 4 Data Transfer Request Status */
                vuint32_t DTRS3:1;      /* Channel 3 Data Transfer Request Status */
                vuint32_t DTRS2:1;      /* Channel 2 Data Transfer Request Status */
                vuint32_t DTRS1:1;      /* Channel 1 Data Transfer Request Status */
                vuint32_t DTRS0:1;      /* Channel 0 Data Transfer Request Status */
            } B;
        } CDTRSR_A;
        
        union {                 /* ETPU_B Data Transfer Request Status */
            vuint32_t R;
            struct {
                vuint32_t DTRS31:1;     /* Channel 31 Data Transfer Request Status */
                vuint32_t DTRS30:1;     /* Channel 30 Data Transfer Request Status */
                vuint32_t DTRS29:1;     /* Channel 29 Data Transfer Request Status */
                vuint32_t DTRS28:1;     /* Channel 28 Data Transfer Request Status */
                vuint32_t DTRS27:1;     /* Channel 27 Data Transfer Request Status */
                vuint32_t DTRS26:1;     /* Channel 26 Data Transfer Request Status */
                vuint32_t DTRS25:1;     /* Channel 25 Data Transfer Request Status */
                vuint32_t DTRS24:1;     /* Channel 24 Data Transfer Request Status */
                vuint32_t DTRS23:1;     /* Channel 23 Data Transfer Request Status */
                vuint32_t DTRS22:1;     /* Channel 22 Data Transfer Request Status */
                vuint32_t DTRS21:1;     /* Channel 21 Data Transfer Request Status */
                vuint32_t DTRS20:1;     /* Channel 20 Data Transfer Request Status */
                vuint32_t DTRS19:1;     /* Channel 19 Data Transfer Request Status */
                vuint32_t DTRS18:1;     /* Channel 18 Data Transfer Request Status */
                vuint32_t DTRS17:1;     /* Channel 17 Data Transfer Request Status */
                vuint32_t DTRS16:1;     /* Channel 16 Data Transfer Request Status */
                vuint32_t DTRS15:1;     /* Channel 15 Data Transfer Request Status */
                vuint32_t DTRS14:1;     /* Channel 14 Data Transfer Request Status */
                vuint32_t DTRS13:1;     /* Channel 13 Data Transfer Request Status */
                vuint32_t DTRS12:1;     /* Channel 12 Data Transfer Request Status */
                vuint32_t DTRS11:1;     /* Channel 11 Data Transfer Request Status */
                vuint32_t DTRS10:1;     /* Channel 10 Data Transfer Request Status */
                vuint32_t DTRS9:1;      /* Channel 9 Data Transfer Request Status */
                vuint32_t DTRS8:1;      /* Channel 8 Data Transfer Request Status */
                vuint32_t DTRS7:1;      /* Channel 7 Data Transfer Request Status */
                vuint32_t DTRS6:1;      /* Channel 6 Data Transfer Request Status */
                vuint32_t DTRS5:1;      /* Channel 5 Data Transfer Request Status */
                vuint32_t DTRS4:1;      /* Channel 4 Data Transfer Request Status */
                vuint32_t DTRS3:1;      /* Channel 3 Data Transfer Request Status */
                vuint32_t DTRS2:1;      /* Channel 2 Data Transfer Request Status */
                vuint32_t DTRS1:1;      /* Channel 1 Data Transfer Request Status */
                vuint32_t DTRS0:1;      /* Channel 0 Data Transfer Request Status */
            } B;
        } CDTRSR_B;
        
        uint32_t eTPU_reserved0218[2];  /* 0x0218-0x021F */
        
        union {                 /* ETPU_A Interruput Overflow Status */
            vuint32_t R;
            struct {
                vuint32_t CIOS31:1;     /* Channel 31 Interruput Overflow Status */
                vuint32_t CIOS30:1;     /* Channel 30 Interruput Overflow Status */
                vuint32_t CIOS29:1;     /* Channel 29 Interruput Overflow Status */
                vuint32_t CIOS28:1;     /* Channel 28 Interruput Overflow Status */
                vuint32_t CIOS27:1;     /* Channel 27 Interruput Overflow Status */
                vuint32_t CIOS26:1;     /* Channel 26 Interruput Overflow Status */
                vuint32_t CIOS25:1;     /* Channel 25 Interruput Overflow Status */
                vuint32_t CIOS24:1;     /* Channel 24 Interruput Overflow Status */
                vuint32_t CIOS23:1;     /* Channel 23 Interruput Overflow Status */
                vuint32_t CIOS22:1;     /* Channel 22 Interruput Overflow Status */
                vuint32_t CIOS21:1;     /* Channel 21 Interruput Overflow Status */
                vuint32_t CIOS20:1;     /* Channel 20 Interruput Overflow Status */
                vuint32_t CIOS19:1;     /* Channel 19 Interruput Overflow Status */
                vuint32_t CIOS18:1;     /* Channel 18 Interruput Overflow Status */
                vuint32_t CIOS17:1;     /* Channel 17 Interruput Overflow Status */
                vuint32_t CIOS16:1;     /* Channel 16 Interruput Overflow Status */
                vuint32_t CIOS15:1;     /* Channel 15 Interruput Overflow Status */
                vuint32_t CIOS14:1;     /* Channel 14 Interruput Overflow Status */
                vuint32_t CIOS13:1;     /* Channel 13 Interruput Overflow Status */
                vuint32_t CIOS12:1;     /* Channel 12 Interruput Overflow Status */
                vuint32_t CIOS11:1;     /* Channel 11 Interruput Overflow Status */
                vuint32_t CIOS10:1;     /* Channel 10 Interruput Overflow Status */
                vuint32_t CIOS9:1;      /* Channel 9 Interruput Overflow Status */
                vuint32_t CIOS8:1;      /* Channel 8 Interruput Overflow Status */
                vuint32_t CIOS7:1;      /* Channel 7 Interruput Overflow Status */
                vuint32_t CIOS6:1;      /* Channel 6 Interruput Overflow Status */
                vuint32_t CIOS5:1;      /* Channel 5 Interruput Overflow Status */
                vuint32_t CIOS4:1;      /* Channel 4 Interruput Overflow Status */
                vuint32_t CIOS3:1;      /* Channel 3 Interruput Overflow Status */
                vuint32_t CIOS2:1;      /* Channel 2 Interruput Overflow Status */
                vuint32_t CIOS1:1;      /* Channel 1 Interruput Overflow Status */
                vuint32_t CIOS0:1;      /* Channel 0 Interruput Overflow Status */
            } B;
        } CIOSR_A;
        
        union {                 /* ETPU_B Interruput Overflow Status */
            vuint32_t R;
            struct {
                vuint32_t CIOS31:1;     /* Channel 31 Interruput Overflow Status */
                vuint32_t CIOS30:1;     /* Channel 30 Interruput Overflow Status */
                vuint32_t CIOS29:1;     /* Channel 29 Interruput Overflow Status */
                vuint32_t CIOS28:1;     /* Channel 28 Interruput Overflow Status */
                vuint32_t CIOS27:1;     /* Channel 27 Interruput Overflow Status */
                vuint32_t CIOS26:1;     /* Channel 26 Interruput Overflow Status */
                vuint32_t CIOS25:1;     /* Channel 25 Interruput Overflow Status */
                vuint32_t CIOS24:1;     /* Channel 24 Interruput Overflow Status */
                vuint32_t CIOS23:1;     /* Channel 23 Interruput Overflow Status */
                vuint32_t CIOS22:1;     /* Channel 22 Interruput Overflow Status */
                vuint32_t CIOS21:1;     /* Channel 21 Interruput Overflow Status */
                vuint32_t CIOS20:1;     /* Channel 20 Interruput Overflow Status */
                vuint32_t CIOS19:1;     /* Channel 19 Interruput Overflow Status */
                vuint32_t CIOS18:1;     /* Channel 18 Interruput Overflow Status */
                vuint32_t CIOS17:1;     /* Channel 17 Interruput Overflow Status */
                vuint32_t CIOS16:1;     /* Channel 16 Interruput Overflow Status */
                vuint32_t CIOS15:1;     /* Channel 15 Interruput Overflow Status */
                vuint32_t CIOS14:1;     /* Channel 14 Interruput Overflow Status */
                vuint32_t CIOS13:1;     /* Channel 13 Interruput Overflow Status */
                vuint32_t CIOS12:1;     /* Channel 12 Interruput Overflow Status */
                vuint32_t CIOS11:1;     /* Channel 11 Interruput Overflow Status */
                vuint32_t CIOS10:1;     /* Channel 10 Interruput Overflow Status */
                vuint32_t CIOS9:1;      /* Channel 9 Interruput Overflow Status */
                vuint32_t CIOS8:1;      /* Channel 8 Interruput Overflow Status */
                vuint32_t CIOS7:1;      /* Channel 7 Interruput Overflow Status */
                vuint32_t CIOS6:1;      /* Channel 6 Interruput Overflow Status */
                vuint32_t CIOS5:1;      /* Channel 5 Interruput Overflow Status */
                vuint32_t CIOS4:1;      /* Channel 4 Interruput Overflow Status */
                vuint32_t CIOS3:1;      /* Channel 3 Interruput Overflow Status */
                vuint32_t CIOS2:1;      /* Channel 2 Interruput Overflow Status */
                vuint32_t CIOS1:1;      /* Channel 1 Interruput Overflow Status */
                vuint32_t CIOS0:1;      /* Channel 0 Interruput Overflow Status */
            } B;
        } CIOSR_B;
        
        uint32_t eTPU_reserved0228[2];  /* 0x0228-0x022F */
        
        union {                 /* ETPU_A Data Transfer Overflow Status */
            vuint32_t R;
            struct {
                vuint32_t DTROS31:1;    /* Channel 31 Data Transfer Overflow Status */
                vuint32_t DTROS30:1;    /* Channel 30 Data Transfer Overflow Status */
                vuint32_t DTROS29:1;    /* Channel 29 Data Transfer Overflow Status */
                vuint32_t DTROS28:1;    /* Channel 28 Data Transfer Overflow Status */
                vuint32_t DTROS27:1;    /* Channel 27 Data Transfer Overflow Status */
                vuint32_t DTROS26:1;    /* Channel 26 Data Transfer Overflow Status */
                vuint32_t DTROS25:1;    /* Channel 25 Data Transfer Overflow Status */
                vuint32_t DTROS24:1;    /* Channel 24 Data Transfer Overflow Status */
                vuint32_t DTROS23:1;    /* Channel 23 Data Transfer Overflow Status */
                vuint32_t DTROS22:1;    /* Channel 22 Data Transfer Overflow Status */
                vuint32_t DTROS21:1;    /* Channel 21 Data Transfer Overflow Status */
                vuint32_t DTROS20:1;    /* Channel 20 Data Transfer Overflow Status */
                vuint32_t DTROS19:1;    /* Channel 19 Data Transfer Overflow Status */
                vuint32_t DTROS18:1;    /* Channel 18 Data Transfer Overflow Status */
                vuint32_t DTROS17:1;    /* Channel 17 Data Transfer Overflow Status */
                vuint32_t DTROS16:1;    /* Channel 16 Data Transfer Overflow Status */
                vuint32_t DTROS15:1;    /* Channel 15 Data Transfer Overflow Status */
                vuint32_t DTROS14:1;    /* Channel 14 Data Transfer Overflow Status */
                vuint32_t DTROS13:1;    /* Channel 13 Data Transfer Overflow Status */
                vuint32_t DTROS12:1;    /* Channel 12 Data Transfer Overflow Status */
                vuint32_t DTROS11:1;    /* Channel 11 Data Transfer Overflow Status */
                vuint32_t DTROS10:1;    /* Channel 10 Data Transfer Overflow Status */
                vuint32_t DTROS9:1;     /* Channel 9 Data Transfer Overflow Status */
                vuint32_t DTROS8:1;     /* Channel 8 Data Transfer Overflow Status */
                vuint32_t DTROS7:1;     /* Channel 7 Data Transfer Overflow Status */
                vuint32_t DTROS6:1;     /* Channel 6 Data Transfer Overflow Status */
                vuint32_t DTROS5:1;     /* Channel 5 Data Transfer Overflow Status */
                vuint32_t DTROS4:1;     /* Channel 4 Data Transfer Overflow Status */
                vuint32_t DTROS3:1;     /* Channel 3 Data Transfer Overflow Status */
                vuint32_t DTROS2:1;     /* Channel 2 Data Transfer Overflow Status */
                vuint32_t DTROS1:1;     /* Channel 1 Data Transfer Overflow Status */
                vuint32_t DTROS0:1;     /* Channel 0 Data Transfer Overflow Status */
            } B;
        } CDTROSR_A;
        
        union {                 /* ETPU_B Data Transfer Overflow Status */
            vuint32_t R;
            struct {
                vuint32_t DTROS31:1;    /* Channel 31 Data Transfer Overflow Status */
                vuint32_t DTROS30:1;    /* Channel 30 Data Transfer Overflow Status */
                vuint32_t DTROS29:1;    /* Channel 29 Data Transfer Overflow Status */
                vuint32_t DTROS28:1;    /* Channel 28 Data Transfer Overflow Status */
                vuint32_t DTROS27:1;    /* Channel 27 Data Transfer Overflow Status */
                vuint32_t DTROS26:1;    /* Channel 26 Data Transfer Overflow Status */
                vuint32_t DTROS25:1;    /* Channel 25 Data Transfer Overflow Status */
                vuint32_t DTROS24:1;    /* Channel 24 Data Transfer Overflow Status */
                vuint32_t DTROS23:1;    /* Channel 23 Data Transfer Overflow Status */
                vuint32_t DTROS22:1;    /* Channel 22 Data Transfer Overflow Status */
                vuint32_t DTROS21:1;    /* Channel 21 Data Transfer Overflow Status */
                vuint32_t DTROS20:1;    /* Channel 20 Data Transfer Overflow Status */
                vuint32_t DTROS19:1;    /* Channel 19 Data Transfer Overflow Status */
                vuint32_t DTROS18:1;    /* Channel 18 Data Transfer Overflow Status */
                vuint32_t DTROS17:1;    /* Channel 17 Data Transfer Overflow Status */
                vuint32_t DTROS16:1;    /* Channel 16 Data Transfer Overflow Status */
                vuint32_t DTROS15:1;    /* Channel 15 Data Transfer Overflow Status */
                vuint32_t DTROS14:1;    /* Channel 14 Data Transfer Overflow Status */
                vuint32_t DTROS13:1;    /* Channel 13 Data Transfer Overflow Status */
                vuint32_t DTROS12:1;    /* Channel 12 Data Transfer Overflow Status */
                vuint32_t DTROS11:1;    /* Channel 11 Data Transfer Overflow Status */
                vuint32_t DTROS10:1;    /* Channel 10 Data Transfer Overflow Status */
                vuint32_t DTROS9:1;     /* Channel 9 Data Transfer Overflow Status */
                vuint32_t DTROS8:1;     /* Channel 8 Data Transfer Overflow Status */
                vuint32_t DTROS7:1;     /* Channel 7 Data Transfer Overflow Status */
                vuint32_t DTROS6:1;     /* Channel 6 Data Transfer Overflow Status */
                vuint32_t DTROS5:1;     /* Channel 5 Data Transfer Overflow Status */
                vuint32_t DTROS4:1;     /* Channel 4 Data Transfer Overflow Status */
                vuint32_t DTROS3:1;     /* Channel 3 Data Transfer Overflow Status */
                vuint32_t DTROS2:1;     /* Channel 2 Data Transfer Overflow Status */
                vuint32_t DTROS1:1;     /* Channel 1 Data Transfer Overflow Status */
                vuint32_t DTROS0:1;     /* Channel 0 Data Transfer Overflow Status */
            } B;
        } CDTROSR_B;
        
        uint32_t eTPU_reserved0238[2];  /* 0x0238-0x023F */
        
        union {                 /* ETPU_A Channel Interruput Enable */
            vuint32_t R;
            struct {
                vuint32_t CIE31:1;      /* Channel 31 Interruput Enable */
                vuint32_t CIE30:1;      /* Channel 30 Interruput Enable */
                vuint32_t CIE29:1;      /* Channel 29 Interruput Enable */
                vuint32_t CIE28:1;      /* Channel 28 Interruput Enable */
                vuint32_t CIE27:1;      /* Channel 27 Interruput Enable */
                vuint32_t CIE26:1;      /* Channel 26 Interruput Enable */
                vuint32_t CIE25:1;      /* Channel 25 Interruput Enable */
                vuint32_t CIE24:1;      /* Channel 24 Interruput Enable */
                vuint32_t CIE23:1;      /* Channel 23 Interruput Enable */
                vuint32_t CIE22:1;      /* Channel 22 Interruput Enable */
                vuint32_t CIE21:1;      /* Channel 21 Interruput Enable */
                vuint32_t CIE20:1;      /* Channel 20 Interruput Enable */
                vuint32_t CIE19:1;      /* Channel 19 Interruput Enable */
                vuint32_t CIE18:1;      /* Channel 18 Interruput Enable */
                vuint32_t CIE17:1;      /* Channel 17 Interruput Enable */
                vuint32_t CIE16:1;      /* Channel 16 Interruput Enable */
                vuint32_t CIE15:1;      /* Channel 15 Interruput Enable */
                vuint32_t CIE14:1;      /* Channel 14 Interruput Enable */
                vuint32_t CIE13:1;      /* Channel 13 Interruput Enable */
                vuint32_t CIE12:1;      /* Channel 12 Interruput Enable */
                vuint32_t CIE11:1;      /* Channel 11 Interruput Enable */
                vuint32_t CIE10:1;      /* Channel 10 Interruput Enable */
                vuint32_t CIE9:1;       /* Channel 9 Interruput Enable */
                vuint32_t CIE8:1;       /* Channel 8 Interruput Enable */
                vuint32_t CIE7:1;       /* Channel 7 Interruput Enable */
                vuint32_t CIE6:1;       /* Channel 6 Interruput Enable */
                vuint32_t CIE5:1;       /* Channel 5 Interruput Enable */
                vuint32_t CIE4:1;       /* Channel 4 Interruput Enable */
                vuint32_t CIE3:1;       /* Channel 3 Interruput Enable */
                vuint32_t CIE2:1;       /* Channel 2 Interruput Enable */
                vuint32_t CIE1:1;       /* Channel 1 Interruput Enable */
                vuint32_t CIE0:1;       /* Channel 0 Interruput Enable */
            } B;
        } CIER_A;
        
        union {                 /* ETPU_B Channel Interruput Enable */
            vuint32_t R;
            struct {
                vuint32_t CIE31:1;      /* Channel 31 Interruput Enable */
                vuint32_t CIE30:1;      /* Channel 30 Interruput Enable */
                vuint32_t CIE29:1;      /* Channel 29 Interruput Enable */
                vuint32_t CIE28:1;      /* Channel 28 Interruput Enable */
                vuint32_t CIE27:1;      /* Channel 27 Interruput Enable */
                vuint32_t CIE26:1;      /* Channel 26 Interruput Enable */
                vuint32_t CIE25:1;      /* Channel 25 Interruput Enable */
                vuint32_t CIE24:1;      /* Channel 24 Interruput Enable */
                vuint32_t CIE23:1;      /* Channel 23 Interruput Enable */
                vuint32_t CIE22:1;      /* Channel 22 Interruput Enable */
                vuint32_t CIE21:1;      /* Channel 21 Interruput Enable */
                vuint32_t CIE20:1;      /* Channel 20 Interruput Enable */
                vuint32_t CIE19:1;      /* Channel 19 Interruput Enable */
                vuint32_t CIE18:1;      /* Channel 18 Interruput Enable */
                vuint32_t CIE17:1;      /* Channel 17 Interruput Enable */
                vuint32_t CIE16:1;      /* Channel 16 Interruput Enable */
                vuint32_t CIE15:1;      /* Channel 15 Interruput Enable */
                vuint32_t CIE14:1;      /* Channel 14 Interruput Enable */
                vuint32_t CIE13:1;      /* Channel 13 Interruput Enable */
                vuint32_t CIE12:1;      /* Channel 12 Interruput Enable */
                vuint32_t CIE11:1;      /* Channel 11 Interruput Enable */
                vuint32_t CIE10:1;      /* Channel 10 Interruput Enable */
                vuint32_t CIE9:1;       /* Channel 9 Interruput Enable */
                vuint32_t CIE8:1;       /* Channel 8 Interruput Enable */
                vuint32_t CIE7:1;       /* Channel 7 Interruput Enable */
                vuint32_t CIE6:1;       /* Channel 6 Interruput Enable */
                vuint32_t CIE5:1;       /* Channel 5 Interruput Enable */
                vuint32_t CIE4:1;       /* Channel 4 Interruput Enable */
                vuint32_t CIE3:1;       /* Channel 3 Interruput Enable */
                vuint32_t CIE2:1;       /* Channel 2 Interruput Enable */
                vuint32_t CIE1:1;       /* Channel 1 Interruput Enable */
                vuint32_t CIE0:1;       /* Channel 0 Interruput Enable */
            } B;
        } CIER_B;
        
        uint32_t eTPU_reserved0248[2];  /* 0x0248-0x024F */
        
        union {                 /* ETPU_A Channel Data Transfer Request Enable */
            vuint32_t R;
            struct {
                vuint32_t DTRE31:1;     /* Channel 31 Data Transfer Request Enable */
                vuint32_t DTRE30:1;     /* Channel 30 Data Transfer Request Enable */
                vuint32_t DTRE29:1;     /* Channel 29 Data Transfer Request Enable */
                vuint32_t DTRE28:1;     /* Channel 28 Data Transfer Request Enable */
                vuint32_t DTRE27:1;     /* Channel 27 Data Transfer Request Enable */
                vuint32_t DTRE26:1;     /* Channel 26 Data Transfer Request Enable */
                vuint32_t DTRE25:1;     /* Channel 25 Data Transfer Request Enable */
                vuint32_t DTRE24:1;     /* Channel 24 Data Transfer Request Enable */
                vuint32_t DTRE23:1;     /* Channel 23 Data Transfer Request Enable */
                vuint32_t DTRE22:1;     /* Channel 22 Data Transfer Request Enable */
                vuint32_t DTRE21:1;     /* Channel 21 Data Transfer Request Enable */
                vuint32_t DTRE20:1;     /* Channel 20 Data Transfer Request Enable */
                vuint32_t DTRE19:1;     /* Channel 19 Data Transfer Request Enable */
                vuint32_t DTRE18:1;     /* Channel 18 Data Transfer Request Enable */
                vuint32_t DTRE17:1;     /* Channel 17 Data Transfer Request Enable */
                vuint32_t DTRE16:1;     /* Channel 16 Data Transfer Request Enable */
                vuint32_t DTRE15:1;     /* Channel 15 Data Transfer Request Enable */
                vuint32_t DTRE14:1;     /* Channel 14 Data Transfer Request Enable */
                vuint32_t DTRE13:1;     /* Channel 13 Data Transfer Request Enable */
                vuint32_t DTRE12:1;     /* Channel 12 Data Transfer Request Enable */
                vuint32_t DTRE11:1;     /* Channel 11 Data Transfer Request Enable */
                vuint32_t DTRE10:1;     /* Channel 10 Data Transfer Request Enable */
                vuint32_t DTRE9:1;      /* Channel 9 Data Transfer Request Enable */
                vuint32_t DTRE8:1;      /* Channel 8 Data Transfer Request Enable */
                vuint32_t DTRE7:1;      /* Channel 7 Data Transfer Request Enable */
                vuint32_t DTRE6:1;      /* Channel 6 Data Transfer Request Enable */
                vuint32_t DTRE5:1;      /* Channel 5 Data Transfer Request Enable */
                vuint32_t DTRE4:1;      /* Channel 4 Data Transfer Request Enable */
                vuint32_t DTRE3:1;      /* Channel 3 Data Transfer Request Enable */
                vuint32_t DTRE2:1;      /* Channel 2 Data Transfer Request Enable */
                vuint32_t DTRE1:1;      /* Channel 1 Data Transfer Request Enable */
                vuint32_t DTRE0:1;      /* Channel 0 Data Transfer Request Enable */
            } B;
        } CDTRER_A;
        
        union {                 /* ETPU_B Channel Data Transfer Request Enable */
            vuint32_t R;
            struct {
                vuint32_t DTRE31:1;     /* Channel 31 Data Transfer Request Enable */
                vuint32_t DTRE30:1;     /* Channel 30 Data Transfer Request Enable */
                vuint32_t DTRE29:1;     /* Channel 29 Data Transfer Request Enable */
                vuint32_t DTRE28:1;     /* Channel 28 Data Transfer Request Enable */
                vuint32_t DTRE27:1;     /* Channel 27 Data Transfer Request Enable */
                vuint32_t DTRE26:1;     /* Channel 26 Data Transfer Request Enable */
                vuint32_t DTRE25:1;     /* Channel 25 Data Transfer Request Enable */
                vuint32_t DTRE24:1;     /* Channel 24 Data Transfer Request Enable */
                vuint32_t DTRE23:1;     /* Channel 23 Data Transfer Request Enable */
                vuint32_t DTRE22:1;     /* Channel 22 Data Transfer Request Enable */
                vuint32_t DTRE21:1;     /* Channel 21 Data Transfer Request Enable */
                vuint32_t DTRE20:1;     /* Channel 20 Data Transfer Request Enable */
                vuint32_t DTRE19:1;     /* Channel 19 Data Transfer Request Enable */
                vuint32_t DTRE18:1;     /* Channel 18 Data Transfer Request Enable */
                vuint32_t DTRE17:1;     /* Channel 17 Data Transfer Request Enable */
                vuint32_t DTRE16:1;     /* Channel 16 Data Transfer Request Enable */
                vuint32_t DTRE15:1;     /* Channel 15 Data Transfer Request Enable */
                vuint32_t DTRE14:1;     /* Channel 14 Data Transfer Request Enable */
                vuint32_t DTRE13:1;     /* Channel 13 Data Transfer Request Enable */
                vuint32_t DTRE12:1;     /* Channel 12 Data Transfer Request Enable */
                vuint32_t DTRE11:1;     /* Channel 11 Data Transfer Request Enable */
                vuint32_t DTRE10:1;     /* Channel 10 Data Transfer Request Enable */
                vuint32_t DTRE9:1;      /* Channel 9 Data Transfer Request Enable */
                vuint32_t DTRE8:1;      /* Channel 8 Data Transfer Request Enable */
                vuint32_t DTRE7:1;      /* Channel 7 Data Transfer Request Enable */
                vuint32_t DTRE6:1;      /* Channel 6 Data Transfer Request Enable */
                vuint32_t DTRE5:1;      /* Channel 5 Data Transfer Request Enable */
                vuint32_t DTRE4:1;      /* Channel 4 Data Transfer Request Enable */
                vuint32_t DTRE3:1;      /* Channel 3 Data Transfer Request Enable */
                vuint32_t DTRE2:1;      /* Channel 2 Data Transfer Request Enable */
                vuint32_t DTRE1:1;      /* Channel 1 Data Transfer Request Enable */
                vuint32_t DTRE0:1;      /* Channel 0 Data Transfer Request Enable */
            } B;
        } CDTRER_B;
        
        uint32_t eTPU_reserved0258[2];  /* 0x0258-0x025F */
        
        union {                 /* Watchdog Status Register A */
            vuint32_t R;
            struct {
                vuint32_t WDS31:1;
                vuint32_t WDS30:1;
                vuint32_t WDS29:1;
                vuint32_t WDS28:1;
                vuint32_t WDS27:1;
                vuint32_t WDS26:1;
                vuint32_t WDS25:1;
                vuint32_t WDS24:1;
                vuint32_t WDS23:1;
                vuint32_t WDS22:1;
                vuint32_t WDS21:1;
                vuint32_t WDS20:1;
                vuint32_t WDS19:1;
                vuint32_t WDS18:1;
                vuint32_t WDS17:1;
                vuint32_t WDS16:1;
                vuint32_t WDS15:1;
                vuint32_t WDS14:1;
                vuint32_t WDS13:1;
                vuint32_t WDS12:1;
                vuint32_t WDS11:1;
                vuint32_t WDS10:1;
                vuint32_t WDS9:1;
                vuint32_t WDS8:1;
                vuint32_t WDS7:1;
                vuint32_t WDS6:1;
                vuint32_t WDS5:1;
                vuint32_t WDS4:1;
                vuint32_t WDS3:1;
                vuint32_t WDS2:1;
                vuint32_t WDS1:1;
                vuint32_t WDS0:1;
            } B;
        } WDSR_A;
        
        union {                 /* Watchdog Status Register B */
            vuint32_t R;
            struct {
                vuint32_t WDS31:1;
                vuint32_t WDS30:1;
                vuint32_t WDS29:1;
                vuint32_t WDS28:1;
                vuint32_t WDS27:1;
                vuint32_t WDS26:1;
                vuint32_t WDS25:1;
                vuint32_t WDS24:1;
                vuint32_t WDS23:1;
                vuint32_t WDS22:1;
                vuint32_t WDS21:1;
                vuint32_t WDS20:1;
                vuint32_t WDS19:1;
                vuint32_t WDS18:1;
                vuint32_t WDS17:1;
                vuint32_t WDS16:1;
                vuint32_t WDS15:1;
                vuint32_t WDS14:1;
                vuint32_t WDS13:1;
                vuint32_t WDS12:1;
                vuint32_t WDS11:1;
                vuint32_t WDS10:1;
                vuint32_t WDS9:1;
                vuint32_t WDS8:1;
                vuint32_t WDS7:1;
                vuint32_t WDS6:1;
                vuint32_t WDS5:1;
                vuint32_t WDS4:1;
                vuint32_t WDS3:1;
                vuint32_t WDS2:1;
                vuint32_t WDS1:1;
                vuint32_t WDS0:1;
            } B;
        } WDSR_B;
        
        uint32_t eTPU_reserved0268[6];  /* 0x0268-0x027F */
        
        union {                 /* ETPU_A Channel Pending Service Status */
            vuint32_t R;
            struct {
                vuint32_t SR31:1;       /* Channel 31 Pending Service Status */
                vuint32_t SR30:1;       /* Channel 30 Pending Service Status */
                vuint32_t SR29:1;       /* Channel 29 Pending Service Status */
                vuint32_t SR28:1;       /* Channel 28 Pending Service Status */
                vuint32_t SR27:1;       /* Channel 27 Pending Service Status */
                vuint32_t SR26:1;       /* Channel 26 Pending Service Status */
                vuint32_t SR25:1;       /* Channel 25 Pending Service Status */
                vuint32_t SR24:1;       /* Channel 24 Pending Service Status */
                vuint32_t SR23:1;       /* Channel 23 Pending Service Status */
                vuint32_t SR22:1;       /* Channel 22 Pending Service Status */
                vuint32_t SR21:1;       /* Channel 21 Pending Service Status */
                vuint32_t SR20:1;       /* Channel 20 Pending Service Status */
                vuint32_t SR19:1;       /* Channel 19 Pending Service Status */
                vuint32_t SR18:1;       /* Channel 18 Pending Service Status */
                vuint32_t SR17:1;       /* Channel 17 Pending Service Status */
                vuint32_t SR16:1;       /* Channel 16 Pending Service Status */
                vuint32_t SR15:1;       /* Channel 15 Pending Service Status */
                vuint32_t SR14:1;       /* Channel 14 Pending Service Status */
                vuint32_t SR13:1;       /* Channel 13 Pending Service Status */
                vuint32_t SR12:1;       /* Channel 12 Pending Service Status */
                vuint32_t SR11:1;       /* Channel 11 Pending Service Status */
                vuint32_t SR10:1;       /* Channel 10 Pending Service Status */
                vuint32_t SR9:1;        /* Channel 9 Pending Service Status */
                vuint32_t SR8:1;        /* Channel 8 Pending Service Status */
                vuint32_t SR7:1;        /* Channel 7 Pending Service Status */
                vuint32_t SR6:1;        /* Channel 6 Pending Service Status */
                vuint32_t SR5:1;        /* Channel 5 Pending Service Status */
                vuint32_t SR4:1;        /* Channel 4 Pending Service Status */
                vuint32_t SR3:1;        /* Channel 3 Pending Service Status */
                vuint32_t SR2:1;        /* Channel 2 Pending Service Status */
                vuint32_t SR1:1;        /* Channel 1 Pending Service Status */
                vuint32_t SR0:1;        /* Channel 0 Pending Service Status */
            } B;
        } CPSSR_A;
        
        union {                 /* ETPU_B Channel Pending Service Status */
            vuint32_t R;
            struct {
                vuint32_t SR31:1;       /* Channel 31 Pending Service Status */
                vuint32_t SR30:1;       /* Channel 30 Pending Service Status */
                vuint32_t SR29:1;       /* Channel 29 Pending Service Status */
                vuint32_t SR28:1;       /* Channel 28 Pending Service Status */
                vuint32_t SR27:1;       /* Channel 27 Pending Service Status */
                vuint32_t SR26:1;       /* Channel 26 Pending Service Status */
                vuint32_t SR25:1;       /* Channel 25 Pending Service Status */
                vuint32_t SR24:1;       /* Channel 24 Pending Service Status */
                vuint32_t SR23:1;       /* Channel 23 Pending Service Status */
                vuint32_t SR22:1;       /* Channel 22 Pending Service Status */
                vuint32_t SR21:1;       /* Channel 21 Pending Service Status */
                vuint32_t SR20:1;       /* Channel 20 Pending Service Status */
                vuint32_t SR19:1;       /* Channel 19 Pending Service Status */
                vuint32_t SR18:1;       /* Channel 18 Pending Service Status */
                vuint32_t SR17:1;       /* Channel 17 Pending Service Status */
                vuint32_t SR16:1;       /* Channel 16 Pending Service Status */
                vuint32_t SR15:1;       /* Channel 15 Pending Service Status */
                vuint32_t SR14:1;       /* Channel 14 Pending Service Status */
                vuint32_t SR13:1;       /* Channel 13 Pending Service Status */
                vuint32_t SR12:1;       /* Channel 12 Pending Service Status */
                vuint32_t SR11:1;       /* Channel 11 Pending Service Status */
                vuint32_t SR10:1;       /* Channel 10 Pending Service Status */
                vuint32_t SR9:1;        /* Channel 9 Pending Service Status */
                vuint32_t SR8:1;        /* Channel 8 Pending Service Status */
                vuint32_t SR7:1;        /* Channel 7 Pending Service Status */
                vuint32_t SR6:1;        /* Channel 6 Pending Service Status */
                vuint32_t SR5:1;        /* Channel 5 Pending Service Status */
                vuint32_t SR4:1;        /* Channel 4 Pending Service Status */
                vuint32_t SR3:1;        /* Channel 3 Pending Service Status */
                vuint32_t SR2:1;        /* Channel 2 Pending Service Status */
                vuint32_t SR1:1;        /* Channel 1 Pending Service Status */
                vuint32_t SR0:1;        /* Channel 0 Pending Service Status */
            } B;
        } CPSSR_B;
        
        uint32_t eTPU_reserved0288[2];  /* 0x0288-0x028F */
        
        union {                 /* ETPU_A Channel Service Status */
            vuint32_t R;
            struct {
                vuint32_t SS31:1;       /* Channel 31 Service Status */
                vuint32_t SS30:1;       /* Channel 30 Service Status */
                vuint32_t SS29:1;       /* Channel 29 Service Status */
                vuint32_t SS28:1;       /* Channel 28 Service Status */
                vuint32_t SS27:1;       /* Channel 27 Service Status */
                vuint32_t SS26:1;       /* Channel 26 Service Status */
                vuint32_t SS25:1;       /* Channel 25 Service Status */
                vuint32_t SS24:1;       /* Channel 24 Service Status */
                vuint32_t SS23:1;       /* Channel 23 Service Status */
                vuint32_t SS22:1;       /* Channel 22 Service Status */
                vuint32_t SS21:1;       /* Channel 21 Service Status */
                vuint32_t SS20:1;       /* Channel 20 Service Status */
                vuint32_t SS19:1;       /* Channel 19 Service Status */
                vuint32_t SS18:1;       /* Channel 18 Service Status */
                vuint32_t SS17:1;       /* Channel 17 Service Status */
                vuint32_t SS16:1;       /* Channel 16 Service Status */
                vuint32_t SS15:1;       /* Channel 15 Service Status */
                vuint32_t SS14:1;       /* Channel 14 Service Status */
                vuint32_t SS13:1;       /* Channel 13 Service Status */
                vuint32_t SS12:1;       /* Channel 12 Service Status */
                vuint32_t SS11:1;       /* Channel 11 Service Status */
                vuint32_t SS10:1;       /* Channel 10 Service Status */
                vuint32_t SS9:1;        /* Channel 9 Service Status */
                vuint32_t SS8:1;        /* Channel 8 Service Status */
                vuint32_t SS7:1;        /* Channel 7 Service Status */
                vuint32_t SS6:1;        /* Channel 6 Service Status */
                vuint32_t SS5:1;        /* Channel 5 Service Status */
                vuint32_t SS4:1;        /* Channel 4 Service Status */
                vuint32_t SS3:1;        /* Channel 3 Service Status */
                vuint32_t SS2:1;        /* Channel 2 Service Status */
                vuint32_t SS1:1;        /* Channel 1 Service Status */
                vuint32_t SS0:1;        /* Channel 0 Service Status */
            } B;
        } CSSR_A;
        
        union {                 /* ETPU_B Channel Service Status */
            vuint32_t R;
            struct {
                vuint32_t SS31:1;       /* Channel 31 Service Status */
                vuint32_t SS30:1;       /* Channel 30 Service Status */
                vuint32_t SS29:1;       /* Channel 29 Service Status */
                vuint32_t SS28:1;       /* Channel 28 Service Status */
                vuint32_t SS27:1;       /* Channel 27 Service Status */
                vuint32_t SS26:1;       /* Channel 26 Service Status */
                vuint32_t SS25:1;       /* Channel 25 Service Status */
                vuint32_t SS24:1;       /* Channel 24 Service Status */
                vuint32_t SS23:1;       /* Channel 23 Service Status */
                vuint32_t SS22:1;       /* Channel 22 Service Status */
                vuint32_t SS21:1;       /* Channel 21 Service Status */
                vuint32_t SS20:1;       /* Channel 20 Service Status */
                vuint32_t SS19:1;       /* Channel 19 Service Status */
                vuint32_t SS18:1;       /* Channel 18 Service Status */
                vuint32_t SS17:1;       /* Channel 17 Service Status */
                vuint32_t SS16:1;       /* Channel 16 Service Status */
                vuint32_t SS15:1;       /* Channel 15 Service Status */
                vuint32_t SS14:1;       /* Channel 14 Service Status */
                vuint32_t SS13:1;       /* Channel 13 Service Status */
                vuint32_t SS12:1;       /* Channel 12 Service Status */
                vuint32_t SS11:1;       /* Channel 11 Service Status */
                vuint32_t SS10:1;       /* Channel 10 Service Status */
                vuint32_t SS9:1;        /* Channel 9 Service Status */
                vuint32_t SS8:1;        /* Channel 8 Service Status */
                vuint32_t SS7:1;        /* Channel 7 Service Status */
                vuint32_t SS6:1;        /* Channel 6 Service Status */
                vuint32_t SS5:1;        /* Channel 5 Service Status */
                vuint32_t SS4:1;        /* Channel 4 Service Status */
                vuint32_t SS3:1;        /* Channel 3 Service Status */
                vuint32_t SS2:1;        /* Channel 2 Service Status */
                vuint32_t SS1:1;        /* Channel 1 Service Status */
                vuint32_t SS0:1;        /* Channel 0 Service Status */
            } B;
        } CSSR_B;
        
        uint32_t eTPU_reserved0298[2];  /* 0x0298-0x029F */
        
        uint32_t eTPU_reserved02A0[88];  /* 0x02A0-0x03FF */

/*****************************Channels********************************/

        struct {
            union {    /* Channel Configuration Register */
                vuint32_t R;
                struct {
                    vuint32_t CIE:1;    /* Channel Interruput Enable */
                    vuint32_t DTRE:1;   /* Data Transfer Request Enable */
                    vuint32_t CPR:2;    /* Channel Priority */
                    vuint32_t:2;
                    vuint32_t ETPD:1;
                    vuint32_t ETCS:1;   /* Entry Table Condition Select */
                    vuint32_t:3;
                    vuint32_t CFS:5;    /* Channel Function Select */
                    vuint32_t ODIS:1;   /* Output disable */
                    vuint32_t OPOL:1;   /* output polarity */
                    vuint32_t:3;
                    vuint32_t CPBA:11;  /* Channel Parameter Base Address */
                } B;
            } CR;
            
            union {    /* Channel Status Control Register */
                vuint32_t R;
                struct {
                    vuint32_t CIS:1;    /* Channel Interruput Status */
                    vuint32_t CIOS:1;   /* Channel Interruput Overflow Status */
                    vuint32_t:6;
                    vuint32_t DTRS:1;   /* Data Transfer Status */
                    vuint32_t DTROS:1;  /* Data Transfer Overflow Status */
                    vuint32_t:6;
                    vuint32_t IPS:1;    /* Input Pin State */
                    vuint32_t OPS:1;    /* Output Pin State */
                    vuint32_t OBE:1;    /* Output Buffer Enable */
                    vuint32_t:11;
                    vuint32_t FM1:1;    /* Function mode */
                    vuint32_t FM0:1;    /* Function mode */
                } B;
            } SCR;
            
            union {    /* Channel Host Service Request Register */
                vuint32_t R;
                struct {
                    vuint32_t:29;       /* Host Service Request */
                    vuint32_t HSR:3;
                } B;
            } HSRR;
            
            uint32_t eTPU_ch_reserved00C;  /* channel offset 0x00C-0x00F */
            
        } CHAN[127];
        
        uint32_t eTPU_reserved1000[7168];  /* 0x1000-0x7FFF */
        
    };

/****************************************************************************/
/*                          MODULE : PIT / RTI                              */
/****************************************************************************/

    struct PIT_tag {
        union {                  /* Module Configuration Register */
            vuint32_t R;
            struct {
                vuint32_t:29;
                vuint32_t MDIS_RTI:1;
                vuint32_t MDIS:1;
                vuint32_t FRZ:1;
            } B;
        } MCR;
   
        uint32_t PIT_reserved0004[59];  /* 0x0004-0x00EF */
        
        struct {
            union {
                vuint32_t R;    /* <URM>TSVn</URM> */
            } LDVAL;            /* Timer Load Value Register */

            union {
                vuint32_t R;    /* <URM>TVLn</URM> */
            } CVAL;             /* Current Timer Value Register */

            union {
                vuint32_t R;
                struct {
                    vuint32_t:30;
                    vuint32_t TIE:1;
                    vuint32_t TEN:1;
                } B;
            } TCTRL;            /* Timer Control Register */

            union {
                vuint32_t R;
                struct {
                    vuint32_t:31;
                    vuint32_t TIF:1;
                } B;
            } TFLG;             /* Timer Flag Register */
        } RTI;                  /* RTI Channel */

        struct {
            union {
                vuint32_t R;
                struct {
                    vuint32_t TSV:32;
                } B;
            } LDVAL;
            
            union {
                vuint32_t R;
                struct {
                    vuint32_t TVL:32;
                } B;
            } CVAL;
            
            union {
                vuint32_t R;
                struct {
                    vuint32_t:30;
                    vuint32_t TIE:1;
                    vuint32_t TEN:1;
                } B;
            } TCTRL;
            
            union {
                vuint32_t R;
                struct {
                    vuint32_t:31;
                    vuint32_t TIF:1;
                } B;
            } TFLG;
        } CH[4];

        uint32_t PIT_reserved00140[4016];  /* 0x0140-0x3FFF */
    };

/****************************************************************************/
/*                          MODULE : XBAR CrossBar                          */
/****************************************************************************/

    struct XBAR_tag {
    
        union {                 /* Master Priority Register for Slave Port 0 */
            vuint32_t R;
            struct {
                vuint32_t:1;
                vuint32_t MSTR7:3; /* EBI (development bus) */
                vuint32_t:1;
                vuint32_t MSTR6:3; /* FlexRay */
                vuint32_t:1;
                vuint32_t MSTR5:3; /* eDMA_B */
                vuint32_t:1;
                vuint32_t MSTR4:3; /* eDMA_A */
                vuint32_t:1;
                vuint32_t MSTR3:3; /* !!! Unsupported in Mamba !!! - Legacy FEC */
                vuint32_t:1;
                vuint32_t MSTR2:3; /* !!! Unsupported in Mamba !!! - Legacy EBI */
                vuint32_t:1;
                vuint32_t MSTR1:3; /* e200z7 core-Data, and Nexus 3 - Legacy was eDMA_A */
                vuint32_t:1;
                vuint32_t MSTR0:3; /* e200z7 core-CPU Instruction - Legacy was z6 core-Instruction/Data & Nexus */
            } B;
        } MPR0;
        
        uint32_t XBAR_reserved0004[3];  /* 0x0004-0x000F */
        
        union {               /* General Purpose Control Register for Slave Port 0 */
            vuint32_t R;
            struct {
                vuint32_t RO:1;
                vuint32_t:21;
                vuint32_t ARB:2;
                vuint32_t:2;
                vuint32_t PCTL:2;
                vuint32_t:1;
                vuint32_t PARK:3;
            } B;
        } SGPCR0;
        
        uint32_t XBAR_reserved0014[59];  /* 0x0014-0x00FF */
        
        union {                 /* Master Priority Register for Slave Port 1 */
            vuint32_t R;
            struct {
                vuint32_t:1;
                vuint32_t MSTR7:3; /* EBI (development bus) */
                vuint32_t:1;
                vuint32_t MSTR6:3; /* FlexRay */
                vuint32_t:1;
                vuint32_t MSTR5:3; /* eDMA_B */
                vuint32_t:1;
                vuint32_t MSTR4:3; /* eDMA_A */
                vuint32_t:1;
                vuint32_t MSTR3:3; /* !!! Unsupported in Mamba !!! - Legacy FEC */
                vuint32_t:1;
                vuint32_t MSTR2:3; /* !!! Unsupported in Mamba !!! - Legacy EBI */
                vuint32_t:1;
                vuint32_t MSTR1:3; /* e200z7 core-Data, and Nexus 3 - Legacy was eDMA_A */
                vuint32_t:1;
                vuint32_t MSTR0:3; /* e200z7 core-CPU Instruction - Legacy was z6 core-Instruction/Data & Nexus */
            } B;
        } MPR1;
        
        uint32_t XBAR_reserved0104[3];  /* 0x0104-0x010F */
        
        union {               /* General Purpose Control Register for Slave Port 1 */
            vuint32_t R;
            struct {
                vuint32_t RO:1;
                vuint32_t:21;
                vuint32_t ARB:2;
                vuint32_t:2;
                vuint32_t PCTL:2;
                vuint32_t:1;
                vuint32_t PARK:3;
            } B;
        } SGPCR1;
        
        uint32_t XBAR_reserved0114[59];  /* 0x0114-0x01FF */
        
        union {                 /* Master Priority Register for Slave Port 2 */
            vuint32_t R;
            struct {
                vuint32_t:1;
                vuint32_t MSTR7:3; /* EBI (development bus) */
                vuint32_t:1;
                vuint32_t MSTR6:3; /* FlexRay */
                vuint32_t:1;
                vuint32_t MSTR5:3; /* eDMA_B */
                vuint32_t:1;
                vuint32_t MSTR4:3; /* eDMA_A */
                vuint32_t:1;
                vuint32_t MSTR3:3; /* !!! Unsupported in Mamba !!! - Legacy FEC */
                vuint32_t:1;
                vuint32_t MSTR2:3; /* !!! Unsupported in Mamba !!! - Legacy EBI */
                vuint32_t:1;
                vuint32_t MSTR1:3; /* e200z7 core-Data, and Nexus 3 - Legacy was eDMA_A */
                vuint32_t:1;
                vuint32_t MSTR0:3; /* e200z7 core-CPU Instruction - Legacy was z6 core-Instruction/Data & Nexus */
            } B;
        } MPR2;
        
        uint32_t XBAR_reserved0204[3];  /* 0x0204-0x020F */
        
        union {               /* General Purpose Control Register for Slave Port 2 */
            vuint32_t R;
            struct {
                vuint32_t RO:1;
                vuint32_t:21;
                vuint32_t ARB:2;
                vuint32_t:2;
                vuint32_t PCTL:2;
                vuint32_t:1;
                vuint32_t PARK:3;
            } B;
        } SGPCR2;
        
        uint32_t XBAR_reserved0214[59];  /* 0x0214-0x02FF */
        
        uint32_t XBAR_reserved0300[64];  /* 0x0300-0x03FF */
        
        uint32_t XBAR_reserved0400[64];  /* 0x0400-0x04FF */
        
        uint32_t XBAR_reserved0500[64];  /* 0x0500-0x05FF */
        
        union {                 /* Master Priority Register for Slave Port 6 */
            vuint32_t R;
            struct {
                vuint32_t:1;
                vuint32_t MSTR7:3; /* EBI (development bus) */
                vuint32_t:1;
                vuint32_t MSTR6:3; /* FlexRay */
                vuint32_t:1;
                vuint32_t MSTR5:3; /* eDMA_B */
                vuint32_t:1;
                vuint32_t MSTR4:3; /* eDMA_A */
                vuint32_t:1;
                vuint32_t MSTR3:3; /* !!! Unsupported in Mamba !!! - Legacy FEC */
                vuint32_t:1;
                vuint32_t MSTR2:3; /* !!! Unsupported in Mamba !!! - Legacy EBI */
                vuint32_t:1;
                vuint32_t MSTR1:3; /* e200z7 core-Data, and Nexus 3 - Legacy was eDMA_A */
                vuint32_t:1;
                vuint32_t MSTR0:3; /* e200z7 core-CPU Instruction - Legacy was z6 core-Instruction/Data & Nexus */
            } B;
        } MPR6;
        
        uint32_t XBAR_reserved604[3];  /* 0x0604-0x060F */
        
        union {               /* General Purpose Control Register for Slave Port 6 */
            vuint32_t R;
            struct {
                vuint32_t RO:1;
                vuint32_t:21;
                vuint32_t ARB:2;
                vuint32_t:2;
                vuint32_t PCTL:2;
                vuint32_t:1;
                vuint32_t PARK:3;
            } B;
        } SGPCR6;
        
        uint32_t XBAR_reserved0614[59];  /* 0x0614-0x06FF */
        
        union {                 /* Master Priority Register for Slave Port 7 */
            vuint32_t R;
            struct {
                vuint32_t:1;
                vuint32_t MSTR7:3; /* EBI (development bus) */
                vuint32_t:1;
                vuint32_t MSTR6:3; /* FlexRay */
                vuint32_t:1;
                vuint32_t MSTR5:3; /* eDMA_B */
                vuint32_t:1;
                vuint32_t MSTR4:3; /* eDMA_A */
                vuint32_t:1;
                vuint32_t MSTR3:3; /* !!! Unsupported in Mamba !!! - Legacy FEC */
                vuint32_t:1;
                vuint32_t MSTR2:3; /* !!! Unsupported in Mamba !!! - Legacy EBI */
                vuint32_t:1;
                vuint32_t MSTR1:3; /* e200z7 core-Data, and Nexus 3 - Legacy was eDMA_A */
                vuint32_t:1;
                vuint32_t MSTR0:3; /* e200z7 core-CPU Instruction - Legacy was z6 core-Instruction/Data & Nexus */
            } B;
        } MPR7;
        
        uint32_t XBAR_reserved704[3];  /* 0x0704-0x070F */
        
        union {
            vuint32_t R;
            struct {
                vuint32_t RO:1;
                  vuint32_t:21;
                vuint32_t ARB:2;
                  vuint32_t:2;
                vuint32_t PCTL:2;
                  vuint32_t:1;
                vuint32_t PARK:3;
            } B;
        } SGPCR7;               /* General Purpose Control Register for Slave Port 7 */
        
        uint32_t XBAR_reserved0714[59];  /* 0x0714-0x07FF */
        
        uint32_t XBAR_reserved0800[3584];  /* 0x0800-0x3FFF */
    };

/****************************************************************************/
/*                          MODULE : MPU                                    */
/****************************************************************************/

    struct MPU_tag {
    
        union {                 /* Module Control/Error Status Register */
            vuint32_t R;
            struct {
                vuint32_t SPERR:8;
                  vuint32_t:4;
                vuint32_t HRL:4;
                vuint32_t NSP:4;
                vuint32_t NRGD:4;
                  vuint32_t:7;
                vuint32_t VLD:1;
            } B;
        } CESR;
        
        uint32_t MPU_reserved0004[3]; /* 0x0004-0x000F */
        
        struct {
            union {             /* MPU Error Address Registers */
                vuint32_t R;
                struct {
                    vuint32_t EADDR:32;
                } B;
            } EAR;
            
            union {             /* MPU Error Detail Registers */
                vuint32_t R;
                struct {
                    vuint32_t EACD:16;
                    vuint32_t EPID:8;
                    vuint32_t EMN:4;
                    vuint32_t EATTR:3;
                    vuint32_t ERW:1;
                } B;
            } EDR;
        } PORT[3];
        
        uint32_t MPU_reserved0028[246];  /* 0x0028-0x03FF */
        
        struct {
            union {            /* Region Descriptor n Word 0 */
                vuint32_t R;
                struct {
                    vuint32_t SRTADDR:27;
                    vuint32_t:5;
                } B;
            } WORD0;
            
            union {            /* Region Descriptor n Word 1 */
                vuint32_t R;
                struct {
                    vuint32_t ENDADDR:27;
                    vuint32_t:5;
                } B;
            } WORD1;
            
            union {            /* Region Descriptor n Word 2 */
                vuint32_t R;
                struct {
                    vuint32_t M7RE:1;
                    vuint32_t M7WE:1;
                    vuint32_t M6RE:1;
                    vuint32_t M6WE:1;
                    vuint32_t M5RE:1;
                    vuint32_t M5WE:1;
                    vuint32_t M4RE:1;
                    vuint32_t M4WE:1;
                    vuint32_t: 18;
                    vuint32_t M0PE:1;
                    vuint32_t M0SM:2;
                    vuint32_t M0UM:3;
                } B;
            } WORD2;
            
            union {            /* Region Descriptor n Word 3 */
                vuint32_t R;
                struct {
                    vuint32_t PID:8;
                    vuint32_t PIDMASK:8;
                      vuint32_t:15;
                    vuint32_t VLD:1;
                } B;
            } WORD3;
        } RGD[16];
        
        uint32_t MPU_reserved0500[192];  /* 0x0500-0x07FF */
        
        union {           /* Region Descriptor Alternate Access Control n */
            vuint32_t R;
            struct {
                vuint32_t:6;
                vuint32_t M4RE:1;
                vuint32_t M4WE:1;
                vuint32_t M3PE:1;
                vuint32_t M3SM:2;
                vuint32_t M3UM:3;
                vuint32_t M2PE:1;
                vuint32_t M2SM:2;
                vuint32_t M2UM:3;
                vuint32_t M1PE:1;
                vuint32_t M1SM:2;
                vuint32_t M1UM:3;
                vuint32_t M0PE:1;
                vuint32_t M0SM:2;
                vuint32_t M0UM:3;
            } B;
        } RGDAAC[16];
        
        uint32_t MPU_reserved0840[3568];  /* 0x0840-0x3FFF */
    
    };

/****************************************************************************/
/*                     MODULE : SWT                                         */
/****************************************************************************/

    struct SWT_tag {
    
        union {                  /* Module Configuration Register */
            vuint32_t R;
            struct {
                vuint32_t MAP0:1;
                vuint32_t MAP1:1;
                vuint32_t:1;
                vuint32_t:1;
                vuint32_t MAP4:1;
                vuint32_t MAP5:1;
                vuint32_t MAP6:1;
                vuint32_t MAP7:1;
                vuint32_t:14;
                vuint32_t KEY:1;
                vuint32_t RIA:1;
                vuint32_t WND:1;
                vuint32_t ITR:1;
                vuint32_t HLK:1;
                vuint32_t SLK:1;
                vuint32_t CSL:1;
                vuint32_t STP:1;
                vuint32_t FRZ:1;
                vuint32_t WEN:1;
            } B;
        } MCR;
        
        union {                /* Interrupt register */
            vuint32_t R;
            struct {
                vuint32_t :31;
                vuint32_t TIF:1;
            } B;
        } IR;
        
        union {                /* Timeout register */
            vuint32_t R;
            struct {
                vuint32_t WTO:32;
            } B;
        } TO;
        
        union {                /* Window register */
            vuint32_t R;
            struct {
                vuint32_t WST:32;
            } B;
        } WN;
        
        union {                /* Service register */
            vuint32_t R;
            struct {
                vuint32_t :16;
                vuint32_t WSC:16;
            } B;
        } SR;
        
        union {                /* Counter output register */
            vuint32_t R;
            struct {
                vuint32_t CNT:32;
            } B;
        } CO;
        
        union {                /* Service key register */
            vuint32_t R;
            struct {
                vuint32_t :16;
                vuint32_t SK:16;
            } B;
        } SK;
        
        uint32_t SWT_reserved001C[4089]; /* 0x001C-0x3FFF */
    
    };

/****************************************************************************/
/*                     MODULE : STM                                         */
/****************************************************************************/

    struct STM_tag {
    
        union {                  /* Control Register */
            vuint32_t R;
            struct {
                vuint32_t :16;
                vuint32_t CPS:8;
                vuint32_t :6;
                vuint32_t FRZ:1;
                vuint32_t TEN:1;
            } B;
        } CR;
        
        union {                /* STM Counter */
            vuint32_t R;
        } CNT;
        
        uint32_t STM_reserved0008[2];  /* 0x0008-0x000F */
        
 /* channel 0 registers */
		union {
            vuint32_t R;
            struct {
                vuint32_t :31;
             	vuint32_t CEN:1;   			
            } B;
        } CCR0;                /* Chan 0 Control Register */
        
        union {
    	    vuint32_t R;
            struct {
                vuint32_t :31;
                vuint32_t CIF:1;
        	} B;
        } CIR0;                /* Chan 0 Interrupt Register */
	
		union {
    	    vuint32_t R;
        } CMP0;                /* Chan 0 Compare Register */

		uint32_t STM_reserved2[1];
	
/* channel 1 registers */
		union {
            vuint32_t R;
            struct {
                vuint32_t :31;
             	vuint32_t CEN:1;   			
            } B;
        } CCR1;                /* Chan 1 Control Register */
        
        union {
    	    vuint32_t R;
            struct {
                vuint32_t :31;
                vuint32_t CIF:1;
        	} B;
        } CIR1;                /* Chan 1 Interrupt Register */
	
		union {
    	    vuint32_t R;
        } CMP1;                /* Chan 1 Compare Register */

		uint32_t STM_reserved3[1];
        
/* channel 2 registers */
		union {
            vuint32_t R;
            struct {
                vuint32_t :31;
             	vuint32_t CEN:1;   			
            } B;
        } CCR2;                /* Chan 2 Control Register */
        
        union {
    	    vuint32_t R;
            struct {
                vuint32_t :31;
                vuint32_t CIF:1;
        	} B;
        } CIR2;                /* Chan 2 Interrupt Register */
	
		union {
    	    vuint32_t R;
        } CMP2;                /* Chan 2 Compare Register */

		uint32_t STM_reserved4[1];

/* channel 3 registers */
		union {
            vuint32_t R;
            struct {
                vuint32_t :31;
             	vuint32_t CEN:1;   			
            } B;
        } CCR3;                /* Chan 3 Control Register */
        
        union {
    	    vuint32_t R;
            struct {
                vuint32_t :31;
                vuint32_t CIF:1;
        	} B;
        } CIR3;                /* Chan 3 Interrupt Register */
	
		union {
    	    vuint32_t R;
        } CMP3;                /* Chan 3 Compare Register */
        
        uint32_t STM_reserved0050[4076];  /* 0x0050-0x3FFF */
    
    };

/****************************************************************************/
/*                     MODULE : ECSM                                        */
/****************************************************************************/

    struct ECSM_tag {
    
        union {                /* Processor core type */
            vuint16_t R;
        } PCT;
        
        union {                /* Platform revision */
            vuint16_t R;
        } REV;
        
        uint32_t ECSM_reserved0004;  /* 0x0004-0x0007 */
        
        union {                 /* IPS Module Configuration */
            vuint32_t R;
        } IMC;
        
        uint8_t ECSM_reserved000C[3];  /* 0x000C-0x000E */
        
        union {                 /* Miscellaneous Reset Status Register */
            vuint8_t R;
            struct {
                vuint8_t POR:1;
                vuint8_t DIR:1;
                vuint8_t SWTR:1;
                vuint8_t:5;
            } B;
        } MRSR;
        
        uint8_t ECSM_reserved0010[51]; /* 0x0010-0x0042 */
        
        union {                  /* ECC Configuration Register */
            vuint8_t R;
            struct {
                vuint8_t:2;
                vuint8_t ER1BR:1;
                vuint8_t EF1BR:1;
                vuint8_t:2;
                vuint8_t ERNCR:1;
                vuint8_t EFNCR:1;
            } B;
        } ECR;
        
        uint8_t ECSM_reserved0044[3];  /* 0x0044-0x0046 */
        
        union {                  /* ECC Status Register */
            vuint8_t R;
            struct {
                vuint8_t:2;
                vuint8_t R1BC:1;
                vuint8_t F1BC:1;
                vuint8_t:2;
                vuint8_t RNCE:1;
                vuint8_t FNCE:1;
            } B;
        } ESR;
        
    uint16_t ECSM_reserved0048; /* 0x0048-0x0049 */
        
        union {                 /* ECC Error Generation Register */
            vuint16_t R;
            struct {
                vuint16_t:2;
                vuint16_t FRC1BI:1;
                vuint16_t FR11BI:1;
                vuint16_t:2;
                vuint16_t FRCNCI:1;
                vuint16_t FR1NCI:1;
                vuint16_t:1;
                vuint16_t ERRBIT:7;
            } B;
        } EEGR;
        
        uint32_t ECSM_reserved004C; /* 0x004C-0x004F */
        
        union {                 /* Flash ECC Address Register */
            vuint32_t R;
            struct {
                vuint32_t FEAR:32;
            } B;
        } FEAR;
        
        uint16_t ECSM_reserved0054; /* 0x0054-0x0055 */
        
        union {                 /* Flash ECC Master Number Register */
            vuint8_t R;
            struct {
                vuint8_t:4;
                vuint8_t FEMR:4;
            } B;
        } FEMR;
        
        union {                 /* Flash ECC Attributes Register */
            vuint8_t R;
            struct {
                vuint8_t WRITE:1;
                vuint8_t SIZE:3;
                vuint8_t PROT0:1;
                vuint8_t PROT1:1;
                vuint8_t PROT2:1;
                vuint8_t PROT3:1;
            } B;
        } FEAT;
        
        union {                /* Flash ECC Data Register High */
            vuint32_t R;
            struct {
                vuint32_t FEDH:32;
            } B;
        } FEDRH;
        
        union {                /* Flash ECC Data Register Low */
            vuint32_t R;
            struct {
                vuint32_t FEDL:32;
            } B;
        } FEDRL;
        
        union {                /* RAM ECC Address Register */
            vuint32_t R;
            struct {
                vuint32_t REAR:32;
            } B;
        } REAR;
        
        uint8_t ECSM_reserved0064; /* 0x0064 */
                
        union {                /* RAM ECC Syndrome Register */
            vuint8_t R;
            struct {
                vuint8_t RESR:8;
            } B;
        } RESR;
        
        union {                 /* RAM ECC Master Number Register */
            vuint8_t R;
            struct {
                vuint8_t:4;
                vuint8_t REMR:4;
            } B;
        } REMR;
        
        union {                 /* RAM ECC Attributes Register */
            vuint8_t R;
            struct {
                vuint8_t WRITE:1;
                vuint8_t SIZE:3;
                vuint8_t PROT0:1;
                vuint8_t PROT1:1;
                vuint8_t PROT2:1;
                vuint8_t PROT3:1;
            } B;
        } REAT;
        
        union {                /* RAM ECC Data Register */
            vuint32_t R;
            struct {
                vuint32_t REDH:32;
            } B;
        } REDRH;
        
        union {                /* RAM ECC Data Register */
            vuint32_t R;
            struct {
                vuint32_t REDL:32;
            } B;
        } REDRL;
        
        uint32_t ECSM_reserved0070[4068]; /* 0x0070-0x3FFF */
    
    };

/****************************************************************************/
/*                          MODULE : eDMA                                   */
/****************************************************************************/

    struct EDMA_tag {
    
        union {                   /* Control Register */
            vuint32_t R;
            struct {
                vuint32_t:14;
                vuint32_t CX:1;
                vuint32_t ECX:1;
                vuint32_t GRP3PRI:2;
                vuint32_t GRP2PRI:2;
                vuint32_t GRP1PRI:2;
                vuint32_t GRP0PRI:2;
                vuint32_t EMLM:1;
                vuint32_t CLM:1;
                vuint32_t HALT:1;
                vuint32_t HOE:1;
                vuint32_t ERGA:1;
                vuint32_t ERCA:1;
                vuint32_t EDBG:1;
                vuint32_t:1;
            } B;
        } CR; /* Legacy naming - refer to MCR in Reference Manual */
        
        union {                  /* Error Status Register */
            vuint32_t R;
            struct {
                vuint32_t VLD:1;
                vuint32_t:14;
                vuint32_t ECX:1;
                vuint32_t GPE:1;
                vuint32_t CPE:1;
                vuint32_t ERRCHN:6;
                vuint32_t SAE:1;
                vuint32_t SOE:1;
                vuint32_t DAE:1;
                vuint32_t DOE:1;
                vuint32_t NCE:1;
                vuint32_t SGE:1;
                vuint32_t SBE:1;
                vuint32_t DBE:1;
            } B;
        } ESR;
        
        union {                /* DMA Enable Request Register High */
            vuint32_t R;
            struct {
                vuint32_t ERQ63:1;
                vuint32_t ERQ62:1;
                vuint32_t ERQ61:1;
                vuint32_t ERQ60:1;
                vuint32_t ERQ59:1;
                vuint32_t ERQ58:1;
                vuint32_t ERQ57:1;
                vuint32_t ERQ56:1;
                vuint32_t ERQ55:1;
                vuint32_t ERQ54:1;
                vuint32_t ERQ53:1;
                vuint32_t ERQ52:1;
                vuint32_t ERQ51:1;
                vuint32_t ERQ50:1;
                vuint32_t ERQ49:1;
                vuint32_t ERQ48:1;
                vuint32_t ERQ47:1;
                vuint32_t ERQ46:1;
                vuint32_t ERQ45:1;
                vuint32_t ERQ44:1;
                vuint32_t ERQ43:1;
                vuint32_t ERQ42:1;
                vuint32_t ERQ41:1;
                vuint32_t ERQ40:1;
                vuint32_t ERQ39:1;
                vuint32_t ERQ38:1;
                vuint32_t ERQ37:1;
                vuint32_t ERQ36:1;
                vuint32_t ERQ35:1;
                vuint32_t ERQ34:1;
                vuint32_t ERQ33:1;
                vuint32_t ERQ32:1;
            } B;
        } ERQRH;
        
        union {                /* DMA Enable Request Register Low */
            vuint32_t R;
            struct {
                vuint32_t ERQ31:1;
                vuint32_t ERQ30:1;
                vuint32_t ERQ29:1;
                vuint32_t ERQ28:1;
                vuint32_t ERQ27:1;
                vuint32_t ERQ26:1;
                vuint32_t ERQ25:1;
                vuint32_t ERQ24:1;
                vuint32_t ERQ23:1;
                vuint32_t ERQ22:1;
                vuint32_t ERQ21:1;
                vuint32_t ERQ20:1;
                vuint32_t ERQ19:1;
                vuint32_t ERQ18:1;
                vuint32_t ERQ17:1;
                vuint32_t ERQ16:1;
                vuint32_t ERQ15:1;
                vuint32_t ERQ14:1;
                vuint32_t ERQ13:1;
                vuint32_t ERQ12:1;
                vuint32_t ERQ11:1;
                vuint32_t ERQ10:1;
                vuint32_t ERQ09:1;
                vuint32_t ERQ08:1;
                vuint32_t ERQ07:1;
                vuint32_t ERQ06:1;
                vuint32_t ERQ05:1;
                vuint32_t ERQ04:1;
                vuint32_t ERQ03:1;
                vuint32_t ERQ02:1;
                vuint32_t ERQ01:1;
                vuint32_t ERQ00:1;
            } B;
        } ERQRL;
        
        union {                /* DMA Enable Error Interrupt Register High */
            vuint32_t R;
            struct {
                
                vuint32_t EEI63:1;
                vuint32_t EEI62:1;
                vuint32_t EEI61:1;
                vuint32_t EEI60:1;
                vuint32_t EEI59:1;
                vuint32_t EEI58:1;
                vuint32_t EEI57:1;
                vuint32_t EEI56:1;
                vuint32_t EEI55:1;
                vuint32_t EEI54:1;
                vuint32_t EEI53:1;
                vuint32_t EEI52:1;
                vuint32_t EEI51:1;
                vuint32_t EEI50:1;
                vuint32_t EEI49:1;
                vuint32_t EEI48:1;
                vuint32_t EEI47:1;
                vuint32_t EEI46:1;
                vuint32_t EEI45:1;
                vuint32_t EEI44:1;
                vuint32_t EEI43:1;
                vuint32_t EEI42:1;
                vuint32_t EEI41:1;
                vuint32_t EEI40:1;
                vuint32_t EEI39:1;
                vuint32_t EEI38:1;
                vuint32_t EEI37:1;
                vuint32_t EEI36:1;
                vuint32_t EEI35:1;
                vuint32_t EEI34:1;
                vuint32_t EEI33:1;
                vuint32_t EEI32:1;
            } B;
        } EEIRH;
        
        union {                /* DMA Enable Error Interrupt Register Low */
            vuint32_t R;
            struct {
                vuint32_t EEI31:1;
                vuint32_t EEI30:1;
                vuint32_t EEI29:1;
                vuint32_t EEI28:1;
                vuint32_t EEI27:1;
                vuint32_t EEI26:1;
                vuint32_t EEI25:1;
                vuint32_t EEI24:1;
                vuint32_t EEI23:1;
                vuint32_t EEI22:1;
                vuint32_t EEI21:1;
                vuint32_t EEI20:1;
                vuint32_t EEI19:1;
                vuint32_t EEI18:1;
                vuint32_t EEI17:1;
                vuint32_t EEI16:1;
                vuint32_t EEI15:1;
                vuint32_t EEI14:1;
                vuint32_t EEI13:1;
                vuint32_t EEI12:1;
                vuint32_t EEI11:1;
                vuint32_t EEI10:1;
                vuint32_t EEI09:1;
                vuint32_t EEI08:1;
                vuint32_t EEI07:1;
                vuint32_t EEI06:1;
                vuint32_t EEI05:1;
                vuint32_t EEI04:1;
                vuint32_t EEI03:1;
                vuint32_t EEI02:1;
                vuint32_t EEI01:1;
                vuint32_t EEI00:1;
            } B;
        } EEIRL;
        
        union {                /* DMA Set Enable Request Register */
            vuint8_t R;
            struct {
                vuint8_t NOP:1;
                vuint8_t SERQ:7;
            } B;
        } SERQR;
        
        union {                /* DMA Clear Enable Request Register */
            vuint8_t R;
            struct {
                vuint8_t NOP:1;
                vuint8_t CERQ:7;
            } B;
        } CERQR;
        
        union {                /* DMA Set Enable Error Interrupt Register */
            vuint8_t R;
            struct {
                vuint8_t NOP:1;
                vuint8_t SEEI:7;
            } B;
        } SEEIR;
        
        union {                /* DMA Clear Enable Error Interrupt Register */
            vuint8_t R;
            struct {
                vuint8_t NOP:1;
                vuint8_t CEEI:7;
            } B;
        } CEEIR;
        
        union {                /* DMA Clear Interrupt Request Register */
            vuint8_t R;
            struct {
                vuint8_t NOP:1;
                vuint8_t CINT:7;
            } B;
        } CIRQR;
        
        union {                  /* DMA Clear error Register */
            vuint8_t R;
            struct {
                vuint8_t NOP:1;
                vuint8_t CERR:7;
            } B;
        } CER;
        
        union {                 /* Set Start Bit Register */
            vuint8_t R;
            struct {
                vuint8_t NOP:1;
                vuint8_t SSB:7;
            } B;
        } SSBR;
        
        union {                /* Clear Done Status Bit Register */
            vuint8_t R;
            struct {
                vuint8_t NOP:1;
                vuint8_t CDSB:7;
            } B;
        } CDSBR;
        
        union {                /* DMA Interrupt Request High */
            vuint32_t R;
            struct {
                vuint32_t INT63:1;
                vuint32_t INT62:1;
                vuint32_t INT61:1;
                vuint32_t INT60:1;
                vuint32_t INT59:1;
                vuint32_t INT58:1;
                vuint32_t INT57:1;
                vuint32_t INT56:1;
                vuint32_t INT55:1;
                vuint32_t INT54:1;
                vuint32_t INT53:1;
                vuint32_t INT52:1;
                vuint32_t INT51:1;
                vuint32_t INT50:1;
                vuint32_t INT49:1;
                vuint32_t INT48:1;
                vuint32_t INT47:1;
                vuint32_t INT46:1;
                vuint32_t INT45:1;
                vuint32_t INT44:1;
                vuint32_t INT43:1;
                vuint32_t INT42:1;
                vuint32_t INT41:1;
                vuint32_t INT40:1;
                vuint32_t INT39:1;
                vuint32_t INT38:1;
                vuint32_t INT37:1;
                vuint32_t INT36:1;
                vuint32_t INT35:1;
                vuint32_t INT34:1;
                vuint32_t INT33:1;
                vuint32_t INT32:1;
            } B;
        } IRQRH;
        
        union {                /* DMA Interrupt Request Low */
            vuint32_t R;
            struct {
                vuint32_t INT31:1;
                vuint32_t INT30:1;
                vuint32_t INT29:1;
                vuint32_t INT28:1;
                vuint32_t INT27:1;
                vuint32_t INT26:1;
                vuint32_t INT25:1;
                vuint32_t INT24:1;
                vuint32_t INT23:1;
                vuint32_t INT22:1;
                vuint32_t INT21:1;
                vuint32_t INT20:1;
                vuint32_t INT19:1;
                vuint32_t INT18:1;
                vuint32_t INT17:1;
                vuint32_t INT16:1;
                vuint32_t INT15:1;
                vuint32_t INT14:1;
                vuint32_t INT13:1;
                vuint32_t INT12:1;
                vuint32_t INT11:1;
                vuint32_t INT10:1;
                vuint32_t INT09:1;
                vuint32_t INT08:1;
                vuint32_t INT07:1;
                vuint32_t INT06:1;
                vuint32_t INT05:1;
                vuint32_t INT04:1;
                vuint32_t INT03:1;
                vuint32_t INT02:1;
                vuint32_t INT01:1;
                vuint32_t INT00:1;
            } B;
        } IRQRL;
        
        union {                  /* DMA Error High */
            vuint32_t R;
            struct {
                vuint32_t ERR63:1;
                vuint32_t ERR62:1;
                vuint32_t ERR61:1;
                vuint32_t ERR60:1;
                vuint32_t ERR59:1;
                vuint32_t ERR58:1;
                vuint32_t ERR57:1;
                vuint32_t ERR56:1;
                vuint32_t ERR55:1;
                vuint32_t ERR54:1;
                vuint32_t ERR53:1;
                vuint32_t ERR52:1;
                vuint32_t ERR51:1;
                vuint32_t ERR50:1;
                vuint32_t ERR49:1;
                vuint32_t ERR48:1;
                vuint32_t ERR47:1;
                vuint32_t ERR46:1;
                vuint32_t ERR45:1;
                vuint32_t ERR44:1;
                vuint32_t ERR43:1;
                vuint32_t ERR42:1;
                vuint32_t ERR41:1;
                vuint32_t ERR40:1;
                vuint32_t ERR39:1;
                vuint32_t ERR38:1;
                vuint32_t ERR37:1;
                vuint32_t ERR36:1;
                vuint32_t ERR35:1;
                vuint32_t ERR34:1;
                vuint32_t ERR33:1;
                vuint32_t ERR32:1;
            } B;
        } ERH;
        
        union {                  /* DMA Error Low */
            vuint32_t R;
            struct {
                vuint32_t ERR31:1;
                vuint32_t ERR30:1;
                vuint32_t ERR29:1;
                vuint32_t ERR28:1;
                vuint32_t ERR27:1;
                vuint32_t ERR26:1;
                vuint32_t ERR25:1;
                vuint32_t ERR24:1;
                vuint32_t ERR23:1;
                vuint32_t ERR22:1;
                vuint32_t ERR21:1;
                vuint32_t ERR20:1;
                vuint32_t ERR19:1;
                vuint32_t ERR18:1;
                vuint32_t ERR17:1;
                vuint32_t ERR16:1;
                vuint32_t ERR15:1;
                vuint32_t ERR14:1;
                vuint32_t ERR13:1;
                vuint32_t ERR12:1;
                vuint32_t ERR11:1;
                vuint32_t ERR10:1;
                vuint32_t ERR09:1;
                vuint32_t ERR08:1;
                vuint32_t ERR07:1;
                vuint32_t ERR06:1;
                vuint32_t ERR05:1;
                vuint32_t ERR04:1;
                vuint32_t ERR03:1;
                vuint32_t ERR02:1;
                vuint32_t ERR01:1;
                vuint32_t ERR00:1;
            } B;
        } ERL;
        
        union {                  /* hardware request status high */
            vuint32_t R;
            struct {
                vuint32_t HRS63:1;
                vuint32_t HRS62:1;
                vuint32_t HRS61:1;
                vuint32_t HRS60:1;
                vuint32_t HRS59:1;
                vuint32_t HRS58:1;
                vuint32_t HRS57:1;
                vuint32_t HRS56:1;
                vuint32_t HRS55:1;
                vuint32_t HRS54:1;
                vuint32_t HRS53:1;
                vuint32_t HRS52:1;
                vuint32_t HRS51:1;
                vuint32_t HRS50:1;
                vuint32_t HRS49:1;
                vuint32_t HRS48:1;
                vuint32_t HRS47:1;
                vuint32_t HRS46:1;
                vuint32_t HRS45:1;
                vuint32_t HRS44:1;
                vuint32_t HRS43:1;
                vuint32_t HRS42:1;
                vuint32_t HRS41:1;
                vuint32_t HRS40:1;
                vuint32_t HRS39:1;
                vuint32_t HRS38:1;
                vuint32_t HRS37:1;
                vuint32_t HRS36:1;
                vuint32_t HRS35:1;
                vuint32_t HRS34:1;
                vuint32_t HRS33:1;
                vuint32_t HRS32:1;
            } B;
        } HRSH;
        
        union {                  /* hardware request status low */
            vuint32_t R;
            struct {
                vuint32_t HRS31:1;
                vuint32_t HRS30:1;
                vuint32_t HRS29:1;
                vuint32_t HRS28:1;
                vuint32_t HRS27:1;
                vuint32_t HRS26:1;
                vuint32_t HRS25:1;
                vuint32_t HRS24:1;
                vuint32_t HRS23:1;
                vuint32_t HRS22:1;
                vuint32_t HRS21:1;
                vuint32_t HRS20:1;
                vuint32_t HRS19:1;
                vuint32_t HRS18:1;
                vuint32_t HRS17:1;
                vuint32_t HRS16:1;
                vuint32_t HRS15:1;
                vuint32_t HRS14:1;
                vuint32_t HRS13:1;
                vuint32_t HRS12:1;
                vuint32_t HRS11:1;
                vuint32_t HRS10:1;
                vuint32_t HRS09:1;
                vuint32_t HRS08:1;
                vuint32_t HRS07:1;
                vuint32_t HRS06:1;
                vuint32_t HRS05:1;
                vuint32_t HRS04:1;
                vuint32_t HRS03:1;
                vuint32_t HRS02:1;
                vuint32_t HRS01:1;
                vuint32_t HRS00:1;
            } B;
        } HRSL;
        
        uint32_t eDMA_reserved0038[50];  /* 0x0038-0x00FF */
        
        union {              /* Channel n Priority */
            vuint8_t R;
            struct {
                vuint8_t ECP:1;
                vuint8_t DPA:1;
                vuint8_t GRPPRI:2;
                vuint8_t CHPRI:4;
            } B;
        } CPR[64];
        
        uint32_t eDMA_reserved0140[944];  /* 0x0140-0x0FFF */
		

/****************************************************************************/
/*       DMA2 Transfer Control Descriptor                                   */
/****************************************************************************/

        struct tcd_t {          /* for "standard" format TCDs (when EDMA.TCD[x].CITER.E_LINK==BITER.E_LINK=0 && EDMA.EMLM=0 ) */
            /* 00 */
            vuint32_t SADDR;    /* Source Address */
            
            /* 04 */            /* Transfer Attributes */
            vuint16_t SMOD:5;   /* Source Address Modulo */
            vuint16_t SSIZE:3;  /* Source Data Transfer Size */
            vuint16_t DMOD:5;   /* Destination Address Modulo */
            vuint16_t DSIZE:3;  /* Destination Data Transfer Size */
            
            /* 06 */
            vint16_t SOFF;      /* Signed Source Address Offset */
            
            /* 08 */
           vuint32_t NBYTES;   /* Inner ("Minor") Byte Transfer Count */
           
            /* 0C */
            vint32_t SLAST;     /* Last Source Address Adjustment */
            
            /* 10 */
            vuint32_t DADDR;    /* Destination Address */
            
            /* 14 */
            vuint16_t CITERE_LINK:1;     /* Enable Channel-to-Channel        */
                                         /* Linking on Minor Loop Completion */
            vuint16_t CITER:15;          /* Current Major Iteration Count    */
            
            /* 16 */
            vint16_t DOFF;      /* Signed Destination Address Offset */
            
            /* 18 */
            vint32_t DLAST_SGA; /* Last Destination Address Adjustment, or  */
                                /* Scatter/Gather Address (if E_SG = 1)     */
            
            /* 1C */
            vuint16_t BITERE_LINK:1;    /* Enable Channel-to-Channel           */
                                        /* Linking on Minor Loop Complete      */
            vuint16_t BITER:15;         /* Starting ("Major") Iteration Count */
            
            /* 1E */                    /* Channel Control/Status */
            vuint16_t BWC:2;            /* Bandwidth Control */
            vuint16_t MAJORLINKCH:6;    /* Link Channel Number */
            vuint16_t DONE:1;           /* Channel Done */
			vuint16_t ACTIVE:1;
            vuint16_t MAJORE_LINK:1;    /* Enable Channel-to-Channel Link */
            vuint16_t E_SG:1;           /* Enable Scatter/Gather Descriptor */
            vuint16_t D_REQ:1;          /* Disable IPD_REQ When Done */
            vuint16_t INT_HALF:1;       /* Interrupt on CITER = (BITER >> 1) */
            vuint16_t INT_MAJ:1;        /* Interrupt on Major Loop Completion */
            vuint16_t START:1;          /* Explicit Channel Start */
        } TCD[64];                      /* Transfer_Control_Descriptor */
    
    };

    struct EDMA_TCD_alt1_tag {  /*for alternate format TCDs (when EDMA.TCD[x].CITER.E_LINK==BITER.E_LINK=1 ) */
    
        struct tcd_alt1_t {
            /* 00 */
            vuint32_t SADDR;    /* Source Address */
            
            /* 04 */            /* Transfer Attributes */
            vuint16_t SMOD:5;   /* Source Address Modulo */
            vuint16_t SSIZE:3;  /* Source Data Transfer Size */
            vuint16_t DMOD:5;   /* Destination Address Modulo */
            vuint16_t DSIZE:3;  /* Destination Data Transfer Size */
            
            /* 06 */
            vint16_t SOFF;      /* Signed Source Address Offset */
            
            /* 08 */
            vuint32_t NBYTES;   /* Inner ("Minor") Byte Transfer Count */
            
            /* 0C */
            vint32_t SLAST;     /* Last Source Address Adjustment */
            
            /* 10 */
            vuint32_t DADDR;    /* Destination Address */
            
            /* 14 */
            vuint16_t CITERE_LINK:1;     /* Enable Channel-to-Channel        */
                                         /* Linking on Minor Loop Completion */
            vuint16_t CITERLINKCH:6;     /* Link Channel Number              */
            vuint16_t CITER:9;           /* Current Major Iteration Count    */
            
            /* 16 */
            vint16_t DOFF;      /* Signed Destination Address Offset */
            
            /* 18 */
            vint32_t DLAST_SGA; /* Last Destination Address Adjustment, or  */
                                /* Scatter/Gather Address (if E_SG = 1)     */
            
            /* 1C */
            vuint16_t BITERE_LINK:1;    /* Enable Channel-to-Channel           */
                                        /* Linking on Minor Loop Complete      */
            vuint16_t BITERLINKCH:6;    /* Link Channel Number                 */
            vuint16_t BITER:9;          /* Starting ("Major") Iteration Count  */
            
            /* 1E */                    /* Channel Control/Status */
            vuint16_t BWC:2;            /* Bandwidth Control */
            vuint16_t MAJORLINKCH:6;    /* Link Channel Number */
            vuint16_t DONE:1;           /* Channel Done */
            vuint16_t ACTIVE:1;         /* Channel Active */
            vuint16_t MAJORE_LINK:1;    /* Enable Channel-to-Channel Link */
            vuint16_t E_SG:1;           /* Enable Scatter/Gather Descriptor */
            vuint16_t D_REQ:1;          /* Disable IPD_REQ When Done */
            vuint16_t INT_HALF:1;       /* Interrupt on CITER = (BITER >> 1) */
            vuint16_t INT_MAJ:1;        /* Interrupt on Major Loop Completion */
            vuint16_t START:1;          /* Explicit Channel Start */
        } TCD[64];              /* transfer_control_descriptor */
    };

/****************************************************************************/
/*                          MODULE : INTC                                   */
/****************************************************************************/

    struct INTC_tag {
    
        union {                  /* Module Configuration Register */
            vuint32_t R;
            struct {
                vuint32_t:26;
                vuint32_t VTES:1;
                vuint32_t:4;
                vuint32_t HVEN:1;
            } B;
        } MCR;
        
        uint32_t INTC_reserved0004;  /* 0x0004-0x0007 */
        
        union {                  /* Current Priority Register */
            vuint32_t R;
            struct {
                vuint32_t:28;
                vuint32_t PRI:4;
            } B;
        } CPR;
        
        uint32_t INTC_reserved000C;  /* 0x000C-0x000F */
        
        union {                /* Interrupt Acknowledge Register */
            vuint32_t R;
            struct {
                vuint32_t VTBA:21;
                vuint32_t INTVEC:9;
                  vuint32_t:2;
            } B;
        } IACKR;
        
        uint32_t INTC_reserved0014;  /* 0x0014-0x0017 */
        
        union {                 /* End of Interrupt Register */
            vuint32_t R;
            struct {
                vuint32_t EOIR:32;
            } B;
        } EOIR;
        
        uint32_t INTC_reserved001C;  /* 0x001C-0x001F */
        
        union {             /* Software Set/Clear Interruput Register */
            vuint8_t R;
            struct {
                vuint8_t:6;
                vuint8_t SET:1;
                vuint8_t CLR:1;
            } B;
        } SSCIR[8];
        
        uint32_t INTC_reserved0028[6]; /* 0x0028-0x003F */
        
        union {             /* Priority Select Registers */
            vuint8_t R;
            struct {
                vuint8_t:4;
                vuint8_t PRI:4;
            } B;
        } PSR[480];
        
        uint16_t INTC_reserved0220[7922]; /* 0x0220-0x3FFF */
    
    };
    
/****************************************************************************/
/*                          MODULE : EQADC                                  */
/****************************************************************************/

    struct EQADC_tag {
    
        union {                  /* Module Configuration Register */
            vuint32_t R;
            struct {
                vuint32_t:24;
                vuint32_t ICEA0:1;
                vuint32_t ICEA1:1;
                vuint32_t:1;
                vuint32_t:2;
                vuint32_t:1;
                vuint32_t DBG:2;
            } B;
        } MCR;
        
        uint32_t eQADC_reserved0004;  /* 0x0004-0x0007 */
        
        uint32_t eQADC_reserved0008;  /* 0x0008-0x000B */
        
        union {                /* External Trigger Digital Filter Register */
            vuint32_t R;
            struct {
                vuint32_t:28;
                vuint32_t DFL:4;
            } B;
        } ETDFR;
        
        union {              /* CFIFO Push Registers */
            vuint32_t R;
            struct {
                vuint32_t CFPUSH:32;
            } B;
        } CFPR[6];
        
        uint32_t eQADC_reserved0028[2];  /* 0x0028-0x002F */
        
        union {              /* Result FIFO Pop Registers */
            vuint32_t R;
            struct {
                vuint32_t:16;
                vuint32_t RFPOP:16;
            } B;
        } RFPR[6];
        
        uint32_t eQADC_reserved0048[2];  /* 0x0048-0x004F */
        
        union {              /* CFIFO Control Registers */
            vuint16_t R;
            struct {
                vuint16_t:3;
                vuint16_t CFEEE:1; /* ONLY valid for CFCR[0] */
                vuint16_t STRME:1; /* ONLY valid for CFCR[0] */
                vuint16_t SSE:1;
                vuint16_t CFINV:1;
                vuint16_t:1;
                vuint16_t MODE:4;
                vuint16_t AMODE:4; /* ONLY valid for CFCR[0] */
            } B;
        } CFCR[6];
        
        uint32_t eQADC_reserved005C;  /* 0x005C-0x005F */
        
        union {              /* Interrupt and DMA Control Registers */
            vuint16_t R;
            struct {
                vuint16_t NCIE:1;
                vuint16_t TORIE:1;
                vuint16_t PIE:1;
                vuint16_t EOQIE:1;
                vuint16_t CFUIE:1;
                vuint16_t:1;
                vuint16_t CFFE:1;
                vuint16_t CFFS:1;
                vuint16_t:4;
                vuint16_t RFOIE:1;
                vuint16_t:1;
                vuint16_t RFDE:1;
                vuint16_t RFDS:1;
            } B;
        } IDCR[6];
        
        uint32_t eQADC_reserved006C;  /* 0x006C-0x006F */
        
        union {              /* FIFO and Interrupt Status Registers */
            vuint32_t R;
            struct {
                vuint32_t NCF:1;
                vuint32_t TORF:1;
                vuint32_t PF:1;
                vuint32_t EOQF:1;
                vuint32_t CFUF:1;
                vuint32_t SSS:1;
                vuint32_t CFFF:1;
                vuint32_t:5;
                vuint32_t RFOF:1;
                vuint32_t:1;
                vuint32_t RFDF:1;
                vuint32_t:1;
                vuint32_t CFCTR:4;
                vuint32_t TNXTPTR:4;
                vuint32_t RFCTR:4;
                vuint32_t POPNXTPTR:4;
            } B;
        } FISR[6];
        
        uint32_t eQADC_reserved0088[2];  /* 0x0088-0x008F */
        
        union {             /* CFIFO Transfer Counter Registers */
            vuint16_t R;
            struct {
                vuint16_t:5;
                vuint16_t TCCF:11; /* Legacy naming - refer to TC_CF in Reference Manual */
            } B;
        } CFTCR[6];
        
        uint32_t eQADC_reserved009C[1];  /* 0x009F */
        
        union {               /* CFIFO Status Register 0 */
            vuint32_t R;
            struct {
                vuint32_t CFS0:2; /* Legacy naming - refer to CFS0_TCB0 in Reference Manual */
                vuint32_t CFS1:2; /* Legacy naming - refer to CFS1_TCB0 in Reference Manual */
                vuint32_t CFS2:2; /* Legacy naming - refer to CFS2_TCB0 in Reference Manual */
                vuint32_t CFS3:2; /* Legacy naming - refer to CFS3_TCB0 in Reference Manual */
                vuint32_t CFS4:2; /* Legacy naming - refer to CFS4_TCB0 in Reference Manual */
                vuint32_t CFS5:2; /* Legacy naming - refer to CFS5_TCB0 in Reference Manual */
                vuint32_t:5;
                vuint32_t LCFTCB0:4;
                vuint32_t TC_LCFTCB0:11;
            } B;
        } CFSSR0;
        
        union {               /* CFIFO Status Register 1 */
            vuint32_t R;
            struct {
                vuint32_t CFS0:2; /* Legacy naming - refer to CFS0_TCB1 in Reference Manual */
                vuint32_t CFS1:2; /* Legacy naming - refer to CFS1_TCB1 in Reference Manual */
                vuint32_t CFS2:2; /* Legacy naming - refer to CFS2_TCB1 in Reference Manual */
                vuint32_t CFS3:2; /* Legacy naming - refer to CFS3_TCB1 in Reference Manual */
                vuint32_t CFS4:2; /* Legacy naming - refer to CFS4_TCB1 in Reference Manual */
                vuint32_t CFS5:2; /* Legacy naming - refer to CFS5_TCB1 in Reference Manual */
                vuint32_t:5;
                vuint32_t LCFTCB1:4;
                vuint32_t TC_LCFTCB1:11;
            } B;
        } CFSSR1;
        
        union {               /* CFIFO Status Register 2 */
            vuint32_t R;
            struct {
                vuint32_t CFS0:2; /* Legacy naming - refer to CFS0_TSSI in Reference Manual */
                vuint32_t CFS1:2; /* Legacy naming - refer to CFS1_TSSI in Reference Manual */
                vuint32_t CFS2:2; /* Legacy naming - refer to CFS2_TSSI in Reference Manual */
                vuint32_t CFS3:2; /* Legacy naming - refer to CFS3_TSSI in Reference Manual */
                vuint32_t CFS4:2; /* Legacy naming - refer to CFS4_TSSI in Reference Manual */
                vuint32_t CFS5:2; /* Legacy naming - refer to CFS5_TSSI in Reference Manual */
                vuint32_t:4;
                vuint32_t ECBNI:1;
                vuint32_t LCFTSSI:4;
                vuint32_t TC_LCFTSSI:11;
            } B;
        } CFSSR2;
        
        union {                 /* CFIFO Status Register */
            vuint32_t R;
            struct {
                vuint32_t CFS0:2;
                vuint32_t CFS1:2;
                vuint32_t CFS2:2;
                vuint32_t CFS3:2;
                vuint32_t CFS4:2;
                vuint32_t CFS5:2;
                vuint32_t:20;
            } B;
        } CFSR;
        
        uint32_t eQADC_reserved00B0;  /* 0x00B0-0x00B3 */
        uint32_t eQADC_reserved00B4;  /* 0x00B4-0x00B7 */
        uint32_t eQADC_reserved00B8;  /* 0x00B8-0x00BB */
        
        uint32_t eQADC_reserved00BC[5];  /* 0x00BC-0x00CF */
        
        union {                 /* EQADC Red Line Client Configuration Register */
            vuint32_t R;
            struct {
                vuint32_t:16;
                vuint32_t REDBS2:4;
                vuint32_t SRV2:4;
                vuint32_t REDBS1:4;
                vuint32_t SRV1:4;
            } B;
        } REDLCCR;

        uint32_t eQADC_reserved00D4[11];  /* 0x00D4-0x00FF */

        struct {
            union {
                vuint32_t R;
                struct {
                    vuint32_t CFIFO_DATA:32;
                } B;
            } R[4];
            
            union {             /* NOTE: ER registers valid only for CF[0]. */
                vuint32_t R;
                struct {
                    vuint32_t CFIFO_EDATA:32;
                } B;
            } ER[4];

            uint32_t eQADC_cf_reserved020[8];  /* CFIFO offset 0x020-0x03F */
           
        } CF[6];
        
        uint32_t eQADC_reserved0280[32];  /* 0x0280-0x02FF */
        
        struct {
            union {
                vuint32_t R;
                struct {
                    vuint32_t RFIFO_DATA:32;
                } B;
            } R[4];
            
            uint32_t eQADC_rf_reserved010[12];  /* RFIFO offset 0x010-0x03F */
            
        } RF[6];
    
        uint32_t eQADC_reserved0480[3808];  /* 0x0480-0x3FFF */
    };

/****************************************************************************/
/*                          MODULE : Decimation Filter                      */
/****************************************************************************/

    struct DECFIL_tag {
    
        union {                  /* Module Configuration Register */
            vuint32_t R;
            struct {
                vuint32_t MDIS:1;
                vuint32_t FREN:1;
                vuint32_t :1;
                vuint32_t FRZ:1;
                vuint32_t SRES:1;
                vuint32_t CASCD:2;
                vuint32_t IDEN:1;
                vuint32_t ODEN:1;
                vuint32_t ERREN:1;
                vuint32_t :1;
                vuint32_t FTYPE:2;
                vuint32_t :1;
                vuint32_t SCAL:2;
                vuint32_t IDIS:1;
                vuint32_t SAT:1;
                vuint32_t IO_SEL:2;

                vuint32_t DEC_RATE:4;
                vuint32_t SDIE:1;
                vuint32_t DSEL:1;
                vuint32_t IBIE:1;
                vuint32_t OBIE:1;
                vuint32_t EDME:1;
                vuint32_t :3;
            } B;
        } MCR;
        
        union {                  /* Module Status Register */
            vuint32_t R;
            struct {
                vuint32_t BSY:1;
                vuint32_t:1;
                vuint32_t DEC_COUNTER:4;
                vuint32_t IDFC:1;
                vuint32_t ODFC:1;
                vuint32_t:1;
                vuint32_t IBIC:1;
                vuint32_t OBIC:1;
                vuint32_t:1;
                vuint32_t DIVRC:1;
                vuint32_t OVFC:1;
                vuint32_t OVRC:1;
                vuint32_t IVRC:1;
                vuint32_t:6;
                vuint32_t IDF:1;
                vuint32_t ODF:1;
                vuint32_t:1;
                vuint32_t IBIF:1;
                vuint32_t OBIF:1;
                vuint32_t:1;
                vuint32_t DIVR:1;
                vuint32_t OVF:1;
                vuint32_t OVR:1;
                vuint32_t IVR:1;
            } B;
		} SR;
        
        union {                  /* Module Extended Config Register */
            vuint32_t R;
            struct {
            	vuint32_t SDMAE:1;
            	vuint32_t SSIG:1;
            	vuint32_t SSAT:1;
            	vuint32_t SCSAT:1;
            	vuint32_t:10;
                vuint32_t SRQ:1;
                vuint32_t SZR0:1;
                vuint32_t SISEL:1;
                vuint32_t:1;
                vuint32_t SZROSEL:2;
            	vuint32_t:2;
				vuint32_t SHLTSEL:2;
            	vuint32_t:1;
                vuint32_t SRQSEL:3;
            	vuint32_t:2;
				vuint32_t SENSEL:2;
            } B;
        } MXCR;
        
        union {                  /* Module Extended Status Register */
            vuint32_t R;
            struct {
                vuint32_t:7;
                vuint32_t SDFC:1;
                vuint32_t:2;
                vuint32_t SSEC:1;
                vuint32_t SCEC:1;
                vuint32_t:1;
                vuint32_t SSOVFC:1;
                vuint32_t SCOVFC:1;
                vuint32_t SVRC:1;
                vuint32_t:7;
                vuint32_t SDF:1;
                vuint32_t:2;
                vuint32_t SSE:1;
                vuint32_t SCE:1;
                vuint32_t:1;
                vuint32_t SSOVF:1;
                vuint32_t SCOVF:1;
                vuint32_t SVR:1;
 	      } B;
        } MXSR;
        
        union {                  /* Interface Input Buffer Register */
            vuint32_t R;
            struct {
                vuint32_t:4;
            	vuint32_t INTAG:4;
                vuint32_t:6;
                vuint32_t PREFILL:1;
                vuint32_t FLUSH:1;
                vuint32_t INPBUF:16;
            } B;
        } IB;
        
        union {                  /* Interface Output Buffer Register */
            vuint32_t R;
            struct {
                vuint32_t:12;
                vuint32_t OUTTAG:4;
                vuint32_t OUTBUF:16;
            } B;
        } OB;
        
        uint32_t DFILT_reserved0018[2];  /* 0x0018-0x001F */
        
        union {                  /* Coefficient n Register */
            vint32_t R;
            struct {
                vint32_t:8;
                vint32_t COEF:24;
            } B;
        } COEF[9];
        
        uint32_t DFILT_reserved0044[13];  /* 0x0044-0x0077 */
        
        union {                  /* TAP n Register */
            vint32_t R;
            struct {
                vint32_t:8;
                vint32_t TAP:24;
            } B;
        } TAP[8];
        
        uint32_t DFILT_reserved0098[14]; /* 0x0098-0x00CF */
        
        union {                  /* EDID Register */
            vuint32_t R;
            struct {
                vuint32_t:16;
                vuint32_t SAMP_DATA:16;
            } B;
        } EDID;
        
        uint32_t DFILT_reserved00D4[3]; /* 0x00D4-0x00DF */
        
        union {                  /* FINTVAL Register */
            vuint32_t R;
            struct {
                vuint32_t SUM_VALUE:32;
            } B;
        } FINTVAL;
        
        union {                  /* FINTCNT Register */
            vuint32_t R;
            struct {
                vuint32_t COUNT:32;
            } B;
        } FINTCNT;
        
        union {                  /* CINTVAL Register */
            vuint32_t R;
            struct {
                vuint32_t SUM_VALUE:32;
            } B;
        } CINTVAL;
        
        union {                  /* CINTCNT Register */
            vuint32_t R;
            struct {
                vuint32_t COUNT:32;
            } B;
        } CINTCNT;
        
        
    
    };

/****************************************************************************/
/*                          MODULE : DSPI                                   */
/****************************************************************************/

    struct DSPI_tag {
    
        union {                  /* Module Configuration Register */
            vuint32_t R;
            struct {
                vuint32_t MSTR:1;
                vuint32_t CONT_SCKE:1;
                vuint32_t DCONF:2;
                vuint32_t FRZ:1;
                vuint32_t MTFE:1;
                vuint32_t PCSSE:1;
                vuint32_t ROOE:1;
                vuint32_t PCSIS7:1;
                vuint32_t PCSIS6:1;
                vuint32_t PCSIS5:1;
                vuint32_t PCSIS4:1;
                vuint32_t PCSIS3:1;
                vuint32_t PCSIS2:1;
                vuint32_t PCSIS1:1;
                vuint32_t PCSIS0:1;
                vuint32_t DOZE:1;
                vuint32_t MDIS:1;
                vuint32_t DIS_TXF:1;
                vuint32_t DIS_RXF:1;
                vuint32_t CLR_TXF:1;
                vuint32_t CLR_RXF:1;
                vuint32_t SMPL_PT:2;
                vuint32_t:7;
                vuint32_t HALT:1;
            } B;
        } MCR;
        
        uint32_t DSPI_reserved0004;  /* 0x0004-0x0007 */
        
        union {              /* Transfer Count Register */
            vuint32_t R;
            struct {
                vuint32_t TCNT:16;
                vuint32_t:16;
            } B;
        } TCR;
        
        union {              /* Clock and Transfer Attributes Registers */
            vuint32_t R;
            struct {
                vuint32_t DBR:1;
                vuint32_t FMSZ:4;
                vuint32_t CPOL:1;
                vuint32_t CPHA:1;
                vuint32_t LSBFE:1;
                vuint32_t PCSSCK:2;
                vuint32_t PASC:2;
                vuint32_t PDT:2;
                vuint32_t PBR:2;
                vuint32_t CSSCK:4;
                vuint32_t ASC:4;
                vuint32_t DT:4;
                vuint32_t BR:4;
            } B;
        } CTAR[8];
        
        union {                   /* Status Register */
            vuint32_t R;
            struct {
                vuint32_t TCF:1;
                vuint32_t TXRXS:1;
                vuint32_t:1;
                vuint32_t EOQF:1;
                vuint32_t TFUF:1;
                vuint32_t:1;
                vuint32_t TFFF:1;
                vuint32_t:5;
                vuint32_t RFOF:1;
                vuint32_t:1;
                vuint32_t RFDF:1;
                vuint32_t:1;
                vuint32_t TXCTR:4;
                vuint32_t TXNXTPTR:4;
                vuint32_t RXCTR:4;
                vuint32_t POPNXTPTR:4;
            } B;
        } SR;
        
        union {                 /* DMA/Interrupt Request Select and Enable Register */
            vuint32_t R;
            struct {
                vuint32_t TCFRE:1;
                vuint32_t:2;
                vuint32_t EOQFRE:1;
                vuint32_t TFUFRE:1;
                vuint32_t:1;
                vuint32_t TFFFRE:1;
                vuint32_t TFFFDIRS:1;
                vuint32_t:4;
                vuint32_t RFOFRE:1;
                vuint32_t:1;
                vuint32_t RFDFRE:1;
                vuint32_t RFDFDIRS:1;
                vuint32_t:16;
            } B;
        } RSER;
        
        union {                /* PUSH TX FIFO Register */
            vuint32_t R;
            struct {
                vuint32_t CONT:1;
                vuint32_t CTAS:3;
                vuint32_t EOQ:1;
                vuint32_t CTCNT:1;
                vuint32_t:2;
                vuint32_t PCS7:1;
                vuint32_t PCS6:1;
                vuint32_t PCS5:1;
                vuint32_t PCS4:1;
                vuint32_t PCS3:1;
                vuint32_t PCS2:1;
                vuint32_t PCS1:1;
                vuint32_t PCS0:1;
                vuint32_t TXDATA:16;
            } B;
        } PUSHR;
        
        union {                 /* POP RX FIFO Register */
            vuint32_t R;
            struct {
                vuint32_t:16;
                vuint32_t RXDATA:16;
            } B;
        } POPR;
        
        union {              /* Transmit FIFO Registers */
            vuint32_t R;
            struct {
                vuint32_t TXCMD:16;
                vuint32_t TXDATA:16;
            } B;
        } TXFR[4];
        
        uint32_t DSPI_reserved004C[12]; /* 0x004C-0x007B */
        
        union {              /* Transmit FIFO Registers */
            vuint32_t R;
            struct {
                vuint32_t:16;
                vuint32_t RXDATA:16;
            } B;
        } RXFR[4];
        
        uint32_t DSPI_reserved008C[12]; /* 0x008C-0x00BB */
        
        union {                /* DSI Configuration Register */
            vuint32_t R;
            struct {
                vuint32_t MTOE:1;
                vuint32_t:1;
                vuint32_t MTOCNT:6;
                vuint32_t:3;
                vuint32_t TSBC:1;
                vuint32_t TXSS:1;
                vuint32_t TPOL:1;
                vuint32_t TRRE:1;
                vuint32_t CID:1;
                vuint32_t DCONT:1;
                vuint32_t DSICTAS:3;
                vuint32_t:4;
                vuint32_t DPCS7:1;
                vuint32_t DPCS6:1;
                vuint32_t DPCS5:1;
                vuint32_t DPCS4:1;
                vuint32_t DPCS3:1;
                vuint32_t DPCS2:1;
                vuint32_t DPCS1:1;
                vuint32_t DPCS0:1;
            } B;
        } DSICR;
        
        union {                  /* DSI Serialization Data Register */
            vuint32_t R;
            struct {
                vuint32_t SER_DATA:32;
            } B;
        } SDR;
        
        union {                 /* DSI Alternate Serialization Data Register */
            vuint32_t R;
            struct {
                vuint32_t ASER_DATA:32;
            } B;
        } ASDR;
        
        union {                /* DSI Transmit Comparison Register */
            vuint32_t R;
            struct {
                vuint32_t COMP_DATA:32;
            } B;
        } COMPR;
        
        union {                  /* DSI deserialization Data Register */
            vuint32_t R;
            struct {
                vuint32_t DESER_DATA:32;
            } B;
        } DDR;
        
        union {
            vuint32_t R;
            struct {
                vuint32_t:3;
                vuint32_t TSBCNT:5;
                  vuint32_t:16;
                vuint32_t DPCS1_7:1;
                vuint32_t DPCS1_6:1;
                vuint32_t DPCS1_5:1;
                vuint32_t DPCS1_4:1;
                vuint32_t DPCS1_3:1;
                vuint32_t DPCS1_2:1;
                vuint32_t DPCS1_1:1;
                vuint32_t DPCS1_0:1;
            } B;
        } DSICR1;    
        uint32_t DSPI_reserved00D4[4043];  /* 0x00D4-0x3FFF */
    
    };

/****************************************************************************/
/*                          MODULE : eSCI                                   */
/****************************************************************************/

    struct ESCI_tag {
        union {                  /* Control Register 1 */
            vuint32_t R;
            struct {
                vuint32_t:3;
                vuint32_t SBR:13;
                vuint32_t LOOPS:1;
                vuint32_t:1;
                vuint32_t RSRC:1;
                vuint32_t M:1;
                vuint32_t WAKE:1;
                vuint32_t ILT:1;
                vuint32_t PE:1;
                vuint32_t PT:1;
                vuint32_t TIE:1;
                vuint32_t TCIE:1;
                vuint32_t RIE:1;
                vuint32_t ILIE:1;
                vuint32_t TE:1;
                vuint32_t RE:1;
                vuint32_t RWU:1;
                vuint32_t SBK:1;
            } B;
        } CR1;
        
        union {                  /* Control Register 2 */
            vuint16_t R;
            struct {
                vuint16_t MDIS:1;
                vuint16_t FBR:1;
                vuint16_t BSTP:1;
                vuint16_t IEBERR:1;
                vuint16_t RXDMA:1;
                vuint16_t TXDMA:1;
                vuint16_t BRK13:1;
                vuint16_t TXDIR:1;
                vuint16_t BESM13:1;
                vuint16_t SBSTP:1;
                vuint16_t RXPOL:1;
                vuint16_t PMSK:1;
                vuint16_t ORIE:1;
                vuint16_t NFIE:1;
                vuint16_t FEIE:1;
                vuint16_t PFIE:1;
            } B;
        } CR2;
        
        union {                   /* Data Register */
            vuint16_t R;

            struct {
                vuint16_t RN:1;
                vuint16_t TN:1;
                vuint16_t ERR:1;
                vuint16_t:1;
                vuint16_t RD_11:4;
                vuint16_t D:8;
            } B;
        } DR; /* Legacy naming - refer to SDR in Reference Manual */
        
        union {                   /* Status Register */
            vuint32_t R;
            struct {
                vuint32_t TDRE:1;
                vuint32_t TC:1;
                vuint32_t RDRF:1;
                vuint32_t IDLE:1;
                vuint32_t OR:1;
                vuint32_t NF:1;
                vuint32_t FE:1;
                vuint32_t PF:1;
                vuint32_t:3;
                vuint32_t BERR:1;
                vuint32_t:2;
                vuint32_t TACT:1;
                vuint32_t RAF:1;
                vuint32_t RXRDY:1;
                vuint32_t TXRDY:1;
                vuint32_t LWAKE:1;
                vuint32_t STO:1;
                vuint32_t PBERR:1;
                vuint32_t CERR:1;
                vuint32_t CKERR:1;
                vuint32_t FRC:1;
                vuint32_t:6;
                vuint32_t UREQ:1;
                vuint32_t OVFL:1;
            } B;
        } SR;
        
        union {                  /* LIN Control Register */
            vuint32_t R;
            struct {
                vuint32_t LRES:1;
                vuint32_t WU:1;
                vuint32_t WUD0:1;
                vuint32_t WUD1:1;
                vuint32_t :2;
                vuint32_t PRTY:1;
                vuint32_t LIN:1;
                vuint32_t RXIE:1;
                vuint32_t TXIE:1;
                vuint32_t WUIE:1;
                vuint32_t STIE:1;
                vuint32_t PBIE:1;
                vuint32_t CIE:1;
                vuint32_t CKIE:1;
                vuint32_t FCIE:1;
                vuint32_t:6;
                vuint32_t UQIE:1;
                vuint32_t OFIE:1;
                vuint32_t:8;
            } B;
        } LCR;
        
        union {                  /* LIN Transmit Register */
            vuint8_t R;
        } LTR;
        
        vuint8_t eSCI_reserved0011[3];  /* 0x0011-0x0013 */
        
        union {                  /* LIN Recieve Register */
            vuint8_t R;
            struct {
                vuint8_t D:8;
            } B;
        } LRR;
        
        vuint8_t eSCI_reserved0015[3];  /* 0x0015-0x0017 */
        
        union {                  /* LIN CRC Polynom Register  */
            vuint16_t R;
            struct {
                vuint16_t P:16;
            } B;
        } LPR;
        
        union {                  /* Control Register 3 */
            vuint16_t R;
            struct {
                vuint16_t:3;
                vuint16_t SYNM:1;
                vuint16_t EROE:1;
                vuint16_t ERFE:1;
                vuint16_t ERPE:1;
                vuint16_t M2:1;
                vuint16_t:8;
            } B;
        } CR3;

        uint32_t eSCI_reserved001C; /* 0x001C-0x001F */
        
        uint32_t eSCI_reserved0020[4088];  /* 0x0020-0x3FFF */
    
    };

/****************************************************************************/
/*                          MODULE : FlexCAN                                */
/****************************************************************************/
	struct canbuf_t {
            union {
                vuint32_t R;
                struct {
                    vuint32_t:4;
                    vuint32_t CODE:4;
                    vuint32_t:1;
                    vuint32_t SRR:1;
                    vuint32_t IDE:1;
                    vuint32_t RTR:1;
                    vuint32_t LENGTH:4;
                    vuint32_t TIMESTAMP:16;
                } B;
            } CS;
            
            union {
                vuint32_t R;
                struct {
                    vuint32_t PRIO:3;
                    vuint32_t STD_ID:11;
                    vuint32_t EXT_ID:18;
                } B;
            } ID;
            
            union {
                vuint8_t B[8];  /* Data buffer in Bytes (8 bits) */
                vuint16_t H[4]; /* Data buffer in Half-words (16 bits) */
                vuint32_t W[2]; /* Data buffer in words (32 bits) */
                vuint32_t R[2]; /* Data buffer in words (32 bits) */
            } DATA;
            
        };
		
		struct FLEXCAN_RXFIFO_t {
        union {
            vuint32_t R;
            struct {
                vuint32_t:9;
                vuint32_t SRR:1;
                vuint32_t IDE:1;
                vuint32_t RTR:1;
                vuint32_t LENGTH:4;
                vuint32_t TIMESTAMP:16;
            } B;
        } CS;

        union {
            vuint32_t R;
            struct {
                vuint32_t:3;
                vuint32_t STD_ID:11;
                vuint32_t EXT_ID:18;
            } B;
        } ID;

        union {
            vuint8_t B[8];      /* Data buffer in Bytes (8 bits) */
            vuint16_t H[4];     /* Data buffer in Half-words (16 bits) */
            vuint32_t W[2];     /* Data buffer in words (32 bits) */
            vuint32_t R[2];     /* Data buffer in words (32 bits) */
        } DATA;

        uint32_t FLEXCAN_RXFIFO_reserved[20];   /* {0x00E0-0x0090}/0x4 = 0x14 */

        union {
            vuint32_t R;
        } IDTABLE[8];

    };                          /* end of FLEXCAN_RXFIFO_t */
	
    struct FLEXCAN2_tag {
        union {                  /* Module Configuration Register */
            vuint32_t R;
            struct {
                vuint32_t MDIS:1;
                vuint32_t FRZ:1;
                vuint32_t FEN:1;
                vuint32_t HALT:1;
                vuint32_t NOTRDY:1;
                vuint32_t:1;
                vuint32_t SOFTRST:1;
                vuint32_t FRZACK:1;
                vuint32_t SUPV:1;
                vuint32_t:1;
                vuint32_t WRNEN:1;
                vuint32_t MDISACK:1;
                vuint32_t:1;
                vuint32_t DOZE:1;
                vuint32_t SRXDIS:1;
                vuint32_t BCC:1;   /* Legacy name: Refer to MBFEN in the reference manual */
                vuint32_t:2;
                vuint32_t LPRIO_EN:1;
                vuint32_t AEN:1;
                vuint32_t:2;
                vuint32_t IDAM:2;
                vuint32_t:2;
                vuint32_t MAXMB:6;
            } B;
        } MCR;
        
        union {                   /* Control Register */
            vuint32_t R;
            struct {
                vuint32_t PRESDIV:8;
                vuint32_t RJW:2;
                vuint32_t PSEG1:3;
                vuint32_t PSEG2:3;
                vuint32_t BOFFMSK:1;
                vuint32_t ERRMSK:1;
                vuint32_t CLKSRC:1;
                vuint32_t LPB:1;
                vuint32_t TWRNMSK:1;
                vuint32_t RWRNMSK:1;
                vuint32_t:2;
                vuint32_t SMP:1;
                vuint32_t BOFFREC:1;
                vuint32_t TSYN:1;
                vuint32_t LBUF:1;
                vuint32_t LOM:1;
                vuint32_t PROPSEG:3;
            } B;
        } CR; /* Legacy naming - refer to CTRL in Reference Manual */
        
        union {                /* Free Running Timer */
            vuint32_t R;
        } TIMER;
        
        int32_t FLEXCAN_reserved000C;  /* 0x000C-0x000F */
        
        union {              /* RX Global Mask */
            vuint32_t R;
            struct {
                vuint32_t MI31:1;
                vuint32_t MI30:1;
                vuint32_t MI29:1;
                vuint32_t MI28:1;
                vuint32_t MI27:1;
                vuint32_t MI26:1;
                vuint32_t MI25:1;
                vuint32_t MI24:1;
                vuint32_t MI23:1;
                vuint32_t MI22:1;
                vuint32_t MI21:1;
                vuint32_t MI20:1;
                vuint32_t MI19:1;
                vuint32_t MI18:1;
                vuint32_t MI17:1;
                vuint32_t MI16:1;
                vuint32_t MI15:1;
                vuint32_t MI14:1;
                vuint32_t MI13:1;
                vuint32_t MI12:1;
                vuint32_t MI11:1;
                vuint32_t MI10:1;
                vuint32_t MI9:1;
                vuint32_t MI8:1;
                vuint32_t MI7:1;
                vuint32_t MI6:1;
                vuint32_t MI5:1;
                vuint32_t MI4:1;
                vuint32_t MI3:1;
                vuint32_t MI2:1;
                vuint32_t MI1:1;
                vuint32_t MI0:1;
            } B;
        } RXGMASK;
        
        union {             /* RX 14 Mask */
            vuint32_t R;
            struct {
                vuint32_t MI31:1;
                vuint32_t MI30:1;
                vuint32_t MI29:1;
                vuint32_t MI28:1;
                vuint32_t MI27:1;
                vuint32_t MI26:1;
                vuint32_t MI25:1;
                vuint32_t MI24:1;
                vuint32_t MI23:1;
                vuint32_t MI22:1;
                vuint32_t MI21:1;
                vuint32_t MI20:1;
                vuint32_t MI19:1;
                vuint32_t MI18:1;
                vuint32_t MI17:1;
                vuint32_t MI16:1;
                vuint32_t MI15:1;
                vuint32_t MI14:1;
                vuint32_t MI13:1;
                vuint32_t MI12:1;
                vuint32_t MI11:1;
                vuint32_t MI10:1;
                vuint32_t MI9:1;
                vuint32_t MI8:1;
                vuint32_t MI7:1;
                vuint32_t MI6:1;
                vuint32_t MI5:1;
                vuint32_t MI4:1;
                vuint32_t MI3:1;
                vuint32_t MI2:1;
                vuint32_t MI1:1;
                vuint32_t MI0:1;
            } B;
        } RX14MASK;
        
        union {             /* RX 15 Mask */
            vuint32_t R;
            struct {
                vuint32_t MI31:1;
                vuint32_t MI30:1;
                vuint32_t MI29:1;
                vuint32_t MI28:1;
                vuint32_t MI27:1;
                vuint32_t MI26:1;
                vuint32_t MI25:1;
                vuint32_t MI24:1;
                vuint32_t MI23:1;
                vuint32_t MI22:1;
                vuint32_t MI21:1;
                vuint32_t MI20:1;
                vuint32_t MI19:1;
                vuint32_t MI18:1;
                vuint32_t MI17:1;
                vuint32_t MI16:1;
                vuint32_t MI15:1;
                vuint32_t MI14:1;
                vuint32_t MI13:1;
                vuint32_t MI12:1;
                vuint32_t MI11:1;
                vuint32_t MI10:1;
                vuint32_t MI9:1;
                vuint32_t MI8:1;
                vuint32_t MI7:1;
                vuint32_t MI6:1;
                vuint32_t MI5:1;
                vuint32_t MI4:1;
                vuint32_t MI3:1;
                vuint32_t MI2:1;
                vuint32_t MI1:1;
                vuint32_t MI0:1;
            } B;
        } RX15MASK;
        
        union {                  /* Error Counter Register */
            vuint32_t R;
            struct {
                vuint32_t:16;
                vuint32_t RXECNT:8;
                vuint32_t TXECNT:8;
            } B;
        } ECR;
        
        union {                  /* Error and Status Register */
            vuint32_t R;
            struct {
                vuint32_t:14;
                
                vuint32_t TWRNINT:1;
                vuint32_t RWRNINT:1;
                vuint32_t BIT1ERR:1;
                vuint32_t BIT0ERR:1;
                vuint32_t ACKERR:1;
                vuint32_t CRCERR:1;
                vuint32_t FRMERR:1;
                vuint32_t STFERR:1;
                vuint32_t TXWRN:1;
                vuint32_t RXWRN:1;
                vuint32_t IDLE:1;
                vuint32_t TXRX:1;
                vuint32_t FLTCONF:2;
                vuint32_t:1;
                vuint32_t BOFFINT:1;
                vuint32_t ERRINT:1;
                vuint32_t:1;
            } B;
        } ESR;
        
        union {                 /* Interruput Masks Register */
            vuint32_t R;
            struct {
                vuint32_t BUF63M:1;
                vuint32_t BUF62M:1;
                vuint32_t BUF61M:1;
                vuint32_t BUF60M:1;
                vuint32_t BUF59M:1;
                vuint32_t BUF58M:1;
                vuint32_t BUF57M:1;
                vuint32_t BUF56M:1;
                vuint32_t BUF55M:1;
                vuint32_t BUF54M:1;
                vuint32_t BUF53M:1;
                vuint32_t BUF52M:1;
                vuint32_t BUF51M:1;
                vuint32_t BUF50M:1;
                vuint32_t BUF49M:1;
                vuint32_t BUF48M:1;
                vuint32_t BUF47M:1;
                vuint32_t BUF46M:1;
                vuint32_t BUF45M:1;
                vuint32_t BUF44M:1;
                vuint32_t BUF43M:1;
                vuint32_t BUF42M:1;
                vuint32_t BUF41M:1;
                vuint32_t BUF40M:1;
                vuint32_t BUF39M:1;
                vuint32_t BUF38M:1;
                vuint32_t BUF37M:1;
                vuint32_t BUF36M:1;
                vuint32_t BUF35M:1;
                vuint32_t BUF34M:1;
                vuint32_t BUF33M:1;
                vuint32_t BUF32M:1;
            } B;
        } IMRH; /* Legacy naming - refer to IMASK2 in Reference Manual */
        
        union {                 /* Interruput Masks Register */
            vuint32_t R;
            struct {
                vuint32_t BUF31M:1;
                vuint32_t BUF30M:1;
                vuint32_t BUF29M:1;
                vuint32_t BUF28M:1;
                vuint32_t BUF27M:1;
                vuint32_t BUF26M:1;
                vuint32_t BUF25M:1;
                vuint32_t BUF24M:1;
                vuint32_t BUF23M:1;
                vuint32_t BUF22M:1;
                vuint32_t BUF21M:1;
                vuint32_t BUF20M:1;
                vuint32_t BUF19M:1;
                vuint32_t BUF18M:1;
                vuint32_t BUF17M:1;
                vuint32_t BUF16M:1;
                vuint32_t BUF15M:1;
                vuint32_t BUF14M:1;
                vuint32_t BUF13M:1;
                vuint32_t BUF12M:1;
                vuint32_t BUF11M:1;
                vuint32_t BUF10M:1;
                vuint32_t BUF09M:1;
                vuint32_t BUF08M:1;
                vuint32_t BUF07M:1;
                vuint32_t BUF06M:1;
                vuint32_t BUF05M:1;
                vuint32_t BUF04M:1;
                vuint32_t BUF03M:1;
                vuint32_t BUF02M:1;
                vuint32_t BUF01M:1;
                vuint32_t BUF00M:1;
            } B;
        } IMRL; /* Legacy naming - refer to IMASK1 in Reference Manual */
        
        union {                 /* Interruput Flag Register */
            vuint32_t R;
            struct {
                vuint32_t BUF63I:1;
                vuint32_t BUF62I:1;
                vuint32_t BUF61I:1;
                vuint32_t BUF60I:1;
                vuint32_t BUF59I:1;
                vuint32_t BUF58I:1;
                vuint32_t BUF57I:1;
                vuint32_t BUF56I:1;
                vuint32_t BUF55I:1;
                vuint32_t BUF54I:1;
                vuint32_t BUF53I:1;
                vuint32_t BUF52I:1;
                vuint32_t BUF51I:1;
                vuint32_t BUF50I:1;
                vuint32_t BUF49I:1;
                vuint32_t BUF48I:1;
                vuint32_t BUF47I:1;
                vuint32_t BUF46I:1;
                vuint32_t BUF45I:1;
                vuint32_t BUF44I:1;
                vuint32_t BUF43I:1;
                vuint32_t BUF42I:1;
                vuint32_t BUF41I:1;
                vuint32_t BUF40I:1;
                vuint32_t BUF39I:1;
                vuint32_t BUF38I:1;
                vuint32_t BUF37I:1;
                vuint32_t BUF36I:1;
                vuint32_t BUF35I:1;
                vuint32_t BUF34I:1;
                vuint32_t BUF33I:1;
                vuint32_t BUF32I:1;
            } B;
        } IFRH; /* Legacy naming - refer to IFLAG2 in Reference Manual */
        
        union {                 /* Interruput Flag Register */
            vuint32_t R;
            struct {
                vuint32_t BUF31I:1;
                vuint32_t BUF30I:1;
                vuint32_t BUF29I:1;
                vuint32_t BUF28I:1;
                vuint32_t BUF27I:1;
                vuint32_t BUF26I:1;
                vuint32_t BUF25I:1;
                vuint32_t BUF24I:1;
                vuint32_t BUF23I:1;
                vuint32_t BUF22I:1;
                vuint32_t BUF21I:1;
                vuint32_t BUF20I:1;
                vuint32_t BUF19I:1;
                vuint32_t BUF18I:1;
                vuint32_t BUF17I:1;
                vuint32_t BUF16I:1;
                vuint32_t BUF15I:1;
                vuint32_t BUF14I:1;
                vuint32_t BUF13I:1;
                vuint32_t BUF12I:1;
                vuint32_t BUF11I:1;
                vuint32_t BUF10I:1;
                vuint32_t BUF09I:1;
                vuint32_t BUF08I:1;
                vuint32_t BUF07I:1;
                vuint32_t BUF06I:1;
                vuint32_t BUF05I:1;
                vuint32_t BUF04I:1;
                vuint32_t BUF03I:1;
                vuint32_t BUF02I:1;
                vuint32_t BUF01I:1;
                vuint32_t BUF00I:1;
            } B;
        } IFRL; /* Legacy naming - refer to IFLAG1 in Reference Manual */
        
        uint32_t FLEXCAN_reserved0034[19];  /* 0x0034-0x007F */
        
        struct canbuf_t BUF[64];
		
        int32_t FLEXCAN_reserved0480[256]; /* 0x0480-0x087F */
        
        union {            /* RX Individual Mask Registers */
            vuint32_t R;
            struct {
                vuint32_t MI31:1;
                vuint32_t MI30:1;
                vuint32_t MI29:1;
                vuint32_t MI28:1;
                vuint32_t MI27:1;
                vuint32_t MI26:1;
                vuint32_t MI25:1;
                vuint32_t MI24:1;
                vuint32_t MI23:1;
                vuint32_t MI22:1;
                vuint32_t MI21:1;
                vuint32_t MI20:1;
                vuint32_t MI19:1;
                vuint32_t MI18:1;
                vuint32_t MI17:1;
                vuint32_t MI16:1;
                vuint32_t MI15:1;
                vuint32_t MI14:1;
                vuint32_t MI13:1;
                vuint32_t MI12:1;
                vuint32_t MI11:1;
                vuint32_t MI10:1;
                vuint32_t MI9:1;
                vuint32_t MI8:1;
                vuint32_t MI7:1;
                vuint32_t MI6:1;
                vuint32_t MI5:1;
                vuint32_t MI4:1;
                vuint32_t MI3:1;
                vuint32_t MI2:1;
                vuint32_t MI1:1;
                vuint32_t MI0:1;
            } B;
        } RXIMR[64];
        
        int32_t FLEXCAN_reserved0980[3488]; /* 0x0980-0x3FFF */
    
    };

/****************************************************************************/
/*                          MODULE : FlexRay                                */
/****************************************************************************/

    typedef union uMVR {
        vuint16_t R;
        struct {
            vuint16_t CHIVER:8; /* CHI Version Number */
            vuint16_t PEVER:8;  /* PE Version Number */
        } B;
    } MVR_t;

    typedef union uMCR {
        vuint16_t R;
        struct {
            vuint16_t MEN:1;    /* module enable */
            vuint16_t SBFF:1;   /* sys bus failure freeze */
            vuint16_t SCM:1;   /* single channel mode */
            vuint16_t CHB:1;    /* channel B enable */
            vuint16_t CHA:1;    /* channel A enable */
            vuint16_t SFFE:1;   /* synchronization frame filter enable */
            vuint16_t:1;
            vuint16_t R:1;      /* reserved, read as zero. system must not 
                                   write 1 to this bit */
            vuint16_t FUM:1;    /* FIFO update mode */
            vuint16_t FAM:1;    /* FIFO address mode */
            vuint16_t:1;
            vuint16_t CLKSEL:1; /* protocol engine clock source select */
            vuint16_t BITRATE:3;   /* flexray bus bitrate */
            vuint16_t:1;
        } B;
    } MCR_t;
    
    typedef union uSTBSCR {
        vuint16_t R;
        struct {
            vuint16_t WMD:1;      /* write mode */
            vuint16_t:3;
            vuint16_t STBSSEL:4;  /* strobe signal select */
            vuint16_t:3;
            vuint16_t ENB:1;      /* strobe signal enable */
            vuint16_t:2;
            vuint16_t STBPSEL:2;  /* strobe port select */
        } B;
    } STBSCR_t;
    
    typedef union uMBDSR {
        vuint16_t R;
        struct {
            vuint16_t:1;
            vuint16_t MBSEG2DS:7;       /* message buffer segment 2 data size */
            vuint16_t:1;
            vuint16_t MBSEG1DS:7;       /* message buffer segment 1 data size */
        } B;
    } MBDSR_t;
    typedef union uMBSSUTR {
        vuint16_t R;
        struct {
            vuint16_t:1;
            vuint16_t LAST_MB_SEG1:7;   /* last message buffer control register for message buffer segment 1 */
            vuint16_t:1;
            vuint16_t LAST_MB_UTIL:7;   /* last message buffer utilized */
        } B;
    } MBSSUTR_t;

    typedef union uPOCR {
        vuint16_t R;
        vuint8_t byte[2];
        struct {
            vuint16_t WME:1;    /* write mode external correction command */
            vuint16_t:3;
            vuint16_t EOC_AP:2; /* external offset correction application */
            vuint16_t ERC_AP:2; /* external rate correction application */
            vuint16_t BSY:1;    /* command write busy / write mode command */
            vuint16_t:3;
            vuint16_t POCCMD:4; /* protocol command */
        } B;
    } POCR_t;
/* protocol commands */
    typedef union uGIFER {
        vuint16_t R;
        struct {
            vuint16_t MIF:1;    /* module interrupt flag */
            vuint16_t PRIF:1;   /* protocol interrupt flag */
            vuint16_t CHIF:1;   /* CHI interrupt flag */
            vuint16_t WKUPIF:1; /* wakeup interrupt flag *//* Legacy naming: Refer to WUPIF in the reference manual */
            vuint16_t FNEBIF:1; /* receive FIFO channel B not empty interrupt flag *//* Legacy naming: Refer to FAFBIF in the reference manual */
            vuint16_t FNEAIF:1; /* receive FIFO channel A not empty interrupt flag *//* Legacy naming: Refer to FAFAIF in the reference manual */
            vuint16_t RBIF:1;   /* receive message buffer interrupt flag */
            vuint16_t TBIF:1;   /* transmit buffer interrupt flag */
            vuint16_t MIE:1;    /* module interrupt enable */
            vuint16_t PRIE:1;   /* protocol interrupt enable */
            vuint16_t CHIE:1;   /* CHI interrupt enable */
            vuint16_t WKUPIE:1; /* wakeup interrupt enable *//* Legacy naming: Refer to WUPIE in the reference manual */
            vuint16_t FNEBIE:1; /* receive FIFO channel B not empty interrupt enable *//* Legacy naming: Refer to FAFBIE in the reference manual */
            vuint16_t FNEAIE:1; /* receive FIFO channel A not empty interrupt enable *//* Legacy naming: Refer to FAFAIE in the reference manual */
            vuint16_t RBIE:1;   /* receive message buffer interrupt enable */
            vuint16_t TBIE:1;   /* transmit buffer interrupt enable */
        } B;
    } GIFER_t;
    typedef union uPIFR0 {
        vuint16_t R;
        struct {
            vuint16_t FATLIF:1; /* fatal protocol error interrupt flag */
            vuint16_t INTLIF:1; /* internal protocol error interrupt flag */
            vuint16_t ILCFIF:1; /* illegal protocol configuration flag */
            vuint16_t CSAIF:1;  /* cold start abort interrupt flag */
            vuint16_t MRCIF:1;  /* missing rate correctio interrupt flag */
            vuint16_t MOCIF:1;  /* missing offset correctio interrupt flag */
            vuint16_t CCLIF:1;  /* clock correction limit reached interrupt flag */
            vuint16_t MXSIF:1;  /* max sync frames detected interrupt flag */
            vuint16_t MTXIF:1;  /* media access test symbol received flag */
            vuint16_t LTXBIF:1; /* pdLatestTx violation on channel B interrupt flag */
            vuint16_t LTXAIF:1; /* pdLatestTx violation on channel A interrupt flag */
            vuint16_t TBVBIF:1; /* Transmission across boundary on channel B Interrupt Flag */
            vuint16_t TBVAIF:1; /* Transmission across boundary on channel A Interrupt Flag */
            vuint16_t TI2IF:1;  /* timer 2 expired interrupt flag */
            vuint16_t TI1IF:1;  /* timer 1 expired interrupt flag */
            vuint16_t CYSIF:1;  /* cycle start interrupt flag */
        } B;
    } PIFR0_t;
    typedef union uPIFR1 {
        vuint16_t R;
        struct {
            vuint16_t EMCIF:1;  /* error mode changed interrupt flag */
            vuint16_t IPCIF:1;  /* illegal protocol command interrupt flag */
            vuint16_t PECFIF:1; /* protocol engine communication failure interrupt flag */
            vuint16_t PSCIF:1;  /* Protocol State Changed Interrupt Flag */
            vuint16_t SSI3IF:1; /* slot status counter incremented interrupt flag */
            vuint16_t SSI2IF:1; /* slot status counter incremented interrupt flag */
            vuint16_t SSI1IF:1; /* slot status counter incremented interrupt flag */
            vuint16_t SSI0IF:1; /* slot status counter incremented interrupt flag */
            vuint16_t:2;
            vuint16_t EVTIF:1;  /* even cycle table written interrupt flag */
            vuint16_t ODTIF:1;  /* odd cycle table written interrupt flag */
            vuint16_t:4;
        } B;
    } PIFR1_t;
    typedef union uPIER0 {
        vuint16_t R;
        struct {
            vuint16_t FATLIE:1; /* fatal protocol error interrupt enable */
            vuint16_t INTLIE:1; /* internal protocol error interrupt interrupt enable  */
            vuint16_t ILCFIE:1; /* illegal protocol configuration interrupt enable */
            vuint16_t CSAIE:1;  /* cold start abort interrupt enable */
            vuint16_t MRCIE:1;  /* missing rate correctio interrupt enable */
            vuint16_t MOCIE:1;  /* missing offset correctio interrupt enable */
            vuint16_t CCLIE:1;  /* clock correction limit reached interrupt enable */
            vuint16_t MXSIE:1;  /* max sync frames detected interrupt enable */
            vuint16_t MTXIE:1;  /* media access test symbol received interrupt enable */
            vuint16_t LTXBIE:1; /* pdLatestTx violation on channel B interrupt enable */
            vuint16_t LTXAIE:1; /* pdLatestTx violation on channel A interrupt enable */
            vuint16_t TBVBIE:1; /* Transmission across boundary on channel B Interrupt enable */
            vuint16_t TBVAIE:1; /* Transmission across boundary on channel A Interrupt enable */
            vuint16_t TI2IE:1;  /* timer 2 expired interrupt enable */
            vuint16_t TI1IE:1;  /* timer 1 expired interrupt enable */
            vuint16_t CYSIE:1;  /* cycle start interrupt enable */
        } B;
    } PIER0_t;
    typedef union uPIER1 {
        vuint16_t R;
        struct {
            vuint16_t EMCIE:1;  /* error mode changed interrupt enable */
            vuint16_t IPCIE:1;  /* illegal protocol command interrupt enable */
            vuint16_t PECFIE:1; /* protocol engine communication failure interrupt enable */
            vuint16_t PSCIE:1;  /* Protocol State Changed Interrupt enable */
            vuint16_t SSI3IE:1; /* slot status counter incremented interrupt enable */
            vuint16_t SSI2IE:1; /* slot status counter incremented interrupt enable */
            vuint16_t SSI1IE:1; /* slot status counter incremented interrupt enable */
            vuint16_t SSI0IE:1; /* slot status counter incremented interrupt enable */
            vuint16_t:2;
            vuint16_t EVTIE:1;  /* even cycle table written interrupt enable */
            vuint16_t ODTIE:1;  /* odd cycle table written interrupt enable */
            vuint16_t:4;
        } B;
    } PIER1_t;
    typedef union uCHIERFR {
        vuint16_t R;
        struct {
            vuint16_t FRLBEF:1; /* flame lost channel B error flag */
            vuint16_t FRLAEF:1; /* frame lost channel A error flag */
            vuint16_t PCMIEF:1; /* command ignored error flag */
            vuint16_t FOVBEF:1; /* receive FIFO overrun channel B error flag */
            vuint16_t FOVAEF:1; /* receive FIFO overrun channel A error flag */
            vuint16_t MSBEF:1;  /* message buffer search error flag *//* Legacy naming: Refer to MBSEF in the reference manual */
            vuint16_t MBUEF:1;  /* message buffer utilization error flag */
            vuint16_t LCKEF:1;  /* lock error flag */
            vuint16_t DBLEF:1;  /* double transmit message buffer lock error flag */
            vuint16_t SBCFEF:1; /* system bus communication failure error flag */
            vuint16_t FIDEF:1;  /* frame ID error flag */
            vuint16_t DPLEF:1;  /* dynamic payload length error flag */
            vuint16_t SPLEF:1;  /* static payload length error flag */
            vuint16_t NMLEF:1;  /* network management length error flag */
            vuint16_t NMFEF:1;  /* network management frame error flag */
            vuint16_t ILSAEF:1; /* illegal access error flag */
        } B;
    } CHIERFR_t;
    typedef union uMBIVEC {
        vuint16_t R;
        struct {
            vuint16_t:1;
            vuint16_t TBIVEC:7; /* transmit buffer interrupt vector */
            vuint16_t:1;
            vuint16_t RBIVEC:7; /* receive buffer interrupt vector */
        } B;
    } MBIVEC_t;

    typedef union uPSR0 {
        vuint16_t R;
        struct {
            vuint16_t ERRMODE:2;        /* error mode */
            vuint16_t SLOTMODE:2;       /* slot mode */
            vuint16_t:1;
            vuint16_t PROTSTATE:3;      /* protocol state */
            vuint16_t SUBSTATE:4;       /* protocol sub state *//* Legacy naming: Refer to STARTUPSTATE in the reference manual */
            vuint16_t:1;
            vuint16_t WAKEUPSTATUS:3;   /* wakeup status */
        } B;
    } PSR0_t;

/* protocol states */
/* protocol sub-states */
/* wakeup status */
    typedef union uPSR1 {
        vuint16_t R;
        struct {
            vuint16_t CSAA:1;   /* cold start attempt abort flag */
            vuint16_t SCP:1;    /* cold start path *//* Legacy naming: Refer to CSP in the reference manual */
            vuint16_t:1;
            vuint16_t REMCSAT:5;/* remanining coldstart attempts */
            vuint16_t CPN:1;    /* cold start noise path */
            vuint16_t HHR:1;    /* host halt request pending */
            vuint16_t FRZ:1;    /* freeze occured */
            vuint16_t APTAC:5;  /* allow passive to active counter */
        } B;
    } PSR1_t;
    typedef union uPSR2 {
        vuint16_t R;
        struct {
            vuint16_t NBVB:1;   /* NIT boundary violation on channel B */
            vuint16_t NSEB:1;   /* NIT syntax error on channel B */
            vuint16_t STCB:1;   /* symbol window transmit conflict on channel B */
            vuint16_t SBVB:1;   /* symbol window boundary violation on channel B */
            vuint16_t SSEB:1;   /* symbol window syntax error on channel B */
            vuint16_t MTB:1;    /* media access test symbol MTS received on channel B */
            vuint16_t NBVA:1;   /* NIT boundary violation on channel A */
            vuint16_t NSEA:1;   /* NIT syntax error on channel A */
            vuint16_t STCA:1;   /* symbol window transmit conflict on channel A */
            vuint16_t SBVA:1;   /* symbol window boundary violation on channel A */
            vuint16_t SSEA:1;   /* symbol window syntax error on channel A */
            vuint16_t MTA:1;    /* media access test symbol MTS received on channel A */
            vuint16_t CLKCORRFAILCNT:4; /* clock correction failed counter */
        } B;
    } PSR2_t;
    typedef union uPSR3 {
        vuint16_t R;
        struct {
            vuint16_t:2;
            vuint16_t WUB:1;    /* wakeup symbol received on channel B */
            vuint16_t ABVB:1;   /* aggregated boundary violation on channel B */
            vuint16_t AACB:1;   /* aggregated additional communication on channel B */
            vuint16_t ACEB:1;   /* aggregated content error on channel B */
            vuint16_t ASEB:1;   /* aggregated syntax error on channel B */
            vuint16_t AVFB:1;   /* aggregated valid frame on channel B */
            vuint16_t:2;
            vuint16_t WUA:1;    /* wakeup symbol received on channel A */
            vuint16_t ABVA:1;   /* aggregated boundary violation on channel A */
            vuint16_t AACA:1;   /* aggregated additional communication on channel A */
            vuint16_t ACEA:1;   /* aggregated content error on channel A */
            vuint16_t ASEA:1;   /* aggregated syntax error on channel A */
            vuint16_t AVFA:1;   /* aggregated valid frame on channel A */
        } B;
    } PSR3_t;
    typedef union uCIFRR {
        vuint16_t R;
        struct {
            vuint16_t:8;
            vuint16_t MIFR:1;   /* module interrupt flag */
            vuint16_t PRIFR:1;  /* protocol interrupt flag */
            vuint16_t CHIFR:1;  /* CHI interrupt flag */
            vuint16_t WUPIFR:1; /* wakeup interrupt flag */
            vuint16_t FNEBIFR:1;        /* receive fifo channel B no empty interrupt flag *//* Legacy naming: Refer to FAFBIF in the reference manual */
            vuint16_t FNEAIFR:1;        /* receive fifo channel A no empty interrupt flag *//* Legacy naming: Refer to FAFAIF in the reference manual */
            vuint16_t RBIFR:1;  /* receive message buffer interrupt flag */
            vuint16_t TBIFR:1;  /* transmit buffer interrupt flag */
        } B;
    } CIFRR_t;
    
    typedef union uSYMATOR {
        vuint16_t R;
        struct {
            vuint16_t:8;
            vuint16_t TIMEOUT:8;  /* system memory access time-out */
        } B;
    } SYMATOR_t;
    
    
    typedef union uSFCNTR {
        vuint16_t R;
        struct {
            vuint16_t SFEVB:4;  /* sync frames channel B, even cycle */
            vuint16_t SFEVA:4;  /* sync frames channel A, even cycle */
            vuint16_t SFODB:4;  /* sync frames channel B, odd cycle */
            vuint16_t SFODA:4;  /* sync frames channel A, odd cycle */
        } B;
    } SFCNTR_t;

    typedef union uSFTCCSR {
        vuint16_t R;
        struct {
            vuint16_t ELKT:1;   /* even cycle tables lock and unlock trigger */
            vuint16_t OLKT:1;   /* odd cycle tables lock and unlock trigger */
            vuint16_t CYCNUM:6; /* cycle number */
            vuint16_t ELKS:1;   /* even cycle tables lock status */
            vuint16_t OLKS:1;   /* odd cycle tables lock status */
            vuint16_t EVAL:1;   /* even cycle tables valid */
            vuint16_t OVAL:1;   /* odd cycle tables valid */
            vuint16_t:1;
            vuint16_t OPT:1;    /*one pair trigger */
            vuint16_t SDVEN:1;  /* sync frame deviation table enable */
            vuint16_t SIDEN:1;  /* sync frame ID table enable */
        } B;
    } SFTCCSR_t;
    typedef union uSFIDRFR {
        vuint16_t R;
        struct {
            vuint16_t:6;
            vuint16_t SYNFRID:10;       /* sync frame rejection ID */
        } B;
    } SFIDRFR_t;

    typedef union uTICCR {
        vuint16_t R;
        struct {
            vuint16_t:2;
            vuint16_t T2CFG:1;  /* timer 2 configuration */
            vuint16_t T2REP:1;  /* timer 2 repetitive mode */
            vuint16_t:1;
            vuint16_t T2SP:1;   /* timer 2 stop */
            vuint16_t T2TR:1;   /* timer 2 trigger */
            vuint16_t T2ST:1;   /* timer 2 state */
            vuint16_t:3;
            vuint16_t T1REP:1;  /* timer 1 repetitive mode */
            vuint16_t:1;
            vuint16_t T1SP:1;   /* timer 1 stop */
            vuint16_t T1TR:1;   /* timer 1 trigger */
            vuint16_t T1ST:1;   /* timer 1 state */
        } B;
    } TICCR_t;
    typedef union uTI1CYSR {
        vuint16_t R;
        struct {
            vuint16_t:2;
            vuint16_t TI1CYCVAL:6;      /* timer 1 cycle filter value */
            vuint16_t:2;
            vuint16_t TI1CYCMSK:6;      /* timer 1 cycle filter mask */

        } B;
    } TI1CYSR_t;

    typedef union uSSSR {
        vuint16_t R;
        struct {
            vuint16_t WMD:1;    /* write mode */
            vuint16_t:1;
            vuint16_t SEL:2;    /* static slot number */
            vuint16_t:1;
            vuint16_t SLOTNUMBER:11;    /* selector */
        } B;
    } SSSR_t;

    typedef union uSSCCR {
        vuint16_t R;
        struct {
            vuint16_t WMD:1;    /* write mode */
            vuint16_t:1;
            vuint16_t SEL:2;    /* selector */
            vuint16_t:1;
            vuint16_t CNTCFG:2; /* counter configuration */
            vuint16_t MCY:1;    /* multi cycle selection */
            vuint16_t VFR:1;    /* valid frame selection */
            vuint16_t SYF:1;    /* sync frame selection */
            vuint16_t NUF:1;    /* null frame selection  */
            vuint16_t SUF:1;    /* startup frame selection */
            vuint16_t STATUSMASK:4;     /* slot status mask */
        } B;
    } SSCCR_t;
    typedef union uSSR {
        vuint16_t R;
        struct {
            vuint16_t VFB:1;    /* valid frame on channel B */
            vuint16_t SYB:1;    /* valid sync frame on channel B */
            vuint16_t NFB:1;    /* valid null frame on channel B */
            vuint16_t SUB:1;    /* valid startup frame on channel B */
            vuint16_t SEB:1;    /* syntax error on channel B */
            vuint16_t CEB:1;    /* content error on channel B */
            vuint16_t BVB:1;    /* boundary violation on channel B */
            vuint16_t TCB:1;    /* tx conflict on channel B */
            vuint16_t VFA:1;    /* valid frame on channel A */
            vuint16_t SYA:1;    /* valid sync frame on channel A */
            vuint16_t NFA:1;    /* valid null frame on channel A */
            vuint16_t SUA:1;    /* valid startup frame on channel A */
            vuint16_t SEA:1;    /* syntax error on channel A */
            vuint16_t CEA:1;    /* content error on channel A */
            vuint16_t BVA:1;    /* boundary violation on channel A */
            vuint16_t TCA:1;    /* tx conflict on channel A */
        } B;                                                              
    } SSR_t;
    typedef union uMTSCFR {
        vuint16_t R;
        struct {
            vuint16_t MTE:1;    /* media access test symbol transmission enable */
            vuint16_t:1;
            vuint16_t CYCCNTMSK:6;      /* cycle counter mask */
            vuint16_t:2;
            vuint16_t CYCCNTVAL:6;      /* cycle counter value */
        } B;
    } MTSCFR_t;
    typedef union uRSBIR {
        vuint16_t R;
        struct {
            vuint16_t WMD:1;    /* write mode */
            vuint16_t:1;
            vuint16_t SEL:2;    /* selector */
            vuint16_t:4;
            vuint16_t RSBIDX:8; /* receive shadow buffer index */
        } B;
    } RSBIR_t;
    typedef union uRFDSR {
        vuint16_t R;
        struct {
            vuint16_t FIFODEPTH:8;      /* fifo depth */
            vuint16_t:1;
            vuint16_t ENTRYSIZE:7;      /* entry size */
        } B;
    } RFDSR_t;

    typedef union uRFRFCFR {
        vuint16_t R;
        struct {
            vuint16_t WMD:1;    /* write mode */
            vuint16_t IBD:1;    /* interval boundary */
            vuint16_t SEL:2;    /* filter number */
            vuint16_t:1;
            vuint16_t SID:11;   /* slot ID */
        } B;
    } RFRFCFR_t;

    typedef union uRFRFCTR {
        vuint16_t R;
        struct {
            vuint16_t:4;
            vuint16_t F3MD:1;   /* filter mode */
            vuint16_t F2MD:1;   /* filter mode */
            vuint16_t F1MD:1;   /* filter mode */
            vuint16_t F0MD:1;   /* filter mode */
            vuint16_t:4;
            vuint16_t F3EN:1;   /* filter enable */
            vuint16_t F2EN:1;   /* filter enable */
            vuint16_t F1EN:1;   /* filter enable */
            vuint16_t F0EN:1;   /* filter enable */
        } B;
    } RFRFCTR_t;
    typedef union uPCR0 {
        vuint16_t R;
        struct {
            vuint16_t ACTION_POINT_OFFSET:6;
            vuint16_t STATIC_SLOT_LENGTH:10;
        } B;
    } PCR0_t;

    typedef union uPCR1 {
        vuint16_t R;
        struct {
            vuint16_t:2;
            vuint16_t MACRO_AFTER_FIRST_STATIC_SLOT:14;
        } B;
    } PCR1_t;

    typedef union uPCR2 {
        vuint16_t R;
        struct {
            vuint16_t MINISLOT_AFTER_ACTION_POINT:6;
            vuint16_t NUMBER_OF_STATIC_SLOTS:10;
        } B;
    } PCR2_t;

    typedef union uPCR3 {
        vuint16_t R;
        struct {
            vuint16_t WAKEUP_SYMBOL_RX_LOW:6;
            vuint16_t MINISLOT_ACTION_POINT_OFFSET:5;
            vuint16_t COLDSTART_ATTEMPTS:5;
        } B;
    } PCR3_t;

    typedef union uPCR4 {
        vuint16_t R;
        struct {
            vuint16_t CAS_RX_LOW_MAX:7;
            vuint16_t WAKEUP_SYMBOL_RX_WINDOW:9;
        } B;
    } PCR4_t;

    typedef union uPCR5 {
        vuint16_t R;
        struct {
            vuint16_t TSS_TRANSMITTER:4;
            vuint16_t WAKEUP_SYMBOL_TX_LOW:6;
            vuint16_t WAKEUP_SYMBOL_RX_IDLE:6;
        } B;
    } PCR5_t;

    typedef union uPCR6 {
        vuint16_t R;
        struct {
            vuint16_t:1;
            vuint16_t SYMBOL_WINDOW_AFTER_ACTION_POINT:8;
            vuint16_t MACRO_INITIAL_OFFSET_A:7;
        } B;
    } PCR6_t;

    typedef union uPCR7 {
        vuint16_t R;
        struct {
            vuint16_t DECODING_CORRECTION_B:9;
            vuint16_t MICRO_PER_MACRO_NOM_HALF:7;
        } B;
    } PCR7_t;

    typedef union uPCR8 {
        vuint16_t R;
        struct {
            vuint16_t MAX_WITHOUT_CLOCK_CORRECTION_FATAL:4;
            vuint16_t MAX_WITHOUT_CLOCK_CORRECTION_PASSIVE:4;
            vuint16_t WAKEUP_SYMBOL_TX_IDLE:8;
        } B;
    } PCR8_t;

    typedef union uPCR9 {
        vuint16_t R;
        struct {
            vuint16_t MINISLOT_EXISTS:1;
            vuint16_t SYMBOL_WINDOW_EXISTS:1;
            vuint16_t OFFSET_CORRECTION_OUT:14;
        } B;
    } PCR9_t;

    typedef union uPCR10 {
        vuint16_t R;
        struct {
            vuint16_t SINGLE_SLOT_ENABLED:1;
            vuint16_t WAKEUP_CHANNEL:1;
            vuint16_t MACRO_PER_CYCLE:14;
        } B;
    } PCR10_t;

    typedef union uPCR11 {
        vuint16_t R;
        struct {
            vuint16_t KEY_SLOT_USED_FOR_STARTUP:1;
            vuint16_t KEY_SLOT_USED_FOR_SYNC:1;
            vuint16_t OFFSET_CORRECTION_START:14;
        } B;
    } PCR11_t;

    typedef union uPCR12 {
        vuint16_t R;
        struct {
            vuint16_t ALLOW_PASSIVE_TO_ACTIVE:5;
            vuint16_t KEY_SLOT_HEADER_CRC:11;
        } B;
    } PCR12_t;

    typedef union uPCR13 {
        vuint16_t R;
        struct {
            vuint16_t FIRST_MINISLOT_ACTION_POINT_OFFSET:6;
            vuint16_t STATIC_SLOT_AFTER_ACTION_POINT:10;
        } B;
    } PCR13_t;

    typedef union uPCR14 {
        vuint16_t R;
        struct {
            vuint16_t RATE_CORRECTION_OUT:11;
            vuint16_t LISTEN_TIMEOUT_H:5;
        } B;
    } PCR14_t;

    typedef union uPCR15 {
        vuint16_t R;
        struct {
            vuint16_t LISTEN_TIMEOUT_L:16;
        } B;
    } PCR15_t;

    typedef union uPCR16 {
        vuint16_t R;
        struct {
            vuint16_t MACRO_INITIAL_OFFSET_B:7;
            vuint16_t NOISE_LISTEN_TIMEOUT_H:9;
        } B;
    } PCR16_t;

    typedef union uPCR17 {
        vuint16_t R;
        struct {
            vuint16_t NOISE_LISTEN_TIMEOUT_L:16;
        } B;
    } PCR17_t;

    typedef union uPCR18 {
        vuint16_t R;
        struct {
            vuint16_t WAKEUP_PATTERN:6;
            vuint16_t KEY_SLOT_ID:10;
        } B;
    } PCR18_t;

    typedef union uPCR19 {
        vuint16_t R;
        struct {
            vuint16_t DECODING_CORRECTION_A:9;
            vuint16_t PAYLOAD_LENGTH_STATIC:7;
        } B;
    } PCR19_t;

    typedef union uPCR20 {
        vuint16_t R;
        struct {
            vuint16_t MICRO_INITIAL_OFFSET_B:8;
            vuint16_t MICRO_INITIAL_OFFSET_A:8;
        } B;
    } PCR20_t;

    typedef union uPCR21 {
        vuint16_t R;
        struct {
            vuint16_t EXTERN_RATE_CORRECTION:3;
            vuint16_t LATEST_TX:13;
        } B;
    } PCR21_t;

    typedef union uPCR22 {
        vuint16_t R;
        struct {
            vuint16_t:1;
            vuint16_t COMP_ACCEPTED_STARTUP_RANGE_A:11;
            vuint16_t MICRO_PER_CYCLE_H:4;
        } B;
    } PCR22_t;

    typedef union uPCR23 {
        vuint16_t R;
        struct {
            vuint16_t micro_per_cycle_l:16;
        } B;
    } PCR23_t;

    typedef union uPCR24 {
        vuint16_t R;
        struct {
            vuint16_t CLUSTER_DRIFT_DAMPING:5;
            vuint16_t MAX_PAYLOAD_LENGTH_DYNAMIC:7;
            vuint16_t MICRO_PER_CYCLE_MIN_H:4;
        } B;
    } PCR24_t;

    typedef union uPCR25 {
        vuint16_t R;
        struct {
            vuint16_t MICRO_PER_CYCLE_MIN_L:16;
        } B;
    } PCR25_t;

    typedef union uPCR26 {
        vuint16_t R;
        struct {
            vuint16_t ALLOW_HALT_DUE_TO_CLOCK:1;
            vuint16_t COMP_ACCEPTED_STARTUP_RANGE_B:11;
            vuint16_t MICRO_PER_CYCLE_MAX_H:4;
        } B;
    } PCR26_t;

    typedef union uPCR27 {
        vuint16_t R;
        struct {
            vuint16_t MICRO_PER_CYCLE_MAX_L:16;
        } B;
    } PCR27_t;

    typedef union uPCR28 {
        vuint16_t R;
        struct {
            vuint16_t DYNAMIC_SLOT_IDLE_PHASE:2;
            vuint16_t MACRO_AFTER_OFFSET_CORRECTION:14;
        } B;
    } PCR28_t;

    typedef union uPCR29 {
        vuint16_t R;
        struct {
            vuint16_t EXTERN_OFFSET_CORRECTION:3;
            vuint16_t MINISLOTS_MAX:13;
        } B;
    } PCR29_t;

    typedef union uPCR30 {
        vuint16_t R;
        struct {
            vuint16_t:12;
            vuint16_t SYNC_NODE_MAX:4;
        } B;
    } PCR30_t;

    typedef union uRFSYMBADHR {
        vuint16_t R;
        struct {
            vuint16_t SMBA:16;
        } B;
    } RFSYMBADHR_t;
    
    typedef union uRFSYMBADLR {
        vuint16_t R;
        struct {
            vuint16_t SMBA:12;
            vuint16_t:4;
        } B;
    } RFSYMBADLR_t;
    
    typedef union uRFPTR {
        vuint16_t R;
        struct {
            vuint16_t:2;
            vuint16_t PTD:14;
        } B;
    } RFPTR_t;
    
    typedef union uRFFLPCR {
        vuint16_t R;
    } RFFLPCR_t;

    typedef struct uMSG_BUFF_CCS {
        union {
            vuint16_t R;
            struct {
                vuint16_t:1;
                vuint16_t MCM:1;        /* message buffer commit mode */
                vuint16_t MBT:1;        /* message buffer type */
                vuint16_t MTD:1;        /* message buffer direction */
                vuint16_t CMT:1;        /* commit for transmission */
                vuint16_t EDT:1;        /* enable / disable trigger */
                vuint16_t LCKT:1;       /* lock request trigger */
                vuint16_t MBIE:1;       /* message buffer interrupt enable */
                vuint16_t:3;
                vuint16_t DUP:1;        /* data updated  */
                vuint16_t DVAL:1;       /* data valid */
                vuint16_t EDS:1;        /* lock status */
                vuint16_t LCKS:1;       /* enable / disable status */
                vuint16_t MBIF:1;       /* message buffer interrupt flag */
            } B;
        } MBCCSR;
        union {
            vuint16_t R;
            struct {
                vuint16_t MTM:1;        /* message buffer transmission mode */
                vuint16_t CHNLA:1;      /* channel assignement *//* Legacy naming: Refer to CHA in the reference manual */
                vuint16_t CHNLB:1;      /* channel assignement *//* Legacy naming: Refer to CHB in the reference manual */
                vuint16_t CCFE:1;       /* cycle counter filter enable */
                vuint16_t CCFMSK:6;     /* cycle counter filter mask */
                vuint16_t CCFVAL:6;     /* cycle counter filter value */
            } B;
        } MBCCFR;
        union {
            vuint16_t R;
            struct {
                vuint16_t:5;
                vuint16_t FID:11;       /* frame ID */
            } B;
        } MBFIDR;
        union {
            vuint16_t R;
            struct {
                vuint16_t:8;
                vuint16_t MBIDX:8;      /* message buffer index */
            } B;
        } MBIDXR;
    } MSG_BUFF_CCS_t;
    typedef union uSYSBADHR {
        vuint16_t R;
    } SYSBADHR_t;
    typedef union uSYSBADLR {
        vuint16_t R;
    } SYSBADLR_t;
    typedef union uCASERCR {
        vuint16_t R;
    } CASERCR_t;
    typedef union uCBSERCR {
        vuint16_t R;
    } CBSERCR_t;
    typedef union uCYCTR {
        vuint16_t R;
    } CYCTR_t;
    typedef union uMTCTR {
        vuint16_t R;
    } MTCTR_t;
    typedef union uSLTCTAR {
        vuint16_t R;
    } SLTCTAR_t;
    typedef union uSLTCTBR {
        vuint16_t R;
    } SLTCTBR_t;
    typedef union uRTCORVR {
        vuint16_t R;
    } RTCORVR_t;
    typedef union uOFCORVR {
        vuint16_t R;
    } OFCORVR_t;
    typedef union uSFTOR {
        vuint16_t R;
    } SFTOR_t;
    typedef union uSFIDAFVR {
        vuint16_t R;
        struct {
            vuint16_t:6;
            vuint16_t FVAL:10;
        } B;
    } SFIDAFVR_t;
    typedef union uSFIDAFMR {
        vuint16_t R;
        struct {
            vuint16_t:6;
            vuint16_t FMSK:10;
        } B;
    } SFIDAFMR_t;
    typedef union uNMVR {
        vuint16_t R;
    } NMVR_t;
    typedef union uNMVLR {
        vuint16_t R;
        struct {
            vuint16_t:12;
            vuint16_t NMVL:4;
        } B;
    } NMVLR_t;
    typedef union uT1MTOR {
        vuint16_t R;
        struct {
            vuint16_t:2;
            vuint16_t T1_MTOFFSET:14;
        } B;
    } T1MTOR_t;
    typedef union uTI2CR0 {
        vuint16_t R;
    } TI2CR0_t;
    typedef union uTI2CR1 {
        vuint16_t R;
    } TI2CR1_t;
    typedef union uSSCR {
        vuint16_t R;
    } SSCR_t;
    typedef union uRFSR {
        vuint16_t R;
        struct {
            vuint16_t WM:8;
            vuint16_t:7;
            vuint16_t SEL:1;
        } B;
    } RFSR_t;
    typedef union uRFSIR {
        vuint16_t R;
        struct {
            vuint16_t:6;
            vuint16_t SIDX:10;
        } B;
    } RFSIR_t;
    typedef union uRFARIR {
        vuint16_t R;
        struct {
            vuint16_t:6;
            vuint16_t RDIDX:10;
        } B;
    } RFARIR_t;
    typedef union uRFBRIR {
        vuint16_t R;
        struct {
            vuint16_t:6;
            vuint16_t RDIDX:10;
        } B;
    } RFBRIR_t;
    typedef union uRFMIDAFVR {
        vuint16_t R;
    } RFMIDAFVR_t;
    typedef union uRFMIAFMR {
        vuint16_t R;
    } RFMIAFMR_t;
    typedef union uRFFIDRFVR {
        vuint16_t R;
        struct {
            vuint16_t:5;
            vuint16_t FIDRFVAL:11;
        } B;
    } RFFIDRFVR_t;
    typedef union uRFFIDRFMR {
        vuint16_t R;
        struct {
            vuint16_t:5;
            vuint16_t FIDRFMSK:11;
        } B;
    } RFFIDRFMR_t;
    typedef union uLDTXSLAR {
        vuint16_t R;
        struct {
            vuint16_t:5;
            vuint16_t LASTDYNTXSLOTA:11;
        } B;
    } LDTXSLAR_t;
    typedef union uLDTXSLBR {
        vuint16_t R;
        struct {
            vuint16_t:5;
            vuint16_t LASTDYNTXSLOTB:11;
        } B;
    } LDTXSLBR_t;

    typedef struct FR_tag {
        volatile MVR_t MVR;     /*module version register *//*0  */
        volatile MCR_t MCR;     /*module configuration register *//*2  */
        volatile SYSBADHR_t SYSBADHR;   /*system memory base address high register *//*4*//* Legacy naming: Refer to SYMBADHR in the reference manual */
        volatile SYSBADLR_t SYSBADLR;   /*system memory base address low register *//*6*//* Legacy naming: Refer to SYMBADLR in the reference manual */
        volatile STBSCR_t STBSCR;       /*strobe signal control register *//*8*/
        vuint16_t reserved3b;           /* A */
        volatile MBDSR_t MBDSR; /*message buffer data size register *//*C*/
        volatile MBSSUTR_t MBSSUTR;     /*message buffer segment size and utilization register *//*E  */
        vuint16_t reserved3a[2];        /*10 and 12 */
        volatile POCR_t POCR;   /*Protocol operation control register *//*14 */
        volatile GIFER_t GIFER; /*global interrupt flag and enable register *//*16 */
        volatile PIFR0_t PIFR0; /*protocol interrupt flag register 0 *//*18 */
        volatile PIFR1_t PIFR1; /*protocol interrupt flag register 1 *//*1A */
        volatile PIER0_t PIER0; /*protocol interrupt enable register 0 *//*1C */
        volatile PIER1_t PIER1; /*protocol interrupt enable register 1 *//*1E */
        volatile CHIERFR_t CHIERFR;     /*CHI error flag register *//*20 */
        volatile MBIVEC_t MBIVEC;       /*message buffer interrupt vector register *//*22 */
        volatile CASERCR_t CASERCR;     /*channel A status error counter register *//*24 */
        volatile CBSERCR_t CBSERCR;     /*channel B status error counter register *//*26 */
        volatile PSR0_t PSR0;   /*protocol status register 0 *//*28 */
        volatile PSR1_t PSR1;   /*protocol status register 1 *//*2A */
        volatile PSR2_t PSR2;   /*protocol status register 2 *//*2C */
        volatile PSR3_t PSR3;   /*protocol status register 3 *//*2E */
        volatile MTCTR_t MTCTR; /*macrotick counter register *//*30 */
        volatile CYCTR_t CYCTR; /*cycle counter register *//*32 */
        volatile SLTCTAR_t SLTCTAR;     /*slot counter channel A register *//*34 */
        volatile SLTCTBR_t SLTCTBR;     /*slot counter channel B register *//*36 */
        volatile RTCORVR_t RTCORVR;     /*rate correction value register *//*38 */
        volatile OFCORVR_t OFCORVR;     /*offset correction value register *//*3A */
        volatile CIFRR_t CIFRR; /*combined interrupt flag register *//*3C */
        volatile SYMATOR_t SYMATOR;     /*System memory access timeout register */
        volatile SFCNTR_t SFCNTR;       /*sync frame counter register *//*40 */
        volatile SFTOR_t SFTOR; /*sync frame table offset register *//*42 */
        volatile SFTCCSR_t SFTCCSR;     /*sync frame table configuration, control, status register *//*44 */
        volatile SFIDRFR_t SFIDRFR;     /*sync frame ID rejection filter register *//*46 */
        volatile SFIDAFVR_t SFIDAFVR;   /*sync frame ID acceptance filter value regiater *//*48 */
        volatile SFIDAFMR_t SFIDAFMR;   /*sync frame ID acceptance filter mask register *//*4A */
        volatile NMVR_t NMVR[6];        /*network management vector registers (12 bytes) *//*4C */
        volatile NMVLR_t NMVLR; /*network management vector length register *//*58 */
        volatile TICCR_t TICCR; /*timer configuration and control register *//*5A */
        volatile TI1CYSR_t TI1CYSR;     /*timer 1 cycle set register *//*5C */
        volatile T1MTOR_t T1MTOR;       /*timer 1 macrotick offset register *//*5E *//* Legacy naming: Refer to TI1MTOR in the reference manual */
        volatile TI2CR0_t TI2CR0;       /*timer 2 configuration register 0 *//*60 */
        volatile TI2CR1_t TI2CR1;       /*timer 2 configuration register 1 *//*62 */
        volatile SSSR_t SSSR;   /*slot status selection register *//*64 */
        volatile SSCCR_t SSCCR; /*slot status counter condition register *//*66 */
        volatile SSR_t SSR[8];  /*slot status registers 0-7 *//*68 */
        volatile SSCR_t SSCR[4];        /*slot status counter registers 0-3 *//*78 */
        volatile MTSCFR_t MTSACFR;      /*mts a config register *//*80 */
        volatile MTSCFR_t MTSBCFR;      /*mts b config register *//*82 */
        volatile RSBIR_t RSBIR; /*receive shadow buffer index register *//*84 */
        volatile RFSR_t RFSR;   /*receive fifo selection register *//*86 *//* Legacy naming: Refer to RFWMSR in the reference manual */
        volatile RFSIR_t RFSIR; /*receive fifo start index register *//*88 */
        volatile RFDSR_t RFDSR; /*receive fifo depth and size register *//*8A */
        volatile RFARIR_t RFARIR;       /*receive fifo a read index register *//*8C */
        volatile RFBRIR_t RFBRIR;       /*receive fifo b read index register *//*8E */
        volatile RFMIDAFVR_t RFMIDAFVR; /*receive fifo message ID acceptance filter value register *//*90 */
        volatile RFMIAFMR_t RFMIAFMR;   /*receive fifo message ID acceptance filter mask register *//*92 */
        volatile RFFIDRFVR_t RFFIDRFVR; /*receive fifo frame ID rejection filter value register *//*94 */
        volatile RFFIDRFMR_t RFFIDRFMR; /*receive fifo frame ID rejection filter mask register *//*96 */
        volatile RFRFCFR_t RFRFCFR;     /*receive fifo range filter configuration register *//*98 */
        volatile RFRFCTR_t RFRFCTR;     /*receive fifo range filter control register *//*9A */
        volatile LDTXSLAR_t LDTXSLAR;   /*last dynamic transmit slot channel A register *//*9C */
        volatile LDTXSLBR_t LDTXSLBR;   /*last dynamic transmit slot channel B register *//*9E */
        volatile PCR0_t PCR0;   /*protocol configuration register 0 *//*A0 */
        volatile PCR1_t PCR1;   /*protocol configuration register 1 *//*A2 */
        volatile PCR2_t PCR2;   /*protocol configuration register 2 *//*A4 */
        volatile PCR3_t PCR3;   /*protocol configuration register 3 *//*A6 */
        volatile PCR4_t PCR4;   /*protocol configuration register 4 *//*A8 */
        volatile PCR5_t PCR5;   /*protocol configuration register 5 *//*AA */
        volatile PCR6_t PCR6;   /*protocol configuration register 6 *//*AC */
        volatile PCR7_t PCR7;   /*protocol configuration register 7 *//*AE */
        volatile PCR8_t PCR8;   /*protocol configuration register 8 *//*B0 */
        volatile PCR9_t PCR9;   /*protocol configuration register 9 *//*B2 */
        volatile PCR10_t PCR10; /*protocol configuration register 10 *//*B4 */
        volatile PCR11_t PCR11; /*protocol configuration register 11 *//*B6 */
        volatile PCR12_t PCR12; /*protocol configuration register 12 *//*B8 */
        volatile PCR13_t PCR13; /*protocol configuration register 13 *//*BA */
        volatile PCR14_t PCR14; /*protocol configuration register 14 *//*BC */
        volatile PCR15_t PCR15; /*protocol configuration register 15 *//*BE */
        volatile PCR16_t PCR16; /*protocol configuration register 16 *//*C0 */
        volatile PCR17_t PCR17; /*protocol configuration register 17 *//*C2 */
        volatile PCR18_t PCR18; /*protocol configuration register 18 *//*C4 */
        volatile PCR19_t PCR19; /*protocol configuration register 19 *//*C6 */
        volatile PCR20_t PCR20; /*protocol configuration register 20 *//*C8 */
        volatile PCR21_t PCR21; /*protocol configuration register 21 *//*CA */
        volatile PCR22_t PCR22; /*protocol configuration register 22 *//*CC */
        volatile PCR23_t PCR23; /*protocol configuration register 23 *//*CE */
        volatile PCR24_t PCR24; /*protocol configuration register 24 *//*D0 */
        volatile PCR25_t PCR25; /*protocol configuration register 25 *//*D2 */
        volatile PCR26_t PCR26; /*protocol configuration register 26 *//*D4 */
        volatile PCR27_t PCR27; /*protocol configuration register 27 *//*D6 */
        volatile PCR28_t PCR28; /*protocol configuration register 28 *//*D8 */
        volatile PCR29_t PCR29; /*protocol configuration register 29 *//*DA */
        volatile PCR30_t PCR30; /*protocol configuration register 30 *//*DC */
        vuint16_t reserved2[5];
        volatile RFSYMBADHR_t RFSYMBADHR; /* Receive FIFO System Memory Base Address High Register *//*E8 */
        volatile RFSYMBADLR_t RFSYMBADLR; /* Receive FIFO System Memory Base Address Low Register *//*EA */
        volatile RFPTR_t RFPTR;           /* Receive FIFO Periodic Timer Register *//*EC */
        volatile RFPTR_t RFFLPCR;         /* Receive FIFO Fill Level and POP Count Register *//*EE */
        vuint16_t reserved3[8];
        volatile MSG_BUFF_CCS_t MBCCS[128];     /* message buffer configuration, control & status registers 0-31 *//*100 */
    } FR_tag_t;

    typedef union uF_HEADER     /* frame header */
    {
        struct {
            vuint16_t:1;
            vuint16_t PPI:1;    /* Payload Preamble Indicator */
            vuint16_t NUF:1;    /* Null Frame Indicator */
            vuint16_t SYF:1;    /* Sync Frame Indicator */
            vuint16_t SUF:1;    /* Startup Frame Indicator */
            vuint16_t FID:11;   /* Frame ID */
            vuint16_t:2;
            vuint16_t CYCCNT:6; /* Cycle Count */
            vuint16_t:1;
            vuint16_t PLDLEN:7; /* Payload Length */
            vuint16_t:5;
            vuint16_t HDCRC:11; /* Header CRC */
        } B;
        vuint16_t WORDS[3];
    } F_HEADER_t;
    typedef union uS_STSTUS     /* slot status */
    {
        struct {
            vuint16_t VFB:1;    /* Valid Frame on channel B */
            vuint16_t SYB:1;    /* Sync Frame Indicator channel B */
            vuint16_t NFB:1;    /* Null Frame Indicator channel B */
            vuint16_t SUB:1;    /* Startup Frame Indicator channel B */
            vuint16_t SEB:1;    /* Syntax Error on channel B */
            vuint16_t CEB:1;    /* Content Error on channel B */
            vuint16_t BVB:1;    /* Boundary Violation on channel B */
            vuint16_t CH:1;     /* Channel */
            vuint16_t VFA:1;    /* Valid Frame on channel A */
            vuint16_t SYA:1;    /* Sync Frame Indicator channel A */
            vuint16_t NFA:1;    /* Null Frame Indicator channel A */
            vuint16_t SUA:1;    /* Startup Frame Indicator channel A */
            vuint16_t SEA:1;    /* Syntax Error on channel A */
            vuint16_t CEA:1;    /* Content Error on channel A */
            vuint16_t BVA:1;    /* Boundary Violation on channel A */
              vuint16_t:1;
        } RX;
        struct {
            vuint16_t VFB:1;    /* Valid Frame on channel B */
            vuint16_t SYB:1;    /* Sync Frame Indicator channel B */
            vuint16_t NFB:1;    /* Null Frame Indicator channel B */
            vuint16_t SUB:1;    /* Startup Frame Indicator channel B */
            vuint16_t SEB:1;    /* Syntax Error on channel B */
            vuint16_t CEB:1;    /* Content Error on channel B */
            vuint16_t BVB:1;    /* Boundary Violation on channel B */
            vuint16_t TCB:1;    /* Tx Conflict on channel B */
            vuint16_t VFA:1;    /* Valid Frame on channel A */
            vuint16_t SYA:1;    /* Sync Frame Indicator channel A */
            vuint16_t NFA:1;    /* Null Frame Indicator channel A */
            vuint16_t SUA:1;    /* Startup Frame Indicator channel A */
            vuint16_t SEA:1;    /* Syntax Error on channel A */
            vuint16_t CEA:1;    /* Content Error on channel A */
            vuint16_t BVA:1;    /* Boundary Violation on channel A */
            vuint16_t TCA:1;    /* Tx Conflict on channel A */
        } TX;
        vuint16_t R;
    } S_STATUS_t;

    typedef struct uMB_HEADER   /* message buffer header */
    {
        F_HEADER_t FRAME_HEADER;
        vuint16_t DATA_OFFSET;
        S_STATUS_t SLOT_STATUS;
    } MB_HEADER_t;

/* Define memories */

#define SRAM_START    0x40000000
#define SRAM_SIZE        0x40000
#define SRAM_END      0x4003FFFF

#define FLASH_START   0x00000000
#define FLASH_SIZE      0x400000
#define FLASH_END     0x003FFFFF

/* Define instances of modules */
#define PBRIDGE_A (*( volatile struct PBRIDGE_A_tag *)  0xC3F00000)
#define FMPLL     (*( volatile struct FMPLL_tag *)      0xC3F80000)
#define EBI       (*( volatile struct EBI_tag *)        0xC3F84000)
#define FLASH_A   (*( volatile struct FLASH_tag *)      0xC3F88000)
#define FLASH_B   (*( volatile struct FLASH_tag *)      0xC3F8C000)
#define SIU       (*( volatile struct SIU_tag *)        0xC3F90000)

#define EMIOS     (*( volatile struct EMIOS_tag *)      0xC3FA0000)
#define PMC       (*( volatile struct PMC_tag *)        0xC3FBC000)

#define ETPU      (*( volatile struct ETPU_tag *)       0xC3FC0000)
#define ETPU_DATA_RAM      (*( uint32_t *)              0xC3FC8000)
#define ETPU_DATA_RAM_END                               0xC3FC8FFC 
#define ETPU_DATA_RAM_EXT  (*( uint32_t *)              0xC3FCC000)
#define CODE_RAM           (*( uint32_t *)              0xC3FD0000)
#define ETPU_CODE_RAM      (*( uint32_t *)              0xC3FD0000)

#define PIT       (*( volatile struct PIT_tag *)        0xC3FF0000)

#define PBRIDGE_B (*( volatile struct PBRIDGE_B_tag *)  0xFFF00000)
#define XBAR      (*( volatile struct XBAR_tag *)       0xFFF04000)
#define MPU       (*( volatile struct MPU_tag *)        0xFFF10000)
#define SWT       (*( volatile struct SWT_tag *)        0xFFF38000)
#define STM       (*( volatile struct STM_tag *)        0xFFF3C000)
#define ECSM      (*( volatile struct ECSM_tag *)       0xFFF40000)
#define EDMA_A    (*( volatile struct EDMA_tag *)       0xFFF44000)
#define INTC      (*( volatile struct INTC_tag *)       0xFFF48000)
#define EDMA_B    (*( volatile struct EDMA_tag *)       0xFFF54000)

#define EQADC_A   (*( volatile struct EQADC_tag *)      0xFFF80000)
#define EQADC_B   (*( volatile struct EQADC_tag *)      0xFFF84000)

#define DECFIL_A   (*( volatile struct DECFIL_tag *)      0xFFF88000)
#define DECFIL_B   (*( volatile struct DECFIL_tag *)      0xFFF88800)
#define DECFIL_C   (*( volatile struct DECFIL_tag *)      0xFFF89000)
#define DECFIL_D   (*( volatile struct DECFIL_tag *)      0xFFF89800)
#define DECFIL_E   (*( volatile struct DECFIL_tag *)      0xFFF8A000)
#define DECFIL_F   (*( volatile struct DECFIL_tag *)      0xFFF8A800)
#define DECFIL_G   (*( volatile struct DECFIL_tag *)      0xFFF8B000)
#define DECFIL_H   (*( volatile struct DECFIL_tag *)      0xFFF8B800)

#define DSPI_A    (*( volatile struct DSPI_tag *)       0xFFF90000)
#define DSPI_B    (*( volatile struct DSPI_tag *)       0xFFF94000)
#define DSPI_C    (*( volatile struct DSPI_tag *)       0xFFF98000)
#define DSPI_D    (*( volatile struct DSPI_tag *)       0xFFF9C000)

#define ESCI_A    (*( volatile struct ESCI_tag *)       0xFFFB0000)
#define ESCI_B    (*( volatile struct ESCI_tag *)       0xFFFB4000)
#define ESCI_C    (*( volatile struct ESCI_tag *)       0xFFFB8000)

#define CAN_A     (*( volatile struct FLEXCAN2_tag *)   0xFFFC0000)
#define CAN_B     (*( volatile struct FLEXCAN2_tag *)   0xFFFC4000)
#define CAN_C     (*( volatile struct FLEXCAN2_tag *)   0xFFFC8000)
#define CAN_D     (*( volatile struct FLEXCAN2_tag *)   0xFFFCC000)

#define FR        (*( volatile struct FR_tag *)         0xFFFE0000)
#define TSENS     (*( volatile struct TSENS_tag *)      0xFFFEC000)

#ifdef __MWERKS__
#pragma pop
#endif

#ifdef  __cplusplus
}
#endif
#endif                          /* ifdef _MPC5674_H */
/*********************************************************************
 *
 * Copyright:
 *  Freescale Semiconductor, INC. All Rights Reserved.
 *  You are hereby granted a copyright license to use, modify, and
 *  distribute the SOFTWARE so long as this entire notice is
 *  retained without alteration in any modified and/or redistributed
 *  versions, and that such modified versions are clearly identified
 *  as such. No licenses are granted by implication, estoppel or
 *  otherwise under any patents or trademarks of Freescale
 *  Semiconductor, Inc. This software is provided on an "AS IS"
 *  basis and without warranty.
 *
 *  To the maximum extent permitted by applicable law, Freescale
 *  Semiconductor DISCLAIMS ALL WARRANTIES WHETHER EXPRESS OR IMPLIED,
 *  INCLUDING IMPLIED WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A
 *  PARTICULAR PURPOSE AND ANY WARRANTY AGAINST INFRINGEMENT WITH
 *  REGARD TO THE SOFTWARE (INCLUDING ANY MODIFIED VERSIONS THEREOF)
 *  AND ANY ACCOMPANYING WRITTEN MATERIALS.
 *
 *  To the maximum extent permitted by applicable law, IN NO EVENT
 *  SHALL Freescale Semiconductor BE LIABLE FOR ANY DAMAGES WHATSOEVER
 *  (INCLUDING WITHOUT LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS,
 *  BUSINESS INTERRUPTION, LOSS OF BUSINESS INFORMATION, OR OTHER
 *  PECUNIARY LOSS) ARISING OF THE USE OR INABILITY TO USE THE SOFTWARE.
 *
 *  Freescale Semiconductor assumes no responsibility for the
 *  maintenance and support of this software
 *
 ********************************************************************/
