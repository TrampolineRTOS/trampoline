//--------------------------------------------------------------------------------------------------
//
//  Routine 'F_Analyze_CLI_Options' : a way for automatic command line options analysis for MacOS, Win32 and Unix.     *
//
//  This file is part of libpm library
//
//  Copyright (C) 2001, ..., 2024 Pierre Molinaro.
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

#include "F_Analyze_CLI_Options.h"
#include "C_BoolCommandLineOption.h"
#include "C_UIntCommandLineOption.h"
#include "C_StringCommandLineOption.h"
#include "C_StringListCommandLineOption.h"
#include "C_builtin_CLI_Options.h"
#include "C_ConsoleOut.h"
#include "FileManager.h"

//--------------------------------------------------------------------------------------------------

#include <string.h>
#include <ctype.h>

//--------------------------------------------------------------------------------------------------

#ifndef COMPILE_FOR_WINDOWS
  #error COMPILE_FOR_WINDOWS is undefined
#endif

//--------------------------------------------------------------------------------------------------

#if COMPILE_FOR_WINDOWS == 1
  #include <windows.h>
#endif

//--------------------------------------------------------------------------------------------------
//
//                        C O C O A   O U T P U T
//
//--------------------------------------------------------------------------------------------------

static bool gCocoaOutput = false ;

//--------------------------------------------------------------------------------------------------

bool cocoaOutput (void) {
  return gCocoaOutput ;
}

//--------------------------------------------------------------------------------------------------

const char * galgasVersionString (void) {
  return "GALGASBETAVERSION" ;
}

//--------------------------------------------------------------------------------------------------
//
//     print_usage
//
//--------------------------------------------------------------------------------------------------

static void print_usage (int argv, const char * argc []) {
  gCout.setForeColor (kMagentaForeColor) ;
  gCout.setTextAttribute (kBoldTextAttribute) ;
  gCout.appendCString ("Usage:\n") ;
  gCout.setTextAttribute (kAllAttributesOff) ;
  if (argv > 0) {
    gCout.appendCString (argc [0]) ;
  }
  C_BoolCommandLineOption::printUsageOfBoolOptions () ;
  C_UIntCommandLineOption::printUsageOfUIntOptions () ;
  C_StringCommandLineOption::printUsageOfStringOptions () ;
  C_StringListCommandLineOption::printUsageOfStringOptions () ;
  gCout.appendCString (" file...\n") ;
}

//--------------------------------------------------------------------------------------------------
//
//     print_options
//
//--------------------------------------------------------------------------------------------------

static void print_option_list (void) {
  printf ("*** Available command line options:\n") ;
  C_BoolCommandLineOption::printBoolOptions () ;
  C_UIntCommandLineOption::printUIntOptions () ;
  C_StringCommandLineOption::printStringOptions () ;
  C_StringListCommandLineOption::printStringOptions () ;
}

//--------------------------------------------------------------------------------------------------
//
//     print_help
//
//--------------------------------------------------------------------------------------------------

