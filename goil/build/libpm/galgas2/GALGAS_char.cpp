//--------------------------------------------------------------------------------------------------
//
//   GALGAS_char                                                                                 
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2002, ..., 2016 Pierre Molinaro.
//
//  e-mail : pierre@pcmolinaro.name
//
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)
//  any later version.
//
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//  more details.
//
//--------------------------------------------------------------------------------------------------

#include "all-predefined-types.h"
#include "Compiler.h"
#include "unicode_character_cpp.h"

//--------------------------------------------------------------------------------------------------

#include <ctype.h>

//--------------------------------------------------------------------------------------------------

#if COMPILE_FOR_WINDOWS == 0
  #include <termios.h>
  #include <string.h>
  #include <unistd.h>
  #include <sys/ioctl.h>
#endif

//--------------------------------------------------------------------------------------------------

GALGAS_char::GALGAS_char (void) :
AC_GALGAS_root (),
mIsValid (false),
mCharValue (TO_UNICODE (0)) {
}

//--------------------------------------------------------------------------------------------------

#if (COMPILE_FOR_WINDOWS == 1) || defined(__CYGWIN__)
  GALGAS_char GALGAS_char::class_func_unicodeCharacterFromRawKeyboard (Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
    inCompiler->onTheFlyRunTimeError (
      "@char unicodeCharacterFromRawKeyboard constructor is not implemented for Windows"
      COMMA_THERE
    ) ;
    return GALGAS_char () ; // Poison value
  }
#else
  static void waitForRawInput (void) {
    bool waiting = true ;
    while (waiting) {
      int bytesAvailable = 0 ;
      ioctl (STDIN_FILENO, FIONREAD, & bytesAvailable) ;
      waiting = bytesAvailable == 0 ;
      if (waiting) {
        usleep (10000) ; // 10 ms
      }
    }
  }

  GALGAS_char GALGAS_char::class_func_unicodeCharacterFromRawKeyboard (Compiler * /* inCompiler */
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  //--- Save current configuration
    struct termios termios_orig ;
    tcgetattr (STDIN_FILENO, &termios_orig) ;
  //--- Set new configuration
    struct termios raw ;
    tcgetattr (STDIN_FILENO, &raw) ;
    cfmakeraw (& raw) ;
    raw.c_oflag = OPOST | OCRNL ;
    raw.c_iflag = 0 ;
    raw.c_lflag = ISIG ;
    tcsetattr (STDIN_FILENO, TCSANOW, & raw);
  //--- Wait for input character
    waitForRawInput () ;
  //--- Get character
    uint8_t c = '\0' ;
    ssize_t unusedResult __attribute__ ((unused)) = read (STDIN_FILENO, & c, 1) ;
  //--- ASCII ?
    uint32_t unicodeChar = c ;
    if ((unicodeChar & 0xE0) == 0xC0) { // 2 bytes
      unicodeChar &= 0x1F ;
      unicodeChar <<= 6 ;
      waitForRawInput () ;
      unusedResult = read (STDIN_FILENO, & c, 1) ;
      c &= 0x3F ;
      unicodeChar |= c ;
    }else if ((unicodeChar & 0xF0) == 0xE0) { // 3 bytes
      unicodeChar &= 0x0F ;
      unicodeChar <<= 6 ;
      waitForRawInput () ;
      unusedResult = read (STDIN_FILENO, & c, 1) ;
      c &= 0x3F ;
      unicodeChar |= c ;
      unicodeChar <<= 6 ;
      waitForRawInput () ;
      unusedResult = read (STDIN_FILENO, & c, 1) ;
      c &= 0x3F ;
      unicodeChar |= c ;
    }else if ((unicodeChar & 0xF8) == 0xF0) { // 4 bytes
      unicodeChar &= 0x0F ;
      unicodeChar <<= 6 ;
      waitForRawInput () ;
      unusedResult = read (STDIN_FILENO, & c, 1) ;
      c &= 0x3F ;
      unicodeChar |= c ;
      unicodeChar <<= 6 ;
      waitForRawInput () ;
      unusedResult = read (STDIN_FILENO, & c, 1) ;
      c &= 0x3F ;
      unicodeChar |= c ;
      unicodeChar <<= 6 ;
      waitForRawInput () ;
      unusedResult = read (STDIN_FILENO, & c, 1) ;
      c &= 0x3F ;
      unicodeChar |= c ;
    }
  //--- Restore configuration
    tcsetattr (STDIN_FILENO, TCSANOW, &termios_orig) ;
  //--- Return input character
    return GALGAS_char (TO_UNICODE (unicodeChar)) ;
  }
#endif

//--------------------------------------------------------------------------------------------------

GALGAS_char::GALGAS_char (const utf32 inValue) :
AC_GALGAS_root (),
mIsValid (true),
mCharValue (inValue) {
}

