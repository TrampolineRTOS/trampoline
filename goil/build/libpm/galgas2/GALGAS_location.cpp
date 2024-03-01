//----------------------------------------------------------------------------------------------------------------------
//
//  'GALGAS_location'
//
//  This file is part of libpm library
//
//  Copyright (C) 1996, ..., 2023 Pierre Molinaro.
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

#include "all-predefined-types.h"
#include "Compiler.h"
#include "FileManager.h"

//----------------------------------------------------------------------------------------------------------------------

class InternalLocation final : public SharedObject {
  public: const SourceTextInString mSourceText ;
  public: const LocationInSource mStartLocation ;
  public: const LocationInSource mEndLocation ;

//--- Constructor
  public: InternalLocation (const SourceTextInString & inSourceText,
                            const LocationInSource & inStartLocation,
                            const LocationInSource & inEndLocation) :
  SharedObject (HERE),
  mSourceText (inSourceText),
  mStartLocation (inStartLocation),
  mEndLocation (inEndLocation) {
  }

//--- No copy
  private: InternalLocation (const InternalLocation &) = delete ;
  private: InternalLocation & operator = (const InternalLocation &) = delete ;
} ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location::GALGAS_location (void) :
mInternalLocation (nullptr) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location::~ GALGAS_location (void) {
  macroDetachSharedObject (mInternalLocation)
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location::GALGAS_location (const LocationInSource & inStartLocationInSource,
                                  const LocationInSource & inEndLocationInSource,
                                  const SourceTextInString & inSourceText) :
AC_GALGAS_root (),
mInternalLocation (nullptr) {
  macroMyNew (mInternalLocation, InternalLocation (inSourceText, inStartLocationInSource, inEndLocationInSource))
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_location::drop (void) {
  macroDetachSharedObject (mInternalLocation) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location & GALGAS_location::operator = (const GALGAS_location & inSource) {
  macroAssignSharedObject (mInternalLocation, inSource.mInternalLocation) ;
  return *this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location::GALGAS_location (const GALGAS_location & inSource) :
mInternalLocation (nullptr) {
  macroAssignSharedObject (mInternalLocation, inSource.mInternalLocation) ;
}

//----------------------------------------------------------------------------------------------------------------------

LocationInSource GALGAS_location::startLocation (void) const {
  return (mInternalLocation == nullptr) ? LocationInSource () : mInternalLocation->mStartLocation ;
}

//----------------------------------------------------------------------------------------------------------------------

LocationInSource GALGAS_location::endLocation (void) const {
  return (mInternalLocation == nullptr) ? LocationInSource () : mInternalLocation->mEndLocation ;
}

//----------------------------------------------------------------------------------------------------------------------

SourceTextInString GALGAS_location::sourceText (void) const {
  return (mInternalLocation == nullptr) ? SourceTextInString () : mInternalLocation->mSourceText ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_location::class_func_nowhere (UNUSED_LOCATION_ARGS) {
  GALGAS_location result ;
  macroMyNew (result.mInternalLocation, InternalLocation (SourceTextInString (), LocationInSource (), LocationInSource ()))
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_location::isValid (void) const {
  return mInternalLocation != nullptr ;
}

//----------------------------------------------------------------------------------------------------------------------
//   CONSTRUCTORS
//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_location::class_func_here (Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  return inCompiler->here () ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_location::class_func_next (Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  return inCompiler->next () ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_location::class_func_separator (Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  return inCompiler->separator () ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_location::isValidAndNotNowhere (void) const {
  return (mInternalLocation != nullptr) && mInternalLocation->mSourceText.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_location::getter_isNowhere (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (mInternalLocation != nullptr) {
    result = GALGAS_bool (!mInternalLocation->mSourceText.isValid ()) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_location::objectCompare (const GALGAS_location & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    int32_t r = 0 ;
    if (ssize_t (mInternalLocation) != ssize_t (inOperand.mInternalLocation)) {
      r = mInternalLocation->mStartLocation.index () - inOperand.mInternalLocation->mStartLocation.index () ;
      if (r == 0) {
        r = mInternalLocation->mEndLocation.index () - inOperand.mInternalLocation->mEndLocation.index () ;
      }
      if (r == 0) {
        r = mInternalLocation->mSourceText.sourceString ().compare (inOperand.mInternalLocation->mSourceText.sourceString ()) ;
      }
    }
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

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_location::description (String & ioString,
                                   const int32_t /* inIndentation */) const {
  ioString.appendCString ("<@location:") ;
  if (isValid ()) {
    if (!mInternalLocation->mSourceText.isValid ()) {
      ioString.appendCString ("nowhere") ;
    }else{
      ioString.appendCString ("'") ;
      ioString.appendString (mInternalLocation->mSourceText.sourceFilePath ()) ;
      ioString.appendCString ("'") ;
    }
    ioString.appendCString (":") ;
    ioString.appendSigned (mInternalLocation->mStartLocation.lineNumber ()) ;
    ioString.appendCString (":") ;
    ioString.appendSigned (mInternalLocation->mStartLocation.columnNumber ()) ;
  }else{
    ioString.appendCString ("not built") ;
  }
  ioString.appendCString (">") ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_location::getter_startLocationString (Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    if (!mInternalLocation->mSourceText.isValid ()) {
      inCompiler->onTheFlyRunTimeError ("'startLocationString' reader cannot be called on a nowhere @location object" COMMA_THERE) ;
    }else{
      String s ;
      s.appendCString ("file '") ;
      s.appendString (mInternalLocation->mSourceText.sourceFilePath ()) ;
      s.appendCString ("', line ") ;
      s.appendSigned (mInternalLocation->mStartLocation.lineNumber ()) ;
      s.appendCString (":") ;
      s.appendSigned (mInternalLocation->mStartLocation.columnNumber ()) ;
      result = GALGAS_string (s) ;
    }
  }
  return result ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_location::getter_endLocationString (Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    if (!mInternalLocation->mSourceText.isValid ()) {
      inCompiler->onTheFlyRunTimeError ("'endLocationString' reader cannot be called on a nowhere @location object" COMMA_THERE) ;
    }else{
      String s = "file '" ;
      s.appendString (mInternalLocation->mSourceText.sourceFilePath ()) ;
      s.appendCString ("', line ") ;
      s.appendSigned (mInternalLocation->mEndLocation.lineNumber ()) ;
      s.appendCString (":") ;
      s.appendSigned (mInternalLocation->mEndLocation.columnNumber ()) ;
      result = GALGAS_string (s) ;
    }
  }
  return result ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_location::getter_file (Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    if (!mInternalLocation->mSourceText.isValid ()) {
      inCompiler->onTheFlyRunTimeError ("'file' reader cannot be called on a nowhere @location object" COMMA_THERE) ;
    }else{
      result = GALGAS_string (mInternalLocation->mSourceText.sourceFilePath ()) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_location::getter_startLocationIndex (Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    if (!mInternalLocation->mSourceText.isValid ()) {
      inCompiler->onTheFlyRunTimeError ("'startLocationIndex' reader cannot be called on a nowhere @location object" COMMA_THERE) ;
    }else{
      result = GALGAS_uint ((uint32_t) mInternalLocation->mStartLocation.index ()) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_location::getter_endLocationIndex (Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    if (!mInternalLocation->mSourceText.isValid ()) {
      inCompiler->onTheFlyRunTimeError ("'endLocationIndex' reader cannot be called on a nowhere @location object" COMMA_THERE) ;
    }else{
      result = GALGAS_uint ((uint32_t) mInternalLocation->mEndLocation.index ()) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_location::getter_startColumn (Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    if (!mInternalLocation->mSourceText.isValid ()) {
      inCompiler->onTheFlyRunTimeError ("'startColumn' reader cannot be called on a nowhere @location object" COMMA_THERE) ;
    }else{
      result = GALGAS_uint ((uint32_t) mInternalLocation->mStartLocation.columnNumber ()) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_location::getter_endColumn (Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    if (!mInternalLocation->mSourceText.isValid ()) {
      inCompiler->onTheFlyRunTimeError ("'endColumn' reader cannot be called on a nowhere @location object" COMMA_THERE) ;
    }else{
      result = GALGAS_uint ((uint32_t) mInternalLocation->mEndLocation.columnNumber ()) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_location::getter_startLine (Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    if (!mInternalLocation->mSourceText.isValid ()) {
      inCompiler->onTheFlyRunTimeError ("'startLine' getter cannot be called on a nowhere @location object" COMMA_THERE) ;
    }else{
      result = GALGAS_uint ((uint32_t) mInternalLocation->mEndLocation.lineNumber ()) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_location::getter_endLine (Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    if (!mInternalLocation->mSourceText.isValid ()) {
      inCompiler->onTheFlyRunTimeError ("'endLine' getter cannot be called on a nowhere @location object" COMMA_THERE) ;
    }else{
      result = GALGAS_uint ((uint32_t) mInternalLocation->mEndLocation.lineNumber ()) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_location::getter_union (const GALGAS_location & inOtherLocation,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (isValid () && inOtherLocation.isValid ()) {
    if (mInternalLocation->mSourceText != inOtherLocation.mInternalLocation->mSourceText) {
      inCompiler->onTheFlyRunTimeError ("'union' getter cannot be called on an @location object that is relative to an other source" COMMA_THERE) ;
    }else{
      LocationInSource startLocation = mInternalLocation->mStartLocation ;
      if (startLocation.index () > inOtherLocation.mInternalLocation->mStartLocation.index ()){
        startLocation = inOtherLocation.mInternalLocation->mStartLocation ;
      }
      LocationInSource endLocation = mInternalLocation->mEndLocation ;
      if (endLocation.index () < inOtherLocation.mInternalLocation->mEndLocation.index ()){
        endLocation = inOtherLocation.mInternalLocation->mEndLocation ;
      }
      macroMyNew (result.mInternalLocation, InternalLocation (mInternalLocation->mSourceText, startLocation, endLocation))
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

