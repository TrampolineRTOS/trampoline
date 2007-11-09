/**
 * @file tpl_os.c
 *
 * @section Copyright
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 *
 * @section File description
 *
 * Here stands services for :
 * - hardware and application initialization
 * - OS startup
 * - OS shutdown
 */

#include "tpl_os.h"
#include "tpl_os_kernel.h"
#include "tpl_os_definitions.h"
#include "tpl_os_hooks.h"
#include "tpl_os_std_types.h"
#include "tpl_machine_interface.h"
#include "tpl_os_application_def.h"

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
#include "tpl_as_timing_protec.h"
#endif

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

_STATIC_ VAR(AppModeType, OS_VAR) application_mode;

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(AppModeType, OS_CODE) GetActiveApplicationMode(void)
{
    return application_mode;
}

/*
 * StartOS can be called by the app to start the OS in
 * an appropriate mode.
 */
FUNC(void, OS_CODE) StartOS(
    CONST(AppModeType, AUTOMATIC) mode
)
{
    application_mode = mode;

    /*  Set the initial state of the OS */
    tpl_os_state = (u8)OS_INIT;

    tpl_init_machine();

    tpl_get_task_lock();

    tpl_init_os(mode);

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    tpl_init_timing_protection ();
#endif

    /*  Call the startup hook. According to the spec, it should be called
        after the os is initialized and before the scheduler is running   */
    CALL_STARTUP_HOOK()

    /*  Call tpl_schedule to elect the greatest priority task
        tpl_schedule also set the state of the OS according to the elected
        task */
    tpl_schedule(FROM_TASK_LEVEL);

    tpl_release_task_lock();

    /*  Fall back to the idle loop */
    tpl_sleep();
}

/*
 * ShutdownOS can be called by the app to shutdown it
 */
void ShutdownOS(
    CONST(StatusType, AUTOMATIC) error  /*@unused@*/
)
{
    CALL_SHUTDOWN_HOOK(error)
    /* architecture dependant shutdown. */
    tpl_shutdown();
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os.c */
