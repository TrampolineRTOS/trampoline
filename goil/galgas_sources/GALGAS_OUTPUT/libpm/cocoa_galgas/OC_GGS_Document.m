//---------------------------------------------------------------------------*
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2003, ..., 2011 Pierre Molinaro.                           *
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

#import "OC_GGS_Document.h"
#import "OC_GGS_PreferencesController.h"
#import "OC_GGS_RulerViewForTextView.h"
#import "OC_Lexique.h"
#import "F_CocoaWrapperForGalgas.h"
#import "PMCocoaCallsDebug.h"
#import "PMIssueDescriptor.h"
#import "OC_GGS_TextSyntaxColoring.h"
#import "OC_GGS_TextDisplayDescriptor.h"
#import "PMTabBarView.h"
#import "OC_GGS_BuildTask.h"

//---------------------------------------------------------------------------*

//#define DEBUG_MESSAGES

//---------------------------------------------------------------------------*

@implementation OC_GGS_Document

//---------------------------------------------------------------------------*
//                                                                           *
//       I N I T                                                             *
//                                                                           *
//---------------------------------------------------------------------------*

- (id) init {
  self = [super init] ;
  if (self) {
    #ifdef DEBUG_MESSAGES
      NSLog (@"%s", __PRETTY_FUNCTION__) ;
    #endif
    mFileEncoding = NSUTF8StringEncoding ;
    mSourceDisplayArrayController = [NSArrayController new] ;
    self.undoManager = nil ;
    mBuildTask = [OC_GGS_BuildTask new] ;
  }
  return self;
}

//---------------------------------------------------------------------------*

- (NSString *) sourceStringForGlobalSearch {
  return mSourceTextWithSyntaxColoring.sourceString ;
}

//---------------------------------------------------------------------------*

- (void) replaceSourceStringWithString: (NSString *) inString {
  [mSourceTextWithSyntaxColoring replaceSourceStringWithString:inString] ;
}

//---------------------------------------------------------------------------*

- (OC_GGS_TextSyntaxColoring *) textSyntaxColoring {
  return mSourceTextWithSyntaxColoring ;
}

//---------------------------------------------------------------------------*

#pragma mark Nib relative Actions

//---------------------------------------------------------------------------*
//                                                                           *
//       W I N D O W    N I B    N A M E                                     *
//                                                                           *
//---------------------------------------------------------------------------*

- (NSString *) windowNibName {
  return @"OC_GGS_Document" ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       W I N D O W    C O N T R O L L E R    D I D    L O A D    N I B     *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) windowControllerDidLoadNib: (NSWindowController *) inWindowController {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [super windowControllerDidLoadNib: inWindowController];

//--- Tell to window controller that closing the source text window closes the document
  [inWindowController setShouldCloseDocument: YES] ;
//--- Bindings
  [mIssueTableViewColumn
    bind:@"value"
    toObject:mBuildTask.issueArrayController
    withKeyPath:@"arrangedObjects.issueMessage"
    options:nil
  ] ;
  [mIssueTableViewColumn
    bind:@"textColor"
    toObject:mBuildTask.issueArrayController
    withKeyPath:@"arrangedObjects.issueColor"
    options:nil
  ] ;
//--- Handle clic on issue table view
  mIssueTableView.target = self ;
  mIssueTableView.action = @selector(clicOnIssueTableView:) ;
//--- Set up windows location
  NSString * key = [NSString stringWithFormat: @"frame_for_source:%@", self.lastComponentOfFileName] ;
  [self.windowForSheet setFrameAutosaveName:key] ;

//--- Add Split view binding
// Note : use [self lastComponentOfFileName] instead of [window title], because window title may not set at this point
  key = [NSString stringWithFormat:@"values.issue-split-fraction:%@", self.lastComponentOfFileName] ;
  [mIssueSplitView setAutosaveName:key] ;
//---
  [mDetailedIssueSplitView setDelegate:self] ;
//--- Source file encoding
  [mSourceEncodingTextField
    bind:@"value"
    toObject:self
    withKeyPath:@"fileEncodingString"
    options:nil    
  ] ;
//---
  [mSourceDisplayArrayController
    addObserver:self 
    forKeyPath:@"selectionIndex"
    options:0
    context:NULL
  ] ;
  [mSourceDisplayArrayController
    addObserver:mTabBarView 
    forKeyPath:@"selectionIndex"
    options:0
    context:NULL
  ] ;
//---
  [mSourceDisplayArrayController
    addObserver:self 
    forKeyPath:@"selection.textSelectionStart"
    options:0
    context:NULL
  ] ;
//---
  [mSourceDisplayArrayController
    addObserver:self 
    forKeyPath:@"selection.mTextSyntaxColoring.mTokenizer.menuForEntryPopUpButton"
    options:0
    context:NULL
  ] ;
//---
  [mSourceDisplayArrayController
    addObserver:mTabBarView 
    forKeyPath:@"selection.sourcePath"
    options:0
    context:NULL
  ] ;
//---
  [mSourceDisplayArrayController
    addObserver:mTabBarView
    forKeyPath:@"arrangedObjects"
    options:0
    context:NULL
  ] ;
//--- Display the document contents
  OC_GGS_TextDisplayDescriptor * textDisplayDescriptor = [[OC_GGS_TextDisplayDescriptor alloc]
    initWithDelegateForSyntaxColoring:mSourceTextWithSyntaxColoring
    document:self
  ] ;
  [mSourceDisplayArrayController addObject:textDisplayDescriptor] ;
  [mSourceDisplayArrayController setSelectedObjects:[NSArray arrayWithObject:textDisplayDescriptor]] ;
//---
  [mTabBarView setTarget:self] ;
  [mTabBarView setChangeSourceTabAction:@selector (changeSelectedSourceViewAction:)] ;
  [mTabBarView setRemoveSourceTabAction:@selector (removeSelectedSourceViewAction:)] ;
//---
  [self displayIssueDetailedMessage:nil] ;
//---
  [mBuildProgressIndicator startAnimation:nil] ;
  [mStartBuildButton
    bind:@"hidden"
    toObject:mBuildTask
    withKeyPath:@"buildTaskIsRunning"
    options:nil    
  ] ;
  [mBuildProgressIndicator
    bind:@"hidden"
    toObject:mBuildTask
    withKeyPath:@"buildTaskIsNotRunning"
    options:nil    
  ] ;
  [mStopBuildButton
    bind:@"enabled"
    toObject:mBuildTask
    withKeyPath:@"buildTaskIsRunning"
    options:nil    
  ] ;
  [mStopBuildButton
    bind:@"hidden"
    toObject:mBuildTask
    withKeyPath:@"buildTaskIsNotRunning"
    options:nil    
  ] ;
  [mErrorCountTextField
    bind:@"hidden"
    toObject:mBuildTask
    withKeyPath:@"buildTaskIsRunning"
    options:nil    
  ] ;
  [mErrorCountTextField
    bind:@"value"
    toObject:mBuildTask
    withKeyPath:@"errorCountString"
    options:nil    
  ] ;
  [mWarningCountTextField
    bind:@"hidden"
    toObject:mBuildTask
    withKeyPath:@"buildTaskIsRunning"
    options:nil    
  ] ;
  [mWarningCountTextField
    bind:@"value"
    toObject:mBuildTask
    withKeyPath:@"warningCountString"
    options:nil    
  ] ;
}

