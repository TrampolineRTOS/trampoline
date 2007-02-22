/**
 * @file tpl_os.h
 *
 * @section desc File description
 *
 * This header file provides standard OSEK-VDX API. We do not give detailed 
 * documentation here, you just have to follow the specification reference for
 * each element you need more informations.
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
 * Trampoline est protégé par la loi sur la propriété intellectuelle
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
 
#ifndef __TPL_OS_H__
#define __TPL_OS_H__

#include "tpl_os_internal_types.h"
#include "tpl_os_definitions.h"

/*
 * Common data types
 */

/**
 * @typedef StatusType
 *
 * Status information for many services. Values names are usually prefixed by E_OS_*.
 * Each API service provides more informations about error codes.
 * 
 * See §13.1, page 48 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_status      StatusType;

/**
 * @typedef TaskStateType
 *
 * identifies the state of a task
 *
 * see §13.2.1, page 49 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_exec_state  TaskStateType;

/**
 * @typedef TaskStateRefType
 *
 * References a #TaskStateType
 *
 * see §13.2.1, page 49 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_exec_state  *TaskStateRefType;

/**
 * @typedef TaskType
 *
 * A task's identifier.
 *
 * see §13.2.1, page 49 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_task_id     TaskType;

/**
 * @typedef TaskRefType
 *
 * References a #TaskType
 *
 * see §13.2.1, page 49 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_task_id     *TaskRefType;

/*
 * Task Management
 * constructional elements
 * see §13.2.2,
 * pages 50+ of OSEK/VDX 2.2.2 spec
 */

/**
 * @def DeclareTask
 *
 * This is used to define a task
 *
 * @param task_id the task identifier (provide a C identifier here)
 *
 * see §13.2.2.1 page 50 of OSEK/VDX 2.2.2 spec
 */
#define DeclareTask(task_id)

/*
 * Task Management
 * System services
 * see §13.2.3,
 * pages 50+ of OSEK/VDX 2.2.2 spec
 */

/**
 * (re)activates a task.
 *
 * @param TaskID identifier of the task to be activated
 *
 * @retval E_OK no error
 * @retval E_OS_LIMIT too many task activations
 * @retval E_OS_ID (extended error only) TaskID is invalid
 *
 * see §13.2.3.1 page 50 of OSEK/VDX 2.2.2 spec
 */
StatusType ActivateTask(TaskType TaskID);

/**
 * Terminates the execution of a task.
 *
 * @note this function never returns unless extended error mode is
 * active and an error occurred
 *
 * @retval E_OS_RESOURCE (extended error only) task still occupies resources
 * @retval E_OS_CALLEVEL (extended error only) call at interrupt level
 *
 * see §13.2.3.2 page 51 of OSEK/VDX 2.2.2 spec
 */
StatusType TerminateTask(void);

/**
 * Chain terminaison of current task with activation of another.
 *
 * @param TaskID identifier of the task to activate
 *
 * @note if this function succeeds, it does not returns (as the current
 * task is then finished)
 *
 * @retval E_OS_LIMIT too many task activations
 * @retval E_OS_ID (extended error only) TaskID is invalid
 *
 * see §13.2.3.3 page 51 of OSEK/VDX 2.2.2 spec
 */
StatusType ChainTask(TaskType TaskID);

/**
 * Call to the scheduler.
 *
 * @retval E_OK no error
 * @retval E_OS_CALLEVEL (extended error only) call at interrupt level
 * @retval E_OS_RESOURCE (extended error only) task still occupies resource
 *
 * see §13.2.3.4 page 52 of OSEK/VDX 2.2.2 spec
 */
StatusType Schedule(void);

/**
 * Gives the identifier of the running task
 *
 * @param TaskID reference of the variable where the identifier will be returned
 *
 * @retval E_OK no error
 *
 * see §13.2.3.5 page 53 of OSEK/VDX 2.2.2 spec
 */
StatusType GetTaskID(TaskRefType TaskID);

/**
 * Gives the state of a task
 *
 * @param TaskID identifier of the task
 * @param State reference of the variable where the state of the specified task will be stored
 *
 * @retval E_OK no error
 * @retval E_OS_ID (extended error only) TaskID is invalid
 *
 * see §13.2.3.6
 */
StatusType GetTaskState(TaskType TaskID, TaskStateRefType State);

/*
 * Interrupt handling
 * see §13.3,
 * pages 54+ of OSEK/VDX 2.2.2 spec
 */

/**
 * Enable all interrupts
 *
 * see §13.3.2.1 page 54 of OSEK/VDX 2.2.2 spec
 *
 * @see #DisableAllInterrupts
 */
void EnableAllInterrupts(void);     

/**
 * Disable all interrupts
 *
 * see §13.3.2.2 page 55 of OSEK/VDX 2.2.2 spec
 *
 * @see #EnableAllInterrupts
 */
