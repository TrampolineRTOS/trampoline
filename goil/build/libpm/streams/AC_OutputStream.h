//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  AC_OutputStream : an abstract output stream class                                                                  *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 1997, ..., 2015 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes, ECN, École Centrale de Nantes (France)  *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef CLASS_OUTPUT_STREAM_DEFINED
#define CLASS_OUTPUT_STREAM_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "utilities/MF_Assert.h"
#include "utilities/M_machine.h"
#include "strings/string_encodings.h"

//---------------------------------------------------------------------------------------------------------------------*

class C_String ;

//---------------------------------------------------------------------------------------------------------------------*

class AC_OutputStream {
//--- Default constructor
  protected : AC_OutputStream (void) ;

//--- Virtual destructor 
  public : virtual ~AC_OutputStream (void) ;

//--- Appending string
  public : void appendString (const C_String inString) ; // Pass by copy (for handling 's.appendString (s) ;' instruction)
  public : void appendUTF32LiteralStringConstant (const C_String & inUTF32String) ;

//--- Appending C string
  public : void appendCString (const char * inCstring) ;
  public : void appendCString (const char * inCstring, const int32_t inCount) ;

//--- Appending UTF32 string
  public : void appendUTF32String (const utf32 * inUTF32String) ;

//--- Appending character
  public : void appendUnicodeCharacter (const utf32 inUnicodeCharacter COMMA_LOCATION_ARGS) ;

//--- Appending uint64_t in Hex
  public : void appendUnsignedHex  (const uint64_t inValue) ;
  public : void appendUnsignedHex2 (const uint64_t inValue) ;
  public : void appendUnsignedHex4 (const uint64_t inValue) ;
  public : void appendUnsignedHex8 (const uint64_t inValue) ;

//--- Appending uint64_t
  public : void appendUnsignedWithZeroFill (const uint64_t inValue, const uint32_t inWidth) ;
  public : void appendUnsigned (const uint64_t inValue) ;
  public : void appendUnsignedHex16 (const uint64_t inValue) ;

//--- Appending Sint64
  public : void appendSigned (const int64_t inValue) ;

//--- Appending Double
  public : void appendDouble (const double inValue) ;

//--- Appending bool ("true" or"false")
  public : void appendBool (const bool inValue) ;

//--- Appending Pointer value (in hex)
  public : void appendPointer (const void * inValue) ;

//--- Output Stream
  public : AC_OutputStream & operator << (const char * inCstring) ;
  public : AC_OutputStream & operator << (const C_String inString) ; // Pass by copy (for handling 's << s ;' instruction)
  public : AC_OutputStream & operator << (const utf32 * inUTF32String) ;

//--- Flush print (does nothing for this class)
  public : virtual void flush (void) ;

//--- Abstract method for output single byte characters
  public : void genericCharArrayOutput (const char * inCharArray, const int32_t inArrayCount) ;

  protected : virtual void
  performActualCharArrayOutput (const char * inCharArray, const int32_t inArrayCount) = 0 ;

//--- Abstract method for output unicode characters
  public : void genericUnicodeArrayOutput (const utf32 * inCharArray, const int32_t inArrayCount) ;

  protected : virtual void
  performActualUnicodeArrayOutput (const utf32 * inCharArray, const int32_t inArrayCount) = 0 ;

//--- Writing spaces
  public : void appendSpaces (const int32_t inSpaceCount) ;

//--- Writing a string several times
  public : void writeStringMultiple (const C_String & inString, const int32_t inRepeatCount) ;

//--- Methods for writing comment
  public : void appendTitleComment (const C_String & inLineCommentPrefix,
                                    const C_String & inCommentString) ;
  public : void appendHyphenLineCommentWithoutExtraBlankLine (const C_String & inLineCommentPrefix) ;
  public : void appendCppHyphenLineComment (const C_String & inLineCommentPrefix) ;
  public : void appendSpaceLineComment (const C_String & inLineCommentPrefix) ;
  public : void appendCenterJustifiedComment (const C_String & inLineCommentPrefix,
                                              const C_String & inCommentString) ;
  public : void appendComment (const C_String & inLineCommentPrefix,
                               const C_String & inCommentString) ;
  public : void appendFileHeaderComment (const C_String & inLineCommentPrefix,
                                         const C_String & inTitle,
                                         const C_String & in_generatedBy_subtitle,
                                         const bool inIncludeLGPLtext) ;

//--- Methods for writing C and C++ code
  public : void appendCLiteralStringConstant (const C_String & inString, const int32_t inLineMaxLength) ;
  public : void appendCLiteralStringConstant (const C_String & inCstring) ;
  public : void appendCLiteralCharConstant (const utf32 c) ;
  public : void appendCLiteralStringConstantWithoutDelimiters (const C_String & inCstring) ;

//--- Writing C++ Comments (// ...)
  public : void appendCppTitleComment (const C_String & inCommentString) ;
  public : void appendCppTitleComment (const char * inCommentString) ;
  public : void appendCppHyphenLineCommentWithoutExtraBlankLine (void) ;
  public : void appendCppHyphenLineComment (void) ;
  public : void appendCppSpaceLineComment (void) ;
  public : void appendCppCenterJustifiedComment (const C_String & inCommentString) ;
  public : void appendCppComment (const C_String & inCommentString) ;

//--- Writing C Comments (/* ... */)
  public : void append_C_HyphenLineComment (void) ;
  public : void append_C_SpaceLineComment (void) ;
  
//--- Handle indentation
  public : void incIndentation (const int32_t inIncrement) {
    mIndentation += inIncrement ;
  }
  public : int32_t indentation (void) const {
    return mIndentation ;
  }

//--- Private data
  private : int32_t mIndentation ;
  private : bool mStartingLine ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

C_String cStringWithUnsigned (const uint64_t inValue) ;

//---------------------------------------------------------------------------------------------------------------------*

C_String cHexStringWithUnsigned (const uint64_t inValue) ;

//---------------------------------------------------------------------------------------------------------------------*

C_String cStringWithSigned (const int64_t inValue) ;

//---------------------------------------------------------------------------------------------------------------------*

C_String cStringWithPointer (const void * inValue) ;

//---------------------------------------------------------------------------------------------------------------------*

C_String cStringWithCharacter (const char inValue) ;

//---------------------------------------------------------------------------------------------------------------------*

C_String cStringWithUnicodeCharacter (const utf32 inValue) ;

//---------------------------------------------------------------------------------------------------------------------*

C_String cStringWithDouble (const double inValue) ;

//---------------------------------------------------------------------------------------------------------------------*

#endif
