/**
 * @file config.c
 *
 * @section desc File description
 *
 * @section copyright Copyright
 *
 * Trampoline Test Suite
 *
 * Trampoline Test Suite is copyright (c) IRCCyN 2005-2007
 * Trampoline Test Suite is protected by the French intellectual property law.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_app_define.h"
#include "tpl_registers.h"

#if WITH_AUTOSAR == YES
  #include "Os.h"
#else
  #include "tpl_os.h"
#endif

#if ISR_COUNT > 0
void sendSoftwareIt(uint32 to_core_id, uint32 channel)
{
  TPL_INTC(to_core_id).SSCIR[channel] = INTC_SSCIR_SET;
#if WITH_VLE == YES
  _asm("se_isync");
#else
  _asm("isync");
#endif
}
#endif

