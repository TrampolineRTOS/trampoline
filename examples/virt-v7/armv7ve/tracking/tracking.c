#include "arm_board.h"
#include "tpl_os.h"
#include "arm_stdio.h"
#include "arm_string.h"

static char  cmdline[1024];

/*
 * Defines pour le traitement des chaines de caractères et commandes
 */
#define ARM_MAX_CMD_STR_SIZE	32
#define ARM_MAX_ARG_SIZE	8

/*
 * Defines pour le traitement des messages en réception/émission
 */
#define MSG_TX_REQUETE               "<requete>"
#define MSG_TX_SEPARATEUR            " "
#define MSG_TX_FIN                   "\n"
#define MSG_RX_REPONSE               "<reponse>"

#define MSG_TX_REQ_CONV_A0           "<requete> analogRead A0\n"
#define MSG_TX_REQ_CONV_A1           "<requete> analogRead A1\n"

/* convertisseur A/N */
#define MSG_TX_DEMANDE_DE_CONVERSION "analogRead"

/* commande */
#define MSG_TX_ENVOI_POSITION        "digitalWrite"
#define MSG_TX_ENVOI_DIRECTION_HIGH  "HIGH"
#define MSG_TX_ENVOI_DIRECTION_LOW   "LOW"
#define MSG_TX_ENVOI_DIRECTION_NO    "NO"

/* Les ports utilisés */
#define MSG_TX_PORT_A0             "A0"
#define MSG_TX_PORT_A1             "A1"
#define MSG_TXRX_

#define SENSIBILITE                  40

/*
 * Structures de données pour le traitement des messages
 */
typedef struct {
	char data[ARM_MAX_CMD_STR_SIZE];
	uint16 index;
} T_txBuffer;

/*
 * Variables globales, c'est mal
 */
T_txBuffer txBuffer;
char line[ARM_MAX_CMD_STR_SIZE];

uint16 lights[2];
uint16 lightdiff;
uint8 dir;

/*
 * Variables définies par ailleurs
*/
extern long arm_irq;
extern void arm_exec(char *line);

/*
 * main
 */
#define APP_Task_control_START_SEC_CODE
#include "tpl_memmap.h"
/* Works in user mode */
void arm_main(void)
{
	char line[ARM_MAX_CMD_STR_SIZE];

	arm_irq = 0;
  txBuffer.index = 0;
	lights[0] = 500;
	lights[1] = 500;

	/* Setup board specific linux default cmdline */
	arm_board_linux_default_cmdline(cmdline, sizeof(cmdline));

	arm_puts(arm_board_name());
	arm_puts("Trampoline Firmware from trampoline git\n");

	arm_board_init();

	// arm_puts("Starting OS ...\n\n");
	// StartOS(OSDEFAULTAPPMODE);

	while(1) {
		arm_puts("trampoline# ");

		arm_gets(line, ARM_MAX_CMD_STR_SIZE, '\n');

		arm_exec(line);
	}
}

TASK(control) {
  static uint32 compte = 0;
  char commande[32];
	char num[32];

  compte++;

	arm_puts("lights:[");
	arm_uint2hexstr(num, lights[0]);
	arm_puts(num);
	arm_puts(",");
	arm_uint2hexstr(num, lights[0]);
	arm_puts(num);
	arm_puts("]\n");

	if (lights[0] >= lights[1]) {
		lightdiff = lights[0] - lights[1];
		dir = 1;
	} else {
		lightdiff = lights[1] - lights[0];
		dir = 3;
	}
  if (lightdiff <= SENSIBILITE) {
		lightdiff = 0;
		dir = 2;
	}

	arm_puts(MSG_TX_REQUETE);
	arm_puts(MSG_TX_SEPARATEUR);
	arm_puts(MSG_TX_ENVOI_POSITION);
	arm_puts(MSG_TX_SEPARATEUR);
	arm_uint2hexstr(num, lightdiff);
	arm_puts(num);
	arm_puts(MSG_TX_SEPARATEUR);
	if (dir == 1) {
		arm_puts(MSG_TX_ENVOI_DIRECTION_LOW);
	} else {
		if (dir == 2) {
			arm_puts(MSG_TX_ENVOI_DIRECTION_NO);
		} else {
		arm_puts(MSG_TX_ENVOI_DIRECTION_HIGH);
		}
	}
	arm_puts(MSG_TX_FIN);

  TerminateTask();
}
#define APP_Task_control_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_inputs_START_SEC_CODE
#include "tpl_memmap.h"
TASK(inputs) {
  static uint32 compte = 0;
	char command[16];
	char num[32];

  compte++;
  // arm_puts("Tache inputs : ");
	// arm_uint2hexstr(num, compte);
	// arm_puts(num);
	// arm_puts("\n");

	/*
	 * Lecture des entrees : valeurs de luminosité des deux photorécepteurs
	 */

	/*
	 * On lance une nouvelle acquisition des valeurs de luminosité
	 */
	arm_puts(MSG_TX_REQ_CONV_A0);
	arm_puts(MSG_TX_REQ_CONV_A1);

	// arm_puts(MSG_TX_REQUETE);
 // 	arm_puts(MSG_TX_SEPARATEUR);
 // 	arm_puts(MSG_TX_DEMANDE_DE_CONVERSION);
 // 	arm_puts(MSG_TX_SEPARATEUR);
 // 	arm_puts(MSG_TXRX_PORT_A1);
 // 	arm_puts(MSG_TX_FIN);

	if (txBuffer.index > 0) {
    // arm_puts("txBufferIndex : ");
 	// 	arm_uint2hexstr(num, txBuffer.index);
 	// 	arm_puts(num);
		// arm_puts(" : ");
		// for (int i=0; i<txBuffer.index; i++) {
		// 	arm_board_serial_putc(txBuffer.data[i]);
		// }
 	// 	arm_puts("\n");
		 /* There may be a command */
		com_exec(&txBuffer);
		//  arm_puts("txBufferIndex : ");
		//  arm_uint2hexstr(num, txBuffer.index);
		//  arm_puts(num);
		//  arm_puts("\n");
  }

  TerminateTask();
}
#define APP_Task_inputs_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_polling_START_SEC_CODE
#include "tpl_memmap.h"