void DisableAllInterrupts(void);

/** 
 * Resume all interrupts
 *
 * see §13.3.2.3 page 55 of OSEK/VDX 2.2.2 spec
 *
 * @see #SuspendAllInterrupts
 */
void ResumeAllInterrupts(void);

/**
 * Suspend all interrupts
 *
 * see §13.3.2.4 page 56 of OSEK/VDX 2.2.2 spec
 *
 * @see #ResumeAllInterrupts
 */
void SuspendAllInterrupts(void);

/** 
 * Resume category 2 interrupts
 *
 * see §13.3.2.5 page 56 of OSEK/VDX 2.2.2 spec
 * 
 * @see #SuspendOSInterrupts
 */
void ResumeOSInterrupts(void);

/**
 * Suspend category 2 interrupts
 *
 * see §13.3.2.6 page 57 of OSEK/VDX 2.2.2 spec
 *
 * @see #ResumeOSInterrupts
 */
void SuspendOSInterrupts(void);

/*
 * Resource Management
 * see §13.4,
 * pages 58+ of OSEK/VDX 2.2.2 spec
 */

/**
 * @typedef ResourceType
 * 
 * identifies a resource
 *
 * see §13.4.1 page 58 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_resource_id ResourceType;

/**
 * @def DeclareResource
 *
 * Defines a resource
 *
 * @param resource_id resource's C identifier
 *
 * see "Constructional elements" §13.4.2 page 58 of OSEK/VDX 2.2.2 spec
 */
#define DeclareResource(resource_id)

/*
 * System services
 * see §13.4.3,
 * pages 58+ of OSEK/VDX 2.2.2 spec
 */

/**
 * Get the resource
 *
 * @param ResID identifier of the resource
 *
 * @retval E_OK no error
 * @retval E_OS_ID ResID is invalid
 *
 * see §13.4.3.1 page 58 of OSEK/VDX 2.2.2 spec
 */
StatusType GetResource(ResourceType ResID);

/**
 * Releases the resource
 *
 * @param ResID identifier of the resource
 *
 * @retval E_OK no error
 * @retval (extended error only) E_OS_ID ResID is invalid
 * @retval (extended error only) E_OS_NOFUNC the resource is not occupied or another resource shall be released before
 * @retval (extended error only) E_OS_ACCESS the resource has a lower ceiling priority than the static priority of the caller
 *
 * see §13.4.3.2 page 59 of OSEK/VDX 2.2.2 spec
 */
StatusType ReleaseResource(ResourceType ResID);

/**
 * This special resource is used to deny preemption.
 *
 * @note It can be used by a task but is not stored
 * in the general resource table.  
 *
 * see §13.4.4 page 59 of OSEK/VDX 2.2.2 spec
 */
extern ResourceType RES_SCHEDULER;

/*
 * Event Control
 * see §13.5,
 * pages 60+ of OSEK/VDX 2.2.2 spec
 */
 
/**
 * @typedef EventMaskType
 *
 * identifies an event
 *
 * see §13.5.1 page 60 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_event_mask  EventMaskType;

/**
 * @typedef EventMaskRefType
 *
 * references an #EventMaskType
 *
 * see §13.5.1 page 60 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_event_mask  *EventMaskRefType;

/**
 * @def DeclareEvent
 *
 * defines an event
 *
 * @param event_id C identifier of the event
 *
 * see §13.5.2.1 page 60 of OSEK/VDX 2.2.2 spec
 */
#define DeclareEvent(event_id)

/*
 * System services
 * see §13.5.3,
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
 * see §13.5.3.1 page 60 of OSEK/VDX 2.2.2 spec
 */
StatusType SetEvent(TaskType TaskID, EventMaskType Mask);

/**
 * Clear event of current task
 *
 * @param Mask mask for selected event bits
 *
 * @retval E_OK no error
 * @retval E_OS_ACCESS (extended error only) caller is not an extended task
 * @retval E_OS_CALLEVEL (extended error only) call at interrupt level
 *
 * see §13.5.3.2 page 61 of OSEK/VDX 2.2.2 spec
 */
StatusType ClearEvent(EventMaskType Mask);

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
 * see §13.5.3.3 page 61 of OSEK/VDX 2.2.2 spec
 */
StatusType GetEvent(TaskType TaskID, EventMaskRefType Event);

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
 * see §13.5.3.4 page 61 of OSEK/VDX 2.2.2 spec
 */
StatusType WaitEvent(EventMaskType Mask);

/*
 * Alarms
 * see §13.6,
 * pages 62+ of OSEK/VDX 2.2.2 spec
 */

/**
 * @typedef TickType
 *
 * Represents a count value in ticks
 * 
 * see §13.6.1 page 62 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_tick            TickType;

/**
 * @typedef TickRefType
 *
 * References a #TickType
 *
 * see §13.6.1 page 62 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_tick            *TickRefType;

/**
 * @typedef AlarmBaseType
 *
 * see §13.6.1 page 62 of OSEK/VDX 2.2.2 spec
 *
 * @see #tpl_alarm_base
 */
