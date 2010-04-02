/**
 * USB support for jeJOS. 
 * We use a mixture of interrupt driven and directly driven I/O. Interrupts
 * are used for handling the configuration/enumeration phases, which allows
 * us to respond quickly to events. For actual data transfer we drive the
 * process directly thus removing the need top have data buffers available at
 * interrupt time. As with other leJOS drivers we implement only a minimal
 * set of functions in the firmware with as much as possible being done in
 * Java. In the case of USB there are strict timing requirements so we 
 * perform all of the configuration and enumeration here.
 * The leJOS implementation uses the standard Lego identifiers (and so can
 * be used from the PC side applications that work with the standard Lego
 * firmware).
 */
#include "types.h"
#include "mytypes.h"
#include "udp.h"
#include "interrupts.h"
#include "AT91SAM7.h"

#include "aic.h"
#include "systick.h"
#include "display.h"
#include <string.h>
//#include "rconsole.h"

#define MAX_BUF   64
#define EP_OUT    1
#define EP_IN     2

#define AT91C_PERIPHERAL_ID_UDP        11

#define AT91C_UDP_CSR0  ((AT91_REG *)   0xFFFB0030) 
#define AT91C_UDP_CSR1  ((AT91_REG *)   0xFFFB0034) 
#define AT91C_UDP_CSR2  ((AT91_REG *)   0xFFFB0038) 
#define AT91C_UDP_CSR3  ((AT91_REG *)   0xFFFB003C)

#define AT91C_UDP_FDR0  ((AT91_REG *)   0xFFFB0050) 
#define AT91C_UDP_FDR1  ((AT91_REG *)   0xFFFB0054) 
#define AT91C_UDP_FDR2  ((AT91_REG *)   0xFFFB0058) 
#define AT91C_UDP_FDR3  ((AT91_REG *)   0xFFFB005C) 

// The following functions are used to set/clear bits in the control
// register. This must be synchronized against the actual hardware.
// Care must also be taken to avoid clearing bits that may have been
// set by the hardware during the operation. The actual code comes
// from the Atmel sample drivers.
/// Bitmap for all status bits in CSR.
#define AT91C_UDP_STALLSENT AT91C_UDP_ISOERROR
#define REG_NO_EFFECT_1_ALL      AT91C_UDP_RX_DATA_BK0 | AT91C_UDP_RX_DATA_BK1 \
                                |AT91C_UDP_STALLSENT   | AT91C_UDP_RXSETUP \
                                |AT91C_UDP_TXCOMP

/// Sets the specified bit(s) in the UDP_CSR register.
/// \param endpoint The endpoint number of the CSR to process.
/// \param flags The bitmap to set to 1.
#define UDP_SETEPFLAGS(csr, flags) \
    { \
        volatile unsigned int reg; \
        reg = (csr) ; \
        reg |= REG_NO_EFFECT_1_ALL; \
        reg |= (flags); \
        do (csr) = reg; \
        while ( ((csr) & (flags)) != (flags)); \
    }

/// Clears the specified bit(s) in the UDP_CSR register.
/// \param endpoint The endpoint number of the CSR to process.
/// \param flags The bitmap to clear to 0.
#define UDP_CLEAREPFLAGS(csr, flags) \
    { \
        volatile unsigned int reg; \
        reg = (csr); \
        reg |= REG_NO_EFFECT_1_ALL; \
        reg &= ~(flags); \
        do (csr) = reg; \
        while ( ((csr) & (flags)) != 0); \
    }

#define MIN(a, b) ((a) < (b) ? (a) : (b))

// USB States
#define USB_READY       0
#define USB_CONFIGURED  1
#define USB_SUSPENDED   2

#define USB_DISABLED    0x8000
#define USB_NEEDRESET   0x4000
#define USB_WRITEABLE   0x100000
#define USB_READABLE    0x200000

// Critical section macros. Disable and enable interrupts
#define ENTER() (*AT91C_UDP_IDR = (AT91C_UDP_EPINT0 | AT91C_UDP_RXSUSP | AT91C_UDP_RXRSM))
#define LEAVE() (*AT91C_UDP_IER = (AT91C_UDP_EPINT0 | AT91C_UDP_RXSUSP | AT91C_UDP_RXRSM))

