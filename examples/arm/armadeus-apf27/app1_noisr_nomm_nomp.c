#include <stdio.h>
#include "tpl_os.h"
#include "tpl_app_config.h"

CONST(u32, AUTOMATIC ) CONST_TO_WRITE = 0x55;

VAR (int, AUTOMATIC) trace = 0;
VAR(int, AUTOMATIC) var_t1 = 0;

VAR(int, AUTOMATIC) var_t2 = 0;
P2VAR (u32, AUTOMATIC, OS_CODE) write_code; 

VAR(int, AUTOMATIC) var_t3 = 20;
P2VAR (u32, AUTOMATIC, OS_CONST) write_const;

VAR(int, AUTOMATIC) var_t4 = 0;

VAR(int, AUTOMATIC) var_it1 = 0;

VAR(int, AUTOMATIC) var_it2 = 0;

FUNC(int, AUTOMATIC) main()
{
		serial_init();
		serial_puts ("yes, ca marche !!!\r\n");
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}
FUNC(void, AUTOMATIC) ProtectionHook(StatusType error)
{
	trace++;
}

FUNC(void, AUTOMATIC) ErrorHook(StatusType error)
{
}

DeclareTask (t2);

TASK(t1)
{
	u32 *ptr;

	var_t1 = 1;
 	var_t2 = 3; /* Try to write in the task 2 data section's */
	ptr = &CONST_TO_WRITE;
	*ptr = 18;
	ActivateTask (t2);
	TerminateTask();
}

TASK(t4)
{
	TerminateTask ();
}

TASK(t3)
{
	TerminateTask ();
}

TASK(t2)
{
	TerminateTask ();
}

