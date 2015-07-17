//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2003, ..., 2014 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes, ECN, École Centrale de Nantes (France)  *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#import "OC_GGS_Document.h"
#import "OC_GGS_ApplicationDelegate.h"
#import "OC_GGS_RulerViewForTextView.h"
#import "OC_Lexique.h"
#import "F_CocoaWrapperForGalgas.h"
#import "PMIssueDescriptor.h"
#import "OC_GGS_TextSyntaxColoring.h"
#import "OC_GGS_TextDisplayDescriptor.h"
#import "OC_GGS_BuildTask.h"
#import "OC_GGS_DocumentData.h"
#import "OC_GGS_RulerViewForBuildOutput.h"
#import "OC_GGS_Scroller.h"
#import "PMDebug.h"
#import "PMSearchResultDescriptor.h"
#import "NSString+identifierRepresentation.h"

//---------------------------------------------------------------------------------------------------------------------*

// #define DEBUG_MESSAGES

//---------------------------------------------------------------------------------------------------------------------*

@implementation OC_GGS_Document

//---------------------------------------------------------------------------------------------------------------------*

@synthesize mBuildTaskIsRunning ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//       I N I T                                                                                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (instancetype) init {
  self = [super init] ;
  if (self) {
    #ifdef DEBUG_MESSAGES
      NSLog (@"%s", __PRETTY_FUNCTION__) ;
    #endif
    noteObjectAllocation (self) ;
    mSourceDisplayArrayControllerHigh = [NSArrayController new] ;
    mDisplayDescriptorArrayHigh = [NSMutableArray new] ;
    self.undoManager = nil ;
    self.hasUndoManager = NO ;
  //---
    NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
    NSData * data = [ud objectForKey:GGS_build_text_font] ;
    if (nil != data) {
      mBuildTextFont = [NSUnarchiver unarchiveObjectWithData:data] ;
    }
    if (nil == mBuildTextFont) {
      mBuildTextFont = [NSFont fontWithName:@"Courier" size:13.0] ;
    }
  //--- Add font change observer
    [ud
      addObserver:self
      forKeyPath:GGS_build_text_font
      options:0
      context:NULL
    ] ;
   }
  return self;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) FINALIZE_OR_DEALLOC {
  noteObjectDeallocation (self) ;
  macroSuperFinalize ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSString *) sourceStringForGlobalSearch {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  return mDocumentData.sourceString ;
}

//---------------------------------------------------------------------------------------------------------------------*

#pragma mark Nib relative Actions

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//       W I N D O W    N I B    N A M E                                                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (NSString *) windowNibName {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  return @"OC_GGS_Document" ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//       W I N D O W    C O N T R O L L E R    D I D    L O A D    N I B                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (void) windowControllerDidLoadNib: (NSWindowController *) inWindowController {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [super windowControllerDidLoadNib: inWindowController];
//--- Tell to window controller that closing the source text window closes the document
  [inWindowController setShouldCloseDocument: YES] ;
//--- Set up windows location
  NSString * key = [NSString stringWithFormat: @"frame_for_source:%@", mBaseFilePreferenceKey] ;
  [self.windowForSheet setFrameAutosaveName:key] ;

//--- Add Split view binding
// Note : use [self lastComponentOfFileName] instead of [window title], because window title may not set at this point
  key = [NSString stringWithFormat:@"values.issue-split-fraction:%@", mBaseFilePreferenceKey] ;
  [mFirstSplitView setAutosaveName:key] ;
  key = [NSString stringWithFormat:@"values.build-split-fraction:%@", mBaseFilePreferenceKey] ;
  [mSecondSplitView setAutosaveName:key] ;
//---
  mFirstSplitView.delegate = self ;
  mSecondSplitView.delegate = self ;
//---
  mOccurenceFoundCountTextField.stringValue = @"" ;
//--- Global search result display
  mFoundEntryTreeController = [NSTreeController new] ;
  mFoundEntryTreeController.childrenKeyPath = @"children" ;
  [mFoundEntryTreeController
    bind:@"contentArray"
    toObject:self
    withKeyPath:@"mResultArray"
    options:nil
  ] ;
  [mFoundEntryTreeController
    addObserver:self 
    forKeyPath:@"selectionIndexPath"
    options:0
    context:NULL
  ] ;
  [[mResultOutlineView tableColumnWithIdentifier:@"count"]
    bind:@"value"
    toObject:mFoundEntryTreeController
    withKeyPath:@"arrangedObjects.countString"
    options:nil
  ] ;
  [[mResultOutlineView tableColumnWithIdentifier:@"result"]
    bind:@"value"
    toObject:mFoundEntryTreeController
    withKeyPath:@"arrangedObjects.foundItem"
    options:nil
  ] ;
  [[mResultOutlineView tableColumnWithIdentifier:@"result"]
    bind:@"fontBold"
    toObject:mFoundEntryTreeController
    withKeyPath:@"arrangedObjects.boldDisplay"
    options:nil
  ] ;
  [[mResultOutlineView tableColumnWithIdentifier:@"result"]
    bind:@"textColor"
    toObject:mFoundEntryTreeController
    withKeyPath:@"arrangedObjects.color"
    options:nil
  ] ;
//---
  [mSourceDisplayArrayControllerHigh
    bind:@"contentArray"
    toObject:self
    withKeyPath:@"mDisplayDescriptorArrayHigh"
    options:nil
  ] ;
//---
  [mSourceDisplayArrayControllerHigh
    addObserver:self 
    forKeyPath:@"selection.textSelectionStart"
    options:0
    context:NULL
  ] ;
//---
  [mSourceFilePathControl
    bind:@"value"
    toObject:mSourceDisplayArrayControllerHigh
    withKeyPath:@"selection.sourceURL.path"
    options:nil    
  ] ;
//---
  [[mDisplayDescriptorTableViewHigh tableColumnWithIdentifier:@"source"]
    bind:@"value"
    toObject:mSourceDisplayArrayControllerHigh
    withKeyPath:@"arrangedObjects.title"
    options:nil    
  ] ;
//---
  [[mDisplayDescriptorTableViewHigh tableColumnWithIdentifier:@"source"]
    bind:@"fontBold"
    toObject:mSourceDisplayArrayControllerHigh
    withKeyPath:@"arrangedObjects.isDirty"
    options:nil    
  ] ;
//---
  [[mDisplayDescriptorTableViewHigh tableColumnWithIdentifier:@"remove"]
    bind:@"value"
    toObject:mSourceDisplayArrayControllerHigh
    withKeyPath:@"arrangedObjects.imageForClosingInUserInterface"
    options:nil    
  ] ;
//---
  mDisplayDescriptorTableViewHigh.target = self ;
  mDisplayDescriptorTableViewHigh.action = @selector (clickOnSourceTableViewHigh:) ;
  [mDisplayDescriptorTableViewHigh setDataSource:self] ;
  [mDisplayDescriptorTableViewHigh
    registerForDraggedTypes:[NSArray arrayWithObjects:
      (NSString*)kUTTypeFileURL,
      nil
    ]
  ] ;
//---
  [mBuildProgressIndicator startAnimation:nil] ;
  NSDictionary * negateTransformer = [NSDictionary
    dictionaryWithObject:NSNegateBooleanTransformerName 
    forKey:@"NSValueTransformerName"
  ] ;
  [mStartBuildButton
    bind:@"hidden"
    toObject:self
    withKeyPath:@"mBuildTaskIsRunning"
    options:nil
  ] ;
  [mBuildProgressIndicator
    bind:@"hidden"
    toObject:self
    withKeyPath:@"mBuildTaskIsRunning"
    options:negateTransformer    
  ] ;
  [mStopBuildButton
    bind:@"enabled"
    toObject:self
    withKeyPath:@"mBuildTaskIsRunning"
    options:nil    
  ] ;
  [mStopBuildButton
    bind:@"hidden"
    toObject:self
    withKeyPath:@"mBuildTaskIsRunning"
    options:negateTransformer    
  ] ;
//---
  mWarningCountTextField.stringValue = @"0" ;
  mErrorCountTextField.stringValue = @"0" ;
//---
  [mOutputScrollView setVerticalScroller:[OC_GGS_Scroller new]] ;
//------------------------------------------------------------------- Get selected tab
//  NSString * openedFilePath = self.fileURL.path ;
  key = [NSString stringWithFormat:@"SELECTED-TAB:%@", mBaseFilePreferenceKey] ;
  const NSUInteger selectedTab = (NSUInteger) [[NSUserDefaults standardUserDefaults] integerForKey:key] ;
//  NSLog (@"READ selectedTab %lu", selectedTab) ;
//------------------------------------------------------------------- Install selected tab observer
  [mSourceDisplayArrayControllerHigh
    addObserver:self 
    forKeyPath:@"selectionIndex"
    options:0
    context:NULL
  ] ;
//------------------------------------------------------------------ Display the document contents
  OC_GGS_TextDisplayDescriptor * textDisplayDescriptor = [mDocumentData newSourceDisplayDescriptorForDocument:self] ;
  if (nil != textDisplayDescriptor) {
    [mSourceDisplayArrayControllerHigh addObject:textDisplayDescriptor] ;
    [mSourceDisplayArrayControllerHigh setSelectedObjects:[NSArray arrayWithObject:textDisplayDescriptor]] ;
  //---
    mRulerViewForBuildOutput = [[OC_GGS_RulerViewForBuildOutput alloc] initWithDocument:self] ;
    [mOutputScrollView setVerticalRulerView:mRulerViewForBuildOutput] ;
    [mOutputScrollView setHasVerticalRuler:YES] ;
    [mOutputScrollView.verticalRulerView setRuleThickness:8.0] ;
    [mOutputScrollView setRulersVisible:YES] ;
  }
