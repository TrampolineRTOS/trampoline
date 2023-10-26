/**
 * @file tpl_trace.c
 *
 * @section desc File description
 *
 * Functions for trace production
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
*/

/* should be defined before including tpl_app_define.h */
#define TRACE_FORMAT_SERIAL   0

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
* Overflow. there are too many trace messages and the trace subsystem
* cannot handle all this stuff.
* we just flush the fifo and send a trace overflow message. There will
* be lost trace messages.
* NOTE: ***** the system should be able to send 5 bytes at minimum *****
* (the TX serial line fifo should be > 5 bytes).
*
*/
FUNC(void, OS_CODE) tpl_trace_overflow()
{
  const tpl_tick ts=tpl_trace_get_timestamp();
  tpl_trace_start();
#  if TRACE_FORMAT == TRACE_FORMAT_SERIAL
  //there was an overflow, first flush the serial line
  //we do not generate any overflow here of course
  //to prevent recursive calls.
  //
  tpl_serial_tx_fifo_discard();
  /* TTT 00000 (Type) */
  uint8_t byte = OVERFLOW << 5;
  uint8_t chksum = byte;
  tpl_serial_putchar(byte);

  byte = ts >> 8;
  chksum += byte;
  tpl_serial_putchar(byte);

  byte = ts & 0xff;
  chksum += byte;
  tpl_serial_putchar(byte);
  
  tpl_serial_putchar(0); //no data
  tpl_serial_putchar(chksum);
#  else
#    error "unsupported trace mode: TRACE_FORMAT"
#  endif /* TRACE_FORMAT == TRACE_FORMAT_SERIAL */
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
  uint8_t byte = PROC_TYPE<<5 | target_state;
  uint8_t chksum = byte;
  int overflow = 0;
  overflow |= tpl_serial_putchar(byte);

  byte = ts >> 8;
  chksum += byte;
  overflow |= tpl_serial_putchar(byte);

  byte = ts & 0xff;
  chksum += byte;
  overflow |= tpl_serial_putchar(byte);

  byte = proc_id & 0xff;
  chksum += byte;
  overflow |= tpl_serial_putchar(byte);

  overflow |= tpl_serial_putchar(chksum);
  if(overflow) tpl_trace_overflow();
# else
#  error "unsupported trace mode: TRACE_FORMAT"
#endif
}

/**
* trace the lock of a resource by an entity
* ** Function defined in os/tpl_trace.h **
* @param res_id       identifier of the locked resource
* @param target_state new state of the resource (RESOURCE_FREE / RESOURCE_TAKEN)
*/
FUNC(void, OS_CODE) tpl_trace_res_change_state(
    CONST(tpl_resource_id, AUTOMATIC)   res_id,
    CONST(tpl_trace_resource_state,AUTOMATIC) target_state)
{
  const tpl_tick ts=tpl_trace_get_timestamp();
  tpl_trace_start();
# if TRACE_FORMAT == TRACE_FORMAT_SERIAL
  /* TTT 00 00S (Type, State) */
  uint8_t byte = (RES_TYPE<<5) | (target_state & 1);
  uint8_t chksum = byte;
  int overflow = 0;
  overflow |= tpl_serial_putchar(byte);

  byte = ts >> 8;
  chksum += byte;
  overflow |= tpl_serial_putchar(byte);

  byte = ts & 0xff;
  chksum += byte;
  overflow |= tpl_serial_putchar(byte);

  byte = res_id & 0xff;
  chksum += byte;
  overflow |= tpl_serial_putchar(byte);

  overflow |= tpl_serial_putchar(chksum);
  if(overflow) tpl_trace_overflow();
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
  /* TTT K0 SSS (Type, Kind, State) */
  uint8_t byte = TIMEOBJ_TYPE<<5 | TIMEOBJ_CHANGE_STATE_KIND <<4 | target_state;
  uint8_t chksum = byte;
  int overflow = 0;
  overflow |= tpl_serial_putchar(byte);

  byte = ts >> 8;
  chksum += byte;
  overflow |= tpl_serial_putchar(byte);

  byte = ts & 0xff;
  chksum += byte;
  overflow |= tpl_serial_putchar(byte);

  byte = timeobj_id & 0xff;
  chksum += byte;
  overflow |= tpl_serial_putchar(byte);

  overflow |= tpl_serial_putchar(chksum);
  if(overflow) tpl_trace_overflow();
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
  /* TTT K0000 (Type, Kind) */
  uint8_t byte = TIMEOBJ_TYPE<<5 | TIMEOBJ_EXPIRE_KIND <<4;
  uint8_t chksum = byte;
  int overflow = 0;
  overflow |= tpl_serial_putchar(byte);

  byte = ts >> 8;
  chksum += byte;
  overflow |= tpl_serial_putchar(byte);

  byte = ts & 0xff;
  chksum += byte;
  overflow |= tpl_serial_putchar(byte);

  byte = timeobj_id & 0xff;
  chksum += byte;
  overflow |= tpl_serial_putchar(byte);

  overflow |= tpl_serial_putchar(chksum);
  if(overflow) tpl_trace_overflow();
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
  uint8_t byte = EVENT_TYPE<<5 | (event & 0x1F);
  uint8_t chksum = byte;
  int overflow = 0;
  overflow |= tpl_serial_putchar(byte);

  byte = ts >> 8;
  chksum += byte;
  overflow |= tpl_serial_putchar(byte);

  byte = ts & 0xff;
  chksum += byte;
  overflow |= tpl_serial_putchar(byte);

  //TODO: limited to 128 tasks
  byte = (EVENT_SET_KIND << 7) | (task_target_id & 0x7f); 
  chksum += byte;
  overflow |= tpl_serial_putchar(byte);

  overflow |= tpl_serial_putchar(chksum);
  if(overflow) tpl_trace_overflow();
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
  uint8_t byte = EVENT_TYPE<<5 | (event & 0x1F);
  uint8_t chksum = byte;
  int overflow = 0;
  overflow |= tpl_serial_putchar(byte);

  byte = ts >> 8;
  chksum += byte;
  overflow |= tpl_serial_putchar(byte);

  byte = ts & 0xff;
  chksum += byte;
  overflow |= tpl_serial_putchar(byte);

  byte = EVENT_RESET_KIND << 7; 
  chksum += byte;
  overflow |= tpl_serial_putchar(byte);

  overflow |= tpl_serial_putchar(chksum);
  if(overflow) tpl_trace_overflow();
# else
#  error "unsupported trace mode: TRACE_FORMAT"
#endif
}

