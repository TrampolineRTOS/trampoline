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
#define TRACE_FILENAME "trace.json"

#define TRACE_FORMAT_JSON 1
#define TRACE_FORMAT_BIN 2

#include "tpl_app_define.h" /* WITH_TRACE */

#if WITH_TRACE == YES
#include <stdio.h>
#include <stdlib.h> /* exit */

#include "tpl_trace.h"

#define OS_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "tpl_memmap.h"

FILE *trace_file = NULL;

#define OS_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(tpl_tick, OS_CODE) tpl_trace_get_timestamp()
{
#if (WITH_AUTOSAR == YES)
  extern CONSTP2VAR(tpl_counter, OS_VAR, OS_APPL_DATA) tpl_counter_table;
  CONSTP2VAR(tpl_counter, AUTOMATIC, OS_APPL_DATA) counter = tpl_counter_table;
#else
  CONSTP2VAR(tpl_counter, AUTOMATIC, OS_APPL_DATA)
  counter = &SystemCounter_counter_desc;
#endif
  tpl_tick timestamp = counter->current_date;
  return timestamp;
}

/* return 1 when the file is opened (first time)*/
FUNC(uint8, OS_CODE) tpl_trace_start()
{
  uint8 first = 0;
  if (trace_file == NULL)
  {
    // first time run (open file in write mode)
    trace_file = fopen(TRACE_FILENAME, "w");
    if (trace_file == NULL)
    {
      perror("[trace] unable to open trace file");
      exit(1);
    }
    first = 1;
#if TRACE_FORMAT == TRACE_FORMAT_JSON
    fprintf(trace_file, "[\n");
#endif
  }
  return first;
}

/**
 * Trace ends (close the file for instance). This event is sent by
 * ShutdownOS() system call
 * This function should be implemented in the machine dependant trace backend.
 */
FUNC(void, OS_CODE) tpl_trace_close()
{
#if TRACE_FORMAT == TRACE_FORMAT_JSON
  fprintf(trace_file, "]\n");
#endif
  if (trace_file)
    fclose(trace_file);
}

/**
 * trace the execution of a task or ISR
 * ** Function defined in os/tpl_trace.h **
 *
 */
FUNC(void, OS_CODE)
tpl_trace_proc_change_state(CONST(tpl_proc_id, AUTOMATIC) proc_id,
                            CONST(tpl_proc_state, AUTOMATIC) target_state)
{
  const uint8 first = tpl_trace_start();
  const tpl_tick ts = tpl_trace_get_timestamp();
#if TRACE_FORMAT == TRACE_FORMAT_JSON
  if (!first)
    fprintf(trace_file, ",");
  fprintf(trace_file,
          "\n\t{\n"
          "\t\t\"type\":\"proc\",\n"
          "\t\t\"ts\":\"%u\",\n"
          "\t\t\"proc_id\":\"%d\",\n"
          "\t\t\"target_state\":\"%d\"\n"
          "\t}",
          ts, proc_id, target_state);
#else
#error "unsupported trace mode: TRACE_FORMAT"
#endif
}

/**
 * trace the lock of a resource by an entity
 * ** Function defined in os/tpl_trace.h **
 * @param res_id       identifier of the locked resource
 * @param target_state identifier of the locked resource
 */
FUNC(void, OS_CODE)
tpl_trace_res_change_state(CONST(tpl_resource_id, AUTOMATIC) res_id,
                           CONST(tpl_trace_resource_state, AUTOMATIC)
                               target_state)
{
  const uint8 first = tpl_trace_start();
  const tpl_tick ts = tpl_trace_get_timestamp();
#if TRACE_FORMAT == TRACE_FORMAT_JSON
  if (!first)
    fprintf(trace_file, ",");
  fprintf(trace_file,
          "\n\t{\n"
          "\t\t\"type\":\"resource\",\n"
          "\t\t\"ts\":\"%u\",\n"
          "\t\t\"res_id\":\"%d\",\n"
          "\t\t\"target_state\":\"%d\"\n"
          "\t}",
          ts, res_id, target_state);
#else
#error "unsupported trace mode: TRACE_FORMAT"
#endif
}

