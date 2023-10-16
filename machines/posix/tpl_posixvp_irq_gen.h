/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) CNRS,
 * University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
 * Trampoline posix machine irq generator
 *
 */

#ifndef tpl_posixvp_h
#define tpl_posixvp_h

#include <stdint.h>

extern void tpl_posixvp_irq_gen_init(void);

void set_leds(uint8_t led);

void reset_leds(uint8_t led);

#define RED 0x1
#define GREEN 0x2
#define BLUE 0x4
#define YELLOW 0x8

#endif
