//---------------------------------------------------------------------------*
//                                                                           *
//   GALGAS_data : this class implements the GALGAS 'data' native type       *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2009, ..., 2012 Pierre Molinaro.                           *
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

#include "galgas2/predefined-types.h"
#include "galgas2/capCollectionElement.h"
#include "galgas2/cCollectionElement.h"
#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "strings/unicode_character_cpp.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "files/C_BinaryFileWrite.h"

//---------------------------------------------------------------------------*

#include <ctype.h>

//---------------------------------------------------------------------------*
//   GALGAS_data                                                             *
//---------------------------------------------------------------------------*

GALGAS_data::GALGAS_data (void) :
mIsValid (false),
mData () {
}

//---------------------------------------------------------------------------*

GALGAS_data::GALGAS_data (const C_Data & inData) :
mIsValid (true),
mData (inData) {
}

//---------------------------------------------------------------------------*

GALGAS_data GALGAS_data::constructor_emptyData (UNUSED_LOCATION_ARGS) {
  return GALGAS_data (C_Data ()) ;
}

//---------------------------------------------------------------------------*

GALGAS_data GALGAS_data::constructor_dataWithContentsOfFile (const GALGAS_string & inFilePath,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  GALGAS_data result ;
  if (inFilePath.isValid()){
    C_Data binaryData ;
    const bool ok = C_FileManager::binaryDataWithContentOfFile (inFilePath.stringValue (), binaryData) ;
    if (ok) {
      
      result = GALGAS_data (binaryData) ;
    }else{
      C_String s ;
      s << "cannot read binary file at path '" << inFilePath.stringValue () << "'" ;
      inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

typeComparisonResult GALGAS_data::objectCompare (const GALGAS_data & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const PMSInt32 r = mData.compareWithData (inOperand.mData) ;
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

void GALGAS_data::description (C_String & ioString,
                               const PMSInt32 /* inIndentation */) const {
  ioString << "<@data:" ;
  if (isValid ()) {
    ioString << "length=" << cStringWithSigned (mData.length ()) ;
  }else{
    ioString << "not built" ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------*

GALGAS_uint GALGAS_data::reader_length (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint ((PMUInt32) mData.length ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_data::reader_cStringRepresentation (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    C_String s (cStringWithUnsigned (mData (0 COMMA_HERE))) ;
    for (PMSInt32 i=1 ; i<mData.length () ; i++) {
      s << ", " << cStringWithUnsigned (mData (i COMMA_HERE)) ;
      if ((i % 16) == 0) {
        s << "\n" ;
      }
    }
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

void GALGAS_data::modifier_appendByte (GALGAS_uint inArgument0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  if (inArgument0.isValid ()) {
    if (inArgument0.uintValue () > 255) {
      inCompiler->onTheFlyRunTimeError ("'@data appendByte' modifier invoked with value greater than 255" COMMA_THERE) ;
    }else{
      const PMUInt8 byte = (PMUInt8) (inArgument0.uintValue () & PMUINT8_MAX) ;
      mData.appendByte (byte) ;
    }
  }
}

//---------------------------------------------------------------------------*

void GALGAS_data::modifier_appendShortBE (GALGAS_uint inArgument0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  if (inArgument0.isValid ()) {
    if (inArgument0.uintValue () > 0xFFFF) {
      inCompiler->onTheFlyRunTimeError ("'@data appendShortBE' modifier invoked with value greater than 0xFFFF" COMMA_THERE) ;
    }else{
      const PMUInt32 value = inArgument0.uintValue () & 0xFFFFU ;
      mData.appendByte ((PMUInt8) ((value >> 8) & PMUINT8_MAX)) ;
      mData.appendByte ((PMUInt8) (value & 255)) ;
    }
  }
}

//---------------------------------------------------------------------------*

void GALGAS_data::modifier_appendShortLE (GALGAS_uint inArgument0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  if (inArgument0.isValid ()) {
    if (inArgument0.uintValue () > 0xFFFF) {
      inCompiler->onTheFlyRunTimeError ("'@data appendShortLE' modifier invoked with value greater than 0xFFFF" COMMA_THERE) ;
    }else{
      const PMUInt32 value = inArgument0.uintValue () & 0xFFFFU ;
      mData.appendByte ((PMUInt8) (value & 255)) ;
      mData.appendByte ((PMUInt8) ((value >> 8) & PMUINT8_MAX)) ;
    }
  }
}

//---------------------------------------------------------------------------*

void GALGAS_data::modifier_appendUIntBE (GALGAS_uint inArgument0
                                         COMMA_UNUSED_LOCATION_ARGS) {
  if (inArgument0.isValid ()) {
    const PMUInt32 value = inArgument0.uintValue () ;
    mData.appendByte ((PMUInt8) (value >> 24)) ;
    mData.appendByte ((PMUInt8) ((value >> 16) & 255)) ;
    mData.appendByte ((PMUInt8) ((value >> 8) & 255)) ;
    mData.appendByte ((PMUInt8) (value & 255)) ;
  }
}

//---------------------------------------------------------------------------*

void GALGAS_data::modifier_appendUIntLE (GALGAS_uint inArgument0
                                         COMMA_UNUSED_LOCATION_ARGS) {
  if (inArgument0.isValid ()) {
    const PMUInt32 value = inArgument0.uintValue () ;
    mData.appendByte ((PMUInt8) (value & 255)) ;
    mData.appendByte ((PMUInt8) ((value >> 8) & 255)) ;
    mData.appendByte ((PMUInt8) ((value >> 16) & 255)) ;
    mData.appendByte ((PMUInt8) (value >> 24)) ;
  }
}

//---------------------------------------------------------------------------*

void GALGAS_data::modifier_appendUTF_38_String (GALGAS_string inString
                                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inString.isValid ()) {
    const C_String s = inString.stringValue () ;
    for (PMSInt32 i=0 ; i<s.length () ; i++) {
      const utf32 c = s (i COMMA_HERE) ;
      char sequence [5] ;
      const PMSInt32 n = UTF8StringFromUTF32Character (c, sequence) ;
      for (PMSInt32 j=0 ; j<n ; j++) {
        mData.appendByte ((PMUInt8) sequence [j]) ;
      }
    }
    mData.appendByte (0) ;
  }
}

//---------------------------------------------------------------------------*

void GALGAS_data::modifier_appendData (GALGAS_data inData
                                       COMMA_UNUSED_LOCATION_ARGS) {
  if (inData.isValid ()) {
    mData.appendData (inData.mData) ;
  }
}

//---------------------------------------------------------------------------*

void GALGAS_data::method_writeToFileWhenDifferentContents (GALGAS_string inFilePath,
                                                           GALGAS_bool & outFileWritten,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  outFileWritten.drop () ;
  if (inFilePath.isValid ()) {
    bool needToWrite = true ;
    const bool fileAlreadyExists = C_FileManager::fileExistsAtPath (inFilePath.stringValue ()) ;
    if (fileAlreadyExists) {
      inCompiler->logFileRead (inFilePath.stringValue ()) ;
      C_Data binaryData ;
      C_FileManager::binaryDataWithContentOfFile (inFilePath.stringValue (), binaryData) ;
      needToWrite = mData != binaryData ;
    }
    outFileWritten = GALGAS_bool (needToWrite) ;
    if (needToWrite) {
      if (C_Compiler::performGeneration ()) {
        const bool verboseOptionOn = gOption_galgas_5F_builtin_5F_options_verbose_5F_output.mValue ;
        bool ok = C_FileManager::makeDirectoryIfDoesNotExist (inFilePath.stringValue ().stringByDeletingLastPathComponent ()) ;
        if (! ok) {
          C_String message ;
          message << "cannot create '" << inFilePath.stringValue () << "' directory" ;
          inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
          outFileWritten.drop () ;
        }else{
          ok = C_FileManager::writeBinaryDataToFile (mData, inFilePath.stringValue ()) ;
          if (ok && verboseOptionOn && fileAlreadyExists) {
            ggs_printFileOperationSuccess (C_String ("Replaced '") + inFilePath.stringValue () + "'.\n" COMMA_THERE) ;
          }else if (ok && verboseOptionOn && ! fileAlreadyExists) {
            ggs_printFileOperationSuccess (C_String ("Created '") + inFilePath.stringValue () + "'.\n" COMMA_HERE) ;
          }else if (! ok) {
            C_String message ;
            message << "cannot write '" << inFilePath.stringValue () << "' file" ;
            inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
            outFileWritten.drop () ;
          }
        }
      }else{
        ggs_printWarning (NULL, C_LocationInSource (), C_String ("Need to write '") + inFilePath.stringValue () + "'.\n" COMMA_HERE) ;
      }
    }
  }
}

//---------------------------------------------------------------------------*

void GALGAS_data::method_writeToFile (GALGAS_string inFilePath,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  if (inFilePath.isValid ()) {
    const C_String filePath = inFilePath.stringValue () ;
    if (filePath.length () == 0) {
      inCompiler->onTheFlyRunTimeError ("'@data writeToFile' modifier invoked with empty file path argument" COMMA_THERE) ;
    }else if (! C_Compiler::performGeneration ()) {
      ggs_printWarning (NULL, C_LocationInSource (), C_String ("Need to write '") + filePath + "'.\n" COMMA_HERE) ;
    }else{
      const bool fileAlreadyExists = C_FileManager::fileExistsAtPath (filePath) ;
      const bool verboseOptionOn = gOption_galgas_5F_builtin_5F_options_verbose_5F_output.mValue ;
      C_FileManager::makeDirectoryIfDoesNotExist (filePath.stringByDeletingLastPathComponent()) ;
      C_BinaryFileWrite binaryFile (filePath) ;
      if (! binaryFile.isOpened ()) {
        C_String s ;
        s << "'@data writeToFile': cannot open '" << filePath << "' file in write mode" ;
        inCompiler->onTheFlyRunTimeError (s.cString (HERE) COMMA_THERE) ;
      }else{
        binaryFile.appendData (mData) ;
        const bool ok = binaryFile.close () ;
        if (ok && verboseOptionOn && fileAlreadyExists) {
          ggs_printFileOperationSuccess (C_String ("Replaced '") + filePath + "'.\n" COMMA_THERE) ;
        }else if (ok && verboseOptionOn && ! fileAlreadyExists) {
          ggs_printFileOperationSuccess (C_String ("Created '") + filePath + "'.\n" COMMA_THERE) ;
        }else if (! ok) {
          C_String message ;
          message << "cannot write '" << filePath << "' file" ;
          inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
        }
      }
    }
  }
}

//---------------------------------------------------------------------------*

void GALGAS_data::method_writeToExecutableFile (GALGAS_string inFilePath,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  if (inFilePath.isValid ()) {
    const C_String filePath = inFilePath.stringValue () ;
    if (filePath.length () == 0) {
      inCompiler->onTheFlyRunTimeError ("'@data writeToFile' modifier invoked with empty file path argument" COMMA_THERE) ;
    }else if (! C_Compiler::performGeneration ()) {
      ggs_printWarning (NULL, C_LocationInSource (), C_String ("Need to write '") + filePath + "'.\n" COMMA_HERE) ;
    }else{
      const bool fileAlreadyExists = C_FileManager::fileExistsAtPath (filePath) ;
      const bool verboseOptionOn = gOption_galgas_5F_builtin_5F_options_verbose_5F_output.mValue ;
      C_FileManager::makeDirectoryIfDoesNotExist (filePath.stringByDeletingLastPathComponent()) ;
      C_BinaryFileWrite binaryFile (filePath) ;
      if (! binaryFile.isOpened ()) {
        C_String s ;
        s << "'@data writeToExecutableFile': cannot open '" << filePath << "' file in write mode" ;
        inCompiler->onTheFlyRunTimeError (s.cString (HERE) COMMA_THERE) ;
      }else{
        binaryFile.appendData (mData) ;
        const bool ok = binaryFile.close () ;
        C_FileManager::makeFileExecutable (filePath) ;
        if (ok && verboseOptionOn && fileAlreadyExists) {
          ggs_printFileOperationSuccess (C_String ("Replaced '") + filePath + "'.\n" COMMA_THERE) ;
        }else if (ok && verboseOptionOn && ! fileAlreadyExists) {
          ggs_printFileOperationSuccess (C_String ("Created '") + filePath + "'.\n" COMMA_THERE) ;
        }else if (! ok) {
          C_String message ;
          message << "cannot write '" << filePath << "' file" ;
          inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
        }
      }
    }
  }
}

//---------------------------------------------------------------------------*
//   cCollectionElement_data                                                 *
//---------------------------------------------------------------------------*

class cCollectionElement_data : public cCollectionElement {
//--- Private member
  protected : GALGAS_uint mAttribute_data ;
  public : inline GALGAS_uint attribute_data (void) const { return mAttribute_data ; }

//--- Default constructor
  public : cCollectionElement_data (const GALGAS_uint & inData
                                    COMMA_LOCATION_ARGS) ;

//--- No copy
  private : cCollectionElement_data (const cCollectionElement_data &) ;
  private : cCollectionElement_data & operator = (const cCollectionElement_data &) ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const PMSInt32 inIndentation) const ;
} ;

//---------------------------------------------------------------------------*

cCollectionElement_data::cCollectionElement_data (const GALGAS_uint & inData
                                                  COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mAttribute_data (inData) {
}

//---------------------------------------------------------------------------*

bool cCollectionElement_data::isValid (void) const {
  return mAttribute_data.isValid () ;
}

//---------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_data::compare (const cCollectionElement * inOperand) const {
  const cCollectionElement_data * operand = (const cCollectionElement_data *) inOperand ;
  macroValidSharedObject (operand, const cCollectionElement_data) ;
  return mAttribute_data.objectCompare (operand->mAttribute_data) ;
}

//---------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_data::copy (void) {
  cCollectionElement_data * p = NULL ;
  macroMyNew (p, cCollectionElement_data (mAttribute_data COMMA_HERE)) ;
  return p ;
}

//---------------------------------------------------------------------------*

void cCollectionElement_data::description (C_String & ioString, const PMSInt32 inIndentation) const {
  mAttribute_data.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//     cEnumerator_data class                                                *
//                                                                           *
//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark cEnumerator_data
#endif

//---------------------------------------------------------------------------*

void GALGAS_data::populateEnumerationArray (capCollectionElementArray & inEnumerationArray,
                                            const typeEnumerationOrder inEnumerationOrder) const {
  const PMSInt32 count = mData.length () ;
  inEnumerationArray.setCapacity ((PMUInt32) count) ;
  switch (enumerationOrderValue (inEnumerationOrder)) {
  case kENUMERATION_UP:
    for (PMSInt32 i=0 ; i<count ; i++) {
      cCollectionElement_data * p = NULL ;
      macroMyNew (p, cCollectionElement_data (GALGAS_uint (mData (i COMMA_HERE)) COMMA_HERE)) ;
      capCollectionElement object ;
      object.setPointer (p) ;
      macroDetachSharedObject (p) ;
      inEnumerationArray.addObject (object) ;
    }
    break ;
  case kENUMERATION_DOWN:
    for (PMSInt32 i=0 ; i<count ; i++) {
      cCollectionElement_data * p = NULL ;
      macroMyNew (p, cCollectionElement_data (GALGAS_uint (mData (mData.length () - i - 1 COMMA_HERE)) COMMA_HERE)) ;
      capCollectionElement object ;
      object.setPointer (p) ;
      macroDetachSharedObject (p) ;
      inEnumerationArray.addObject (object) ;
    }
    break ;
  case kENUMERATION_ENTER_ORDER : case kENUMERATION_REVERSE_ENTER_ORDER:
    MF_Assert (false, "invalid inEnumerationOrder %lld", enumerationOrderValue (inEnumerationOrder), 0) ;
    break ;
  }
}

//---------------------------------------------------------------------------*

cEnumerator_data::cEnumerator_data (const GALGAS_data & inEnumeratedObject,
                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------*

GALGAS_uint cEnumerator_data::current_data (LOCATION_ARGS) const {
  const cCollectionElement_data * p = (const cCollectionElement_data *) (currentObjectPtr (THERE)) ;
  macroValidSharedObject (p, const cCollectionElement_data) ;
  return p->attribute_data () ;
}

//---------------------------------------------------------------------------*

GALGAS_uint cEnumerator_data::current (LOCATION_ARGS) const {
  const cCollectionElement_data * p = (const cCollectionElement_data *) (currentObjectPtr (THERE)) ;
  macroValidSharedObject (p, const cCollectionElement_data) ;
  return p->attribute_data () ;
}

//---------------------------------------------------------------------------*