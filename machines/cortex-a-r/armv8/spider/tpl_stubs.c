/**
 * @file tpl_stubs.c
 *
 * @section descr File description
 *
 * Spider platform specific routines and variables
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation and ARM port
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */
#include "tpl_machine.h"
#include "tpl_machine_arm.h"
#include "tpl_machine_interface.h"
#include "tpl_os_definitions.h"
#include "tpl_os_kernel.h"

#include "emblib.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

extern uint32 vectors;

/* GICD */
#define GICD_CTLR          (0xf0000000)
#define GICD_TYPER         (0xf0000004)
#define GICD_IGROUPR       (0xf0000080)
#define GICD_ICENABLER     (0xf0000180)
#define GICD_ICPENDR       (0xf0000280)
#define GICD_ICFGR         (0xf0000c00)

/* GICR */
#define GICR_CTLR          (0xf0100000)
#define GICR_WAKER         (0xf0100014)
#define GICR_IGROUPR0      (0xf0110080)
#define GICR_ICENABLER0    (0xf0110180)
#define GICR_ICPENDR0      (0xf0110280)

FUNC(void, OS_CODE) wait_rwp(void) {

	/* Wait for rwp cleared */
	while (readFromAddress(GICD_CTLR) & 0x80000000)
        ;

}

FUNC(void, OS_CODE) wait_uwp(void) {

	/* Wait for uwp cleared */
	while (readFromAddress(GICR_CTLR) & 0x80000000)
        ;

}

FUNC(void, OS_CODE) init_irq(void) {

    __asm__ volatile ("CPSID IF"); /* Disable interrupts */

    uint16 nb_int_reg = (readFromAddress(GICD_TYPER) & 0x1f) + 1; /* GICD_TYPER.ITLinesNumber */
    writeToAddress(GICD_CTLR, 0x0); /* Disable interrupts distribution to CPU */
    wait_rwp();

    /* Starting from 1, because first 32 interrupts are located in an other bank of registers */
    for(uint8 int_id = 1; int_id < nb_int_reg; int_id++) {
        writeToAddress(GICD_ICENABLER + int_id * 4, 0xffffffff); /* Disable interrupts */
        writeToAddress(GICD_ICPENDR + int_id * 4, 0xffffffff); /* Clear pending interrupts */
        writeToAddress(GICD_IGROUPR + int_id * 4, 0xffffffff); /* Use group 1 for all interrupts */

        writeToAddress(GICD_ICFGR + int_id * 8, 0x0); /* Set interrupts as level sensitive */
        writeToAddress(GICD_ICFGR + int_id * 8 + 4, 0x0);
    }
    wait_rwp();

    writeToAddress(GICR_WAKER, 0x4); /* Set CPU as awake */

    writeToAddress(GICR_ICENABLER0, 0xffffffff); /* Disable forwarding int to cpu */
    writeToAddress(GICR_ICPENDR0, 0xffffffff); /* Clear pending interrupts */
    writeToAddress(GICR_IGROUPR0, 0xffffffff); /* Use group1=IRQ (group0=FIQ) */
    wait_uwp();

    writeToAddress(GICD_CTLR, 0x2); /* Enable interrupts distribution to CPU */
    wait_rwp();

    cp15_write32(0, 4, 6, 0, 0xff); /* Write 0xff to ICC_PMR_EL1: allow all priority levels */

    cp15_write32(0, 12, 12, 6, 1); /* Write 1 to ICC_IGRPEN0 */
    cp15_write32(0, 12, 12, 7, 1); /* Write 1 to ICC_IGRPEN1 */

    __asm__ volatile ("CPSIE IF"); /* Enable interrupts */
}

FUNC(void, OS_CODE) tpl_init_machine(void)
{
    cp15_write32(0, 12, 0, 0, &vectors);  /* write VBAR */

    init_irq();

    tpl_init_machine_generic ();

}

FUNC(void, OS_CODE) tpl_shutdown(void)
{
    /* FIXME: this is does not conform to AUTOSAR OS specifications,
     * should return to main with initial context */
    DISABLE_FIQ ();
    DISABLE_IRQ ();

    while (1);
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
