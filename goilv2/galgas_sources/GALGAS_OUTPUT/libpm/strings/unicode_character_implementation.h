//-----------------------------------------------------------------------------*
//                                                                             *
//  unicode_character : an implementation of Unicode character               *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2008, ..., 2010 Pierre Molinaro.                             *
//                                                                             *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
//                                                                             *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes  *
//  ECN, École Centrale de Nantes (France)                                     *
//                                                                             *
//  This library is free software; you can redistribute it and/or modify it    *
//  under the terms of the GNU Lesser General Public License as published      *
//  by the Free Software Foundation; either version 2 of the License, or       *
//  (at your option) any later version.                                        *
//                                                                             *
//  This program is distributed in the hope it will be useful, but WITHOUT     *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or      *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for   *
//  more details.                                                              *
//                                                                             *
//-----------------------------------------------------------------------------*

const utf32 UNICODE_REPLACEMENT_CHARACTER = TO_UNICODE (0x0000FFFD) ;
const utf32 UNICODE_MAX_LEGAL_UTF32_CHARACTER = TO_UNICODE (0x0010FFFF) ;

//-----------------------------------------------------------------------------*

bool isUnicodeCharacterAssigned (const utf32 inUnicodeCharacter) {
  bool result = UNICODE_VALUE (inUnicodeCharacter) <= UNICODE_VALUE (UNICODE_MAX_LEGAL_UTF32_CHARACTER) ;
  if (result) {
    const PMUInt32 pageIndex = UNICODE_VALUE (inUnicodeCharacter) / gNamePageSize ;
    if (pageIndex <= gLastNamePage) {
      const PMUInt32 * page = gNamePages [pageIndex] ;
      if (page != NULL) {
        const PMUInt32 entry = page [UNICODE_VALUE (inUnicodeCharacter) % gNamePageSize] ;
        result = entry != 0 ;
      }
    }
  }
  return result ;
}

//-----------------------------------------------------------------------------*
// Each entry is a sequence of uint values. The two significant bits encode
// the meaning of the entry:
//  - 00xx xxx : shift accumulator left 6 bits,
//               then or it with xxxxxx;
//  - 01xx xxx : shift accumulator left 6 bits,
//               then or it with xxxxxx,
//               write name at accumulator index,
//               write one space,
//               set accumultor to zero;
//  - 10xx xxx : shift accumulator left 6 bits,
//               then or it with xxxxxx,
//               write name at accumulator index,
//               write one '-' character,
//               set accumultor to zero;
//  - 11xx xxx : shift accumulator left 6 bits,
//               then or it with xxxxxx,
//               write name at accumulator index,
//               EXIT.

#ifdef __cplusplus
  C_String unicodeName (const utf32 inUnicodeCharacter) {
    C_String result ;
    if (! isUnicodeCharacterAssigned (inUnicodeCharacter)) {
      result << "invalid unicode character \\U" ;
      result.appendUnsignedHex8 (UNICODE_VALUE (inUnicodeCharacter)) ;
    }else{
      const PMUInt32 pageIndex = UNICODE_VALUE (inUnicodeCharacter) / gNamePageSize ;
      if (pageIndex <= gLastNamePage) {
        const PMUInt32 * page = gNamePages [pageIndex] ;
        if (page != NULL) {
          PMUInt32 entry = page [UNICODE_VALUE (inUnicodeCharacter) % gNamePageSize] & kNameMask ;
          bool completed = entry == 0 ;
          PMUInt32 idx = 0 ;
          while (! completed) {
            const PMUInt8 nameCode = gPartNameConstruction [entry] ;
            entry ++ ;
            idx = (idx << 6) | (nameCode & 0x3F) ;
            switch (nameCode & 0xC0) {
            case 0 : // Prefix
              break ;
            case 0x40 : // Enter name, append space character
              result << gPartNames [idx] << " " ;
              idx = 0 ;
              break ;
            case 0x80 : // Enter name, append minus character
              result << gPartNames [idx] << "-" ;
              idx = 0 ;
              break ;
            default : // Enter name, exit
              result << gPartNames [idx] ;
              completed = true ;
              break ;
            }
          }
        }
      }
      if (result.length () == 0) {
        if (UNICODE_VALUE (inUnicodeCharacter) < 0x10000) {
          result << "\\u" ;
          result.appendUnsignedHex4 (UNICODE_VALUE (inUnicodeCharacter)) ;
        }else{
          result << "\\U" ;
          result.appendUnsignedHex8 (UNICODE_VALUE (inUnicodeCharacter)) ;
        }
      }
    } 
    return result ;
  }
