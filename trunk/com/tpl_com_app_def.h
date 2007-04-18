/**
 * @file tpl_com_app_def.h
 *
 * @section File description
 *
 * This file wraps user application configuration header for communication
 * objects. This wrapped file is typically
 * generated from an OIL source.
 *
 * @section Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_COM_APP_DEF_H
#define TPL_COM_APP_DEF_H

#include "tpl_app_objects.h"

#ifndef SEND_MESSAGE_COUNT
	#define SEND_MESSAGE_COUNT 0
#endif
#if SEND_MESSAGE_COUNT == 0
/**
 * @def NO_SEND_MESSAGE
 *
 * When this flag is defined, this means there is no sending message object
 * defined in the system.
 */
	#define NO_SEND_MESSAGE
#endif

#ifndef RECEIVE_MESSAGE_COUNT
	#define RECEIVE_MESSAGE_COUNT 0
#endif
#if RECEIVE_MESSAGE_COUNT == 0
/**
 * @def NO_RECEIVE_MESSAGE
 *
 * When this flag is defined, this means there is no sending message object
 * defined in the system.
 */
	#define NO_RECEIVE_MESSAGE
#endif


/* TPL_COM_APP_DEF_H */
#endif
