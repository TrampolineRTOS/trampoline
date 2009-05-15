/*
 *  @file tpl_os_service_ids.h
 *
 * @section desc File description
 *
 * Trampoline service ids
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * libpcl port is copyright (c) Jean-Francois Deverge 2006
 * ARM7 port is copyright (c) ESEO 2007
 * hcs12 port is copyright (c) Geensys 2007
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
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

#ifndef TPL_OS_SERVICE_IDS
#define TPL_OS_SERVICE_IDS

/************************
 * Services identifiers *
 ************************/

/**
 * @def OSServiceId_ActivateTask
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #ActivateTask
 */
#define OSServiceId_ActivateTask                0

/**
 * @def OSServiceId_TerminateTask
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #TerminateTask
 */
#define OSServiceId_TerminateTask               1

/**
 * @def OSServiceId_ChainTask
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #ChainTask
 */
#define OSServiceId_ChainTask                   2

/**
 * @def OSServiceId_Schedule
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #Schedule
 */
#define OSServiceId_Schedule                    3

/**
 * @def OSServiceId_GetTaskID
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetTaskID
 */
#define OSServiceId_GetTaskID                   4

/**
 * @def OSServiceId_GetTaskState
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetTaskState
 */
#define OSServiceId_GetTaskState                5

/**
 * @def OSServiceId_EnableAllInterrupts
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #EnableAllInterrupts
 */
#define OSServiceId_EnableAllInterrupts         6

/**
 * @def OSServiceId_DisableAllInterrupts
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #DisableAllInterrupts
 */
#define OSServiceId_DisableAllInterrupts        7

/**
 * @def OSServiceId_ResumeAllInterrupts
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #ResumeAllInterrupts
 */
#define OSServiceId_ResumeAllInterrupts         8

/**
 * @def OSServiceId_SuspendAllInterrupts
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #SuspendAllInterrupts
 */
#define OSServiceId_SuspendAllInterrupts        9

/**
 * @def OSServiceId_ResumeOSInterrupts
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #ResumeOSInterrupts
 */
#define OSServiceId_ResumeOSInterrupts          10

/**
 * @def OSServiceId_SuspendOSInterrupts
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #SuspendOSInterrupts
 */
#define OSServiceId_SuspendOSInterrupts         11


/**
 * @def OSServiceId_GetResource
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetResource
 */
#define OSServiceId_GetResource                 12

/**
 * @def OSServiceId_ReleaseResource
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #ReleaseResource
 */
#define OSServiceId_ReleaseResource             13

/**
 * @def OSServiceId_SetEvent
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #SetEvent
 */
#define OSServiceId_SetEvent                    14

/**
 * @def OSServiceId_ClearEvent
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #ClearEvent
 */
#define OSServiceId_ClearEvent                  15

/**
 * @def OSServiceId_GetEvent
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetEvent
 */
#define OSServiceId_GetEvent                    16

/**
 * @def OSServiceId_WaitEvent
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #WaitEvent
 */
#define OSServiceId_WaitEvent                   17

/**
 * @def OSServiceId_GetAlarmBase
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetAlarmBase
 */
#define OSServiceId_GetAlarmBase                18

/**
 * @def OSServiceId_GetAlarm
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetAlarm
 */
#define OSServiceId_GetAlarm                    19

/**
 * @def OSServiceId_SetRelAlarm
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #SetRelAlarm
 */
#define OSServiceId_SetRelAlarm                 20

/**
 * @def OSServiceId_SetAbsAlarm
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #SetAbsAlarm
 */
#define OSServiceId_SetAbsAlarm                 21

/**
 * @def OSServiceId_CancelAlarm
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #CancelAlarm
 */
#define OSServiceId_CancelAlarm                 22

/**
 * @def OSServiceId_GetActiveApplicationMode
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetActiveApplicationMode
 */
#define OSServiceId_GetActiveApplicationMode    23

/**
 * @def OSServiceId_StartOS
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #StartOS
 */
#define OSServiceId_StartOS                     24

/**
 * @def OSServiceId_ShutdownOS
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #ShutdownOS
 */
#define OSServiceId_ShutdownOS                  25

/**
 * @def OSServiceId_TerminateISR2
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #TerminateISR2
 */
#define OSServiceId_TerminateISR                26

/**
 * @def OS_SYSCALL_COUNT
 *
 * Number of system calls in the OS
 */
#define OS_SYSCALL_COUNT                        27

/* TPL_OS_SERVICE_IDS */
#endif
/* End of file tpl_os_service_ids.h */
