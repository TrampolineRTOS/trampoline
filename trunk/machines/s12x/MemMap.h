/**
 * @file MemMap.h
 *
 * @section desc File description
 *
 * Memory Mapping of AUTOSAR Modules
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

/******************************************************************************/
/* SYMBOL DEFINITIONS                                                         */
/******************************************************************************/

#define MEMMAP_ERROR


/*****************************************************************************/
/* COMSTACKDATA                                                              */
/*****************************************************************************/
#ifdef AUTOSAR_COMSTACKDATA_START_SEC_VAR_NOINIT_8BIT
  #undef AUTOSAR_COMSTACKDATA_START_SEC_VAR_NOINIT_8BIT
  #define START_SECTION_COMMON_BANKED_VAR
#endif
#ifdef AUTOSAR_COMSTACKDATA_STOP_SEC_VAR_NOINIT_8BIT
  #undef AUTOSAR_COMSTACKDATA_STOP_SEC_VAR_NOINIT_8BIT
  #define STOP_SECTION_COMMON_BANKED_VAR
#endif

#ifdef AUTOSAR_COMSTACKDATA_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef AUTOSAR_COMSTACKDATA_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SECTION_COMMON_BANKED_VAR
#endif
#ifdef AUTOSAR_COMSTACKDATA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef AUTOSAR_COMSTACKDATA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SECTION_COMMON_BANKED_VAR
#endif


/*****************************************************************************/
/* SchM                                                                      */
/*****************************************************************************/
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


/*****************************************************************************/
/* GPT                                                                       */
/*****************************************************************************/
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

#ifdef GPT_START_CONFIG_DATA_UNSPECIFIED
  #undef GPT_START_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR
#endif
#ifdef GPT_STOP_CONFIG_DATA_UNSPECIFIED
  #undef GPT_STOP_CONFIG_DATA_UNSPECIFIED
  #undef MEMMAP_ERROR
#endif


/*****************************************************************************/
/* ECUM                                                                      */
/*****************************************************************************/
#ifdef ECUM_START_SEC_CODE
  #undef ECUM_START_SEC_CODE
  #define START_SECTION_COMMON_CODE
#endif
#ifdef ECUM_STOP_SEC_CODE
  #undef ECUM_STOP_SEC_CODE
  #define STOP_SECTION_COMMON_CODE
#endif

#ifdef ECUM_START_SEC_VAR_NOINIT_16BIT
  #undef ECUM_START_SEC_VAR_NOINIT_16BIT
  #define START_SECTION_COMMON_BANKED_VAR
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_16BIT
  #undef ECUM_STOP_SEC_VAR_NOINIT_16BIT
  #define STOP_SECTION_COMMON_BANKED_VAR
#endif

#ifdef ECUM_START_SEC_VAR_NOINIT_8BIT
  #undef ECUM_START_SEC_VAR_NOINIT_8BIT
  #define START_SECTION_COMMON_BANKED_VAR
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_8BIT
  #undef ECUM_STOP_SEC_VAR_NOINIT_8BIT
  #define STOP_SECTION_COMMON_BANKED_VAR
#endif

#ifdef ECUM_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef ECUM_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SECTION_COMMON_BANKED_VAR
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef ECUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SECTION_COMMON_BANKED_VAR
#endif

#ifdef ECUM_START_SEC_VAR_UNSPECIFIED
  #undef ECUM_START_SEC_VAR_UNSPECIFIED
  #define START_SECTION_COMMON_VAR
#endif
#ifdef ECUM_STOP_SEC_VAR_UNSPECIFIED
  #undef ECUM_STOP_SEC_VAR_UNSPECIFIED
  #define STOP_SECTION_COMMON_VAR
#endif

#ifdef ECUM_START_SEC_VAR_8BIT
  #undef ECUM_START_SEC_VAR_8BIT
  #define START_SECTION_COMMON_VAR
#endif
#ifdef ECUM_STOP_SEC_VAR_8BIT
  #undef ECUM_STOP_SEC_VAR_8BIT
  #define STOP_SECTION_COMMON_VAR
#endif

#ifdef ECUM_START_CONFIG_DATA_UNSPECIFIED
  #undef ECUM_START_CONFIG_DATA_UNSPECIFIED
  #define START_SECTION_COMMON_BANKED_CONST
