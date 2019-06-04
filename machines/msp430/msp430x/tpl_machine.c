#include "tpl_machine.h"

//function that should be defined for msp430...

FUNC(void, OS_CODE) tpl_init_context(
  CONST(tpl_proc_id, OS_APPL_DATA) proc_id)
{
}

void tpl_disable_interrupts() {}
void tpl_enable_interrupts() {}
void tpl_disable_os_interrupts() {}
void tpl_enable_os_interrupts() {}

void tpl_sc_handler() {}

void idle_function(void)
{
	while(1);
}

void tpl_init_machine() {};
