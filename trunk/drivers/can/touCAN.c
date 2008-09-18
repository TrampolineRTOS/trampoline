/**************************************************************************************************/
/* COPYRIGHT (c) MOTOROLA 1998                                                                    */
/* FILE NAME: toucan.c                                                                            */
/*                                                                                                */
/* Generic functions for TouCAN                                                                   */
/*================================================================================================*/
/*                                                                                                */
/* DESCRIPTION:                                                                                   */
/* This file contains generic TouCAN functions as follows :                                       */
/* void toucan_MB_off (void) - Set all 16 MB's to inactive, clear IFLAG                           */
/* void toucan_bus_on (void) - Activates TouCAN by negating the HALT flag                         */
/* void toucan_init_global (void) - Initialise TOUCAN global registers                            */
/*                                                                                                */
/* This code is intended for demonstration purposes only and is not                               */
/* guaranteed to function in a given application.                                                 */
/*                                                                                                */
/**************************************************************************************************/

#include "mpc565.h"/* 68376 registers plus basic type defs */
#include "toucan.h" /* Constants and bit defs for TouCAN */

t_busCan ppc_Can[NO_BUS_CAN];

/***************************************************************************************************
Function : toucan_MB_off()
Parameters : struct TOUCAN_tag
Return : Void
Description : Set all 16 TouCAN MB's to inactive and clear IFLAG register.
***************************************************************************************************/
void toucan_MB_off (struct TOUCAN_tag *CAN)
{
  int i;
  UINT16 Flags;
  
  for(i=0;i<16;i++)
  {
  	CAN->MBUFF[i].SCR.B.CODE = RX_DISABLE;	// DEvery buffer is set to inactive mode
  }
  Flags = CAN->IFLAG.R;
  CAN->IFLAG.R = 0x0000; // Clear the 16 bits of IFLAG register  by reading it
}

/***************************************************************************************************
Function : toucan_bus_on()
Parameters : struct TOUCAN_tag
Return : Void
Description : Unlocks all message buffers and activates the TouCAN by negating
the HALT flag to allow synchronisation with the external CAN bus.
***************************************************************************************************/
void toucan_bus_on (struct TOUCAN_tag *CAN)
{
  UINT16 tmr_temp; /* used to read CAN TIMER and unlock all MBs */
  tmr_temp = CAN->TIMER.R; /* read the free running timer to release last buffer read */
  CAN->TCNMCR.B.HALT = 0; /* activate the TouCAN module by clearing HALT */
}

/***************************************************************************************************
Function : toucan_init_global()
Parameters : struct TOUCAN_tag
Return : Void
Description : Initialise TOUCAN global registers (CANMCR, CANICR, CANCTRL0/1,
PRESDIV, CANCTRL2) for bit timing, pin control . All 16
TouCAN MB's are set to inactive. Mask registers and IMASK register are
NOT configured here. TouCAN is left in HALT mode.
***************************************************************************************************/
void toucan_init (struct TOUCAN_tag *CAN)
{
 /* Soft reset du module TouCAN */
 CAN->TCNMCR.B.SOFTRST=1;
 while(CAN->TCNMCR.B.SOFTRST) /* Wait the end of the reset */
 
 CAN->CANCTRL0.B.RXMODE = 0;	/* 0 is dominant bir */
 CAN->CANCTRL0.B.TXMODE = 0;
 
 CAN->CANCTRL1.B.PROPSE = 2;
 CAN->CANCTRL1.B.LBUF = 0;	/* messages with lower ID have the priority */
 
 // Selection of Bit Rate
 CAN->CANCTRL2.B.RJW = 1;
 CAN->CANCTRL2.B.PSEG = 2;
 CAN->CANCTRL2.B.PSEG2 = 2;
 CAN->PRESDIV.R = 7;
 
 toucan_MB_off(CAN); /* set all 16 TouCAN MB's to inactive */
}

