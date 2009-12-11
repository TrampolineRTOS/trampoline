//_____________________________________________
// counter_specific for CM3
// widely inspired from free rtos portmacro.h
//_____________________________________________


/* For backward compatibility, ensure configKERNEL_INTERRUPT_PRIORITY is
defined.  The value should also ensure backward compatibility.
FreeRTOS.org versions prior to V4.4.0 did not include this definition. */
#ifndef configKERNEL_INTERRUPT_PRIORITY
	#define configKERNEL_INTERRUPT_PRIORITY 255
#endif

/* Constants required to manipulate the NVIC. */
#define portNVIC_SYSTICK_CTRL		( ( volatile unsigned portLONG *) 0xe000e010 )
#define portNVIC_SYSTICK_LOAD		( ( volatile unsigned portLONG *) 0xe000e014 )
#define portNVIC_INT_CTRL			( ( volatile unsigned portLONG *) 0xe000ed04 )
#define portNVIC_SYSPRI2			( ( volatile unsigned portLONG *) 0xe000ed20 )
#define portNVIC_SYSTICK_CLK		0x00000004
#define portNVIC_SYSTICK_INT		0x00000002
#define portNVIC_SYSTICK_ENABLE		0x00000001
#define portNVIC_PENDSVSET			0x10000000
#define portNVIC_PENDSV_PRI			( ( ( unsigned portLONG ) configKERNEL_INTERRUPT_PRIORITY ) << 16 )
#define portNVIC_SYSTICK_PRI		( ( ( unsigned portLONG ) configKERNEL_INTERRUPT_PRIORITY ) << 24 )


/* The priority used by the kernel is assigned to a variable to make access
from inline assembler easier. */
const unsigned portLONG ulKernelPriority = configKERNEL_INTERRUPT_PRIORITY;

/*
 * Exception handler.
 */
void SysTick_Handler( void );

void tpl_init_tick_timer()
{
	/* Configure SysTick to interrupt at the requested rate. */
	*(portNVIC_SYSTICK_LOAD) = ( configCPU_CLOCK_HZ / configTICK_RATE_HZ ) - 1UL;
	*(portNVIC_SYSTICK_CTRL) = portNVIC_SYSTICK_CLK | portNVIC_SYSTICK_INT | portNVIC_SYSTICK_ENABLE;

}

void tpl_schedule(int from);

tpl_status tpl_counter_tick(tpl_counter *counter);

void tpl_call_counter_tick()
{
	tpl_status  need_rescheduling = NO_SPECIAL_CODE;
    //need_rescheduling |= tpl_counter_tick(&descriptor_of_counter_General_counter);

	if (need_rescheduling == NEED_RESCHEDULING) {
		tpl_schedule(FROM_IT_LEVEL);
    }
}

// Timer system tick
//___________________

void SysTick_Handler( void )
{

	portDISABLE_INTERRUPTS();	

	tpl_call_counter_tick();

	portENABLE_INTERRUPTS();	

	// return from it using PSP
	__asm__(
		" mov lr, #0xfffffffd ;"
		" bx  lr "
	)	 ;
}
//_______________End of Counter specific code___________________________
