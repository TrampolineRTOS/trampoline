/* Interrupt table vector */
#include "tpl_compiler.h"
#include "tpl_os.h"
#include "tpl_os_interrupt_kernel.h"
#include "tpl_machine.h"

/* External handlers */
extern FUNC(void, OS_CODE) tpl_reset_handler(P2CONST(void, OS_APPL_DATA, AUTOMATIC));
extern FUNC(void, OS_CODE) NMI_Handler(P2CONST(void, OS_APPL_DATA, AUTOMATIC));
extern FUNC(void, OS_CODE) HardFault_Handler(P2CONST(void, OS_APPL_DATA, AUTOMATIC));
extern FUNC(void, OS_CODE) MemManage_Handler(P2CONST(void, OS_APPL_DATA, AUTOMATIC));
extern FUNC(void, OS_CODE) BusFault_Handler(P2CONST(void, OS_APPL_DATA, AUTOMATIC));
extern FUNC(void, OS_CODE) UsageFault_Handler(P2CONST(void, OS_APPL_DATA, AUTOMATIC));
extern FUNC(void, OS_CODE) tpl_sc_handler(P2CONST(void, OS_APPL_DATA, AUTOMATIC));
extern FUNC(void, OS_CODE) DebugMonitor_Handler(P2CONST(void, OS_APPL_DATA, AUTOMATIC));
extern FUNC(void, OS_CODE) tpl_primary_irq_handler_SysTick(P2CONST(void, OS_APPL_DATA, AUTOMATIC));

/* Interrupt table vector */

__attribute__ ((section(".isr_vector"))) CONST(tpl_it_handler, AUTOMATIC) tpl_it_vectors[90] = {
  (tpl_it_handler)&_estack,
  (tpl_it_handler)tpl_reset_handler,
  (tpl_it_handler)NMI_Handler,
  (tpl_it_handler)HardFault_Handler,
  (tpl_it_handler)MemManage_Handler,
  (tpl_it_handler)BusFault_Handler,
  (tpl_it_handler)UsageFault_Handler,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_sc_handler,
  (tpl_it_handler)DebugMonitor_Handler,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_primary_irq_handler_SysTick,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it
};

