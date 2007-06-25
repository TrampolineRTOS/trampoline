/*==============================================================================
**                             AYRTON TECHNOLOGY
**                      Proprietary - Copyright (C) 2007
**------------------------------------------------------------------------------
** Customer          : Internal
** Project           : O4A (06-01-BEE-055)
**------------------------------------------------------------------------------
** Supported MCUs    : MCU independent
**------------------------------------------------------------------------------
** File name         : MemMap.h
**
** Module name       : All AUTOSAR Modules
**
** Summary: Memory Mapping of AUTOSAR Modules
**
**= History ====================================================================
** 01.00  N. Cornet	05/02/07 
** - Creation
==============================================================================*/



/******************************************************************************/
/* SYMBOL DEFINITIONS                                                         */
/******************************************************************************/

#define MEMMAP_ERROR

/******************************************************************************/
/* OS                                                                        */
/******************************************************************************/
#ifdef OS_START_SEC_CODE
  #include "non_bank.sgm"
  #undef OS_START_SEC_CODE
  #undef MEMMAP_ERROR
#endif
#ifdef OS_STOP_SEC_CODE
  #include "default.sgm"
  #undef OS_STOP_SEC_CODE
  #undef MEMMAP_ERROR
#endif

#ifdef OS_START_SEC_TASK_CODE
  #include "non_bank.sgm"
  #undef OS_START_SEC_TASK_CODE
  #undef MEMMAP_ERROR
#endif
#ifdef OS_STOP_SEC_TASK_CODE
  #include "default.sgm"
  #undef OS_STOP_SEC_TASK_CODE
  #undef MEMMAP_ERROR
#endif

#ifdef OS_START_SEC_VAR_UNSPECIFIED
  #include "non_bank.sgm"
  #undef OS_START_SEC_VAR_UNSPECIFIED
  #undef MEMMAP_ERROR
#endif
#ifdef OS_STOP_SEC_VAR_UNSPECIFIED
  #include "default.sgm"
  #undef OS_STOP_SEC_VAR_UNSPECIFIED
  #undef MEMMAP_ERROR
#endif



/******************************************************************************/
/* COMMON                                                                     */
/******************************************************************************/
#ifdef START_SECTION_COMMON_ISR_CODE
  #include "non_bank.sgm"
  #undef START_SECTION_COMMON_ISR_CODE
  #undef MEMMAP_ERROR
#endif

#ifdef STOP_SECTION_COMMON_ISR_CODE
  #include "default.sgm"
  #undef STOP_SECTION_COMMON_ISR_CODE
  #undef MEMMAP_ERROR
#endif


#ifdef MEMMAP_ERROR
  #error "MemMap.h, wrong pragma command"
#endif

/******************************************************************************/
/* PUBLISHED INFORMATION                                                      */
/******************************************************************************/
#define MEM_VENDOR_ID        0     
#define MEM_AR_MAJOR_VERSION 2
#define MEM_AR_MINOR_VERSION 1
#define MEM_AR_PATCH_VERSION 0
#define MEM_SW_MAJOR_VERSION 1
#define MEM_SW_MINOR_VERSION 0
#define MEM_SW_PATCH_VERSION 0