static void print_help (const int argv,
                        const char* * argc,
                        const char* * inExtensionArray,
                        const char* * inHelpMessageArray,
                        void print_tool_help_message (void)) {
  #ifdef __LP64__
    gCout.appendCString ("Compiled in 64 bits mode") ;
  #else
    gCout.appendCString ("Compiled in 32 bits mode") ;
  #endif
  #ifndef DO_NOT_GENERATE_CHECKINGS
    gCout.appendCString (" (with debug code)") ;
  #endif
  gCout.appendCString (".\n") ;
  print_tool_help_message () ;
  print_usage (argv, argc) ;
  gCout.setForeColor (kMagentaForeColor) ;
  gCout.setTextAttribute (kBoldTextAttribute) ;
  gCout.appendCString ("Options:\n") ;
  gCout.setTextAttribute (kAllAttributesOff) ;
  gCout.appendCString ("You can place options anywhere in the command line: they will be executed before the files are processed.\n") ;
  C_BoolCommandLineOption::printBoolOptions () ;
  C_UIntCommandLineOption::printUIntOptions () ;
  C_StringCommandLineOption::printStringOptions () ;
  C_StringListCommandLineOption::printStringOptions () ;

  int32_t extensionIndex = 0 ;
  while (inExtensionArray [extensionIndex] != nullptr) {
    extensionIndex ++ ;
  }
  gCout.setForeColor (kMagentaForeColor) ;
  gCout.setTextAttribute (kBoldTextAttribute) ;
  gCout.appendCString ("Handled extension") ;
  gCout.appendCString ((extensionIndex > 1) ? "s" : "") ;
  gCout.appendCString (":\n") ;
  gCout.setTextAttribute (kAllAttributesOff) ;
  extensionIndex = 0 ;
  while (inExtensionArray [extensionIndex] != nullptr) {
    gCout.setForeColor (kBlueForeColor) ;
    gCout.setTextAttribute (kBoldTextAttribute) ;
    gCout.appendCString (".") ;
    gCout.appendCString (inExtensionArray [extensionIndex]) ;
    gCout.setTextAttribute (kAllAttributesOff) ;
    const uint32_t extensionLength = (uint32_t) (strlen (inExtensionArray [extensionIndex]) & UINT32_MAX) ;
    const uint32_t kDisplayLength = 20 ;
    if (extensionLength < kDisplayLength) {
      for (uint32_t i=extensionLength ; i<kDisplayLength ; i++) {
        gCout.appendCString (" ") ;
      }
    }else{
      gCout.appendNewLine () ; ;
      gCout.appendSpaces (kDisplayLength+2) ;
    }
    gCout.appendCString (inHelpMessageArray [extensionIndex]) ;
    gCout.appendNewLine () ; ;
    extensionIndex ++ ;
  }
}

//--------------------------------------------------------------------------------------------------
//
//     Command line option beginning with a single '-'
//
//--------------------------------------------------------------------------------------------------

static void option_beginning_with_single_minus_sign (const String & inCommand, // Without leading '-'
                                                     bool & outOk) {
  outOk = false ;
  const int32_t optionLength = inCommand.length () ;
//--- Search for boolean option (minus following by a character)
  if (optionLength == 1) {
    C_BoolCommandLineOption::setBoolOptionForCommandChar (inCommand.charAtIndex (0 COMMA_HERE), outOk) ;
    if (! outOk) {
      gCout.appendCString ("Error : unknown '") ;
      gCout.appendString (inCommand) ;
      gCout.appendCString ("' command line option.\n") ;
    }
  }else if (optionLength > 1) {
    const String command = inCommand.subStringFromIndex (1) ;
  //--- Search for an UInt option
    bool correctFormat = false ;
    C_UIntCommandLineOption::setUIntOptionForCommandChar (command, outOk, correctFormat) ;
  //--- Not found : search for a string option
    if (! outOk) {
      C_StringCommandLineOption::setStringOptionForCommandChar (command, outOk, correctFormat) ;
    }
    if (! outOk) {
      C_StringListCommandLineOption::setStringListOptionForCommandChar (command, outOk, correctFormat) ;
    }
    if (! outOk) {
      gCout.appendCString ("Error : unknown '-") ;
      gCout.appendString (inCommand) ;
      gCout.appendCString ("' command line option.\n") ;
    }else if (! correctFormat) {
      outOk = false ;
      gCout.appendCString ("Error : incorrect format for '-") ;
      gCout.appendString (inCommand) ;
      gCout.appendCString ("' command line option (correct format is : '-") ;
      gCout.appendString (inCommand) ;
      gCout.appendCString ("=value').\n") ;
    }
  }else{
    gCout.appendCString ("Error : unknown '-") ;
    gCout.appendString (inCommand) ;
    gCout.appendCString ("' command line option.\n") ;
  }
}

//--------------------------------------------------------------------------------------------------
//
//     Command line option beginning with '--'
//
//--------------------------------------------------------------------------------------------------

