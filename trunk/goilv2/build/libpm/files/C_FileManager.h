//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  'C_FileManager' : a class for handling files,                              *
//  independantly from platform                                                *
//                                                                                                                     *
//  This file is part of libpm library                                         *
//                                                                                                                     *
//  Copyright (C) 2012, ..., 2012 Pierre Molinaro.                             *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes                                          *
//  ECN, École Centrale de Nantes (France)                                                                             *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it                                            *
//  under the terms of the GNU Lesser General Public License as published                                              *
//  by the Free Software Foundation; either version 2 of the License, or                                               *
//  (at your option) any later version.                                                                                *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT                                             *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or                                              *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for                                           *
//  more details.                                                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef FILE_MANAGER_DEFINED
#define FILE_MANAGER_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "strings/C_String.h"
#include "utilities/C_Data.h"

//---------------------------------------------------------------------------------------------------------------------*

class C_FileManager {
//--- File path conversions
  public : static C_String unixPathWithNativePath (const C_String & inFilePath) ;
  public : static C_String nativePathWithUnixPath (const C_String & inFilePath) ;

//--- File exists
  public : static bool fileExistsAtPath (const C_String & inFilePath) ;

//--- File exists
  public : static bool makeFileExecutable (const C_String & inFilePath) ;

//--- Open file for reading
  public : static FILE * openTextFileForReading (const C_String & inFilePath) ;

  public : static FILE * openBinaryFileForReading (const C_String & inFilePath) ;

//--- Read binary file at once
  public : static bool binaryDataWithContentOfFile (const C_String & inFilePath,
                                                    C_Data & outBinaryData) ;

//--- Read text file at once
  public : static C_String stringWithContentOfFile (const C_String & inFilePath) ;

  public : static C_String stringWithContentOfFile (const C_String & inFilePath,
                                                    PMTextFileEncoding & outTextFileEncoding,
                                                    bool & outOk) ;
//--- Write string to file
  public : static bool writeStringToFile (const C_String & inString,
                                          const C_String & inFilePath) ;

  public : static bool writeStringToExecutableFile (const C_String & inString,
                                                    const C_String & inFilePath) ;

//--- Write data to file
  public : static bool writeBinaryDataToFile (const C_Data & inBinaryData,
                                              const C_String & inFilePath) ;

  public : static bool writeBinaryDataToExecutableFile (const C_Data & inBinaryData,
                                                        const C_String & inFilePath) ;

//--- Delete file (returns an empty string on success, or a string describing the error)
  public : static C_String deleteFile (const C_String & inFilePath) ;

//--- Directory handling
  public : static C_String currentDirectory (void) ;
  public : static bool directoryExists (const C_String & inDirectoryPath) ;
  public : static bool makeDirectoryIfDoesNotExist (const C_String & inDirectoryPath) ;

//--- Remove directory (returns an empty string on success, or a string describing the error)
  public : static C_String removeDirectory (const C_String & inDirectoryPath) ;

  public : static C_String findFileInDirectory (const C_String & inDirectoryPath,
                                                const C_String & inFileName,
                                                const TC_UniqueArray <C_String> & inDirectoriesToExclude) ;

//--- Find all files in directory and subdirectories that respond to a given extension
//    Initial directory is got from receiver value. If it is not a directory, this method does nothing.
//    Found files are appended to outFoundFilePathes.
  public : static void findAllFilesInDirectoryFromExtension (const C_String & inDirectoryPath,
                                                             const C_String & inExtension,
                                                             TC_UniqueArray <C_String> & outFoundFilePathes) ;

//--- Path handling
  public : static bool isAbsolutePath (const C_String & inPath) ;
  public : static C_String absolutePathFromCurrentDirectory (const C_String & inPath) ;
  public : static C_String absolutePathFromPath (const C_String & inPath,
                                                 const C_String & inFromPath) ;
  public : static C_String relativePathFromPath (const C_String & inPath,
                                                 const C_String & inFromPath) ;


//--- Symbolic Link
  public : static bool makeSymbolicLinkWithPath (const C_String & inPath,
                                                 const C_String & inLinkPath) ;
  public : static bool isSymbolicLink (const C_String & inLinkPath) ;
  public : static C_String stringWithSymbolicLinkContents (const C_String & inLinkPath,
                                                           bool & outOk) ;

//--- File permissions
  public : static int32_t filePosixPermissions (const C_String & inFilePath) ;

  public : static int32_t setFilePosixPermissions (const C_String & inFilePath,
                                                    const int32_t inNewFilePosixPermissions) ;

//--- File modification time
  public : static C_DateTime fileModificationTime (const C_String & inFilePath) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

#endif
