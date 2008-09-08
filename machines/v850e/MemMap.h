/*==============================================================================
** Trampoline OS
**
** Trampoline is copyright (c) IRCCyN 2005+
** Copyright ESEO for function and data structures documentation
** Trampoline is protected by the French intellectual property law.
**
** This software is distributed under the Lesser GNU Public Licence
**-----------------------------------------------------------------------------
** Supported MCUs       : NEC V850E
** Supported Compilers  : GHS Multi
**-----------------------------------------------------------------------------
** File name         : Memmap.h
**
** Module name       : All AUTOSAR modules
**
** Summary: Memory Mapping of AUTOSAR Modules
**
**= History ====================================================================
** 01.00  J.Monsimier 19/12/07
** - Creation
==============================================================================*/



/******************************************************************************/
/* OS                                                                         */
/******************************************************************************/
#ifdef OS_START_SEC_CODE
  #define DEFAULT_START_SEC_CODE
  #undef OS_START_SEC_CODE
#endif
#ifdef OS_STOP_SEC_CODE
  #define DEFAULT_STOP_SEC_CODE
  #undef OS_STOP_SEC_CODE
#endif

#ifdef OS_START_SEC_VAR_8BITS
  #define DEFAULT_START_SEC_VAR_8BIT
  #undef OS_START_SEC_VAR_8BITS
#endif
#ifdef OS_STOP_SEC_VAR_8BITS
  #define DEFAULT_STOP_SEC_VAR_8BIT
  #undef OS_STOP_SEC_VAR_8BITS
#endif

#ifdef OS_START_SEC_VAR_UNSPECIFIED
  #define DEFAULT_START_SEC_VAR_UNSPECIFIED
  #undef OS_START_SEC_VAR_UNSPECIFIED
#endif
#ifdef OS_STOP_SEC_VAR_UNSPECIFIED
  #define DEFAULT_START_SEC_VAR_UNSPECIFIED
  #undef OS_STOP_SEC_VAR_UNSPECIFIED
#endif

/******************************************************************************/
/* GPT                                                                        */
/******************************************************************************/
#ifdef GPT_START_SEC_VAR_8BIT
   #undef      GPT_START_SEC_VAR_8BIT
   #define DEFAULT_START_SEC_VAR_8BIT
#endif
#ifdef GPT_STOP_SEC_VAR_8BIT
   #undef      GPT_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT
#endif

#ifdef GPT_START_SEC_VAR_FAST_8BIT
   #undef      GPT_START_SEC_VAR_FAST_8BIT
   #define DEFAULT_START_SEC_VAR_FAST_8BIT
#endif
#ifdef GPT_STOP_SEC_VAR_FAST_8BIT
   #undef      GPT_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT
#endif

#ifdef GPT_START_SEC_VAR_16BIT
   #undef      GPT_START_SEC_VAR_16BIT
   #define DEFAULT_START_SEC_VAR_16BIT
#endif
#ifdef GPT_STOP_SEC_VAR_16BIT
   #undef      GPT_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT
#endif

#ifdef GPT_START_SEC_VAR_32BIT
   #undef      GPT_START_SEC_VAR_32BIT
   #define DEFAULT_START_SEC_VAR_32BIT
#endif
#ifdef GPT_STOP_SEC_VAR_32BIT
   #undef      GPT_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT
#endif

#ifdef GPT_START_SEC_VAR_UNSPECIFIED
   #undef      GPT_START_SEC_VAR_UNSPECIFIED
   #define DEFAULT_START_SEC_VAR_UNSPECIFIED
#endif
#ifdef GPT_STOP_SEC_VAR_UNSPECIFIED
   #undef      GPT_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
#endif

#ifdef GPT_START_SEC_CONFIG_VAR_UNSPECIFIED
   #undef      GPT_START_SEC_CONFIG_VAR_UNSPECIFIED
   #define DEFAULT_START_SEC_CONFIG_VAR_UNSPECIFIED
#endif
#ifdef GPT_STOP_SEC_CONFIG_VAR_UNSPECIFIED
   #undef      GPT_STOP_SEC_CONFIG_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONFIG_VAR_UNSPECIFIED
#endif

