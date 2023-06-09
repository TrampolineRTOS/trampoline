#include "spider_serial.h"

uint32 Serial_Init(void)
{
  volatile uint8  wait_cmpt;

  /* Clear bits TE and RE in HSSCR to 0 */
  SERIAL_SCR =  SERIAL_SCR_INT_VALUE;

  /* Set bits TFRST and RFRST in FCR to 1 */
  SERIAL_FCR |= SERIAL_FCR_TFRST_MASK | SERIAL_FCR_RFRS_MASK;

  /* Clear flags ER, DR, BRK, and RDF in FSR */
  SERIAL_FSR =  SERIAL_FSR_INIT_VALUE;

  /* Clear TO and ORER in LSR,*/
  SERIAL_LSR =  SERIAL_LSR_INIT_VALUE;

  /* Set bits CKE[1:0] in SCR (leaving other bits cleared to 0) */
  SERIAL_SCR   =  (SERIAL_SCR & ~SERIAL_SCR_CKE_MASK) | SERIAL_SCR_CKE_INIT_VALUE;

  /* Set data transfer format in HSSMR ( 8 bits, no parity, 1 stop bit, async) */
  SERIAL_SMR = SERIAL_SMR_INIT_VALUE;

  /* Baud rate setting */
  SERIAL_BRR = SERIAL_BAUDRATE;
                      
#if (SERIAL_BASE_ADDR == SCIF_BASE_ADDR)
  /* SCIF module used */
  SERIAL_DL    = SERIAL_DL_SETTING_VALUE;
  SERIAL_CKS   &= ~(SERIAL_CKS_DIV_MASK | SERIAL_CKS_XIN_MASK);
#else
  /* HSCIF module used */
  /* Sampling rate 8  */
  SERIAL_SRR = SERIAL_SRR_VAL;
#endif

  for (wait_cmpt = 0; wait_cmpt < 100; wait_cmpt++)
  {
  }

  /* reset-off, tx-fifo, rx-fifo */
  SERIAL_FCR = SERIAL_FCR_INIT_VALUE;

  /* Enable TE and RE bits*/
  SERIAL_SCR |= SERIAL_SCR_TE_MASK | SERIAL_SCR_RE_MASK;

  return 1;
}

void Serial_Tx_Wait(void)
{
  /* Wait until TX FIFO is empty */
  do
  {
  } while ((SERIAL_FSR & SERIAL_TX_DONE) != SERIAL_TX_DONE);
}

uint32 Serial_Tx(uint8 data)
{
  Serial_Tx_Wait();

  /* Fill FTDR register with data to send */
  SERIAL_FTDR = data;

  /* Clear TX status bits */
  SERIAL_FSR &= ~SERIAL_TX_DONE;

  return 1;
}

uint8 Serial_Rx(uint8* data)
{
  /* Check if data available */
  if((SERIAL_FSR & SERIAL_FSR_RDF_MASK) != SERIAL_FSR_RDF_MASK)
    return 0;

  /* Check Data Ready and no break, timeout, overrun nor receive errors */
  if (((SERIAL_FSR & SERIAL_RX_READY) != 0) || (SERIAL_LSR != 0))
    return 2;

  /* Get rx data */
  *data = SERIAL_FRDR;
  /* Send back data */
  Serial_Tx(*data);
  /* Clear RDF flag */
  SERIAL_FSR &= ~SERIAL_FSR_RDF_MASK;

  return 1;
}