#endif

//-----------------------------------------------------------------------------*

#ifdef __OBJC__
  NSString * unicodeName (const utf32 inUnicodeCharacter) {
    NSMutableString * result = [NSMutableString new] ;
    if (! isUnicodeCharacterAssigned (inUnicodeCharacter)) {
      [result appendFormat:@"invalid unicode character \\U%u", UNICODE_VALUE (inUnicodeCharacter)] ;
    }else{
      const PMUInt32 pageIndex = UNICODE_VALUE (inUnicodeCharacter) / gNamePageSize ;
      if (pageIndex <= gLastNamePage) {
        const PMUInt32 * page = gNamePages [pageIndex] ;
        if (page != NULL) {
          PMUInt32 entry = page [UNICODE_VALUE (inUnicodeCharacter) % gNamePageSize] & kNameMask ;
          bool completed = entry == 0 ;
          PMUInt32 idx = 0 ;
          while (! completed) {
            const PMUInt8 nameCode = gPartNameConstruction [entry] ;
            entry ++ ;
            idx = (idx << 6) | (nameCode & 0x3F) ;
            switch (nameCode & 0xC0) {
            case 0 : // Prefix
              break ;
            case 0x40 : // Enter name, append space character
              [result appendFormat:@"%s ", gPartNames [idx]] ;
              idx = 0 ;
              break ;
            case 0x80 : // Enter name, append minus character
              [result appendFormat:@"%s-", gPartNames [idx]] ;
              idx = 0 ;
              break ;
            default : // Enter name, exit
              [result appendFormat:@"%s", gPartNames [idx]] ;
              completed = true ;
              break ;
            }
          }
        }
      }
      if ([result length] == 0) {
        if (UNICODE_VALUE (inUnicodeCharacter) < 0x10000) {
          [result appendFormat:@"\\u%04X", UNICODE_VALUE (inUnicodeCharacter)] ;
        }else{
          [result appendFormat:@"\\U%08X", UNICODE_VALUE (inUnicodeCharacter)] ;
        }
      }
    } 
    return result ;
  }
#endif

//-----------------------------------------------------------------------------*

utf32 unicodeToLower (const utf32 inUnicodeCharacter) {
  utf32 result = inUnicodeCharacter ;
  const PMUInt32 pageIndex = UNICODE_VALUE (inUnicodeCharacter) / gToLowerPageSize ;
  if (pageIndex <= gLastToLowerPage) {
    const PMUInt32 * page = gToLowerPages [pageIndex] ;
    if (page != NULL) {
      const PMUInt32 entry = page [UNICODE_VALUE (inUnicodeCharacter) % gToLowerPageSize] ;
      if (entry != 0) {
        result = TO_UNICODE (entry) ;
      }
    }
  } 
  return result ;
}

//-----------------------------------------------------------------------------*

