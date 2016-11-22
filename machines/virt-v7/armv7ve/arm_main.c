/**
 * Copyright (c) 2012 Jean-Christophe Dubois.
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * @file arm_main.c
 * @author Jean-Christophe Dubois (jcd@tribudubois.net)
 * @brief basic firmware main file
 */

#include <arm_io.h>
#include <arm_cache.h>
#include <arm_heap.h>
#include <arm_mmu.h>
#include <arm_irq.h>
#include <arm_timer.h>
#include <arm_math.h>
#include <arm_string.h>
#include <arm_stdio.h>
#include <arm_board.h>
//#include <libfdt.h>
//#include <fdt_support.h>
#include <dhry.h>

#include "tpl_dispatch_table.h"
#include "tpl_os.h"
#include "tpl_os_kernel.h"

static int memory_size = 0x0;

const unsigned int test_const = 0xABC;

extern long arm_irq;
extern long arm_tick;
extern long tpl_call_counter_tick_nbcall;
extern long tpl_counter_tick_nbcall;
extern long test_nbcall;
extern long testi_nbcall;
extern volatile VAR (uint32, OS_VAR) nested_kernel_entrance_counter;

extern FUNC(tpl_bool, OS_CODE)  tpl_call_counter_tick();

/* Works in supervisor mode */
void arm_init(void)
{
	arm_heap_init();

	arm_irq_disable();

	arm_irq_setup();

	arm_stdio_init();

	arm_timer_init(10000);
	// arm_timer_init(500000);

	memory_size = arm_board_ram_size();

	arm_timer_enable();

	arm_irq_enable();
}

void arm_cmd_help(int argc, char **argv)
{
	arm_puts("help        - List commands and their usage\n");
	arm_puts("\n");
	arm_puts("vars        - Print initial vars values\n");
	arm_puts("\n");
	arm_puts("startos     - Starts Trampoline\n");
	arm_puts("\n");
	arm_puts("tpld       - tpl_dispatch_table print index\n");
	arm_puts("\n");
	arm_puts("i           - Simulate tick timer interrupt\n");
	arm_puts("\n");
	arm_puts("svc         - Raise SVC call\n");
	arm_puts("\n");
	arm_puts("ptick       - Print number of ticks\n");
	arm_puts("\n");
	arm_puts("hi          - Say hi to basic firmware\n");
	arm_puts("\n");
	arm_puts("hello       - Say hello to basic firmware\n");
	arm_puts("\n");
	arm_puts("wfi_test    - Run wait for irq instruction test for basic firmware\n");
	arm_puts("            Usage: wfi_test [<msecs>]\n");
	arm_puts("            <msecs>  = delay in milliseconds to wait for\n");
	arm_puts("\n");
	arm_puts("mmu_setup   - Setup MMU for basic firmware\n");
	arm_puts("\n");
	arm_puts("mmu_state   - MMU is enabled/disabled for basic firmware\n");
	arm_puts("\n");
	arm_puts("mmu_test    - Run MMU test suite for basic firmware\n");
	arm_puts("\n");
	arm_puts("mmu_cleanup - Cleanup MMU for basic firmware\n");
	arm_puts("\n");
	arm_puts("timer       - Display timer information\n");
	arm_puts("\n");
	arm_puts("dhrystone   - Dhrystone 2.1 benchmark\n");
	arm_puts("            Usage: dhrystone [<iterations>]\n");
	arm_puts("\n");
	arm_puts("hexdump     - Dump memory contents in hex format\n");
	arm_puts("            Usage: hexdump <addr> <count>\n");
	arm_puts("            <addr>  = memory address in hex\n");
	arm_puts("            <count> = byte count in hex\n");
	arm_puts("\n");
	arm_puts("copy        - Copy to target memory from source memory\n");
	arm_puts("            Usage: copy <dest> <src> <count>\n");
	arm_puts("            <dest>  = destination address in hex\n");
	arm_puts("            <src>   = source address in hex\n");
	arm_puts("            <count> = byte count in hex\n");
	arm_puts("\n");
	arm_puts("start_linux - Start linux kernel (atags mechanism)\n");
	arm_puts("            Usage: start_linux <kernel_addr> [<initrd_addr>] [<initrd_size>]\n");
	arm_puts("            <kernel_addr>  = kernel load address\n");
	arm_puts("            <initrd_addr>  = initrd load address (optional)\n");
	arm_puts("            <initrd_size>  = initrd size (optional)\n");
	arm_puts("\n");
	arm_puts("linux_cmdline - Show/Update linux command line\n");
	arm_puts("            Usage: linux_cmdline [<new_linux_cmdline>]\n");
	arm_puts("            <new_linux_cmdline>  = linux command line\n");
	arm_puts("\n");
	arm_puts("linux_memory_size - Show/Update linux memory size\n");
	arm_puts("            Usage: linux_memory_size [<memory_size>]\n");
	arm_puts("            <memory_size>  = memory size in hex\n");
	arm_puts("\n");
	arm_puts("autoexec    - autoexec command list from flash\n");
	arm_puts("            Usage: autoexec\n");
	arm_puts("\n");
	arm_puts("go          - Jump to a given address\n");
	arm_puts("            Usage: go <addr>\n");
	arm_puts("            <addr>  = jump address in hex\n");
	arm_puts("\n");
	arm_puts("reset       - Reset the system\n");
	arm_puts("\n");
}