/***************************************************************************************************
Function : toucan_set_interrupt()
Parameters : struct TOUCAN_tag
Return : Void
Description : Sets the interrupt for the CAN Bus
***************************************************************************************************/
void toucan_set_interrupt(struct TOUCAN_tag *CAN,UINT8 LEVEL)
{
  /* Interruption for bus Error */
  CAN->CANCTRL0.B.BOFFMSK = (LEVEL & 0x10)>>4;
  CAN->CANCTRL0.B.ERRMSK = (LEVEL & 0x20)>>5;
  
  /* Configuration of interruption level */
  CAN->CANICR.B.IRL = (LEVEL & 0x0F); 
  CAN->CANICR.B.ILBS = 0; /* Only interruption level from 0 to 7 are allowed */
  
   USIU.SIMASK.R |= (0x40000000 >> ((LEVEL&0x0F)<<1)); 	/* Enable level interrupt */
}

void toucan_SetBuf_interrupt(struct TOUCAN_tag *CAN,UINT8 NoBuffer)
{
	CAN->IMASK.R |= 0x01 << NoBuffer;	
}

void toucan_ClearBuf_interrupt(struct TOUCAN_tag *CAN,UINT8 NoBuffer)
{
	CAN->IMASK.R &= ~(0x01 << NoBuffer);
}


void toucan_SetCode(UINT8 no_BusCan,UINT8 no_Buffer,UINT8 Code)
{
	ppc_Can[no_BusCan].CAN->MBUFF[no_Buffer].SCR.B.CODE = Code;	
}

UINT8 toucan_GetCode(UINT8 no_BusCan,UINT8 no_Buffer)
{
	UINT8 Code;
	Code = ppc_Can[no_BusCan].CAN->MBUFF[no_Buffer].SCR.B.CODE;
	return Code;	
}


void toucan_copy_buffer2message(UINT8 no_BusCan,UINT8 no_Buffer)
{
	UINT8 msg_length,buf_data,i;
	
	// On récupère la longueur du message
	msg_length = ppc_Can[no_BusCan].CAN->MBUFF[no_Buffer].SCR.B.LENGTH;
	ppc_Can[no_BusCan].Buffer[no_Buffer].IPDU->Length = msg_length;
	
	for(i=0;i<msg_length;i++)
	{
		buf_data = ppc_Can[no_BusCan].CAN->MBUFF[no_Buffer].DATA[i].R;
		ppc_Can[no_BusCan].Buffer[no_Buffer].IPDU->DATA[i] = buf_data;
	}
}


void toucan_copy_message2buffer(UINT8 no_BusCan,UINT8 no_Buffer)
{
	UINT8 msg_length,buf_data,i;
	UINT8 code,timer,id_buf;
	
	// Lock the buffer for reading;
	code = ppc_Can[no_BusCan].CAN->MBUFF[no_Buffer].SCR.B.CODE;
	
	// On récupère le masque du message
	id_buf = ppc_Can[no_BusCan].CAN->MBUFF[no_Buffer].ID_HIGH.R;
	ppc_Can[no_BusCan].Buffer[no_Buffer].IPDU->ID_HIGH = id_buf;
	
	id_buf = ppc_Can[no_BusCan].CAN->MBUFF[no_Buffer].ID_HIGH.R;
	ppc_Can[no_BusCan].Buffer[no_Buffer].IPDU->ID_LOW = id_buf;
	
	
	// On récupère la taille du message
	msg_length = ppc_Can[no_BusCan].Buffer[no_Buffer].IPDU->Length;
	ppc_Can[no_BusCan].CAN->MBUFF[no_Buffer].SCR.B.LENGTH = msg_length;
	
	for(i=0;i<msg_length;i++)
	{
		buf_data = 	ppc_Can[no_BusCan].Buffer[no_Buffer].IPDU->DATA[i];
		ppc_Can[no_BusCan].CAN->MBUFF[no_Buffer].DATA[i].R = buf_data;
	}
	
	// Unlock buffer for other use
	timer = ppc_Can[no_BusCan].CAN->MBUFF[no_Buffer].SCR.B.TIMESTAMP;
	
}