// int com_gets(char *s, int maxwidth, char endchar);
void com_exec(T_txBuffer *);
uint16 serial_gets(char *s, int maxwidth, char endchar);

TASK(polling) {
	int somethingToExec;
	char c;
	char num[32];

	arm_puts("Tache polling\n");

	while(1) {
		if (txBuffer.index == 0) {
    	txBuffer.index = serial_gets(txBuffer.data, ARM_MAX_CMD_STR_SIZE, '\n');
			// arm_puts("string : ");
			// arm_uint2hexstr(num, txBuffer.index);
			// arm_puts(num);
			// arm_puts(" : ");
			// arm_puts(txBuffer.data);
			// arm_puts("\n");
		}
	}

  TerminateTask();
}

// int com_gets(char *s, char *command, int maxwidth, char endchar)
// {
// 	int nbchar;
// 	char *retval;
// 	char ch;
//
// 	nbchar = 0;
// 	retval = s;
// 	ch = arm_board_serial_mute_getc();
// 	// arm_board_serial_putc('-');
// 	// arm_board_serial_putc(ch);
// 	while (ch != endchar && maxwidth > 0) {
// 		*retval = ch;
// 		retval++;
// 		maxwidth--;
// 		nbchar++;
// 		if (maxwidth == 0)
// 			break;
// 		ch = arm_board_serial_mute_getc();
// 	}
// 	*retval = '\0';
//
// 	return nbchar;
// }

void com_cmd_analogRead(int argc, char **argv);

void com_exec(T_txBuffer *buffer)
{
	int argc = 0, pos = 0, cnt = 0;
	char *argv[ARM_MAX_ARG_SIZE];
	char *data;
	char num[32];

	while (pos < buffer->index && (argc < ARM_MAX_ARG_SIZE)) {
		// arm_puts("car : ");
		num[0] = buffer->data[pos];
		// arm_board_serial_putc(num[0]);
		// arm_puts("\n");
		if ((buffer->data[pos] == '\r') ||
		    (buffer->data[pos] == '\n')) {
			buffer->data[pos] = '\0';
			break;
		}
		if (buffer->data[pos] == ' ') {
			if (cnt > 0) {
				buffer->data[pos] = '\0';
				cnt = 0;
			}
		} else {
			if (cnt == 0) {
				argv[argc] = &buffer->data[pos];
				argc++;
			}
			cnt++;
		}
		pos++;
	}

	// arm_puts("argv : \n");
	// for (int i=0; i<argc; i++) {
	// 	arm_uint2hexstr(num, i);
	// 	arm_puts(num);
	// 	arm_puts(" : ");
	// 	arm_puts(argv[i]);
	// 	arm_puts("\n");
	// }
	if (argc > 0) {
		// arm_puts("buffer : ");
		// arm_puts(buffer->data);
		// arm_puts("\n");

		if (arm_strcmp(argv[1], "analogRead") == 0) {
			com_cmd_analogRead(argc, argv);
		} else {
			arm_puts("Unknown command : ");
			arm_uint2hexstr(num, argc);
			arm_puts(num);
			arm_puts(" : ");
			arm_puts(argv[0]);
			arm_puts(" : ");
			arm_puts(argv[1]);
			arm_puts(" : ");
			arm_puts(argv[2]);
			arm_puts("\n");
		}
		for (pos = 0; pos < buffer->index; pos++) {
			buffer->data[pos] = '\0';
		}
		buffer->index = 0;
	}
}

void com_cmd_analogRead(int argc, char **argv)
{
	uint16 val;
	char num[32];

	// arm_uint2hexstr(num, argc);
	// arm_puts("com_cmd_analogRead : ");
	// arm_puts(num);
	// arm_puts("\n");

	if (argc != 4) {
		arm_puts ("analogRead: need 2 parameters\n");
	} else {
		if (arm_strcmp(argv[2], "A0") == 0) {
			// Valeur dans argv[2]
			arm_puts("A0 ");
			// val = arm_str2int(argv[3]);
			// arm_uint2hexstr(num, val);
			// arm_puts(num);
			// arm_puts("\n");
			lights[0] = (int)*argv[3];
			arm_uint2hexstr(num, lights[0]);
			arm_puts(num);
			arm_puts("\n");
		} else if (arm_strcmp(argv[2], "A1") == 0) {
			// Valeur dans argv[2]
			arm_puts("A1 ");
			// val = arm_str2int(argv[3]);
			// arm_uint2hexstr(num, val);
			// arm_puts(num);
			// arm_puts("\n");
			lights[1] = (int)*argv[3];
			arm_uint2hexstr(num, lights[1]);
			arm_puts(num);
			arm_puts("\n");
		} else {
			arm_puts ("analogRead: parameter 1 unknown\n");
		}
	}
}

uint16 serial_gets(char *s, int maxwidth, char endchar)
{
	char *retval;
	char ch;
	uint16 size = 0;

	retval = s;
	ch = arm_board_serial_getc();
	while (ch != endchar && maxwidth > 0) {
		*retval = ch;
		retval++;
		maxwidth--;
		size++;
		if (maxwidth == 0)
			break;
		ch = arm_board_serial_getc();
	}
	*retval = '\0';
	return size;
}

#define APP_Task_polling_STOP_SEC_CODE
#include "tpl_memmap.h"
