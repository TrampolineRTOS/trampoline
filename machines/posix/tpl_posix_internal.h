/**
 *
 * @file tpl_posix_internal.h
 *
 * @section descr File description
 *
 * Declaration of internal function of Trampoline posix platform
 * used in tpl_machine_posix.c
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
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

#include "tpl_app_config.h"
#include "tpl_app_custom_types.h"

/* TODO change viper API to hide this variable */
#if ((WITH_AUTOSAR == YES) && (SCHEDTABLE_COUNT > 0)) || (ALARM_COUNT > 0)
extern const int signal_for_counters;
#endif

#if WITH_AUTOSAR_TIMING_PROTECTION == YES
void tpl_start_tptimer ();
#endif

void tpl_create_context(tpl_proc_id proc_id);

void tpl_posix_sigblock(const char* error_message);
void tpl_posix_sigunblock(const char* error_message);
void tpl_posix_siginit(void);