static U8 currentConfig;
static U32 currentFeatures;
static unsigned currentRxBank;
static int configured = (USB_DISABLED|USB_NEEDRESET);
static int newAddress;
static U8 *outPtr;
static U32 outCnt;
static U8 delayedEnable = 0;
static U32 intCnt = 0;
#if REMOTE_CONSOLE
static U8 rConsole = 0;
#endif
// Device descriptor
static const U8 dd[] = {
  0x12, 
  0x01,
  0x00,
  0x02,
  0x00,
  0x00,
  0x00, 
  0x08,
  0x94,
  0x06,
  0x02,
  0x00,
  0x00,
  0x00,
  0x00, 
  0x00, 
  0x01,
  0x01  
};

// Configuration descriptor
static const U8 cfd[] = {
  0x09,
  0x02,
  0x20,
  0x00, 
  0x01,
  0x01, 
  0x00,
  0xC0,
  0x00,
  0x09,
  0x04,
  0x00,
  0x00,
  0x02,
  0xFF, 
  0xFF,
  0xFF,
  0x00,
  0x07, 
  0x05,
  0x01,
  0x02,
  64,
  0x00,
  0x00, 
  0x07,
  0x05,
  0x82,
  0x02,
  64,
  0x00,
  0x00};

// Serial Number Descriptor
static U8 snd[] =
{
      0x1A,           // Descriptor length
      0x03,           // Descriptor type 3 == string 
      0x31, 0x00,     // MSD of Lap (Lap[2,3]) in UNICode
      0x32, 0x00,     // Lap[4,5]
      0x33, 0x00,     // Lap[6,7]
      0x34, 0x00,     // Lap[8,9]
      0x35, 0x00,     // Lap[10,11]
      0x36, 0x00,     // Lap[12,13]
      0x37, 0x00,     // Lap[14,15]
      0x38, 0x00,     // LSD of Lap (Lap[16,17]) in UNICode
      0x30, 0x00,     // MSD of Nap (Nap[18,19]) in UNICode
      0x30, 0x00,     // LSD of Nap (Nap[20,21]) in UNICode
      0x39, 0x00,     // MSD of Uap in UNICode
      0x30, 0x00      // LSD of Uap in UNICode
};

// Name descriptor, we allow up to 16 unicode characters
static U8 named[] =
{
      0x08,           // Descriptor length
      0x03,           // Descriptor type 3 == string 
      0x6e, 0x00,     // n
      0x78, 0x00,     // x
      0x74, 0x00,     // t
      0x00, 0x00,
      0x00, 0x00,
      0x00, 0x00,
      0x00, 0x00,
      0x00, 0x00,
      0x00, 0x00,
      0x00, 0x00,
      0x00, 0x00,
      0x00, 0x00,
      0x00, 0x00,
      0x00, 0x00,
      0x00, 0x00,
      0x00, 0x00
};

static const U8 ld[] = {0x04,0x03,0x09,0x04}; // Language descriptor
      
extern void udp_isr_entry(void);


static char x4[5];
static char* hexchars = "0123456789abcdef";
  
static char *
hex4(int i)
{
  x4[0] = hexchars[(i >> 12) & 0xF];
  x4[1] = hexchars[(i >> 8) & 0xF];
  x4[2] = hexchars[(i >> 4) & 0xF];
  x4[3] = hexchars[i & 0xF];
  x4[4] = 0;
  return x4;
}

static
void
reset()
{
  // setup config state.
  currentConfig = 0;
  currentRxBank = AT91C_UDP_RX_DATA_BK0;
  configured = (configured & USB_DISABLED) | USB_READY;
  currentFeatures = 0;
  newAddress = -1;
  outCnt = 0;
  delayedEnable = 0;
}
 

int
udp_init(void)
{
  udp_disable();
  configured = (USB_DISABLED|USB_NEEDRESET);
  return 1;
}

