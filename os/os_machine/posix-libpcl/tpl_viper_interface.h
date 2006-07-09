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

#ifndef __TPL_VIPER_INTERFACE_H__
#define __TPL_VIPER_INTERFACE_H__


#define _XOPEN_SOURCE 500
#include <unistd.h>

void lx86_init_viper(void);
void lx86_start_one_shot_timer(int sig, useconds_t delay);
void lx86_start_auto_timer(int sig, useconds_t delay);

#endif
