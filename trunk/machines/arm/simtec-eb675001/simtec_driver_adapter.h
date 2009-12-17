/**
 * @file simtec_driver_adapter.h
 *
 * @section descr File description
 *
 * Simtec board support adapter. Here is the interface directly used
 * by Trampoline Simtec port. Thus, drivers can be those provided by
 * Trampoline or any external library.
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
#ifndef SIMTEC_DRIVER_ADAPTER_H
#define SIMTEC_DRIVER_ADAPTER_H

#ifdef SIMTEC_DEFAULT_DRIVERS
#include "default_drivers/miro_types.h"
#include "default_drivers/interruption.h"
#define SYSTEM_TIMER_INT_SOURCE INTERRUPTION_TIMER_SYSTEME
#endif

extern void simtec_clock_gen_setup_defaults ();

extern void simtec_int_ctrl_setup_defaults ();

extern void simtec_memory_setup_defaults ();

extern void simtec_disable_all_devices ();

extern void simtec_setup_heartbeat_timer_1ms ();

extern void simtec_heartbeat_timer_start ();

extern void simtec_heartbeat_timer_ack ();

extern void simtec_cpu_halt ();

extern void simtec_system_standby ();

extern u32 simtec_get_interrupt_source ();

extern void simtec_acknoledge_current_irq_level ();

#endif /* SIMTEC_DRIVER_ADAPTER_H */