utf32 unicodeToUpper (const utf32 inUnicodeCharacter) {
  utf32 result = inUnicodeCharacter ;
  // printf ("U+%X", inUnicodeCharacter) ;
  const PMUInt32 pageIndex = UNICODE_VALUE (inUnicodeCharacter) / gToUpperPageSize ;
  // printf (", pageIndex %u, lastPage %u", pageIndex, gLastToUpperPage) ;
  if (pageIndex <= gLastToUpperPage) {
    const PMUInt32 * page = gToUpperPages [pageIndex] ;
    if (page != NULL) {
      // printf (", index %u", inUnicodeCharacter % gToUpperPageSize) ;
      const PMUInt32 entry = page [UNICODE_VALUE (inUnicodeCharacter) % gToUpperPageSize] ;
      // printf (", entry 0x%X", entry) ;
      if (entry != 0) {
        result = TO_UNICODE (entry) ;
      }
    }
  }
  // printf ("\n") ;
  return result ;
}

//-----------------------------------------------------------------------------*

bool isUnicodeLetter (const utf32 inUnicodeCharacter) {
  bool result = false ;
  const PMUInt32 pageIndex = UNICODE_VALUE (inUnicodeCharacter) / gNamePageSize ;
  if (pageIndex <= gLastNamePage) {
    const PMUInt32 * page = gNamePages [pageIndex] ;
    if (page != NULL) {
      const PMUInt32 entry = page [UNICODE_VALUE (inUnicodeCharacter) % gNamePageSize] ;
      if (entry != 0) {
        const PMUInt32 category = entry >> 27 ;
        result = (category >= kUnicodeCategory_Lu) && (category <= kUnicodeCategory_Lo) ;
      }
    }
  } 
  return result ;
}

//-----------------------------------------------------------------------------*

bool isUnicodeMark (const utf32 inUnicodeCharacter) {
  bool result = false ;
  const PMUInt32 pageIndex = UNICODE_VALUE (inUnicodeCharacter) / gNamePageSize ;
  if (pageIndex <= gLastNamePage) {
    const PMUInt32 * page = gNamePages [pageIndex] ;
    if (page != NULL) {
      const PMUInt32 entry = page [UNICODE_VALUE (inUnicodeCharacter) % gNamePageSize] ;
      if (entry != 0) {
        const PMUInt32 category = entry >> 27 ;
        result = (category >= kUnicodeCategory_Mn) && (category <= kUnicodeCategory_Me) ;
      }
    }
  } 
  return result ;
}

//-----------------------------------------------------------------------------*

bool isUnicodeNumber (const utf32 inUnicodeCharacter) {
  bool result = false ;
  const PMUInt32 pageIndex = UNICODE_VALUE (inUnicodeCharacter) / gNamePageSize ;
  if (pageIndex <= gLastNamePage) {
    const PMUInt32 * page = gNamePages [pageIndex] ;
    if (page != NULL) {
      const PMUInt32 entry = page [UNICODE_VALUE (inUnicodeCharacter) % gNamePageSize] ;
      if (entry != 0) {
        const PMUInt32 category = entry >> 27 ;
        result = (category >= kUnicodeCategory_Nd) && (category <= kUnicodeCategory_No) ;
      }
    }
  } 
  return result ;
}

//-----------------------------------------------------------------------------*

bool isUnicodeDecimalDigit (const utf32 inUnicodeCharacter) {
  bool result = false ;
  const PMUInt32 pageIndex = UNICODE_VALUE (inUnicodeCharacter) / gNamePageSize ;
  if (pageIndex <= gLastNamePage) {
    const PMUInt32 * page = gNamePages [pageIndex] ;
    if (page != NULL) {
      const PMUInt32 entry = page [UNICODE_VALUE (inUnicodeCharacter) % gNamePageSize] ;
      if (entry != 0) {
        const PMUInt32 category = entry >> 27 ;
        result = category == kUnicodeCategory_Nd ;
      }
    }
  } 
  return result ;
}

//-----------------------------------------------------------------------------*