/**
 * trace the state of a time object (alarm/schedule tables)
 * ** Function defined in os/tpl_trace.h **
 * @param sheduled_alarm    data structure concerning the sheduled alarm
 */
FUNC(void, OS_CODE)
tpl_trace_time_obj_change_state(CONST(tpl_timeobj_id, AUTOMATIC) timeobj_id,
                                CONST(tpl_time_obj_state, AUTOMATIC)
                                    target_state)
{
  const uint8 first = tpl_trace_start();
  const tpl_tick ts = tpl_trace_get_timestamp();
#if TRACE_FORMAT == TRACE_FORMAT_JSON
  if (!first)
    fprintf(trace_file, ",");
  fprintf(trace_file,
          "\n\t{\n"
          "\t\t\"type\":\"timeobj\",\n"
          "\t\t\"ts\":\"%u\",\n"
          "\t\t\"timeobj_id\":\"%d\",\n"
          "\t\t\"target_state\":\"%d\"\n"
          "\t}",
          ts, timeobj_id, target_state);
#else
#error "unsupported trace mode: TRACE_FORMAT"
#endif
}

/**
 * trace the expiration of an alarm
 * ** Function defined in os/tpl_trace.h **
 * @param expired_alarm    data structure concerning the expired alarm
 */
FUNC(void, OS_CODE)
tpl_trace_time_obj_expire(CONST(tpl_timeobj_id, AUTOMATIC) timeobj_id)
{
  const uint8 first = tpl_trace_start();
  const tpl_tick ts = tpl_trace_get_timestamp();
#if TRACE_FORMAT == TRACE_FORMAT_JSON
  if (!first)
    fprintf(trace_file, ",");
  fprintf(trace_file,
          "\n\t{\n"
          "\t\t\"type\":\"timeobj_expire\",\n"
          "\t\t\"ts\":\"%u\",\n"
          "\t\t\"timeobj_id\":\"%d\"\n"
          "\t}",
          ts, timeobj_id);
#else
#error "unsupported trace mode: TRACE_FORMAT"
#endif
}

/**
 * trace the events:
 * when an event mask is set to a task (source task is the current running task)
 * ** Function defined in os/tpl_trace.h **
 *
 */
FUNC(void, OS_CODE)
tpl_trace_event_set(CONST(tpl_task_id, AUTOMATIC) task_target_id,
                    CONST(tpl_event_mask, AUTOMATIC) event)
{
  const uint8 first = tpl_trace_start();
  const tpl_tick ts = tpl_trace_get_timestamp();
#if TRACE_FORMAT == TRACE_FORMAT_JSON
  if (!first)
    fprintf(trace_file, ",");
  fprintf(trace_file,
          "\n\t{\n"
          "\t\t\"type\":\"set_event\",\n"
          "\t\t\"ts\":\"%u\",\n"
          "\t\t\"target_task_id\":\"%d\",\n"
          "\t\t\"event\":\"%d\"\n"
          "\t}",
          ts, task_target_id, event);
#else
#error "unsupported trace mode: TRACE_FORMAT"
#endif
}

/**
 * trace the events:
 * - when an event mask is reset
 * ** Function defined in os/tpl_trace.h **
 *
 */
FUNC(void, OS_CODE)
tpl_trace_event_reset(CONST(tpl_event_mask, AUTOMATIC) event)
{
  const uint8 first = tpl_trace_start();
  const tpl_tick ts = tpl_trace_get_timestamp();
#if TRACE_FORMAT == TRACE_FORMAT_JSON
  if (!first)
    fprintf(trace_file, ",");
  fprintf(trace_file,
          "\n\t{\n"
          "\t\t\"type\":\"reset_event\",\n"
          "\t\t\"ts\":\"%u\",\n"
          "\t\t\"event\":\"%d\"\n"
          "\t}",
          ts, event);
#else
#error "unsupported trace mode: TRACE_FORMAT"
#endif
}

//----------------------------------------------------
/**
 * trace the ioc:
 * - when an ioc message is sent
 *
 */
