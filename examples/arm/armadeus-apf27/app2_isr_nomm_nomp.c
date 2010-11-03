#include "tpl_os.h"
#include "tpl_app_config.h"
#include "apf27_switch.h"
#include "apf27_aitc.h"

FUNC(int, AUTOMATIC) main()
{
		apf27_s1_init ();
		serial_init();
		serial_puts ("bootstrap finished, starting Trampoline...");
		serial_puts (" GO!\n");
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}
FUNC(void, AUTOMATIC) ProtectionHook(StatusType error)
{
}

FUNC(void, AUTOMATIC) ErrorHook(StatusType error)
{
}

DeclareTask (t2);

TASK(t1)
{
	serial_puts ("t1 starts t2\n");
	ActivateTask (t2);
	serial_puts ("t1 will terminate\n");
	TerminateTask();
}

TASK(t4)
{
	serial_puts ("t4 says hello\n");
	apf27_aitc_force_source_int (INT_GPT1);
	TerminateTask ();
}

TASK(t3)
{
	serial_puts ("t3 starts\n");
	serial_puts ("t3 will terminate\n");
	TerminateTask ();
}

TASK(t2)
{
	serial_puts ("t2 starts t3\n");
	ActivateTask (t3);
	serial_puts ("t2 will terminate\n");
	TerminateTask ();
}

TASK(t5)
{
	serial_puts ("t5 starts and ends\n");
	TerminateTask ();
}

ISR(it1)
{
	serial_puts ("it1 came up\n");
	ActivateTask (t5);
	serial_puts ("it1 ends\n");
	apf27_s1_ack_int ();
}

ISR(it2)
{
	serial_puts ("it2 came up\n");
}