PMUInt32 unicodeDecimalValue (const utf32 inUnicodeCharacter) {
  PMUInt32 result = 0 ;
  const PMUInt32 pageIndex = UNICODE_VALUE (inUnicodeCharacter) / gNamePageSize ;
  if (pageIndex <= gLastNamePage) {
    const PMUInt32 * page = gNamePages [pageIndex] ;
    if (page != NULL) {
      const PMUInt32 entry = page [UNICODE_VALUE (inUnicodeCharacter) % gNamePageSize] ;
      if (entry != 0) {
        if ((entry >> 27) == kUnicodeCategory_Nd) {
          result = (entry >> 16) & 0xF ;
        }
      }
    }
  } 
  return result ;
}

//-----------------------------------------------------------------------------*

bool isUnicodeASCIIHexDigit (const utf32 inUnicodeCharacter) {
  return
     ((UNICODE_VALUE (inUnicodeCharacter) >= '0') && (UNICODE_VALUE (inUnicodeCharacter) <= '9'))
  || ((UNICODE_VALUE (inUnicodeCharacter) >= 'A') && (UNICODE_VALUE (inUnicodeCharacter) <= 'F'))
  || ((UNICODE_VALUE (inUnicodeCharacter) >= 'a') && (UNICODE_VALUE (inUnicodeCharacter) <= 'f'))
  ;
}

//-----------------------------------------------------------------------------*

PMUInt32 ASCIIHexValue (const utf32 inUnicodeCharacter) {
  PMUInt32 result = 0 ;
  if ((UNICODE_VALUE (inUnicodeCharacter) >= '0') && (UNICODE_VALUE (inUnicodeCharacter) <= '9')) {
    result = UNICODE_VALUE (inUnicodeCharacter) - '0' ;
  }else if ((UNICODE_VALUE (inUnicodeCharacter) >= 'A') && (UNICODE_VALUE (inUnicodeCharacter) <= 'F')) {
    result = UNICODE_VALUE (inUnicodeCharacter) - 'A' + 10 ;
  }else if ((UNICODE_VALUE (inUnicodeCharacter) >= 'a') && (UNICODE_VALUE (inUnicodeCharacter) <= 'f')) {
    result = UNICODE_VALUE (inUnicodeCharacter) - 'a' + 10 ;
  }
  return result  ;
}

//-----------------------------------------------------------------------------*

bool isUnicodeSeparator (const utf32 inUnicodeCharacter) {
  bool result = false ;
  const PMUInt32 pageIndex = UNICODE_VALUE (inUnicodeCharacter) / gNamePageSize ;
  if (pageIndex <= gLastNamePage) {
    const PMUInt32 * page = gNamePages [pageIndex] ;
    if (page != NULL) {
      const PMUInt32 entry = page [UNICODE_VALUE (inUnicodeCharacter) % gNamePageSize] ;
      if (entry != 0) {
        const PMUInt32 category = entry >> 27 ;
        result = (category >= kUnicodeCategory_Zs) && (category <= kUnicodeCategory_Zp) ;
      }
    }
  } 
  return result ;
}

//-----------------------------------------------------------------------------*

bool isUnicodeCommand (const utf32 inUnicodeCharacter) {
  bool result = true ; // Undefined character has 'Cn' category
  const PMUInt32 pageIndex = UNICODE_VALUE (inUnicodeCharacter) / gNamePageSize ;
  if (pageIndex <= gLastNamePage) {
    const PMUInt32 * page = gNamePages [pageIndex] ;
    if (page != NULL) {
      const PMUInt32 entry = page [UNICODE_VALUE (inUnicodeCharacter) % gNamePageSize] ;
      if (entry != 0) {
        const PMUInt32 category = entry >> 27 ;
        result = (category >= kUnicodeCategory_Cc) && (category <= kUnicodeCategory_Co) ;
      }
    }
  } 
  return result ;
}

//-----------------------------------------------------------------------------*

