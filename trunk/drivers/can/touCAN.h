#ifndef _TOUCAN_H_
#define _TOUCAN_H_

#define  NO_BUS_CAN		2

typedef struct
{
	UINT8 no_Can;
	UINT8 bufType;
	UINT16 ID_HIGH;
	UINT16 ID_LOW;
	UINT8 Length;
	UINT8 DATA[8];
	UINT8 Mode;
}canMsgType;

typedef struct 
{
	canMsgType *IPDU;
	UINT8  bufType;
	UINT8  mode;
} t_Buffer;

typedef struct
{
	struct TOUCAN_tag *CAN;
	t_Buffer Buffer[16];
}t_busCan;

/**************************************************************************************************/
/* Function prototypes */
/**************************************************************************************************/

void toucan_MB_off (struct TOUCAN_tag *CAN); /* set all 16 TouCAN MB's to inactive */
void toucan_bus_on (struct TOUCAN_tag *CAN); /* turn on TouCAN - release all MB's and clear HALT */
void toucan_init (struct TOUCAN_tag *CAN); /* Initialise TOUCAN global regs and reset all MBs */
void toucan_set_interrupt(struct TOUCAN_tag *CAN,UINT8 LEVEL); /* Initialize TOUCAN Interrupts */
void toucan_SetBuf_interrupt(struct TOUCAN_tag *CAN,UINT8 NoBuffer);
void toucan_ClearBuf_interrupt(struct TOUCAN_tag *CAN,UINT8 NoBuffer);
void toucan_SetCode(UINT8 no_BusCan,UINT8 no_Buffer,UINT8 Code);
UINT8 toucan_GetCode(UINT8 no_BusCan,UINT8 no_Buffer);
void toucan_copy_buffer2message(UINT8 no_BusCan,UINT8 no_Buffer);
void toucan_copy_message2buffer(UINT8 no_BusCan,UINT8 no_Buffer);
void toucan_set_filter(UINT8 no_BusCan, UINT8 no_Buffer,UINT16 ID_HIGH, UINT16 ID_LOW);
/*void toucan_data_send(struct TOUCAN_tag *CAN,UINT8 NoBuffer,sBuffer *Mes);
void toucan_init_receive(struct TOUCAN_tag *CAN,UINT8 NoBuffer,sBuffer *Mes);
void toucan_set_RxGlobalMask(struct TOUCAN_tag *CAN,sMask *Masque);
*/

/**************************************************************************************************/
/* Constants for TouCAN */
/**************************************************************************************************/
/* TouCAN Message Buffer codes */

#define RX_DISABLE 0x00 /* RX buffer not active */
#define RX_ENABLE 0x40 /* RX buffer active */
#define RX_FULL 0x20 /* RX buffer full */
#define RX_OVER 0x60 /* RX buffer overrun */
#define RX_BUSY 0x01 /* RX buffer busy */
#define TX_DISABLE 0x80 /* TX buffer not active */
#define TX_ENABLE 0xC0 /* TX buffer active */
#define TX_REM_REQ 0xC0 /* TX buffer remote transmission request */
#define TX_REM_REP 0xA0 /* TX buffer remote transmission reply */
#define TX_EN_REM_REP 0xE0 /* TX buffer active, then remote reply */

#define SRR		0x10
#define IDE		0x08

#define BUFFER_0			0
#define BUFFER_1			1
#define BUFFER_2			2
#define BUFFER_3			3
#define BUFFER_4			4
#define BUFFER_5			5
#define BUFFER_6			6
#define BUFFER_7			7
#define BUFFER_8			8
#define BUFFER_9			9
#define BUFFER_10			10
#define BUFFER_11			11
#define BUFFER_12			12
#define BUFFER_13			13
#define BUFFER_14			14
#define BUFFER_15			15

// TOUCAN Interrupts
#define BUSINT_Off			0x00
#define BUSINT_On			0x10
#define ERRINT_Off			0x00
#define ERRINT_On			0x20

#define INT_BUFFER_0		0x0001
#define INT_BUFFER_1		0x0002
#define INT_BUFFER_2		0x0004
#define INT_BUFFER_3		0x0008
#define INT_BUFFER_4		0x0010
#define INT_BUFFER_5		0x0020
#define INT_BUFFER_6		0x0040
#define INT_BUFFER_7		0x0080
#define INT_BUFFER_8		0x0100
#define INT_BUFFER_9		0x0200
#define INT_BUFFER_10		0x0400
#define INT_BUFFER_11		0x0800
#define INT_BUFFER_12		0x1000
#define INT_BUFFER_13		0x2000
#define INT_BUFFER_14		0x4000
#define INT_BUFFER_15		0x8000

// Niveau de priorité
#define CAN_PRIOR_LEVEL_0	0x00	
#define CAN_PRIOR_LEVEL_1	0x01
#define CAN_PRIOR_LEVEL_2	0x02
#define CAN_PRIOR_LEVEL_3	0x03
#define CAN_PRIOR_LEVEL_4	0x04
#define CAN_PRIOR_LEVEL_5	0x05
#define CAN_PRIOR_LEVEL_6	0x06
#define CAN_PRIOR_LEVEL_7	0x07

/************************************************************************************************* */
/* The following static parameters are passed to the TouCAN
initialisation function to initialise the global registers */
/************************************************************************************************* */

//#define RJW 3 /* BIT TIMING: resync jump width (-1): 0-3 */
//#define PSEG1 5 /* BIT TIMING: phase segment 1 (-1): 0-7 */
//#define PSEG2 5 /* BIT TIMING: phase segment 2 (-1): 0-7 */
/* BIT TIMING =
FSYS 20MHz
-------------------------------------------------= ------------- = 1MHz
PRES_D * (1 + PROPSEG(+1) + PSEG1(+1) + PSEG2(+1)) 1 * (1+6+6+7)
*/

#endif