/**
* trace the COM message:
* - when a message is sent
*
*/
#if WITH_COM == YES
FUNC(void, OS_CODE) tpl_trace_msg_send(
    CONST(tpl_message_id, AUTOMATIC)   mess_id,
    CONST(tpl_bool,AUTOMATIC)          is_zero_message)
{
  const tpl_tick ts=tpl_trace_get_timestamp();
  tpl_trace_start();
#  if TRACE_FORMAT == TRACE_FORMAT_SERIAL
  /* TTT MMMMM (Type, Message) */
  uint8_t byte = MESSAGE_TYPE << 5 | (mess_id & 0x1F);
  uint8_t chksum = byte;
  int overflow = 0;
  overflow |= tpl_serial_putchar(byte);

  byte = ts >> 8;
  chksum += byte;
  overflow |= tpl_serial_putchar(byte);

  byte = ts & 0xff;
  chksum += byte;
  overflow |= tpl_serial_putchar(byte);
  
  byte = (uint8_t)is_zero_message; 
  chksum += byte;
  overflow |= tpl_serial_putchar(byte);

  overflow |= tpl_serial_putchar(chksum);
  if(overflow) tpl_trace_overflow();
#  else
#    error "unsupported trace mode: TRACE_FORMAT"
#  endif /* TRACE_FORMAT == TRACE_FORMAT_SERIAL */
}
/**
* trace the message:
* - when a message is received 
*
*/
FUNC(void, OS_CODE) tpl_trace_msg_receive(
    VAR(tpl_message_id, AUTOMATIC) mess_id)
{
  const tpl_tick ts=tpl_trace_get_timestamp();
  tpl_trace_start();
#  if TRACE_FORMAT == TRACE_FORMAT_SERIAL
  /* TTT MMMMM (Type, Message) */
  uint8_t byte = MESSAGE_TYPE << 5 | (mess_id & 0x1F);
  uint8_t chksum = byte;
  int overflow = 0;
  overflow |= tpl_serial_putchar(byte);

  byte = ts >> 8;
  chksum += byte;
  overflow |= tpl_serial_putchar(byte);

  byte = ts & 0xff;
  chksum += byte;
  overflow |= tpl_serial_putchar(byte);
  
  byte = (uint8_t)MESSAGE_RECEIVE_KIND;
  chksum += byte;
  overflow |= tpl_serial_putchar(byte);

  overflow |= tpl_serial_putchar(chksum);
  if(overflow) tpl_trace_overflow();
#  else
#    error "unsupported trace mode: TRACE_FORMAT"
#  endif /* TRACE_FORMAT == TRACE_FORMAT_SERIAL */
}
#endif /* WITH_COM == YES */


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* WITH_TRACE == YES  */
