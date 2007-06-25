/**
 * @file tpl_os.h
 *
 * @section desc File description
 *
 * This header file provides standard OSEK-VDX API. We do not give detailed 
 * documentation here, you just have to follow the specification reference for
 * each element you need more informations.
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
 
#ifndef TPL_OS_H
#define TPL_OS_H

#include "tpl_os_definitions.h"

/*
 * Inclusion of the header for task related API services
 */
#include "tpl_os_task.h"

/*
 * Inclusion of the header for event related API services
 */
#include "tpl_os_event.h"

/*
 * Inclusion of the header for alarm related API services
 */
#include "tpl_os_alarm.h"

/*
 * Inclusion of the header for resource related API services
 */
#include "tpl_os_rez.h"

/*
 * Inclusion of the header for interrupt related API services
 */
#include "tpl_os_it.h"

/**
 * @typedef AppModeType
 *
 * Application execution mode
 *
 * see paragraph 13.7.1 page 66 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_application_mode AppModeType;

/*
 * System services
 * see paragraph 13.7.2,
 * pages 66+ of OSEK/VDX 2.2.2 spec
 */

/**
 * Gives the current application mode
 *
 * @return the application mode
 *
 * see paragraph 13.7.2.1 page 66 of OSEK/VDX 2.2.2 spec
 */
#define OS_START_SEC_CODE
#include "Memmap.h"
AppModeType GetActiveApplicationMode(void);
#define OS_STOP_SEC_CODE
#include "Memmap.h"

/**
 * Starts Trampoline
 *
 * @param Mode choosen application mode
 *
 * see paragraph 13.7.2.2 page 66 of OSEK/VDX 2.2.2 spec
 */
#define OS_START_SEC_CODE
#include "Memmap.h"
void StartOS(const AppModeType mode);
#define OS_STOP_SEC_CODE
#include "Memmap.h"

/**
 * Stops Trampoline
 *
 * @param Error error occured
 *
 * see paragraph 13.7.2.3 page 67 of OSEK/VDX 2.2.2 spec
 */
#define OS_START_SEC_CODE
#include "Memmap.h"
void ShutdownOS(const StatusType error);
#define OS_STOP_SEC_CODE
#include "Memmap.h"

#endif /* TPL_OS_H */

/* End of file tpl_os.h */
