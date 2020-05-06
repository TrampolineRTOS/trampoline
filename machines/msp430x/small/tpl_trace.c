/**
 * @file tpl_trace.c
 *
 * @section desc File description
 *
 * Trampoline Trace Calls
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
 * Copyright IRISA - JF Deverge for libpcl port
 * Copyright Geensys for hcs12 port
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 */

/* should be defined before including tpl_app_define.h */
#define TRACE_FORMAT_SERIAL   0
#define TRACE_FORMAT_FRAM     1

#include "tpl_app_define.h" /* WITH_TRACE */
#include <stdint.h>

#if WITH_TRACE == YES
#include "tpl_trace.h"

#if TRACE_FORMAT == TRACE_FORMAT_SERIAL
# include "serial.h"
#endif

#define OS_START_SEC_CODE
#include "tpl_memmap.h"


FUNC(tpl_tick, OS_CODE) tpl_trace_get_timestamp()
{
  CONSTP2VAR(tpl_counter, AUTOMATIC, OS_APPL_DATA) counter = &SystemCounter_counter_desc;
  tpl_tick timestamp = counter->current_date;
  return timestamp;
}

FUNC(void, OS_CODE) tpl_trace_start()
{
# if TRACE_FORMAT == TRACE_FORMAT_SERIAL
  static char serialOk = 0;
  if(serialOk == 0)
  {
    tpl_serial_begin();
	serialOk = 1;
  }
# else
#  error "unsupported trace mode: TRACE_FORMAT"
#endif
}

/**
 * Trace ends (close the file for instance). This event is sent by
 * ShutdownOS() system call
 * This function should be implemented in the machine dependant trace backend.
*/
FUNC(void, OS_CODE) tpl_trace_close()
{

}

/**
* trace the execution of a task or ISR
* ** Function defined in os/tpl_trace.h **
*
*/
FUNC(void, OS_CODE) tpl_trace_proc_change_state(
    CONST(tpl_proc_id,AUTOMATIC) proc_id,
    CONST(tpl_proc_state,AUTOMATIC) target_state)
{
  const tpl_tick ts=tpl_trace_get_timestamp();
  tpl_trace_start();
# if TRACE_FORMAT == TRACE_FORMAT_SERIAL
  /* TTT 00 SSS (Type, State) */
  uint8_t byte = PROC_CHANGE_STATE<<5 | target_state;
  uint8_t chksum = byte;
  tpl_serial_putchar(byte);

  byte = ts >> 8;
  chksum += byte;
  tpl_serial_putchar(byte);

  byte = ts & 0xff;
  chksum += byte;
  tpl_serial_putchar(byte);

  byte = proc_id & 0xff;
  chksum += byte;
  tpl_serial_putchar(byte);

  tpl_serial_putchar(chksum);
# else
#  error "unsupported trace mode: TRACE_FORMAT"
#endif
}

/**
* trace the lock of a resource by an entity
* ** Function defined in os/tpl_trace.h **
* @param res_id       identifier of the locked resource
* @param target_state identifier of the locked resource
*/
FUNC(void, OS_CODE) tpl_trace_res_change_state(
    CONST(tpl_resource_id, AUTOMATIC)   res_id,
    CONST(tpl_trace_resource_state,AUTOMATIC) target_state)
{
  const tpl_tick ts=tpl_trace_get_timestamp();
  tpl_trace_start();
# if TRACE_FORMAT == TRACE_FORMAT_SERIAL
  /* TTT 00 SSS (Type, State) */
  uint8_t byte = RES_CHANGE_STATE<<5 | target_state;
  uint8_t chksum = byte;
  tpl_serial_putchar(byte);

  byte = ts >> 8;
  chksum += byte;
  tpl_serial_putchar(byte);

  byte = ts & 0xff;
  chksum += byte;
  tpl_serial_putchar(byte);

  byte = res_id & 0xff;
  chksum += byte;
  tpl_serial_putchar(byte);

  tpl_serial_putchar(chksum);
# else
#  error "unsupported trace mode: TRACE_FORMAT"
#endif
}