#ifdef GPT_START_SEC_CONST_8BIT
   #undef      GPT_START_SEC_CONST_8BIT
   #define DEFAULT_START_SEC_CONST_8BIT
#endif
#ifdef GPT_STOP_SEC_CONST_8BIT
   #undef      GPT_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT
#endif

#ifdef GPT_START_SEC_CONST_16BIT
   #undef      GPT_START_SEC_CONST_16BIT
   #define DEFAULT_START_SEC_CONST_16BIT
#endif
#ifdef GPT_STOP_SEC_CONST_16BIT
   #undef      GPT_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT
#endif

#ifdef GPT_START_SEC_CONST_UNSPECIFIED
   #undef      GPT_START_SEC_CONST_UNSPECIFIED
   #define DEFAULT_START_SEC_CONST_UNSPECIFIED
#endif
#ifdef GPT_STOP_SEC_CONST_UNSPECIFIED
   #undef      GPT_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
#endif

#ifdef GPT_START_SEC_CONFIG_CONST_UNSPECIFIED
   #undef      GPT_START_SEC_CONFIG_CONST_UNSPECIFIED
   #pragma ghs section rosdata=".GPT_CFG_CONST_ROM_UNSPEC"
#endif
#ifdef GPT_STOP_SEC_CONFIG_CONST_UNSPECIFIED
   #undef      GPT_STOP_SEC_CONFIG_CONST_UNSPECIFIED
   #pragma ghs section rosdata=default
#endif

#ifdef GPT_START_SEC_PUBLIC_CODE
   #undef      GPT_START_SEC_PUBLIC_CODE
   #pragma ghs section text=".GPT_PUBLIC_CODE_ROM"
#endif
#ifdef GPT_STOP_SEC_PUBLIC_CODE
   #undef      GPT_STOP_SEC_PUBLIC_CODE
   #define DEFAULT_STOP_SEC_CODE
#endif

#ifdef GPT_START_SEC_PRIVATE_CODE
   #undef      GPT_START_SEC_PRIVATE_CODE
   #pragma ghs section text=".GPT_PRIVATE_CODE_ROM"
#endif
#ifdef GPT_STOP_SEC_PRIVATE_CODE
   #undef      GPT_STOP_SEC_PRIVATE_CODE
   #define DEFAULT_STOP_SEC_CODE
#endif



/******************************************************************************/
/* COMMON                                                                     */
/******************************************************************************/

/* ---------------------------------------------------------------------------*/
/* RAM variables initialized from ROM on reset                                */
/* ---------------------------------------------------------------------------*/
#ifdef DEFAULT_START_SEC_VAR_8BIT
   #undef      DEFAULT_START_SEC_VAR_8BIT
   #pragma ghs section sbss=".RAM_8BIT"
#endif
#ifdef DEFAULT_STOP_SEC_VAR_8BIT
   #undef      DEFAULT_STOP_SEC_VAR_8BIT
   #pragma ghs section sbss=default
#endif

#ifdef DEFAULT_START_SEC_VAR_16BIT
   #undef      DEFAULT_START_SEC_VAR_16BIT
   #pragma ghs section sbss=".RAM_16BIT"
#endif
#ifdef DEFAULT_STOP_SEC_VAR_16BIT
   #undef      DEFAULT_STOP_SEC_VAR_16BIT
   #pragma ghs section sbss=default
#endif

#ifdef DEFAULT_START_SEC_VAR_32BIT
   #undef      DEFAULT_START_SEC_VAR_32BIT
   #pragma ghs section sbss=".RAM_32BIT"
#endif
#ifdef DEFAULT_STOP_SEC_VAR_32BIT
   #undef      DEFAULT_STOP_SEC_VAR_32BIT
   #pragma ghs section sbss=default
#endif

#ifdef DEFAULT_START_SEC_VAR_UNSPECIFIED
   #undef      DEFAULT_START_SEC_VAR_UNSPECIFIED
   #pragma ghs section sbss=".RAM_UNSPECIFIED"
#endif
#ifdef DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #undef      DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #pragma ghs section sbss=default
#endif

#ifdef DEFAULT_START_SEC_CONFIG_VAR_UNSPECIFIED
   #undef      DEFAULT_START_SEC_CONFIG_VAR_UNSPECIFIED
   #pragma ghs section sbss=".RAM_CONFIG_UNSPECIFIED"