typedef tpl_alarm_base      AlarmBaseType;

/**
 * @typedef AlarmBaseRefType
 *
 * References an #AlarmBaseType
 *
 * See §13.6.1 page 62 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_alarm_base      *AlarmBaseRefType;

/**
 * @typedef AlarmType
 *
 * alarm identifier
 *
 * See §13.6.1 page 62 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_alarm_id        AlarmType;

/**
 * @def DeclareAlarm
 *
 * Defines an alarm
 *
 * @param alarm_id alarm C-identifier
 *
 * see §13.6.2.1 page 62 of OSEK/VDX 2.2.2 spec
 */
#define DeclareAlarm(alarm_id)

/*
 * System services
 * see §13.6.3,
 * pages 63+ of OSEK/VDX 2.2.2 spec
 */

/**
 * Get informations about alarm base
 *
 * @param AlarmID identifier of the alarm
 * @param Info #AlarmBaseType variable where will be stored requested informations
 *
 * @retval E_OK no error
 * @retval E_OS_ID (extended error only) AlarmID is invalid
 *
 * see §13.6.3.1 page 63 of OSEK/VDX 2.2.2 spec
 */
StatusType GetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Info);

/**
 * Get relative ticks count before alarm exprires
 *
 * @param AlarmID identifier of the alarm
 * @param Tick reference to the variable where ticks will be stored
 *
 * @retval E_OK no error
 * @retval E_OS_NOFUNC AlarmID is not used
 * @retval E_OS_ID (extended error only) AlarmID is invalid
 *
 * see §13.6.3.2 page 63 of OSEK/VDX 2.2.2 spec
 */
StatusType GetAlarm(AlarmType AlarmID, TickRefType Tick);

/**
 * Changes the alarm trigger relative to the current counter
 *
 * @param AlarmID identifier of the alarm
 * @param increment relative ticks to set
 * @param cycle number of cycles after next expiration (0 if unused)
 *
 * @retval E_OK no error
 * @retval E_OS_STATE alarm is already in use
 * @retval E_OS_ID (extended error only) AlarmID is invalid
 * @retval E_OS_VALUE (extended error only) increment or cycle is outside of limits
 *
 * see §13.6.3.3 page 63 of OSEK/VDX 2.2.2 spec
 */
StatusType SetRelAlarm(AlarmType AlarmID, TickType increment, TickType cycle);

/**
 * Changes the alarm trigger relative to the current counter
 *
 * @param AlarmID identifier of the alarm
 * @param start the number of tick when the alarm will raise
 * @param cycle the number of tick when the alarm will raise after the first expiry
 *
 * @retval E_OK no error
 * @retval E_OS_STATE alarm is already in use
 * @retval E_OS_ID (extended error only) AlarmID is invalid
 * @retval E_OS_VALUE (extended error only) start or cycle is outside of limits
 *
 * see §13.6.3.3 page 63 of OSEK/VDX 2.2.2 spec
 */
StatusType SetAbsAlarm(AlarmType AlarmID, TickType start, TickType cycle);

/**
 * Cancels the alarm
 * 
 * @param AlarmID identifier of the alarm
 *
 * @retval E_OK no error
 * @retval E_OS_NOFUNC alarm is not in use
 * @retval E_OS_ID (extended error only) AlarmID is invalid
 *
 * see §13.6.3.3 page 63 of OSEK/VDX 2.2.2 spec
 */
StatusType CancelAlarm(AlarmType AlarmID);

/*
 * Operating system execution control
 * see §13.7,
 * pages 66+ of OSEK/VDX 2.2.2 spec
 */

/**
 * @typedef AppModeType
 *
 * Application execution mode
 *
 * see §13.7.1 page 66 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_application_mode AppModeType;

/*
 * System services
 * see §13.7.2,
 * pages 66+ of OSEK/VDX 2.2.2 spec
 */

/**
 * Gives the current application mode
 *
 * @return the application mode
 *
 * see §13.7.2.1 page 66 of OSEK/VDX 2.2.2 spec
 */
AppModeType GetActiveApplicationMode(void);

/**
 * Starts Trampoline
 *
 * @param Mode choosen application mode
 *
 * see §13.7.2.2 page 66 of OSEK/VDX 2.2.2 spec
 */
void StartOS(AppModeType Mode);

/**
 * Stops Trampoline
 *
 * @param Error error occured
 *
 * see §13.7.2.3 page 67 of OSEK/VDX 2.2.2 spec
 */
void ShutdownOS(StatusType Error);

/**
 * Additional non-standard system service to terminate a category 2 interrupt routine.
 *
 * This service is equivalent to TerminateTask but for ISR2
 */
StatusType TerminateISR2(void);

#endif