//---------------------------------------------------------------------------*

- (void) willCloseDocument: (OC_GGS_Document *) inDocument {
  NSArray * sourceDisplayArray = mSourceDisplayArrayController.arrangedObjects ;
  for (OC_GGS_TextDisplayDescriptor * tdd in sourceDisplayArray.copy) {
    if (tdd.textSyntaxColoring == inDocument.textSyntaxColoring) {
      tdd.syntaxColoringDelegate = nil ;
      [mSourceDisplayArrayController removeObject:tdd] ;
    }
  }
}

//---------------------------------------------------------------------------*

- (void) removeWindowController:(NSWindowController *) inWindowController {
  [super removeWindowController:inWindowController] ;
//---
  for (OC_GGS_Document * doc in [[NSDocumentController sharedDocumentController] documents]) {
    [doc willCloseDocument:self] ;
  }
}

//---------------------------------------------------------------------------*

#pragma mark Actions

//---------------------------------------------------------------------------*

- (IBAction) duplicateSelectedSourceViewAction: (id) inSender {
  OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayController.selectedObjects objectAtIndex:0 HERE] ;
  OC_GGS_TextDisplayDescriptor * textDisplayDescriptor = [[OC_GGS_TextDisplayDescriptor alloc]
    initWithDelegateForSyntaxColoring:selectedObject.textSyntaxColoring
    document:self
  ] ;
  [mSourceDisplayArrayController addObject:textDisplayDescriptor] ;
  [mSourceDisplayArrayController setSelectedObjects:[NSArray arrayWithObject:textDisplayDescriptor]] ;
}

//---------------------------------------------------------------------------*

- (IBAction) removeSelectedSourceViewAction: (id) inSender {
  [mSourceDisplayArrayController remove:inSender] ;
}

//---------------------------------------------------------------------------*

- (IBAction) changeSelectedSourceViewAction: (NSButton *) inSender {
  [mSourceDisplayArrayController setSelectionIndex:inSender.tag] ;
}

//---------------------------------------------------------------------------*

- (IBAction) actionGotoLine: (id) inSender {
  [NSApp
    beginSheet:mGotoWindow
    modalForWindow:self.windowForSheet
    modalDelegate: self
    didEndSelector: @selector (sheetDidEnd:returnCode:contextInfo:)
    contextInfo: nil
  ] ;
}

//---------------------------------------------------------------------------*

- (void) collapseDetailledMessageAction: (id) inSender {
  [mDetailedIssueSplitView setPosition:mDetailedIssueSplitView.bounds.size.height ofDividerAtIndex:0] ;
}

//---------------------------------------------------------------------------*

- (void) collapseIssuesAction: (id) inSender {
  [mIssueSplitView setPosition:0.0 ofDividerAtIndex:0] ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//        S H E E T    D I D    E N D    ( G O T O    L I N E )              *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) sheetDidEnd: (NSWindow *) inSheet
         returnCode: (int) inReturnCode
         contextInfo: (void *) inContextInfo {
  if (inReturnCode == 1) {
  //--- Get selected line
    const NSUInteger selectedLine = [mGotoLineTextField integerValue] ;
  //--- Goto selected line
    OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayController.selectedObjects objectAtIndex:0 HERE] ;
    [selectedObject gotoLine:selectedLine] ;
  }
}

//---------------------------------------------------------------------------*

- (IBAction) actionComment: (id) sender {
  OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayController.selectedObjects objectAtIndex:0 HERE] ;
  [selectedObject commentSelection] ;
}

//---------------------------------------------------------------------------*

- (IBAction) actionUncomment: (id) sender {
  OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayController.selectedObjects objectAtIndex:0 HERE] ;
  [selectedObject uncommentSelection] ;
}

//---------------------------------------------------------------------------*

