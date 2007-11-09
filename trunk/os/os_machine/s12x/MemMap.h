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
** 01.00  N. Cornet 05/02/07
** - Creation
==============================================================================*/



/******************************************************************************/
/* SYMBOL DEFINITIONS                                                         */
/******************************************************************************/

#define MEMMAP_ERROR



/******************************************************************************/
/* SchM                                                                       */
/******************************************************************************/
#ifdef SCHM_START_SEC_CODE
  #undef SCHM_START_SEC_CODE
  #define START_SECTION_COMMON_CODE
#endif
#ifdef SCHM_STOP_SEC_CODE
  #undef SCHM_STOP_SEC_CODE
  #define STOP_SECTION_COMMON_CODE
#endif

#ifdef SCHM_START_SEC_TASK
  #undef SCHM_START_SEC_TASK
  #define START_SECTION_COMMON_CODE
#endif
#ifdef SCHM_STOP_SEC_TASK
  #undef SCHM_STOP_SEC_TASK
  #define STOP_SECTION_COMMON_CODE
#endif

/******************************************************************************/
/* GPT                                                                        */
/******************************************************************************/
#ifdef GPT_START_SEC_ISR_CODE
  #undef GPT_START_SEC_ISR_CODE
  #define START_SECTION_COMMON_ISR_CODE
#endif
#ifdef GPT_STOP_SEC_ISR_CODE
  #undef GPT_STOP_SEC_ISR_CODE
  #define STOP_SECTION_COMMON_ISR_CODE
#endif

#ifdef GPT_START_SEC_CODE
  #undef GPT_START_SEC_CODE
  #define START_SECTION_COMMON_CODE
#endif
#ifdef GPT_STOP_SEC_CODE
  #undef GPT_STOP_SEC_CODE
  #define STOP_SECTION_COMMON_CODE
#endif

#ifdef GPT_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef GPT_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef MEMMAP_ERROR
#endif
#ifdef GPT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef GPT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_NOINIT_16BIT
  #undef GPT_START_SEC_VAR_NOINIT_16BIT
  #undef MEMMAP_ERROR
#endif
#ifdef GPT_STOP_SEC_VAR_NOINIT_16BIT
  #undef GPT_STOP_SEC_VAR_NOINIT_16BIT
  #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_REGISTRE
  #undef GPT_START_SEC_REGISTRE
  #undef MEMMAP_ERROR
#endif
#ifdef GPT_STOP_SEC_REGISTRE
  #undef GPT_STOP_SEC_REGISTRE
  #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_POWER_ON_INIT_16BIT
  #undef GPT_START_SEC_VAR_POWER_ON_INIT_16BIT
  #undef MEMMAP_ERROR
#endif
#ifdef GPT_STOP_SEC_VAR_POWER_ON_INIT_16BIT
  #undef GPT_STOP_SEC_VAR_POWER_ON_INIT_16BIT
  #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_FAST_16BIT
  #undef GPT_START_SEC_VAR_FAST_16BIT
  #undef MEMMAP_ERROR
#endif
#ifdef GPT_STOP_SEC_VAR_FAST_16BIT
  #undef GPT_STOP_SEC_VAR_FAST_16BIT
  #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_UNSPECIFIED
  #undef GPT_START_SEC_VAR_UNSPECIFIED
  #undef MEMMAP_ERROR
#endif
#ifdef GPT_STOP_SEC_VAR_UNSPECIFIED
  #undef GPT_STOP_SEC_VAR_UNSPECIFIED
  #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_8BIT
  #undef GPT_START_SEC_VAR_8BIT
  #undef MEMMAP_ERROR
#endif
#ifdef GPT_STOP_SEC_VAR_8BIT
  #undef GPT_STOP_SEC_VAR_8BIT
  #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_VAR_16BIT
  #undef GPT_START_SEC_VAR_16BIT
  #undef MEMMAP_ERROR
#endif
#ifdef GPT_STOP_SEC_VAR_16BIT
  #undef GPT_STOP_SEC_VAR_16BIT
  #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CONST_16BIT
  #undef GPT_START_SEC_CONST_16BIT
  #undef MEMMAP_ERROR
#endif
#ifdef GPT_STOP_SEC_CONST_16BIT
  #undef GPT_STOP_SEC_CONST_16BIT
  #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_CONFIG_DATA_16BIT
  #undef GPT_START_CONFIG_DATA_16BIT
  #undef MEMMAP_ERROR
