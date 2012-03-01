//---------------------------------------------------------------------------*
//                                                                           *
//  C_String : an implementation of fully dynamic character string           *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 1997, ..., 2011 Pierre Molinaro.                           *
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

#ifndef CLASS_C_STRING_DEFINED
#define CLASS_C_STRING_DEFINED

//---------------------------------------------------------------------------*

#include "utilities/M_SourceLocation.h"
#include "collections/TC_Array.h"
#include "utilities/M_machine.h"
#include "streams/C_ConsoleOut.h"
#include "utilities/TF_Swap.h"
#include "time/C_DateTime.h"

//---------------------------------------------------------------------------*

#include <exception>
#include <stdio.h> 
#include <dirent.h> 

//---------------------------------------------------------------------------*

#ifndef MACHINE_IS_DEFINED
  #error "Undefined machine"
#endif

//---------------------------------------------------------------------------*

#ifdef UNIX_TOOL
  #include <sys/types.h>
  #include <sys/stat.h>
#endif

//---------------------------------------------------------------------------*

#ifdef TARGET_API_MAC_CARBON
  #define MAC_OS_CREATOR_FORMAL_ARGUMENT_NAME       inCreator
  #define COMMA_MAC_OS_CREATOR_FORMAL_ARGUMENT_NAME , MAC_OS_CREATOR_FORMAL_ARGUMENT_NAME
  #define MAC_OS_CREATOR_FORMAL_ARGUMENT            const PMSInt32 MAC_OS_CREATOR_FORMAL_ARGUMENT_NAME
  #define COMMA_MAC_OS_CREATOR_FORMAL_ARGUMENT      , MAC_OS_CREATOR_FORMAL_ARGUMENT
  #define COMMA_CODE_WARRIOR_CREATOR                , 'CWIE'
  #define COMMA_TEACH_TEXT_CREATOR                  , 'ttxt'
  #define COMMA_SAFARI_CREATOR                      , 'sfri'
#else
  #define MAC_OS_CREATOR_FORMAL_ARGUMENT_NAME
  #define COMMA_MAC_OS_CREATOR_FORMAL_ARGUMENT_NAME
  #define MAC_OS_CREATOR_FORMAL_ARGUMENT
  #define COMMA_MAC_OS_CREATOR_FORMAL_ARGUMENT
  #define COMMA_CODE_WARRIOR_CREATOR
  #define COMMA_TEACH_TEXT_CREATOR
  #define COMMA_SAFARI_CREATOR
#endif

//---------------------------------------------------------------------------*

typedef enum {
  kUTF_8_FileEncoding,
  kUTF_16BE_FileEncoding,
  kUTF_16LE_FileEncoding,
  kUTF_32BE_FileEncoding,
  kUTF_32LE_FileEncoding,
  kISO_8859_1_FileEncoding,
  kISO_8859_10_FileEncoding,
  kISO_8859_11_FileEncoding,
  kISO_8859_13_FileEncoding,
  kISO_8859_14_FileEncoding,
  kISO_8859_15_FileEncoding,
  kISO_8859_16_FileEncoding,
  kISO_8859_2_FileEncoding,
  kISO_8859_3_FileEncoding,
  kISO_8859_4_FileEncoding,
  kISO_8859_5_FileEncoding,
  kISO_8859_6_FileEncoding,
  kISO_8859_7_FileEncoding,
  kISO_8859_8_FileEncoding,
  kISO_8859_9_FileEncoding,
  kCP1252_FileEncoding,
  kCP437_DOS_FileEncoding,
  kMacRoman_FileEncoding
} PMTextFileEncoding ;

//---------------------------------------------------------------------------*
//                                                                           *
//      Fully dynamic character string : C_String                            *
//                                                                           *
//---------------------------------------------------------------------------*