- (IBAction) actionShiftLeft: (id) sender {
  OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayController.selectedObjects objectAtIndex:0 HERE] ;
  [selectedObject shiftLeftAction] ;
}

//---------------------------------------------------------------------------*

- (IBAction) actionShiftRight: (id) sender {
  OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayController.selectedObjects objectAtIndex:0 HERE] ;
  [selectedObject shiftRightAction] ;
}

//---------------------------------------------------------------------------*

#pragma mark Document Actions

//---------------------------------------------------------------------------*
//                                                                           *
//    P R I N T                                                              *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) printDocument: (id) sender {
  OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayController.selectedObjects objectAtIndex:0 HERE] ;
  [selectedObject.textView print:sender] ;
}

//---------------------------------------------------------------------------*

#pragma mark Tracking File Document changes

//---------------------------------------------------------------------------*

- (NSDate *) sourceFileModificationDateInFileSystem {
  NSURL * fileURL = [self fileURL] ;
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSDate * date = [NSDate date] ;
  if ([fileURL isFileURL]) {
    NSDictionary * fileAttributes = [[[NSFileManager alloc] init] attributesOfItemAtPath:[fileURL path] error:NULL] ;
    date = [fileAttributes objectForKey:NSFileModificationDate] ;
  }
  return date ;
}

//---------------------------------------------------------------------------*

- (void) updateFromFileSystem: (id) inUnusedArgument {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [NSApp
    beginSheet:mUpdateFromFileSystemPanel
    modalForWindow:[self windowForSheet]
    modalDelegate:nil
    didEndSelector:NULL
    contextInfo:NULL
  ] ;
//--- Read new content
  NSString * source = [[NSString alloc]
    initWithContentsOfURL:[self fileURL]
    encoding:NSUTF8StringEncoding
    error:nil
  ] ;
  if (source != nil) {
//    [mDelegateForSyntaxColoring setSourceString:source] ;
  }
//---
  [mUpdateFromFileSystemPanel orderOut:self] ;
  [NSApp endSheet:mUpdateFromFileSystemPanel] ;   
}

//---------------------------------------------------------------------------*

- (void) askForUpdatingFromFileSystem {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
//--- Get application name
  NSDictionary * bundleDictionary = [[NSBundle mainBundle] localizedInfoDictionary] ;
  NSString * applicationName = [bundleDictionary objectForKey: @"CFBundleName"] ;
//--- Build Alert
  NSString * message = [NSString stringWithFormat:
     @"This file for document at %@ has been modified by an other application."
     " Do you want to keep the %@ version or update from file contents ?",
     self.fileURL.path,
     applicationName
  ] ;
  NSAlert *alert = [NSAlert
    alertWithMessageText:@"Warning"
    defaultButton:[NSString stringWithFormat:@"Keep %@ Version", applicationName]
    alternateButton:@"Update From File Contents"
    otherButton:nil
    informativeTextWithFormat:message
  ] ;
//--- Display alert as window sheet
  [alert
    beginSheetModalForWindow:[self windowForSheet]
    modalDelegate:self
    didEndSelector:@selector (askForUpdatingFromFileSystemAlertEnding:returnCode:contextInfo:)
    contextInfo:NULL
  ] ;
}

//---------------------------------------------------------------------------*

- (void) askForUpdatingFromFileSystemAlertEnding:(NSAlert *) inAlert
         returnCode:(int) returnCode
         contextInfo:(void *) contextInfo {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
//  NSLog (@"returnCode %d", returnCode) ;
  if (returnCode == NSAlertAlternateReturn) { // Revert button
    [[NSRunLoop currentRunLoop]
      performSelector: @selector (updateFromFileSystem:)
      target:self
      argument:nil
      order:0
      modes:[NSArray arrayWithObject:NSDefaultRunLoopMode]
    ] ;
  }
//--- Set new file modification date
  [self setFileModificationDate:[self sourceFileModificationDateInFileSystem]] ;
}

//---------------------------------------------------------------------------*

- (void) windowDidBecomeKey: (NSNotification *) inNotification {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  if (self.fileURL.path.length > 0) {
    NSDate * modificationDateOnFileSystem = [self sourceFileModificationDateInFileSystem] ;
    if ([modificationDateOnFileSystem compare:[self fileModificationDate]] != NSOrderedSame) {
      [self askForUpdatingFromFileSystem] ;
    }
  }
}


//---------------------------------------------------------------------------*

#pragma mark Document Save

//---------------------------------------------------------------------------*
//                                                                           *
//    W R I T E    T O    F I L E                                            *
//                                                                           *
//---------------------------------------------------------------------------*