#endif
#ifdef GPT_STOP_CONFIG_DATA_16BIT
  #undef GPT_STOP_CONFIG_DATA_16BIT
  #undef MEMMAP_ERROR
#endif

#ifdef GPT_START_SEC_CODE_FAST_1
  #undef GPT_START_SEC_CODE_FAST_1
  #undef MEMMAP_ERROR
#endif
#ifdef GPT_STOP_SEC_CODE_FAST_1
  #undef GPT_STOP_SEC_CODE_FAST_1
  #undef MEMMAP_ERROR
#endif

/******************************************************************************/
/* MCU                                                                        */
/******************************************************************************/
#ifdef MCU_START_SEC_CODE
  #undef MCU_START_SEC_CODE
  #define START_SECTION_COMMON_CODE
#endif
#ifdef MCU_STOP_SEC_CODE
  #undef MCU_STOP_SEC_CODE
  #define STOP_SECTION_COMMON_CODE
#endif

/******************************************************************************/
/* ECUM                                                                       */
/******************************************************************************/
#ifdef ECUM_START_SEC_ISR_CODE
  #undef ECUM_START_SEC_ISR_CODE
  #define START_SECTION_COMMON_ISR_CODE
#endif
#ifdef ECUM_STOP_SEC_ISR_CODE
  #undef ECUM_STOP_SEC_ISR_CODE
  #define STOP_SECTION_COMMON_ISR_CODE
#endif

#ifdef ECUM_START_SEC_CODE
  #define START_SECTION_COMMON_CODE
  #undef ECUM_START_SEC_CODE
#endif
#ifdef ECUM_STOP_SEC_CODE
  #define STOP_SECTION_COMMON_CODE
  #undef ECUM_STOP_SEC_CODE
#endif

#ifdef ECUM_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef ECUM_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef MEMMAP_ERROR
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef ECUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef MEMMAP_ERROR
#endif

#ifdef ECUM_START_SEC_VAR_NOINIT_16BIT
  #undef ECUM_START_SEC_VAR_NOINIT_16BIT
  #undef MEMMAP_ERROR
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_16BIT
  #undef ECUM_STOP_SEC_VAR_NOINIT_16BIT
  #undef MEMMAP_ERROR
#endif

#ifdef ECUM_START_SEC_VAR_POWER_ON_INIT_16BIT
  #undef ECUM_START_SEC_VAR_POWER_ON_INIT_16BIT
  #undef MEMMAP_ERROR
#endif
#ifdef ECUM_STOP_SEC_VAR_POWER_ON_INIT_16BIT
  #undef ECUM_STOP_SEC_VAR_POWER_ON_INIT_16BIT
  #undef MEMMAP_ERROR
#endif

#ifdef ECUM_START_SEC_VAR_FAST_16BIT
  #undef ECUM_START_SEC_VAR_FAST_16BIT
  #undef MEMMAP_ERROR
#endif
#ifdef ECUM_STOP_SEC_VAR_FAST_16BIT
  #undef ECUM_STOP_SEC_VAR_FAST_16BIT
  #undef MEMMAP_ERROR
#endif

#ifdef ECUM_START_SEC_VAR_UNSPECIFIED
  #undef ECUM_START_SEC_VAR_UNSPECIFIED
  #undef MEMMAP_ERROR
#endif
#ifdef ECUM_STOP_SEC_VAR_UNSPECIFIED
  #undef ECUM_STOP_SEC_VAR_UNSPECIFIED
  #undef MEMMAP_ERROR
#endif

#ifdef ECUM_START_SEC_VAR_8BIT
  #undef ECUM_START_SEC_VAR_8BIT
  #undef MEMMAP_ERROR
#endif
#ifdef ECUM_STOP_SEC_VAR_8BIT
  #undef ECUM_STOP_SEC_VAR_8BIT
  #undef MEMMAP_ERROR
#endif

#ifdef ECUM_START_SEC_VAR_16BIT
  #undef ECUM_START_SEC_VAR_16BIT
  #undef MEMMAP_ERROR
#endif
#ifdef ECUM_STOP_SEC_VAR_16BIT
  #undef ECUM_STOP_SEC_VAR_16BIT
  #undef MEMMAP_ERROR
#endif