class C_String : public AC_OutputStream {
//--- Constructors
  public : C_String (void) ; // Empty string
  public : C_String (const char * chaineC) ; // From a C string
  public : C_String (const utf32 * inUTF32String) ;
//  public : C_String (const PMSInt32 inSignedValue) ; // From an PMSInt32
  
//--- Virtual destructor
  public : virtual ~C_String (void) ;

//--- Handling copy
  public : C_String (const C_String & inSource) ;
  public : C_String & operator = (const C_String & inString) ;

//--- Copy from a C string
  public : C_String & operator = (const char * inSource) ;

//--- Set capacity (does nothing if length >= inCapacity)
  public : void setCapacity (const PMSInt32 inCapacity) ;
  
//--- Suppress 'inLength' characters from 'inLocation' index
  public : void suppress (const PMSInt32 inLocation, const PMSInt32 inLength COMMA_LOCATION_ARGS) ;

//--- Init from a string
  public : void setFromCstring (const char * inCstring) ;
  public : void setFromString (const C_String & inString) ;

//--- hash code
  public : PMUInt32 hash (void) const ;

//--- Set length to 0 ; do not release memory
  public : void setLengthToZero (void) ;

//--- Release memory
  public : void releaseString (void) ;

//--- Get dynamic array allocated size
  public : PMSInt32 capacity (void) const ;

//--- Get current column index (starting from 0)
  public : PMUInt32 currentColumn (void) const ;
  
//--- Append space character until given column
  public : void appendSpacesUntilColumn (const PMUInt32 inColumn) ;

//--- Get a character
  public : utf32 operator () (const PMSInt32 inIndex COMMA_LOCATION_ARGS) const ;
  public : utf32 readCharOrNul (const PMSInt32 inIndex COMMA_LOCATION_ARGS) const ;

//--- Set a character
  public : void setUnicodeCharacterAtIndex (const utf32 inCharacter, const PMSInt32 inIndex COMMA_LOCATION_ARGS) ;

//--- Get last character
  public : utf32 lastCharacter (LOCATION_ARGS) const ;

//--- Get string length
  public : PMSInt32 length (void) const ;

//--- Get a representation that contains only letters, digits or '_', so that 
//    it is a valid C identifier
  public : C_String identifierRepresentation (void) const ;

//--- Get an UTF32 representation
  public : C_String utf32Representation (void) const ;

//--- Get an HTML representation (&, <, > and " are escaped using HTML escape sequence)
  public : C_String HTMLRepresentation (void) const ;

//--- Get MD5 value
  public : C_String md5 (void) const ;

//--- Get a string pointer
  public : const char * cString (LOCATION_ARGS) const ;

//--- Get a UTF32 string pointer
  public : const utf32 * utf32String (LOCATION_ARGS) const ;

//--- Compare with an other string 
  public : PMSInt32 compare (const char * const inCstring) const ;
  public : PMSInt32 compare (const C_String & inString) const ;
  public : PMSInt32 compareStringByLength (const C_String & inString) const ;
  public : bool operator == (const C_String & inString) const ;
  public : bool operator != (const C_String & inString) const ;

//--- Distance from an other string
  public : PMUInt32 LevenshteinDistanceFromString (const C_String & inOtherString) const ;

//--- Get lines array
  public : void getLinesArray (TC_UniqueArray <C_String> & outStringArray) const ;

//--- Subsitute 'inCharacter' by 'inString' ; if the character occurs twice, suppress one
  public : C_String stringByReplacingCharacterByString (const utf32 inCharacter,
                                                        const C_String & inString) const ;

//--- Substitute 'inSearchedString' by 'inReplacementString'
  public : C_String stringByReplacingStringByString (const C_String inSearchedString,
                                                     const C_String & inReplacementString,
                                                     PMUInt32 & outReplacementCount,
                                                     bool & outOk
                                                     COMMA_LOCATION_ARGS) const ;

//--- Get character last occurrence (returns -1 if not found)
  public : PMSInt32 lastOccurrenceIndexOfChar (const utf32 inChar) const ;

//--- Trim white spaces ('\n' or ' '):
//    - at the beginning of the string,
//    - within the string (replace a sequence of white spaces with a single space),
//    - at end at the end of string.
  public : C_String stringByTrimmingWhiteSpaces (void) const ;

//--- Get a sub string
  public : C_String subString (const PMSInt32 inStartIndex,
                               const PMSInt32 inLength) const ;

//--- Get a sub string
  public : C_String leftSubString (const PMSInt32 inLength) const ;
  public : C_String rightSubString (const PMSInt32 inLength) const ;

//--- String concatenation
  public : C_String operator + (const C_String & inOperand) const ;
  public : C_String operator + (const char * inOperand) const ;

//--- Returns a string where ", ', <, > and & have been replaced by &quot;, &apos;, &lt;, &gt; and &amp;
  public : C_String XMLEscapedString (void) const ;

//--- Returns an array containing substrings from the receiver that have been divided by separator
  public : void componentsSeparatedByString (const C_String & inSeparator,
                                             TC_UniqueArray <C_String> & outResult) const ;

//--- Recompose a string from components
  public : static C_String componentsJoinedByString (const TC_UniqueArray <C_String> & inComponentArray,
                                                     const C_String & inSeparator) ;

//--- Interprets the receiver as a path, returning the receiver's extension
  public : C_String pathExtension (void) const ;

//--- Returns a new string made by appending inPathComponent to the receiver, preceded if necessary by a path separator.
  public : C_String stringByAppendingPathComponent (const C_String & inPathComponent) const ;

//--- Returns a string made by deleting the last path component (if any, and only the last)
//    from the receiver.
  public : C_String stringByDeletingLastPathComponent (void) const ;

//--- Returns a string made by deleting the extension (if any, and only the last)
//    from the receiver.
  public : C_String stringByDeletingPathExtension (void) const ;

//--- Returns a string made by deleting from the receiver all characters from inSearchedString
  public : C_String stringByDeletingTailFromString (const C_String & inSearchedString) const ;

//--- Returns the last path component of the receiver.
  public : C_String lastPathComponent (void) const ;
  public : C_String lastPathComponentWithoutExtension (void) const ;

//--- Contains an other string ?
  public : bool containsString (const C_String & inSearchedString) const ;

//--- Return string, with first letter in upper case
  public : C_String stringByCapitalizingFirstCharacter (void) const ;

//--- Return string, with all letters in upper case
  public : C_String uppercaseString (void) const ;

//--- Return string, with all letters in lower case
  public : C_String lowercaseString (void) const ;

//--- Return reversed string
  public : C_String reversedString (void) const ;

//--- Get current column index (starting from 0)
  public : static C_String stringWithRepeatedCharacter (const utf32 inRepeatedCharacter, const PMUInt32 inCount) ;

//--- Conversion to and from native path
  public : C_String unixPathWithNativePath (void) const ;
  public : C_String nativePathWithUnixPath (void) const ;

//--- Standardizing Path
//    - first, convert Windows Path to Unix Path (on windows only)
//    - Reduce empty components and references to the current directory (that is, the sequences "//" and "/./") to single path separators
  public : C_String stringByStandardizingPath (void) const ;

//--- Current directory (returns always an Unux path)
  public : static C_String currentDirectory (void) ;
  
