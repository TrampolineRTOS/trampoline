/*
 * @file tpl_os_event.h
 *
 * @section desc File description
 *
 * Trampoline Event Management header file
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
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

#ifndef TPL_OS_EVENT_H
#define TPL_OS_EVENT_H

#include "tpl_os_types.h"

/*
 * Event Control
 * see paragraph 13.5,
 * pages 60+ of OSEK/VDX 2.2.2 spec
 */

/**
 * @typedef EventmaskType
 *
 * identifies an event
 *
 * see paragraph 13.5.1 page 60 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_event_mask  EventMaskType;

/**
 * @typedef EventmaskRefType
 *
 * references an #EventmaskType
 *
 * see paragraph 13.5.1 page 60 of OSEK/VDX 2.2.2 spec
 */
typedef P2VAR(tpl_event_mask, TYPEDEF, OS_APPL_DATA)  EventMaskRefType;

/**
 * @def DeclareEvent
 *
 * defines an event
 *
 * @param event_id C identifier of the event
 *
 * see paragraph 13.5.2.1 page 60 of OSEK/VDX 2.2.2 spec
 */
#define DeclareEvent(event_id)  \
extern CONST(EventMaskType, AUTOMATIC) event_id

#endif /* TPL_OS_EVENT */

/* End of file tpl_os_event.h */
