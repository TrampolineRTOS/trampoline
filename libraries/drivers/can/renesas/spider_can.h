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

// A bus bridge is used on the CR52 core to access the CAN bus located in the G4MH control domain, that's why the base address high bits are different
#ifdef __arm__
	/** CAN module 0 */
	#define RSCFD0_BASE_ADDR 0xDFF50000
	/** CAN module 1 */
	#define RSCFD1_BASE_ADDR 0xDFD00000
#else
	/** CAN module 0 */
	#define RSCFD0_BASE_ADDR 0xFFF50000
	/** CAN module 1 */
	#define RSCFD1_BASE_ADDR 0xFFD00000
#endif

/**
 * All available CAN controllers.
 */
extern tpl_can_controller_t spider_can_controller_0, spider_can_controller_1;

#endif