void arm_cmd_vars(int argc, char **argv) {
		char str[32];
		tpl_proc_id save_proc_id;
		tpl_proc_state save_proc_state;

	if (argc != 1) {
		arm_puts ("vars: no parameters required\n");
		return;
	}

	arm_puts("Some variables ...\n");

	arm_puts("nested_kernel_entrance_counter = ");
	arm_uint2hexstr(str, nested_kernel_entrance_counter);
	arm_puts(str);
	arm_puts("\n");

	arm_puts("tpl_kern = ");

	arm_puts("Test variable access write ...\n");

	arm_puts("Writing running_id\n");
	arm_puts("running_id = ");
	save_proc_id = tpl_kern.running_id;
	arm_int2str(str, tpl_kern.running_id);
	arm_puts(str);
	arm_puts(" - w - ");
	tpl_kern.running_id = (tpl_proc_id)7;
	arm_puts("running_id = ");
	arm_int2str(str, tpl_kern.running_id);
	arm_puts(str);
	arm_puts("\n");
	tpl_kern.running_id = save_proc_id;

	arm_puts("Writing running->state\n");
	if (tpl_kern.running != 0) {
		arm_puts("running->state = ");
		save_proc_state = tpl_kern.running->state;
		arm_uint2hexstr(str, tpl_kern.running->state);
		arm_puts(str);
		arm_puts(" - w - ");
		tpl_kern.running->state = (tpl_proc_state)9;
		arm_uint2hexstr(str, tpl_kern.running->state);
		arm_puts(str);
		arm_puts("\n");
		tpl_kern.running->state = save_proc_state;
	} else {
		arm_puts("running non initialisé\n");
	}
}

void arm_cmd_startos(int argc, char **argv) {
	if (argc != 1) {
		arm_puts ("startos: no parameters required\n");
		return;
	}
	arm_puts("Starting OS ...\n\n");
	StartOS(OSDEFAULTAPPMODE);
}

void arm_cmd_tpld(int argc, char **argv)
{
	int n;
	unsigned int addr;
	char saddr[32];
	char sval[32];
	if (argc != 2) {
		arm_puts ("tpld: one parameter <index of service>\n");
		return;
	} else if (argc == 2) {
		arm_uint2hexstr(sval, test_const);
		arm_puts("valeur test_const : ");
		arm_puts(sval);
		arm_puts("\n");

		addr = (unsigned int)tpl_dispatch_table;
		arm_uint2hexstr(saddr, addr);
		arm_puts("adresse de tpl_dispatch_table : ");
		arm_puts(saddr);
		arm_puts("\n");

		n = arm_str2int(argv[1]);
		addr = (unsigned int)tpl_dispatch_table[n];
		arm_uint2hexstr(saddr, addr);
		arm_puts("adresse de fonction : ");
		arm_puts(saddr);
		arm_puts("\n");
		if (addr != 0) {
			(*tpl_dispatch_table[n])();
		} else {
			arm_puts("Addresse invalide\n");
		}
	} else {
		arm_puts ("tpld: unavailable service\n");
	}
}

