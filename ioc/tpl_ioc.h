/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline AUTOSAR IOC API declaration
 *
 * $Date$ - $Rev$
 * $Author$
 * $URL$
 */
/* MISRA RULE 3.1 VIOLATION: special character is used for svn integration, the code can survive to this ! */

#ifndef __TPL_IOC_H__
#define __TPL_IOC_H__

/*#include "Std_Types.h"*/
/*#include "Rte.h"*/
#include "tpl_os_definitions.h"
#include "tpl_app_define.h"
#include "tpl_ioc_internal_types.h"

/**
 * @def IOC_E_OK
 *
 * IOC
 * This error code means: no error.
 * This code is defined by RTE
 */
#ifdef RTE_E_OK
#define IOC_E_OK          RTE_E_OK
#else
#define IOC_E_OK          E_OK
#endif
/**
 * @def IOC_E_NOT_OK
 *
 * IOC
 * This error code means: unknown error.
 * This code is defined by RTE
 */
#ifdef RTE_E_NOT_OK
#define IOC_E_NOT_OK      RTE_E_NOT_OK
#else
#define IOC_E_NOT_OK      E_NOT_OK
#endif
/**
 * @def IOC_E_LIMIT
 *
 * IOC
 * This error code means: limit of queue has been reached.
 * This code is defined by RTE
 */
#ifdef RTE_E_LIMIT
#define IOC_E_LIMIT       RTE_E_LIMIT
#else
#define IOC_E_LIMIT       E_OS_LIMIT
#endif
/**
 * @def IOC_E_LOST_DATA
 *
 * IOC
 * This error code means: when receiving a data, an IOC_E_LIMIT was returns during previous send.
 * This code is defined by RTE
 */
#ifdef RTE_E_LOST_DATA
#define IOC_E_LOST_DATA   RTE_E_LOST_DATA
#else
#define IOC_E_LOST_DATA   E_OS_LOST_DATA
#endif
/**
 * @def IOC_E_NO_DATA
 *
 * IOC
 * This error code means: no data to read, queue is empty.
 * This code is defined by RTE
 */
#ifdef RTE_E_NO_DATA
#define IOC_E_NO_DATA     RTE_E_NO_DATA
#else
#define IOC_E_NO_DATA     E_OS_NO_DATA
#endif

/*  __TPL_IOC_H__ */
#endif

