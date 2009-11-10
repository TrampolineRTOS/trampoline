/**
 * @file MemMap.h
 *
 * @section desc File description
 *
 * Memory Mapping of Application $APPNAME$
 * Automatically generated by goil on $TIMESTAMP$
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

/********************************************************************************/
/* OS                                                                        	*/
/********************************************************************************/
/* .osCode */
#ifdef OS_START_SEC_CODE
	#undef OS_START_SEC_CODE
	#ifdef CURRENT_LINKER_SECTION_NAME
		#error "Starting a .osCode section while section CURRENT_LINKER_SECTION_NAME is already started"
	#else
    #define CURRENT_LINKER_SECTION_NAME ".osCode"
  #endif
#endif

#ifdef OS_STOP_SEC_CODE
	#undef OS_STOP_SEC_CODE
	#if CURRENT_LINKER_SECTION_NAME != ".osCode"
    #error "Stopping section .osCode while it is not started"
  #else
    #undef CURRENT_LINKER_SECTION_NAME
  #endif
#endif

/* .osVar */
#ifdef OS_START_SEC_VAR_BOOLEAN
	#undef OS_START_SEC_VAR_BOOLEAN
	#ifdef CURRENT_LINKER_SECTION_NAME
		#error "Starting a .osVar section while section CURRENT_LINKER_SECTION_NAME is already started"
  #else
  	#define CURRENT_LINKER_SECTION_NAME ".osVar"
	#endif
#endif

#ifdef OS_STOP_SEC_VAR_BOOLEAN
	#undef OS_STOP_SEC_VAR_BOOLEAN
	#if CURRENT_LINKER_SECTION_NAME != ".osVar"
    #error "Stopping section .osVar while it is not started"
  #else
    #undef CURRENT_LINKER_SECTION_NAME
  #endif
#endif

#ifdef OS_START_SEC_VAR_8BIT
	#undef OS_START_SEC_VAR_8BIT
	#ifdef CURRENT_LINKER_SECTION_NAME
		#error "Starting a .osVar section while section CURRENT_LINKER_SECTION_NAME is already started"
  #else
  	#define CURRENT_LINKER_SECTION_NAME ".osVar"
	#endif
#endif

#ifdef OS_STOP_SEC_VAR_8BIT
	#undef OS_STOP_SEC_VAR_8BIT
	#if CURRENT_LINKER_SECTION_NAME != ".osVar"
    #error "Stopping section .osVar while it is not started"
  #else
    #undef CURRENT_LINKER_SECTION_NAME
  #endif
#endif

#ifdef OS_START_SEC_VAR_16BIT
	#undef OS_START_SEC_VAR_16BIT
	#ifdef CURRENT_LINKER_SECTION_NAME
		#error "Starting a .osVar section while section CURRENT_LINKER_SECTION_NAME is already started"
  #else
  	#define CURRENT_LINKER_SECTION_NAME ".osVar"
	#endif
#endif

#ifdef OS_STOP_SEC_VAR_16BIT
	#undef OS_STOP_SEC_VAR_16BIT
	#if CURRENT_LINKER_SECTION_NAME != ".osVar"
    #error "Stopping section .osVar while it is not started"
  #else
    #undef CURRENT_LINKER_SECTION_NAME
  #endif
#endif

#ifdef OS_START_SEC_VAR_32BIT
	#undef OS_START_SEC_VAR_32BIT
	#ifdef CURRENT_LINKER_SECTION_NAME
		#error "Starting a .osVar section while section CURRENT_LINKER_SECTION_NAME is already started"
  #else
  	#define CURRENT_LINKER_SECTION_NAME ".osVar"
	#endif
#endif

#ifdef OS_STOP_SEC_VAR_32BIT
	#undef OS_STOP_SEC_VAR_32BIT
	#if CURRENT_LINKER_SECTION_NAME != ".osVar"
    #error "Stopping section .osVar while it is not started"
  #else
    #undef CURRENT_LINKER_SECTION_NAME
  #endif
#endif

#ifdef OS_START_SEC_VAR_UNSPECIFIED
	#undef OS_START_SEC_VAR_UNSPECIFIED
	#ifdef CURRENT_LINKER_SECTION_NAME
		#error "Starting a .osVar section while section CURRENT_LINKER_SECTION_NAME is already started"
  #else
  	#define CURRENT_LINKER_SECTION_NAME ".osVar"
	#endif
#endif

#ifdef OS_STOP_SEC_VAR_UNSPECIFIED
	#undef OS_STOP_SEC_VAR_UNSPECIFIED
	#if CURRENT_LINKER_SECTION_NAME != ".osVar"
    #error "Stopping section .osVar while it is not started"
  #else
    #undef CURRENT_LINKER_SECTION_NAME
  #endif
