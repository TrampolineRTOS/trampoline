/**
 * @file tpl_os_types.h
 *
 * @section descr File description
 *
 * Trampoline general types definitions. This file is included
 * by the communication library
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
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
typedef tpl_status      StatusType;

/**
 * @typedef TaskStateType
 *
 * identifies the state of a task
 *
 * see paragraph 13.2.1, page 49 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_exec_state  TaskStateType;

/**
 * @typedef TaskStateRefType
 *
 * References a #TaskStateType
 *
 * see paragraph 13.2.1, page 49 of OSEK/VDX 2.2.2 spec
 */
typedef P2VAR(tpl_exec_state, OS_APPL_DATA, AUTOMATIC)  TaskStateRefType;

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
typedef P2VAR(tpl_task_id, OS_APPL_DATA, AUTOMATIC) TaskRefType;

#endif /* TPL_OS_TYPES_H */

/* End of file tpl_os_types.h */
