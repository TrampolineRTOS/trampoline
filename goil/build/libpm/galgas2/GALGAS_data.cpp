//----------------------------------------------------------------------------------------------------------------------
//
//   GALGAS_data : this class implements the GALGAS 'data' native type
//
//  This file is part of libpm library
//
//  Copyright (C) 2009, ..., 2023 Pierre Molinaro.
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
#include "galgas2/capCollectionElement.h"
#include "galgas2/cCollectionElement.h"
#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "strings/unicode_character_cpp.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "files/C_BinaryFileWrite.h"
#include "galgas2/F_verbose_output.h"

//----------------------------------------------------------------------------------------------------------------------
//   GALGAS_data
//----------------------------------------------------------------------------------------------------------------------

GALGAS_data::GALGAS_data (void) :
AC_GALGAS_root (),
mIsValid (false),
mData () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_data::GALGAS_data (const C_Data & inData) :
AC_GALGAS_root (),
mIsValid (true),
mData (inData) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_data GALGAS_data::constructor_emptyData (UNUSED_LOCATION_ARGS) {
  return GALGAS_data (C_Data ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_data::objectCompare (const GALGAS_data & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t r = mData.compareWithData (inOperand.mData) ;
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

void GALGAS_data::description (C_String & ioString,
                               const int32_t /* inIndentation */) const {
  ioString << "<@data:" ;
  if (isValid ()) {
    ioString << "length=" << cStringWithSigned (mData.count ()) ;
  }else{
    ioString << "not built" ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_data::getter_count (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint (uint32_t (mData.count ())) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_data::getter_cStringRepresentation (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    C_String s (cStringWithUnsigned (mData (0 COMMA_HERE))) ;
    for (int32_t i=1 ; i<mData.count () ; i++) {
      s << ", " << cStringWithUnsigned (mData (i COMMA_HERE)) ;
      if ((i % 16) == 0) {
        s << "\n" ;
      }
    }
    result = GALGAS_string (s) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_data::setter_appendByte (GALGAS_uint inArgument0,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
  if (inArgument0.isValid ()) {
    if (inArgument0.uintValue () > 255) {
      inCompiler->onTheFlyRunTimeError ("'@data appendByte' modifier invoked with value greater than 255" COMMA_THERE) ;
    }else{
      const uint8_t byte = (uint8_t) (inArgument0.uintValue () & UINT8_MAX) ;
      mData.appendByte (byte) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_data::setter_appendShortBE (GALGAS_uint inArgument0,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  if (inArgument0.isValid ()) {
    if (inArgument0.uintValue () > 0xFFFF) {
      inCompiler->onTheFlyRunTimeError ("'@data appendShortBE' modifier invoked with value greater than 0xFFFF" COMMA_THERE) ;
    }else{
      const uint32_t value = inArgument0.uintValue () & 0xFFFFU ;
      mData.appendByte ((uint8_t) ((value >> 8) & UINT8_MAX)) ;
      mData.appendByte ((uint8_t) (value & 255)) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_data::setter_appendShortLE (GALGAS_uint inArgument0,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  if (inArgument0.isValid ()) {
    if (inArgument0.uintValue () > 0xFFFF) {
      inCompiler->onTheFlyRunTimeError ("'@data appendShortLE' modifier invoked with value greater than 0xFFFF" COMMA_THERE) ;
    }else{
      const uint32_t value = inArgument0.uintValue () & 0xFFFFU ;
      mData.appendByte ((uint8_t) (value & 255)) ;
      mData.appendByte ((uint8_t) ((value >> 8) & UINT8_MAX)) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_data::setter_appendUIntBE (GALGAS_uint inArgument0
                                       COMMA_UNUSED_LOCATION_ARGS) {
  if (inArgument0.isValid ()) {
    const uint32_t value = inArgument0.uintValue () ;
    mData.appendByte ((uint8_t) (value >> 24)) ;
    mData.appendByte ((uint8_t) ((value >> 16) & 255)) ;
    mData.appendByte ((uint8_t) ((value >> 8) & 255)) ;
    mData.appendByte ((uint8_t) (value & 255)) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_data::setter_appendUIntLE (GALGAS_uint inArgument0
                                       COMMA_UNUSED_LOCATION_ARGS) {
  if (inArgument0.isValid ()) {
    const uint32_t value = inArgument0.uintValue () ;
    mData.appendByte ((uint8_t) (value & 255)) ;
    mData.appendByte ((uint8_t) ((value >> 8) & 255)) ;
    mData.appendByte ((uint8_t) ((value >> 16) & 255)) ;
    mData.appendByte ((uint8_t) (value >> 24)) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_data::setter_appendUTF_38_String (GALGAS_string inString
                                              COMMA_UNUSED_LOCATION_ARGS) {
  if (inString.isValid ()) {
    const C_String s = inString.stringValue () ;
    for (int32_t i=0 ; i<s.length () ; i++) {
      const utf32 c = s (i COMMA_HERE) ;
      char sequence [5] ;
      const int32_t n = UTF8StringFromUTF32Character (c, sequence) ;
      for (int32_t j=0 ; j<n ; j++) {
        mData.appendByte ((uint8_t) sequence [j]) ;
      }
    }
    mData.appendByte (0) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_data::setter_appendData (GALGAS_data inData
                                     COMMA_UNUSED_LOCATION_ARGS) {
  if (inData.isValid ()) {
    mData.appendData (inData.mData) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

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
        const bool verboseOptionOn = verboseOutput () ;
        bool ok = C_FileManager::makeDirectoryIfDoesNotExist (inFilePath.stringValue ().stringByDeletingLastPathComponent ()) ;
        if (! ok) {
          C_String message ;
          message << "cannot create '" << inFilePath.stringValue () << "' directory" ;
          inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
          outFileWritten.drop () ;
        }else{
          ok = C_FileManager::writeBinaryDataToFile (mData, inFilePath.stringValue ()) ;
          if (ok && verboseOptionOn && fileAlreadyExists) {
            ggs_printFileOperationSuccess (C_String ("Replaced '") + inFilePath.stringValue () + "'.\n") ;
          }else if (ok && verboseOptionOn && ! fileAlreadyExists) {
            ggs_printFileCreationSuccess (C_String ("Created '") + inFilePath.stringValue () + "'.\n") ;
          }else if (! ok) {
            C_String message ;
            message << "cannot write '" << inFilePath.stringValue () << "' file" ;
            inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
            outFileWritten.drop () ;
          }
        }
      }else{
        ggs_printWarning (inCompiler, C_SourceTextInString (), C_IssueWithFixIt (), C_String ("Need to write '") + inFilePath.stringValue () + "'." COMMA_HERE) ;
      }
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_data::method_writeToFile (GALGAS_string inFilePath,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  if (inFilePath.isValid ()) {
    const C_String filePath = inFilePath.stringValue () ;
    if (filePath.length () == 0) {
      inCompiler->onTheFlyRunTimeError ("'@data writeToFile' modifier invoked with empty file path argument" COMMA_THERE) ;
    }else if (! C_Compiler::performGeneration ()) {
      ggs_printWarning (inCompiler, C_SourceTextInString (), C_IssueWithFixIt (), C_String ("Need to write '") + filePath + "'." COMMA_HERE) ;
    }else{
      const bool fileAlreadyExists = C_FileManager::fileExistsAtPath (filePath) ;
      const bool verboseOptionOn = verboseOutput () ;
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
          ggs_printFileOperationSuccess (C_String ("Replaced '") + filePath + "'.\n") ;
        }else if (ok && verboseOptionOn && ! fileAlreadyExists) {
          ggs_printFileCreationSuccess (C_String ("Created '") + filePath + "'.\n") ;
        }else if (! ok) {
          C_String message ;
          message << "cannot write '" << filePath << "' file" ;
          inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
        }
      }
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_data::method_writeToExecutableFile (GALGAS_string inFilePath,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  if (inFilePath.isValid ()) {
    const C_String filePath = inFilePath.stringValue () ;
    if (filePath.length () == 0) {
      inCompiler->onTheFlyRunTimeError ("'@data writeToFile' modifier invoked with empty file path argument" COMMA_THERE) ;
    }else if (! C_Compiler::performGeneration ()) {
      ggs_printWarning (inCompiler, C_SourceTextInString (), C_IssueWithFixIt (), C_String ("Need to write '") + filePath + "'." COMMA_HERE) ;
    }else{
      const bool fileAlreadyExists = C_FileManager::fileExistsAtPath (filePath) ;
      const bool verboseOptionOn = verboseOutput () ;
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
          ggs_printFileOperationSuccess (C_String ("Replaced '") + filePath + "'.\n") ;
        }else if (ok && verboseOptionOn && ! fileAlreadyExists) {
          ggs_printFileOperationSuccess (C_String ("Created '") + filePath + "'.\n") ;
        }else if (! ok) {
          C_String message ;
          message << "cannot write '" << filePath << "' file" ;
          inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
        }
      }
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------
//   cCollectionElement_data
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_data : public cCollectionElement {
//--- Private member
  protected: GALGAS_uint mProperty_data ;
  public: inline GALGAS_uint attribute_data (void) const { return mProperty_data ; }

//--- Default constructor
  public: cCollectionElement_data (const GALGAS_uint & inData
                                    COMMA_LOCATION_ARGS) ;

//--- No copy
  private: cCollectionElement_data (const cCollectionElement_data &) ;
  private: cCollectionElement_data & operator = (const cCollectionElement_data &) ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cCollectionElement * copy (void) ;

//--- Description
 public: virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_data::cCollectionElement_data (const GALGAS_uint & inData
                                                  COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mProperty_data (inData) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_data::isValid (void) const {
  return mProperty_data.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_data::compare (const cCollectionElement * inOperand) const {
  const cCollectionElement_data * operand = (const cCollectionElement_data *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_data) ;
  return mProperty_data.objectCompare (operand->mProperty_data) ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_data::copy (void) {
  cCollectionElement_data * p = nullptr ;
  macroMyNew (p, cCollectionElement_data (mProperty_data COMMA_HERE)) ;
  return p ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_data::description (C_String & ioString, const int32_t inIndentation) const {
  mProperty_data.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     cEnumerator_data class
//
//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark cEnumerator_data
#endif

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_data::populateEnumerationArray (capCollectionElementArray & inEnumerationArray) const {
  const int32_t count = mData.count () ;
  inEnumerationArray.setCapacity (uint32_t (count)) ;
  for (int32_t i=0 ; i<count ; i++) {
    cCollectionElement_data * p = nullptr ;
    macroMyNew (p, cCollectionElement_data (GALGAS_uint (mData (i COMMA_HERE)) COMMA_HERE)) ;
    capCollectionElement object ;
    object.setPointer (p) ;
    macroDetachSharedObject (p) ;
    inEnumerationArray.appendObject (object) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_data::cEnumerator_data (const GALGAS_data & inEnumeratedObject,
                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cEnumerator_data::current_data (LOCATION_ARGS) const {
  const cCollectionElement_data * p = (const cCollectionElement_data *) (currentObjectPtr (THERE)) ;
  macroValidSharedObject (p, cCollectionElement_data) ;
  return p->attribute_data () ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cEnumerator_data::current (LOCATION_ARGS) const {
  const cCollectionElement_data * p = (const cCollectionElement_data *) (currentObjectPtr (THERE)) ;
  macroValidSharedObject (p, cCollectionElement_data) ;
  return p->attribute_data () ;
}

//----------------------------------------------------------------------------------------------------------------------
