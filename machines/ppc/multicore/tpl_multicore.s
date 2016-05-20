/*
 * @file tpl_multicore.s
 *
 * @section desc File description
 *
 * Trampoline multicore assembly functions for PPC
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 *  Trampoline is copyright (c) IRCCyN 2005-2009
 *  Autosar extension is copyright (c) IRCCyN and ESEO 2007-2009
 *  Trampoline and its Autosar extension are protected by the
 *  French intellectual property law.
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


#include "tpl_assembler.h"
#include "tpl_registers_asm.h"
#include "tpl_app_define.h"

#if (WITH_VLE == YES)
TPL_VLE_ON
#else
TPL_VLE_OFF
#endif

#if WITH_MULTICORE == YES

#define OS_START_SEC_CODE
#include "AsMemMap.h"
TPL_GLOBAL(tpl_get_core_id)
TPL_GLOBAL_REF(tpl_get_core_id):
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  mfspr r3,spr_PIR
  se_blr
/* ------------ NO VLE ------------------------------------------------------*/
#else
  mfspr r3,spr_PIR
  blr
#endif
  FUNCTION(TPL_GLOBAL_REF(tpl_get_core_id))
TPL_TYPE(TPL_GLOBAL_REF(tpl_get_core_id),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_get_core_id),$-TPL_GLOBAL_REF(tpl_get_core_id))
#define OS_STOP_SEC_CODE
#include "AsMemMap.h"

#endif // if WITH_MULTICORE == YES