- (BOOL) writeToURL: (NSURL *) inAbsoluteURL
         ofType: (NSString *) inTypeName
         error: (NSError **) outError {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s, URL %@", __PRETTY_FUNCTION__, inAbsoluteURL) ;
  #endif
  [mSourceTextWithSyntaxColoring breakUndoCoalescing] ;
  NSString * string = [mSourceTextWithSyntaxColoring sourceString] ;
  const BOOL ok = [string
    writeToURL:inAbsoluteURL
    atomically:YES
    encoding:NSUTF8StringEncoding
    error:outError
  ] ;
//---
  if (ok) {
    [mSourceTextWithSyntaxColoring documentHasBeenSaved] ;
  }
//---
  return ok ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//  S A V I N G    H F S    T Y P E    A N D    C R E A T O R    C O D E S   *
//                                                                           *
//---------------------------------------------------------------------------*

- (NSDictionary *) fileAttributesToWriteToURL:(NSURL *) inDocumentURL
    ofType:(NSString *)documentTypeName
    forSaveOperation:(NSSaveOperationType)saveOperationType
    originalContentsURL: (NSURL *) inOriginalURL
    error: (NSError **) outError {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
    
  NSDictionary *infoPlist = [[NSBundle mainBundle] infoDictionary];
  NSString *creatorCodeString;
  NSArray *documentTypes;
  NSNumber *typeCode, *creatorCode;
  NSMutableDictionary *newAttributes;
  
  typeCode = creatorCode = nil;
  
  // First, set creatorCode to the HFS creator code for the application,
  // if it exists.
   creatorCodeString = [infoPlist objectForKey:@"CFBundleSignature"];
  if(creatorCodeString)
  {
      creatorCode = [NSNumber
          numberWithUnsignedLong:NSHFSTypeCodeFromFileType([NSString
          stringWithFormat:@"'%@'",creatorCodeString])];
  }
  
  // Then, find the matching Info.plist dictionary entry for this type.
  // Use the first associated HFS type code, if any exist.
  documentTypes = [infoPlist objectForKey:@"CFBundleDocumentTypes"];
  if(documentTypes)
  {
      NSInteger i, count = [documentTypes count];
      
      for(i = 0; i < count; i++)
      {
          NSString *type = [[documentTypes objectAtIndex:i HERE]
              objectForKey:@"CFBundleTypeName"];
          if(type && [type isEqualToString:documentTypeName])
          {
              NSArray *typeCodeStrings = [[documentTypes objectAtIndex:i HERE]
                  objectForKey:@"CFBundleTypeOSTypes"];
              if(typeCodeStrings)
              {
                 NSString *firstTypeCodeString = [typeCodeStrings
                      objectAtIndex:0 HERE];
                  if (firstTypeCodeString)
                  {
                      typeCode = [NSNumber                            numberWithUnsignedLong:
                         NSHFSTypeCodeFromFileType([NSString
                         stringWithFormat:@"'%@'",firstTypeCodeString])];
                  }
              }
              break;
          }
      }
  }
   // If neither type nor creator code exist, use the default implementation.
  if(!(typeCode || creatorCode))
  {
      return [super
        fileAttributesToWriteToURL:inDocumentURL
        ofType:documentTypeName
        forSaveOperation:saveOperationType
        originalContentsURL:inOriginalURL
        error:outError
      ];
  }
  
  // Otherwise, add the type and/or creator to the dictionary.
  newAttributes = [NSMutableDictionary
    dictionaryWithDictionary:[super
      fileAttributesToWriteToURL:inDocumentURL
      ofType:documentTypeName
      forSaveOperation:saveOperationType
      originalContentsURL:inOriginalURL
      error:outError
    ]
  ];
  if(typeCode)
      [newAttributes setObject:typeCode forKey:NSFileHFSTypeCode];
  if(creatorCode)
      [newAttributes setObject:creatorCode forKey:NSFileHFSCreatorCode];
  return newAttributes;
}

//---------------------------------------------------------------------------*

#pragma mark Document Close

//---------------------------------------------------------------------------*
//                                                                           *
//       D I S P L A Y    A     S H E E T    B E F O R E    C L O S I N G    *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) displaySheetBeforeClosing: (NSAlert *) inAlert {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [inAlert
    beginSheetModalForWindow:[self windowForSheet]
    modalDelegate:self
    didEndSelector:@selector (closeDocumentOnAlertEnding:returnCode:contextInfo:)
    contextInfo:NULL
  ] ;
}

//---------------------------------------------------------------------------*