//------------------------------------------------------------------ Open tabs
//--- Open tabs
  key = [NSString stringWithFormat:@"CONFIG:%@", mBaseFilePreferenceKey] ;
  NSArray * tabFiles = [[[NSUserDefaults standardUserDefaults] objectForKey:key] copy] ;
  for (NSString * fileAbsolutePath in tabFiles) {
    [self appendTabForFile:fileAbsolutePath] ;
  }
//--- Select tab
  NSArray * sourceDisplayArray = mSourceDisplayArrayControllerHigh.arrangedObjects ;
  mSourceDisplayArrayControllerHigh.selectionIndex = (selectedTab < sourceDisplayArray.count) ? selectedTab : 0 ;
  // NSLog (@"DONE") ;
//---
  [mCaseSensitiveSearchCheckbox
    bind:@"value"
    toObject:[NSUserDefaultsController sharedUserDefaultsController] 
    withKeyPath:@"values.SENSITIVE-SEARCH" 
    options:nil
  ] ;
  [mGlobalReplaceTextField
    bind:@"value"
    toObject:[NSUserDefaultsController sharedUserDefaultsController] 
    withKeyPath:@"values.GLOBAL-REPLACE-FIELD" 
    options:nil
  ] ;
  [mSearchMatrix
    bind:@"selectedIndex"
    toObject:[NSUserDefaultsController sharedUserDefaultsController] 
    withKeyPath:[NSString stringWithFormat:@"values.searchMatrixFor:%@", mBaseFilePreferenceKey]
    options:nil
  ] ;
  [[NSUserDefaults standardUserDefaults]
    addObserver:self
    forKeyPath:[NSString stringWithFormat:@"searchMatrixFor:%@", mBaseFilePreferenceKey]
    options:0
    context:NULL
  ] ;
  [self updateDirectoryListVisibility] ;
//--- Configuring recent search menu
  NSMenu * cellMenu = [[NSMenu alloc]
    initWithTitle:NSLocalizedString(@"Search Menu", @"Search Menu title")
  ] ;
  NSMenuItem * item = [[NSMenuItem alloc]
    initWithTitle:NSLocalizedString(@"Clear", @"Clear menu title")
    action:NULL
    keyEquivalent:@""
  ];
  [item setTag:NSSearchFieldClearRecentsMenuItemTag];
  [cellMenu insertItem:item atIndex:0];
  item = [NSMenuItem separatorItem];
  [item setTag:NSSearchFieldRecentsTitleMenuItemTag];
  [cellMenu insertItem:item atIndex:1];
  item = [[NSMenuItem alloc]
    initWithTitle:NSLocalizedString(@"Recent Searches", @"Recent Searches menu title")
    action:NULL keyEquivalent:@""
  ];
  [item setTag:NSSearchFieldRecentsTitleMenuItemTag];
  [cellMenu insertItem:item atIndex:2];
  item = [[NSMenuItem alloc]
    initWithTitle:@"Recents"
    action:NULL
    keyEquivalent:@""
  ];
  [item setTag:NSSearchFieldRecentsMenuItemTag];
  [cellMenu insertItem:item atIndex:3];
  id searchCell = [mGlobalSearchTextField cell];
  [searchCell setSearchMenuTemplate:cellMenu];

//--- Excluded directories
  mExcludedDirectoryArrayController = [NSArrayController new] ;
  mAddExcludedDirectoryButton.action = @selector (addExcludedDirectoryAction:) ;
  mAddExcludedDirectoryButton.target = self ;
  mRemoveExcludedDirectoryButton.action = @selector (remove:) ;
  mRemoveExcludedDirectoryButton.target = mExcludedDirectoryArrayController ;
  [mExcludedDirectoryArrayController
    bind:@"contentArray"
    toObject:[NSUserDefaultsController sharedUserDefaultsController]
    withKeyPath:[NSString stringWithFormat:@"values.excludedDirectoryArray:%@", mBaseFilePreferenceKey] // self.fileURL.absoluteString.identifierRepresentation]
    options:nil
  ] ;
  [mRemoveExcludedDirectoryButton
    bind:@"enabled"
    toObject:mExcludedDirectoryArrayController
    withKeyPath:@"canRemove"
    options:nil
  ] ;
  [[mExcludedDirectoryTableView tableColumnWithIdentifier:@"path"]
    bind:@"value"
    toObject:mExcludedDirectoryArrayController
    withKeyPath:@"arrangedObjects"
    options:nil
  ] ;

//--- Excplicit search in directories
  mExplicitSearchDirectoryArrayController = [NSArrayController new] ;
  mAddExplicitSearchDirectoryButton.action = @selector (addExplicitSearchDirectoryAction:) ;
  mAddExplicitSearchDirectoryButton.target = self ;
  mRemoveExplicitSearchDirectoryButton.action = @selector (remove:) ;
  mRemoveExplicitSearchDirectoryButton.target = mExplicitSearchDirectoryArrayController ;
  [mExplicitSearchDirectoryArrayController
    bind:@"contentArray"
    toObject:[NSUserDefaultsController sharedUserDefaultsController]
    withKeyPath:[NSString stringWithFormat:@"values.searchDirectoryArray:%@", mBaseFilePreferenceKey] // self.fileURL.absoluteString.identifierRepresentation]
    options:nil
  ] ;
  [mRemoveExplicitSearchDirectoryButton
    bind:@"enabled"
    toObject:mExplicitSearchDirectoryArrayController
    withKeyPath:@"canRemove"
    options:nil
  ] ;
  [[mExplicitSearchDirectoryTableView tableColumnWithIdentifier:@"path"]
    bind:@"value"
    toObject:mExplicitSearchDirectoryArrayController
    withKeyPath:@"arrangedObjects"
    options:nil
  ] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) removeWindowController:(NSWindowController *) inWindowController {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
//---
  [OC_GGS_DocumentData saveAllDocuments] ;
//---
  NSArray * sourceDisplayArray = mSourceDisplayArrayControllerHigh.arrangedObjects ;
  for (OC_GGS_TextDisplayDescriptor * tdd in sourceDisplayArray) {
    [tdd detachTextDisplayDescriptor] ;
  }
//---
  for (PMIssueDescriptor * issue in mIssueArray) {
    [issue detach] ;
  }
//---
  [mRulerViewForBuildOutput detach] ;
  for (NSView * subview in mSourceHostView.subviews.copy) {
    [subview removeFromSuperview] ;
  }
//---
  [mSourceFilePathControl
    unbind:@"value"
  ] ;
//---
  [mSourceDisplayArrayControllerHigh
    unbind:@"contentArray"
  ] ;
  [mSourceDisplayArrayControllerHigh
    removeObserver:self 
    forKeyPath:@"selectionIndex"
  ] ;
//---
  [mSourceDisplayArrayControllerHigh
    removeObserver:self 
    forKeyPath:@"selection.textSelectionStart"
  ] ;
//---
  [mStartBuildButton
    unbind:@"hidden"
  ] ;
  [mBuildProgressIndicator
    unbind:@"hidden"
  ] ;
  [mStopBuildButton
    unbind:@"enabled"
  ] ;
  [mStopBuildButton
    unbind:@"hidden"
  ] ;
//---
  [[mDisplayDescriptorTableViewHigh tableColumnWithIdentifier:@"source"]
    unbind:@"value"
  ] ;
  [[mDisplayDescriptorTableViewHigh tableColumnWithIdentifier:@"source"]
    unbind:@"fontBold"
  ] ;
  [[mDisplayDescriptorTableViewHigh tableColumnWithIdentifier:@"remove"]
    unbind:@"value"
  ] ;
//---
  [mFoundEntryTreeController
    unbind:@"contentArray"
  ] ;
  [mFoundEntryTreeController
    removeObserver:self 
    forKeyPath:@"selectionIndexPath"
  ] ;
  [[mResultOutlineView tableColumnWithIdentifier:@"count"]
    unbind:@"value"
  ] ;
  [[mResultOutlineView tableColumnWithIdentifier:@"result"]
    unbind:@"value"
  ] ;
  [[mResultOutlineView tableColumnWithIdentifier:@"result"]
    unbind:@"fontBold"
  ] ;
  [[mResultOutlineView tableColumnWithIdentifier:@"result"]
    unbind:@"textColor"
  ] ;
//---
  NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
  [ud
    removeObserver:self
    forKeyPath:GGS_build_text_font
  ] ;
//---
  [mCaseSensitiveSearchCheckbox
    unbind:@"value"
  ] ;
  [mGlobalReplaceTextField
    unbind:@"value"
  ] ;
  [mSearchMatrix
    unbind:@"selectedIndex"
  ] ;
  [ud
    removeObserver:self
    forKeyPath:[NSString stringWithFormat:@"searchMatrixFor:%@", mBaseFilePreferenceKey]
  ] ;
//---
  mSourceDisplayArrayControllerHigh = nil ;
  mDisplayDescriptorArrayHigh = nil ;
//---
  [mRemoveExcludedDirectoryButton unbind:@"enabled"] ;
  [[mExcludedDirectoryTableView tableColumnWithIdentifier:@"path"] unbind:@"value"] ;
  [mExcludedDirectoryArrayController unbind:@"contentArray"] ;
  mExcludedDirectoryArrayController = nil ;
//--- Last call
  [OC_GGS_DocumentData cocoaDocumentWillClose:mDocumentData] ;
//---
  [super removeWindowController:inWindowController] ;
}

//---------------------------------------------------------------------------------------------------------------------*

#pragma mark Actions

//---------------------------------------------------------------------------------------------------------------------*