static void option_beginning_with_double_minus_sign (const String & inCommand,
                                                     bool & outFound) {
  outFound = false ;
  bool correctFormat = true ;
//--- Look for a boolean argument
  C_BoolCommandLineOption::setBoolOptionForCommandString (inCommand, outFound, gCocoaOutput) ;
//--- If not found, look for a Uint option
  if (! outFound) {
    C_UIntCommandLineOption::setUIntOptionForCommandString (inCommand, outFound, correctFormat) ;
  }
//--- If not found, look for a String option
  if (! outFound) {
    C_StringCommandLineOption::setStringOptionForCommandString (inCommand, outFound, correctFormat) ;
  }
  if (! outFound) {
    C_StringListCommandLineOption::setStringListOptionForCommandString (inCommand, outFound, correctFormat) ;
  }
  if (! outFound) {
    gCout.appendCString ("Error : unknown '--") ;
    gCout.appendString (inCommand) ;
    gCout.appendCString ("' command line option.\n") ;
  }else if (! correctFormat) {
    outFound = false ;
    gCout.appendCString ("Error : incorrect format for '--") ;
    gCout.appendString (inCommand) ;
    gCout.appendCString ("' command line option.\n") ;
  }
}

//--------------------------------------------------------------------------------------------------
//
//     analyze_one_option
//
//--------------------------------------------------------------------------------------------------

static void analyze_one_option (const String & inCommand,
                                TC_UniqueArray <String> & outSourceFileArray,
                                bool & outOk) {
  const int32_t optionLength = inCommand.length () ;
  bool found = false ;
//--- Begin by a '-' character ?
  if ((optionLength > 1) && (inCommand.charAtIndex (0 COMMA_HERE) == '-')) {
  //--- Second character is also a '-' ?
    if ((optionLength > 2) && (inCommand.charAtIndex (1 COMMA_HERE) == '-')) {
    //--- two minus signs '--' at beginning
      const String command = inCommand.subStringFromIndex (2) ;
      option_beginning_with_double_minus_sign (command, found) ;
    }else{
    //--- Single '-' at beginning
      const String command = inCommand.subStringFromIndex (1) ;
      option_beginning_with_single_minus_sign (command, found) ;
    }
  }
//--- Look for a file
  if (! found) {
    if (UNICODE_VALUE (inCommand.charAtIndex (0 COMMA_HERE)) != '-') {
      String fileName ;
      #if COMPILE_FOR_WINDOWS == 1
        const int32_t fileLength = inCommand.length () ;
        int32_t firstChar = 0 ;
        if ((fileLength > 3)
         && isalpha (int (UNICODE_VALUE (inCommand.charAtIndex (0 COMMA_HERE))))
         && (inCommand.charAtIndex (1 COMMA_HERE) == ':')
         && (inCommand.charAtIndex (2 COMMA_HERE) == '\\')) {
          fileName.appendCString ("/") ;
          fileName.appendChar (inCommand.charAtIndex (0 COMMA_HERE)) ;
          fileName.appendCString ("/") ;
          firstChar = 3 ;
        }
        for (int32_t i=firstChar ; i<fileLength ; i++) {
          const utf32 c = inCommand.charAtIndex (i COMMA_HERE) ;
          fileName.appendChar ((UNICODE_VALUE (c) == '\\') ? '/' : c) ;
        }
      #else
        fileName = inCommand ;
      #endif
      outSourceFileArray.appendObject (FileManager::absolutePathFromPath (fileName, String ())) ;
      found = true ;
    }
  }
//--- Error ?
  if (! found) {
    outOk = false ;
  }
}

//--------------------------------------------------------------------------------------------------