/**
* trace the state of a time object (alarm/schedule tables)
* ** Function defined in os/tpl_trace.h **
* @param sheduled_alarm    data structure concerning the sheduled alarm
*/
FUNC(void, OS_CODE) tpl_trace_time_obj_change_state(
    CONST(tpl_timeobj_id, AUTOMATIC) timeobj_id,
    CONST(tpl_time_obj_state, AUTOMATIC) target_state)
{
  const tpl_tick ts=tpl_trace_get_timestamp();
  tpl_trace_start();
# if TRACE_FORMAT == TRACE_FORMAT_SERIAL
  /* TTT 00 SSS (Type, State) */
  uint8_t byte = TIMEOBJ_CHANGE_STATE<<5 | target_state;
  uint8_t chksum = byte;
  tpl_serial_putchar(byte);

  byte = ts >> 8;
  chksum += byte;
  tpl_serial_putchar(byte);

  byte = ts & 0xff;
  chksum += byte;
  tpl_serial_putchar(byte);

  byte = timeobj_id & 0xff;
  chksum += byte;
  tpl_serial_putchar(byte);

  tpl_serial_putchar(chksum);
# else
#  error "unsupported trace mode: TRACE_FORMAT"
#endif
}

/**
* trace the expiration of an alarm
* ** Function defined in os/tpl_trace.h **
* @param expired_alarm    data structure concerning the expired alarm
*/
FUNC(void, OS_CODE) tpl_trace_time_obj_expire(
    CONST(tpl_timeobj_id,AUTOMATIC) timeobj_id)
{
  const tpl_tick ts=tpl_trace_get_timestamp();
  tpl_trace_start();
# if TRACE_FORMAT == TRACE_FORMAT_SERIAL
  /* TTT 00000 (Type) */
  uint8_t byte = TIMEOBJ_EXPIRE<<5;
  uint8_t chksum = byte;
  tpl_serial_putchar(byte);

  byte = ts >> 8;
  chksum += byte;
  tpl_serial_putchar(byte);

  byte = ts & 0xff;
  chksum += byte;
  tpl_serial_putchar(byte);

  byte = timeobj_id & 0xff;
  chksum += byte;
  tpl_serial_putchar(byte);

  tpl_serial_putchar(chksum);
# else
#  error "unsupported trace mode: TRACE_FORMAT"
#endif
}

/**
* trace the events:
* when an event mask is set to a task (source task is the current running task)
* ** Function defined in os/tpl_trace.h **
*
*/
FUNC(void, OS_CODE) tpl_trace_event_set(
    CONST(tpl_task_id, AUTOMATIC)       task_target_id,
    CONST(tpl_event_mask, AUTOMATIC)    event)
{
  const tpl_tick ts=tpl_trace_get_timestamp();
  tpl_trace_start();
# if TRACE_FORMAT == TRACE_FORMAT_SERIAL
  /* TTT EEEEE (Type, Event) */
  uint8_t byte = EVENT_SET<<5 | (event & 0x1F);
  uint8_t chksum = byte;
  tpl_serial_putchar(byte);

  byte = ts >> 8;
  chksum += byte;
  tpl_serial_putchar(byte);

  byte = ts & 0xff;
  chksum += byte;
  tpl_serial_putchar(byte);

  byte = task_target_id & 0xff;
  chksum += byte;
  tpl_serial_putchar(byte);

  tpl_serial_putchar(chksum);
# else
#  error "unsupported trace mode: TRACE_FORMAT"
#endif
}

/**
* trace the events:
* - when an event mask is reset 
* ** Function defined in os/tpl_trace.h **
*
*/
FUNC(void, OS_CODE) tpl_trace_event_reset(
    CONST(tpl_event_mask, AUTOMATIC)    event)
{
  const tpl_tick ts=tpl_trace_get_timestamp();
  tpl_trace_start();
# if TRACE_FORMAT == TRACE_FORMAT_SERIAL
  /* TTT EEEEE (Type, Event) */
  uint8_t byte = EVENT_RESET<<5 | (event & 0x1F);
  uint8_t chksum = byte;
  tpl_serial_putchar(byte);

  byte = ts >> 8;
  chksum += byte;
  tpl_serial_putchar(byte);

  byte = ts & 0xff;
  chksum += byte;
  tpl_serial_putchar(byte);

  byte = 0;
  chksum += byte;
  tpl_serial_putchar(byte);

  tpl_serial_putchar(chksum);
# else
#  error "unsupported trace mode: TRACE_FORMAT"
#endif
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* WITH_TRACE == YES  */
