/**
 * @file tpl_ecn.c
 *
 * @section File description
 *
 * functions to access various I/O of the TP-ECN board
 *
 * forked from Pierre Molinaro code
 *
 * @section File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tp_ecn.h"
#include "lpc22xx.h"
#include "check-lpc2200-timing-settings.h"

//-------------------------------------------------------------------------*
// Sortie 0 : S3 -> P0.17
// Sortie 1 : S2 -> P0.10
// Sortie 2 : S1 -> P0.12
// Sortie 3 : S0 -> P0.13

FUNC(void, OS_CODE) led_off(CONST(uint32, AUTOMATIC) inValue)
{
  if ((inValue & 8) != 0) {
    IO1CLR = (1 << 20) ;
  }
  if ((inValue & 4) != 0) {
    IO1CLR = (1 << 24) ;
  }
  if ((inValue & 2) != 0) {
    IO1CLR = (1 << 21) ;
  }
  if ((inValue & 1) != 0) {
    IO1CLR = (1 << 22) ;
  }
}

//-------------------------------------------------------------------------*

FUNC(void, OS_CODE) led_on(CONST(uint32, AUTOMATIC) inValue) {
  if ((inValue & 8) != 0) {
    IO1SET = (1 << 20) ;
  }
  if ((inValue & 4) != 0) {
    IO1SET = (1 << 24) ;
  }
  if ((inValue & 2) != 0) {
    IO1SET = (1 << 21) ;
  }
  if ((inValue & 1) != 0) {
    IO1SET = (1 << 22) ;
  }
}

uint32 current_state = 0;

//-------------------------------------------------------------------------*

FUNC(uint32, OS_CODE) push_button(void) {
  if (U1LSR & (0x01 == 0x01)) {
    current_state = U1RBR;
  }
  return current_state;
}

//-------------------------------------------------------------------------*
// P1.16 à P1.19 : commutateur rotatif

FUNC(uint32, OS_CODE) rotary_switch (void) {
  const uint32 port = IO1PIN ;
  uint32 v = 0 ;
  if ((port & (1 << 17)) == 0) {
    v = 1 ;
  }
  if ((port & (1 << 16)) == 0) {
    v |= 2 ;
  }
  if ((port & (1 << 19)) == 0) {
    v |= 4 ;
  }
  if ((port & (1 << 18)) == 0) {
    v |= 8 ;
  }
  return v ;
}

//-------------------------------------------------------------------------*
// INTER0 : E3 -> P0.16
// INTER1 : E2 -> P1.25
// INTER2 : E1 -> P0.15
// INTER3 : E0 -> P0.20

FUNC(uint32, OS_CODE) switcher(void) {
  const uint32 port0 = IO0PIN ;
  uint32 v = 0 ;
  if ((port0 & (1 << 20)) != 0) {
    v = 8 ;
  }
  if ((port0 & (1 << 15)) != 0) {
    v |= 4 ;
  }
  if ((IO1PIN & (1 << 25)) != 0) {
    v |= 2 ;
  }
  if ((port0 & (1 << 16)) != 0) {
    v |= 1 ;
  }
  return v ;
}

FUNC(void, OS_CODE) open_serial_1 (CONST(uint32, AUTOMATIC) inBaudRate) {
//--- Disable UART1 interrupt
  U1IER = 0 ;
//--- 1. Set DLAB=1 in UART1_LCR(for accessing to UART1_DLL)
  U1LCR = 0x80 ;
//--- 2. Set baud rate by writing values to registers UART1_DLL and UART1_DLM
  const uint32 SETTING_VALUE = (PCLK / (16 * inBaudRate)) ;
  U1DLM = SETTING_VALUE >> 8 ;
  U1DLL = SETTING_VALUE & 255 ;
//--- 3. Program UART1_LCR
// Bit 7 : 0 (Disable access to Divisor Latches)
// Bit 6 : 0 (Disable break transmission)
// Bits 5-4 : 00 (any value, parity is not enabled)
// Bit 3 : 0 (Disable parity generation and checking)
// Bit 2 : 0 (1 stop bit)
// Bits 1-0 : 11 (8 bit character length)
  U1LCR = 0x03 ;
//--- 4. UART FIFO (UART1_FCR)
// Bit 7-6 : 00 (1 received character triggers interrupt)
// Bits 5-3 : 000 (reserved)
// Bit 2 : 0 (no action on TX FIFO)
// Bit 1 : 0 (no action on RX FIFO)
// Bit 0 : 0->1 (clears TX and RX FIFO, and enables them)
  U1FCR = 0 ;
  U1FCR = 0x01 ;
//--- 5. Select PIN for beeing TXB1 and RXB1
//  Bits 17-16 : 01 (P0.8 is TxD for UART1)
//  Bits 19-18 : 01 (P0.9 is RxD for UART1)
  PINSEL0 &= ~ 0xF0000 ;
  PINSEL0 |=   0x50000 ;
}

FUNC(void, OS_CODE) envoyer_caractere_serie1 (CONST(char, AUTOMATIC) inCaractere) {
//--- Attendre que le buffer d'émission ne soit plus plein
  while ((U1LSR & 0x20) == 0) {} // Wait for transmission buffer empty
//--- Send
  U1THR = inCaractere ; // Transmit Character
}


#define USER_MODE_
#define MODE_

//-------------------------------------------------------------------------*

void lcd_goto_line_column (USER_MODE_ const uint32 inLine, const uint32 inColumn) {
  const uint32 line = (inLine < 3) ? inLine : 3 ;
  const uint32 colonne = (inColumn < 19) ? inColumn : 19 ;
  const uint32 commande = 0x80 + (line * 20) + colonne ;
  envoyer_caractere_serie1 (MODE_ commande) ;
}

//-------------------------------------------------------------------------*

void lcd_backlight (USER_MODE_ const uint8 inBacklightOn) {
  envoyer_caractere_serie1 (MODE_ 0xD0 + inBacklightOn) ;
}

//-------------------------------------------------------------------------*

void lcd_print_char (USER_MODE_ const char inChar) {
  envoyer_caractere_serie1 (MODE_ inChar) ;
}

//-------------------------------------------------------------------------*

void lcd_print_string (USER_MODE_ const char * inChaine) {
  const char * p = inChaine ;
  while ((* p) != '\0') {
    envoyer_caractere_serie1 (MODE_ * p) ;
    p ++ ;
  }
}

//-------------------------------------------------------------------------*

void lcd_init (void) {
  envoyer_caractere_serie1 (MODE_ 0xD2) ;
  envoyer_caractere_serie1 (MODE_ 0xD1) ; // Backlight ON
}

//-------------------------------------------------------------------------*

void lcd_print_hex1 (USER_MODE_ const uint8 inValue) {
  const uint8 v = inValue & 0x0F ;
  if (v <= 9) {
    envoyer_caractere_serie1 (MODE_ v + '0') ;
  }else{
    envoyer_caractere_serie1 (MODE_ v + 'A' - 10) ;
  }
}

//-------------------------------------------------------------------------*

void lcd_print_unsigned (USER_MODE_ const uint32 inValue) {
  if (inValue <= 9) {
    envoyer_caractere_serie1 (MODE_ inValue + '0') ;
  }else{
    lcd_print_unsigned (MODE_ inValue / 10) ;
    envoyer_caractere_serie1 (MODE_ (inValue % 10) + '0') ;
  }
}

//-------------------------------------------------------------------------*

void lcd_print_unsigned_with_leading_spaces (USER_MODE_ 
                                             const uint32 inValue,
                                             const uint32 inDisplayWidth) {
  uint32 v = inValue ;
  uint32 digits = 1 ;
  while (v > 9) {
    v /= 10 ;
    digits ++ ;
  }
  while (digits < inDisplayWidth) {
    envoyer_caractere_serie1 (MODE_ ' ') ;
    digits ++ ;
  }
  lcd_print_unsigned (MODE_ inValue) ;
}

//-------------------------------------------------------------------------*

void lcd_print_signed (USER_MODE_ const sint32 inValue) {
  if (inValue >= 0) {
    lcd_print_unsigned (MODE_ inValue) ;
  }else{
    envoyer_caractere_serie1 (MODE_ '-') ;
    lcd_print_unsigned (MODE_ - inValue) ;
  }
}

//-------------------------------------------------------------------------*

void lcd_print_signed_with_leading_spaces (USER_MODE_ 
                                           const sint32 inValue,
                                           const uint32 inDisplayWidth) {

  sint32 v = inValue ;
  uint32 digits = 1 ;
  if (v < 0) {
    v = - v ;
    digits ++ ;
  }
  while (v > 9) {
    v /= 10 ;
    digits ++ ;
  }
  while (digits < inDisplayWidth) {
    envoyer_caractere_serie1 (MODE_ ' ') ;
    digits ++ ;
  }
  lcd_print_signed (MODE_ inValue) ;
}

//-------------------------------------------------------------------------*

void lcd_print_hex2 (USER_MODE_ const uint8 inValue) {
  lcd_print_hex1 (MODE_ inValue >> 4) ;
  lcd_print_hex1 (MODE_ inValue) ;
}

//-------------------------------------------------------------------------*

void lcd_print_hex4 (USER_MODE_ const uint16 inValue) {
  lcd_print_hex2 (MODE_ inValue >> 8) ;
  lcd_print_hex2 (MODE_ inValue) ;
}

//-------------------------------------------------------------------------*

void lcd_print_hex8 (USER_MODE_ const uint32 inValue) {
  lcd_print_hex4 (MODE_ inValue >> 16) ;
  lcd_print_hex4 (MODE_ inValue) ;
}

//-------------------------------------------------------------------------*

void lcd_print_spaces (USER_MODE_ const uint32 inSpaceCount) {
  uint32 spaceCount = inSpaceCount ;
  while (spaceCount > 0) {
    envoyer_caractere_serie1 (MODE_ ' ') ;
    spaceCount -- ;
  }
}

//---------------------------------------------------------------------------*
