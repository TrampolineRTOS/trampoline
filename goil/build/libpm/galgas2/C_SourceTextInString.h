//----------------------------------------------------------------------------------------------------------------------
//
//  'C_SourceTextInString'
//
//  This file is part of libpm library
//
//  Copyright (C) 1996, ..., 2016 Pierre Molinaro.
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
//----------------------------------------------------------------------------------------------------------------------

#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include "strings/C_String.h"
#include "utilities/C_SharedObject.h"

//----------------------------------------------------------------------------------------------------------------------
//
//                 Classes for handling source text
//
//----------------------------------------------------------------------------------------------------------------------

class cSourceTextInString final : public C_SharedObject {
//--- Constructor
  public: cSourceTextInString (const C_String & inSourceString,
                               const C_String & inFilePath,
                               const bool inShowSourceOnDetailledErrorMessage
                               COMMA_LOCATION_ARGS) :
  C_SharedObject (THERE),
  mFilePath (inFilePath),
  mSourceString (inSourceString),
  mShowSourceOnDetailledErrorMessage (inShowSourceOnDetailledErrorMessage) {
  }

  public: C_String mFilePath ;
  public: C_String mSourceString ;
  public: bool mShowSourceOnDetailledErrorMessage ;

//--- No copy
  private: cSourceTextInString (const cSourceTextInString &) ;
  private: cSourceTextInString & operator = (const cSourceTextInString &) ;
} ;

//----------------------------------------------------------------------------------------------------------------------

class C_SourceTextInString {
//--- Default constructor
  public: C_SourceTextInString (void) ;

//--- Constructor
  public: C_SourceTextInString (const C_String & inSourceString,
                                 const C_String & inFilePath,
                                 const bool inShowSourceOnDetailledErrorMessage) ;

//--- Default constructor
  public: virtual ~ C_SourceTextInString (void) ;

//--- Handle copy
  public: C_SourceTextInString (const C_SourceTextInString & inSource) ;
  public: C_SourceTextInString & operator = (const C_SourceTextInString & inSource) ;

//--- Source file Name
  private: cSourceTextInString * mObject ;

  public: inline C_String sourceFilePath (void) const {
    return (mObject == nullptr) ? "" : mObject->mFilePath ;
  }

//--- Source text
  public: inline C_String sourceString (void) const {
    return (mObject == nullptr) ? "" : mObject->mSourceString ;
  }

  public: inline bool isValid (void) const {
    return mObject != nullptr ;
  }

  public: inline bool operator == (const C_SourceTextInString & inOther) const {
    return mObject == inOther.mObject ;
  }

  public: inline bool operator != (const C_SourceTextInString & inOther) const {
    return mObject != inOther.mObject ;
  }

  public: int32_t sourceLength (void) const {
    return (mObject == nullptr) ? 0 : mObject->mSourceString.length () ;
  }

  public: utf32 readCharOrNul (const int32_t inIndex COMMA_LOCATION_ARGS) const {
    return (mObject == nullptr) ? TO_UNICODE (0) : mObject->mSourceString.readCharOrNul (inIndex COMMA_THERE) ;
  }

  public: const utf32 * temporaryUTF32StringAtIndex (const int32_t inIndex COMMA_LOCATION_ARGS) const {
    return (mObject == nullptr) ? nullptr : & (mObject->mSourceString.utf32String (THERE)) [inIndex] ;
  }

  public: C_String getLineForLocation (const class C_LocationInSource & inLocation) const ;

  public: void appendSourceContents (C_String & ioMessage) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------
