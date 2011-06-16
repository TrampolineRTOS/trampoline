#ifdef BENCHMARK
#include "tpl_benchmark.h"
#endif


/*
 * Tick for counters. 
 * There is a tick each 1ms for a 40 MHz microcontroller
 * WARNING: It uses *** timer 6 ***
 * This timer MUST NOT be used elsewhere in the application.
 */
#include <C167CS.H> /*TODO: C166 */
void tpl_init_tick_timer()
{
  /* use interrupt mode: 
   * T6IE:1 Interrupt enable
   * ilvl:13 Interrupt Level
   * glvl:1 Group Level
  */
  T6IC = 0x61;
  /* at 40 MHz, resultion max is 100ns.
   * To get 1ms, we need 10 000 ticks.
   * 65536 - 10000 = 55536
   */
  CAPREL = 55536;
  /* T6SR :1 reload with CAPREL
   * T6OTL:0 No toggle latch.
   * T6OE :0 Output Function disabled
   * T6UDE:0 No external Up/Down
   * T6UD :0 Count Up
   * T6R  :1 Run
   * T6M  :0 Timer mode
   * T6I  :0 100ns resolution
   */
  T6CON = 0x8040;
}


#include "tpl_os_kernel.h"          /* tpl_schedule */
#include "tpl_os_timeobj_kernel.h"  /* tpl_counter_tick */
#include "tpl_machine_interface.h"  /* tpl_switch_context_from_it */

void tpl_call_counter_tick()
{
	tpl_status  need_rescheduling = NO_SPECIAL_CODE;
$COUNTER_LIST$

  need_rescheduling |= tpl_counter_tick(&SystemCounter_counter_desc);

  
	if (need_rescheduling == NEED_RESCHEDULING)
  {
    tpl_schedule_from_running();
    if (tpl_kern.need_switch != NO_NEED_SWITCH) {
      tpl_switch_context_from_it(
        &(tpl_kern.s_old->context),
        &(tpl_kern.s_running->context)
      );
    }
  }
}

extern unsigned int registers_it[16]; 

#pragma NOFRAME
#pragma warning disable = 138 /* disables the "expression with possibly no effect" warning */
/* timer 6 -> trap number 38*/
void tpl_timer6_tick(void) interrupt 38
{

	/* Benchmark GF 04/08*/
	#ifdef BENCHMARK
	tpl_benchmark_tick = get_tb();
	#endif

	__asm {
		BCLR IEN /*disable interrupt */
		SCXT DPP3, #3
		NOP
		SCXT CP,#registers_it
		NOP
		MOV R0,0xfe12 
		MOV R0,[R0] //get R0<-CP
		MOV R0,[R0] //get the previous user stack.
		NOP
		PUSH DPP0
	}

	/* We have to call a function, because we can not use any local var here.*/
	tpl_call_counter_tick();
	
	/* dummy code to allow the use of registers_it in
	 * the assembly code
	 */
	if(registers_it[0]);
	__asm {
		POP DPP0
		POP CP
		POP DPP3
	}
}


