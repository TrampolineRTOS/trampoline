/**
 * @file tpl_trace_posix.h
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
 * @section infos File informations
 *
 * $Date: 2009-04-24 10:26:01 +0000 (ven. 24 avril 2009) $
 * $Rev: 735 $
 * $Author: ljunker $
 * $URL: http://trampoline.rts-software.org/svn/trunk/os/tpl_trace.c $
 */

/* This file describes proprieties of the posix plateform used for the trace*/

/* System's libraries used*/
#ifndef __TPL_TRACE_POSIX_H__
#define __TPL_TRACE_POSIX_H__

#include "tpl_machine_interface.h"
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>


#if WITH_TRACE == YES

/**
* @def EVENT_BEGIN
*/
#	define EVENT_BEGIN(trace_id)\
	tpl_trace_event_begin(trace_id);

/**
* @def EVENT_VALUE
*/
#	define EVENT_VALUE(value)\
	tpl_trace_value(value);

/**
* @def END_EVENT
*/
#	define EVENT_END()\
	tpl_trace_event_end();

/**
 * @def FORMAT_TRACE
 */
#	define FORMAT_TRACE()\
	  TRACE_FORMAT()

#else
#	define EVENT_BEGIN(trace_id)
#	define EVENT_VALUE(value)
#	define EVENT_END()
#	define FORMAT_TRACE()
#endif

/* Declarations of constants and variables used */

struct STR_TRACE
{
  VAR(char,TYPEDEF) begin_date[20];
  VAR(int,TYPEDEF) trace_type;
  VAR(int,TYPEDEF) value[10];
  VAR(char,TYPEDEF) end_date[20];
};

typedef struct STR_TRACE tpl_str_trace;

extern VAR(tpl_str_trace, OS_CONST) trace;

extern VAR(char,OS_VAR) DATE[20];

extern FILE* TRACE_FILE_PT;

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
* DATE FUNCTION
*/

FUNC(void, OS_CODE)tpl_trace_get_date();

/**
* RECORD FUNCTIONS
*/

/** Function which start the record, memorizing the begin date of the event 
* and the type of event traced 
*/

FUNC(void, OS_CODE)tpl_trace_event_begin(
    VAR(int, OS_VAR) trace_id);

/** Function adding a value to the record. Knowing the event type of the trace, 
* we can retrieve how much value this record must contain. 
*/

FUNC(void, OS_CODE)tpl_trace_value(
  VAR(int, OS_VAR) value);

/* Function ending the record, by adding the end date of the event traced. */

FUNC(void, OS_CODE)tpl_trace_event_end(void);

/* Three functions of format, each one corresponding to a different output format. */

FUNC(void, OS_CODE)tpl_trace_format_txt(void);


FUNC(void, OS_CODE)tpl_trace_format_xml(void);


FUNC(void, OS_CODE)tpl_trace_format_bin(void);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* __TPL_TRACE_POSIX_H__ */