#if COMPILE_FOR_WINDOWS == 1
  static void getSourceFileFromWin32OpenDialog (TC_UniqueArray <String> & outSourceFileArray,
                                                const char * * inExtensionArray) {
    char szFile[260] ;       // buffer for file name
    OPENFILENAME ofn ;
  //--- Initialize OPENFILENAME
    ZeroMemory (& ofn, sizeof(ofn)) ;
    ofn.lStructSize = sizeof (ofn) ;
    ofn.hwndOwner = nullptr ;
    ofn.lpstrFile = szFile ;
  // Set lpstrFile[0] to '\0' so that GetOpenFileName does not
  // use the contents of szFile to initialize itself.
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof (szFile) ;
    char filterString [1000] = "";
    int32_t filterIndex = 0 ;
    while (inExtensionArray [filterIndex] != nullptr) {
      if (filterIndex != 0) {
        strcat (filterString, ";") ;
      }
      strcat (filterString, "*.") ;
      strcat (filterString, inExtensionArray [filterIndex]) ;
      filterIndex ++ ;
    }
    char filter [1000] ;
    const char zero = '\0' ;
    snprintf (filter, 999, "%c%s%c", zero, filterString, zero) ;
    ofn.lpstrFilter = filter ;
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = nullptr;
    ofn.nMaxFileTitle = 0 ;
    char * currentDir = getcwd (nullptr, 0) ;
    ofn.lpstrInitialDir = currentDir ;
    ofn.lpstrTitle = nullptr ;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY ;
    if (GetOpenFileName (& ofn)) {
      String fileName ;
      const int32_t fileLength = (int32_t) strlen (szFile) ;
      int32_t firstChar = 0 ;
      if ((fileLength > 3)
       && isalpha (szFile [0])
       && (szFile [1] == ':')
       && (szFile [2] == '\\')) {
        fileName.appendCString ("/") ;
        fileName.appendChar (TO_UNICODE (szFile [0])) ;
        fileName.appendCString ("/") ;
        firstChar = 3 ;
      }
      for (int32_t i=firstChar ; i<fileLength ; i++) {
        fileName.appendChar (TO_UNICODE ((szFile [i] == '\\') ? '/' : szFile [i])) ;
      }
      outSourceFileArray.appendObject (fileName) ;
    }
    ::free (currentDir) ;
  }
#endif

//--------------------------------------------------------------------------------------------------
//
//     F_Analyze_CLI_Options
//
//--------------------------------------------------------------------------------------------------

void F_Analyze_CLI_Options (const int argv,
                            const char * * argc,
                            TC_UniqueArray <String> & outSourceFileArray,
                            const char* * inExtensionArray,
                            const char* * inHelpMessageArray,
                            void print_tool_help_message (void)) {
//--- Analyze command
  bool errorFound = false ;
  for (int i = 1 ; i < argv ; i++) {
    bool ok = true ;
    analyze_one_option (String (argc [i]), outSourceFileArray, ok) ;
    if (! ok) {
      errorFound = true ;
    }
  }
  if (errorFound) {
    print_option_list () ;
  }
//--- No colored output ?
  #if COMPILE_FOR_WINDOWS == 0
    if (gOption_generic_5F_cli_5F_options_no_5F_color.mValue) {
      C_ColoredConsole::setUseTextAttributes (false) ;
    }
  #endif
//--- Print version ?
  if (gOption_generic_5F_cli_5F_options_display_5F_version.mValue) {
    gCout.appendCString (argc [0]) ;
    gCout.appendCString (" : ") ;
    gCout.appendCString (projectVersionString ()) ;
    #ifndef DO_NOT_GENERATE_CHECKINGS
      gCout.appendCString (" [DEBUG]") ;
    #endif
    gCout.appendCString (", build with GALGAS ") ;
    gCout.appendCString (galgasVersionString ()) ;
    gCout.appendNewLine () ;
  }
//--- Print Help ?
  if (gOption_generic_5F_cli_5F_options_display_5F_help.mValue) {
    print_help (argv, argc, inExtensionArray, inHelpMessageArray, print_tool_help_message) ;
  }
//--- WIN32 : if got no file, display file open dialog
  #if COMPILE_FOR_WINDOWS == 1
    if ((outSourceFileArray.count () == 0) && !gOption_generic_5F_cli_5F_options_nodialog.mValue) {
      getSourceFileFromWin32OpenDialog (outSourceFileArray, inExtensionArray) ;
    }
  #endif
}

//--------------------------------------------------------------------------------------------------