#endif
#ifdef ECUM_STOP_CONFIG_DATA_UNSPECIFIED
  #undef ECUM_STOP_CONFIG_DATA_UNSPECIFIED
  #define STOP_SECTION_COMMON_BANKED_CONST
#endif

#ifdef ECUM_START_SEC_CONST_UNSPECIFIED
  #undef ECUM_START_SEC_CONST_UNSPECIFIED
  #define START_SECTION_COMMON_CONST
#endif
#ifdef ECUM_STOP_SEC_CONST_UNSPECIFIED
  #undef ECUM_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SECTION_COMMON_CONST
#endif


/*****************************************************************************/
/* OS                                                                        */
/*****************************************************************************/
#ifdef OS_START_SEC_CODE
  #undef OS_START_SEC_CODE
  #define START_SECTION_COMMON_CODE
#endif
#ifdef OS_STOP_SEC_CODE
  #undef OS_STOP_SEC_CODE
  #define STOP_SECTION_COMMON_CODE
#endif

#ifdef OS_START_SEC_TASK_CODE
  #undef OS_START_SEC_TASK_CODE
  #define START_SECTION_COMMON_CODE
#endif
#ifdef OS_STOP_SEC_TASK_CODE
  #undef OS_STOP_SEC_TASK_CODE
  #define STOP_SECTION_COMMON_CODE
#endif

#ifdef OS_START_SEC_VAR_BOOLEAN
  #undef OS_START_SEC_VAR_BOOLEAN
  #define START_SECTION_COMMON_VAR
#endif
#ifdef OS_STOP_SEC_VAR_BOOLEAN
  #undef OS_STOP_SEC_VAR_BOOLEAN
  #define STOP_SECTION_COMMON_VAR
#endif

#ifdef OS_START_SEC_VAR_8BITS
  #undef OS_START_SEC_VAR_8BITS
  #define START_SECTION_COMMON_VAR
#endif
#ifdef OS_STOP_SEC_VAR_8BITS
  #undef OS_STOP_SEC_VAR_8BITS
  #define STOP_SECTION_COMMON_VAR
#endif

#ifdef OS_START_SEC_VAR_16BITS
  #undef OS_START_SEC_VAR_16BITS
  #define START_SECTION_COMMON_VAR
#endif
#ifdef OS_STOP_SEC_VAR_16BITS
  #undef OS_STOP_SEC_VAR_16BITS
  #define STOP_SECTION_COMMON_VAR
#endif

#ifdef OS_START_SEC_VAR_UNSPECIFIED
  #undef OS_START_SEC_VAR_UNSPECIFIED
  #define START_SECTION_COMMON_VAR
#endif
#ifdef OS_STOP_SEC_VAR_UNSPECIFIED
  #undef OS_STOP_SEC_VAR_UNSPECIFIED
  #define STOP_SECTION_COMMON_VAR
#endif

#ifdef OS_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef OS_START_SEC_VAR_NOINIT_UNSPECIFIED
  #define START_SECTION_COMMON_VAR
#endif
#ifdef OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #define STOP_SECTION_COMMON_VAR
#endif

#ifdef OS_START_SEC_CONFIGDATA_UNSPECIFIED
  #undef OS_START_SEC_CONFIGDATA_UNSPECIFIED
  #define START_SECTION_COMMON_CONST
#endif
#ifdef OS_STOP_SEC_CONFIGDATA_UNSPECIFIED
  #undef OS_STOP_SEC_CONFIGDATA_UNSPECIFIED
  #define STOP_SECTION_COMMON_CONST
#endif


/*****************************************************************************/
/* COMMON                                                                    */
/*****************************************************************************/
/* CODE **********************************************************************/
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

/* CONST *********************************************************************/
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

/* VAR ***********************************************************************/
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

/*****************************************************************************/
/* PUBLISHED INFORMATION                                                     */
/*****************************************************************************/
#define MEMMAP_VENDOR_ID        48
#define MEMMAP_AR_MAJOR_VERSION 3
#define MEMMAP_AR_MINOR_VERSION 0
#define MEMMAP_AR_PATCH_VERSION 0
#define MEMMAP_SW_MAJOR_VERSION 1
#define MEMMAP_SW_MINOR_VERSION 0
#define MEMMAP_SW_PATCH_VERSION 0