bool isUnicodePunctuation (const utf32 inUnicodeCharacter) {
  bool result = false ;
  const PMUInt32 pageIndex = UNICODE_VALUE (inUnicodeCharacter) / gNamePageSize ;
  if (pageIndex <= gLastNamePage) {
    const PMUInt32 * page = gNamePages [pageIndex] ;
    if (page != NULL) {
      const PMUInt32 entry = page [UNICODE_VALUE (inUnicodeCharacter) % gNamePageSize] ;
      if (entry != 0) {
        const PMUInt32 category = entry >> 27 ;
        result = (category >= kUnicodeCategory_Pc) && (category <= kUnicodeCategory_Po) ;
      }
    }
  } 
  return result ;
}

//-----------------------------------------------------------------------------*

bool isUnicodeSymbol (const utf32 inUnicodeCharacter) {
  bool result = false ;
  const PMUInt32 pageIndex = UNICODE_VALUE (inUnicodeCharacter) / gNamePageSize ;
  if (pageIndex <= gLastNamePage) {
    const PMUInt32 * page = gNamePages [pageIndex] ;
    if (page != NULL) {
      const PMUInt32 entry = page [UNICODE_VALUE (inUnicodeCharacter) % gNamePageSize] ;
      if (entry != 0) {
        const PMUInt32 category = entry >> 27 ;
        result = (category >= kUnicodeCategory_Sm) && (category <= kUnicodeCategory_So) ;
      }
    }
  } 
  return result ;
}

//-----------------------------------------------------------------------------*

#ifdef __cplusplus
  utf32 unicodeCharacterFromHTMLSequence (const C_String & inString) {
    utf32 result = TO_UNICODE (0) ; // Means not found
    PMSInt32 lowIndex = 0 ;
    PMSInt32 highIndex = kHTMLtoUnicodeConversionTableSize - 1 ;
    while ((highIndex >= lowIndex) && (UNICODE_VALUE (result) == 0)) {
      const PMSInt32 newIndex = (highIndex + lowIndex) / 2 ;
      const PMSInt32 c = inString.compare (kHTMLtoUnicodeConversionArray [newIndex].mDefinition) ;
      if (c > 0) {
        lowIndex = newIndex + 1 ;
      }else if (c < 0) {
        highIndex = newIndex - 1 ;
      }else{
        result = TO_UNICODE (kHTMLtoUnicodeConversionArray [newIndex].mUnicodeCharacter) ;
      }  
    }
    return result ;
  }
#endif

//-----------------------------------------------------------------------------*

#ifdef __OBJC__
  utf32 unicodeCharacterFromHTMLSequence (NSString * inString) {
    utf32 result = TO_UNICODE (0) ; // Means not found
    PMSInt32 lowIndex = 0 ;
    PMSInt32 highIndex = kHTMLtoUnicodeConversionTableSize - 1 ;
    while ((highIndex >= lowIndex) && (UNICODE_VALUE (result) == 0)) {
      const PMSInt32 newIndex = (highIndex + lowIndex) / 2 ;
      const NSInteger c = [inString compare:[NSString stringWithCString:kHTMLtoUnicodeCocoaConversionArray [newIndex].mDefinition encoding:NSASCIIStringEncoding]] ;
      if (c > 0) {
        lowIndex = newIndex + 1 ;
      }else if (c < 0) {
        highIndex = newIndex - 1 ;
      }else{
        result = TO_UNICODE (kHTMLtoUnicodeCocoaConversionArray [newIndex].mUnicodeCharacter) ;
      }  
    }
    return result ;
  }
#endif

//-----------------------------------------------------------------------------*
//                                                                             *
//   S T R I N G    E N C O D I N G S    T A B L E S                         *
//                                                                             *
//-----------------------------------------------------------------------------*

typedef struct {
  const char * mCodeName ;
  const structConvertFromUnicodeEntry * mMappingFromUnicode ;
  const PMUInt32 mMappingFromUnicodeSize ;
  const PMUInt16 * mMappingToUnicode ;
} unicodeMappingDescriptorType ;

//-----------------------------------------------------------------------------*

#define kMappingDescriptorsSize (18)

//-----------------------------------------------------------------------------*

