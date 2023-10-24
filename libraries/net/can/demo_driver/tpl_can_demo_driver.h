/**
 * @file tpl_can_demo_driver.h
 *
 * @section desc File description
 *
 * Exposes two dummy CAN controllers that implements all controller operations
 * by displaying debug messages.
 * The purpose of this driver is to test the CAN stack.
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
#ifndef TPL_CAN_DEMO_DRIVER_H
#define TPL_CAN_DEMO_DRIVER_H

#include <Can.h>

// All available controllers
extern tpl_can_controller_t can_demo_driver_controller_1;
extern tpl_can_controller_t can_demo_driver_controller_2;

#endif
