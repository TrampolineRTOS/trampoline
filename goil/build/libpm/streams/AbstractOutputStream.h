//--------------------------------------------------------------------------------------------------
//
//  AbstractOutputStream : an abstract output stream class                                            
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 1997, ..., 2023 Pierre Molinaro.
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

#pragma once

//--------------------------------------------------------------------------------------------------

#include "macroAssert.h"
#include "M_machine.h"
#include "string_encodings.h"

//--------------------------------------------------------------------------------------------------

#include <initializer_list>

//--------------------------------------------------------------------------------------------------

class String ;

//--------------------------------------------------------------------------------------------------

class AbstractOutputStream {
//--- Default constructor
  protected: AbstractOutputStream (void) ;

//--- Virtual destructor 
  public: virtual ~ AbstractOutputStream (void) ;

//--- Appending end od line
  public: void appendNewLine (void) ;

//--- Appending string
  public: void appendString (const String inString) ; // Pass by copy (for handling 's.appendString (s) ;' instruction)
  public: void appendUTF32LiteralStringConstant (const String inString, const bool inAppendZeroTerminator) ;

//--- Appending C string
  public: void appendCString (const char * inCstring) ;
  public: void appendString (const char * inCstring, const int32_t inCount) ;
  public: void appendString (const std::initializer_list <utf32> & inSource) ;

//--- Appending character
  public: void appendASCIIChar (const char inCharacter) ;
  public: void appendChar (const utf32 inUnicodeCharacter) ;

//--- Appending uint64_t in Hex
  public: void appendUnsigned0xHex (const uint64_t inValue) ;
  public: void appendUnsignedHex  (const uint64_t inValue) ;
  public: void appendUnsignedHex2 (const uint64_t inValue) ;
  public: void appendUnsignedHex4 (const uint64_t inValue) ;
  public: void appendUnsignedHex8 (const uint64_t inValue) ;
  public: void appendUnsignedHex16 (const uint64_t inValue) ;

//--- Appending uint64_t
  public: void appendUnsignedWithZeroFill (const uint64_t inValue, const uint32_t inWidth) ;
  public: void appendUnsigned (const uint64_t inValue) ;

//--- Appending int64_t
  public: void appendSigned (const int64_t inValue) ;

//--- Appending Double
  public: void appendDouble (const double inValue) ;

//--- Appending bool ("true" or"false")
  public: void appendBool (const bool inValue) ;

//--- Appending Pointer value (in hex)
  public: void appendPointer (const void * inValue) ;

//--- Abstract method for output single byte characters
  public: void performAppendCString (const char * inCharArray,
                                     const int32_t inArrayCount) ;

  protected: virtual void handleAppendUTF8Array (const char * inCharArray,
                                                 const int32_t inArrayCount) = 0 ;

//--- Abstract method for output unicode characters
  public: void performAppendCharacter (const utf32 inCharacter) ;
  protected: virtual void handleAppendCharacter (const utf32 inCharacter) = 0 ;

//--- Writing spaces
  public: void appendSpaces (const int32_t inSpaceCount) ;

//--- Writing a string several times
  public: void appendStringMultiple (const String & inString, const int32_t inRepeatCount) ;

//--- Methods for writing comment
  public: void appendTitleComment (const char * inLineCommentPrefix,
                                   const String & inCommentString) ;
  public: void appendHyphenLineCommentWithoutExtraBlankLine (const char * inLineCommentPrefix) ;
  public: void appendHyphenLineComment (const char * inLineCommentPrefix) ;
  public: void appendSpaceLineComment (const char * inLineCommentPrefix) ;
  public: void appendCenterJustifiedComment (const char * inLineCommentPrefix,
                                             const String & inCommentString) ;
  public: void appendComment (const char * inLineCommentPrefix,
                              const String & inCommentString) ;

//--- Methods for writing C and C++ code
  public: void appendStringAsCLiteralStringConstant (const String & inCstring) ;
  public: void appendStringAsCLiteralCharConstant (const utf32 c) ;
  public: void appendStringAsCLiteralStringConstantWithoutDelimiters (const String & inCstring) ;

//--- Writing C++ Comments (// ...)
  public: void appendCppTitleComment (const String & inCommentString) ;
  public: void appendCppHyphenLineCommentWithoutExtraBlankLine (void) ;
  public: void appendCppHyphenLineComment (void) ;
  public: void appendCppSpaceLineComment (void) ;
  public: void appendCppCenterJustifiedComment (const String & inCommentString) ;
  public: void appendCppComment (const String & inCommentString) ;

//--- Writing C Comments (/* ... */)
  public: void append_C_HyphenLineComment (void) ;
  public: void append_C_SpaceLineComment (void) ;
  
//--- Handle indentation
  public: void incIndentation (const int32_t inIncrement) {
    mIndentation += inIncrement ;
  }
  public: int32_t indentation (void) const {
    return mIndentation ;
  }

//--- Private data
  private: int32_t mIndentation ;
  private: bool mStartingLine ;
} ;

//--------------------------------------------------------------------------------------------------

String stringWithUnsigned (const uint64_t inValue) ;

String stringWithUnsigned0xHex (const uint64_t inValue) ;

String stringWithSigned (const int64_t inValue) ;

String stringWithPointer (const void * inValue) ;

String stringWithCharacter (const char inValue) ;

String stringWithUnicodeCharacter (const utf32 inValue) ;

String stringWithDouble (const double inValue) ;

//--------------------------------------------------------------------------------------------------