static const unicodeMappingDescriptorType kMappingDescriptors [kMappingDescriptorsSize] = {
  {"ISO 8859-1", gMappingFromUnicodeTo_8859_1, gMappingFromUnicodeTo_8859_1_count, gMappingFrom_8859_1_ToUnicode},
  {"ISO 8859-2", gMappingFromUnicodeTo_8859_2, gMappingFromUnicodeTo_8859_2_count, gMappingFrom_8859_2_ToUnicode},
  {"ISO 8859-3", gMappingFromUnicodeTo_8859_3, gMappingFromUnicodeTo_8859_3_count, gMappingFrom_8859_3_ToUnicode},
  {"ISO 8859-4", gMappingFromUnicodeTo_8859_4, gMappingFromUnicodeTo_8859_4_count, gMappingFrom_8859_4_ToUnicode},
  {"ISO 8859-5", gMappingFromUnicodeTo_8859_5, gMappingFromUnicodeTo_8859_5_count, gMappingFrom_8859_5_ToUnicode},
  {"ISO 8859-6", gMappingFromUnicodeTo_8859_6, gMappingFromUnicodeTo_8859_6_count, gMappingFrom_8859_6_ToUnicode},
  {"ISO 8859-7", gMappingFromUnicodeTo_8859_7, gMappingFromUnicodeTo_8859_7_count, gMappingFrom_8859_7_ToUnicode},
  {"ISO 8859-8", gMappingFromUnicodeTo_8859_8, gMappingFromUnicodeTo_8859_8_count, gMappingFrom_8859_8_ToUnicode},
  {"ISO 8859-9", gMappingFromUnicodeTo_8859_9, gMappingFromUnicodeTo_8859_9_count, gMappingFrom_8859_9_ToUnicode},
  {"ISO 8859-10", gMappingFromUnicodeTo_8859_10, gMappingFromUnicodeTo_8859_10_count, gMappingFrom_8859_10_ToUnicode},
  {"ISO 8859-11", gMappingFromUnicodeTo_8859_11, gMappingFromUnicodeTo_8859_11_count, gMappingFrom_8859_11_ToUnicode},
  {"ISO 8859-13", gMappingFromUnicodeTo_8859_13, gMappingFromUnicodeTo_8859_13_count, gMappingFrom_8859_13_ToUnicode},
  {"ISO 8859-14", gMappingFromUnicodeTo_8859_14, gMappingFromUnicodeTo_8859_14_count, gMappingFrom_8859_14_ToUnicode},
  {"ISO 8859-15", gMappingFromUnicodeTo_8859_15, gMappingFromUnicodeTo_8859_15_count, gMappingFrom_8859_15_ToUnicode},
  {"ISO 8859-16", gMappingFromUnicodeTo_8859_16, gMappingFromUnicodeTo_8859_16_count, gMappingFrom_8859_16_ToUnicode},
  {"CP 1252", gMappingFromUnicodeTo_CP1252, gMappingFromUnicodeTo_CP1252_count, gMappingFrom_CP1252_ToUnicode},
  {"CP 437 (DOS)", gMappingFromUnicodeTo_CP437, gMappingFromUnicodeTo_CP437_count, gMappingFrom_CP437_ToUnicode},
  {"Mac Roman", gMappingFromUnicodeTo_ROMAN, gMappingFromUnicodeTo_ROMAN_count, gMappingFrom_ROMAN_ToUnicode}
} ;

//-----------------------------------------------------------------------------*

utf32 unicodeCharacterForSingleByteCharacter (const char inChar, const PMStringEncoding inStringEncoding) {
  const unsigned short c = (unsigned short) (((unsigned short) inChar) & 0x00FFU) ;
  utf32 result = UNICODE_REPLACEMENT_CHARACTER ;
  if ((c & 0x80) == 0) {
    result = TO_UNICODE (c) ;
  }
  if (((PMUInt32) inStringEncoding) < kMappingDescriptorsSize) {
    result = TO_UNICODE (kMappingDescriptors [inStringEncoding].mMappingToUnicode [c - 128]) ;
  }
  return result ;
}

