/**
 * @file tpl_os_types.h
 *
 * @section descr File description
 *
 * Trampoline general types definitions. This file is included
 * by the communication library
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_OS_TYPES_H
#define TPL_OS_TYPES_H

#include "tpl_os_internal_types.h"

/**
 * @typedef StatusType
 *
 * Status information for many services. Values names are usually prefixed by
 * E_OS_*. Each API service provides more informations about error codes.
 *
 * See paragraph 13.1, page 48 of OSEK/VDX 2.2.2 spec
 */
#ifndef STATUSTYPE_DEFINED
#define STATUSTYPE_DEFINED
typedef tpl_status      StatusType;
#endif

/**
 * @typedef Std_ReturnType
 *
 * This type can be used as standard API return type which is shared between the
 * RTE and the BSW modules.
 *
 * See AUTOSAR R21-11 AUTOSAR_SWS_StandardTypes chapter 8.1.1.
 */
typedef uint8 Std_ReturnType;

/**
 * @typedef TaskStateType
 *
 * identifies the state of a task
 *
 * see paragraph 13.2.1, page 49 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_proc_state  TaskStateType;

/**
 * @typedef TaskStateRefType
 *
 * References a #TaskStateType
 *
 * see paragraph 13.2.1, page 49 of OSEK/VDX 2.2.2 spec
 */
typedef P2VAR(tpl_proc_state, TYPEDEF, OS_APPL_DATA)  TaskStateRefType;

/**
 * @typedef TaskType
 *
 * A task's identifier.
 *
 * see paragraph 13.2.1, page 49 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_task_id     TaskType;

/**
 * @typedef TaskRefType
 *
 * References a #TaskType
 *
 * see paragraph 13.2.1, page 49 of OSEK/VDX 2.2.2 spec
 */
typedef P2VAR(tpl_task_id, TYPEDEF, OS_APPL_DATA) TaskRefType;

/**
 * @typedef TickType
 *
 * Represents a count value in ticks
 *
 * see paragraph 13.6.1 page 62 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_tick            TickType;

/**
 * @typedef TickRefType
 *
 * References a #TickType
 *
 * see paragraph 13.6.1 page 62 of OSEK/VDX 2.2.2 spec
 */
typedef P2VAR(tpl_tick, TYPEDEF, OS_APPL_DATA)  TickRefType;

#endif /* TPL_OS_TYPES_H */

/* End of file tpl_os_types.h */
