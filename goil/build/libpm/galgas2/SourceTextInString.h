//--------------------------------------------------------------------------------------------------
//
//  'SourceTextInString'
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
//--------------------------------------------------------------------------------------------------

#pragma once

//--------------------------------------------------------------------------------------------------

#include "String-class.h"
#include "SharedObject.h"

//--------------------------------------------------------------------------------------------------
//
//                 Classes for handling source text
//
//--------------------------------------------------------------------------------------------------

class cSourceTextInString final : public SharedObject {
//--- Constructor
  public: cSourceTextInString (const String & inSourceString,
                               const String & inFilePath,
                               const bool inShowSourceOnDetailledErrorMessage
                               COMMA_LOCATION_ARGS) :
  SharedObject (THERE),
  mFilePath (inFilePath),
  mSourceString (inSourceString),
  mShowSourceOnDetailledErrorMessage (inShowSourceOnDetailledErrorMessage) {
  }

  public: String mFilePath ;
  public: String mSourceString ;
  public: bool mShowSourceOnDetailledErrorMessage ;

//--- No copy
  private: cSourceTextInString (const cSourceTextInString &) = delete ;
  private: cSourceTextInString & operator = (const cSourceTextInString &) = delete ;
} ;

//--------------------------------------------------------------------------------------------------

class SourceTextInString final {
//--- Default constructor
  public: SourceTextInString (void) ;

//--- Constructor
  public: SourceTextInString (const String & inSourceString,
                              const String & inFilePath,
                              const bool inShowSourceOnDetailledErrorMessage) ;

//--- Default constructor
  public: ~ SourceTextInString (void) ;

//--- Handle copy
  public: SourceTextInString (const SourceTextInString & inSource) ;
  public: SourceTextInString & operator = (const SourceTextInString & inSource) ;

  public: inline String sourceFilePath (void) const {
    return (mObject == nullptr) ? String () : mObject->mFilePath ;
  }

//--- Source text
  public: inline String sourceString (void) const {
    return (mObject == nullptr) ? String () : mObject->mSourceString ;
  }

  public: inline bool isValid (void) const {
    return mObject != nullptr ;
  }

  public: inline bool operator == (const SourceTextInString & inOther) const {
    return mObject == inOther.mObject ;
  }

  public: inline bool operator != (const SourceTextInString & inOther) const {
    return mObject != inOther.mObject ;
  }

  public: int32_t sourceLength (void) const {
    return (mObject == nullptr) ? 0 : mObject->mSourceString.length () ;
  }

  public: utf32 readCharOrNul (const int32_t inIndex COMMA_LOCATION_ARGS) const {
    return (mObject == nullptr) ? TO_UNICODE (0) : mObject->mSourceString.readCharOrNul (inIndex COMMA_THERE) ;
  }

  public: String getLineForLocation (const class LocationInSource & inLocation) const ;

  public: void appendSourceContents (String & ioMessage) const ;

//--- Private property
  private: cSourceTextInString * mObject ;
} ;

//--------------------------------------------------------------------------------------------------
