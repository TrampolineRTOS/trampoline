/**
 * @file buttons.h
 *
 * @section descr File description
 *
 * NXT platform. Prototype to check buttons status
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
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
#ifndef BUTTONS_H
#define BUTTONS_H

#include "tpl_os_definitions.h"

ISR(check_buttons_status);
void InitButtons(void);

#endif /* BUTTONS_H */

/* End of file buttons.h */