extern FUNC(tpl_bool, OS_CODE) tpl_tick_ARM_TIMER(void);

void arm_cmd_i(int argc, char **argv)
{
	if (argc != 1) {
		arm_puts ("i: no parameters required\n");
		return;
	}
  tpl_tick_ARM_TIMER();
}

void arm_cmd_svc(int argc, char **argv)
{
	int n;
	if (argc != 2) {
		arm_puts ("svc: one parameter <number of service call>\n");
		return;
	} else if (argc == 2) {
		n = arm_str2int(argv[1]);
		if (n == 0) {
			__asm__ ("svc #0");
		} else if (n == 1) {
			__asm__ ("svc #1");
		} else if (n == 2) {
			__asm__ ("svc #2");
		} else {
			arm_puts ("svc: unavailable service\n\n");
		}
		// __asm__ ("svc %0"
    //     : /* No outputs. */
    //     : "r" (n));
	}
}

void arm_cmd_ntick(int argc, char **argv)
{
	char num[256];

	if (argc != 1) {
		arm_puts ("ntick: no parameters required\n");
		return;
	}
	arm_puts("irqs :  ");
	arm_ulonglong2str(num, arm_irq);
	arm_puts(num);
	arm_puts("\n");
	arm_puts("ticks : ");
	arm_ulonglong2str(num, arm_tick);
	arm_puts(num);
	arm_puts("\n");
	arm_puts("tpl_call_counter_tick : ");
	arm_ulonglong2str(num, tpl_call_counter_tick_nbcall);
	arm_puts(num);
	arm_puts("\n");
	arm_puts("tpl_counter_tick : ");
	arm_ulonglong2str(num, tpl_counter_tick_nbcall);
	arm_puts(num);
	arm_puts("\n");
	arm_puts("test_nbcall : ");
	arm_ulonglong2str(num, test_nbcall);
	arm_puts(num);
	arm_puts("\n");
	arm_puts("testi_nbcall : ");
	arm_ulonglong2str(num, testi_nbcall);
	arm_puts(num);
	arm_puts("\n");
}

void arm_cmd_hi(int argc, char **argv)
{
	if (argc != 1) {
		arm_puts ("hi: no parameters required\n");
		return;
	}

	arm_puts("hello\n");
}

void arm_cmd_hello(int argc, char **argv)
{
	if (argc != 1) {
		arm_puts ("hello: no parameters required\n");
		return;
	}

	arm_puts("hi\n");
}

void arm_cmd_wfi_test(int argc, char **argv)
{
	u64 tstamp;
	char time[256];
	int delay = 1000;

	if (argc > 2) {
		arm_puts ("wfi_test: could provide only <delay>\n");
		return;
	} else if (argc == 2) {
		delay = arm_str2int(argv[1]);
	}

	arm_puts("Executing WFI instruction\n");
	arm_timer_disable();
	arm_timer_change_period(delay*1000);
	arm_timer_enable();
	tstamp = arm_timer_timestamp();
	arm_irq_wfi();
	tstamp = arm_timer_timestamp() - tstamp;
	arm_timer_disable();
	arm_timer_change_period(10000);
	arm_timer_enable();
	arm_puts("Resumed from WFI instruction\n");
	arm_puts("Time spent in WFI: ");
	arm_ulonglong2str(time, tstamp);
	arm_puts(time);
	arm_puts(" nsecs\n");
}

void arm_cmd_mmu_setup(int argc, char **argv)
{
	if (argc != 1) {
		arm_puts ("mmu_setup: no parameters required\n");
		return;
	}

	arm_mmu_setup();
}

void arm_cmd_mmu_state(int argc, char **argv)
{
	if (argc != 1) {
		arm_puts ("mmu_state: no parameters required\n");
		return;
	}

	if (arm_mmu_is_enabled()) {
		arm_puts("MMU Enabled\n");
	} else {
		arm_puts("MMU Disabled\n");
	}
}