void 
udp_reset()
{
  int i_state;

  // We must be enabled
  if (configured & USB_DISABLED) return;

  // Take the hardware off line
  *AT91C_PIOA_PER = (1 << 16);
  *AT91C_PIOA_OER = (1 << 16);
  *AT91C_PIOA_SODR = (1 << 16);
  *AT91C_PMC_SCDR = AT91C_PMC_UDP;
  *AT91C_PMC_PCDR = (1 << AT91C_ID_UDP);
  systick_wait_ms(2);
  // now bring it back online
  i_state = interrupts_get_and_disable();
  /* Make sure the USB PLL and clock are set up */
  *AT91C_CKGR_PLLR |= AT91C_CKGR_USBDIV_1;
  *AT91C_PMC_SCER = AT91C_PMC_UDP;
  *AT91C_PMC_PCER = (1 << AT91C_ID_UDP);
  *AT91C_UDP_FADDR = 0;            
  *AT91C_UDP_GLBSTATE = 0;

  /* Enable the UDP pull up by outputting a zero on PA.16 */
  *AT91C_PIOA_PER = (1 << 16);
  *AT91C_PIOA_OER = (1 << 16);
  *AT91C_PIOA_CODR = (1 << 16);
  *AT91C_UDP_IDR = ~0; 

  /* Set up default state */
  reset();


  *AT91C_UDP_IER = (AT91C_UDP_EPINT0 | AT91C_UDP_RXSUSP | AT91C_UDP_RXRSM);
  if (i_state)
    interrupts_enable(); 
}

int
udp_read(U8* buf, int off, int len)
{
  /* Perform a non-blocking read operation. We use double buffering (ping-pong)
   * operation to provide better throughput.
   */
  int packetSize = 0, i;
  
  if (len == 0) return 0;
  if ((*AT91C_UDP_CSR1) & currentRxBank) // data to read
  {
    packetSize = ((*AT91C_UDP_CSR1) & AT91C_UDP_RXBYTECNT) >> 16;
    if (packetSize > len) packetSize = len;
    // Transfer the data 
    for(i=0;i<packetSize;i++) buf[off+i] = *AT91C_UDP_FDR1;

    // Flip bank
    ENTER();
    UDP_CLEAREPFLAGS(*AT91C_UDP_CSR1, currentRxBank); 
    if (currentRxBank == AT91C_UDP_RX_DATA_BK0) {    
      currentRxBank = AT91C_UDP_RX_DATA_BK1;
    } else {
      currentRxBank = AT91C_UDP_RX_DATA_BK0;
    }
    // We may have an enable/reset pending do it now if there is no data
    // in the buffers.
    if (delayedEnable && ((*AT91C_UDP_CSR1) & AT91C_UDP_RXBYTECNT) == 0)
    {
      delayedEnable = 0;
      UDP_CLEAREPFLAGS(*AT91C_UDP_CSR1, AT91C_UDP_FORCESTALL);
      (*AT91C_UDP_RSTEP) |= AT91C_UDP_EP1;
      (*AT91C_UDP_RSTEP) &= ~AT91C_UDP_EP1;
    }
    LEAVE();

    // use special case for a real zero length packet so we can use it to
    // indicate EOF
    if (packetSize == 0) return -2;
    return packetSize;
  }
  if (configured != USB_CONFIGURED) return -1;
  return 0;
}

int
udp_write(U8* buf, int off, int len)
{
  /* Perform a non-blocking write. Return the number of bytes actually
   * written.
   */
  int i;
  
  if (configured != USB_CONFIGURED) return -1;
  // Can we write ?
  if ((*AT91C_UDP_CSR2 & AT91C_UDP_TXPKTRDY) != 0) return 0;
  // Limit to max transfer size
  if (len > MAX_BUF) len = MAX_BUF;
  for(i=0;i<len;i++) *AT91C_UDP_FDR2 = buf[off+i];
  
  ENTER();
  UDP_SETEPFLAGS(*AT91C_UDP_CSR2, AT91C_UDP_TXPKTRDY);
  UDP_CLEAREPFLAGS(*AT91C_UDP_CSR2, AT91C_UDP_TXCOMP);
  LEAVE();
  return len;
}

static
void 
udp_send_null()
{
  UDP_SETEPFLAGS(*AT91C_UDP_CSR0, AT91C_UDP_TXPKTRDY);
}

static void udp_send_stall()
{
  UDP_SETEPFLAGS(*AT91C_UDP_CSR0, AT91C_UDP_FORCESTALL); 
}

static void udp_send_control(U8* p, int len)
{
  outPtr = p;
  outCnt = len;
  int i;
  // Start sending the first part of the data...
  for(i=0;i<8 && i<outCnt;i++)
    *AT91C_UDP_FDR0 = outPtr[i];
  UDP_SETEPFLAGS(*AT91C_UDP_CSR0, AT91C_UDP_TXPKTRDY);
}
  
