#include "mytypes.h"
#include "AT91SAM7.h"
#include "uart.h"
#include "bt.h"
#include "aic.h"
#include  <string.h>
#include "display.h"
#include "systick.h"

static U8 in_buf[2][128];
static U8 in_buf_in_ptr, out_buf_ptr;
static U8 out_buf[2][256];

static U8* buf_ptr;

static int in_buf_idx = 0;

#define BAUD_RATE 460800
#define CLOCK_RATE 48054850

	
void bt_init(void)
{
  U8 trash;
  U32 trash2;
  in_buf_in_ptr = out_buf_ptr = 0; 
  in_buf_idx = 0;
  
  *AT91C_PMC_PCER = (1 << AT91C_PERIPHERAL_ID_US1); 
  
  *AT91C_PIOA_PDR = BT_RX_PIN | BT_TX_PIN | BT_SCK_PIN | BT_RTS_PIN | BT_CTS_PIN; 
  *AT91C_PIOA_ASR = BT_RX_PIN | BT_TX_PIN | BT_SCK_PIN | BT_RTS_PIN | BT_CTS_PIN; 
  
  *AT91C_US1_CR   = AT91C_US_RSTSTA;
  *AT91C_US1_CR   = AT91C_US_STTTO;
  *AT91C_US1_RTOR = 10000; 
  *AT91C_US1_IDR  = AT91C_US_TIMEOUT;
  *AT91C_US1_MR = (AT91C_US_USMODE_HWHSH & ~AT91C_US_SYNC) | AT91C_US_CLKS_CLOCK | AT91C_US_CHRL_8_BITS | AT91C_US_PAR_NONE | AT91C_US_NBSTOP_1_BIT | AT91C_US_OVER;
  *AT91C_US1_BRGR = ((CLOCK_RATE/8/BAUD_RATE) | (((CLOCK_RATE/8) - ((CLOCK_RATE/8/BAUD_RATE) * BAUD_RATE)) / ((BAUD_RATE + 4)/8)) << 16);
  *AT91C_US1_PTCR = (AT91C_PDC_RXTDIS | AT91C_PDC_TXTDIS); 
  *AT91C_US1_RCR  = 0; 
  *AT91C_US1_TCR  = 0; 
  *AT91C_US1_RNPR = 0;
  *AT91C_US1_TNPR = 0;
  
  aic_mask_off(AT91C_PERIPHERAL_ID_US1);
  aic_clear(AT91C_PERIPHERAL_ID_US1);

  trash = *AT91C_US1_RHR;
  trash = *AT91C_US1_CSR;
  
  *AT91C_US1_RPR  = (unsigned int)&(in_buf[0][0]); 
  *AT91C_US1_RCR  = 128;
  *AT91C_US1_RNPR = (unsigned int)&(in_buf[1][0]);
  *AT91C_US1_RNCR = 128;
  *AT91C_US1_CR   = AT91C_US_RXEN | AT91C_US_TXEN; 
  *AT91C_US1_PTCR = (AT91C_PDC_RXTEN | AT91C_PDC_TXTEN); 
  
  *AT91C_PIOA_PDR = BT_RX_PIN | BT_TX_PIN | BT_SCK_PIN | BT_RTS_PIN | BT_CTS_PIN; 
  *AT91C_PIOA_ASR = BT_RX_PIN | BT_TX_PIN | BT_SCK_PIN | BT_RTS_PIN | BT_CTS_PIN; 
  *AT91C_PIOA_PER   = BT_CS_PIN | BT_RST_PIN; 
  *AT91C_PIOA_OER   = BT_CS_PIN | BT_RST_PIN; 
  *AT91C_PIOA_SODR  = BT_CS_PIN | BT_RST_PIN;
  *AT91C_PIOA_PPUDR = BT_ARM7_CMD_PIN;
  *AT91C_PIOA_PER   = BT_ARM7_CMD_PIN; 
  *AT91C_PIOA_CODR  = BT_ARM7_CMD_PIN;
  *AT91C_PIOA_OER   = BT_ARM7_CMD_PIN; 
  // Configure timer 01 as trigger for ADC, sample every 0.5ms
  *AT91C_PMC_PCER = (1 << AT91C_PERIPHERAL_ID_TC1); 
  *AT91C_TC1_CCR = AT91C_TC_CLKDIS;
  *AT91C_TC1_IDR = ~0;
  trash2 = *AT91C_TC1_SR;
  *AT91C_TC1_CMR = AT91C_TC_WAVE | AT91C_TC_WAVESEL_UP_AUTO | AT91C_TC_ACPA_SET | AT91C_TC_ACPC_CLEAR | AT91C_TC_ASWTRG_SET; /* MCLK/2, wave mode 10 */
  *AT91C_TC1_RC = (CLOCK_FREQUENCY/2)/(2000);
  *AT91C_TC1_RA = (CLOCK_FREQUENCY/2)/(4000);
  *AT91C_TC1_CCR = AT91C_TC_CLKEN;
  *AT91C_TC1_CCR = AT91C_TC_SWTRG;

  *AT91C_PMC_PCER = (1 << AT91C_PERIPHERAL_ID_ADC); 
  *AT91C_ADC_MR  = 0;
  *AT91C_ADC_MR |= AT91C_ADC_TRGEN_EN | AT91C_ADC_TRGSEL_TIOA1;
  *AT91C_ADC_MR |= 0x00003F00;
  *AT91C_ADC_MR |= 0x00020000;
  *AT91C_ADC_MR |= 0x09000000;
  *AT91C_ADC_CHER  = AT91C_ADC_CH6 | AT91C_ADC_CH4; 
  
  buf_ptr = &(in_buf[0][0]);
}