- (void) closeDocumentOnAlertEnding:(NSAlert *) inAlert
         returnCode:(int)returnCode
         contextInfo:(void *)contextInfo{
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSDocumentController * dc = [NSDocumentController sharedDocumentController] ;
  [dc removeDocument:self] ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       D O C U M E N T    W I N D O W    D I D    R E S I Z E              *
//                     N O T I F I C A T I O N                               *
//                                                                           *
//---------------------------------------------------------------------------*

- (BOOL) shouldCloseDocument {
  return YES ;
} 

//---------------------------------------------------------------------------*

#pragma mark Document Encoding Display

//---------------------------------------------------------------------------*

- (NSString *) fileEncodingString {
  NSString * s = @"Lossy ASCII encoding" ;
  switch (mFileEncoding) {
  case NSASCIIStringEncoding : s = @"ASCII" ; break ;
  case NSNEXTSTEPStringEncoding : s = @"Next Step" ; break ;
  case NSJapaneseEUCStringEncoding : s = @"Japanese EUC" ; break ;
  case NSUTF8StringEncoding : s = @"UTF-8" ; break ;
  case NSISOLatin1StringEncoding : s = @"ISO Latin 1" ; break ;
  case NSSymbolStringEncoding : s = @"Symbol" ; break ;
  case NSNonLossyASCIIStringEncoding : s = @"Non Lossy ASCII" ; break ;
  case NSShiftJISStringEncoding : s = @"Shift JIS" ; break ;
  case NSISOLatin2StringEncoding : s = @"ISO Latin 2" ; break ;
  case NSUTF16StringEncoding : s = @"UTF-16" ; break ;
  case NSWindowsCP1251StringEncoding : s = @"Windows CP 1251" ; break ;
  case NSWindowsCP1252StringEncoding : s = @"Windows CP 1252" ; break ;
  case NSWindowsCP1253StringEncoding : s = @"Windows CP 1253" ; break ;
  case NSWindowsCP1254StringEncoding : s = @"Windows CP 1254" ; break ;
  case NSWindowsCP1250StringEncoding : s = @"Windows CP 1250" ; break ;
  case NSISO2022JPStringEncoding : s = @"ISO 2022" ; break ;
  case NSMacOSRomanStringEncoding : s = @"Mac OS Roman" ; break ;
  case NSUTF16BigEndianStringEncoding : s = @"UTF-16BE" ; break ;
  case NSUTF16LittleEndianStringEncoding : s = @"UTF_16LE" ; break ;
  case NSUTF32StringEncoding : s = @"UTF-32" ; break ;
  case NSUTF32BigEndianStringEncoding : s = @"UTF-32BE" ; break ;
  case NSUTF32LittleEndianStringEncoding : s = @"UTF-32LE" ; break ;
  default: break ;
  }
  return s ;
}


//---------------------------------------------------------------------------*

- (void) setSourceFileEncoding: (NSStringEncoding) inFileEncoding {
  [self willChangeValueForKey:@"fileEncodingString"] ;
  mFileEncoding = inFileEncoding ;
  [self didChangeValueForKey:@"fileEncodingString"] ;
}

//---------------------------------------------------------------------------*

#pragma mark Document Read

//---------------------------------------------------------------------------*

- (void) performCharacterConversion {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
//--- Get source string
  NSString * source = [mSourceTextWithSyntaxColoring sourceString] ;
//--- Search for "\r" ?
  BOOL needsConversionForCR = NO ;
  if ([[NSUserDefaults standardUserDefaults] boolForKey:@"PMConvert_CRLF_And_CR_To_LF_AtStartUp"]) {
    // NSLog (@"Convert CRLF and CR to LF") ;
    needsConversionForCR = [source rangeOfString:@"\r"].location != NSNotFound ;
  }
  BOOL needsConversionForHTAB = NO ;
  if ([[NSUserDefaults standardUserDefaults] boolForKey:@"PMConvert_HTAB_To_SPACE_AtStartUp"]) {
    // NSLog (@"Convert HTAB to SPACE") ;
    needsConversionForHTAB = [source rangeOfString:@"\x09"].location != NSNotFound ;
  }
  if (needsConversionForCR || needsConversionForHTAB) {
    NSMutableString * s = [NSMutableString new] ;
    if (needsConversionForCR) {
    //--- Convert CR LF to LF
      NSArray * a = [source componentsSeparatedByString:@"\r\n"] ;
      const NSUInteger CRLFcount = [a count] - 1 ;
      if (CRLFcount > 0) {
        source = [a componentsJoinedByString:@"\n"] ;
        if (CRLFcount == 1) {
          [s appendFormat:@"1 CRLF has been converted to LF."] ;
        }else if (CRLFcount > 1) {
          [s appendFormat:@"%u CRLF have been converted to LF.", CRLFcount] ;
        }
      }
    //--- Convert CR to LF
      a = [source componentsSeparatedByString:@"\r"] ;
      const NSUInteger CRcount = [a count] - 1 ;
      if (CRcount > 0) {
        source = [a componentsJoinedByString:@"\n"] ;
        if ([s length] > 0) {
          [s appendString:@"\n"] ;
        }
        if (CRcount == 1) {
          [s appendFormat:@"1 CR has been converted to LF."] ;
        }else if (CRcount > 1) {
          [s appendFormat:@"%u CR have been converted to LF.", CRcount] ;
        }
      }
    }
    if (needsConversionForHTAB) {
      NSArray * a = [source componentsSeparatedByString:@"\x09"] ;
      const NSUInteger HTABcount = [a count] - 1 ;
      if (HTABcount > 0) {
        source = [a componentsJoinedByString:@" "] ;
        if ([s length] > 0) {
          [s appendString:@"\n"] ;
        }
        if (HTABcount == 1) {
          [s appendFormat:@"1 HTAB has been converted to SPACE."] ;
        }else if (HTABcount > 1) {
          [s appendFormat:@"%u HTAB have been converted to SPACE.", HTABcount] ;
        }
      }
    }
  //--- Display sheet if conversion done
    if ([s length] > 0) {
      [mSourceTextWithSyntaxColoring replaceSourceStringWithString:source] ;
      NSAlert * alert = [NSAlert 
        alertWithMessageText:@"Source String Conversion"
        defaultButton:@"Ok"
        alternateButton:nil
        otherButton:nil
        informativeTextWithFormat:@"%@", s
      ] ;
      [alert
        beginSheetModalForWindow:[self windowForSheet]
        modalDelegate:nil
        didEndSelector:NULL
        contextInfo:NULL
      ] ;
    }
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//    R E A D    F R O M    F I L E                                          *
//                                                                           *
//---------------------------------------------------------------------------*

- (BOOL) readFromURL:(NSURL *) inAbsoluteURL
         ofType:(NSString *) inTypeName
         error:(NSError **)outError {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
//--- Try UTF8
  NSStringEncoding fileEncoding = mFileEncoding ;
  NSString * source = [[NSString alloc]
    initWithContentsOfURL:inAbsoluteURL
    encoding:fileEncoding
    error:outError
  ] ;
//--- If not UTF8, try any encoding
  if (source == nil) {
    NSLog (@"Try any encoding") ;
    if (nil != outError) {
      * outError = nil ;
    }
    source = [[NSString alloc]
      initWithContentsOfURL:inAbsoluteURL
      usedEncoding:& fileEncoding
      error:outError
    ] ;
  }
//--- If error, try lossy encoding
  if (source == nil) {
    NSLog (@"Try lossy encoding") ;
    if (nil != outError) {
      * outError = nil ;
    }
    NSData * data = [NSData dataWithContentsOfURL:inAbsoluteURL options:0 error:outError] ;
    if (nil != data) {
      const NSUInteger dataLength = [data length] ;
      const unsigned char * bytes = [data bytes] ;
      NSMutableString * s = [NSMutableString new] ;
      for (NSUInteger i=0 ; i<dataLength ; i++) {
        const unsigned char c = bytes [i] ;
        if ((c == 0x0A) || (c == 0x0D) || (c == 0x09) || ((c >= ' ') && (c <= 0x7E))) {
          [s appendFormat:@"%c", c] ;
        }else{
          [s appendFormat:@"%C", 0xFFFD] ; // Replacement character
        }
      }
      source = [s copy] ;
    }
  }
  [self setSourceFileEncoding:fileEncoding] ;
//--- Delegate for syntax coloring
  if (source != nil) {
    [[NSRunLoop currentRunLoop]
      performSelector:@selector (performCharacterConversion)
      target:self
      argument:nil
      order:0
      modes:[NSArray arrayWithObject:NSDefaultRunLoopMode]
    ] ;
  }
//---
  mSourceTextWithSyntaxColoring = [[OC_GGS_TextSyntaxColoring alloc]
    initWithSourceString:source
    tokenizer:tokenizerForExtension (inAbsoluteURL.absoluteString.pathExtension)
    sourceURL:self.fileURL
    issueArray:mBuildTask.issueArrayController.arrangedObjects
  ] ;
//---
  [mBuildTask.issueArrayController
    addObserver:mSourceTextWithSyntaxColoring 
    forKeyPath:@"arrangedObjects"
    options:0
    context:NULL
  ] ;
//---
  return source != nil ;
}

//---------------------------------------------------------------------------*

#pragma mark Build

//---------------------------------------------------------------------------*
//                                                                           *
//    C O M P I L E                                                          *
//                                                                           *
//---------------------------------------------------------------------------*

- (IBAction) stopBuild: (id) sender {
  [mBuildTask stopBuild] ;
}

//---------------------------------------------------------------------------*

- (IBAction) actionBuild: (id) inUnusedSender {
  [mBuildTask buildDocument:self] ;
}

//---------------------------------------------------------------------------*

- (BOOL) buildTaskIsRunning {
  return mBuildTask.buildTaskIsRunning ;
}

//---------------------------------------------------------------------------*

- (void) triggerDocumentEditedStatusUpdate {
  // NSLog (@"%s", __PRETTY_FUNCTION__) ;
  BOOL isEdited = NO ;
  NSArray * sourceDisplayArray = mSourceDisplayArrayController.arrangedObjects ;
  for (NSUInteger i=0 ; (i<sourceDisplayArray.count) && ! isEdited ; i++) {
    OC_GGS_TextDisplayDescriptor * textDisplay = [sourceDisplayArray objectAtIndex:i HERE] ;
    OC_GGS_TextSyntaxColoring * textSyntaxColoring = textDisplay.textSyntaxColoring ;
    NSUndoManager * undoManager = textSyntaxColoring.undoManager ;
    isEdited = undoManager.canUndo ;
  }
  [self updateChangeCount:isEdited ? NSChangeDone : NSChangeCleared] ;
}

//---------------------------------------------------------------------------*

- (void) triggerLiveCompilation {
  // NSLog (@"PMLiveCompilation %d", [[NSUserDefaults standardUserDefaults] boolForKey:@"PMLiveCompilation"]) ;
  if ([[NSUserDefaults standardUserDefaults] boolForKey:@"PMLiveCompilation"]) {
    [[NSRunLoop currentRunLoop]
      performSelector:@selector (abortAndBuildDocument:)
      target:mBuildTask
      argument:self
      order:0
      modes:[NSArray arrayWithObject:NSDefaultRunLoopMode]
    ] ;
  }
}

//---------------------------------------------------------------------------*

#pragma mark Click on issue table view

//---------------------------------------------------------------------------*

- (OC_GGS_TextSyntaxColoring *) findOrAddDocumentWithPath: (NSString *) inPath {
  OC_GGS_TextSyntaxColoring * result = nil ;
  NSString * currentSourceDir = mSourceTextWithSyntaxColoring.sourceURL.path.stringByDeletingLastPathComponent ;
  NSString * requestedAbsolutePath = inPath.isAbsolutePath
    ? inPath
    : [currentSourceDir stringByAppendingPathComponent:inPath]
  ;
//--- Search in opened documents
  NSArray * documents = [[NSDocumentController sharedDocumentController] documents] ;
  for (NSUInteger i=0 ; (i<documents.count) && (nil == result) ; i++) {
    OC_GGS_Document * doc = [documents objectAtIndex:i HERE] ;
    if ([requestedAbsolutePath isEqualToString:doc.fileURL.path]) {
      result = doc.textSyntaxColoring ;
    }
  }
//--- if not found, open a new document
  if (nil == result) {
    OC_GGS_Document * doc = [[NSDocumentController sharedDocumentController]
      openDocumentWithContentsOfURL:[NSURL fileURLWithPath:requestedAbsolutePath]
      display:YES
      error:nil
    ] ;
    [doc.windowForSheet orderBack:nil] ;
    result = doc.textSyntaxColoring ;
  }
//---  
  return result ;
}

//---------------------------------------------------------------------------*

- (OC_GGS_TextDisplayDescriptor *) findOrAddNewTabForFile: (NSString *) inDocumentPath {
  NSArray * sourceDisplayDescriptorArray = mSourceDisplayArrayController.arrangedObjects ;
  OC_GGS_TextSyntaxColoring * newTextSyntaxColoring = [self findOrAddDocumentWithPath:inDocumentPath] ;
  OC_GGS_TextDisplayDescriptor * foundSourceText = nil ;
  if (nil != newTextSyntaxColoring) { // Find a text display descriptor
    for (NSUInteger i=0 ; (i<sourceDisplayDescriptorArray.count) && (nil == foundSourceText) ; i++) {
      OC_GGS_TextDisplayDescriptor * std = [sourceDisplayDescriptorArray objectAtIndex:i HERE] ;
      if (std.textSyntaxColoring == newTextSyntaxColoring) {
        foundSourceText = std ;
      }
    }
    if (nil == foundSourceText) { // Create a tab
      foundSourceText = [[OC_GGS_TextDisplayDescriptor alloc]
        initWithDelegateForSyntaxColoring:newTextSyntaxColoring
        document:self
      ] ;
      [mSourceDisplayArrayController addObject:foundSourceText] ;
    }

    [mSourceDisplayArrayController setSelectedObjects:[NSArray arrayWithObject:foundSourceText]] ;
  }
  return foundSourceText ;
}

//---------------------------------------------------------------------------*

- (void) clicOnIssueTableView: (id) inSender {
  const NSInteger clickedRow = mIssueTableView.clickedRow ;
  NSArray * arrangedObjects = mBuildTask.issueArrayController.arrangedObjects ;
  if ((clickedRow >= 0) && (clickedRow < (NSInteger) arrangedObjects.count)) {
    PMIssueDescriptor * issue = [arrangedObjects objectAtIndex:clickedRow HERE] ;
    NSArray * sourceDisplayArray = mSourceDisplayArrayController.arrangedObjects ;
    OC_GGS_TextDisplayDescriptor * textDisplay = [sourceDisplayArray objectAtIndex:mSourceDisplayArrayController.selectionIndex HERE] ;
    [self displayIssueDetailedMessage:issue.issueMessage] ;
    const BOOL ok = [textDisplay makeVisibleIssue:issue] ;
    if (! ok) { // Current tab view does not correspond: open a new tab
      textDisplay = [self findOrAddNewTabForFile:issue.issueURL.path] ;
      [textDisplay makeVisibleIssue:issue] ;
    }
  }
}

//---------------------------------------------------------------------------*

#pragma mark Entry Pop up

//---------------------------------------------------------------------------*

- (void) populatePopUpButton {
  if (mSourceDisplayArrayController.selectionIndex != NSNotFound) {
    NSArray * sourceDisplayArray = mSourceDisplayArrayController.arrangedObjects ;
    OC_GGS_TextDisplayDescriptor * textDisplay = [sourceDisplayArray objectAtIndex:mSourceDisplayArrayController.selectionIndex HERE] ;
    NSMenu * menu = [textDisplay menuForEntryPopUpButton] ;
    const NSUInteger n = [menu numberOfItems] ;
    if (n == 0) {
      [menu
        addItemWithTitle:@"No entry"
        action:NULL
        keyEquivalent:@""
      ] ;
      [mEntryListPopUpButton setEnabled:NO] ;
    }else{
      for (NSUInteger i=0 ; i<n ; i++) {
        NSMenuItem * item = [menu itemAtIndex:i] ;
        [item setTarget:self] ;
        [item setAction:@selector (gotoEntry:)] ;
      }
      [mEntryListPopUpButton setEnabled:YES] ;
    }
    [mEntryListPopUpButton setMenu:menu] ;
    //NSLog (@"mEntryListPopUpButton %@", mEntryListPopUpButton) ;
  }
}

//---------------------------------------------------------------------------*

- (void) gotoEntry: (id) inSender {
  const NSRange range = {[inSender tag], 0} ;
  NSArray * sourceDisplayArray = mSourceDisplayArrayController.arrangedObjects ;
  OC_GGS_TextDisplayDescriptor * textDisplay = [sourceDisplayArray objectAtIndex:mSourceDisplayArrayController.selectionIndex HERE] ;
  NSTextView * textView = textDisplay.textView ;
  [textView setSelectedRange:range] ;
  [textView scrollRangeToVisible:range] ;
}

//---------------------------------------------------------------------------*

- (void) selectEntryPopUp {
  if (mSourceDisplayArrayController.selectionIndex != NSNotFound) {
    NSArray * sourceDisplayArray = mSourceDisplayArrayController.arrangedObjects ;
    OC_GGS_TextDisplayDescriptor * textDisplay = [sourceDisplayArray objectAtIndex:mSourceDisplayArrayController.selectionIndex HERE] ;
    const NSUInteger selectionStart = textDisplay.textSelectionStart ;
    NSArray * menuItemArray = [mEntryListPopUpButton itemArray] ;
    if ([mEntryListPopUpButton isEnabled]) {
      NSInteger idx = NSNotFound ;
      NSInteger i ;
      const NSInteger n = [menuItemArray count] ;
      for (i=n-1 ; (i>=0) && (idx == NSNotFound) ; i--) {
        NSMenuItem * item = [menuItemArray objectAtIndex:i HERE] ;
        const NSUInteger startPoint = [item tag] ;
        if (selectionStart >= startPoint) {
          idx = i ;
        }
      }
      if (idx == NSNotFound) {
        [mEntryListPopUpButton selectItemAtIndex:0] ;
      }else{
        [mEntryListPopUpButton selectItemAtIndex:idx] ;
      }
    }
  }
}

//---------------------------------------------------------------------------*

#pragma mark observeValueForKeyPath

//---------------------------------------------------------------------------*

- (void) observeValueForKeyPath:(NSString *) inKeyPath
         ofObject: (id) inObject
         change:(NSDictionary *) inChange
         context:(void *) inContext {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  if ([inKeyPath isEqualToString:@"selectionIndex"]) {
    for (NSView * subview in mSourceHostView.subviews.copy) {
      [subview removeFromSuperview] ;
    }
    NSArray * arrangedObjects = mSourceDisplayArrayController.arrangedObjects ;
    const NSUInteger sel = mSourceDisplayArrayController.selectionIndex ;
    if (sel != NSNotFound) {
      OC_GGS_TextDisplayDescriptor * object = [arrangedObjects objectAtIndex:sel HERE] ;
      object.scrollView.frame = mSourceHostView.bounds ;
      // NSLog (@"object.scrollView %d", object.scrollView.autoresizesSubviews) ;
      [mSourceHostView addSubview:object.scrollView] ;
      [mSourceHostView.window makeFirstResponder:object.textView] ;
    }
  }else if ([inKeyPath isEqualToString:@"selection.textSelectionStart"]) {
    [self selectEntryPopUp] ;
  }else if ([inKeyPath isEqualToString:@"selection.mTextSyntaxColoring.mTokenizer.menuForEntryPopUpButton"]) {
    [self populatePopUpButton] ;
  }
}

//---------------------------------------------------------------------------*

- (void) displayIssueDetailedMessage: (NSString *) inDetailledMessage {
  NSTextStorage * textStorage = mDetailedIssueTextView.textStorage ;
  if (nil == inDetailledMessage) {
    [textStorage beginEditing] ;
    [textStorage replaceCharactersInRange:NSMakeRange (0, [textStorage length]) withString:@""] ;
    [textStorage endEditing] ;
    [mDetailedIssueSplitView
      setPosition:mDetailedIssueSplitView.bounds.size.height
      ofDividerAtIndex:0
    ] ;
  }else{
    [textStorage beginEditing] ;
    [textStorage replaceCharactersInRange:NSMakeRange (0, [textStorage length]) withString:inDetailledMessage] ;
    [mDetailedIssueTextView setFont:[NSFont fontWithName:@"Courier" size:13.0]] ;
    [textStorage endEditing] ;
    const NSRect r = [mDetailedIssueTextView.layoutManager
      lineFragmentUsedRectForGlyphAtIndex:inDetailledMessage.length - 1
      effectiveRange:NULL
    ] ;
   // NSLog (@"r %g %g %g %g", r.origin.x, r.origin.y, r.size.width, r.size.height) ;
    // NSLog (@"mDetailedIssueTextView.textContainerInset.height %g", mDetailedIssueTextView.textContainerInset.height) ;
    const double position = mDetailedIssueSplitView.bounds.size.height - mDetailedIssueSplitView.dividerThickness - NSMaxY (r) - 8.0 ;
    [mDetailedIssueSplitView
      setPosition:position
      ofDividerAtIndex:0
    ] ;
  }
}

//---------------------------------------------------------------------------*

- (CGFloat) splitView:(NSSplitView *)splitView
            constrainMinCoordinate:(CGFloat)proposedMin
            ofSubviewAt:(NSInteger) inDividerIndex {
  return 40.0 ;
}

//---------------------------------------------------------------------------*

#pragma mark Open Quickly

//---------------------------------------------------------------------------*

- (void) actionOpenQuickly: (id) sender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSArray * sourceDisplayDescriptorArray = mSourceDisplayArrayController.arrangedObjects ;
  const NSUInteger sel = mSourceDisplayArrayController.selectionIndex ;
  OC_GGS_TextDisplayDescriptor * currentSourceText = [sourceDisplayDescriptorArray objectAtIndex:sel HERE] ;
  OC_GGS_TextSyntaxColoring * textSyntaxColoring = currentSourceText.textSyntaxColoring ;
//--- Get source string
  NSString * sourceString = textSyntaxColoring.sourceString ;
  const NSUInteger length = sourceString.length ;
//--- Get selection
  NSRange selection = currentSourceText.textView.selectedRange ;
//--- A selection is available ?
  BOOL ok = (selection.location != NSNotFound) ;
  if (ok && (selection.length > 1) && ([sourceString characterAtIndex:selection.location] == '\"')) {
    selection.location ++ ;
    selection.length -- ;
  }
  if (ok && (selection.length > 1) && ([sourceString characterAtIndex:selection.location + selection.length - 1] == '\"')) {
    selection.length -- ;
  }
//--- Check there is end of line within the selection
  if (ok) {
    for (NSUInteger i=selection.location ; (i<(selection.location + selection.length)) && ok ; i++) {
      const unichar c = [sourceString characterAtIndex:i] ;
      ok = (c != '\n') & (c != '\r') ;
    }
  }
//--- If ok, extend selection until a '\r', '\n' or a '"'.
  if (ok) {
    NSUInteger idx = selection.location + selection.length ;
    while ((idx < length)
        && ([sourceString characterAtIndex:idx] != '\r')
        && ([sourceString characterAtIndex:idx] != '\n')
        && ([sourceString characterAtIndex:idx] != '\"')) {
      idx ++ ;
      selection.length ++ ;
    }
  }
//--- If ok, advance selection until a '\r', '\n' or a '"'
  if (ok && (selection.location > 0)) {
    NSUInteger idx = selection.location - 1 ;
    while ((idx > 0)
        && ([sourceString characterAtIndex:idx] != '\r')
        && ([sourceString characterAtIndex:idx] != '\n')
        && ([sourceString characterAtIndex:idx] != '\"')) {
      idx -- ;
      selection.location -- ;
      selection.length ++ ;
    }
  }
//--- Display selection
  [currentSourceText.textView setSelectedRange:selection] ;
//---
  NSString * selectedString = [sourceString substringWithRange:selection] ;
  [self findOrAddNewTabForFile:selectedString] ;
}

//---------------------------------------------------------------------------*

@end