static
void 
udp_enumerate()
{
  U8 bt, br;
  int req, len, ind, val; 
  short status;
    //display_goto_xy(8,3);
    //display_string(hex4(*AT91C_UDP_CSR0));
    //display_goto_xy(12,3);
    //display_string("    ");
  
  // First we deal with any completion states.
  if ((*AT91C_UDP_CSR0) & AT91C_UDP_TXCOMP)
  {
    // Write operation has completed.
    // Send config data if needed. Send a zero length packet to mark the
    // end of the data if an exact multiple of 8.
    if (outCnt >= 8)
    {
      outCnt -= 8;
      outPtr += 8;
      int i;
      // Send next part of the data
      for(i=0;i<8 && i<outCnt;i++)
        *AT91C_UDP_FDR0 = outPtr[i];
      UDP_SETEPFLAGS(*AT91C_UDP_CSR0, AT91C_UDP_TXPKTRDY);
    }
    else
      outCnt = 0;
    
    
    // Clear the state
    UDP_CLEAREPFLAGS(*AT91C_UDP_CSR0, AT91C_UDP_TXCOMP);
    if (newAddress >= 0)
    {
      // Set new address
      *AT91C_UDP_FADDR = (AT91C_UDP_FEN | newAddress);            
      *AT91C_UDP_GLBSTATE  = (newAddress) ? AT91C_UDP_FADDEN : 0;
      newAddress = -1;
    }
  }
  if ((*AT91C_UDP_CSR0) & (AT91C_UDP_RX_DATA_BK0))
  {
    // Got Transfer complete ack
    // Clear the state
    UDP_CLEAREPFLAGS(*AT91C_UDP_CSR0, AT91C_UDP_RX_DATA_BK0);
  }
  if (*AT91C_UDP_CSR0 & AT91C_UDP_ISOERROR)
  {
    // Clear the state
    UDP_CLEAREPFLAGS(*AT91C_UDP_CSR0, (AT91C_UDP_ISOERROR|AT91C_UDP_FORCESTALL));
  }

    //display_goto_xy(12,3);
    //display_string("E1");

  if (!((*AT91C_UDP_CSR0) & AT91C_UDP_RXSETUP)) return;
  
  bt = *AT91C_UDP_FDR0;
  br = *AT91C_UDP_FDR0;
  
  val = ((*AT91C_UDP_FDR0 & 0xFF) | (*AT91C_UDP_FDR0 << 8));
  ind = ((*AT91C_UDP_FDR0 & 0xFF) | (*AT91C_UDP_FDR0 << 8));
  len = ((*AT91C_UDP_FDR0 & 0xFF) | (*AT91C_UDP_FDR0 << 8));
  
  if (bt & 0x80)
  {
    UDP_SETEPFLAGS(*AT91C_UDP_CSR0, AT91C_UDP_DIR); 
  }
  
  UDP_CLEAREPFLAGS(*AT91C_UDP_CSR0, AT91C_UDP_RXSETUP);

  req = br << 8 | bt;
 /* 
  if (1) {

    display_goto_xy(0,1);
    display_string(hex4(req));
    display_goto_xy(4,1);
    display_string(hex4(val));
    display_goto_xy(8,1);
    display_string(hex4(ind));
    display_goto_xy(12,1);
    display_string(hex4(len));
    display_update();
  }*/
  // If we are disabled we respond to requests with a stall
  if (configured & USB_DISABLED)
  {
    udp_send_stall();
    return;
  }
  switch(req)
  {
    case STD_GET_DESCRIPTOR: 
      if (val == 0x100) // Get device descriptor
      {
        udp_send_control((U8 *)dd, MIN(sizeof(dd), len));
      }
      else if (val == 0x200) // Configuration descriptor
      {     
        udp_send_control((U8 *)cfd, MIN(sizeof(cfd), len));
        //if (len > sizeof(cfd)) udp_send_null();
      }    
      else if ((val & 0xF00) == 0x300)
      {
        switch(val & 0xFF)
        {
          case 0x00:
            udp_send_control((U8 *)ld, MIN(sizeof(ld), len));
            break;
          case 0x01:
            udp_send_control(snd, MIN(sizeof(snd), len));
            break;
          default:
            udp_send_stall();
        }
      }  
      else
      {
        udp_send_stall();
      }
      break;
        
    case STD_SET_ADDRESS:
      newAddress = val;
      udp_send_null();
      break;
        
    case STD_SET_CONFIGURATION:

      currentConfig = val;
      if (val)
      {
        configured = USB_CONFIGURED;
        *AT91C_UDP_GLBSTATE  = AT91C_UDP_CONFG;
        delayedEnable = 0;
        // Make sure we are not stalled
        UDP_CLEAREPFLAGS(*AT91C_UDP_CSR1, AT91C_UDP_FORCESTALL);
        UDP_CLEAREPFLAGS(*AT91C_UDP_CSR2, AT91C_UDP_FORCESTALL);
        UDP_CLEAREPFLAGS(*AT91C_UDP_CSR3, AT91C_UDP_FORCESTALL);
        // Now enable the endpoints
        UDP_SETEPFLAGS(*AT91C_UDP_CSR1, (AT91C_UDP_EPEDS | AT91C_UDP_EPTYPE_BULK_OUT));
        UDP_SETEPFLAGS(*AT91C_UDP_CSR2, (AT91C_UDP_EPEDS | AT91C_UDP_EPTYPE_BULK_IN));
        UDP_SETEPFLAGS(*AT91C_UDP_CSR3, AT91C_UDP_EPTYPE_INT_IN);
        // and reset them...
        (*AT91C_UDP_RSTEP) |= (AT91C_UDP_EP1|AT91C_UDP_EP2|AT91C_UDP_EP3);
        (*AT91C_UDP_RSTEP) &= ~(AT91C_UDP_EP1|AT91C_UDP_EP2|AT91C_UDP_EP3);
      }
      else
      {
        configured = USB_READY;
        *AT91C_UDP_GLBSTATE  = AT91C_UDP_FADDEN;
        delayedEnable = 0;
        UDP_CLEAREPFLAGS(*AT91C_UDP_CSR1, AT91C_UDP_EPEDS|AT91C_UDP_FORCESTALL);
        UDP_CLEAREPFLAGS(*AT91C_UDP_CSR2, AT91C_UDP_EPEDS|AT91C_UDP_FORCESTALL);
        *AT91C_UDP_CSR3 = 0;
      }
      udp_send_null(); 
      
      break;
      
    case STD_SET_FEATURE_ENDPOINT:

      ind &= 0x0F;

      if ((val == 0) && ind && (ind <= 3))
      {
        switch (ind)
        {
          case 1:
            UDP_SETEPFLAGS(*AT91C_UDP_CSR1, AT91C_UDP_FORCESTALL);
            delayedEnable = 0;
            break;
          case 2:   
            UDP_SETEPFLAGS(*AT91C_UDP_CSR2, AT91C_UDP_FORCESTALL);
            break;
          case 3:   
            UDP_SETEPFLAGS(*AT91C_UDP_CSR3, AT91C_UDP_FORCESTALL);
            break;
        }
        udp_send_null();
      }
      else udp_send_stall();
      break;

    case STD_CLEAR_FEATURE_ENDPOINT:
      ind &= 0x0F;

      if ((val == 0) && ind && (ind <= 3))
      {
        // Enable and reset the end point
        int res = 0;
        switch (ind)
        {
          case 1:
            // We need to take special care for the input end point because
            // we may have data in the hardware buffer. If we do then the reset
            // will cause this to be lost. To prevent this loss we delay the
            // enable until the data has been read.
            if ((*AT91C_UDP_CSR1) & currentRxBank) 
            {
              UDP_SETEPFLAGS(*AT91C_UDP_CSR1, AT91C_UDP_FORCESTALL);
              delayedEnable = 1;
            }
            else
            {
              UDP_CLEAREPFLAGS(*AT91C_UDP_CSR1, AT91C_UDP_FORCESTALL);
              delayedEnable = 0;
              res = AT91C_UDP_EP1;
            }
            break;
          case 2:   
            UDP_CLEAREPFLAGS(*AT91C_UDP_CSR2, AT91C_UDP_FORCESTALL);
            res = AT91C_UDP_EP2;
            break;
          case 3:   
            UDP_CLEAREPFLAGS(*AT91C_UDP_CSR3, AT91C_UDP_FORCESTALL);
            res = AT91C_UDP_EP3;
            break;
        }
        (*AT91C_UDP_RSTEP) |= res;
        (*AT91C_UDP_RSTEP) &= ~res;
        udp_send_null();
      }
      else udp_send_stall();

      break;
      
    case STD_GET_CONFIGURATION:                                   

      udp_send_control((U8 *) &(currentConfig), MIN(sizeof(currentConfig), len));
      break;

    case STD_GET_STATUS_ZERO:
    
      status = 0x01; 
      udp_send_control((U8 *) &status, MIN(sizeof(status), len));
      break;
      
    case STD_GET_STATUS_INTERFACE:

      status = 0;
      udp_send_control((U8 *) &status, MIN(sizeof(status), len));
      break;

    case STD_GET_STATUS_ENDPOINT:

      status = 0;
      ind &= 0x0F;

      if (((*AT91C_UDP_GLBSTATE) & AT91C_UDP_CONFG) && (ind <= 3)) 
      {
        switch (ind)
        {
          case 1: 
            status = ((*AT91C_UDP_CSR1) & AT91C_UDP_FORCESTALL) ? 1 : 0; 
            break;
          case 2: 
            status = ((*AT91C_UDP_CSR2) & AT91C_UDP_FORCESTALL) ? 1 : 0; 
            break;
          case 3: 
            status = ((*AT91C_UDP_CSR3) & AT91C_UDP_FORCESTALL) ? 1 : 0; 
            break;
        }
        udp_send_control((U8 *) &status, MIN(sizeof(status), len));
      }
      else if (((*AT91C_UDP_GLBSTATE) & AT91C_UDP_FADDEN) && (ind == 0))
      {
        status = ((*AT91C_UDP_CSR0) & AT91C_UDP_EPEDS) ? 0 : 1;
        udp_send_control((U8 *) &status, MIN(sizeof(status), len));
      }
      else udp_send_stall();                                // Illegal request :-(

      break;
      
    case VENDOR_SET_FEATURE_INTERFACE:
      ind &= 0xf;
      currentFeatures |= (1 << ind);
      udp_send_null();
      break;
    case VENDOR_CLEAR_FEATURE_INTERFACE:
      ind &= 0xf;
      currentFeatures &= ~(1 << ind);
      udp_send_null();
      break;
    case VENDOR_GET_DESCRIPTOR:
      udp_send_control((U8 *)named, MIN(named[0], len));
      break;
 
    case STD_SET_FEATURE_INTERFACE:
    case STD_CLEAR_FEATURE_INTERFACE:
      udp_send_null();
      break;
    case STD_SET_INTERFACE:     
    case STD_SET_FEATURE_ZERO:
    case STD_CLEAR_FEATURE_ZERO:
    default:
      udp_send_stall();
  } 
    //display_goto_xy(14,3);
    //display_string("E2");
}

