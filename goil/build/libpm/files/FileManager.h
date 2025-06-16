//--------------------------------------------------------------------------------------------------
//
//  'FileManager' : a class for handling files, independantly from platform                    
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2012, ..., 2023 Pierre Molinaro.
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
#include "U8Data.h"

//--------------------------------------------------------------------------------------------------

class FileManager final {
//--- File path conversions
  public: static String unixPathWithNativePath (const String & inFilePath) ;
  public: static String nativePathWithUnixPath (const String & inFilePath) ;

//--- File exists
  public: static bool fileExistsAtPath (const String & inFilePath) ;

//--- File exists
  public: static bool makeFileExecutable (const String & inFilePath) ;

//--- Open file for reading
  public: static FILE * openTextFileForReading (const String & inFilePath) ;

  public: static FILE * openBinaryFileForReading (const String & inFilePath) ;

//--- Read binary file at once
  public: static bool binaryDataWithContentOfFile (const String & inFilePath,
                                                    U8Data & outBinaryData) ;

//--- Read text file at once
  public: static String stringWithContentOfFile (const String & inFilePath) ;

  public: static String stringWithContentOfFile (const String & inFilePath,
                                                    PMTextFileEncoding & outTextFileEncoding,
                                                    bool & outOk) ;

//--- Write string to file
  public: static bool writeStringToFile (const String & inString,
                                          const String & inFilePath) ;

  public: static bool writeStringToExecutableFile (const String & inString,
                                                    const String & inFilePath) ;

//--- Write data to file
  public: static bool writeBinaryDataToFile (const U8Data & inBinaryData,
                                              const String & inFilePath) ;

  public: static bool writeBinaryDataToExecutableFile (const U8Data & inBinaryData,
                                                        const String & inFilePath) ;

//--- Delete file (returns an empty string on success, or a string describing the error)
  public: static String deleteFile (const String & inFilePath) ;

//--- Directory handling
  public: static String currentDirectory (void) ;
  public: static bool directoryExists (const String & inDirectoryPath) ;
  public: static bool directoryExistsWithNativePath (const String & inDirectoryNativePath) ;
  public: static bool makeDirectoryIfDoesNotExist (const String & inDirectoryPath) ;

//--- Remove directory (returns an empty string on success, or a string describing the error)
  public: static String removeDirectory (const String & inDirectoryPath) ;

  public: static String findFileInDirectory (const String & inDirectoryPath,
                                                const String & inFileName,
                                                const TC_UniqueArray <String> & inDirectoriesToExclude) ;

//--- Find all files in directory and subdirectories that respond to a given extension
//    Initial directory is got from receiver value. If it is not a directory, this method does nothing.
//    Found files are appended to outFoundFilePathes.
  public: static void findAllFilesInDirectoryFromExtension (const String & inDirectoryPath,
                                                            const String & inExtension,
                                                            TC_UniqueArray <String> & outFoundFilePathes) ;

//--- Path handling
  public: static bool isAbsolutePath (const String & inPath) ;
  public: static String absolutePathFromCurrentDirectory (const String & inPath) ;
  public: static String absolutePathFromPath (const String & inPath,
                                              const String & inFromPath) ;
  public: static String relativePathFromPath (const String & inPath,
                                              const String & inFromPath) ;


//--- Symbolic Link
  public: static bool makeSymbolicLinkWithPath (const String & inPath,
                                                const String & inLinkPath) ;
  public: static bool isSymbolicLink (const String & inLinkPath) ;
  public: static String stringWithSymbolicLinkContents (const String & inLinkPath,
                                                        bool & outOk) ;

//--- File permissions
  public: static int32_t filePosixPermissions (const String & inFilePath) ;

  public: static int32_t setFilePosixPermissions (const String & inFilePath,
                                                  const int32_t inNewFilePosixPermissions) ;

//--- File modification time
  public: static DateTime fileModificationTime (const String & inFilePath) ;

//--- File size
  public: static uint64_t fileSize (const String & inFilePath) ;
} ;

//--------------------------------------------------------------------------------------------------
