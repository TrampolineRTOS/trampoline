#ifndef _DR_CAN_H_
#define _DR_CAN_H_

#include "mpc565.h"
#include "touCAN.h"




/**************************************************************************************************/
/* Function prototypes */
/**************************************************************************************************/
void drv_can_interrupt(UINT8);
void drv_can_treat_msg(UINT8 ,UINT8 );
void drv_can_new_msg(canMsgType *);

/**************************************************************************************************/
/* Constants for TouCAN */
/**************************************************************************************************/
#define NULL_MSG	0x00000000

#define RXBuf		0b0000
#define TXBuf		0b1000
#define TX_Run		0b1100
#define RX_Run		0b0100

#define SINGLE_SCAN		0x00
#define CONTINUOUS_SCAN	0x01

#endif