#ifdef ECUM_START_SEC_CONST_16BIT
  #undef ECUM_START_SEC_CONST_16BIT
  #undef MEMMAP_ERROR
#endif
#ifdef ECUM_STOP_SEC_CONST_16BIT
  #undef ECUM_STOP_SEC_CONST_16BIT
  #undef MEMMAP_ERROR
#endif

#ifdef ECUM_START_CONFIG_DATA_16BIT
  #undef ECUM_START_CONFIG_DATA_16BIT
  #undef MEMMAP_ERROR
#endif
#ifdef ECUM_STOP_CONFIG_DATA_16BIT
  #undef ECUM_STOP_CONFIG_DATA_16BIT
  #undef MEMMAP_ERROR
#endif

#ifdef ECUM_START_SEC_CODE_FAST_1
  #undef ECUM_START_SEC_CODE_FAST_1
  #undef MEMMAP_ERROR
#endif
#ifdef ECUM_STOP_SEC_CODE_FAST_1
  #undef ECUM_STOP_SEC_CODE_FAST_1
  #undef MEMMAP_ERROR
#endif


/******************************************************************************/
/* OS                                                                        */
/******************************************************************************/
#ifdef OS_START_SEC_CODE
  #define START_SECTION_COMMON_CODE
  #undef OS_START_SEC_CODE
#endif
#ifdef OS_STOP_SEC_CODE
  #define STOP_SECTION_COMMON_CODE
  #undef OS_STOP_SEC_CODE
#endif

#ifdef OS_START_SEC_TASK_CODE
  #define START_SECTION_COMMON_CODE
  #undef OS_START_SEC_TASK_CODE
#endif
#ifdef OS_STOP_SEC_TASK_CODE
  #define STOP_SECTION_COMMON_CODE
  #undef OS_STOP_SEC_TASK_CODE
#endif

#ifdef OS_START_SEC_VAR_8BITS
  #define START_SECTION_COMMON_VAR
  #undef OS_START_SEC_VAR_8BITS
#endif
#ifdef OS_STOP_SEC_VAR_8BITS
  #define STOP_SECTION_COMMON_VAR
  #undef OS_STOP_SEC_VAR_8BITS
#endif

#ifdef OS_START_SEC_VAR_UNSPECIFIED
  #define START_SECTION_COMMON_VAR
  #undef OS_START_SEC_VAR_UNSPECIFIED
#endif
#ifdef OS_STOP_SEC_VAR_UNSPECIFIED
  #define STOP_SECTION_COMMON_VAR
  #undef OS_STOP_SEC_VAR_UNSPECIFIED
#endif

/******************************************************************************/
/* COMMON                                                                     */
/******************************************************************************/
#ifdef STOP_SECTION_COMMON_ISR_CODE
  #ifdef START_SECTION_COMMON_ISR_CODE
    #undef START_SECTION_COMMON_ISR_CODE
    #undef SECTION_STARTED
    #pragma CODE_SEG __NEAR_SEG NON_BANKED
    #undef STOP_SECTION_COMMON_ISR_CODE
    #undef MEMMAP_ERROR
  #else
    #error "STOP_SECTION_COMMON_ISR_CODE: This section has not been previously started !"
  #endif
#endif

#ifdef START_SECTION_COMMON_ISR_CODE
  #ifndef SECTION_STARTED
    #define SECTION_STARTED
    #pragma CODE_SEG __NEAR_SEG NON_BANKED
    #undef MEMMAP_ERROR
  #else
    #error "START_SECTION_COMMON_ISR_CODE: A section has already been started !"
  #endif
#endif

#ifdef STOP_SECTION_COMMON_CODE
  #ifdef START_SECTION_COMMON_CODE
    #undef START_SECTION_COMMON_CODE
    #undef SECTION_STARTED
    #pragma CODE_SEG __NEAR_SEG NON_BANKED 
    #undef STOP_SECTION_COMMON_CODE
    #undef MEMMAP_ERROR
  #else
    #error "STOP_SECTION_COMMON_CODE: This section has not been previously started !"
  #endif
#endif

#ifdef START_SECTION_COMMON_CODE
  #ifndef SECTION_STARTED
    #define SECTION_STARTED
    #pragma CODE_SEG __NEAR_SEG NON_BANKED
    #undef MEMMAP_ERROR
  #else
    #error "START_SECTION_COMMON_CODE: A section has already been started !"
  #endif
#endif

