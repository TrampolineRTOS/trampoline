//---------------------------------------------------------------------------*
//                                                                           *
//  Routine 'F_Analyze_CLI_Options' : a way for automatic command            *
//  line options analysis for MacOS, Win32 and Unix.                         *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2001, ..., 2010 Pierre Molinaro.                           *
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

#include "command_line_interface/F_Analyze_CLI_Options.h"
#include "command_line_interface/C_BoolCommandLineOption.h"
#include "command_line_interface/C_UIntCommandLineOption.h"
#include "command_line_interface/C_StringCommandLineOption.h"
#include "command_line_interface/C_builtin_CLI_Options.h"
#include "streams/C_ConsoleOut.h"
#include "command_line_interface/mainForLIBPM.h"

//---------------------------------------------------------------------------*

#include <stdio.h>
#include <string.h>
#include <ctype.h>

//---------------------------------------------------------------------------*

#ifdef TARGET_API_MAC_CARBON
  #include <SIOUX.h>
#endif

//---------------------------------------------------------------------------*

#ifdef COMPILE_FOR_WIN32
  #include <windows.h>
  #include <direct.h>
#endif

//---------------------------------------------------------------------------*

#ifndef MACHINE_IS_DEFINED
  #error "Undefined machine"
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//                        C O C O A   O U T P U T                            *
//                                                                           *
//---------------------------------------------------------------------------*

static bool gCocoaOutput = false ;

//---------------------------------------------------------------------------*

