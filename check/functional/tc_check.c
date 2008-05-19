/**
 * @file tc_check.c
 *
 * @section desc File description
 *
 * Trampoline check system implementation
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
 
#include "tc_check.h"
#include <stdio.h>

#define ERROR_MESSAGE_COUNT 9
#define TC_BUFFER_TOO_SMALL 0x7FFF;

static const char *errorstring[] = {
    "E_OK",
    "E_OS_ACCESS",
    "E_OS_CALLEVEL",
    "E_OS_ID",
    "E_OS_LIMIT",
    "E_OS_NOFUNC",
    "E_OS_RESOURCE",
    "E_OS_STATE",
    "E_OS_VALUE"
};

static int tc_buf_size;
static int tc_buf_idx;
static tc_buf_entry *tc_buf; 
static tc_buf_loc   *tc_loc; 
static tc_buf_entry *tc_w_buf; 

/*
 * tc_errorstr returns an error message string according to the
 * error code
 */
const char *tc_errorstr(tpl_status error)
{
    if (error < ERROR_MESSAGE_COUNT) {
        return errorstring[error];
    }
    else {
        return "Unkown error";
    }
}

/*
 * tc_perror prints an error according to the error code. 
 */
void tc_perror(tpl_status error)
{
    printf("Error: %s\n",tc_errorstr(error));
}

/*
 * tc_perror_loc prints an error according to the error code and the location
 * where the error occured. 
 */
void tc_perror_loc(tpl_status error, char *file, int line)
{
    printf("Error in %s:%d: %s\n",file,line,tc_errorstr(error));
}

/*
 * tc_init_buffer inits the check internal to prepare a check
 * report. It should be called before calling tc_report
 */
void tc_init_buffer(
    tc_buf_entry    *w_buf,
    tc_buf_entry    *buf,
    tc_buf_loc      *loc,
    int             size)
{
    int i;
    
    tc_w_buf = w_buf;
    tc_buf = buf;
    tc_loc = loc;
    tc_buf_size = size;
    tc_buf_idx = 0;
    
    for (i = 0; i < size; i++)
    {
        tc_buf[i].error = E_OK;
    }
}

/*
 * tc_report adds a test case report to the buffer specified
 * in tc_init_buffer
 */
void tc_report(short int code, char *file, int line)
{
    if (tc_buf_idx < (tc_buf_size - 1))
    {
        tc_buf[tc_buf_idx].code = code;
        tc_loc[tc_buf_idx].file = file;
        tc_loc[tc_buf_idx].line = line;
        tc_buf_idx++;
    }
    else
    {
        tc_buf[tc_buf_size - 1].code = TC_BUFFER_TOO_SMALL;
    };
}

/*
 * tc_report_error adds a test case report to the buffer specified
 * in tc_init_buffer
 */
void tc_report_error(short int code, tpl_status error, char *file, int line)
{
    if (tc_buf_idx < (tc_buf_size - 1))
    {
        tc_buf[tc_buf_idx].code = code;
        tc_buf[tc_buf_idx].error = error;
        tc_loc[tc_buf_idx].file = file;
        tc_loc[tc_buf_idx].line = line;
        tc_buf_idx++;
    }
    else
    {
        tc_buf[tc_buf_size - 1].code = TC_BUFFER_TOO_SMALL;
    };
}

/*
 * tc_check compares the awaited result and the generated result
 * It should be called at the end of the test
 */
void tc_check(int max_count)
{
    int i;
    int error_count = 0;
    
    for (i = 0; i < tc_buf_idx; i++)
    {
        if ((tc_buf[i].code != tc_w_buf[i].code) ||
            (tc_buf[i].error != tc_w_buf[i].error))
        {
            error_count++;
            if ((max_count == 0) || (error_count <= max_count))
            {
                printf("[%d] Error (%s:%d): waiting[code %d, error %s] got[code %d, error %s] \n",
                        i,
                        tc_loc[i].file,
                        tc_loc[i].line,
                        tc_w_buf[i].code,
                        tc_errorstr(tc_w_buf[i].error),
                        tc_buf[i].code,
                        tc_errorstr(tc_buf[i].error));
            }
        }
    }
    if ((max_count != 0) && (error_count > max_count)) {
        printf("%d error(s) skipped\n",error_count - max_count);
    }
    if (error_count > 0)
    {
        printf("Test failed!\n");
    }
    else
    {
        printf("Test passed\n");
    }
}