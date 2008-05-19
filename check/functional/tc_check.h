/**
 * @file tc_check.h
 *
 * @section desc File description
 *
 * Trampoline check system header
 *
 * @section copyright Copyright
 *
 * Trampoline OpenSource project
 * http://trampoline.rts-software.org
 *
 * Trampoline is copyright (c) IRCCyN 2005+ except for the following parts
 * Copyright ESEO for ARM7 port, function and data structures documentation,
 * timing protection in Autosar extension
 * Copyright Geensys for hcs12 port and v8500 port
 * Copyright IRISA for posix-libpcl port
 * Trampoline is protected by the French intellectual property law.
 *
 * Trampoline check system is distributed under the GPL v2 licence.
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TC_CHECK_H
#define TC_CHECK_H

#include "tpl_os_definitions.h"
#include "tpl_os_types.h"

typedef struct TC_BUF_ENTRY {
    short int   code;
    tpl_status  error;     /* if needed */
} tc_buf_entry;

typedef struct TC_LOC_ENTRY {
    char    *file;
    int     line;
} tc_buf_loc;

/**
 * tc_errorstr returns an error message string according to the
 * error code
 *
 * @param   error   the error code
 * @return  a string pointer
 */
const char *tc_errorstr(tpl_status error);

/**
 * tc_perror prints an error according to the error code. 
 * 
 * @param   error   the error code
 */
void tc_perror(tpl_status error);

/**
 * tc_perror_loc prints an error according to the error code and the location
 * where the error occured. 
 * 
 * @param   error   the error code
 * @param   file    the file where the error occured
 * @param   line    the line where the error occured
 */
void tc_perror_loc(tpl_status error, char *file, int line);

/**
 * tc_init_buffer inits the check internal to prepare a check
 * report. It should be called before calling tc_report
 *
 * @param   buf     a pointer to the report buffer
 * @param   size    the size of the buffer
 */
void tc_init_buffer(
    tc_buf_entry    *w_buf,
    tc_buf_entry    *buf,
    tc_buf_loc      *loc,
    int             size);

/**
 * tc_report adds a test case report to the buffer specified
 * in tc_init_buffer
 *
 * @param   code    code of the test case to report
 */
void tc_report(short int code, char *file, int line);

/**
 * tc_report_error adds a test case report to the buffer specified
 * in tc_init_buffer
 *
 * @param   code    code of the test case to report
 * @param   error   error code.
 */
void tc_report_error(short int code, tpl_status error, char *file, int line);

/**
 * tc_check prints out the result of the test
 *
 * @param   max_count   maximum error message count to be printed. 0 to
 *                      print all error messages.
 */
void tc_check(int max_count);

#endif /* TC_CHECK_H */