//-----------------------------------------------------------------------------*

char singleByteCharacterForUnicodeCharacter (const utf32 inUnicodeChar,
                                             const PMStringEncoding inStringEncoding) {
 char result = '\0' ;
 // printf ("unicode 0x%X\n", inUnicodeChar) ;
 if (UNICODE_VALUE (inUnicodeChar) < 128) {
   result = (char) (UNICODE_VALUE (inUnicodeChar) & 255) ;
 }else if (((PMUInt32) inStringEncoding) < kMappingDescriptorsSize) {
   PMUInt32 low = 0 ;
   PMUInt32 high = kMappingDescriptors [inStringEncoding].mMappingFromUnicodeSize ;
   const structConvertFromUnicodeEntry * mapping = kMappingDescriptors [inStringEncoding].mMappingFromUnicode ;
   while ((low <= high) && (result == 0)) {
     const PMUInt32 mid = (low + high) / 2 ;
    // printf ("<%u, %u> mid %u unicode 0x%X\n", low, high, mid, mapping [mid].mUnicode) ;
     if (UNICODE_VALUE (inUnicodeChar) > mapping [mid].mUnicode) {
       low = mid + 1 ;
     }else if (UNICODE_VALUE (inUnicodeChar) < mapping [mid].mUnicode) {
       high = mid - 1 ;
     }else{ // Found
       // printf ("found") ;
       result = mapping [mid].mSingleByteCode ;
     }
   }
 }
 if (result == '\0') {
   result = '?' ; // Default character
 }
 return result ;
}

//-----------------------------------------------------------------------------*
// From:
//   http://www.unicode.org/Public/PROGRAMS/CVTUTF/ConvertUTF.c
//   http://github.com/lloyd/yajl/blob/d55329340828a736777056f49afd21cb67e2b6b8/src/yajl_encode.c
//--- UTF8 encoding
// 0000 0000  0000 0000  0xxx xxxx -> 0xxx xxxx
// 0000 0000  0000 0yyy  xxxx xxxx -> 110y yyxx  10xx xxxx
// 0000 0000  zzzz yyyy  xxxx xxxx -> 1110 zzzz  10yy yyxx  10xx xxxx
// 000u uuuu  zzzz yyyy  xxxx xxxx -> 1111 0uuu  10uu zzzz  10yy yyxx  10xx xxxx

PMSInt32 UTF8StringFromUTF32Character (const utf32 inUnicodeChar, char outSequence [5]) {
  PMUInt32 codePoint = UNICODE_VALUE (inUnicodeChar) ;
  if (codePoint > UNICODE_VALUE (UNICODE_MAX_LEGAL_UTF32_CHARACTER)) {
    codePoint = UNICODE_VALUE (UNICODE_REPLACEMENT_CHARACTER) ;
  }
  PMSInt32 resultByteCount = 0 ;
  if (codePoint < 0x80) {
    outSequence [0] = (char) (codePoint & 255) ;
    outSequence [1] = 0 ;
    resultByteCount = 1 ;
  }else if (codePoint < 0x0800) {
    outSequence [0] = (char) (((codePoint >> 6) | 0xC0) & 255) ;
    outSequence [1] = (char) ((codePoint & 0x3F) | 0x80) ;
    outSequence [2] = 0 ;
    resultByteCount = 2 ;
  }else if (codePoint < 0x10000) {
    outSequence [0] = (char) (((codePoint >> 12) | 0xE0) & 255) ;
    outSequence [1] = (char) (((codePoint >> 6) & 0x3F) | 0x80) ;
    outSequence [2] = (char) ((codePoint & 0x3F) | 0x80) ;
    outSequence [3] = 0 ;
    resultByteCount = 3 ;
  }else{
    outSequence [0] = (char) (((codePoint >> 18) | 0xF0) & 255) ;
    outSequence [1] = (char) (((codePoint >> 12) & 0x3F) | 0x80) ;
    outSequence [2] = (char) (((codePoint >> 6) & 0x3F) | 0x80) ;
    outSequence [3] = (char) ((codePoint & 0x3F) | 0x80) ;
    outSequence [4] = 0 ;
    resultByteCount = 4 ;
  }
  
  /*printf ("TO_UNICODE (0x%X) 0x%X ->", UNICODE_VALUE (inUnicodeChar), codePoint) ;
  for (PMSInt32 i=0 ; i<resultByteCount ; i++) {
    printf (" 0x%02X", outSequence [i] & 0xFF) ;
  }
  printf ("\n") ;*/
  return resultByteCount ;
}

