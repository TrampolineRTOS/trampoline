/**
 *
 * @file tpl_posix_autosar.c
 *
 * @section descr File description
 *
 * Trampoline machine dependant functions implementation 
 * for AUTOSAR timing protection and stack monitoring on
 * posix platform
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
#include <sys/time.h>
#include <stdio.h>

#include "tpl_os_types.h"
#include "tpl_machine_interface.h"


#if WITH_AUTOSAR_TIMING_PROTECTION == YES

#include "tpl_as_timing_protec.h"

/* Timer used for timing protection
 * TODO use system timer provided by viper?
 */
static struct timeval startup_time;

void tpl_start_tptimer ()
{
    gettimeofday (&startup_time, NULL);  
}

/* Time in tenth of milliseconds since system startup */
FUNC(tpl_time, OS_CODE) tpl_get_tptimer (void)
{
    struct timeval time;
    tpl_time result;

    gettimeofday (&time, NULL);
    result = 
        (time.tv_sec - startup_time.tv_sec) * 100
        + (time.tv_usec - startup_time.tv_usec) / 10000;

    return result;
}

/* Sets a watchdog to expire in tenth of millisec */
FUNC(void, OS_CODE) tpl_set_tpwatchdog (
        CONST(tpl_time, AUTOMATIC) delay)
{
    struct itimerval watchdog;
    tpl_time offset;

    offset = delay;

    /* configure and start the watchdog */
    watchdog.it_interval.tv_sec = 0;
    watchdog.it_interval.tv_usec = 0;
    watchdog.it_value.tv_sec = offset / 100;
    watchdog.it_value.tv_usec = (offset % 100)  * 10000;
    setitimer (ITIMER_REAL, &watchdog, NULL);
}

FUNC(void, OS_CODE) tpl_cancel_tpwatchdog(void)
{
    struct itimerval watchdog;

    watchdog.it_interval.tv_sec = 0;
    watchdog.it_interval.tv_usec = 0;
    watchdog.it_value.tv_sec = 0;
    watchdog.it_value.tv_usec = 0;
    setitimer (ITIMER_REAL, &watchdog, NULL);
}
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */

#if WITH_AUTOSAR_STACK_MONITORING == YES
    FUNC(tpl_bool, OS_CODE) tpl_check_stack_pointer(
            CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
    return 1;
}

    FUNC(tpl_bool, OS_CODE) tpl_check_stack_footprint(
            CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
    return 1;
}
#endif /* WITH_AUTOSAR_STACK_MONITORING */
