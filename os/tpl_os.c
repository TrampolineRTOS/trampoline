/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * OS startup
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_os.h"
#include "tpl_os_kernel.h"
#include "tpl_os_definitions.h"
#include "tpl_os_hooks.h"

void tpl_init_machine(void);
void tpl_init_os(void);
void tpl_schedule(int);
void tpl_get_task_lock(void);
void tpl_release_task_lock(void);
void tpl_sleep(void);
void tpl_shutdown(void);

#ifdef WITH_STARTUP_HOOK
void StartupHook(void);
#endif

#ifdef WITH_SHUTDOWN_HOOK
void ShutdownHook(StatusType);
#endif

/*
 * StartOS can be called by the app to put the OS
 * in a different mode
 */
void StartOS(AppModeType mode)
{       
}

/*
 * ShutdownOS can be called by the app to shutdown it
 */
void ShutdownOS(StatusType error)
{
    CALL_SHUTDOWN_HOOK(error)
    /* architecture dependant shutdown.*/
    tpl_shutdown();
}

/*
 * InitApp is provided by the application
 * Tipycally, it calls StartOS() with the
 * appropriate application mode
 */
void InitApp(void);

/*
 * The OS startup is done in main. The application does not
 * provide a main function. Instead it provides a StartOS()
 */
int main(void)
{
    /*  Set the initial state of the OS */
    tpl_os_state = OS_INIT;
    
    tpl_init_machine();
    
    InitApp();
    
    tpl_get_task_lock();

    tpl_init_os();
    
    /*  Call the startup hook. According to the spec, it should be called
        after the os is initialized and before the scheduler is running         */
    CALL_STARTUP_HOOK()
    
    /*  Call tpl_schedule to elect the greatest priority task
        tpl_schedule also set the state of the OS according to the elected task */
    tpl_schedule(FROM_TASK_LEVEL);
    
    tpl_release_task_lock();
    
    /*  Fall back to the idle loop */
    tpl_sleep();
    
    return 0;
}