#if (WITH_IOC == YES)
FUNC(void, OS_CODE) tpl_trace_ioc_send(VAR(tpl_ioc_id, AUTOMATIC) ioc_id)
{
  const uint8 first = tpl_trace_start();
  const tpl_tick ts = tpl_trace_get_timestamp();
#if TRACE_FORMAT == TRACE_FORMAT_JSON
  if (!first)
    fprintf(trace_file, ",");
  fprintf(trace_file,
          "\n\t{\n"
          "\t\t\"type\":\"ioc\",\n"
          "\t\t\"kind\":\"send\",\n"
          "\t\t\"ts\":\"%u\",\n"
          "\t\t\"ioc_id\":\"%d\"\n"
          "\t}",
          ts, ioc_id);
#else
#error "unsupported trace mode: TRACE_FORMAT"
#endif /* TRACE_FORMAT == TRACE_FORMAT_JSON */
}
/**
 * trace the ioc:
 * - when a ioc message is received
 *
 */
FUNC(void, OS_CODE) tpl_trace_ioc_receive(VAR(tpl_ioc_id, AUTOMATIC) ioc_id)
{
  const uint8 first = tpl_trace_start();
  const tpl_tick ts = tpl_trace_get_timestamp();
#if TRACE_FORMAT == TRACE_FORMAT_JSON
  if (!first)
    fprintf(trace_file, ",");
  fprintf(trace_file,
          "\n\t{\n"
          "\t\t\"type\":\"ioc\",\n"
          "\t\t\"kind\":\"receive\",\n"
          "\t\t\"ts\":\"%u\",\n"
          "\t\t\"ioc_id\":\"%d\"\n"
          "\t}",
          ts, ioc_id);
#else
#error "unsupported trace mode: TRACE_FORMAT"
#endif /* TRACE_FORMAT == TRACE_FORMAT_JSON */
}
#endif /*WITH_IOC == YES*/

//-----------------------------------------------------
/**
 * trace the message:
 * - when a message is sent
 *
 */
#if WITH_COM == YES
FUNC(void, OS_CODE)
tpl_trace_msg_send(CONST(tpl_message_id, AUTOMATIC) mess_id,
                   CONST(tpl_bool, AUTOMATIC) is_zero_message)
{
  const uint8 first = tpl_trace_start();
  const tpl_tick ts = tpl_trace_get_timestamp();
#if TRACE_FORMAT == TRACE_FORMAT_JSON
  if (!first)
    fprintf(trace_file, ",");
  if (is_zero_message == SEND_ZERO_MESSAGE)
  {
    fprintf(trace_file,
            "\n\t{\n"
            "\t\t\"type\":\"message\",\n"
            "\t\t\"kind\":\"send_zero_msg\",\n"
            "\t\t\"ts\":\"%u\",\n"
            "\t\t\"msg_id\":\"%d\"\n"
            "\t}",
            ts, mess_id);
  }
  else
  {
    fprintf(trace_file,
            "\n\t{\n"
            "\t\t\"type\":\"message\",\n"
            "\t\t\"kind\":\"send_msg\",\n"
            "\t\t\"ts\":\"%u\",\n"
            "\t\t\"msg_id\":\"%d\"\n"
            "\t}",
            ts, mess_id);
  }

#else
#error "unsupported trace mode: TRACE_FORMAT"
#endif /* TRACE_FORMAT == TRACE_FORMAT_JSON */
}
/**
 * trace the message:
 * - when a message is received
 *
 */
FUNC(void, OS_CODE)
tpl_trace_msg_receive(VAR(tpl_message_id, AUTOMATIC) mess_id)
{
  const uint8 first = tpl_trace_start();
  const tpl_tick ts = tpl_trace_get_timestamp();
#if TRACE_FORMAT == TRACE_FORMAT_JSON
  if (!first)
    fprintf(trace_file, ",");
  fprintf(trace_file,
          "\n\t{\n"
          "\t\t\"type\":\"message\",\n"
          "\t\t\"kind\":\"receive_msg\",\n"
          "\t\t\"ts\":\"%u\",\n"
          "\t\t\"msg_id\":\"%d\"\n"
          "\t}",
          ts, mess_id);
#else
#error "unsupported trace mode: TRACE_FORMAT"
#endif /* TRACE_FORMAT == TRACE_FORMAT_JSON */
}
#endif /* WITH_TRACE == YES */

//----------------------------------------------------
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* WITH_TRACE == YES  */
