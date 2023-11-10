/**
 * Spider platform specific handlers
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright DG for function and data structures documentation and THUMB2 port
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

#include "handlers_spider.h"

/******************************************************************************
 * Exception handlers.
 ******************************************************************************/

FUNC(void, OS_CODE) c_undefined_handler(void) {
  while(1);
}

FUNC(void, OS_CODE) c_prefetch_handler(void) {
  while(1);
}

FUNC(void, OS_CODE) c_data_handler(void) {
  while(1);
}

FUNC(void, OS_CODE)  c_reserved_handler(void) {
  while(1);
}

FUNC(void, OS_CODE) c_fiq_handler(void) {
  while(1);
}

FUNC(void, OS_CODE) c_irq_handler(void) {
	while(1);
}

FUNC(void, OS_CODE) c_svc_handler(void) {
	while(1);
}

FUNC(void, OS_CODE) c_hang_handler(void) {
  while(1);
}
