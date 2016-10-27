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

#define _POSIX_SOURCE

#include "tpl_app_define.h"

#if WITH_AUTOSAR == YES
	#include "Os.h"
#else
	#include "tpl_os.h"
#endif

#if ALARM_COUNT > 0
	#include "tpl_os_timeobj_kernel.h"
#endif

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <assert.h>

#if ISR_COUNT > 0
/* TODO : Multicore - Get CoreID's ipid */
void sendSoftwareIt(uint32 to_core_id, uint32 channel)
{
  int ipid;
  ipid = getpid();
  kill(ipid, channel);
}
#endif

/*
 * @def pending_signals
 *
 * This function prints the pending signals. Useful to debug to check if an interrupts has occured or not.
 *
 
void pending_signals(void)
{
	sigset_t  sig_set;
	
	int pi = getpid ();
	stdimpl_print("The pid is %d - ",pi);
	
	sigpending(&sig_set);
	
	stdimpl_print("Pending signals are %d ",(int)sig_set);
	
	if (sigismember ( &sig_set,SIGTERM) ) 
		stdimpl_print("SIGTERM is pending \n");
	
	if (sigismember ( &sig_set,SIGUSR2) ) 
		stdimpl_print("SIGUSR2 is pending \n");
}
*/

/* End of file config.c */