void toucan_set_filter(UINT8 no_BusCan, UINT8 no_Buffer,UINT16 ID_HIGH, UINT16 ID_LOW)
{
	UINT16 ID1,ID2;
	#ifdef EXTENDED_MODE
  	  ID1 = (ID_HIGH & 0x3FF8)<<5;
  	  ID2 = (ID_HIGH & 0x0007);
  	  
	  ppc_Can[no_BusCan].CAN->MBUFF[no_Buffer].ID_HIGH.R = ID1 | SRR | IDE | ID2; 
	  ppc_Can[no_BusCan].CAN->MBUFF[no_Buffer].ID_LOW.R = (msg->ID_LOW&0xFE) ; 
	#else
	  ID1 = (ID_HIGH & 0x3FF8)<<5;
	  ppc_Can[no_BusCan].CAN->MBUFF[no_Buffer].ID_HIGH.R = ID1; 
	  
	#endif
}
/*void toucan_data_send(struct TOUCAN_tag *CAN,UINT8 NoBuffer,sBuffer *Mes)
{
    UINT8 i;
  
	CAN->MBUFF[NoBuffer].SCR.B.CODE = 0b1000; // Activate the buffer NoBuffer 
		
	CAN->MBUFF[NoBuffer].ID_HIGH.R = (Mes->COMMANDE<<5) | SRR | IDE | (Mes->NOCARTE);
	CAN->MBUFF[NoBuffer].ID_LOW.R = (Mes->PARAMETRE<<1);
	
	for(i=0;i<Mes->LENGTH;i++)
	{
		CAN->MBUFF[NoBuffer].DATA[i].R = Mes->DATA[i];
	}
	CAN->MBUFF[NoBuffer].SCR.B.LENGTH = Mes->LENGTH;
	CAN->MBUFF[NoBuffer].SCR.B.CODE = 0b1100;
}

void toucan_init_receive(struct TOUCAN_tag *CAN,UINT8 NoBuffer,sBuffer *Mes)
{
	CAN->MBUFF[NoBuffer].SCR.B.CODE = 0b0000;
	CAN->MBUFF[NoBuffer].ID_HIGH.R = (Mes->COMMANDE<<5) | IDE | (Mes->NOCARTE);
	CAN->MBUFF[NoBuffer].ID_LOW.R = (Mes->PARAMETRE<<1);
	CAN->MBUFF[NoBuffer].SCR.B.CODE = 0b0100;
}

void toucan_set_RxGlobalMask(struct TOUCAN_tag *CAN,sMask *Masque)
{
	CAN->RXGMSKHI.R = (Masque->MASK_COMMANDE <<5) | (Masque->MASK_CARTE);
	CAN->RXGMSKLO.R = (Masque->MASK_PARAMETRE<<1);	
}
*/
/*	Exemple d'utilisation
	toucan_init(&CAN_A);
	toucan_init(&CAN_B);
	toucan_set_interrupt(&CAN_A,BUSINT_On | ERRINT_On | CAN_PRIOR_LEVEL_5);
	toucan_set_interrupt(&CAN_B,BUSINT_On | ERRINT_On | CAN_PRIOR_LEVEL_5);
	toucan_bus_on(&CAN_A);
	toucan_bus_on(&CAN_B);
	Mes.COMMANDE = 120;
	Mes.NOCARTE = 2;
	Mes.PARAMETRE = 100;
	Mes.LENGTH = 1;
	Mes.DATA[0] = 93;
	
	Masque.MASK_COMMANDE = 121;
	Masque.MASK_CARTE = 2;
	Masque.MASK_PARAMETRE = 100;
	toucan_set_RxGlobalMask(&CAN_B,&Masque);
	
	toucan_SetBuf_interrupt(&CAN_B,BUFFER_0);
	toucan_init_receive(&CAN_B,BUFFER_0,&Mes);
	
	toucan_SetBuf_interrupt(&CAN_A,BUFFER_0);
	toucan_data_send(&CAN_A,BUFFER_0,&Mes);*/
