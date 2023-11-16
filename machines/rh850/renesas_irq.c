#include "tpl_os.h"
#include "tpl_os_interrupt_kernel.h" /* tpl_it_handler */

extern CONST(tpl_it_vector_entry, OS_CONST) tpl_it_vector[767]; 

void tpl_eeic_handler ()
{
	VAR(tpl_it_handler, AUTOMATIC) isr_vector;
	VAR(u32, AUTOMATIC) source;
	
	/* get interrupt id */
	source = __stsr_rh(13, 0) & 0xfff; /* EIIC */

	/* launch interrupt function (ISR2, timer...) */
	isr_vector = tpl_it_vector[source].func;
	isr_vector(tpl_it_vector[source].args);
}
