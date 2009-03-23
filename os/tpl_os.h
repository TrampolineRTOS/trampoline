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
#include "tpl_os_application_def.h"

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


#ifdef WITH_COM
/*
 * Inclusion of the header for communication related API services
 */
#include "tpl_com_internal.h"
#endif

#ifdef WITH_AUTOSAR
/*
 * Inclusion of the header for schedule table related API services
 * Only for AUTOSAR extension
 */
#include "tpl_as_schedtable.h"

/*
 * Inclusion of the header for counters related API services
 * Only for AUTOSAR extension
 */
#include "tpl_as_counter.h"

/* WITH_AUTOSAR */
#endif

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

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 * Gives the current application mode
 *
 * @return the application mode
 *
 * see paragraph 13.7.2.1 page 66 of OSEK/VDX 2.2.2 spec
 */
FUNC(AppModeType, OS_CODE) GetActiveApplicationMode(void);


/**
 * Starts Trampoline
 *
 * @param Mode choosen application mode
 *
 * see paragraph 13.7.2.2 page 66 of OSEK/VDX 2.2.2 spec
 */
extern FUNC(void, OS_CODE) StartOS(
    CONST(AppModeType, AUTOMATIC) mode
);


/**
 * Stops Trampoline
 *
 * @param Error error occured
 *
 * see paragraph 13.7.2.3 page 67 of OSEK/VDX 2.2.2 spec
 */
FUNC(void, OS_CODE) ShutdownOS(
    CONST(StatusType, AUTOMATIC) error
);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_OS_H */

/* End of file tpl_os.h */
