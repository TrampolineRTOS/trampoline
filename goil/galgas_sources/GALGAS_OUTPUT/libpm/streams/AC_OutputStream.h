//---------------------------------------------------------------------------*
//                                                                           *
//  AC_OutputStream : an abstract output stream class                        *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 1997, ..., 2009 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//                                                                           *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes (France)                                   *
//                                                                           *
//  This library is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU Lesser General Public License as published    *
//  by the Free Software Foundation; either version 2 of the License, or     *
//  (at your option) any later version.                                      *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//  more details.                                                            *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef CLASS_OUTPUT_STREAM_DEFINED
#define CLASS_OUTPUT_STREAM_DEFINED

//---------------------------------------------------------------------------*

#include "utilities/MF_Assert.h"
#include "utilities/M_machine.h"
#include "strings/string_encodings.h"

//---------------------------------------------------------------------------*

class C_String ;

//---------------------------------------------------------------------------*

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
  public : void appendCString (const char * inCstring, const PMSInt32 inCount) ;

//--- Appending UTF32 string
  public : void appendUTF32String (const utf32 * inUTF32String) ;

//--- Appending character
  public : void appendUnicodeCharacter (const utf32 inUnicodeCharacter COMMA_LOCATION_ARGS) ;

//--- Appending PMUInt32
  public : void appendUnsignedWithZeroFill (const PMUInt32 inValue, const PMUInt32 inWidth) ;
  public : void appendUnsigned (const PMUInt32 inValue) ;
  public : void appendUnsignedHex  (const PMUInt32 inValue) ;
  public : void appendUnsignedHex2 (const PMUInt32 inValue) ;
  public : void appendUnsignedHex4 (const PMUInt32 inValue) ;
  public : void appendUnsignedHex8 (const PMUInt32 inValue) ;

//--- Appending PMUInt64
  public : void appendUnsigned64 (const PMUInt64 inValue) ;
  public : void appendUnsigned64inHex (const PMUInt64 inValue) ;

//--- Appending PMSInt32
  public : void appendSigned (const PMSInt32 inValue) ;

//--- Appending Sint64
  public : void appendSigned64 (const PMSInt64 inValue) ;

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
  public : void genericCharArrayOutput (const char * inCharArray, const PMSInt32 inArrayCount) ;

  protected : virtual void
  performActualCharArrayOutput (const char * inCharArray, const PMSInt32 inArrayCount) = 0 ;

//--- Abstract method for output unicode characters
  public : void genericUnicodeArrayOutput (const utf32 * inCharArray, const PMSInt32 inArrayCount) ;

  protected : virtual void
  performActualUnicodeArrayOutput (const utf32 * inCharArray, const PMSInt32 inArrayCount) = 0 ;

//--- Writing spaces
  public : void appendSpaces (const PMSInt32 inSpaceCount) ;

//--- Writing a string several times
  public : void writeStringMultiple (const C_String & inString, const PMSInt32 inRepeatCount) ;

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
  public : void appendCLiteralStringConstant (const C_String & inString, const PMSInt32 inLineMaxLength) ;
  public : void appendCLiteralStringConstant (const C_String & inCstring) ;
  public : void appendCLiteralCharConstant (const utf32 c) ;

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
  public : void incIndentation (const PMSInt32 inIncrement) {
    mIndentation += inIncrement ;
  }
  public : PMSInt32 indentation (void) const {
    return mIndentation ;
  }

//--- Private data
  private : PMSInt32 mIndentation ;
  private : bool mStartingLine ;
} ;

//---------------------------------------------------------------------------*

C_String cStringWithUnsigned (const PMUInt64 inValue) ;

//---------------------------------------------------------------------------*

C_String cStringWithSigned (const PMSInt64 inValue) ;

//---------------------------------------------------------------------------*

C_String cStringWithPointer (const void * inValue) ;

//---------------------------------------------------------------------------*

C_String cStringWithCharacter (const char inValue) ;

//---------------------------------------------------------------------------*

C_String cStringWithUnicodeCharacter (const utf32 inValue) ;

//---------------------------------------------------------------------------*

C_String cStringWithDouble (const double inValue) ;

//---------------------------------------------------------------------------*

#endif