void bt_start_ad_converter()
{
  // This method is no longer required. The ADC is started automatically
  // by the hardware timer.
}

U32 bt_get_mode()
{
  // return the bt4 mode value.
  return (U32) *AT91C_ADC_CDR6;
}

void bt_send(U8 *buf, U32 len)
{
  if (*AT91C_US1_TNCR == 0)
  {
    memcpy(&(out_buf[out_buf_ptr][0]), buf, len);
    *AT91C_US1_TNPR = (unsigned int) &(out_buf[out_buf_ptr][0]);
    *AT91C_US1_TNCR = len;
    out_buf_ptr = (out_buf_ptr+1) % 2;
  }
}

U32 bt_write(U8 *buf, U32 off, U32 len)
{
  if (*AT91C_US1_TNCR == 0)
  {	
    if (len > 256) len = 256;	
    memcpy(&(out_buf[out_buf_ptr][0]), buf+off, len);
    *AT91C_US1_TNPR = (unsigned int) &(out_buf[out_buf_ptr][0]);
    *AT91C_US1_TNCR = len;
    out_buf_ptr = (out_buf_ptr+1) % 2;
    return len;
  }
  else
    return 0;
}

U32 bt_pending()
{
  // return the state of any pending i/o requests one bit for input one bit
  // for output.
  // First check for any input
  int ret = 0;
  int bytes_ready;
  if (*AT91C_US1_RNCR == 0) 
    bytes_ready = 256 - *AT91C_US1_RCR;
  else 
    bytes_ready = 128 - *AT91C_US1_RCR;
  if (bytes_ready  > in_buf_idx) ret |= 1;
  if ((*AT91C_US1_TCR != 0) || (*AT91C_US1_TNCR != 0)) ret |= 2;
  return ret;
}


void bt_clear_arm7_cmd(void)
{
  *AT91C_PIOA_CODR  = BT_ARM7_CMD_PIN;
}

void bt_set_arm7_cmd(void)
{
  *AT91C_PIOA_SODR  = BT_ARM7_CMD_PIN;
}

void bt_set_reset_high(void)
{
  *AT91C_PIOA_SODR = BT_RST_PIN;
}

void bt_receive(U8 * buf)
{
  int bytes_ready, total_bytes_ready;
  int cmd_len, i;
  U8* tmp_ptr;
  
  buf[0] = 0;
  buf[1] = 0;
  
  if (*AT91C_US1_RNCR == 0) {
  	bytes_ready = 128;
  	total_bytes_ready = 256 - *AT91C_US1_RCR;
  }
  else total_bytes_ready = bytes_ready = 128 - *AT91C_US1_RCR;
  
  // At least 2 bytes ready to be processed?
  
  if (total_bytes_ready > in_buf_idx + 1)
  {
  	cmd_len = (int) buf_ptr[in_buf_idx];
  	
  	// Data mode kludge - data cannot be more than 255 bytes
  	
  	if (in_buf_idx < 127)
  	{
  		if (buf_ptr[in_buf_idx+1] == 0) cmd_len++;
  	} 
  	else
  	{
  	  tmp_ptr = &(in_buf[(in_buf_in_ptr+1)%2][0]);
      if (tmp_ptr[0] == 0) cmd_len++;
  	}

    // Is whole command in the buffer?
  
    if (bytes_ready >= in_buf_idx + cmd_len + 1)
    { 	
  	  for(i=0;i<cmd_len+1;i++) buf[i] = buf_ptr[in_buf_idx++];
    }
    else
    {
      if (total_bytes_ready >= in_buf_idx + cmd_len + 1)
      {
      	for(i=0;i<cmd_len+1 && in_buf_idx < 128;i++) buf[i] = buf_ptr[in_buf_idx++];
      	in_buf_idx = 0;
      	tmp_ptr = &(in_buf[(in_buf_in_ptr+1)%2][0]);
      	for(;i<cmd_len+1;i++) buf[i] = tmp_ptr[in_buf_idx++];
      	in_buf_idx += 128;
      }
      else return; // wait for all bytes to be ready
    } 
  }
  
  // Current buffer full and fully processed
  
  if (in_buf_idx >= 128 && *AT91C_US1_RNCR == 0)
  { 	
  	// Switch current buffer, and set up next 
  	
  	in_buf_idx -= 128;
  	*AT91C_US1_RNPR = (unsigned int) buf_ptr;
  	*AT91C_US1_RNCR = 128;
  	in_buf_in_ptr = (in_buf_in_ptr+1) % 2;
  	buf_ptr = &(in_buf[in_buf_in_ptr][0]);
  }   
}

