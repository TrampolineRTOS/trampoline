//---------------------------------------------------------------------------*
//                                                                           *
//   GALGAS_data : this class implements the GALGAS 'data' native type       *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2009, ..., 2011 Pierre Molinaro.                           *
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
#include "capCollectionElement.h"
#include "cCollectionElement.h"
#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "strings/unicode_character_cpp.h"
#include "galgas2/C_galgas_CLI_Options.h"

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

GALGAS_data::GALGAS_data (const TC_Array <PMUInt8> & inOperand_mData) :
mIsValid (true),
mData (inOperand_mData) {
}

//---------------------------------------------------------------------------*

GALGAS_data::GALGAS_data (const PMUInt8 * inSourceArray,
                          const PMUInt32 inLength) :
mIsValid (true),
mData () {
  mData.makeRoom ((PMSInt32) inLength) ;
  for (PMUInt32 i=0 ; i<inLength ; i++) {
    mData.addObject (inSourceArray [i]) ;
  }
}

//---------------------------------------------------------------------------*

GALGAS_data GALGAS_data::constructor_emptyData (UNUSED_LOCATION_ARGS) {
  TC_Array <PMUInt8> t ;
  return GALGAS_data (t) ;
}

//---------------------------------------------------------------------------*

GALGAS_data GALGAS_data::constructor_dataWithContentsOfFile (const GALGAS_string & inFilePath,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  GALGAS_data result ;
  if (inFilePath.isValid()){
    TC_Array <PMUInt8> t ;
    const bool ok = inFilePath.stringValue ().binaryDataWithContentOfFile (t) ;
    if (ok) {
      result = GALGAS_data (t) ;
    }else{
      C_String s ;
      s << "cannot read binary file at path '" << inFilePath.stringValue () << "'" ;
      inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

static PMSInt32 compareData (const TC_Array <PMUInt8> & inData1, const TC_Array <PMUInt8> & inData2) {
  PMSInt32 result = inData1.count () - inData2.count () ;
  for (PMSInt32 i=0 ; (i<inData1.count ()) && (result == 0) ; i++) {
    result = ((PMSInt32) inData1 (i COMMA_HERE)) - ((PMSInt32) inData2 (i COMMA_HERE)) ;  
  }  
  return result ;
}

//---------------------------------------------------------------------------*

typeComparisonResult GALGAS_data::objectCompare (const GALGAS_data & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const PMSInt32 r = compareData (mData, inOperand.mData) ;
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
    ioString << "length=" << cStringWithSigned (mData.count ()) ;
  }else{
    ioString << "not built" ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------*

GALGAS_uint GALGAS_data::reader_length (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint ((PMUInt32) mData.count ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_data::reader_cStringRepresentation (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    C_String s (cStringWithUnsigned (mData (0 COMMA_HERE))) ;
    for (PMSInt32 i=1 ; i<mData.count () ; i++) {
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
      mData.addObject (byte) ;
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
      mData.addObject ((PMUInt8) ((value >> 8) & PMUINT8_MAX)) ;
      mData.addObject ((PMUInt8) (value & 255)) ;
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
      mData.addObject ((PMUInt8) (value & 255)) ;
      mData.addObject ((PMUInt8) ((value >> 8) & PMUINT8_MAX)) ;
    }
  }
}

//---------------------------------------------------------------------------*

void GALGAS_data::modifier_appendUIntBE (GALGAS_uint inArgument0
                                         COMMA_UNUSED_LOCATION_ARGS) {
  if (inArgument0.isValid ()) {
    const PMUInt32 value = inArgument0.uintValue () ;
    mData.addObject ((PMUInt8) (value >> 24)) ;
    mData.addObject ((PMUInt8) ((value >> 16) & 255)) ;
    mData.addObject ((PMUInt8) ((value >> 8) & 255)) ;
    mData.addObject ((PMUInt8) (value & 255)) ;
  }
}

//---------------------------------------------------------------------------*

void GALGAS_data::modifier_appendUIntLE (GALGAS_uint inArgument0
                                         COMMA_UNUSED_LOCATION_ARGS) {
  if (inArgument0.isValid ()) {
    const PMUInt32 value = inArgument0.uintValue () ;
    mData.addObject ((PMUInt8) (value & 255)) ;
    mData.addObject ((PMUInt8) ((value >> 8) & 255)) ;
    mData.addObject ((PMUInt8) ((value >> 16) & 255)) ;
    mData.addObject ((PMUInt8) (value >> 24)) ;
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
        mData.addObject ((PMUInt8) sequence [j]) ;
      }
    }
    mData.addObject (0) ;
  }
}

//---------------------------------------------------------------------------*

void GALGAS_data::modifier_appendData (GALGAS_data inData
                                       COMMA_UNUSED_LOCATION_ARGS) {
  if (inData.isValid ()) {
    mData.addObjectsFromArray (inData.mData) ;
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
    const bool fileAlreadyExists = inFilePath.stringValue ().fileExists () ;
    if (fileAlreadyExists) {
      inCompiler->logFileRead (inFilePath.stringValue ()) ;
      TC_UniqueArray <PMUInt8> binaryData ;
      inFilePath.stringValue ().binaryDataWithContentOfFile (binaryData) ;
      needToWrite = mData != binaryData ;
    }
    outFileWritten = GALGAS_bool (needToWrite) ;
    if (needToWrite) {
      if (inCompiler->mPerformGeneration) {
        const bool verboseOptionOn = gOption_galgas_5F_cli_5F_options_verbose_5F_output.mValue ;
        bool ok = inFilePath.stringValue ().stringByDeletingLastPathComponent ().makeDirectoryIfDoesNotExist () ;
        if (! ok) {
          C_String message ;
          message << "cannot create '" << inFilePath.stringValue () << "' directory" ;
          inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
          outFileWritten.drop () ;
        }else{
          ok = inFilePath.stringValue ().writeBinaryData (mData) ;
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

#ifdef TARGET_API_MAC_CARBON
  static C_String unixPath2macOSpath (const C_String & inPath) {
    C_String macOSpath ;
    const PMSInt32 length = inPath.length () ;
    if (length > 0) {
    //--- Replace '/' by ':'
      for (PMSInt32 i=0 ; i<length ; i++) {
        const utf32 c = inPath (i COMMA_HERE) ;
        macOSpath.appendUnicodeCharacter ((UNICODE_VALUE (c) == '/') ? TO_UNICODE (':') : c COMMA_HERE) ;
      }
    //--- if first character is ':', following char must be 'Volumes:' : suppress them
      if ((UNICODE_VALUE (macOSpath (0 COMMA_HERE)) == ':') && (macOSpath.length () > 9)) {
        macOSpath.suppress (0, 9 COMMA_HERE) ;
      }
    }
    return macOSpath ;
  }
#endif

//---------------------------------------------------------------------------*

#ifdef COMPILE_FOR_WIN32
  static C_String unixPath2winPath (const C_String & inWinFileName) {
    C_String winFileName ;
      const PMSInt32 fileLength = inWinFileName.length () ;
      PMSInt32 firstChar = 0 ;
      if ((fileLength > 3)
       && (UNICODE_VALUE (inWinFileName (0 COMMA_HERE)) == '/')
       && isalpha ((int) UNICODE_VALUE (inWinFileName (1 COMMA_HERE)))
       && (UNICODE_VALUE (inWinFileName (2 COMMA_HERE)) == '/')) {
        winFileName.appendUnicodeCharacter (inWinFileName (1 COMMA_HERE) COMMA_HERE) ;
        winFileName << ":\\" ;
        firstChar = 3 ;
      }
      for (PMSInt32 i=firstChar ; i<fileLength ; i++) {
        const utf32 c = (UNICODE_VALUE (inWinFileName (i COMMA_HERE)) == '/')
          ? TO_UNICODE ('\\')
          : inWinFileName (i COMMA_HERE) ;
        winFileName.appendUnicodeCharacter (c COMMA_HERE) ;
      }
    return winFileName ;
  }
#endif

//---------------------------------------------------------------------------*

void GALGAS_data::method_writeToFile (GALGAS_string inFilePath,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  if (inFilePath.isValid ()) {
    const C_String filePath = inFilePath.stringValue () ;
    if (filePath.length () == 0) {
      inCompiler->onTheFlyRunTimeError ("'@data writeToFile' modifier invoked with empty file path argument" COMMA_THERE) ;
    }else if (! inCompiler->mPerformGeneration) {
      ggs_printWarning (NULL, C_LocationInSource (), C_String ("Need to write '") + filePath + "'.\n" COMMA_HERE) ;
    }else{
      const bool fileAlreadyExists = filePath.fileExists () ;
      const bool verboseOptionOn = gOption_galgas_5F_cli_5F_options_verbose_5F_output.mValue ;
      filePath.stringByDeletingLastPathComponent().makeDirectoryIfDoesNotExist () ;
      FILE * filePtr = NULL ;
//--- If 'inFileName' is the empty string, do not create the file
//    so that 'mFilePtr' remains equal to NULL
    //--- Open file in "w" mode
    //--- Mac OS : fix creator and type
      #ifdef TARGET_API_MAC_CARBON
        filePtr = ::fopen (unixPath2macOSpath (filePath).cString (HERE), "w") ;
      #elif defined (COMPILE_FOR_WIN32)
        filePtr = ::fopen (unixPath2winPath (filePath).cString (HERE), "w") ;
      #else
        filePtr = ::fopen (filePath.cString (HERE), "w") ;
      #endif
      if (filePtr == NULL) {
        C_String s ;
        s << "'@data writeToFile' : cannot open '" << filePath << "' file in write mode" ;
        inCompiler->onTheFlyRunTimeError (s.cString (HERE) COMMA_THERE) ;
      }else{
        const PMUInt32 writtenCount = (PMUInt32) (fwrite (mData.bufferPointer (), 1, (PMUInt32) mData.count (), filePtr) & PMUINT32_MAX) ;
        const bool ok = (::fclose (filePtr) == 0) && (writtenCount == (PMUInt32) mData.count ()) ;
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
  const PMUInt32 count = (PMUInt32) mData.count () ;
  inEnumerationArray.setCapacity (count) ;
  switch (enumerationOrderValue (inEnumerationOrder)) {
  case kENUMERATION_UP:
    for (PMUInt32 i=0 ; i<count ; i++) {
      cCollectionElement_data * p = NULL ;
      macroMyNew (p, cCollectionElement_data (GALGAS_uint (mData ((PMSInt32) i COMMA_HERE)) COMMA_HERE)) ;
      capCollectionElement object ;
      object.setPointer (p) ;
      macroDetachSharedObject (p) ;
      inEnumerationArray.addObject (object) ;
    }
    break ;
  case kENUMERATION_DOWN:
    for (PMUInt32 i=0 ; i<count ; i++) {
      cCollectionElement_data * p = NULL ;
      macroMyNew (p, cCollectionElement_data (GALGAS_uint (mData ((PMSInt32) (mData.count () - i - 1) COMMA_HERE)) COMMA_HERE)) ;
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