#endif
#ifdef DEFAULT_STOP_SEC_CONFIG_VAR_UNSPECIFIED
   #undef      DEFAULT_STOP_SEC_CONFIG_VAR_UNSPECIFIED
   #pragma ghs section sbss=default
#endif

/* ---------------------------------------------------------------------------*/
/* RAM variables not initialized                                              */
/* ---------------------------------------------------------------------------*/
#ifdef DEFAULT_START_SEC_VAR_NO_INIT_8BIT
   #undef      DEFAULT_START_SEC_VAR_NO_INIT_8BIT
   #pragma ghs section sdata=".NOINIT_RAM_8BIT"
#endif
#ifdef DEFAULT_STOP_SEC_VAR_NO_INIT_8BIT
   #undef      DEFAULT_STOP_SEC_VAR_NO_INIT_8BIT
   #pragma ghs section sdata=default
#endif

#ifdef DEFAULT_START_SEC_VAR_NO_INIT_16BIT
   #undef      DEFAULT_START_SEC_VAR_NO_INIT_16BIT
   #pragma ghs section sdata=".NOINIT_RAM_16BIT"
#endif
#ifdef DEFAULT_STOP_SEC_VAR_NO_INIT_16BIT
   #undef      DEFAULT_STOP_SEC_VAR_NO_INIT_16BIT
   #pragma ghs section sdata=default
#endif

#ifdef DEFAULT_START_SEC_VAR_NO_INIT_32BIT
   #undef      DEFAULT_START_SEC_VAR_NO_INIT_32BIT
   #pragma ghs section sdata=".NOINIT_RAM_32BIT"
#endif
#ifdef DEFAULT_STOP_SEC_VAR_NO_INIT_32BIT
   #undef      DEFAULT_STOP_SEC_VAR_NO_INIT_32BIT
   #pragma ghs section sdata=default
#endif

#ifdef DEFAULT_START_SEC_VAR_NO_INIT_UNSPECIFIED
   #undef      DEFAULT_START_SEC_VAR_NO_INIT_UNSPECIFIED
   #pragma ghs section sdata=".NOINIT_RAM_UNSPECIFIED"
#endif
#ifdef DEFAULT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
   #undef      DEFAULT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
   #pragma ghs section sdata=default
#endif

/* ---------------------------------------------------------------------------*/
/* RAM variables frequently used or accessed bitwise                          */
/* ---------------------------------------------------------------------------*/
#ifdef DEFAULT_START_SEC_VAR_FAST_8BIT
   #undef      DEFAULT_START_SEC_VAR_FAST_8BIT
   #pragma ghs section sbss=".FAST_RAM_8BIT"
#endif
#ifdef DEFAULT_STOP_SEC_VAR_FAST_8BIT
   #undef      DEFAULT_STOP_SEC_VAR_FAST_8BIT
   #pragma ghs section sbss=default
#endif

#ifdef DEFAULT_START_SEC_VAR_FAST_16BIT
   #undef      DEFAULT_START_SEC_VAR_FAST_16BIT
   #pragma ghs section sbss=".FAST_RAM_16BIT"
#endif
#ifdef DEFAULT_STOP_SEC_VAR_FAST_16BIT
   #undef      DEFAULT_STOP_SEC_VAR_FAST_16BIT
   #pragma ghs section sbss=default
#endif

#ifdef DEFAULT_START_SEC_VAR_FAST_32BIT
   #undef      DEFAULT_START_SEC_VAR_FAST_32BIT
   #pragma ghs section sbss=".FAST_RAM_32BIT"
#endif
#ifdef DEFAULT_STOP_SEC_VAR_FAST_32BIT
   #undef      DEFAULT_STOP_SEC_VAR_FAST_32BIT
   #pragma ghs section sbss=default
#endif

#ifdef DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
   #undef      DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
   #pragma ghs section sbss=".FAST_RAM_UNSPECIFIED"
#endif
#ifdef DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #undef      DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #pragma ghs section sbss=default
#endif

