#include "arm_board.h"
#include "arm_stdio.h"
#include "arm_string.h"
#include "tpl_os.h"

static char  cmdline[1024];

#define ARM_MAX_CMD_STR_SIZE	256

extern long arm_irq;
extern void arm_exec(char *line);

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"
/* Works in user mode */
void arm_main(void)
{
	char line[ARM_MAX_CMD_STR_SIZE];

	arm_irq = 0;

	/* Setup board specific linux default cmdline */
	arm_board_linux_default_cmdline(cmdline, sizeof(cmdline));

	arm_puts(arm_board_name());
	arm_puts(" Trampoline Firmware from trampoline git\n\n");

	arm_board_init();

	// arm_puts("Starting OS ...\n\n");
	// StartOS(OSDEFAULTAPPMODE);

	while(1) {
		arm_puts("trampoline# ");

		arm_gets(line, ARM_MAX_CMD_STR_SIZE, '\n');

		arm_exec(line);
	}
}

TASK(blink) {
  static long compte = 0;
	char num[32];

  compte++;
  arm_puts("Tache BLINK : ");
	arm_uint2hexstr(num, compte);
	arm_puts(num);
	arm_puts("\n");

  TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"