  public : bool makeDirectoryIfDoesNotExist (void) const ;

  public : static C_String stringWithContentOfFile (const C_String & inFilePath) ;

  public : static C_String stringWithContentOfFile (const C_String & inFilePath,
                                                    PMTextFileEncoding & outTextFileEncoding,
                                                    bool & outOK) ;

  public : bool writeToFile (const C_String & inFilePath
                             COMMA_MAC_OS_CREATOR_FORMAL_ARGUMENT
                             COMMA_LOCATION_ARGS) const ;

  public : bool writeToExecutableFile (const C_String & inFilePath
                                       COMMA_MAC_OS_CREATOR_FORMAL_ARGUMENT
                                       COMMA_LOCATION_ARGS) const ;

  public : bool writeBinaryData (const TC_UniqueArray <PMUInt8> & inBinaryData) const ;

  public : C_DateTime fileModificationTime (void) const ;

  public : bool fileExists (void) const ;

  public : bool directoryExists (void) const ;

  public : bool binaryDataWithContentOfFile (TC_UniqueArray <PMUInt8> & outBinaryData) const ;

  public : PMSInt32 filePosixPermissions (void) const ;

  public : PMSInt32 setFilePosixPermissions (const PMSInt32 inNewFilePosixPermissions) const ;


//--- Testing for absolute path (not empty and begins with '/')
  public : bool isAbsolutePath (void) const ;

//--- If receiver is an absolute path, returns it
//    Otherwise, prepend current directory
  public : C_String absolutePathFromCurrentDirectory (void) const ;

//--- If receiver is an absolute path, returns it
//    Otherwise, prepend path argument
//    if path argument it self is relative, current directory is prepended
  public : C_String absolutePathFromPath (const C_String & inPath) const ;

//--- Return the relative path of the receiver from inPath 
  public : C_String relativePathFromPath (const C_String & inPath) const ;

//--- Find file in directory
  public : C_String findFileInDirectory (const C_String & inFileName,
                                         const TC_UniqueArray <C_String> & inDirectoriesToExclude) const ;

//--- Find all files in directory and subdirectories that respond to a given extension
//    Initial directory is got from receiver value. If it is not a directory, this method does nothing.
//    Found files are appended to outFoundFilePathes.
  public : void findAllFilesInDirectoryFromExtension (const C_String & inExtension,
                                                      TC_UniqueArray <C_String> & outFoundFilePathes) const ;

//--- Delete file (returns NULL on success, or a string describing the error)
  public : const char * deleteFile (void) const ;
  
//--- Remove directory (returns NULL on success, or a string describing the error)
  public : const char * removeDirectory (void) const ;

//---------------- Symbolic links --------------
  public : bool isSymbolicLink (void) const ;

  public : C_String stringWithSymbolicLinkContents (bool & outOk) const ;

  public : bool makeSymbolicLinkWithPath (const C_String & inPath) const ;

//---------------- Virtual output stream methods --------------
  protected : virtual void
  performActualCharArrayOutput (const char * inCharArray,
                                const PMSInt32 inArrayCount) ;

  protected : virtual void
  performActualUnicodeArrayOutput (const utf32 * inCharArray,
                                   const PMSInt32 inArrayCount) ;

//--- Private (internal) methods
  private : void insulateEmbeddedString (const PMSInt32 inNewCapacity) ;

  #ifndef DO_NOT_GENERATE_CHECKINGS
    private : void checkString (LOCATION_ARGS) const ;
  #endif

  public : static bool parseUTF8 (const PMUInt8 * inCString,
                                  const PMSInt32 inLength,
                                  C_String & outString) ;

//---------------- Private attributes -------------
  private : class cEmbeddedString * mEmbeddedString ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//  Exception generated by readTextFile method when a read error occurs      *
//                                                                           *
//---------------------------------------------------------------------------*

const size_t kTextReadExceptionStringMaxLength = 1000 ;

class C_TextReadException : public M_STD_NAMESPACE  exception {
  public : C_TextReadException (const char * inFileName) ;

  private : char mErrorMessage [kTextReadExceptionStringMaxLength + 1] ;

  public : virtual const char * what (void) const throw () ;
} ;

//---------------------------------------------------------------------------*

#endif
