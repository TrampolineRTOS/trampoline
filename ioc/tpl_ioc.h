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
#include "tpl_os_definitions.h"
#include "tpl_ioc_internal_types.h"
#include "tpl_app_define.h"
#include "tpl_ioc_kernel.h"

/*#include "Rte.h"*/


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
#define IOC_E_OK          0
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
#define IOC_E_NOT_OK      1
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
#define IOC_E_LIMIT       2
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
#define IOC_E_LOST_DATA   3
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
#define IOC_E_NO_DATA     4
#endif




#define OS_START_SEC_CODE
#include "tpl_memmap.h"

#if (IOC_QUEUED_COUNT > 0)
/**
 * Send an IOC queued message
 *
 * @param ioc_id identifier of the ioc
 * @param ioc_data pointer to the data struct to send
 *
 * @retval IOC_E_OK no error
 * @retval IOC_E_LIMIT queue is full
 *
 */
extern FUNC(Std_ReturnType, OS_CODE) IOC_Send(
  VAR(tpl_ioc_id, AUTOMATIC) ioc_id,
  P2CONST(tpl_ioc_message, AUTOMATIC, OS_VAR) ioc_data
);

/**
 * Receive an IOC queued message
 *
 * @param ioc_id identifier of the ioc
 * @param ioc_data pointer to the data struct to receive
 *
 * @retval IOC_E_OK no error
 * @retval IOC_E_NO_DATA no data to receive
 * @retval IOC_E_LOST_DATA previous send caused a queue overflow
 *
 */
extern FUNC(Std_ReturnType, OS_CODE) IOC_Receive(
  VAR(tpl_ioc_id, AUTOMATIC) ioc_id,
  P2CONST(tpl_ioc_message, AUTOMATIC, OS_VAR) ioc_data
);

/**
 * empty an IOC queue
 *
 * @param ioc_id identifier of the ioc
 *
 * @retval IOC_E_OK no error
 *
 */
extern FUNC(Std_ReturnType, OS_CODE) IOC_EmptyQueue(
  VAR(tpl_ioc_id, AUTOMATIC) ioc_id
);

#endif


#if (IOC_UNQUEUED_COUNT > 0)
/**
 * Send an IOC unqueued message
 *
 * @param ioc_id identifier of the ioc
 * @param ioc_data pointer to the data struct to send
 *
 * @retval IOC_E_OK no error
 *
 */
extern FUNC(Std_ReturnType, OS_CODE) IOC_Write(
  VAR(tpl_ioc_id, AUTOMATIC) ioc_id,
  P2CONST(tpl_ioc_message, AUTOMATIC, OS_VAR) ioc_data
);

/**
 * Receive an IOC unqueued message
 *
 * @param ioc_id identifier of the ioc
 * @param ioc_data pointer to the data struct to receive
 *
 * @retval IOC_E_OK no error
 *
 */
extern FUNC(StatusType, OS_CODE) IOC_Read(
  VAR(tpl_ioc_id, AUTOMATIC) ioc_id,
  P2CONST(tpl_ioc_message, AUTOMATIC, OS_VAR) ioc_data
);

#endif

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


/*  __TPL_IOC_H__ */
#endif

