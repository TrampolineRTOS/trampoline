/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
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
extern int  tpl_viper_get_motor_pos(int motor);
extern void tpl_viper_set_motor_csg(int motor, int csg);

#endif
