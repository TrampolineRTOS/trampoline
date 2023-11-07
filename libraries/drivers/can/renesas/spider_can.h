/**
 * @file spider_can.h
 *
 * @section desc File description
 *
 * Renesas R-Car S4 CAN 2.0 driver.
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * (C) BayLibre 2023
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 *  @section infos File informations
 *
 *  $Date$
 *  $Rev$
 *  $Author$
 *  $URL$
 */
#ifndef SPIDER_CAN_H
#define SPIDER_CAN_H

#include <Can.h>
#include <tpl_os.h>

/** CAN module 0 */
#define RSCFD0_BASE_ADDR 0xDFF50000
/** CAN module 1 */
#define RSCFD1_BASE_ADDR 0xDFD00000

/**
 * All available CAN controllers.
 */
extern tpl_can_controller_t spider_can_controller_0, spider_can_controller_1;

#endif
