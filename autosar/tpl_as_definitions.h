/*
 *  tpl_as_definitions.h
 *  trampoline
 *
 *  Created by Jean-Luc B�chennec on 20/11/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef TPL_AS_DEFINITIONS_H
#define TPL_AS_DEFINITIONS_H

#include "tpl_os_definitions.h"

/* Schedule tables states */

#define SCHEDULETABLE_AUTOSTART                 TIME_OBJ_AUTOSTART
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
 * @def OBJECT_COUNTER
 * 
 * Identifier of a counter object
 */
#define OBJECT_COUNTER        3

/**
 * @def OBJECT_SCHEDULETABLE
 * 
 * Identifier of a schedule table object
 */
#define OBJECT_SCHEDULETABLE  4

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

#endif /* TPL_AS_DEFINITIONS_H */
