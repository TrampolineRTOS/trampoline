//--------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------

#include "all-predefined-types.h"
#include "capCollectionElement.h"
#include "cCollectionElement.h"
#include "Compiler.h"
#include "C_galgas_io.h"
#include "unicode_character_cpp.h"
#include "C_galgas_CLI_Options.h"
#include "BinaryFileWrite.h"
#include "F_verbose_output.h"

//--------------------------------------------------------------------------------------------------
//   GALGAS_data
//--------------------------------------------------------------------------------------------------

GALGAS_data::GALGAS_data (void) :
AC_GALGAS_root (),
mIsValid (false),
mData () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_data::GALGAS_data (const U8Data & inData) :
AC_GALGAS_root (),
mIsValid (true),
mData (inData) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_data GALGAS_data::class_func_emptyData (UNUSED_LOCATION_ARGS) {
  return GALGAS_data (U8Data ()) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_data GALGAS_data::class_func_dataWithContentsOfFile (const GALGAS_string & inFilePath,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_data result ;
  if (inFilePath.isValid()){
    U8Data binaryData ;
    const bool ok = FileManager::binaryDataWithContentOfFile (inFilePath.stringValue (), binaryData) ;
    if (ok) {

      result = GALGAS_data (binaryData) ;
    }else{
      String s = "cannot read binary file at path '" ;
      s.appendString (inFilePath.stringValue ()) ;
      s.appendCString ("'") ;
      inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------

void GALGAS_data::description (String & ioString,
                               const int32_t /* inIndentation */) const {
  ioString.appendCString ("<@data:") ;
  if (isValid ()) {
    ioString.appendCString ("length=") ;
    ioString.appendSigned (mData.count ()) ;
  }else{
    ioString.appendCString ("not built") ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_data::getter_count (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint (uint32_t (mData.count ())) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_data::getter_cStringRepresentation (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    String s ;
    s.appendUnsigned (mData (0 COMMA_HERE)) ;
    for (int32_t i=1 ; i<mData.count () ; i++) {
      s.appendCString (", ") ;
      s.appendUnsigned (mData (i COMMA_HERE)) ;
      if ((i % 16) == 0) {
        s.appendCString ("\n") ;
      }
    }
    result = GALGAS_string (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_data::setter_appendByte (GALGAS_uint inArgument0,
                                     Compiler * inCompiler
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

//--------------------------------------------------------------------------------------------------

void GALGAS_data::setter_appendShortBE (GALGAS_uint inArgument0,
                                        Compiler * inCompiler
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

//--------------------------------------------------------------------------------------------------

void GALGAS_data::setter_appendShortLE (GALGAS_uint inArgument0,
                                        Compiler * inCompiler
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

//--------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------

void GALGAS_data::setter_appendUTF_38_String (GALGAS_string inString
                                              COMMA_UNUSED_LOCATION_ARGS) {
  if (inString.isValid ()) {
    const String s = inString.stringValue () ;
    for (int32_t i=0 ; i<s.length () ; i++) {
      const utf32 c = s.charAtIndex (i COMMA_HERE) ;
      char sequence [5] ;
      const int32_t n = UTF8StringFromUTF32Character (c, sequence) ;
      for (int32_t j=0 ; j<n ; j++) {
        mData.appendByte ((uint8_t) sequence [j]) ;
      }
    }
    mData.appendByte (0) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_data::setter_appendData (GALGAS_data inData
                                     COMMA_UNUSED_LOCATION_ARGS) {
  if (inData.isValid ()) {
    mData.appendData (inData.mData) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_data::method_writeToFileWhenDifferentContents (GALGAS_string inFilePath,
                                                           GALGAS_bool & outFileWritten,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  outFileWritten.drop () ;
  if (inFilePath.isValid ()) {
    bool needToWrite = true ;
    const bool fileAlreadyExists = FileManager::fileExistsAtPath (inFilePath.stringValue ()) ;
    if (fileAlreadyExists) {
      inCompiler->logFileRead (inFilePath.stringValue ()) ;
      U8Data binaryData ;
      FileManager::binaryDataWithContentOfFile (inFilePath.stringValue (), binaryData) ;
      needToWrite = mData != binaryData ;
    }
    outFileWritten = GALGAS_bool (needToWrite) ;
    if (needToWrite) {
      if (Compiler::performGeneration ()) {
        const bool verboseOptionOn = verboseOutput () ;
        bool ok = FileManager::makeDirectoryIfDoesNotExist (inFilePath.stringValue ().stringByDeletingLastPathComponent ()) ;
        if (! ok) {
          String message ;
          message.appendCString ("cannot create '") ;
          message.appendString (inFilePath.stringValue ()) ;
          message.appendCString ("' directory") ;
          inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
          outFileWritten.drop () ;
        }else{
          ok = FileManager::writeBinaryDataToFile (mData, inFilePath.stringValue ()) ;
          if (ok && verboseOptionOn && fileAlreadyExists) {
            ggs_printFileOperationSuccess (String ("Replaced '") + inFilePath.stringValue () + "'.\n") ;
          }else if (ok && verboseOptionOn && ! fileAlreadyExists) {
            ggs_printFileCreationSuccess (String ("Created '") + inFilePath.stringValue () + "'.\n") ;
          }else if (! ok) {
            String message ;
            message.appendCString ("cannot write '") ;
            message.appendString (inFilePath.stringValue ()) ;
            message.appendCString ("' file") ;
            inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
            outFileWritten.drop () ;
          }
        }
      }else{
        ggs_printWarning (inCompiler, SourceTextInString (), C_IssueWithFixIt (), String ("Need to write '") + inFilePath.stringValue () + "'." COMMA_HERE) ;
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_data::method_writeToFile (GALGAS_string inFilePath,
                                      Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  if (inFilePath.isValid ()) {
    const String filePath = inFilePath.stringValue () ;
    if (filePath.length () == 0) {
      inCompiler->onTheFlyRunTimeError ("'@data writeToFile' modifier invoked with empty file path argument" COMMA_THERE) ;
    }else if (! Compiler::performGeneration ()) {
      ggs_printWarning (inCompiler, SourceTextInString (), C_IssueWithFixIt (), String ("Need to write '") + filePath + "'." COMMA_HERE) ;
    }else{
      const bool fileAlreadyExists = FileManager::fileExistsAtPath (filePath) ;
      const bool verboseOptionOn = verboseOutput () ;
      FileManager::makeDirectoryIfDoesNotExist (filePath.stringByDeletingLastPathComponent()) ;
      BinaryFileWrite binaryFile (filePath) ;
      if (! binaryFile.isOpened ()) {
        String s ;
        s.appendCString ("'@data writeToFile': cannot open '") ;
        s.appendString (filePath) ;
        s.appendCString ("' file in write mode") ;
        inCompiler->onTheFlyRunTimeError (s.cString () COMMA_THERE) ;
      }else{
        binaryFile.appendData (mData) ;
        const bool ok = binaryFile.close () ;
        if (ok && verboseOptionOn && fileAlreadyExists) {
          ggs_printFileOperationSuccess (String ("Replaced '") + filePath + "'.\n") ;
        }else if (ok && verboseOptionOn && ! fileAlreadyExists) {
          ggs_printFileCreationSuccess (String ("Created '") + filePath + "'.\n") ;
        }else if (! ok) {
          String message ;
          message.appendCString ("cannot write '") ;
          message.appendString (filePath) ;
          message.appendCString ("' file") ;
          inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
        }
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_data::method_writeToExecutableFile (GALGAS_string inFilePath,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  if (inFilePath.isValid ()) {
    const String filePath = inFilePath.stringValue () ;
    if (filePath.length () == 0) {
      inCompiler->onTheFlyRunTimeError ("'@data writeToFile' modifier invoked with empty file path argument" COMMA_THERE) ;
    }else if (! Compiler::performGeneration ()) {
      ggs_printWarning (inCompiler, SourceTextInString (), C_IssueWithFixIt (), String ("Need to write '") + filePath + "'." COMMA_HERE) ;
    }else{
      const bool fileAlreadyExists = FileManager::fileExistsAtPath (filePath) ;
      const bool verboseOptionOn = verboseOutput () ;
      FileManager::makeDirectoryIfDoesNotExist (filePath.stringByDeletingLastPathComponent()) ;
      BinaryFileWrite binaryFile (filePath) ;
      if (! binaryFile.isOpened ()) {
        String s ;
        s.appendCString ("'@data writeToExecutableFile': cannot open '") ;
        s.appendString (filePath) ;
        s.appendCString ("' file in write mode") ;
        inCompiler->onTheFlyRunTimeError (s.cString () COMMA_THERE) ;
      }else{
        binaryFile.appendData (mData) ;
        const bool ok = binaryFile.close () ;
        FileManager::makeFileExecutable (filePath) ;
        if (ok && verboseOptionOn && fileAlreadyExists) {
          ggs_printFileOperationSuccess (String ("Replaced '") + filePath + "'.\n") ;
        }else if (ok && verboseOptionOn && ! fileAlreadyExists) {
          ggs_printFileOperationSuccess (String ("Created '") + filePath + "'.\n") ;
        }else if (! ok) {
          String message ;
          message.appendCString ("cannot write '") ;
          message.appendString (filePath) ;
          message.appendCString ("' file") ;
          inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
        }
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------
//   cCollectionElement_data
//--------------------------------------------------------------------------------------------------

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
 public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------

cCollectionElement_data::cCollectionElement_data (const GALGAS_uint & inData
                                                  COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mProperty_data (inData) {
}

//--------------------------------------------------------------------------------------------------

bool cCollectionElement_data::isValid (void) const {
  return mProperty_data.isValid () ;
}

//--------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_data::compare (const cCollectionElement * inOperand) const {
  const cCollectionElement_data * operand = (const cCollectionElement_data *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_data) ;
  return mProperty_data.objectCompare (operand->mProperty_data) ;
}

//--------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_data::copy (void) {
  cCollectionElement_data * p = nullptr ;
  macroMyNew (p, cCollectionElement_data (mProperty_data COMMA_HERE)) ;
  return p ;
}

//--------------------------------------------------------------------------------------------------

void cCollectionElement_data::description (String & ioString, const int32_t inIndentation) const {
  mProperty_data.description (ioString, inIndentation) ;
}

//--------------------------------------------------------------------------------------------------
//
//     cEnumerator_data class
//
//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark cEnumerator_data
#endif

//--------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------

cEnumerator_data::cEnumerator_data (const GALGAS_data & inEnumeratedObject,
                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint cEnumerator_data::current_data (LOCATION_ARGS) const {
  const cCollectionElement_data * p = (const cCollectionElement_data *) (currentObjectPtr (THERE)) ;
  macroValidSharedObject (p, cCollectionElement_data) ;
  return p->attribute_data () ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint cEnumerator_data::current (LOCATION_ARGS) const {
  const cCollectionElement_data * p = (const cCollectionElement_data *) (currentObjectPtr (THERE)) ;
  macroValidSharedObject (p, cCollectionElement_data) ;
  return p->attribute_data () ;
}

//--------------------------------------------------------------------------------------------------