//--- UTF8 encoding
// 0000 0000  0000 0000  0xxx xxxx -> 0xxx xxxx
// 0000 0000  0000 0yyy  xxxx xxxx -> 110y yyxx  10xx xxxx
// 0000 0000  zzzz yyyy  xxxx xxxx -> 1110 zzzz  10yy yyxx  10xx xxxx
// 000u uuuu  zzzz yyyy  xxxx xxxx -> 1111 0uuu  10uu zzzz  10yy yyxx  10xx xxxx
//-----------------------------------------------------------------------------*

#ifdef __cplusplus
  utf32 utf32CharacterForPointer (const PMUInt8 * inDataString,
                                  PMSInt32 & ioIndex,
                                  const PMSInt32 inLength,
                                  bool & ioOK) {
    PMUInt32 result = 0 ;
    PMUInt32 c = inDataString [ioIndex] ;
    ioIndex ++ ;
    ioOK = true ;
    if ((c & 0x80) == 0) {
      result = c ;
    }else if ((c & 0xE0) == 0xC0) {
      result = c & 0x1F ;
      result <<= 6 ;
      c = inDataString [ioIndex] ;
      ioOK = ((c & 0xC0) == 0x80) && (ioIndex < inLength) ;
      if (ioOK) {
        ioIndex ++ ;
        result |= c & 0x3F ;
      }
    }else if ((c & 0xF0) == 0xE0) {
      result = c & 0x0F ;
      result <<= 12 ;
      c = inDataString [ioIndex] ;
      ioOK = ((c & 0xC0) == 0x80) && (ioIndex < inLength) ;
      if (ioOK) {
        ioIndex ++ ;
        result |= (c & 0x3F) << 6 ;
        c = inDataString [ioIndex] ;
        if (ioOK) {
          ioOK &= ((c & 0xC0) == 0x80) && (ioIndex < inLength) ;
          ioIndex ++ ;
          result |= c & 0x3F ;
        }
      }
    }else if ((c & 0xF8) == 0xF0) {
      result = (c & 0x07) << 18 ;
      c = inDataString [ioIndex] ;
      ioOK = ((c & 0xC0) == 0x80) && (ioIndex < inLength) ;
      if (ioOK) {
        ioIndex ++ ;
        result |= (c & 0x3F) << 12 ;
        c = inDataString [ioIndex] ;
        ioOK = ((c & 0xC0) == 0x80) && (ioIndex < inLength) ;
        if (ioOK) {
          ioIndex ++ ;
          result |= (c & 0x3F) << 6 ;
          c = inDataString [ioIndex] ;
          ioOK = ((c & 0xC0) == 0x80) && (ioIndex < inLength) ;
          if (ioOK) {
            ioIndex ++ ;
            result |= c & 0x3F ;
          }
        }
      }
    }else{
      ioOK = false ;
    }
    if (! ioOK) {
      result = UNICODE_VALUE (UNICODE_REPLACEMENT_CHARACTER) ;
    }
    // printf ("UTF8 -> TO_UNICODE 0x%X (%d), ok %d\n", result, result, ioOK) ;
    return TO_UNICODE (result) ;
  }
#endif

//-----------------------------------------------------------------------------*