void udp_isr_C_function(void)
{
  /* Process interrupts. We mainly use these during the configuration and
   * enumeration stages.
   */
/*display_goto_xy(0,3);
display_string(hex4(*AT91C_UDP_ISR));
display_goto_xy(4,3);
display_string(hex4(intCnt++));*/

  if (*AT91C_UDP_ISR & END_OF_BUS_RESET) 
  { 
    //display_goto_xy(0,2);
    //display_string("Bus Reset     ");
    //display_update();
    *AT91C_UDP_ICR = END_OF_BUS_RESET;          
    *AT91C_UDP_ICR = SUSPEND_RESUME;      
    *AT91C_UDP_ICR = WAKEUP;              
    *AT91C_UDP_RSTEP = 0xFFFFFFFF;
    *AT91C_UDP_RSTEP = 0x0; 
    *AT91C_UDP_FADDR = AT91C_UDP_FEN;    
    reset();
    UDP_SETEPFLAGS(*AT91C_UDP_CSR0,(AT91C_UDP_EPEDS | AT91C_UDP_EPTYPE_CTRL)); 
    *AT91C_UDP_IER = (AT91C_UDP_EPINT0 | AT91C_UDP_RXSUSP | AT91C_UDP_RXRSM);
    //display_goto_xy(12,2);
    //display_string("IE1");
    return;
  }
  if (*AT91C_UDP_ISR & SUSPEND_INT)
  {
    //display_goto_xy(0,2);
    //display_string("Suspend      ");
    //display_update();
    if ((configured & ~USB_DISABLED) == USB_CONFIGURED)
      configured = (configured & USB_DISABLED) | USB_SUSPENDED;
    else
      configured = (configured & USB_DISABLED) | USB_READY;
    *AT91C_UDP_ICR = SUSPEND_INT;
    currentRxBank = AT91C_UDP_RX_DATA_BK0;
  }
  if (*AT91C_UDP_ISR & SUSPEND_RESUME)
  {
    //display_goto_xy(0,2);
    //display_string("Resume     ");
    //display_update();
    if ((configured & ~USB_DISABLED) == USB_SUSPENDED)
      configured = (configured & USB_DISABLED) | USB_CONFIGURED;
    else
      configured = (configured & USB_DISABLED) | USB_READY;
    *AT91C_UDP_ICR = WAKEUP;
    *AT91C_UDP_ICR = SUSPEND_RESUME;
  }
  if (*AT91C_UDP_ISR & AT91C_UDP_EPINT0)
  {
    //display_goto_xy(0,2);
    //display_string("Data       ");
    //display_update();
    *AT91C_UDP_ICR = AT91C_UDP_EPINT0; 
    udp_enumerate();                    
  } 
    //display_goto_xy(12,2);
    //display_string("IE2");
}