void arm_cmd_mmu_test(int argc, char **argv)
{
	char str[32];
	u32 total = 0x0, pass = 0x0, fail = 0x0;

	if (argc != 1) {
		arm_puts ("mmu_test: no parameters required\n");
		return;
	}

	arm_puts("MMU Section Test Suite ...\n");
	total = 0x0;
	pass = 0x0;
	fail = 0x0;
	arm_mmu_section_test(&total, &pass, &fail);
	arm_puts("  Total: ");
	arm_int2str(str, total);
	arm_puts(str);
	arm_puts("\n");
	arm_puts("  Pass : ");
	arm_int2str(str, pass);
	arm_puts(str);
	arm_puts("\n");
	arm_puts("  Fail : ");
	arm_int2str(str, fail);
	arm_puts(str);
	arm_puts("\n");
	arm_puts("MMU Page Test Suite ...\n");
	total = 0x0;
	pass = 0x0;
	fail = 0x0;
	arm_mmu_page_test(&total, &pass, &fail);
	arm_puts("  Total: ");
	arm_int2str(str, total);
	arm_puts(str);
	arm_puts("\n");
	arm_puts("  Pass : ");
	arm_int2str(str, pass);
	arm_puts(str);
	arm_puts("\n");
	arm_puts("  Fail : ");
	arm_int2str(str, fail);
	arm_puts(str);
	arm_puts("\n");
}

void arm_cmd_mmu_cleanup(int argc, char **argv)
{
	if (argc != 1) {
		arm_puts ("mmu_cleanup: no parameters required\n");
		return;
	}

	arm_mmu_cleanup();
}

void arm_cmd_timer(int argc, char **argv)
{
	char str[32];
	u64 irq_count, irq_delay, tstamp;

	if (argc != 1) {
		arm_puts ("timer: no parameters required\n");
		return;
	}

	irq_count = arm_timer_irqcount();
	irq_delay = arm_timer_irqdelay();
	tstamp = arm_timer_timestamp();
	arm_puts("Timer Information ...\n");
	arm_puts("  IRQ Count:  0x");
	arm_ulonglong2hexstr(str, irq_count);
	arm_puts(str);
	arm_puts("\n");
	arm_puts("  IRQ Delay:  ");
	arm_ulonglong2str(str, irq_delay);
	arm_puts(str);
	arm_puts(" nsecs\n");
	arm_puts("  Time Stamp: 0x");
	arm_ulonglong2hexstr(str, tstamp);
	arm_puts(str);
	arm_puts("\n");
}

void arm_cmd_dhrystone(int argc, char **argv)
{
	char str[32];
	int iters = 1000000;
	if (argc > 2) {
		arm_puts ("dhrystone: could provide only <iter_number>\n");
		return;
	} else if (argc == 2) {
		iters = arm_str2int(argv[1]);
	} else {
		arm_puts ("dhrystone: number of iterations not provided\n");
		arm_puts ("dhrystone: using default ");
		arm_int2str (str, iters);
		arm_puts (str);
		arm_puts (" iterations\n");
	}
	arm_timer_disable();
	dhry_main(iters);
	arm_timer_enable();
}

void arm_cmd_hexdump(int argc, char **argv)
{
	char str[32];
	u32 *addr;
	u32 i, count, len;
	if (argc != 3) {
		arm_puts ("hexdump: must provide <addr> and <count>\n");
		return;
	}
	addr = (u32 *)arm_hexstr2uint(argv[1]);
	count = arm_hexstr2uint(argv[2]);
	for (i = 0; i < (count / 4); i++) {
		if (i % 4 == 0) {
			arm_uint2hexstr(str, (u32)&addr[i]);
			len = arm_strlen(str);
			while (len < 8) {
				arm_puts("0");
				len++;
			}
			arm_puts(str);
			arm_puts(": ");
		}
		arm_uint2hexstr(str, addr[i]);
		len = arm_strlen(str);
		while (len < 8) {
			arm_puts("0");
			len++;
		}
		arm_puts(str);
		if (i % 4 == 3) {
			arm_puts("\n");
		} else {
			arm_puts(" ");
		}
	}
	arm_puts("\n");
}