- (void) registerConfigurationInPreferences {
  NSMutableArray * configurationArray = [NSMutableArray new] ;
  for (OC_GGS_TextDisplayDescriptor * source in mSourceDisplayArrayControllerHigh.arrangedObjects) {
    [configurationArray addObject:source.sourceURL.path] ;
  }
  NSString * key = [NSString stringWithFormat:@"CONFIG:%@", mBaseFilePreferenceKey] ;
  [configurationArray removeObjectAtIndex:0] ;
  [[NSUserDefaults standardUserDefaults]
    setObject:configurationArray
    forKey:key
  ] ;
  // NSLog (@"Write Prefs '%@' -> %@", key, configurationArray) ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) changeSelectedSourceViewAction: (NSButton *) inSender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [mSourceDisplayArrayControllerHigh setSelectionIndex:(NSUInteger) inSender.tag] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (IBAction) actionGotoLine: (id) inSender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [NSApp
    beginSheet:mGotoWindow
    modalForWindow:self.windowForSheet
    modalDelegate: self
    didEndSelector: @selector (sheetDidEnd:returnCode:contextInfo:)
    contextInfo: nil
  ] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) collapseIssuesAction: (id) inSender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [mFirstSplitView setPosition:0.0 ofDividerAtIndex:0] ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//        S H E E T    D I D    E N D    ( G O T O    L I N E )                                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (void) sheetDidEnd: (NSWindow *) inSheet
         returnCode: (int) inReturnCode
         contextInfo: (void *) inContextInfo {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  if (inReturnCode == 1) {
  //--- Get selected line
    const NSUInteger selectedLine = (NSUInteger) [mGotoLineTextField integerValue] ;
  //--- Goto selected line
    OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
    [selectedObject gotoLine:selectedLine] ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (IBAction) actionComment: (id) sender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  [selectedObject commentSelection] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (IBAction) actionUncomment: (id) sender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  [selectedObject uncommentSelection] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (IBAction) actionShiftLeft: (id) sender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  [selectedObject shiftLeftAction] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (IBAction) actionShiftRight: (id) sender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  [selectedObject shiftRightAction] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (BOOL) validateMenuItem:(NSMenuItem *) item {
  BOOL result = YES ;
  if ((item.action == @selector (actionComment:)) || (item.action == @selector (actionUncomment:))) {
    OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
    result = selectedObject.documentData.textSyntaxColoring.tokenizer.blockComment.length > 0 ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (IBAction) saveAllDocuments: (id) inSender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [OC_GGS_DocumentData saveAllDocuments] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) displaySourceWithURL: (NSURL *) inURL
         atLine: (NSUInteger) inLine {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  if (nil != inURL) {
    OC_GGS_TextDisplayDescriptor * tdd = [self findOrAddNewTabForFile:inURL.path] ;
    const NSRange r = {[tdd.documentData locationForLineInSource:inLine], 0} ;
    [tdd setSelectionRangeAndMakeItVisible:r] ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (IBAction) actionPathControl: (id) inSender {
  NSArray * cells = mSourceFilePathControl.pathComponentCells ;
  NSCell * clickedCell = mSourceFilePathControl.clickedPathComponentCell ;
  NSUInteger clickedCellIndex = [cells indexOfObject:clickedCell] ;
  // NSLog (@"%lu", clickedCellIndex) ;
  NSMutableString * rootPath = [NSMutableString new] ;
  for (NSUInteger i=0 ; i<clickedCellIndex ; i++) {
    [rootPath appendFormat:@"/%@", [[cells objectAtIndex:i] title]] ;
  }
  // NSLog (@"path '%@'", path) ;
  NSWorkspace * ws = [NSWorkspace sharedWorkspace] ;
  NSString * path = [NSString stringWithFormat:@"%@/%@", rootPath, [[cells objectAtIndex:clickedCellIndex] title]] ; 
  [ws selectFile:path inFileViewerRootedAtPath:rootPath] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (IBAction) copyFilePath: (id) inSender {
  OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  NSString * filePath = selectedObject.sourceURL.path ;
  NSPasteboard * pasteboard = [NSPasteboard generalPasteboard] ;
  [pasteboard clearContents] ;
  [pasteboard writeObjects:[NSArray arrayWithObject:filePath]] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (IBAction) copyFileName: (id) inSender {
  OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  NSString * fileName = selectedObject.sourceURL.path.lastPathComponent ;
  NSPasteboard * pasteboard = [NSPasteboard generalPasteboard] ;
  [pasteboard clearContents] ;
  [pasteboard writeObjects:[NSArray arrayWithObject:fileName]] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (IBAction) copyFileDirectory: (id) inSender {
  OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  NSString * fileDirectory = selectedObject.sourceURL.path.stringByDeletingLastPathComponent ;
  NSPasteboard * pasteboard = [NSPasteboard generalPasteboard] ;
  [pasteboard clearContents] ;
  [pasteboard writeObjects:[NSArray arrayWithObject:fileDirectory]] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) actionInsertTextMacro: (NSMenuItem *) inSender {
  OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  [selectedObject actionInsertTextMacro:inSender] ;
}

//---------------------------------------------------------------------------------------------------------------------*

#pragma mark Document Actions

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//    P R I N T                                                                                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (void) printDocument: (id) sender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  [selectedObject.textView print:sender] ;
}

//---------------------------------------------------------------------------------------------------------------------*

#pragma mark Tracking File Document changes

//---------------------------------------------------------------------------------------------------------------------*

- (NSDate *) sourceFileModificationDateInFileSystem {
  NSURL * fileURL = [self fileURL] ;
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSDate * date = [NSDate date] ;
  if ([fileURL isFileURL]) {
    NSFileManager * fm = [NSFileManager new] ;
    NSDictionary * fileAttributes = [fm attributesOfItemAtPath:[fileURL path] error:NULL] ;
    date = [fileAttributes objectForKey:NSFileModificationDate] ;
  }
  return date ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

/*- (void) askForUpdatingFromFileSystem {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
//--- Get application name
  NSDictionary * bundleDictionary = [[NSBundle mainBundle] localizedInfoDictionary] ;
  NSString * applicationName = [bundleDictionary objectForKey: @"CFBundleName"] ;
//--- Build Alert
  NSAlert *alert = [NSAlert
    alertWithMessageText:@"Warning"
    defaultButton:[NSString stringWithFormat:@"Keep %@ Version", applicationName]
    alternateButton:@"Update From File Contents"
    otherButton:nil
    informativeTextWithFormat:@"This file for document at %@ has been modified by an other application."
      " Do you want to keep the %@ version or update from file contents ?",
      self.fileURL.path,
      applicationName
  ] ;
//--- Display alert as window sheet
  [alert
    beginSheetModalForWindow:[self windowForSheet]
    modalDelegate:self
    didEndSelector:@selector (askForUpdatingFromFileSystemAlertEnding:returnCode:contextInfo:)
    contextInfo:NULL
  ] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) askForUpdatingFromFileSystemAlertEnding:(NSAlert *) inAlert
         returnCode:(int) returnCode
         contextInfo:(void *) contextInfo {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
//  NSLog (@"returnCode %d", returnCode) ;
  if (returnCode == NSAlertAlternateReturn) { // Revert button
    [[NSRunLoop mainRunLoop]
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

//---------------------------------------------------------------------------------------------------------------------*

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
*/

//---------------------------------------------------------------------------------------------------------------------*

#pragma mark Document Save

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//    S A V E    D O C U M E N T                                                                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (void) saveDocument:(id) inSender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
//---
  NSURL * url = [self fileURL] ;
  [self setFileURL:mDocumentData.fileURL] ;
  [super saveDocument:inSender] ;
  [self setFileURL:url] ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//    W R I T E    T O    F I L E                                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (BOOL) writeToURL: (NSURL *) inAbsoluteURL
         ofType: (NSString *) inTypeName
         error: (NSError * macroAutoreleasingInARC *) outError {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s, URL %@", __PRETTY_FUNCTION__, inAbsoluteURL) ;
  #endif
//---
  return [mDocumentData performSaveToURL:inAbsoluteURL] ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  S A V I N G    H F S    T Y P E    A N D    C R E A T O R    C O D E S     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (NSDictionary *) fileAttributesToWriteToURL:(NSURL *) inDocumentURL
    ofType:(NSString *)documentTypeName
    forSaveOperation:(NSSaveOperationType)saveOperationType
    originalContentsURL: (NSURL *) inOriginalURL
    error: (NSError * macroAutoreleasingInARC *) outError {
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
      const NSUInteger count = [documentTypes count];
      
      for(NSUInteger i = 0; i < count; i++)
      {
          NSString *type = [[documentTypes objectAtIndex:i]
              objectForKey:@"CFBundleTypeName"];
          if(type && [type isEqualToString:documentTypeName])
          {
              NSArray *typeCodeStrings = [[documentTypes objectAtIndex:i]
                  objectForKey:@"CFBundleTypeOSTypes"];
              if(typeCodeStrings)
              {
                 NSString *firstTypeCodeString = [typeCodeStrings
                      objectAtIndex:0];
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

//---------------------------------------------------------------------------------------------------------------------*

#pragma mark Document Read

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//    R E A D    F R O M    F I L E                                                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (BOOL) readFromURL:(NSURL *) inAbsoluteURL
         ofType:(NSString *) inTypeName
         error:(NSError * macroAutoreleasingInARC *) outError {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s, URL '%@'", __PRETTY_FUNCTION__, inAbsoluteURL) ;
  #endif
  mBaseFilePreferenceKey = [inAbsoluteURL.path identifierRepresentation] ;
//---
  mDocumentData = [OC_GGS_DocumentData
    findOrAddDataForDocumentURL:inAbsoluteURL
    forCocoaDocument:self
 ] ;
//---
  return mDocumentData != nil ;
}

//---------------------------------------------------------------------------------------------------------------------*

#pragma mark Build

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//    C O M P I L E                                                                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (IBAction) stopBuild: (id) sender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  mBuildTaskHasBeenAborted = YES ;
  [mBuildTask terminate] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (IBAction) actionBuildSelected: (id) inUnusedSender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  if (nil == mBuildTask) {
    OC_GGS_TextDisplayDescriptor * tdd = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
    [self compileFileAtPath:tdd.sourceURL.path] ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (IBAction) actionBuildFirst: (id) inUnusedSender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  if (nil == mBuildTask) {
    OC_GGS_TextDisplayDescriptor * tdd = [mDisplayDescriptorArrayHigh objectAtIndex:0] ;
    [self compileFileAtPath:tdd.sourceURL.path] ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) compileFileAtPath: (NSString *) inFilePath {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [self saveAllDocuments:nil] ;
  mBufferedOutputData = [NSMutableData new] ;
  mWarningCountTextField.stringValue = @"0" ;
  mWarningCount = 0 ;
  mErrorCountTextField.stringValue = @"0" ;
  mErrorCount = 0 ;
  mBuildTaskHasBeenAborted = NO ;
  mIssueArray = [NSMutableArray new] ;
  [mRulerViewForBuildOutput setIssueArray:mIssueArray] ;
  OC_GGS_Scroller * scroller = (OC_GGS_Scroller *) mOutputScrollView.verticalScroller ;
  [scroller setIssueArray:mIssueArray] ;
//---
  if (nil == mOutputScrollView.superview) {
    [self closeSearchAndReplaceView:nil] ;
  }
//---
  [OC_GGS_DocumentData broadcastIssueArray:nil] ;
  mBuildTask = [[OC_GGS_BuildTask alloc]
    initWithDocument:self
    filePath:inFilePath
  ] ;
  self.mBuildTaskIsRunning = YES ;
//---
   NSDictionary * defaultDictionary = [NSDictionary dictionaryWithObjectsAndKeys:
    mBuildTextFont, NSFontAttributeName,
    [NSColor orangeColor], NSForegroundColorAttributeName,
    nil
  ] ;
  NSAttributedString * attributedString = [[NSAttributedString alloc]
    initWithString:[NSString stringWithFormat:@"Compiling %@…\n", inFilePath.lastPathComponent]
    attributes:defaultDictionary
  ] ;
  [mOutputTextView.textStorage setAttributedString:attributedString] ;
  [mOutputTextView setAutomaticLinkDetectionEnabled:YES] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) enterIssue: (NSString *) inIssueMessage
         isError: (BOOL) inIsError
         locationInOutputData: (NSRange) inRangeInOutputData {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
//  NSLog (@"inIssueMessage '%@'", inIssueMessage) ;
  NSArray * components = [inIssueMessage componentsSeparatedByString:@"\n"] ;
  NSString * issuePath = nil ;
  NSInteger issueLine = 0 ;
  NSInteger issueColumn = 0 ;
  if (components.count > 1) {
    NSArray * issueLocationArray = [[components objectAtIndex:0] componentsSeparatedByString:@":"] ;
    if (issueLocationArray.count > 3) {
      issuePath = [issueLocationArray objectAtIndex:0] ;
      // NSLog (@"issuePath '%@'", issuePath) ;
      issueLine = [[issueLocationArray objectAtIndex:1] integerValue] ;
      // NSLog (@"issueLine '%ld'", issueLine) ;
      issueColumn = [[issueLocationArray objectAtIndex:2] integerValue] ;
      // NSLog (@"issueColumn '%ld'", issueColumn) ;
    }
  }
  PMIssueDescriptor * issue = [[PMIssueDescriptor alloc]
    initWithMessage:inIssueMessage
    URL:(nil == issuePath) ? nil : [NSURL fileURLWithPath:issuePath]
    line:issueLine
    column:issueColumn
    isError:inIsError
    rangeInOutputData:inRangeInOutputData
    buildOutputRuler:mRulerViewForBuildOutput
  ] ;
  [mIssueArray addObject:issue] ;
  [mRulerViewForBuildOutput setIssueArray:mIssueArray] ;
//---
  OC_GGS_Scroller * scroller = (OC_GGS_Scroller *) mOutputScrollView.verticalScroller ;
  [scroller setIssueArray:mIssueArray] ;
//---
  if (inIsError) {
    mErrorCount ++ ;
    mErrorCountTextField.stringValue = [NSString stringWithFormat:@"%lu", mErrorCount] ;
  }else{
    mWarningCount ++ ;
    mWarningCountTextField.stringValue = [NSString stringWithFormat:@"%lu", mWarningCount] ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static const utf32 COCOA_WARNING_ID = TO_UNICODE (3) ;
static const utf32 COCOA_ERROR_ID   = TO_UNICODE (4) ;

//---------------------------------------------------------------------------------------------------------------------*

- (void) enterOutputData: (NSData *) inData {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s, inData %@", __PRETTY_FUNCTION__, inData) ;
  #endif
  NSString * message = [[NSString alloc] initWithData:inData encoding:NSUTF8StringEncoding] ;
  NSArray * messageArray = [message componentsSeparatedByString:[NSString stringWithFormat:@"%c", 0x1B]] ;
//--- Default attributes dictionary
  NSDictionary * defaultDictionary = [NSDictionary dictionaryWithObjectsAndKeys:
    mBuildTextFont, NSFontAttributeName,
    nil
  ] ;
  NSMutableAttributedString * outputAttributedString = [[NSMutableAttributedString alloc]
    initWithString:[messageArray objectAtIndex:0]
    attributes:defaultDictionary
  ] ;
//--- Send other components
  NSMutableDictionary * componentAttributeDictionary = defaultDictionary.mutableCopy ;
  for (NSUInteger i=1 ; i<messageArray.count ; i++) {
    NSString * component = [messageArray objectAtIndex:i] ;
    NSUInteger idx = 0 ;
    while ((idx < component.length) && ([component characterAtIndex:idx] == '[')) {
      idx ++ ;
      NSUInteger code = 0 ;
      while ((idx < component.length) && isdigit ([component characterAtIndex:idx])) {
        code *= 10 ;
        code += [component characterAtIndex:idx] - '0' ;
        idx ++ ;
      }
      if ((idx < component.length) && ([component characterAtIndex:idx] == 'm')) {
        idx ++ ;
      }
      switch (code) {
      case  0 : componentAttributeDictionary = defaultDictionary.mutableCopy ; break ;
      case 30 : [componentAttributeDictionary setValue:[NSColor blackColor]   forKey:NSForegroundColorAttributeName] ; break ;
      case 31 : [componentAttributeDictionary setValue:[NSColor redColor]     forKey:NSForegroundColorAttributeName] ; break ;
      case 32 : [componentAttributeDictionary setValue:[NSColor colorWithCalibratedRed:0.0 green:0.5 blue:0.0 alpha:1.0] forKey:NSForegroundColorAttributeName] ; break ;
      case 33 : [componentAttributeDictionary setValue:[NSColor orangeColor]  forKey:NSForegroundColorAttributeName] ; break ;
      case 34 : [componentAttributeDictionary setValue:[NSColor blueColor]    forKey:NSForegroundColorAttributeName] ; break ;
      case 35 : [componentAttributeDictionary setValue:[NSColor magentaColor] forKey:NSForegroundColorAttributeName] ; break ;
      case 36 : [componentAttributeDictionary setValue:[NSColor cyanColor]    forKey:NSForegroundColorAttributeName] ; break ;
      case 37 : [componentAttributeDictionary setValue:[NSColor whiteColor]   forKey:NSForegroundColorAttributeName] ; break ;
      case 40 : [componentAttributeDictionary setValue:[NSColor whiteColor]   forKey:NSBackgroundColorAttributeName] ; break ;
      case 41 : [componentAttributeDictionary setValue:[NSColor redColor]     forKey:NSBackgroundColorAttributeName] ; break ;
      case 42 : [componentAttributeDictionary setValue:[NSColor colorWithCalibratedRed:0.0 green:0.5 blue:0.0 alpha:1.0] forKey:NSBackgroundColorAttributeName] ; break ;
      case 43 : [componentAttributeDictionary setValue:[NSColor orangeColor]  forKey:NSBackgroundColorAttributeName] ; break ;
      case 44 : [componentAttributeDictionary setValue:[NSColor blueColor]    forKey:NSBackgroundColorAttributeName] ; break ;
      case 45 : [componentAttributeDictionary setValue:[NSColor magentaColor] forKey:NSBackgroundColorAttributeName] ; break ;
      case 46 : [componentAttributeDictionary setValue:[NSColor cyanColor]    forKey:NSBackgroundColorAttributeName] ; break ;
      case 47 : [componentAttributeDictionary setValue:[NSColor whiteColor]   forKey:NSBackgroundColorAttributeName] ; break ;
      default: break ;
      }
    }
    NSString * s = [component substringFromIndex:idx] ;
    if (s.length > 0) {
      const NSRange r = {mOutputTextView.textStorage.length + outputAttributedString.length, s.length - 1} ;
      if ([s characterAtIndex:0] == COCOA_WARNING_ID) {
        s = [s substringFromIndex:1] ;
        [self
          enterIssue:s
          isError:NO
          locationInOutputData:r
        ] ;
      }else if ([s characterAtIndex:0] == COCOA_ERROR_ID) {
        s = [s substringFromIndex:1] ;
        [self
          enterIssue:s
          isError:YES
          locationInOutputData:r
        ] ;
      }
      NSAttributedString * as = [[NSAttributedString alloc]
        initWithString:s
        attributes:componentAttributeDictionary
      ] ;
      [outputAttributedString appendAttributedString:as] ;
    }
  }
  [mOutputTextView.textStorage appendAttributedString:outputAttributedString] ;
  [mOutputTextView scrollRangeToVisible:NSMakeRange (mOutputTextView.textStorage.length, 0)] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) buildCompleted {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  self.mBuildTaskIsRunning = NO ;
//---
  [self enterOutputData:mBufferedOutputData] ;
  mBufferedOutputData = nil ;
//---
  [OC_GGS_DocumentData broadcastIssueArray:mIssueArray] ;
//---
  NSDictionary * defaultDictionary = [NSDictionary dictionaryWithObjectsAndKeys:
    mBuildTextFont, NSFontAttributeName,
    [NSColor orangeColor], NSForegroundColorAttributeName,
    nil
  ] ;
  NSAttributedString * attributedString = [[NSAttributedString alloc]
    initWithString:mBuildTaskHasBeenAborted ? @"Aborted.\n" : @"Done.\n"
    attributes:defaultDictionary
  ] ;
  [mOutputTextView.textStorage appendAttributedString:attributedString] ;
//---
  [[NSRunLoop mainRunLoop]
    performSelector:@selector (pmReleaseBuildTask)
    target:self
    argument:nil
    order:0
    modes:[NSArray arrayWithObject:NSDefaultRunLoopMode]
  ] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) pmReleaseBuildTask {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  mBuildTask = nil ;
  [NSApp requestUserAttention:NSInformationalRequest] ;
  if ((! mHasSpoken) && (mErrorCount >= 40)) {
    mHasSpoken = YES ;
    NSString * thePhrase = [NSString stringWithFormat:@"Oh! %@ made %lu errors", NSFullUserName (), mErrorCount] ;
    NSSpeechSynthesizer * speech = [[NSSpeechSynthesizer alloc] initWithVoice:nil] ;
    [speech startSpeakingString:thePhrase] ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) appendBuildOutputData: (NSData *) inData {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [mBufferedOutputData appendData:inData] ;
//--- Split input data, by detecting 2 consecutives COCOA_MESSAGE_ID characters
  BOOL ok = YES ;
  const uint16 sentinel = 0x0101 ;
  while (ok) {
    ok = NO ;
  //--- Look for sentinel
    NSUInteger idx = 0 ;
    while ((! ok) && ((idx + 1) < mBufferedOutputData.length)) {
      const NSRange range = {idx, 2} ;
      uint16 c ;
      [mBufferedOutputData getBytes:& c range:range] ;
      ok = c == sentinel ;
      if (! ok) {
        idx ++ ;
      }
    }
  //--- If found, extract data
    if (ok) {
      NSData * data = [mBufferedOutputData subdataWithRange:NSMakeRange (0, idx)] ;
      NSData * remainingData = [mBufferedOutputData subdataWithRange:NSMakeRange (idx + 2, mBufferedOutputData.length - (idx + 2))] ;
      [mBufferedOutputData setData:remainingData] ;
      [self enterOutputData:data] ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) triggerDocumentEditedStatusUpdate {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  BOOL isEdited = NO ;
  NSArray * sourceDisplayArray = mSourceDisplayArrayControllerHigh.arrangedObjects ;
  for (NSUInteger i=0 ; (i<sourceDisplayArray.count) && ! isEdited ; i++) {
    OC_GGS_TextDisplayDescriptor * textDisplay = [sourceDisplayArray objectAtIndex:i] ;
    OC_GGS_TextSyntaxColoring * textSyntaxColoring = textDisplay.documentData.textSyntaxColoring ;
    isEdited = textSyntaxColoring.isDirty ;
  }
  [self updateChangeCount:isEdited ? NSChangeDone : NSChangeCleared] ;
}

//---------------------------------------------------------------------------------------------------------------------*

#pragma mark Click on issue table view

//---------------------------------------------------------------------------------------------------------------------*

- (void) clickOnSourceTableViewHigh: (id) inSender {
  if (mDisplayDescriptorTableViewHigh.clickedColumn == 1) {
    const NSInteger row = mDisplayDescriptorTableViewHigh.clickedRow ;
    if (row >= 0) {
      OC_GGS_TextDisplayDescriptor * desc = [mSourceDisplayArrayControllerHigh.arrangedObjects objectAtIndex: (NSUInteger) row] ;
      [self removeSelectedTabAction:desc] ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (IBAction) openSourceInNewWindowAction: (id) inSender {
  NSError * error = nil ;
  OC_GGS_Document * newDocument = [[NSDocumentController sharedDocumentController]
    openUntitledDocumentAndDisplay:YES
    error:& error
  ] ;
  if (nil == error) {
    OC_GGS_TextDisplayDescriptor * d = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
    [newDocument findOrAddNewTabForFile:d.sourceURL.path] ;
  }else{
    [self.windowForSheet presentError:error] ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (IBAction) moveSourceInNewWindowAction: (id) inSender {
  NSError * error = nil ;
  OC_GGS_Document * newDocument = [[NSDocumentController sharedDocumentController]
    openUntitledDocumentAndDisplay:YES
    error:& error
  ] ;
  if (nil == error) {
    OC_GGS_TextDisplayDescriptor * d = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
    [newDocument findOrAddNewTabForFile:d.sourceURL.path] ;
    [self removeSelectedTabAction:d] ;
  }else{
    [self.windowForSheet presentError:error] ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (IBAction) duplicateSourceAction: (id) inSender {
  OC_GGS_TextDisplayDescriptor * d = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  OC_GGS_TextDisplayDescriptor * tdd = [[OC_GGS_TextDisplayDescriptor alloc]
    initWithDocumentData:d.documentData
    displayDocument:self
  ] ;
  [mSourceDisplayArrayControllerHigh addObject:tdd] ;
  [self registerConfigurationInPreferences] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (IBAction) revealInFinderAction: (id) inSender {
  OC_GGS_TextDisplayDescriptor * d = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  NSWorkspace * ws = [NSWorkspace sharedWorkspace] ;
  const BOOL ok = [ws selectFile:d.sourceURL.path inFileViewerRootedAtPath:@""] ;
  if (! ok) {
    NSBeep () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (IBAction) closeAction: (id) inSender {
  OC_GGS_TextDisplayDescriptor * d = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  [self removeSelectedTabAction:d] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (IBAction) closeOthersAction: (id) inSender {
  OC_GGS_TextDisplayDescriptor * tdd = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  for (OC_GGS_TextDisplayDescriptor * d in [mSourceDisplayArrayControllerHigh.arrangedObjects copy]) {
    if (tdd != d) {
      [self removeSelectedTabAction:d] ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (OC_GGS_DocumentData *) findOrAddDocumentWithPath: (NSString *) inPath {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSString * requestedAbsolutePath = inPath.isAbsolutePath
    ? inPath.copy
    : [self.fileURL.path.stringByDeletingLastPathComponent stringByAppendingPathComponent:inPath]
  ;
  NSURL * url = [NSURL fileURLWithPath:requestedAbsolutePath.stringByStandardizingPath] ;
  return [OC_GGS_DocumentData
    findOrAddDataForDocumentURL:url
    forCocoaDocument:nil
  ] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (OC_GGS_TextDisplayDescriptor *) findOrAddNewTabForFile: (NSString *) inDocumentPath {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s, inDocumentPath: %@", __PRETTY_FUNCTION__, inDocumentPath) ;
  #endif
  OC_GGS_DocumentData * documentData = [self findOrAddDocumentWithPath:inDocumentPath] ;
  OC_GGS_TextDisplayDescriptor * foundSourceText = nil ;
  if (nil != documentData) { // Find a text display descriptor
    NSArray * sourceDisplayDescriptorArray = mSourceDisplayArrayControllerHigh.arrangedObjects ;
    for (NSUInteger i=0 ; (i<sourceDisplayDescriptorArray.count) && (nil == foundSourceText) ; i++) {
      OC_GGS_TextDisplayDescriptor * std = [sourceDisplayDescriptorArray objectAtIndex:i] ;
      if (std.documentData == documentData) {
        foundSourceText = std ;
      }
    }
    if (nil == foundSourceText) { // Create a tab
      foundSourceText = [[OC_GGS_TextDisplayDescriptor alloc]
        initWithDocumentData:documentData
        displayDocument:self
      ] ;
      [mSourceDisplayArrayControllerHigh addObject:foundSourceText] ;
    //--- Update users preferences
      [self registerConfigurationInPreferences] ;
    }
    [mSourceDisplayArrayControllerHigh setSelectedObjects:[NSArray arrayWithObject:foundSourceText]] ;
  }
  return foundSourceText ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) appendTabForFile: (NSString *) inDocumentPath {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s, inDocumentPath: %@", __PRETTY_FUNCTION__, inDocumentPath) ;
  #endif
  OC_GGS_DocumentData * documentData = [self findOrAddDocumentWithPath:inDocumentPath] ;
  if (nil != documentData) { // Find a text display descriptor
    OC_GGS_TextDisplayDescriptor * tdd = [[OC_GGS_TextDisplayDescriptor alloc]
      initWithDocumentData:documentData
      displayDocument:self
    ] ;
    [mSourceDisplayArrayControllerHigh addObject:tdd] ;
    [self registerConfigurationInPreferences] ;
    [mSourceDisplayArrayControllerHigh setSelectedObjects:[NSArray arrayWithObject:tdd]] ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) removeSelectedTabAction: (OC_GGS_TextDisplayDescriptor *) inTextDisplayDescriptor {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
//---
  const BOOL lastSourceWillBeRemoved = [mSourceDisplayArrayControllerHigh.arrangedObjects count] == 1 ;
  [mSourceDisplayArrayControllerHigh removeObject:inTextDisplayDescriptor] ;
  [inTextDisplayDescriptor detachTextDisplayDescriptor] ;
  [OC_GGS_DocumentData cocoaDocumentWillClose:nil] ;
  if (lastSourceWillBeRemoved) {
    [self.windowForSheet performClose:nil] ;
  }else{
    [self registerConfigurationInPreferences] ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

#pragma mark observeValueForKeyPath

//---------------------------------------------------------------------------------------------------------------------*

- (void) observeValueForKeyPath:(NSString *) inKeyPath
         ofObject: (id) inObject
         change:(NSDictionary *) inChange
         context:(void *) inContext {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s, keyPath: %@", __PRETTY_FUNCTION__, inKeyPath) ;
  #endif
  NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
  if ((inObject == ud) && [inKeyPath isEqualToString:[NSString stringWithFormat:@"searchMatrixFor:%@", mBaseFilePreferenceKey]]) {
    [self updateDirectoryListVisibility] ;
  }else if ((inObject == ud) && [inKeyPath isEqualToString:GGS_build_text_font]) {
    NSData * data = [ud objectForKey:GGS_build_text_font] ;
    if (nil != data) {
      mBuildTextFont = [NSUnarchiver unarchiveObjectWithData:data] ;
    }
    if (nil == mBuildTextFont) {
      mBuildTextFont = [NSFont fontWithName:@"Courier" size:13.0] ;
    }
    [mOutputTextView setFont:mBuildTextFont] ;
  }else if ((inObject == mFoundEntryTreeController) && [inKeyPath isEqualToString:@"selectionIndexPath"]) {
    [self changeSelectionInSearchResultView] ;
  }else if ((inObject == mSourceDisplayArrayControllerHigh) && [inKeyPath isEqualToString:@"selectionIndex"]) {
    for (NSView * subview in mSourceHostView.subviews.copy) {
      [subview removeFromSuperview] ;
    }
    NSArray * arrangedObjects = mSourceDisplayArrayControllerHigh.arrangedObjects ;
    const NSUInteger selectedTab = mSourceDisplayArrayControllerHigh.selectionIndex ;
    // NSLog (@"WRITE selectedTab %lu", selectedTab) ;
    if (selectedTab != NSNotFound) {
  //    NSString * key = [NSString stringWithFormat:@"SELECTED-TAB:%@", [[arrangedObjects objectAtIndex:0] sourceURL].path] ;
      NSString * key = [NSString stringWithFormat:@"SELECTED-TAB:%@", mBaseFilePreferenceKey] ;
      [ud setInteger:(NSInteger) selectedTab forKey:key] ;
      OC_GGS_TextDisplayDescriptor * object = [arrangedObjects objectAtIndex:selectedTab] ;
      [self setFileURL:object.sourceURL] ;
      object.enclosingView.frame = mSourceHostView.bounds ;
      [mSourceHostView addSubview:object.enclosingView] ;
      [mSourceHostView.window makeFirstResponder:object.textView] ;
    }
  }else if ([inKeyPath isEqualToString:@"selection.textSelectionStart"]) {
    const NSUInteger sel = mSourceDisplayArrayControllerHigh.selectionIndex ;
    if (sel != NSNotFound) {
      NSArray * arrangedObjects = mSourceDisplayArrayControllerHigh.arrangedObjects ;
      OC_GGS_TextDisplayDescriptor * object = [arrangedObjects objectAtIndex:sel] ;
      [object selectEntryPopUp] ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

#pragma mark Open Quickly

//---------------------------------------------------------------------------------------------------------------------*

- (NSString *) fileNameFromSelection {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSArray * sourceDisplayDescriptorArray = mSourceDisplayArrayControllerHigh.arrangedObjects ;
  const NSUInteger sel = mSourceDisplayArrayControllerHigh.selectionIndex ;
  OC_GGS_TextDisplayDescriptor * currentSourceText = [sourceDisplayDescriptorArray objectAtIndex:sel] ;
  OC_GGS_TextSyntaxColoring * textSyntaxColoring = currentSourceText.documentData.textSyntaxColoring ;
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
//---
  NSString * relativePath = [sourceString substringWithRange:selection] ;
  return [self.fileURL.path.stringByDeletingLastPathComponent stringByAppendingPathComponent:relativePath] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) actionOpenFromSelectionInNewWindow: (id) sender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSString * newDocumentPath = self.fileNameFromSelection ;
  //NSLog (@"%@", newDocumentPath) ;
  NSError * error = nil ;
  NSDocument * doc = [[NSDocumentController sharedDocumentController]
    openDocumentWithContentsOfURL:[NSURL fileURLWithPath:newDocumentPath]
    display:YES
    error:& error
  ] ;
  if (nil == doc) {
    [self.windowForSheet presentError:error] ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) actionOpenFromSelection: (id) sender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [self findOrAddNewTabForFile:self.fileNameFromSelection] ;
}

//---------------------------------------------------------------------------------------------------------------------*

#pragma mark Search and Replace

//---------------------------------------------------------------------------------------------------------------------*

//https://github.com/malcommac/NSSplitView-Animatable

//---------------------------------------------------------------------------------------------------------------------*

- (void) updateDirectoryListVisibility {
  const NSInteger sel = [[NSUserDefaults standardUserDefaults] integerForKey:[NSString stringWithFormat:@"searchMatrixFor:%@", mBaseFilePreferenceKey]] ;
  [mExcludedDirectoryView setHidden:sel != 1] ;
  [mExplicitSearchDirectoryView setHidden:sel != 2] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (double) positionOfDividerAtIndex:(NSInteger)dividerIndex {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  // It looks like NSSplitView relies on its subviews being ordered left->right or top->bottom so we can too.
  // It also raises w/ array bounds exception if you use its API with dividerIndex > count of subviews.
  while ((dividerIndex >= 0) && [mSecondSplitView isSubviewCollapsed:[mSecondSplitView.subviews objectAtIndex: (NSUInteger) dividerIndex]]) {
    dividerIndex-- ;
    if (dividerIndex < 0) {
      return 0.0 ;
    }
  }
  const NSRect priorViewFrame = [[mSecondSplitView.subviews objectAtIndex:(NSUInteger) dividerIndex] frame];
  return mSecondSplitView.isVertical ? NSMaxX (priorViewFrame) : NSMaxY (priorViewFrame);
}

//---------------------------------------------------------------------------------------------------------------------*
// NSPlitView delegate method

- (CGFloat) splitView:(NSSplitView *) inSplitView
            constrainMinCoordinate: (CGFloat) inProposedMin
            ofSubviewAt: (NSInteger) inDividerIndex {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  CGFloat result = inProposedMin ;
  const CGFloat minFirstSplitViewValue = 250.0 ;
  const CGFloat minSecondSplitViewValue = 50.0 ;
  if ((inDividerIndex == 0) && (inSplitView == mFirstSplitView) && (inProposedMin < minFirstSplitViewValue)) {
    result = minFirstSplitViewValue ;
  }else if ((inDividerIndex == 0) && (inSplitView == mSecondSplitView) && (inProposedMin < minSecondSplitViewValue)) {
    result = minSecondSplitViewValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
// NSPlitView delegate method

- (CGFloat) splitView:(NSSplitView *) inSplitView
            constrainMaxCoordinate: (CGFloat) inProposedMax
            ofSubviewAt: (NSInteger) inDividerIndex {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  CGFloat result = inProposedMax ;
  const CGFloat minSecondSplitViewValue = 250.0 ;
  CGFloat max = inSplitView.bounds.size.height - minSecondSplitViewValue ;
  if ((inDividerIndex == 0) && (inSplitView == mSecondSplitView) && (inProposedMax > max)) {
    result = max  ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

// http://stackoverflow.com/questions/17441877/nssplitview-fixed-splitter-on-window-resize

- (void) splitView:(NSSplitView *) inSplitView
         resizeSubviewsWithOldSize: (NSSize) inOldSize {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  const CGFloat dividerThickness = inSplitView.dividerThickness ;
  const NSRect newFrame = inSplitView.frame ;
  if (inSplitView == mFirstSplitView) {
    const NSRect leftRect  = [[inSplitView.subviews objectAtIndex:0] frame] ;
    const CGFloat minFirstSplitViewValue = 250.0 ;
    NSRect newLeftRect = {{0.0, 0.0}, {floor (leftRect.size.width * newFrame.size.width / inOldSize.width), newFrame.size.height}} ;
    if (newLeftRect.size.width < minFirstSplitViewValue) {
      newLeftRect.size.width = minFirstSplitViewValue ;
    }
    const NSRect newRightRect = {
      {newLeftRect.origin.x + newLeftRect.size.width + dividerThickness, 0.0},
      {newFrame.size.width - newLeftRect.size.width - dividerThickness, newFrame.size.height}
    } ;
    [[inSplitView.subviews objectAtIndex:0] setFrame:newLeftRect];
    [[inSplitView.subviews objectAtIndex:1] setFrame:newRightRect];
  }else if (inSplitView == mSecondSplitView) {
    const NSRect bottomRect  = [[inSplitView.subviews objectAtIndex:1] frame] ;
  /*  const NSRect topRect  = [[inSplitView.subviews objectAtIndex:0] frame] ;
    NSLog (@"0:%p, 1:%p, mOutputScrollView:%p, mSearchView:%p", [inSplitView.subviews objectAtIndex:0], [inSplitView.subviews objectAtIndex:1], mOutputScrollView, mSearchView) ;
    NSLog (@"inSplitView.isFlipped %d", inSplitView.isFlipped) ;
    NSLog (@"topRect {{%g, %g}, {%g, %g}}", topRect.origin.x, topRect.origin.y, topRect.size.width, topRect.size.height) ;
    NSLog (@"bottomRect {{%g, %g}, {%g, %g}}", bottomRect.origin.x, bottomRect.origin.y, bottomRect.size.width, bottomRect.size.height) ;*/
    NSRect newBottomRect = {
      {0.0, 0.0 /* temporary */},
      {newFrame.size.width, floor (bottomRect.size.height * newFrame.size.height / inOldSize.height)}
    } ;
    const CGFloat minSecondSplitViewValue = 250.0 ;
    if (newBottomRect.size.height > (newFrame.size.height - dividerThickness)) {
      newBottomRect.size.height = newFrame.size.height - dividerThickness ;
    }else if (newBottomRect.size.height < minSecondSplitViewValue) {
      newBottomRect.size.height = minSecondSplitViewValue ;
    }
    newBottomRect.origin.y = newFrame.size.height - newBottomRect.size.height ;
    const NSRect newTopRect = {
      {0.0, 0.0},
      {newFrame.size.width, newFrame.size.height - newBottomRect.size.height - dividerThickness}
    } ;
    [[inSplitView.subviews objectAtIndex:0] setFrame:newTopRect];
    [[inSplitView.subviews objectAtIndex:1] setFrame:newBottomRect];
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (IBAction) showSearchAndReplaceView: (id) inSender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  const double position = [self positionOfDividerAtIndex:0] ;
  [mOutputScrollView removeFromSuperview] ;
  [mSecondSplitView addSubview:mSearchView] ;
  [mSecondSplitView adjustSubviews] ;
  [mSecondSplitView setPosition:position ofDividerAtIndex:0] ;
  [mGlobalSearchTextField.window makeFirstResponder:mGlobalSearchTextField] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (IBAction) closeSearchAndReplaceView: (id) inSender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  const double position = [self positionOfDividerAtIndex:0] ;
  [mSearchView removeFromSuperview] ;
  [mSecondSplitView addSubview:mOutputScrollView] ;
  [mSecondSplitView adjustSubviews] ;
  [mSecondSplitView setPosition:position ofDividerAtIndex:0] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) updateOccurrenceFoundTextField {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSString * s = @"No Occurrence found" ;
  if (mResultCount == 1) {
    s = @"1 Occurrence found" ;
  }else if (mResultCount > 1) {
    s = [NSString stringWithFormat:@"%lu Occurrences found", mResultCount] ;
  }
  mOccurenceFoundCountTextField.stringValue = s ;
  [mOccurenceFoundCountTextField display] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (IBAction) globalFindAction: (id) inSender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [OC_GGS_DocumentData saveAllDocuments] ;
  [self willChangeValueForKey:@"mResultArray"] ;
  mResultArray = [NSMutableArray new] ;
  [self didChangeValueForKey:@"mResultArray"] ;
  mResultCount = 0 ;
  [self updateOccurrenceFoundTextField] ;
  switch (mSearchMatrix.selectedRow) {
  case 0 : [self findInOpenedFiles] ; break ;
  case 1 : [self findInOpenedFileDirectories] ; break ;
  case 2 : [self findInExplicitDirectories] ; break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) findInExplicitDirectories {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
//---------------------------------------------------------- Get all dir set
  NSMutableSet * directoryPathSet = [NSMutableSet setWithArray:mExplicitSearchDirectoryArrayController.arrangedObjects] ;
  // NSLog (@"directoryPathSet %@", directoryPathSet) ;
//---------------------------------------- Retain only base directories, eliminate sub directories
  NSMutableArray * directoryPathArray = [NSMutableArray new] ;
  for (NSString * directoryPath in directoryPathSet) {
    if (! [directoryPathArray containsObject:directoryPath]) {
      BOOL insert = YES ;
      for (NSUInteger i=0 ; (i<directoryPathArray.count) && insert ; i++) {
        NSString * dir = [directoryPathArray objectAtIndex:i] ;
        if ([dir hasPrefix:directoryPath]) {
          [directoryPathArray replaceObjectAtIndex:i withObject:directoryPath] ;
          insert = NO ;
        }else if ([directoryPath hasPrefix:dir]) {
          insert = NO ;
        }
      }
      if (insert) {
        [directoryPathArray addObject:directoryPath] ;
      }
    }
  }
  // NSLog (@"directoryPathArray %@", directoryPathArray) ;
//------------------------- Explore dirs
  for (NSString * directoryPath in directoryPathArray) {
    [self
      recursiveSearchInDirectory:directoryPath
      recursive:YES
      extensionList:self.allTypesOfCurrentApplication
    ] ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) findInOpenedFileDirectories {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
//---------------------------------------------------------- Get all dir set
  NSSet * directoryToExcludeSet = [NSSet setWithArray:mExcludedDirectoryArrayController.content] ;
  // NSLog (@"directoryToExcludeSet %@", directoryToExcludeSet) ;
  NSMutableSet * directoryPathSet = [NSMutableSet new] ;
  for (OC_GGS_TextDisplayDescriptor * d in mSourceDisplayArrayControllerHigh.arrangedObjects) {
    NSString * dir = d.sourceURL.path.stringByDeletingLastPathComponent ;
    // NSLog (@"dir %@", dir) ;
    if (![directoryToExcludeSet containsObject:dir]) {
      [directoryPathSet addObject:dir] ;
    }
  }
  // NSLog (@"directoryPathSet %@", directoryPathSet) ;
//---------------------------------------- Retain only base directories, eliminate sub directories
  NSMutableArray * directoryPathArray = [NSMutableArray new] ;
  for (NSString * directoryPath in directoryPathSet) {
    if (! [directoryPathArray containsObject:directoryPath]) {
      BOOL insert = YES ;
      for (NSUInteger i=0 ; (i<directoryPathArray.count) && insert ; i++) {
        NSString * dir = [directoryPathArray objectAtIndex:i] ;
        if ([dir hasPrefix:directoryPath]) {
          [directoryPathArray replaceObjectAtIndex:i withObject:directoryPath] ;
          insert = NO ;
        }else if ([directoryPath hasPrefix:dir]) {
          insert = NO ;
        }
      }
      if (insert) {
        [directoryPathArray addObject:directoryPath] ;
      }
    }
  }
  // NSLog (@"directoryPathArray %@", directoryPathArray) ;
//------------------------- Explore dirs
  for (NSString * directoryPath in directoryPathArray) {
    [self
      recursiveSearchInDirectory:directoryPath
      recursive:YES
      extensionList:self.allTypesOfCurrentApplication
    ] ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) recursiveSearchInDirectory: (NSString *) inDirectoryFullPath
         recursive: (BOOL) inRecursive
         extensionList: (NSArray *) inExtensionList {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSFileManager * fm = [NSFileManager new] ;
  NSArray * contents = [fm contentsOfDirectoryAtPath:inDirectoryFullPath error:nil] ;
  if (nil == contents) {
  
  }else{
    for (NSString * subPath in contents) {
      if ('.' != [subPath characterAtIndex:0]) {
        NSString * fullPath = [NSString stringWithFormat:@"%@/%@", inDirectoryFullPath, subPath] ;
        BOOL isDirectory ;
        if ([fm fileExistsAtPath:fullPath isDirectory: & isDirectory]) {
          if (isDirectory && inRecursive) {
            [self recursiveSearchInDirectory:fullPath recursive:YES extensionList:inExtensionList] ;
          }else if ((! isDirectory) && [inExtensionList containsObject:[fullPath pathExtension]]) {
            [self findInFile:fullPath] ;
          }
        }
      }
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSArray *) allTypesOfCurrentApplication {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSMutableArray * allTypes = [NSMutableArray new] ;
  NSDictionary * infoDictionary = [[NSBundle mainBundle] infoDictionary] ;
  NSArray * allDocumentTypes = [infoDictionary objectForKey:@"CFBundleDocumentTypes"] ;
  for (NSDictionary * type in allDocumentTypes) {
    NSArray * a = [type objectForKey:@"CFBundleTypeExtensions"] ;
    [allTypes addObjectsFromArray:a] ;  
  }
  return allTypes ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSUInteger) searchOptions {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSUInteger searchOptions = 0 ;
  if (! mCaseSensitiveSearchCheckbox.state) {
    searchOptions |= NSCaseInsensitiveSearch ;
  }
  return searchOptions ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) findInFile: (NSString *) inFilePath {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSMutableArray * foundEntries = [NSMutableArray new] ;
  NSString * sourceString = [NSString stringWithContentsOfFile:inFilePath encoding:NSUTF8StringEncoding error:nil] ;
  NSRange searchRange = {0, sourceString.length} ;
  while (searchRange.length > 0) {
    const NSRange r = [sourceString rangeOfString:mGlobalSearchTextField.stringValue options:self.searchOptions range:searchRange] ;
    if (r.length > 0) { // Found
      [self
        addFindResult:inFilePath
        sourceString:sourceString
        range:r
        toArray:foundEntries
      ] ;
      searchRange.location = r.location + r.length ;
      searchRange.length = sourceString.length - searchRange.location ;
    }else{
      searchRange.length = 0 ; // For exiting
    }
  }
  [self enterResult:foundEntries forFilePath:inFilePath] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) findInOpenedFiles {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSMutableSet * visitedFilePathes = [NSMutableSet new] ;
  for (OC_GGS_TextDisplayDescriptor * d in mSourceDisplayArrayControllerHigh.arrangedObjects) {
    NSString * filePath = d.sourceURL.path ;
    if (! [visitedFilePathes containsObject:filePath]) {
      [visitedFilePathes addObject:filePath] ;
      NSMutableArray * foundEntries = [NSMutableArray new] ;
      NSString * sourceString = d.documentData.sourceString ;
      NSRange searchRange = {0, sourceString.length} ;
      while (searchRange.length > 0) {
        const NSRange r = [sourceString rangeOfString:mGlobalSearchTextField.stringValue options:self.searchOptions range:searchRange] ;
        if (r.length > 0) { // Found
          [self
            addFindResult:filePath
            sourceString:sourceString
            range:r
            toArray:foundEntries
          ] ;
          searchRange.location = r.location + r.length ;
          searchRange.length = sourceString.length - searchRange.location ;
        }else{
          searchRange.length = 0 ; // For exiting
        }
      }
      [self enterResult:foundEntries forFilePath:filePath] ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) addFindResult:(NSString *) inSourceFilePath
         sourceString: (NSString *) inSourceString
         range: (NSRange) inFoundRange
         toArray: (NSMutableArray *) ioFoundEntries {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  const NSRange lineRange = [inSourceString lineRangeForRange:inFoundRange] ;
  PMSearchResultDescriptor * d = [[PMSearchResultDescriptor alloc]
    initWithLine:[inSourceString substringWithRange:lineRange]
    range:inFoundRange
    sourceFilePath:inSourceFilePath
  ] ;
  [ioFoundEntries addObject:d] ;
//---
  mResultCount ++ ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) enterResult: (NSMutableArray *) inFoundEntries
         forFilePath:(NSString *) inSourceFilePath {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s, inSourceFilePath %@", __PRETTY_FUNCTION__, inSourceFilePath) ;
  #endif
  if (inFoundEntries.count > 0) {
    [self willChangeValueForKey:@"mResultArray"] ;
    PMSearchResultDescriptor * d = [[PMSearchResultDescriptor alloc]
      initWithEntries:inFoundEntries
      sourceFilePath:inSourceFilePath
    ] ;
    [mResultArray addObject:d] ;
    [self didChangeValueForKey:@"mResultArray"] ;
    [mResultOutlineView display] ;
    [self updateOccurrenceFoundTextField] ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) changeSelectionInSearchResultView {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSArray * selectedObjects = mFoundEntryTreeController.selectedObjects ;
  if (selectedObjects.count > 1) {
    NSBeep () ;
  }else if (selectedObjects.count == 1) {
    PMSearchResultDescriptor * d = [selectedObjects objectAtIndex:0] ;
    NSString * filePath = d.filePath ;
    if (nil != filePath) {
      OC_GGS_TextDisplayDescriptor * tdd = [self findOrAddNewTabForFile:filePath] ;
      const NSRange range = d.range ;
      if ((range.location + range.length) > 0) {
        [tdd setSelectionRangeAndMakeItVisible:range] ;
        [mResultOutlineView.window makeFirstResponder:mResultOutlineView] ;
      }else if (nil == d.children) {
        NSBeep () ;
      }
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) updateSearchResultForFile: (NSString *) inFilePath
         previousRange: (NSRange) inPreviousRange
         changeInLength: (NSInteger) inChangeInLength {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  for (PMSearchResultDescriptor * d in mResultArray) {
    [d
      updateSearchResultForFile:inFilePath
      previousRange:inPreviousRange
      changeInLength:inChangeInLength
    ] ;
  }
} 

//---------------------------------------------------------------------------------------------------------------------*

- (IBAction) globalReplaceAllAction: (id) inSender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSString * replaceString = mGlobalReplaceTextField.stringValue ;
  for (PMSearchResultDescriptor * d in mResultArray) {
    NSString * filePath = d.filePath ;
    // NSLog (@"filePath %@", filePath) ;
    NSArray * foundEntries = d.children ;
    OC_GGS_DocumentData * documentData = [OC_GGS_DocumentData findDocumentDataForFilePath:filePath] ;
    if (nil == documentData) {
      NSMutableString * contents = [[NSString stringWithContentsOfFile:filePath encoding:NSUTF8StringEncoding error:nil] mutableCopy] ;
      if (nil != contents) {
        for (PMSearchResultDescriptor * entry in foundEntries.reverseObjectEnumerator) {
          const NSRange r = entry.range ;
          // NSLog (@"r [%lu, %lu]", r.location, r.length) ;
          [contents replaceCharactersInRange:r withString:replaceString] ;
        }
      }
      [contents writeToFile:filePath atomically:YES encoding:NSUTF8StringEncoding error:nil] ;
    }else{
      for (PMSearchResultDescriptor * entry in foundEntries.reverseObjectEnumerator) {
        const NSRange r = entry.range ;
        // NSLog (@"r [%lu, %lu]", r.location, r.length) ;
        [documentData replaceCharactersInRange:r withString:replaceString] ;
      }
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) addExplicitSearchDirectoryAction: (id) inSender {
  NSOpenPanel * panel = [NSOpenPanel openPanel] ;
  panel.title = @"Select a search directory:" ;
  panel.canChooseFiles = NO ;
  panel.canChooseDirectories = YES ;
  panel.canCreateDirectories = YES ;
  panel.allowsMultipleSelection = YES ;
  [panel
    beginSheetForDirectory:nil
    file:nil
    types:[NSArray array]
    modalForWindow:self.windowForSheet
    modalDelegate:self
    didEndSelector:@selector (addSearchDirectoryPanelDidEnd:returnCode:contextInfo:)
    contextInfo:nil
  ] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) addSearchDirectoryPanelDidEnd: (NSOpenPanel *) inPanel
         returnCode: (int) inReturnCode
         contextInfo: (void  *) inContextInfo {
  if (NSOKButton == inReturnCode) {
    for (NSURL * url in inPanel.URLs) {
      if (url.isFileURL) {
        [mExplicitSearchDirectoryArrayController addObject:url.path] ;
      }
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) addExcludedDirectoryAction: (id) inSender {
  NSOpenPanel * panel = [NSOpenPanel openPanel] ;
  panel.title = @"Select the directory to Exclude from search:" ;
  panel.canChooseFiles = NO ;
  panel.canChooseDirectories = YES ;
  panel.canCreateDirectories = YES ;
  panel.allowsMultipleSelection = YES ;
  [panel
    beginSheetForDirectory:nil
    file:nil
    types:[NSArray array]
    modalForWindow:self.windowForSheet
    modalDelegate:self
    didEndSelector:@selector (addExcludedDirectoryPanelDidEnd:returnCode:contextInfo:)
    contextInfo:nil
  ] ;
}


//---------------------------------------------------------------------------------------------------------------------*

- (void) addExcludedDirectoryPanelDidEnd: (NSOpenPanel *) inPanel
         returnCode: (int) inReturnCode
         contextInfo: (void  *) inContextInfo {
  if (NSOKButton == inReturnCode) {
    for (NSURL * url in inPanel.URLs) {
      if (url.isFileURL) {
        [mExcludedDirectoryArrayController addObject:url.path] ;
      }
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//   DRAG AND DROP                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#pragma mark Drag and Drop in source table View

// http://stackoverflow.com/questions/10308008/nstableview-and-drag-and-drop-from-finder

//#define DEBUG_MESSAGES

//---------------------------------------------------------------------------------------------------------------------*

- (BOOL) tableView: (NSTableView *) inTableView
         writeRowsWithIndexes: (NSIndexSet *) inRowIndexes
         toPasteboard: (NSPasteboard*) inPasteboard {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s, inRowIndexes %@", __PRETTY_FUNCTION__, inRowIndexes) ;
  #endif
  [inPasteboard declareTypes:[NSArray arrayWithObject:(NSString *) kPasteboardTypeFileURLPromise] owner:self] ;
  OC_GGS_TextDisplayDescriptor * tdd = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  [inPasteboard clearContents] ; // clear pasteboard to take ownership
  [inPasteboard writeObjects:[NSArray arrayWithObject:tdd.sourceURL]] ;
  #ifdef DEBUG_MESSAGES
    NSLog (@"tdd.sourceURL %@", tdd.sourceURL) ;
  #endif
  return YES;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSDragOperation) tableView:(NSTableView*)tv
                    validateDrop:(id <NSDraggingInfo>)info
                    proposedRow:(NSInteger)row
                    proposedDropOperation:(NSTableViewDropOperation)op {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  return NSDragOperationEvery ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (BOOL) tableView: (NSTableView *) inTableView
         acceptDrop: (id <NSDraggingInfo>) inDraggingInfo
         row: (NSInteger) inRow
         dropOperation:(NSTableViewDropOperation)operation {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSArray * classArray = [NSArray arrayWithObject:[NSURL class]]; // types of objects you are looking for
  NSArray * arrayOfURLs = [inDraggingInfo.draggingPasteboard readObjectsForClasses:classArray options:nil]; // read objects of those classes
//---
  for (NSURL * url in arrayOfURLs) {
    OC_GGS_DocumentData * documentData = [self findOrAddDocumentWithPath:url.path] ;
    if (nil != documentData) { // Find a text display descriptor
      OC_GGS_TextDisplayDescriptor * tdd = [[OC_GGS_TextDisplayDescriptor alloc]
        initWithDocumentData:documentData
        displayDocument:self
      ] ;
      [mSourceDisplayArrayControllerHigh insertObject:tdd atArrangedObjectIndex:(NSUInteger) inRow] ;
      [mSourceDisplayArrayControllerHigh setSelectedObjects:[NSArray arrayWithObject:tdd]] ;
      [self registerConfigurationInPreferences] ;
    }
  }
  return YES ;
}

//---------------------------------------------------------------------------------------------------------------------*

@end