int
udp_status()
{
  /* Return the current status of the USB connection. This information
   * can be used to determine if the connection can be used. We return
   * the connected state, the currently selected configuration and
   * the currenly active features. This latter item is used by co-operating
   * software on the PC and nxt to indicate the start and end of a stream
   * connection.
   */
  int ret = (configured << 28) | (currentConfig << 24) | (currentFeatures & 0xffff);

  if (configured == USB_CONFIGURED)
  {
    if ((*AT91C_UDP_CSR1) & currentRxBank) ret |= USB_READABLE;
    if ((*AT91C_UDP_CSR2 & AT91C_UDP_TXPKTRDY) == 0) ret |= USB_WRITEABLE;
  }
  return ret;
}

extern void tpl_primary_irq_handler(void);

void
udp_enable(int reset)
{
  /* Enable the processing of USB requests. */
  /* Initialise the interrupt handler. We use a very low priority becuase
   * some of the USB operations can run for a relatively long time...
   */
  if (reset & 0x2)
  {
#if REMOTE_CONSOLE
    rConsole = 1;
    printf("Firmware output enabled\n");
#endif
    return;
  }
    
  int i_state = interrupts_get_and_disable();
  aic_mask_off(AT91C_PERIPHERAL_ID_UDP);
  aic_set_vector(AT91C_PERIPHERAL_ID_UDP, AIC_INT_LEVEL_LOWEST,
          (U32) tpl_primary_irq_handler);//(U32) udp_isr_entry);
  aic_mask_on(AT91C_PERIPHERAL_ID_UDP);
  *AT91C_UDP_IER = (AT91C_UDP_EPINT0 | AT91C_UDP_RXSUSP | AT91C_UDP_RXRSM);
  reset = reset || (configured & USB_NEEDRESET);
  configured &= ~USB_DISABLED;
  if (i_state)
    interrupts_enable(); 
  if (reset)
    udp_reset();
}

void
udp_disable()
{
  /* Disable processing of USB requests */
  U8 buf[MAX_BUF];
  // Discard any input
  while (udp_read(buf, 0, sizeof(buf)) > 0)
    ;
  int i_state = interrupts_get_and_disable();
  configured |= USB_DISABLED;
  currentFeatures = 0;
  if (i_state)
    interrupts_enable(); 
#if REMOTE_CONSOLE
  rConsole = 0;
#endif
}

void
udp_set_serialno(U8 *serNo, int len)
{
  /* Set the USB serial number. serNo should point to a 12 character
   * Unicode string, containing the USB serial number.
   */
  if (len == (sizeof(snd)-2)/2)
    memcpy(snd+2, serNo, len*2);
}

void
udp_set_name(U8 *name, int len)
{
  if (len <= (sizeof(named)-2)/2)
  {
    memcpy(named+2, name, len*2);
    named[0] = len*2 + 2;
  } 
}


#if REMOTE_CONSOLE
void
udp_rconsole(U8 *buf, int cnt)
{
  if (!rConsole) return;
  while (udp_write(buf, 0, cnt) == 0)
    ;
}
#endif
