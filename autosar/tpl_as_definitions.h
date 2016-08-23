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

/* Schedule tables states */

#define SCHEDULETABLE_AUTOSTART_ABSOLUTE        (TIME_OBJ_AUTOSTART | 0x04)
#define SCHEDULETABLE_AUTOSTART_RELATIVE        (TIME_OBJ_AUTOSTART | 0x08)
#define SCHEDULETABLE_AUTOSTART_SYNCHRON        (TIME_OBJ_AUTOSTART | 0x0C)
#define SCHEDULETABLE_STOPPED                   TIME_OBJ_SLEEP
#define SCHEDULETABLE_RUNNING                   TIME_OBJ_ACTIVE
#define SCHEDULETABLE_NEXT                      (TIME_OBJ_ACTIVE | 0x04)
#define SCHEDULETABLE_WAITING                   (TIME_OBJ_ACTIVE | 0x08)
#define SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS   (TIME_OBJ_ACTIVE | 0x0C)
#define SCHEDULETABLE_BOOTSTRAP                 0x10
#define SCHEDULETABLE_ASYNC                     0x20

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
 * @def OBJECT_IOC_RECEIVER
 *
 * Identifier of an ioc receiver object
 */
#define OBJECT_IOC_RECEIVER   5

/**
 * @def OBJECT_IOC_SENDER
 *
 * Identifier of an ioc sender object
 */
#define OBJECT_IOC_SENDER     6

/**
 * @def OBJECT_SPINLOCK
 *
 * Identifier of an spinlock object
 */
#define OBJECT_SPINLOCK       7

/**
 * @def OBJECT_KIND_COUNT
 *
 * number of object kind
 */
#define OBJECT_TYPE_COUNT     8

/**
 *  @def  ACCESS_READ
 *
 *  Return value used by CheckObjectAccess. @see #CheckObjectAccess
 *  This value is composed by 2 bits : bit0 : access/no access
 *                                     bit1 : write/read
 */
/*#define ACCESS_READ   2*/

/**
 *  @def  ACCESS_WRITE
 *
 *  Return value used by CheckObjectAccess. @see #CheckObjectAccess
 *  This value is composed by 2 bits : bit0 : access/no access
 *                                     bit1 : write/read
 */
/*#define ACCESS_WRITE  3*/

/**
 *  @def  ACCESS_READ
 *
 *  Return value used by CheckObjectAccess. @see #CheckObjectAccess
 *
 */
#define ACCESS_READ   1

/**
 *  @def  ACCESS_WRITE
 *
 *  Return value used by CheckObjectAccess. @see #CheckObjectAccess
 *
 */
#define ACCESS_WRITE  2

/**
 *  @def  ACCESS_FULL
 *
 *  Return value used by CheckObjectAccess. @see #CheckObjectAccess
 *
 */
#define ACCESS_FULL   3

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
