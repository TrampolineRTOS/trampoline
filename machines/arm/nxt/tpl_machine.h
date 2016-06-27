/**
 * @file tpl_machine.h
 *
 * @section descr File description
 *
 * Trampoline core exported definitions
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
#ifndef TPL_MACHINE_H
#define TPL_MACHINE_H

#include "../tpl_machine_arm_generic.h"
#include "flash_loader.h" // for nxt_device_init()
#include "display.h"
#include "systick.h"
#include "nxt_lcd.h"
#include "nxt_avr.h"
#include "nxt_spi.h"
#include "udp.h"
#include "uart.h"
#include "i2c.h"
#include "ecrobot_interface.h"
#include "buttons.h"

/**
 * Gives the ARM processor mode the normal user tasks
 * will run into. The value can be :
 * - 0x10 : unprivileged
 * - 0x1F : privileged
 */
#define USER_TASKS_ARM_MODE 0x1F

typedef struct ARM_CONTEXT *tpl_context;

extern struct ARM_CONTEXT idle_task_context;

/* interrupts functions */
extern void systick_isr_C(void);
extern void nxt_motor_isr_C(void);
extern void spi_isr_C(void);
extern void uart_isr_C_0(void);
extern void uart_isr_C_1(void);
extern void sound_isr_C(void);
extern void twi_isr_C(void);
extern void systick_low_priority_C(void);
extern void udp_isr_C(void);
extern void i2c_timer_isr_C(void);

/* TODO : This function is called after an ISR2 has been terminated. It should
 *        restore the hardware's cpu priority if it has been increased before
 *        the execution of the ISR2 (see ppc/multicore/tpl_machine.h for an
 *        example).
 */
#define tpl_restore_cpu_priority()

#endif /* TPL_MACHINE_H */

/* End of file tpl_machine.h */