void arm_cmd_copy(int argc, char **argv)
{
	u64 tstamp;
	char time[256];
	u32 *dest, *src;
	virtual_addr_t dest_va;
	u32 i, count;

	/* Determine copy args */
	if (argc != 4) {
		arm_puts ("copy: must provide <dest>, <src>, and <count>\n");
		return;
	}
	dest = (u32 *)arm_hexstr2uint(argv[1]);
	if (((virtual_addr_t)dest) & 0x3) {
		arm_puts ("copy: <dest> should be 4-byte aligned\n");
		return;
	}
	dest_va = (virtual_addr_t)dest;
	src = (u32 *)arm_hexstr2uint(argv[2]);
	if (((virtual_addr_t)src) & 0x3) {
		arm_puts ("copy: <src> should be 4-byte aligned\n");
		return;
	}
	count = arm_hexstr2uint(argv[3]);

	/* Disable timer and get start timestamp */
	arm_timer_disable();
	tstamp = arm_timer_timestamp();

	/* It might happen that we are running Basic firmware
	 * after a reboot from Guest Linux in which case both
	 * I-Cache and D-Cache will have stale contents. We need
	 * to cleanup these stale contents while copying so that
	 * we see correct contents of destination even after
	 * MMU ON.
	 */
	arm_clean_invalidate_dcache_mva_range(dest_va, dest_va + count);

	/* Copy contents */
	for (i = 0; i < (count/sizeof(*dest)); i++) {
		dest[i] = src[i];
	}

	/* Enable timer and get end timestamp */
	tstamp = arm_timer_timestamp() - tstamp;
	tstamp = arm_udiv64(tstamp, 1000);
	arm_timer_enable();

	/* Print time taken */
	arm_ulonglong2str(time, tstamp);
	arm_puts("copy took ");
	arm_puts(time);
	arm_puts(" usecs for ");
	arm_puts(argv[3]);
	arm_puts(" bytes\n");
}

typedef void (*linux_entry_t) (u32 zero, u32 machine_type, u32 kernel_args, u32 zero2);

void arm_exec(char *line);

void arm_cmd_autoexec(int argc, char **argv)
{
#define ARM_CMD_AUTOEXEC_BUF_SIZE	4096
	static int lock = 0;
	int len, pos = 0;
	/* commands to execute are stored in NOR flash */
	char *ptr = (char *)(arm_board_flash_addr() + 0xFF000);
	char buffer[ARM_CMD_AUTOEXEC_BUF_SIZE];

	if (argc != 1) {
		arm_puts ("autoexec: no parameters required\n");
		return;
	}

	/* autoexec is not recursive */
	if (lock) {
		arm_puts("ignoring autoexec calling autoexec\n");
		return;
	}

	lock = 1;

	/* determine length of command list */
	len = 0;
	while ((len < ARM_CMD_AUTOEXEC_BUF_SIZE) &&
	       arm_isprintable(ptr[len])) {
		len++;
	}

	/* sanity check on command list */
	if (!len) {
		arm_puts("command list not found !!!\n");
		return;
	}
	if (len >= ARM_CMD_AUTOEXEC_BUF_SIZE) {
		arm_printf("command list len=%d too big !!!\n", len);
		return;
	}

	/* copy commands from NOR flash */
	arm_memcpy(buffer, ptr, len);
	buffer[len] = '\0';

	/* now we process them */
	while (pos < len) {
		ptr = &buffer[pos];

		/* We need to separate the commands */
		while ((buffer[pos] != '\r') &&
			(buffer[pos] != '\n') &&
			(buffer[pos] != 0)) {
			pos++;
		}
		buffer[pos] = '\0';
		pos++;

		/* print the command */
		arm_puts("autoexec(");
		arm_puts(ptr);
		arm_puts(")\n");
		/* execute it */
		arm_exec(ptr);
	}

	lock = 0;

	return;
}

