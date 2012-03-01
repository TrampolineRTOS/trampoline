//---------------------------------------------------------------------------*
//                                                                           *
//  'GALGAS_location'                                                        *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 1996, ..., 2010 Pierre Molinaro.                           *
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

#include "predefined-types.h"
#include "galgas2/C_Compiler.h"

//---------------------------------------------------------------------------*

GALGAS_location::GALGAS_location (void) :
AC_GALGAS_root (),
mStartLocationInSource (),
mEndLocationInSource (),
mSourceText (NULL),
mIsValid (false) {
}

//---------------------------------------------------------------------------*

GALGAS_location::GALGAS_location (const C_LocationInSource & inStartLocationInSource,
                                  const C_LocationInSource & inEndLocationInSource,
                                  C_SourceTextInString * inSourceText) :
AC_GALGAS_root (),
mStartLocationInSource (inStartLocationInSource),
mEndLocationInSource (inEndLocationInSource),
mSourceText (NULL),
mIsValid (true) {
  macroAssignSharedObject (mSourceText, inSourceText) ;
}

//---------------------------------------------------------------------------*

GALGAS_location::~GALGAS_location (void) {
  macroDetachSharedObject (mSourceText) ;
}

//---------------------------------------------------------------------------*

GALGAS_location::GALGAS_location (const GALGAS_location & inSource) :
AC_GALGAS_root (),
mStartLocationInSource (inSource.mStartLocationInSource),
mEndLocationInSource (inSource.mEndLocationInSource),
mSourceText (NULL),
mIsValid (inSource.mIsValid) {
  macroAssignSharedObject (mSourceText, inSource.mSourceText) ;
}

//---------------------------------------------------------------------------*

GALGAS_location & GALGAS_location::operator = (const GALGAS_location & inSource) {
  mStartLocationInSource = inSource.mStartLocationInSource ;
  mEndLocationInSource = inSource.mEndLocationInSource ;
  mIsValid = inSource.mIsValid ;
  macroAssignSharedObject (mSourceText, inSource.mSourceText) ;
  return * this ;
}

//---------------------------------------------------------------------------*

void GALGAS_location::drop (void) {
  macroDetachSharedObject (mSourceText) ;
  mIsValid = false ;
}

//---------------------------------------------------------------------------*

GALGAS_location GALGAS_location::constructor_nowhere (UNUSED_LOCATION_ARGS) {
  GALGAS_location result ;
  result.mIsValid = true ;
  return result ;
}

//---------------------------------------------------------------------------*

bool GALGAS_location::isValidAndNotNowhere (void) const {
  return mIsValid && (NULL != mSourceText) ;
}

//---------------------------------------------------------------------------*

GALGAS_bool GALGAS_location::reader_isNowhere (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (mIsValid) {
    result = GALGAS_bool (NULL == mSourceText) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

typeComparisonResult GALGAS_location::objectCompare (const GALGAS_location & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    PMSInt32 r = mStartLocationInSource.mIndex - inOperand.mStartLocationInSource.mIndex ;
    if (r == 0) {
      r = mEndLocationInSource.mIndex - inOperand.mEndLocationInSource.mIndex ;
    }
    if (r == 0) {
      if ((NULL != mSourceText) && (NULL != inOperand.mSourceText)) {
        r = mSourceText->mSourceString.compare (inOperand.mSourceText->mSourceString) ;
      }else if ((NULL != mSourceText) && (NULL == inOperand.mSourceText)) {
        r = 1 ;
      }else if ((NULL == mSourceText) && (NULL != inOperand.mSourceText)) {
        r = -1 ;
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

//---------------------------------------------------------------------------*

void GALGAS_location::description (C_String & ioString,
                                   const PMSInt32 /* inIndentation */) const {
  ioString << "<@location:" ;
  if (isValid ()) {
    if (NULL == mSourceText) {
      ioString << "nowhere" ;
    }else{
      ioString << "'" << mSourceText->sourceFilePath () << "'" ;
    }
    ioString << ":" << cStringWithSigned (mStartLocationInSource.mLineNumber)
             << ":" << cStringWithSigned (mStartLocationInSource.mColumnNumber) ;
  }else{
    ioString << "not built" ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_location::reader_locationString (C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    if (NULL == mSourceText) {
      inCompiler->onTheFlyRunTimeError ("'locationString' reader cannot be called on a nowhere @location object" COMMA_THERE) ;
    }else{
      C_String s ;
      s << "file '" << mSourceText->sourceFilePath ()
        << "', line " << cStringWithSigned (mEndLocationInSource.mLineNumber)
        << ":" << cStringWithSigned (mEndLocationInSource.mColumnNumber) ;  
      result = GALGAS_string (s) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_uint GALGAS_location::reader_locationIndex (C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    if (NULL == mSourceText) {
      inCompiler->onTheFlyRunTimeError ("'locationIndex' reader cannot be called on a nowhere @location object" COMMA_THERE) ;
    }else{
      result = GALGAS_uint ((PMUInt32) mEndLocationInSource.mIndex) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_uint GALGAS_location::reader_column (C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    if (NULL == mSourceText) {
      inCompiler->onTheFlyRunTimeError ("'column' reader cannot be called on a nowhere @location object" COMMA_THERE) ;
    }else{
      result = GALGAS_uint ((PMUInt32) mEndLocationInSource.mColumnNumber) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_uint GALGAS_location::reader_line (C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    if (NULL == mSourceText) {
      inCompiler->onTheFlyRunTimeError ("'line' reader cannot be called on a nowhere @location object" COMMA_THERE) ;
    }else{
      result = GALGAS_uint ((PMUInt32) mEndLocationInSource.mLineNumber) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

