/**
 * @file tpl_os_internal_types.h
 *
 * @section descr File description
 *
 * Trampoline internal types. These types are not intended
 * to be used in an application.
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

#ifndef TPL_OS_INTERNAL_TYPES_H
#define TPL_OS_INTERNAL_TYPES_H

#include "tpl_os_std_types.h"
#include "tpl_os_custom_types.h"
#include "tpl_machine.h"
#include "tpl_compiler.h"

/**
 * @def CONFORM_ECC1
 *
 * identifies the ECC1 conformance class
 *
 * @see #CONFORMANCE_CLASS
 */
#define CONFORM_ECC1        1

/**
 * @def CONFORM_ECC2
 *
 * identifies the ECC2 conformance class
 *
 * @see #CONFORMANCE_CLASS
 */
#define CONFORM_ECC2        2

/**
 * @def CONFORMANCE_CLASS
 *
 * represents the configured conformance class
 *
 * @warning at this time, Trampoline only supports ECC2
 */
#define CONFORMANCE_CLASS   CONFORM_ECC2

/**************************************
 * Special result code for Trampoline *
 **************************************/

/**
 * @def NO_SPECIAL_CODE
 *
 * Nothing particular to Trampoline in this code.
 *
 * @note This is a Trampoline result code, not an OSEK one.
 *
 * @see #tpl_status
 */
#define NO_SPECIAL_CODE         0

/**
 * @def NEED_RESCHEDULING
 *
 * Scheduler have to be called, probably because the ready list
 * has changed.
 *
 * @note This is a Trampoline result code, not an OSEK one.
 *
 * @see #tpl_status
 */
#define NEED_RESCHEDULING       32

/**
 * @def NEED_CONTEXT_SWITCH
 *
 * Context switch has to be made.
 *
 * @note This is a Trampoline result code, not an OSEK one.
 *
 * @see #tpl_status
 */
#define NEED_CONTEXT_SWITCH     64

/**
 * @def E_OK_AND_SCHEDULE
 *
 * Combines OSEK-E_OK and Trampoline-NEED_RESCHEDULING result codes
 *
 * @see #tpl_status
 */
#define E_OK_AND_SCHEDULE   ((tpl_status)E_OK | (tpl_status)NEED_RESCHEDULING)

/**
 * @def OSEK_STATUS_MASK
 *
 * This AND mask can be used to keep only result code
 * specific to OSEK in a tpl_status (StatusType)
 * result code.
 *
 * @see #tpl_status
 */
#define OSEK_STATUS_MASK        0x1F

/**
 * @def TRAMPOLINE_STATUS_MASK
 *
 * This AND mask can be used to keep only result code
 * specific to Trampoline in a tpl_status (StatusType)
 * result code.
 *
 * @see #tpl_status
 */
#define TRAMPOLINE_STATUS_MASK  0xE0

#ifdef WITH_AUTOSAR
/**
 * @def HARDWARE_COUNTER
 *
 * Identifies a hardware counter
 *
 * @see #tpl_counter_kind
 */
#define HARDWARE_COUNTER    0

/**
 * @def SOFTWARE_COUNTER
 *
 * Identifies a software counter
 *
 * @see #tpl_counter_kind
 */
#define SOFTWARE_COUNTER    1

/**
 * @typedef tpl_counter_kind
 *
 * Kind (hardware or software) of a counter
 */
typedef u8 tpl_counter_kind;

#endif

/**
 * @typedef tpl_bool
 *
 * Standard bool declaration. Values can be #TRUE or #FALSE.
 */
typedef u8 tpl_bool;

/**
 * @typedef tpl_status
 *
 * This type is used for return
 * status of services (ie one of the result
 * codes specified below).
 *
 * It is binary compatible with OSEK StatusType, provided
 * Trampoline specific codes are removed (via #OSEK_STATUS_MASK
 * AND-mask).
 *
 * @see #OSEK_STATUS_MASK
 * @see #StatusType
 */
typedef u8 tpl_status;

/**
 * @typedef tpl_exec_state
 *
 * This type represents the state of a task.
 *
 * See page 16+ of the OSEK/VDX 2.2.2 spec
 *
 * Value can be one of :
 * - #AUTOSTART
 * - #RUNNING
 * - #READY
 * - #SUSPENDED
 * - #WAITING (only for ECC1 or ECC2 conformance classes)
 * but also :
 * - #READY_AND_NEW that means a task is in the ready list before running
 *   for the first time and its context needs to be initialized.
 */
typedef u8 tpl_exec_state;

/**
 * @struct ALARM_BASE_TYPE
 *
 * This structure is defined as paragraph 13.6.1 of OSEK/VDX spec
 *
 * @see AlarmBaseType
 */
struct ALARM_BASE_TYPE {
    VAR(tpl_tick, TYPEDEF)  maxallowedvalue;    /**< maximum possible allowed
                                                     count values in tick
                                                */
    VAR(tpl_tick, TYPEDEF)  ticksperbase;       /**< number of ticks required
                                                     to reach a counter-
                                                     specific (significant)
                                                     unit 
                                                */
    VAR(tpl_tick, TYPEDEF)  mincycle;           /**< smallest allowed value for
                                                     the cycle-parameter of
                                                     SetRelAlarm/SetAbsAlarm
                                                     (only for systems with
                                                     extended status)
                                                */
};

/**
 * @typedef tpl_alarm_base
 *
 * This is an alias for the structure #ALARM_BASE_TYPE
 *
 * @see #ALARM_BASE_TYPE
 * @see #AlarmBaseType
 */
typedef struct ALARM_BASE_TYPE tpl_alarm_base;

/**
 * @typedef tpl_application_mode
 *
 * Identifies an application mode
 *
 * @see #AppModeType
 */
typedef u8 tpl_application_mode;

/**
 * @typedef tpl_callback_func
 *
 * This type is used for various
 * callback function type in Trampoline.
 */
typedef P2FUNC(void, OS_APPL_CODE, tpl_callback_func)(void);

#endif /* TPL_OS_INTERNAL_TYPES_H */

/* End of file tpl_os_internal_type.h */
