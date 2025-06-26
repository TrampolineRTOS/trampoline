//                                           
//  MIT License
//                                           
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software
// and associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
// BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//                                           
//--------------------------------------------------------------------------------------------------

#include "BigUnsigned.h"

//--------------------------------------------------------------------------------------------------

void BigUnsigned::printHex (const char * inName) const {
  if (isZero ()) {
    printf ("%s: 0\n", inName) ;
  }else{
    printf ("%s: [%" PRIu64 "] 0x", inName, uint64_t (u64Count ())) ;
    for (size_t i = u64Count () ; i > 0 ; i--) {
      printf ("_%016" PRIX64, u64AtIndex (i-1)) ;
    }
    printf ("\n") ;
  }
}

//--------------------------------------------------------------------------------------------------

String BigUnsigned::decimalString (void) const {
  String result ;
  if (isZero ()) {
    result = "0" ;
  }else{
    BigUnsigned number = *this ;
    TC_UniqueArray <ChunkUInt> decimalValueArray ;
    while (!number.isZero ()) {
      const ChunkUInt divisor = greatestPowerOf10 ;
      const BigUnsignedQuotientU64Remainder r = number.dividingByChunkUInt (divisor) ;
      decimalValueArray.appendObject (r.remainder ()) ;
      number = r.quotient () ;
    }
    const int32_t n = decimalValueArray.count () ;
    result.appendUnsigned (decimalValueArray (n - 1 COMMA_HERE)) ;
    char s [32] ;
    for (int32_t i = n - 1 ; i > 0 ; i--) {
      const uint64_t v = decimalValueArray (i-1 COMMA_HERE) ;
      snprintf (s, 32, "%0*" PRIu64, int (greatestPowerOf10DigitCount), v) ;
      result.appendString (s) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

String BigUnsigned::spacedDecimalString (const uint32_t inSeparation) const {
  String result = decimalString () ;
  if (inSeparation > 0) {
    for (int32_t i = result.length () - int32_t (inSeparation) ; i > 0 ; i -= int32_t (inSeparation)) {
      result.insertCharacterAtIndex (' ', i COMMA_HERE) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

String BigUnsigned::spacedDecimalStringWithDigitCount (const uint32_t inSeparation) const {
  String s = decimalString () ;
  const int32_t length = s.length () ;
  if (inSeparation > 0) {
    for (int32_t i = s.length () - int32_t (inSeparation) ; i > 0 ; i -= int32_t (inSeparation)) {
      s.insertCharacterAtIndex (' ', i COMMA_HERE) ;
    }
  }
  String result = "[" ;
  result.appendSigned (length) ;
  result.appendCString ("] ") ;
  result.appendString (s) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

String BigUnsigned::hexString (void) const {
  String result ;
  if (u64Count () == 0) {
    result = "0" ;
  }else{
    result = "0x" ;
    result.appendUnsignedHex (u64AtIndex (u64Count () - 1)) ;
    for (size_t i = u64Count () - 1 ; i > 0 ; i--) {
      result.appendUnsignedHex16 (u64AtIndex (i - 1)) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

String BigUnsigned::xString (void) const {
  String result ;
  if (u64Count () == 0) {
    result = "0" ;
  }else{
    result.appendUnsignedHex (u64AtIndex (u64Count () - 1)) ;
    for (size_t i = u64Count () - 1 ; i > 0 ; i--) {
      result.appendUnsignedHex16 (u64AtIndex (i - 1)) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

String BigUnsigned::bitString (void) const {
  String result ;
  if (u64Count () == 0) {
    result = "0" ;
  }else{
    for (size_t i = u64Count () ; i > 0 ; i--) {
      uint64_t v = u64AtIndex (i-1) ;
      for (size_t bit = 0 ; bit < 64 ; bit++) {
        result.appendString (((v & (uint64_t (1) << 63)) != 0) ? "1" : "0") ;
        v = (v & (UINT64_MAX >> 1)) << 1 ;
      }
    }
    while ((result.length () > 0) && (result.charAtIndex (0 COMMA_HERE) == '0')) {
      result.removeCountFromIndex (1, 0 COMMA_HERE) ; // Remove first character
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void BigUnsigned::extractBytesForUnsignedRepresentation (TC_UniqueArray <uint8_t> & outValue) const {
  outValue.removeAll () ;
  const size_t n = u8Count () ;
  if (n == 0) {
    outValue.appendObject (0) ;
  }else{
    for (size_t i = 0 ; i < n ; i++) {
      const uint8_t v = u8AtIndex (i) ;
      outValue.appendObject (v) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------