//--------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_char::objectCompare (const GALGAS_char & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t r = ((int32_t) UNICODE_VALUE (mCharValue)) - ((int32_t) UNICODE_VALUE (inOperand.mCharValue)) ;
    if (r < 0) {
      result = kFirstOperandLowerThanSecond ;
    }else if (r > 0) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = kOperandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_char::description (String & ioString,
                               const int32_t /* inIndentation */) const {
  ioString.appendCString ("<@char:") ;
  if (isValid ()) {
    if (isprint ((int) UNICODE_VALUE (mCharValue))) {
      ioString.appendCString ("'") ;
      ioString.appendChar (mCharValue) ;
      ioString.appendCString ("'") ;
    }else{
      ioString.appendString (unicodeName (mCharValue)) ;
    }
  }else{
    ioString.appendCString ("not built") ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_char::getter_string (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    String s ;
    s.appendChar (mCharValue) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_char::getter_utf_33__32_CharConstantRepresentation (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    String s ;
    s.appendCString ("TO_UNICODE (") ;
    s.appendStringAsCLiteralCharConstant (mCharValue) ;
    s.appendCString (")") ;
    result = GALGAS_string (s) ;
  }
  return result ;

}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_char::getter_uint (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint (UNICODE_VALUE (mCharValue)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_char::getter_isalnum (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (
        ((UNICODE_VALUE (mCharValue) >= '0') && (UNICODE_VALUE (mCharValue) <= '9'))
     || ((UNICODE_VALUE (mCharValue) >= 'a') && (UNICODE_VALUE (mCharValue) <= 'z'))
     || ((UNICODE_VALUE (mCharValue) >= 'A') && (UNICODE_VALUE (mCharValue) <= 'Z'))
    ) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_char::getter_isalpha (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (((UNICODE_VALUE (mCharValue) >= 'a') && (UNICODE_VALUE (mCharValue) <= 'z'))
                               || ((UNICODE_VALUE (mCharValue) >= 'A') && (UNICODE_VALUE (mCharValue) <= 'Z'))) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_char::getter_iscntrl (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (((UNICODE_VALUE (mCharValue) >= 1) && (UNICODE_VALUE (mCharValue) <= 31)) || (UNICODE_VALUE (mCharValue) == 127)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_char::getter_isdigit (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool  (((UNICODE_VALUE (mCharValue) >= '0') && (UNICODE_VALUE (mCharValue) <= '9'))) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_char::getter_islower (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (((UNICODE_VALUE (mCharValue) >= 'a') && (UNICODE_VALUE (mCharValue) <= 'z'))) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_char::getter_isupper (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (((UNICODE_VALUE (mCharValue) >= 'A') && (UNICODE_VALUE (mCharValue) <= 'Z'))) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_char::getter_isxdigit (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (((UNICODE_VALUE (mCharValue) >= '0') && (UNICODE_VALUE (mCharValue) <= '9'))
                               || ((UNICODE_VALUE (mCharValue) >= 'a') && (UNICODE_VALUE (mCharValue) <= 'f'))
                               || ((UNICODE_VALUE (mCharValue) >= 'A') && (UNICODE_VALUE (mCharValue) <= 'F'))) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_char::getter_isUnicodeLetter (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (isUnicodeLetter (mCharValue)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_char::getter_isUnicodeMark (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (isUnicodeMark  (mCharValue)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_char::getter_isUnicodeSymbol (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (isUnicodeCommand (mCharValue)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_char::getter_isUnicodeCommand (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (isUnicodeCommand (mCharValue)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_char::getter_isUnicodeSeparator (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (isUnicodeSeparator (mCharValue)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_char::getter_isUnicodePunctuation (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (isUnicodePunctuation (mCharValue)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_char::getter_isUnicodeNumber (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (isUnicodeNumber (mCharValue)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_char::getter_unicodeName (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    result = GALGAS_string (unicodeName (mCharValue)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_char GALGAS_char::getter_unicodeToLower (UNUSED_LOCATION_ARGS) const {
  GALGAS_char result ;
  if (isValid ()) {
    result = GALGAS_char (unicodeToLower (mCharValue)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_char GALGAS_char::getter_unicodeToUpper (UNUSED_LOCATION_ARGS) const {
  GALGAS_char result ;
  if (isValid ()) {
    result = GALGAS_char (unicodeToUpper (mCharValue)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_char::getter_utf_38_Length (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint (utf8Length (mCharValue)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_char GALGAS_char::class_func_unicodeCharacterWithUnsigned (const GALGAS_uint & inValue
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_char result ;
  if (inValue.isValid ()) {
    result = GALGAS_char (TO_UNICODE (inValue.uintValue ())) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_char GALGAS_char::class_func_replacementCharacter (UNUSED_LOCATION_ARGS) {
  return GALGAS_char (UNICODE_REPLACEMENT_CHARACTER) ;
}

//--------------------------------------------------------------------------------------------------