#endif

#ifdef OS_START_SEC_VAR_NOINIT_UNSPECIFIED
	#undef OS_START_SEC_VAR_NOINIT_UNSPECIFIED
	#ifdef CURRENT_LINKER_SECTION_NAME
		#undef CURRENT_LINKER_SECTION_NAME
	#endif
	#ifdef GCC_SECTION_ATTRIBUTE
		#undef GCC_SECTION_ATTRIBUTE
	#endif
	#define CURRENT_LINKER_SECTION_NAME ".osVar"
	#define GCC_SECTION_ATTRIBUTE __attribute__ ((aligned(32), section (CURRENT_LINKER_SECTION_NAME)))
	#define START_SECTION_COMMON_VAR
#endif
#ifdef OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#undef OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#undef CURRENT_LINKER_SECTION_NAME
	#define GCC_SECTION_ATTRIBUTE
	#define STOP_SECTION_COMMON_VAR
#endif

#ifdef OS_START_SEC_CONST_UNSPECIFIED
	#undef OS_START_SEC_CONST_UNSPECIFIED
	#ifdef CURRENT_LINKER_SECTION_NAME
		#undef CURRENT_LINKER_SECTION_NAME
	#endif
	#ifdef GCC_SECTION_ATTRIBUTE
		#undef GCC_SECTION_ATTRIBUTE
	#endif
	#define CURRENT_LINKER_SECTION_NAME ".osConst"
	#define GCC_SECTION_ATTRIBUTE __attribute__ ((aligned(32), section (CURRENT_LINKER_SECTION_NAME)))
	#define START_SECTION_COMMON_CONST
#endif
#ifdef OS_STOP_SEC_CONST_UNSPECIFIED
	#undef OS_STOP_SEC_CONST_UNSPECIFIED
	#undef CURRENT_LINKER_SECTION_NAME
	#undef GCC_SECTION_ATTRIBUTE
	#define GCC_SECTION_ATTRIBUTE
	#define STOP_SECTION_COMMON_CONST
#endif

#ifdef OS_START_SEC_CONST_32BIT
	#undef OS_START_SEC_CONST_32BIT
	#ifdef CURRENT_LINKER_SECTION_NAME
		#undef CURRENT_LINKER_SECTION_NAME
	#endif
	#ifdef GCC_SECTION_ATTRIBUTE
		#undef GCC_SECTION_ATTRIBUTE
	#endif
	#define CURRENT_LINKER_SECTION_NAME ".osConst"
	#define GCC_SECTION_ATTRIBUTE __attribute__ ((aligned(32), section (CURRENT_LINKER_SECTION_NAME)))
	#define START_SECTION_COMMON_CONST
#endif
#ifdef OS_STOP_SEC_CONST_32BIT
	#undef OS_STOP_SEC_CONST_32BIT
	#undef CURRENT_LINKER_SECTION_NAME
	#undef GCC_SECTION_ATTRIBUTE
	#define GCC_SECTION_ATTRIBUTE
	#define STOP_SECTION_COMMON_CONST
#endif

#ifdef OS_START_SEC_CONST_16BIT
	#undef OS_START_SEC_CONST_16BIT
	#ifdef CURRENT_LINKER_SECTION_NAME
		#undef CURRENT_LINKER_SECTION_NAME
	#endif
	#ifdef GCC_SECTION_ATTRIBUTE
		#undef GCC_SECTION_ATTRIBUTE
	#endif
	#define CURRENT_LINKER_SECTION_NAME ".osConst"
	#define GCC_SECTION_ATTRIBUTE __attribute__ ((aligned(32), section (CURRENT_LINKER_SECTION_NAME)))
	#define START_SECTION_COMMON_CONST
#endif
#ifdef OS_STOP_SEC_CONST_16BIT
	#undef OS_STOP_SEC_CONST_16BIT
	#undef CURRENT_LINKER_SECTION_NAME
	#undef GCC_SECTION_ATTRIBUTE
	#define GCC_SECTION_ATTRIBUTE
	#define STOP_SECTION_COMMON_CONST
#endif

#ifdef OS_START_SEC_CONFIGDATA_8BIT
	#undef OS_START_SEC_CONFIGDATA_8BIT
	#ifdef CURRENT_LINKER_SECTION_NAME
		#undef CURRENT_LINKER_SECTION_NAME
	#endif
	#ifdef GCC_SECTION_ATTRIBUTE
		#undef GCC_SECTION_ATTRIBUTE
	#endif
	#define CURRENT_LINKER_SECTION_NAME ".osConst"
	#define GCC_SECTION_ATTRIBUTE __attribute__ ((aligned(32), section (CURRENT_LINKER_SECTION_NAME)))
	#define START_SECTION_COMMON_CONST