/* ---------------------------------------------------------------------------*/
/* ROM constants                                                              */
/* ---------------------------------------------------------------------------*/
#ifdef DEFAULT_START_SEC_CONST_8BIT
   #undef      DEFAULT_START_SEC_CONST_8BIT
   #pragma ghs section rosdata=".CONST_ROM_8BIT"
#endif
#ifdef DEFAULT_STOP_SEC_CONST_8BIT
   #undef      DEFAULT_STOP_SEC_CONST_8BIT
   #pragma ghs section rosdata=default
#endif

#ifdef DEFAULT_START_SEC_CONST_16BIT
   #undef      DEFAULT_START_SEC_CONST_16BIT
   #pragma ghs section rosdata=".CONST_ROM_16BIT"
#endif
#ifdef DEFAULT_STOP_SEC_CONST_16BIT
   #undef      DEFAULT_STOP_SEC_CONST_16BIT
   #pragma ghs section rosdata=default
#endif

#ifdef DEFAULT_START_SEC_CONST_32BIT
   #undef      DEFAULT_START_SEC_CONST_32BIT
   #pragma ghs section rosdata=".CONST_ROM_32BIT"
#endif
#ifdef DEFAULT_STOP_SEC_CONST_32BIT
   #undef      DEFAULT_STOP_SEC_CONST_32BIT
   #pragma ghs section rosdata=default
#endif

#ifdef DEFAULT_START_SEC_CONST_UNSPECIFIED
   #undef      DEFAULT_START_SEC_CONST_UNSPECIFIED
   #pragma ghs section rosdata=".CONST_ROM_UNSPECIFIED"
#endif
#ifdef DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #undef      DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #pragma ghs section rosdata=default
#endif

/* ---------------------------------------------------------------------------*/
/* ROM FAR constants                                                          */
/* ---------------------------------------------------------------------------*/
#ifdef DEFAULT_START_SEC_CONST_8BIT_FAR
   #undef      DEFAULT_START_SEC_CONST_8BIT_FAR
   #pragma ghs section rosdata=".CONST_FAR_ROM_8BIT"
#endif
#ifdef DEFAULT_STOP_SEC_CONST_8BIT_FAR
   #undef      DEFAULT_STOP_SEC_CONST_8BIT_FAR
   #pragma ghs section rosdata=default
#endif

#ifdef DEFAULT_START_SEC_CONST_16BIT_FAR
   #undef      DEFAULT_START_SEC_CONST_16BIT_FAR
   #pragma ghs section rosdata=".CONST_FAR_ROM_16BIT"
#endif
#ifdef DEFAULT_STOP_SEC_CONST_16BIT_FAR
   #undef      DEFAULT_STOP_SEC_CONST_16BIT_FAR
   #pragma ghs section rosdata=default
#endif

#ifdef DEFAULT_START_SEC_CONST_32BIT_FAR
   #undef      DEFAULT_START_SEC_CONST_32BIT_FAR
   #pragma ghs section rosdata=".CONST_FAR_ROM_32BIT"
#endif
#ifdef DEFAULT_STOP_SEC_CONST_32BIT_FAR
   #undef      DEFAULT_STOP_SEC_CONST_32BIT_FAR
   #pragma ghs section rosdata=default
#endif

#ifdef DEFAULT_START_SEC_CONST_UNSPECIFIED_FAR
   #undef      DEFAULT_START_SEC_CONST_UNSPECIFIED_FAR
   #pragma ghs section rosdata=".CONST_FAR_ROM_UNSPECIFIED"
#endif
#ifdef DEFAULT_STOP_SEC_CONST_UNSPECIFIED_FAR
   #undef      DEFAULT_STOP_SEC_CONST_UNSPECIFIED_FAR
   #pragma ghs section rosdata=default
#endif

/* ---------------------------------------------------------------------------*/
/* ROM code                                                                   */
/* ---------------------------------------------------------------------------*/
#ifdef DEFAULT_START_SEC_CODE
   #undef      DEFAULT_START_SEC_CODE
   #pragma ghs section text=".DEFAULT_CODE_ROM"
#endif
#ifdef DEFAULT_STOP_SEC_CODE
   #undef      DEFAULT_STOP_SEC_CODE
   #pragma ghs section text=default
#endif



#ifdef MEMMAP_ERROR
  #error "MemMap.h, wrong pragma command"
#endif


