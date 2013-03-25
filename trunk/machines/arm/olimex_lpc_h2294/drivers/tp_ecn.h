/**
 * @file tpl_ecn.c
 *
 * @section File description
 *
 * header of functions to access various I/O of the TP-ECN board
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

#ifndef TP_ECN_H
#define TP_ECN_H

#include "tpl_compiler.h"
#include "processor-defines.h"

/* Led defines */

#define S0 8
#define S1 4
#define S2 2
#define S3 1

#define F0 8
#define F1 4
#define F2 2
#define F3 1

FUNC(void, OS_CODE) led_off(CONST(uint32, AUTOMATIC) inValue);
FUNC(void, OS_CODE) led_on(CONST(uint32, AUTOMATIC) inValue);
FUNC(uint32, OS_CODE) push_button(void);
FUNC(uint32, OS_CODE) rotary_switch(void);
FUNC(uint32, OS_CODE) switcher(void);
FUNC(void, OS_CODE) lcd_goto_line_column(
  CONST(uint32, AUTOMATIC) inLine,
  CONST(uint32, AUTOMATIC) inColumn);
FUNC(void, OS_CODE) lcd_backlight(CONST(uint8, AUTOMATIC) inBacklightOn);
FUNC(void, OS_CODE) lcd_print_char(CONST(char, AUTOMATIC) inChar);
FUNC(void, OS_CODE) lcd_print_string(
  CONSTP2CONST(char, AUTOMATIC, OS_APPL_DATA) inChaine);
FUNC(void, OS_CODE) lcd_init(void);
FUNC(void, OS_CODE) lcd_print_hex1(CONST(uint8, AUTOMATIC) inValue);
FUNC(void, OS_CODE) lcd_print_unsigned(CONST(uint32, AUTOMATIC) inValue);
FUNC(void, OS_CODE) lcd_print_unsigned_with_leading_spaces(
  CONST(uint32, AUTOMATIC) inValue,
  CONST(uint32, AUTOMATIC) inDisplayWidth);
FUNC(void, OS_CODE) lcd_print_signed(CONST(sint32, AUTOMATIC) inValue);
FUNC(void, OS_CODE) lcd_print_signed_with_leading_spaces (
  CONST(sint32, AUTOMATIC) inValue,
  CONST(uint32, AUTOMATIC) inDisplayWidth);
FUNC(void, OS_CODE) lcd_print_hex2(CONST(uint8, AUTOMATIC) inValue);
FUNC(void, OS_CODE) lcd_print_hex4(CONST(uint16, AUTOMATIC) inValue);
FUNC(void, OS_CODE) lcd_print_hex8(CONST(uint32, AUTOMATIC) inValue);
FUNC(void, OS_CODE) lcd_print_spaces(CONST(uint32, AUTOMATIC) inSpaceCount);

#endif