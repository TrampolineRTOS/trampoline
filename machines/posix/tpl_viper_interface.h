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
 * Trampoline viper interface stuff header file
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_VIPER_INTERFACE_H
#define TPL_VIPER_INTERFACE_H

extern void tpl_viper_init(void);
extern void tpl_viper_start_one_shot_timer(int sig, unsigned long delay);
extern void tpl_viper_start_auto_timer(int sig, unsigned long delay);
extern int tpl_viper_get_motor_pos(int motor);
extern void tpl_viper_set_motor_csg(int motor, int csg);

#endif
