/**
 * @file tpl_machine_spider.c
 *
 * @section descr File description
 *
 * Trampoline processor dependant functions.
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de Nantes
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

#include "tpl_compiler.h"
#include "tpl_os_std_types.h"
#include "tpl_machine.h"
#include "emblib.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

#define CNTV_CTL_ENABLE   1
#define CNTV_CTL_IMASK    2

#define CPU_CLOCK (1060*1000*1000) // 1060 MHz
#define NB_TICK	((uint64)(CPU_CLOCK/64) / (uint64)100) // systick 100 times per seconds (every 10ms)

#define GICR_ISENABLER0     (0xf0110100)
#define GICR_ICPENDR0       (0xf0110280)

inline uint32 __attribute__((always_inline)) CNTV_CTL_read(void) {
    uint32 val;
    cp15_read32(0, 14, 3, 1, val);
    return val;
}

inline void __attribute__((always_inline)) CNTV_CTL_write(uint32 val) {
    cp15_write32(0, 14, 3, 1, val);
}

inline uint64 __attribute__((always_inline)) CNTV_CVAL_read(void) {
    uint32 val;
    cp15_read64(3, 14, val);
    return val;
}

inline void __attribute__((always_inline)) CNTV_CVAL_write(uint64 val) {
    cp15_write64(3, 14, val);
}

inline uint64 __attribute__((always_inline)) CNTVCT_read(void) {
    uint64 val;
    cp15_read64(1, 14, val);
    return val;
}

inline void __attribute__((always_inline))
enable_systick_timer(unsigned char enable) {

	uint64 cntv_ctl;

	cntv_ctl = CNTV_CTL_read();

	if (enable) {
		cntv_ctl |= CNTV_CTL_ENABLE;
	} else {
		cntv_ctl &= ~CNTV_CTL_ENABLE;
	}

	CNTV_CTL_write(cntv_ctl);
}

inline uint64 __attribute__((always_inline))
get_systick_timer() {

	return CNTVCT_read();

}

//interrupt id #27
FUNC(void, OS_CODE) tpl_set_systick_timer(void) {

    enable_systick_timer(0);

    CNTV_CVAL_write(get_systick_timer() + NB_TICK); // can set CNTV_TVAL

    enable_systick_timer(1);

    /* Enable forwarding int to cpu */
    writeToAddress(GICR_ISENABLER0, 0x08000000);

    /* Unmask interrupt */
    CNTV_CTL_write(CNTV_CTL_read() & ~CNTV_CTL_IMASK);
}

FUNC(void, OS_CODE) ARM_TIMER_ClearFlag(void) {
	/*
	 * Clear the ARM Timer interrupt
	 */
    CNTV_CVAL_write(get_systick_timer() + NB_TICK);
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
