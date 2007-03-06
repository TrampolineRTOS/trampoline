/*
 * @file tpl_os_kernel.h
 *
 * @section desc File description
 *
 * Trampoline Event Management header file
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
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

#ifndef TPL_OS_EVENT_H
#define TPL_OS_EVENT_H

#include "tpl_os_types.h"

/*
 * Event Control
 * see paragraph 13.5,
 * pages 60+ of OSEK/VDX 2.2.2 spec
 */
 
/**
 * @typedef EventMaskType
 *
 * identifies an event
 *
 * see paragraph 13.5.1 page 60 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_event_mask  EventMaskType;

/**
 * @typedef EventMaskRefType
 *
 * references an #EventMaskType
 *
 * see paragraph 13.5.1 page 60 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_event_mask  *EventMaskRefType;

/**
 * @def DeclareEvent
 *
 * defines an event
 *
 * @param event_id C identifier of the event
 *
 * see paragraph 13.5.2.1 page 60 of OSEK/VDX 2.2.2 spec
 */
#define DeclareEvent(event_id)

/*
 * System services
 * see paragraph 13.5.3,
 * pages 60+ of OSEK/VDX 2.2.2 spec
 */

/**
 * Set events of a task
 *
 * @param TaskID identifier of the task for which events will be set
 * @param Mask mask for selected event bits
 *
 * @retval E_OK no error
 * @retval E_OS_ID (extended error only) TaskID is invalid
 * @retval E_OS_ACCESS (extended error only) referenced task is not extended task
 * @retval E_OS_STATE (extended error only) referenced task is suspended
 *
 * see paragraph 13.5.3.1 page 60 of OSEK/VDX 2.2.2 spec
 */
StatusType SetEvent(
    const TaskType      TaskID,
    const EventMaskType Mask);

/**
 * Clear event of current task
 *
 * @param Mask mask for selected event bits
 *
 * @retval E_OK no error
 * @retval E_OS_ACCESS (extended error only) caller is not an extended task
 * @retval E_OS_CALLEVEL (extended error only) call at interrupt level
 *
 * see paragraph 13.5.3.2 page 61 of OSEK/VDX 2.2.2 spec
 */
StatusType ClearEvent(const EventMaskType Mask);

/**
 * Get the state of an event
 *
 * @param TaskID identifier of the task
 * @param Event #EventMaskType variable where the event value will be stored
 *
 * @retval E_OK no error
 * @retval E_OS_ACCESS (extended error only) referenced task is not extended
 * @retval E_OS_STATE (extended error only) referenced task is suspended
 *
 * see paragraph 13.5.3.3 page 61 of OSEK/VDX 2.2.2 spec
 */
StatusType GetEvent(
    const TaskType          TaskID,
    const EventMaskRefType  Event);

/**
 * Waits for some bits in the event
 *
 * @param Mask mask for selected event bits
 *
 * @retval E_OK no error
 * @retval E_OS_ACCESS (extended error only) calling task is not an extended task
 * @retval E_OS_RESOURCE (extended error only) calling task occupies resources
 * @retval E_OS_CALLEVEL (extended error only) call at interrupt level
 *
 * see paragraph 13.5.3.4 page 61 of OSEK/VDX 2.2.2 spec
 */
StatusType WaitEvent(const EventMaskType Mask);

#endif /* TPL_OS_EVENT */

/* End of file tpl_os_event.h */
