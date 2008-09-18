#include "drv_can.h"

extern t_busCan ppc_Can[NO_BUS_CAN];

void drv_can_interrupt(UINT8 no_BusCan) // A revoir selon le fonctionnement
{
	UINT8 no_Buffer;
	UINT16 mask;
	/* Recherche des buffers ayant levé l'interruption */
	for(no_Buffer=0;no_Buffer<16;no_Buffer++)
	{
		mask = (0x01<<no_Buffer);
		if((&ppc_Can[no_BusCan].CAN->IFLAG && mask) == mask) // Le buffer à interrompu
		{
			drv_can_treat_msg(no_BusCan,no_Buffer);
		}
	}
}

void drv_can_treat_msg(UINT8 no_BusCan,UINT8 no_Buffer)
{
	
	
	/* Look if it's a RX or TX buffer */
	if(ppc_Can[no_BusCan].Buffer[no_Buffer].bufType == TXBuf)
	{
		// Signaler la transmission
		
		// Réinitialiser le buffer
		toucan_SetCode(no_BusCan,no_Buffer,TX_DISABLE);
		
		// Libérer le Buffer et enlever l'IT
		ppc_Can[no_BusCan].Buffer[no_Buffer].IPDU = NULL_MSG;
		toucan_ClearBuf_interrupt(ppc_Can[no_BusCan].CAN,no_Buffer);

	}
	else
	{
		// lecture du Buffer
		toucan_copy_buffer2message(no_BusCan,no_Buffer);
		
		// Regarde le mode de fonctionnement
		if(	ppc_Can[no_BusCan].Buffer[no_Buffer].mode == SINGLE_SCAN)
		{
			// On libère le Buffer et on enlève l'IT
			ppc_Can[no_BusCan].Buffer[no_Buffer].IPDU = NULL_MSG;
			toucan_ClearBuf_interrupt(ppc_Can[no_BusCan].CAN,no_Buffer);
			
			// On libère le Buffer
			toucan_SetCode(no_BusCan,no_Buffer,RX_DISABLE);
		}
		else
		{
			/* Activate receiving */
			toucan_SetCode(no_BusCan,no_Buffer,RX_Run);
		}
		
	}
}


void drv_can_new_msg(canMsgType *msg)
{
  UINT8 i,no_Buffer,no_BusCan;
  
  no_BusCan = msg->no_Can;
  /* Initiate search for a free buffer */
  no_Buffer=0;
  while((ppc_Can[no_BusCan].Buffer[no_Buffer].IPDU)!=NULL_MSG) no_Buffer++;
  
  if(no_Buffer<16) /* A free buffer has been found */
  {
  	ppc_Can[no_BusCan].Buffer[no_Buffer].IPDU = msg;
  	
  	/* Configurate buffer in RX or Tx Mode */
  	
  	ppc_Can[no_BusCan].CAN->MBUFF[no_Buffer].SCR.B.CODE = msg->bufType;
  	
  	/* Set message mask to buffer */
  	
  	toucan_set_filter(no_BusCan,no_Buffer,msg->ID_HIGH,msg->ID_LOW);
  	
	
	if(msg->bufType==TXBuf)
	{
		ppc_Can[no_BusCan].Buffer[no_Buffer].bufType = TXBuf;
		/* Writing the message to the buffer */
		toucan_copy_message2buffer(no_BusCan,no_Buffer);
		
		/* Enable interrupt */
		toucan_SetBuf_interrupt(ppc_Can[no_BusCan].CAN,no_Buffer);
				
		/* Activate sending */
		toucan_SetCode(no_BusCan,no_Buffer,TX_Run);
	}
	else
	{
		ppc_Can[no_BusCan].Buffer[no_Buffer].bufType = RXBuf;
		
		/* Enable interrupt */
		toucan_SetBuf_interrupt(ppc_Can[no_BusCan].CAN,no_Buffer);
		
		/* Activate receiving */
		toucan_SetCode(no_BusCan,no_Buffer,RX_Run);
	}
	
  }
  else /* No free buffer found */
  {
  	
  }
  
}