U32 bt_read(U8 * buf, U32 off, U32 len)
{
  int bytes_ready, total_bytes_ready;
  int cmd_len, i;
  U8* tmp_ptr;
  
  cmd_len = 0;
  if (*AT91C_US1_RNCR == 0) {
    bytes_ready = 128;
    total_bytes_ready = 256 - *AT91C_US1_RCR;
  }
  else
    total_bytes_ready = bytes_ready = 128 - *AT91C_US1_RCR;
  
  if (total_bytes_ready > in_buf_idx)
  {
    cmd_len = (int) (total_bytes_ready - in_buf_idx);
    if (cmd_len > len) cmd_len = len;
  	
    if (bytes_ready >= in_buf_idx + cmd_len)
    { 	
      for(i=0;i<cmd_len;i++) buf[off+i] = buf_ptr[in_buf_idx++];
    }
    else
    {
      for(i=0;i<cmd_len && in_buf_idx < 128;i++) buf[off+i] = buf_ptr[in_buf_idx++];
      in_buf_idx = 0;
      tmp_ptr = &(in_buf[(in_buf_in_ptr+1)%2][0]);
      for(;i<cmd_len;i++) buf[off+i] = tmp_ptr[in_buf_idx++];
      in_buf_idx += 128;
    } 
  }
  
  // Current buffer full and fully processed
  
  if (in_buf_idx >= 128 && *AT91C_US1_RNCR == 0)
  { 	
  	// Switch current buffer, and set up next 
  	
  	in_buf_idx -= 128;
  	*AT91C_US1_RNPR = (unsigned int) buf_ptr;
  	*AT91C_US1_RNCR = 128;
  	in_buf_in_ptr = (in_buf_in_ptr+1) % 2;
  	buf_ptr = &(in_buf[in_buf_in_ptr][0]);
  }
  return cmd_len;   
}

void bt_set_reset_low(void)
{
  *AT91C_PIOA_CODR = BT_RST_PIN;
}

void bt_reset(void)
{
  // Perform hardware reset. This function has some relatively long
  // delays in it and so should probably only be called during application
  // initialisation and termination. Calling it at other times may cause
  // problems for other real time tasks.

  // If power is currently off to the BC4 do not reset it!
  if ((*AT91C_PIOA_ODSR & BT_RST_PIN) == 0) return; 
  //display_goto_xy(0, 1);
  //display_string("BT Reset....");
  //display_update();
  //systick_wait_ms(10000);
  // Ask for command mode
  bt_clear_arm7_cmd();
  // BC4 reset sequence. First take the reset line low for 100ms
  bt_set_reset_low();
  // Wait and discard any packets that may be around
  int cnt = 100;
  U8 *buf = out_buf[0];
  while (cnt-- > 0)
  {
    bt_receive(buf);
    systick_wait_ms(1);
  }
  bt_set_reset_high();
  // Now wait either for 5000ms or for the BC4 chip to signal reset
  // complete. Note we use the out buffer as a scratch area here
  // this id safe since we are forcing a reset.
  cnt = 5000;
  while (cnt-- > 0)
  {
    bt_receive(buf);
    // Look for the reset indication and the checksum
    if ((buf[0] == 3) && (buf[1] == MSG_RESET_INDICATION) && 
        (buf[2] == 0xff) && (buf[3] == 0xe9))
        break;
    systick_wait_ms(1);
  }
  // Force command mode
  bt_clear_arm7_cmd();
  //display_goto_xy(10, 1);
  //display_int(cnt, 5);
  //display_update();
  //systick_wait_ms(10000);
}