bool cocoaOutput (void) {
  return gCocoaOutput ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                       V E R S I O N    S T R I N G                        *
//                                                                           *
//---------------------------------------------------------------------------*

static const char * gCompilerVersionString ;

//---------------------------------------------------------------------------*

const char * compilerVersionString (void) {
  return gCompilerVersionString ;
}

//---------------------------------------------------------------------------*

static const PMUInt32 kDisplayLength = 20 ;

//---------------------------------------------------------------------------*
//                                                                           *
//     print_usage                                                           *
//                                                                           *
//---------------------------------------------------------------------------*

static void print_usage (int argv,
                         const char * argc []) {
  co.setForeColor (kMagentaForeColor) ;
  co.setTextAttribute (kBoldTextAttribute) ;
  co << "Usage:\n" ;
  co.setTextAttribute (kAllAttributesOff) ;
  if (argv > 0) {
    co << argc [0] ;
  }
  C_BoolCommandLineOption::printUsageOfBoolOptions () ;
  C_UIntCommandLineOption::printUsageOfUIntOptions () ;
  C_StringCommandLineOption::printUsageOfStringOptions () ;
  co << " file...\n" ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//     print_options                                                         *
//                                                                           *
//---------------------------------------------------------------------------*

static void print_option_list (void) {
  printf ("*** Available command line options:\n") ;
  C_BoolCommandLineOption::printBoolOptions (kDisplayLength) ;
  C_UIntCommandLineOption::printUIntOptions (kDisplayLength) ;
  C_StringCommandLineOption::printStringOptions (kDisplayLength) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//     print_help                                                            *
//                                                                           *
//---------------------------------------------------------------------------*

static void print_help (int argv,
                        const char * argc [],
                        const char * inExtensions [],
                        const char * inHelpMessages []) {
  #ifdef __LP64__
    co << "Compiled in 64 bits mode" ;
  #else
    co << "Compiled in 32 bits mode" ;
  #endif
  #ifndef DO_NOT_GENERATE_CHECKINGS
    co << " (with debug code)" ;
  #endif
  co << ".\n" ;
  print_tool_help_message () ;
/*  #ifndef DO_NOT_GENERATE_CHECKINGS
    co << "sizeof (short)=" << ((PMUInt32) sizeof (short))
       << ", sizeof (int)=" << ((PMUInt32) sizeof (int))
       << ", sizeof (long)=" << ((PMUInt32) sizeof (long))
       << ", sizeof (long long)=" << ((PMUInt32) sizeof (long long))
       << ", sizeof (wchar_t)=" << ((PMUInt32) sizeof (wchar_t))
       << "\n" ;
  #endif */
  print_usage (argv, argc) ;
  co.setForeColor (kMagentaForeColor) ;
  co.setTextAttribute (kBoldTextAttribute) ;
  co << "Options:\n" ;
  co.setTextAttribute (kAllAttributesOff) ;
  co << "You can place options anywhere in the command line: they will be executed before the files are processed.\n" ;
  C_BoolCommandLineOption::printBoolOptions (kDisplayLength) ;
  C_UIntCommandLineOption::printUIntOptions (kDisplayLength) ;
  C_StringCommandLineOption::printStringOptions (kDisplayLength) ;

  PMSInt32 extensionIndex = 0 ;
  while (inExtensions [extensionIndex] != NULL) {
    extensionIndex ++ ;
  }
  co.setForeColor (kMagentaForeColor) ;
  co.setTextAttribute (kBoldTextAttribute) ;
  co << "Handled extension" << ((extensionIndex > 1) ? "s" : "") << ":\n" ;
  co.setTextAttribute (kAllAttributesOff) ;
  extensionIndex = 0 ;
  while (inExtensions [extensionIndex] != NULL) {
    co.setForeColor (kBlueForeColor) ;
    co.setTextAttribute (kBoldTextAttribute) ;
    co << "." << inExtensions [extensionIndex] ;
    co.setTextAttribute (kAllAttributesOff) ;
    const PMUInt32 extensionLength = (PMUInt32) (strlen (inExtensions [extensionIndex]) & PMUINT32_MAX) ;
    if (extensionLength < kDisplayLength) {
      for (PMUInt32 i=extensionLength ; i<kDisplayLength ; i++) {
        co << " " ;
      }
    }else{
      co << "\n" ;
      co.appendSpaces (kDisplayLength+2) ;
    }
    co << inHelpMessages [extensionIndex] << "\n" ;
    extensionIndex ++ ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//     Command line option beginning with a single '-'                       *
//                                                                           *
//---------------------------------------------------------------------------*

static void option_beginning_with_single_minus_sign (const char * inCommand,
                                                     bool & outOk) {
  outOk = false ;
  const PMUInt32 optionLength = (PMUInt32) (strlen (inCommand) & PMUINT32_MAX) ;
//--- Search for boolean option (minus following by a character)
  if (optionLength == 2) {
    C_BoolCommandLineOption::setBoolOptionForCommandChar (inCommand [1], outOk) ;
    if (! outOk) {
      co << "Error : unknown '" << inCommand << "' command line option.\n" ;
    }
  }else if (optionLength > 2) {
  //--- Search for an UInt option
    bool correctFormat = false ;
    C_UIntCommandLineOption::setUIntOptionForCommandChar (& inCommand [1], outOk, correctFormat) ;
  //--- Not found : search for a string option
    if (! outOk) {
      C_StringCommandLineOption::setStringOptionForCommandChar (& inCommand [1], outOk, correctFormat) ;
    }
    if (! outOk) {
      co << "Error : unknown '" << inCommand << "' command line option.\n" ;
    }else if (! correctFormat) {
      outOk = false ;
      co << "Error : incorrect format for '"
         << inCommand
         << "' command line option (correct format is : '-"
         << inCommand
         << "=value').\n" ;
    }  
  }else{
    co << "Error : unknown '" << inCommand << "' command line option.\n" ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//     Command line option beginning with '--'                               *
//                                                                           *
//---------------------------------------------------------------------------*

static void option_beginning_with_double_minus_sign (const char * inCommand,
                                                     bool & outFound) {
  outFound = false ;
  bool correctFormat = true ;
//--- Look for a boolean argument
  C_BoolCommandLineOption::setBoolOptionForCommandString (& inCommand [2], outFound, gCocoaOutput) ;
//--- If not found, look for a Uint option
  if (! outFound) {
    C_UIntCommandLineOption::setUIntOptionForCommandString (& inCommand [2], outFound, correctFormat) ;
  }
//--- If not found, look for a String option
  if (! outFound) {
    C_StringCommandLineOption::setStringOptionForCommandString (& inCommand [2], outFound, correctFormat) ;
  }
  if (! outFound) {
    co << "Error : unknown '" << inCommand << "' command line option.\n" ;
  }else if (! correctFormat) {
    outFound = false ;
    co << "Error : incorrect format for '" << inCommand << "' command line option.\n" ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//     analyze_one_option                                                    *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef TARGET_API_MAC_CARBON
  static void
  analyze_one_option (const char * inCommand,
                      TC_UniqueArray <C_String> & outSourceFileArray,
                      bool & outOk) {
    const PMSInt32 optionLength = (PMSInt32) (strlen (inCommand) & PMUINT32_MAX) ;
    bool found = false ;
  //--- Begin by a '-' character ?
    if ((optionLength > 1) && (inCommand [0] == '-')) {
    //--- Second character is also a '-' ?
      if ((optionLength > 2) && (inCommand [1] == '-')) {
      //--- two minus signs '--' at beginning
        option_beginning_with_double_minus_sign (inCommand, found) ;
      }else{
      //--- Single '-' at beginning
        option_beginning_with_single_minus_sign (inCommand, found) ;
      }  
    }
  //--- Look for a file
    if (! found) {
      if (inCommand [0] != '-') {
        C_String fileName ;
        #ifdef COMPILE_FOR_WIN32
          const PMSInt32 fileLength = (PMSInt32) strlen (inCommand) ;
          PMSInt32 firstChar = 0 ;
          if ((fileLength > 3)
           && isalpha (inCommand [0])
           && (inCommand [1] == ':')
           && (inCommand [2] == '\\')) {
            fileName << "/" ;
            fileName.appendUnicodeCharacter (TO_UNICODE (inCommand [0]) COMMA_HERE) ;
            fileName << "/" ;
            firstChar = 3 ;
          }
          for (PMSInt32 i=firstChar ; i<fileLength ; i++) {
            fileName.appendUnicodeCharacter (TO_UNICODE (((inCommand [i] == '\\') ? '/' : inCommand [i])) COMMA_HERE) ;
          }
        #else
          fileName = inCommand ;
        #endif
        outSourceFileArray.addObject (fileName.absolutePathFromPath ("")) ;
        found = true ;
      }
    }
  //--- Error ?
    if (! found) {
      outOk = false ;
    }
  }
#endif

//---------------------------------------------------------------------------*

#ifdef COMPILE_FOR_WIN32
  static void
  getSourceFileFromWin32OpenDialog (TC_UniqueArray <C_String> & outSourceFileArray,
                                    const char * inExtensions []) {
    char szFile[260] ;       // buffer for file name
    OPENFILENAME ofn ;
  //--- Initialize OPENFILENAME
    ZeroMemory (& ofn, sizeof(ofn)) ;
    ofn.lStructSize = sizeof (ofn) ;
    ofn.hwndOwner = NULL ;
    ofn.lpstrFile = szFile ;
  // Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
  // use the contents of szFile to initialize itself.
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof (szFile) ;
    char filterString [1000] = "";
    PMSInt32 filterIndex = 0 ;
    while (inExtensions [filterIndex] != NULL) {
      if (filterIndex != 0) {
        strcat (filterString, ";") ;
      }
      strcat (filterString, "*.") ;
      strcat (filterString, inExtensions [filterIndex]) ;
      filterIndex ++ ;
    }
    char filter [1000] ;
    const char zero = '\0' ;
    snprintf (filter, 999, "%c%s%c", zero, filterString, zero) ;
    ofn.lpstrFilter = filter ;
  //  ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0 ;
    char * currentDir = getcwd (NULL, 0) ;
    ofn.lpstrInitialDir = currentDir ;
    ofn.lpstrTitle = NULL ;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY ;
    if (GetOpenFileName (& ofn)) {
      C_String fileName ;
      const PMSInt32 fileLength = (PMSInt32) strlen (szFile) ;
      PMSInt32 firstChar = 0 ;
      if ((fileLength > 3)
       && isalpha (szFile [0])
       && (szFile [1] == ':')
       && (szFile [2] == '\\')) {
        fileName << "/" ;
        fileName.appendUnicodeCharacter (TO_UNICODE (szFile [0]) COMMA_HERE) ;
        fileName << "/" ;
        firstChar = 3 ;
      }
      for (PMSInt32 i=firstChar ; i<fileLength ; i++) {
        fileName.appendUnicodeCharacter (TO_UNICODE ((szFile [i] == '\\') ? '/' : szFile [i]) COMMA_HERE) ;
      }
      outSourceFileArray.addObject (fileName) ;
    }
    ::free (currentDir) ;
  }
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//     F_Analyze_CLI_Options                                                 *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef TARGET_API_MAC_CARBON
  void
  F_Analyze_CLI_Options (const int argv,
                         const char * argc [],
                         const char * inVersionString,
                         TC_UniqueArray <C_String> & outSourceFileArray,
                         const char * inExtensions [],
                         const char * inHelpMessages []) {
    gCompilerVersionString = inVersionString ;
  //--- Analyze command
    bool errorFound = false ;
    for (PMSInt32 i=1 ; i<argv ; i++) {
      bool ok = true ;
      analyze_one_option (argc [i],
                          outSourceFileArray,
                          ok) ;
      if (! ok) {
        errorFound = true ;
      }
    }
    if (errorFound) {
      print_option_list () ;
    }
  //--- No colored output ?
    #ifndef COMPILE_FOR_WIN32
      if (gOption_generic_5F_cli_5F_options_no_5F_color.mValue) {
        C_ColoredConsole::setUseTextAttributes (false) ;
      }
    #endif
  //--- Print version ?
    if (gOption_generic_5F_cli_5F_options_display_5F_version.mValue) {
      co << argc [0] << " : " << inVersionString << "\n" ;
    }
  //--- Print Help ?
    if (gOption_generic_5F_cli_5F_options_display_5F_help.mValue) {
      print_help (argv, argc, inExtensions, inHelpMessages) ;
    }
  //--- WIN32 : if got no file, display file open dialog
    #ifdef COMPILE_FOR_WIN32
      if ((outSourceFileArray.count () == 0)
        && ! gOption_generic_5F_cli_5F_options_nodialog.mValue) {
        getSourceFileFromWin32OpenDialog (outSourceFileArray, inExtensions) ;
      }
    #endif
  }
#endif

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark ========= For Mac OS CARBON
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//     Get source files for Mac OS Carbon                                    *
//                                                                           *
//---------------------------------------------------------------------------*

#ifdef TARGET_API_MAC_CARBON
  static C_String fss2path (const FSSpec & in_fss) {
    FSSpec fss = in_fss ;
    C_String fileName ;
    fileName << "/" ;
    for (int i = 1 ; i <= fss.name [0] ; i++) {
      fileName.appendUnicodeCharacter (TO_UNICODE (fss.name [i]) COMMA_HERE) ; 
    }
    if (fss.parID != fsRtParID) { //path is more than just a volume name
      CInfoPBRec pb ;
      pb.dirInfo.ioNamePtr = & fss.name [0] ;
      pb.dirInfo.ioVRefNum = fss.vRefNum ;
      pb.dirInfo.ioDrParID = fss.parID ;
      bool loop = true ;
      do{
        pb.dirInfo.ioFDirIndex = -1 ;  //get parent directory name
        pb.dirInfo.ioDrDirID = pb.dirInfo.ioDrParID ;   
        loop = PBGetCatInfoSync (&pb) == noErr ;
        if (loop) {
          C_String prefix ;
          prefix << "/" ;
          const PMUInt32 length = fss.name [0] ;
          for(PMUInt32 i=1 ; i<=length ; i++) {
            prefix.appendUnicodeCharacter (TO_UNICODE (fss.name [i]) COMMA_HERE) ; //add to start of path
          }
          fileName = prefix + fileName ;
        }
      }while (loop && (pb.dirInfo.ioDrDirID != fsRtDirID)) ; //while more directory levels
    }
    fileName = C_String ("/Volumes") + fileName ;
    return fileName ;
  }
#endif

//---------------------------------------------------------------------------*

#ifdef TARGET_API_MAC_CARBON
  static pascal void myEventProc (NavEventCallbackMessage callBackSelector,
                                  NavCBRecPtr callBackParms,
                                  void * /* callBackUD */) {
  //--- From Inside Macintosh, Programming With Navigation Services, For Navigation
  //    Services 2.0, pages 51-52
  //    This function is called by "getSourceFileWithNavigationServices"
    switch (callBackSelector) {
    case kNavCBEvent :
      switch (((callBackParms->eventData).eventDataParms).event->what) {
      case updateEvt :
          ::SIOUXHandleOneEvent (((callBackParms->eventData).eventDataParms).event) ;
        break ;
      }
      break ;
    }
  }
#endif

//---------------------------------------------------------------------------*

#ifdef TARGET_API_MAC_CARBON
  static void getSourceFileWithNavigationServices (TC_UniqueArray <C_String> & outSourceFileArray) {
  //--- Get default dialog option
    NavDialogOptions dialogOptions ;
    OSErr error = ::NavGetDefaultDialogOptions (& dialogOptions) ;
  //--- Adjust dialog options
    if (error == noErr) {
    //--- Clear preview flag
      dialogOptions.dialogOptionFlags ^= kNavAllowPreviews ;
    }
  //--- Create a new event function
    NavEventUPP eventProc = NewNavEventUPP (myEventProc) ;
  //--- Dialog
    if (error == noErr) {
      NavReplyRecord reply ; // In <Navigation.h>
      NavTypeListHandle typeList = (NavTypeListHandle) ::NewHandle (sizeof (NavTypeList)) ;
      HLock ((Handle) typeList) ;
      (* typeList)->osTypeCount = 1 ;
      (* typeList)->osType [0] = 'TEXT' ;
      HUnlock ((Handle) typeList) ;
      error = ::NavChooseFile (NULL, // No default location
                               & reply, // Reply record
                               & dialogOptions,
                               eventProc, // The event proc
                               NULL, // No preview proc
                               NULL, // No filter proc
                               typeList, // List of file fypes
                               NULL) ; //
     if (error == -128) { // Dialog canceled
       error = noErr ;
     }else if ((error == noErr) && reply.validRecord) {
       AEKeyword theKeyword ;
       DescType actualType ;
       Size actualSize ;
       FSSpec sourceFile ;
     //--- Get descriptor count
       long count ;
       ::AECountItems (& reply.selection, & count) ;
     //--- Get file descriptors
       for (long i=1 ; i<=count; i++) {
         error = ::AEGetNthPtr (& reply.selection,
                                i,
                                typeFSS,
                                & theKeyword,
                                & actualType,
                                & sourceFile,
                                sizeof (FSSpec),
                                & actualSize) ;
         if (error == noErr) {
           outSourceFileArray.addObject (fss2path (sourceFile)) ;
         }
       }
     }
   //--- Dispose reply record
     ::NavDisposeReply (& reply) ;
   //--- Dispose type list handle
     if (typeList != NULL) {
       ::DisposeHandle ((Handle) typeList) ;
     }
   }
  //--- Delete the event function
    DisposeNavEventUPP (eventProc) ;
  }
#endif

//---------------------------------------------------------------------------*

#ifdef TARGET_API_MAC_CARBON
  #if TARGET_API_MAC_CARBON == 0
    static void getSourceFileWithClassicDialog (TC_UniqueArray <C_String> & outSourceFileArray) {
      SFTypeList typeList ; typeList [0] = 'TEXT' ;
      StandardFileReply reply ;
      ::StandardGetFile (NULL, 1, typeList, &reply) ;
      if (reply.sfGood) {
        C_String sourceFilePath ;
        sourceFilePath << reply.sfFile.name ;
        C_String f (C_directory (reply.sfFile.vRefNum,
                                           reply.sfFile.parID),
                             sourceFilePath) ;
         outSourceFileArray.addObject (f) ;
      }
    }
  #endif
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//   For Mac OS : Get source files from Apple Events                         *
//                                                                           *
//---------------------------------------------------------------------------*

#ifdef TARGET_API_MAC_CARBON
  static bool areAppleEventsImplemented (void) {
    bool appleEventsAreImplemented = false ;
    #ifdef GENERATINGPOWERPC
      #ifdef DebugAppleEvents
        co << "Power PC : apple events always implemented\n" ;
      #endif
      appleEventsAreImplemented = true ; // Allways implemented for power PC
    #else
      #ifdef DebugAppleEvents
        co << "68k : system test..." ;
      #endif
      SysEnvRec leSysteme ;
      OSErr discardError = ::SysEnvirons (1, &leSysteme) ;
      if (theWorld.machineType < 0) { // Very old system : not implemented
        #ifdef DebugAppleEvents
          co << " very old system : no gestalt, no apple events.\n" ;
        #endif
      }else{
        #ifdef DebugAppleEvents
          co << " testing gestalt..." ;
        #endif
        // GestAlt est-il implemente ?
        const bool gestAltImplemente = ::checkTrapAvailable (kGestaltTrapID, ToolTrap) ;
        if (gestAltImplemente) { // Oui, tester alors si les apple events le sont
          #ifdef DebugAppleEvents
            co << " ok, testing apple events implementation..." ;
          #endif
          discardError = Gestalt(gestaltAppleEventsAttr,&result);
          if ((discardError == 0) && ((result & (0x00000001 << gestaltAppleEventsPresent)) != 0))
            appleEventsAreImplemented = true ;
            #ifdef DebugAppleEvents
             co << " ok\n" ;
            #endif
          }else{
            #ifdef DebugAppleEvents
              co << " no!\n" ;
            #endif
          }
        }else{
         #ifdef DebugAppleEvents
           co << " not implemented, so no apple events\n" ;
         #endif
        }
      }
    #endif
    return appleEventsAreImplemented ;
  }
#endif

//---------------------------------------------------------------------------*

// Interapplication Communication, p. 4-35
#ifdef TARGET_API_MAC_CARBON
  static OSErr myGotRequiredParams (const AppleEvent * theAppleEvent) {
    Size actualSize ;
    DescType returnedType ;
    OSErr myErr = AEGetAttributePtr (theAppleEvent, keyMissedKeywordAttr, typeWildCard,
                                     & returnedType, NULL, 0, & actualSize) ;
    if (myErr == errAEDescNotFound) {
      myErr = noErr ;
    }else if (myErr == noErr) {
      myErr = errAEParamMissed ;
    }
    return myErr ;
  }
#endif

//---------------------------------------------------------------------------*

#ifdef TARGET_API_MAC_CARBON
  static TC_UniqueArray <C_String> gTemporarySourceFileArray ;
  static pascal OSErr handleOpenDoc (const AppleEvent * theAppleEvent,
                                     AppleEvent *, // reply
                                     long /*handleRefCon */) {
    #ifdef DebugAppleEvents
      co << "Reception de l'evenement 'Open Document'\n" ;
    #endif
    AEDescList docList ;
    OSErr myErr = ::AEGetParamDesc (theAppleEvent, keyDirectObject, typeAEList, &docList) ;
    if (myErr == noErr) {
      myErr = myGotRequiredParams (theAppleEvent) ;
    }else{
      AEDisposeDesc (&docList) ;
    }
    long itemsInList ;
    if (myErr == noErr) {
      myErr = ::AECountItems (&docList, &itemsInList) ;
    }
    for (PMSInt32 i=1 ; (i<=itemsInList) && (myErr == noErr) ; i++) {
      Size actualSize ;
      DescType returnedType ;
      FSSpec myFSS ;
      AEKeyword keywd ;
      myErr = ::AEGetNthPtr (&docList, i, typeFSS, &keywd, &returnedType,
                             (Ptr) &myFSS, sizeof (myFSS), &actualSize) ;
      if (myErr == noErr) {
        gTemporarySourceFileArray.addObject (fss2path (myFSS)) ;
      }
    }
    return myErr ;
  }
#endif

//---------------------------------------------------------------------------*

#ifdef TARGET_API_MAC_CARBON
  static void 
  getAppleEvents (TC_UniqueArray <C_String> & outSourceFileArray) {
    if (areAppleEventsImplemented ()) {
      swap (gTemporarySourceFileArray, outSourceFileArray) ;
    //--- Installing Apple events handlers (interapplication communication, p. 4-8)
      #ifdef DebugAppleEvents
        co << "Installing Open Doc Event Handler\n" ;
      #endif
      AEEventHandlerUPP openDoc = NewAEEventHandlerUPP (handleOpenDoc) ;
      OSErr myErr = ::AEInstallEventHandler (kCoreEventClass, kAEOpenDocuments,
                                             openDoc, 0, false) ;
      MF_Assert (myErr == noErr, "myErr (%lld) != noErr", myErr, 0) ;
      #ifdef DebugAppleEvents
        co << "Installing Open Applicaton Event Handler\n" ;
      #endif
    //--- Get events
      EventRecord evt ;
      bool existeEvt = true ;
      while (existeEvt) {
        existeEvt = ::WaitNextEvent (everyEvent, & evt, 0, NULL) ;
        if (existeEvt) {
          switch (evt.what) {
          case kHighLevelEvent:
            #ifdef DebugAppleEvents
              co << "got a 'kHighLevelEvent' event\n" ;
            #endif
            OSErr err = ::AEProcessAppleEvent (& evt) ;
            break;
          default:
            #ifdef DebugAppleEvents
              co << "got an event different of an Apple event (what = " << evt.what << ")\n" ;
            #endif
            break;
          }
        }
      }
    //--- Remove apple event handlers
      myErr = ::AERemoveEventHandler (kCoreEventClass, kAEOpenDocuments,
                                      openDoc, false) ;
      DisposeAEEventHandlerUPP (openDoc) ;
      MF_Assert (myErr == noErr, "myErr (%lld) != noErr", myErr, 0) ;
      swap (gTemporarySourceFileArray, outSourceFileArray) ;
    }else{
    //--- No Apple events
      co << "Apple events not installed... can't run !\n" ;
    }
  }
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//     F_Analyze_CLI_Options for CARBON                                      *
//                                                                           *
//---------------------------------------------------------------------------*

#ifdef TARGET_API_MAC_CARBON
  void
  F_Analyze_CLI_Options (const int /* argv */,
                         const char * /* argc */ [],
                         const char * /* inVersionString */,
                         TC_UniqueArray <C_String> & outSourceFileArray,
                         const char * /* inExtensions */ [],
                         const char * /* inHelpMessages */ []) {
    co << "\n" ; // For initializing Mac OS tool box
  //--- Get source file names from apple events
    getAppleEvents (outSourceFileArray) ;
  //--- If got no file, display file open dialog
    if (outSourceFileArray.count () == 0) {
      getSourceFileWithNavigationServices (outSourceFileArray) ;
    }
  }
#endif

//---------------------------------------------------------------------------*
