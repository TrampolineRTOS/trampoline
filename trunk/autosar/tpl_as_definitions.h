/*
 *  tpl_as_definitions.h
 *  trampoline
 *
 *  Created by Jean-Luc BÈchennec on 20/11/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef TPL_AS_DEFINITIONS_H
#define TPL_AS_DEFINITIONS_H

#include "tpl_os_definitions.h"

/* Additional AUTOSAR error codes */

/**
 * @def E_OS_SERVICEID
 *
 * Service can not be called
 */
#define E_OS_SERVICEID            16

/**
 * @def E_OS_ILLEGAL_ADDRESS
 *
 * An invalid address is given as a parameter to a service
 */
#define E_OS_ILLEGAL_ADDRESS      17

/**
 * @def E_OS_STACKFAULT
 *
 * A stack fault detected via stack monitoring by the OS
 */
#define E_OS_STACKFAULT           20

/**
 * @def E_OS_PROTECTION_MEMORY
 *
 * A memory access violation occurred
 */
#define E_OS_PROTECTION_MEMORY    21

/**
 * @def E_OS_PROTECTION_TIME
 *
 * A Task exceeds its execution time budget,
 * A Category 2 OsIsr exceeds its execution time budget
 */
#define E_OS_PROTECTION_TIME      22

/**
 * @def E_OS_PROTECTION_ARRIVAL
 *
 * A Task/Category 2 arrives before its timeframe has expired 
 */
#define E_OS_PROTECTION_ARRIVAL   23

/**
 * @def E_OS_PROTECTION_LOCKED
 *
 * A Task/Category 2 OsIsr blocks for too long
 */
#define E_OS_PROTECTION_LOCKED    24

/**
 * @def E_OS_PROTECTION_EXCEPTION
 *
 * A trap occurred
 */
#define E_OS_PROTECTION_EXCEPTION 25


/* Schedule tables states */

#define SCHEDULETABLE_ASYNC						32
#define SCHEDULETABLE_BOOTSTRAP					16
#define SCHEDULETABLE_AUTOSTART_ABSOLUTE        (TIME_OBJ_AUTOSTART | 0x04 | SCHEDULETABLE_BOOTSTRAP)
#define SCHEDULETABLE_AUTOSTART_RELATIVE        (TIME_OBJ_AUTOSTART | 0x08 | SCHEDULETABLE_BOOTSTRAP)
#define SCHEDULETABLE_AUTOSTART_SYNCHRON        (TIME_OBJ_AUTOSTART | 0x0C | SCHEDULETABLE_BOOTSTRAP)
#define SCHEDULETABLE_STOPPED                   TIME_OBJ_SLEEP
#define SCHEDULETABLE_RUNNING                   TIME_OBJ_ACTIVE
#define SCHEDULETABLE_NEXT                      (TIME_OBJ_ACTIVE | 0x04)
#define SCHEDULETABLE_WAITING                   (TIME_OBJ_ACTIVE | 0x08)
#define SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS   (TIME_OBJ_ACTIVE | 0x0C)

/**
 * @def OBJECT_TASK
 * 
 * Identifier of a task object
 */
#define OBJECT_TASK           0

/**
 * @def OBJECT_ISR
 * 
 * Identifier of an ISR object
 */
#define OBJECT_ISR            0

/**
 * @def OBJECT_ALARM
 * 
 * Identifier of an alarm object
 */
#define OBJECT_ALARM          1

/**
 * @def OBJECT_RESOURCE
 * 
 * Identifier of a resource object
 */
#define OBJECT_RESOURCE       2

/**
 * @def OBJECT_SCHEDULETABLE
 * 
 * Identifier of a schedule table object
 */
#define OBJECT_SCHEDULETABLE  3

/**
 * @def OBJECT_COUNTER
 * 
 * Identifier of a counter object
 */
#define OBJECT_COUNTER        4

/**
 * @def OBJECT_KIND_COUNT
 *
 * number of object kind
 */
#define OBJECT_TYPE_COUNT     5

/**
 *  @def  ACCESS
 *
 *  Return value used by CheckObjectAccess. @see #CheckObjectAccess
 */
#define ACCESS      1

/**
 *  @def  NO_ACCESS
 *
 *  Return value used by CheckObjectAccess. @see #CheckObjectAccess
 */
#define NO_ACCESS   0

/**
 *  @def  RESTART
 *
 *  Parameter for TerminateApplication.
 *  @see #TerminateApplication
 *  @see #RestartType
 */
#define RESTART     0

/**
 *  @def  NO_RESTART
 *
 *  Parameter for TerminateApplication.
 *  @see #TerminateApplication
 *  @see #RestartType
 */
#define NO_RESTART  1

/**
 *  @def  INVALID_RESTART
 *
 *  Invalid Parameter for TerminateApplication.
 *  @see #TerminateApplication
 *  @see #RestartType
 */
#define INVALID_RESTART  2

#endif /* TPL_AS_DEFINITIONS_H */
