/**
 * @file tpl_multicore_rp2040.c
 *
 * @section descr File description
 *
 * Multicore kernel functions for rp2040
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes,
 * Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "pico/multicore.h"
#include "tpl_os_internal_types.h"
#include "tpl_machine_interface.h"
#include "tpl_cortex_definitions.h"
#include "tpl_os_interrupt_kernel.h"

#if NUMBER_OF_CORES > 1


extern CONST(tpl_it_handler, OS_CONST) tpl_it_vectors[41];
extern FUNC(int, OS_APPL_CODE) tpl_multicore_boot_handler(void);
extern FUNC(void, OS_CODE) tpl_primary_irq_handler_SysTick2(void);
extern uint32_t __core1_stack_start__[];
extern uint32_t _Core1_Stack_Size;


__attribute__((aligned(256))) tpl_it_handler tpl_it_vectors_core1[41];
#define tpl_core1_stack       (__core1_stack_start__)
#define tpl_core1_stack_size  ((uint32_t)&_Core1_Stack_Size)
#define tpl_RP2040_SPINLOCK_OFFSET 14
#define tpl_RP2040_SYNC_SPINLOCK_OFFSET 15


    /**
     * @internal
     *
     * tpl_get_core_id is used to get the identifier of the core on which the
     * code is running
     */
FUNC(uint32, OS_CODE) tpl_get_core_id(void)
{
  return sio_hw->cpuid;
}

/**
 * @internal
 *
 * This function starts the processing core given in the argument
 */

FUNC(void, OS_CODE) tpl_start_core(CONST(CoreIdType, AUTOMATIC) core_id)
{
  /*
   * Only CORE1 can be started because it is the only one that does not run when
   * the rp2040 starts.
   */
  if (core_id == OS_CORE_ID_1)
  {
    multicore_launch_core1_with_stack((void (*)(void))tpl_multicore_boot_handler,(uint32_t *)tpl_core1_stack,(uint32_t)tpl_core1_stack_size );
  }
}
FUNC(void, OS_CODE) tpl_get_lock(
  CONSTP2VAR(tpl_lock, AUTOMATIC, OS_VAR) lock){
    while (sio_hw->spinlock[tpl_RP2040_SYNC_SPINLOCK_OFFSET]==0)
    {
    }
  }

FUNC(void, OS_CODE) tpl_release_lock(
  CONSTP2VAR(tpl_lock, AUTOMATIC, OS_VAR) lock){
    sio_hw->spinlock[tpl_RP2040_SYNC_SPINLOCK_OFFSET]=0;
  }

FUNC(void, OS_CODE) tpl_send_intercore_it(
  CONST(CoreIdType, AUTOMATIC) core_id){
    multicore_fifo_push_blocking(0);
  }

FUNC(void, OS_CODE) tpl_init_core(void)
{
  GET_CURRENT_CORE_ID(core_id);
    if(core_id ==0){
    while (multicore_fifo_rvalid())
    {
      (void)multicore_fifo_pop_blocking();
    }
    NVIC_ClearPendingIRQ(15);
    NVIC_EnableIRQ(15);
  }
  if(core_id ==1){
    NVIC_SetPriority(SVCall_IRQn, KERNEL_PRIO_UNSHIFTED);
    while (multicore_fifo_rvalid())
    {
      (void)multicore_fifo_pop_blocking();
    }
    //Remove the interrupt flags generated during boot of core 1
    sio_hw->fifo_st = (1 << 3) | (1 << 2);
    NVIC_ClearPendingIRQ(16);
    NVIC_EnableIRQ(16);
  }
  __set_CONTROL(0x3);
  __ISB();
}
void tpl_ici_ack(void) {
    while (multicore_fifo_rvalid()) {
        (void)multicore_fifo_pop_blocking();
    }
}

void __unhandled_user_irq(void) {
    while (1) {
    }
}

FUNC(void, OS_CODE) tpl_get_task_lock(void){
  while (sio_hw->spinlock[tpl_RP2040_SPINLOCK_OFFSET]==0) {}
}

extern FUNC(void, OS_CODE) tpl_release_task_lock(void){
  sio_hw->spinlock[tpl_RP2040_SPINLOCK_OFFSET]=0;
}


void runtime_run_per_core_initializers(void)
{
}

#endif