#endif
#ifdef OS_STOP_SEC_CONFIGDATA_8BIT
	#undef OS_STOP_SEC_CONFIGDATA_8BIT
	#undef CURRENT_LINKER_SECTION_NAME
	#define GCC_SECTION_ATTRIBUTE
	#define STOP_SECTION_COMMON_CONST
#endif

#ifdef OS_START_SEC_CONFIGDATA_UNSPECIFIED
	#undef OS_START_SEC_CONFIGDATA_UNSPECIFIED
	#ifdef CURRENT_LINKER_SECTION_NAME
		#undef CURRENT_LINKER_SECTION_NAME
	#endif
	#ifdef GCC_SECTION_ATTRIBUTE
		#undef GCC_SECTION_ATTRIBUTE
	#endif
	#define CURRENT_LINKER_SECTION_NAME ".osConst"
	#define GCC_SECTION_ATTRIBUTE __attribute__ ((aligned(32), section (CURRENT_LINKER_SECTION_NAME)))
	#define START_SECTION_COMMON_CONST
#endif
#ifdef OS_STOP_SEC_CONFIGDATA_UNSPECIFIED
	#undef OS_STOP_SEC_CONFIGDATA_UNSPECIFIED
	#undef CURRENT_LINKER_SECTION_NAME
	#undef GCC_SECTION_ATTRIBUTE
	#define GCC_SECTION_ATTRIBUTE
	#define STOP_SECTION_COMMON_CONST
#endif

/*********************************************************************************/
/* COMMON                                                                   	 */
/*********************************************************************************/
/* CODE **************************************************************************/

#ifdef STOP_SECTION_COMMON_CODE
	#ifdef START_SECTION_COMMON_CODE
		#undef START_SECTION_COMMON_CODE
		#undef SECTION_STARTED
		#undef STOP_SECTION_COMMON_CODE
		#undef MEMMAP_ERROR
	#else
		#error "STOP_SECTION_COMMON_CODE: This section has not been previously started !"
	#endif
#endif

#ifdef START_SECTION_COMMON_CODE
	#ifndef SECTION_STARTED
		#define SECTION_STARTED
		#undef MEMMAP_ERROR
	#else
		#error "START_SECTION_COMMON_CODE: A section has already been started !"
	#endif
#endif


/* CONST *************************************************************************/
#ifdef STOP_SECTION_COMMON_CONST
	#ifdef START_SECTION_COMMON_CONST
		#undef START_SECTION_COMMON_CONST
		#undef SECTION_STARTED
		#undef STOP_SECTION_COMMON_CONST
		#undef MEMMAP_ERROR
	#else
		#error "STOP_SECTION_COMMON_CONST: This section has not been previously started !"
	#endif
#endif

#ifdef START_SECTION_COMMON_CONST
	#ifndef SECTION_STARTED
		#define SECTION_STARTED
		#undef MEMMAP_ERROR
	#else
		#error "START_SECTION_COMMON_CONST: A section has already been started !"
	#endif
#endif

/* VAR ***************************************************************************/
#ifdef STOP_SECTION_COMMON_VAR
	#ifdef START_SECTION_COMMON_VAR
		#undef START_SECTION_COMMON_VAR
		#undef SECTION_STARTED
		#undef STOP_SECTION_COMMON_VAR
		#undef MEMMAP_ERROR
	#else
		#error "STOP_SECTION_COMMON_VAR: This section has not been previously started !"
	#endif
#endif

#ifdef START_SECTION_COMMON_VAR
	#ifndef SECTION_STARTED
		#define SECTION_STARTED
		#undef MEMMAP_ERROR
	#else
		#error "START_SECTION_COMMON_VAR: A section has already been started !"
	#endif
#endif

$APP_MEMMAP$

/* TODO UNCOMMENT When MP is set very well 
#ifdef MEMMAP_ERROR
	#error "MemMap.h, wrong pragma command"
#endif*/

/*********************************************************************************/
/* PUBLISHED INFORMATION                                                    	 */
/*********************************************************************************/
#define MEMMAP_VENDOR_ID        48
#define MEMMAP_AR_MAJOR_VERSION 3
#define MEMMAP_AR_MINOR_VERSION 0
#define MEMMAP_AR_PATCH_VERSION 0
#define MEMMAP_SW_MAJOR_VERSION 1
#define MEMMAP_SW_MINOR_VERSION 0
#define MEMMAP_SW_PATCH_VERSION 0

