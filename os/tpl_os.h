/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * OSEK-VDX API header file
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 *
 */
 
#ifndef __TPL_OS_H__
#define __TPL_OS_H__

#include "tpl_os_internal_types.h"
#include "tpl_os_definitions.h"

/*
 * Common data types
 * See paragraph 13.1,
 * pages 48 to 49 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_status      StatusType;
typedef tpl_exec_state  TaskStateType;
typedef tpl_exec_state  *TaskStateRefType;

typedef tpl_task_id     TaskType;
typedef tpl_task_id     *TaskRefType;

/*
 * Task Management
 * Constructional elements
 * See paragraph 13.2.2,
 * pages 50+ of OSEK/VDX 2.2.2 spec
 */

/* task declaration, see §13.2.2.1 */
#define DeclareTask(task_id)

/*
 * Task Management
 * System services
 * See paragraph 13.2.3,
 * pages 50+ of OSEK/VDX 2.2.2 spec
 */

StatusType ActivateTask(TaskType);  /* task activation, see §13.2.3.1       */
StatusType TerminateTask(void);     /* task termination, see §13.2.3.2      */
StatusType ChainTask(TaskType);     /* task chaining, see §13.2.3.3         */
StatusType Schedule(void);          /* call to the scheduler, see §13.2.3.4 */
StatusType GetTaskID(TaskRefType);  /* running task ref, see §13.2.3.5      */
StatusType GetTaskState(TaskType,TaskStateRefType); /* state, §13.2.3.6     */

/*
 * Interrupt handling
 * See paragraph 13.3,
 * pages 54+ of OSEK/VDX 2.2.2 spec
 */
void EnableAllInterrupts(void);     /* Enable interrupts, see §13.3.2.1     */
void DisableAllInterrupts(void);    /* Disable interrupts, see §13.3.2.2    */
void ResumeAllInterrupts(void);     /* Resume interrupts, see §13.3.2.3     */
void SuspendAllInterrupts(void);    /* Suspend interrupts, see §13.3.2.4    */
void ResumeOSInterrupts(void);      /* Resume OS interrupts, see §13.3.2.5  */
void SuspendOSInterrupts(void);     /* Suspend OS interrupts, see §13.3.2.6 */

/*
 * Resource Management
 * See paragraph 13.4,
 * pages 58+ of OSEK/VDX 2.2.2 spec
 */

/*
 * Data types
 * §13.4.1
 * Page 58 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_resource_id ResourceType;

/*
 * Constructional elements
 * §13.4.2
 * Page 58 of OSEK/VDX 2.2.2 spec
 */
#define DeclareResource(resource_id)

/*
 * System services
 * See paragraph 13.4.3,
 * pages 58+ of OSEK/VDX 2.2.2 spec
 */
StatusType GetResource(ResourceType);       /* Get resource, see §13.4.3.1  */
StatusType ReleaseResource(ResourceType);   /* Release resource, §13.4.3.2  */

extern ResourceType RES_SCHEDULER;

/*
 * Event Control
 * See paragraph 13.5,
 * pages 60+ of OSEK/VDX 2.2.2 spec
 */
 
/*
 * Data types
 * See paragraph 13.5.1
 * page 60 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_event_mask  EventMaskType;
typedef tpl_event_mask  *EventMaskRefType;

/*
 * Constructional elements
 * Declaring an event, see $13.5.2.1
 */
#define DeclareEvent(event_id)

/*
 * System services
 * See paragraph 13.5.3,
 * pages 60+ of OSEK/VDX 2.2.2 spec
 */
StatusType SetEvent(TaskType, EventMaskType);
StatusType ClearEvent(EventMaskType);
StatusType GetEvent(TaskType, EventMaskRefType);
StatusType WaitEvent(EventMaskType);

/*
 * Alarms
 * See paragraph 13.6,
 * pages 62+ of OSEK/VDX 2.2.2 spec
 */

/*
 * Data types
 * See paragraph 13.6.1
 * page 60 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_tick            TickType;
typedef tpl_tick            *TickRefType;

/**
 * @typedef AlarmBaseType
 *
 * See paragraph 13.6.1 page 62 of OSEK/VDX 2.2.22 spec
 *
 * @see #tpl_alarm_base
 */
typedef tpl_alarm_base      AlarmBaseType;
typedef tpl_alarm_base      *AlarmBaseRefType;
typedef tpl_alarm_id        AlarmType;

/*
 * Constructional elements
 * Declaring an event, see $13.6.2.1
 */
#define DeclareAlarm(alarm_id)

/*
 * System services
 * See paragraph 13.6.3,
 * pages 63+ of OSEK/VDX 2.2.2 spec
 */
StatusType GetAlarmBase(AlarmType, AlarmBaseRefType);
StatusType GetAlarm(AlarmType, TickRefType);
StatusType SetRelAlarm(AlarmType, TickType, TickType);
StatusType SetAbsAlarm(AlarmType, TickType, TickType);
StatusType CancelAlarm(AlarmType);

/*
 * Operating system execution control
 * See paragraph 13.7,
 * pages 66+ of OSEK/VDX 2.2.2 spec
 */

/*
 * Data types
 */
typedef tpl_application_mode AppModeType;

/*
 * System services
 * See paragraph 13.7.2,
 * pages 66+ of OSEK/VDX 2.2.2 spec
 */
AppModeType GetActiveApplicationMode(void); /* Current application mode     */
void StartOS(AppModeType);                  /* Starting the OS              */
void ShutdownOS(StatusType);                /* Shuting Down the OS          */

/*
 * Additional system service
 */
StatusType TerminateISR2(void);

#endif