void arm_cmd_go(int argc, char **argv)
{
	char str[32];
	void (* jump)(void);

	if (argc != 2) {
		arm_puts ("go: must provide destination address\n");
		return;
	}

	arm_timer_disable();

	jump = (void (*)(void))arm_hexstr2uint(argv[1]);
	arm_uint2hexstr(str, (u32)jump);
	arm_puts("Jumping to location 0x");
	arm_puts(str);
	arm_puts(" ...\n");
	jump ();

	arm_timer_enable();
}

void arm_cmd_reset(int argc, char **argv)
{
	if (argc != 1) {
		arm_puts ("reset: no parameters required\n");
		return;
	}

	arm_puts("System reset ...\n\n");

	arm_board_reset();

	while (1);
}

#define ARM_MAX_ARG_SIZE	32

void arm_exec(char *line)
{
	int argc = 0, pos = 0, cnt = 0;
	char *argv[ARM_MAX_ARG_SIZE];

	while (line[pos] && (argc < ARM_MAX_ARG_SIZE)) {
		if ((line[pos] == '\r') ||
		    (line[pos] == '\n')) {
			line[pos] = '\0';
			break;
		}
		if (line[pos] == ' ') {
			if (cnt > 0) {
				line[pos] = '\0';
				cnt = 0;
			}
		} else {
			if (cnt == 0) {
				argv[argc] = &line[pos];
				argc++;
			}
			cnt++;
		}
		pos++;
	}

	if (argc) {
		if (arm_strcmp(argv[0], "help") == 0) {
			arm_cmd_help(argc, argv);
		} else if (arm_strcmp(argv[0], "vars") == 0) {
			arm_cmd_vars(argc, argv);
		} else if (arm_strcmp(argv[0], "startos") == 0) {
			arm_cmd_startos(argc, argv);
		} else if (arm_strcmp(argv[0], "tpld") == 0) {
			arm_cmd_tpld(argc, argv);
		} else if (arm_strcmp(argv[0], "i") == 0) {
			arm_cmd_i(argc, argv);
		} else if (arm_strcmp(argv[0], "svc") == 0) {
			arm_cmd_svc(argc, argv);
		} else if (arm_strcmp(argv[0], "ntick") == 0) {
			arm_cmd_ntick(argc, argv);
		} else if (arm_strcmp(argv[0], "hi") == 0) {
			arm_cmd_hi(argc, argv);
		} else if (arm_strcmp(argv[0], "hello") == 0) {
			arm_cmd_hello(argc, argv);
		} else if (arm_strcmp(argv[0], "wfi_test") == 0) {
			arm_cmd_wfi_test(argc, argv);
		} else if (arm_strcmp(argv[0], "mmu_setup") == 0) {
			arm_cmd_mmu_setup(argc, argv);
		} else if (arm_strcmp(argv[0], "mmu_state") == 0) {
			arm_cmd_mmu_state(argc, argv);
		} else if (arm_strcmp(argv[0], "mmu_test") == 0) {
			arm_cmd_mmu_test(argc, argv);
		} else if (arm_strcmp(argv[0], "mmu_cleanup") == 0) {
			arm_cmd_mmu_cleanup(argc, argv);
		} else if (arm_strcmp(argv[0], "timer") == 0) {
			arm_cmd_timer(argc, argv);
		} else if (arm_strcmp(argv[0], "dhrystone") == 0) {
			arm_cmd_dhrystone(argc, argv);
		} else if (arm_strcmp(argv[0], "hexdump") == 0) {
			arm_cmd_hexdump(argc, argv);
		} else if (arm_strcmp(argv[0], "copy") == 0) {
			arm_cmd_copy(argc, argv);
		} else if (arm_strcmp(argv[0], "autoexec") == 0) {
			arm_cmd_autoexec(argc, argv);
		} else if (arm_strcmp(argv[0], "go") == 0) {
			arm_cmd_go(argc, argv);
		} else if (arm_strcmp(argv[0], "reset") == 0) {
			arm_cmd_reset(argc, argv);
		} else {
			arm_puts("Unknown command\n");
		}
	}
}