#ifdef STOP_SECTION_COMMON_BANKED_CODE
  #ifdef START_SECTION_COMMON_BANKED_CODE
    #undef START_SECTION_COMMON_BANKED_CODE
    #undef SECTION_STARTED
    #pragma CODE_SEG __NEAR_SEG NON_BANKED
    #undef STOP_SECTION_COMMON_BANKED_CODE
    #undef MEMMAP_ERROR
  #else
    #error "STOP_SECTION_COMMON_BANKED_CODE: This section has not been previously started !"
  #endif
#endif

#ifdef START_SECTION_COMMON_BANKED_CODE
  #ifndef SECTION_STARTED
    #define SECTION_STARTED
    #pragma CODE_SEG DEFAULT
    #undef MEMMAP_ERROR
  #else
    #error "START_SECTION_COMMON_BANKED_CODE: A section has already been started !"
  #endif
#endif

#ifdef STOP_SECTION_COMMON_CONST
  #ifdef START_SECTION_COMMON_CONST
    #undef START_SECTION_COMMON_CONST
    #undef SECTION_STARTED
    #pragma CONST_SEG __NEAR_SEG DEFAULT
    #undef STOP_SECTION_COMMON_CONST
    #undef MEMMAP_ERROR
  #else
    #error "STOP_SECTION_COMMON_CONST: This section has not been previously started !"
  #endif
#endif

#ifdef START_SECTION_COMMON_CONST
  #ifndef SECTION_STARTED
    #define SECTION_STARTED
    #pragma CONST_SEG __NEAR_SEG DEFAULT
    #undef MEMMAP_ERROR
  #else
    #error "START_SECTION_COMMON_CONST: A section has already been started !"
  #endif
#endif

#ifdef STOP_SECTION_COMMON_BANKED_CONST
  #ifdef START_SECTION_COMMON_BANKED_CONST
    #undef START_SECTION_COMMON_BANKED_CONST
    #undef SECTION_STARTED
    #pragma CONST_SEG __NEAR_SEG DEFAULT
    #undef STOP_SECTION_COMMON_BANKED_CONST
    #undef MEMMAP_ERROR
  #else
    #error "STOP_SECTION_COMMON_BANKED_CONST: This section has not been previously started !"
  #endif
#endif

#ifdef START_SECTION_COMMON_BANKED_CONST
  #ifndef SECTION_STARTED
    #define SECTION_STARTED
    #pragma CONST_SEG __GPAGE_SEG BANKED_CONST
    #undef MEMMAP_ERROR
  #else
    #error "START_SECTION_COMMON_BANKED_CONST: A section has already been started !"
  #endif
#endif

#ifdef STOP_SECTION_COMMON_VAR
  #ifdef START_SECTION_COMMON_VAR
    #undef START_SECTION_COMMON_VAR
    #undef SECTION_STARTED
    #undef STOP_SECTION_COMMON_VAR
    #undef MEMMAP_ERROR
    #pragma DATA_SEG __NEAR_SEG DEFAULT 
  #else
    #error "STOP_SECTION_COMMON_VAR: This section has not been previously started !"
  #endif
#endif

#ifdef START_SECTION_COMMON_VAR
  #ifndef SECTION_STARTED
    #define SECTION_STARTED
    #undef MEMMAP_ERROR
    #pragma DATA_SEG __NEAR_SEG DEFAULT
  #else
    #error "START_SECTION_COMMON_VAR: A section has already been started !"
  #endif
#endif

#ifdef STOP_SECTION_COMMON_BANKED_VAR
  #ifdef START_SECTION_COMMON_BANKED_VAR
    #undef START_SECTION_COMMON_BANKED_VAR
    #undef SECTION_STARTED
    #undef STOP_SECTION_COMMON_BANKED_VAR
    #undef MEMMAP_ERROR
    #pragma DATA_SEG __NEAR_SEG DEFAULT 
  #else
    #error "STOP_SECTION_COMMON_BANKED_VAR: This section has not been previously started !"
  #endif
#endif

#ifdef START_SECTION_COMMON_BANKED_VAR
  #ifndef SECTION_STARTED
    #define SECTION_STARTED
    #undef MEMMAP_ERROR
    #pragma DATA_SEG __GPAGE_SEG PAGED_RAM
  #else
    #error "START_SECTION_COMMON_BANKED_VAR: A section has already been started !"
  #endif
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



