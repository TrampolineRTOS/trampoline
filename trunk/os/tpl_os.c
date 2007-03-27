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

static AppModeType application_mode;

AppModeType GetActiveApplicationMode(void)
{
    return application_mode;
}

/*
 * StartOS can be called by the app to start the OS in
 * an appropriate mode.
 */
void StartOS(const AppModeType mode)
{
    application_mode = mode;
    
    /*  Set the initial state of the OS */
    tpl_os_state = (u8)OS_INIT;
    
    tpl_init_machine();
        
    tpl_get_task_lock();

    tpl_init_os(mode);
    
    /*  Call the startup hook. According to the spec, it should be called
        after the os is initialized and before the scheduler is running         */
    CALL_STARTUP_HOOK()
    
    /*  Call tpl_schedule to elect the greatest priority task
        tpl_schedule also set the state of the OS according to the elected task */
    tpl_schedule(FROM_TASK_LEVEL);
    
    tpl_release_task_lock();
    
    /*  Fall back to the idle loop */
    tpl_sleep();
}

/*
 * ShutdownOS can be called by the app to shutdown it
 */
void ShutdownOS(const /*@unused@*/ StatusType error) 
{
    CALL_SHUTDOWN_HOOK(Error)
    /* architecture dependant shutdown. */
    tpl_shutdown();
}

/* End of file tpl_os.c */
