//--------------------------------------------------------------------------------------------------
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2003, ..., 2023 Pierre Molinaro.
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

#import "OC_GGS_Document.h"
#import "OC_GGS_ApplicationDelegate.h"
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
#import "F_CocoaWrapperForGalgas.h"

//--------------------------------------------------------------------------------------------------

@implementation OC_GGS_Document

//--------------------------------------------------------------------------------------------------

@synthesize mBuildTaskIsRunning ;

//--------------------------------------------------------------------------------------------------

- (instancetype) init {
  self = [super init] ;
  if (self) {
    noteObjectAllocation (self) ;
    mSourceDisplayArrayControllerHigh = [NSArrayController new] ;
    mDisplayDescriptorArray = [NSMutableArray new] ;
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
      options:NSKeyValueObservingOptionNew
      context:NULL
    ] ;
    mBuildStringAttributeDictionary = [NSDictionary dictionaryWithObjectsAndKeys:
      mBuildTextFont, NSFontAttributeName,
      nil
    ].mutableCopy ;
  }
  return self;
}

//--------------------------------------------------------------------------------------------------

- (void) dealloc {
  noteObjectDeallocation (self) ;
}

//--------------------------------------------------------------------------------------------------

- (NSString *) sourceStringForGlobalSearch {
  return mDocumentData.sourceString ;
}

//--------------------------------------------------------------------------------------------------

- (NSString *) windowNibName {
  return @"OC_GGS_Document" ;
}

//--------------------------------------------------------------------------------------------------

- (void) windowControllerDidLoadNib: (NSWindowController *) inWindowController {
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
    options:NSKeyValueObservingOptionNew
    context:NULL
  ] ;
  [[mResultOutlineView tableColumnWithIdentifier:@"count"]
    bind: NSValueBinding
    toObject: mFoundEntryTreeController
    withKeyPath: @"arrangedObjects.countString"
    options: nil
  ] ;
  [[mResultOutlineView tableColumnWithIdentifier:@"result"]
    bind: NSValueBinding
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
    withKeyPath:@"mDisplayDescriptorArray"
    options:nil
  ] ;
//---
  [mSourceDisplayArrayControllerHigh
    addObserver:self 
    forKeyPath:@"selection.textSelectionStart"
    options:NSKeyValueObservingOptionNew
    context:NULL
  ] ;
//---
  [mSourceFilePathControl
    bind: NSValueBinding
    toObject:mSourceDisplayArrayControllerHigh
    withKeyPath:@"selection.sourceURL.path"
    options:nil    
  ] ;
//---
  [[mDisplayDescriptorTableViewHigh tableColumnWithIdentifier:@"source"]
    bind: NSValueBinding
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
    bind: NSValueBinding
    toObject:mSourceDisplayArrayControllerHigh
    withKeyPath:@"arrangedObjects.imageForClosingInUserInterface"
    options:nil    
  ] ;
//---
  mDisplayDescriptorTableViewHigh.target = self ;
  mDisplayDescriptorTableViewHigh.action = @selector (clickOnSourceTableViewHigh:) ;
  mDisplayDescriptorTableViewHigh.dataSource = self ;
  [mDisplayDescriptorTableViewHigh
    registerForDraggedTypes: [NSArray arrayWithObjects: (NSString*) kPasteboardTypeFileURLPromise, @"source.path.molinaro.name", nil]
  ] ;
//---
  [mBuildProgressIndicator startAnimation:nil] ;
  NSDictionary * negateTransformer = [NSDictionary
    dictionaryWithObject:NSNegateBooleanTransformerName 
    forKey:@"NSValueTransformerName"
  ] ;
  [mStartBuildButton
    bind: NSHiddenBinding
    toObject:self
    withKeyPath:@"mBuildTaskIsRunning"
    options:nil
  ] ;
  [mBuildProgressIndicator
    bind: NSHiddenBinding
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
    bind: NSHiddenBinding
    toObject:self
    withKeyPath:@"mBuildTaskIsRunning"
    options:negateTransformer    
  ] ;
//---
  mWarningCountTextField.stringValue = @"0" ;
  mErrorCountTextField.stringValue = @"0" ;
//---
  [mOutputScrollView setVerticalScroller:[OC_GGS_Scroller new]] ;
//--- Get selected tab
  key = [NSString stringWithFormat:@"SELECTED-TAB:%@", mBaseFilePreferenceKey] ;
  const NSUInteger selectedTab = (NSUInteger) [[NSUserDefaults standardUserDefaults] integerForKey:key] ;
//--- Install selected tab observer
  [mSourceDisplayArrayControllerHigh
    addObserver:self 
    forKeyPath:@"selectionIndex"
    options:NSKeyValueObservingOptionNew
    context:NULL
  ] ;
//--- Display the document contents
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
//--- Open tabs
//--- Open tabs
  key = [NSString stringWithFormat:@"CONFIG:%@", mBaseFilePreferenceKey] ;
  NSArray * tabFiles = [[[NSUserDefaults standardUserDefaults] objectForKey:key] copy] ;
  for (NSString * fileAbsolutePath in tabFiles) {
    [self appendTabForFile:fileAbsolutePath] ;
  }
//--- Select tab
  NSArray * sourceDisplayArray = mSourceDisplayArrayControllerHigh.arrangedObjects ;
  mSourceDisplayArrayControllerHigh.selectionIndex = (selectedTab < sourceDisplayArray.count) ? selectedTab : 0 ;
//---
  NSUserDefaultsController * udc = [NSUserDefaultsController sharedUserDefaultsController] ;
  [mCaseSensitiveSearchCheckbox
    bind: NSValueBinding
    toObject: udc
    withKeyPath: @"values.SENSITIVE-SEARCH"
    options: nil
  ] ;
  [[NSUserDefaults standardUserDefaults]
    addObserver: self
    forKeyPath: [NSString stringWithFormat:@"searchMatrixFor:%@", mBaseFilePreferenceKey]
    options: NSKeyValueObservingOptionNew
    context :NULL
  ] ;
//--- Configuring recent search menu
  NSMenu * cellMenu = [[NSMenu alloc]
    initWithTitle: NSLocalizedString(@"Search Menu", @"Search Menu title")
  ] ;
  NSMenuItem * item = [[NSMenuItem alloc]
    initWithTitle: NSLocalizedString(@"Clear", @"Clear menu title")
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
    action:NULL
    keyEquivalent:@""
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
}

//--------------------------------------------------------------------------------------------------

- (void) removeWindowController:(NSWindowController *) inWindowController {
  [OC_GGS_DocumentData saveAllDocuments] ;
  NSArray * sourceDisplayArray = mSourceDisplayArrayControllerHigh.arrangedObjects ;
  for (OC_GGS_TextDisplayDescriptor * tdd in sourceDisplayArray) {
    [tdd detachTextDisplayDescriptor] ;
  }
  for (PMIssueDescriptor * issue in mIssueArray) {
    [issue detach] ;
  }
  [mRulerViewForBuildOutput detach] ;
  for (NSView * subview in mSourceHostView.subviews.copy) {
    [subview removeFromSuperview] ;
  }
  [mSourceFilePathControl
    unbind: NSValueBinding
  ] ;
  [mSourceDisplayArrayControllerHigh unbind:@"contentArray"] ;
  [mSourceDisplayArrayControllerHigh removeObserver: self forKeyPath:@"selectionIndex"] ;
//---
  [mSourceDisplayArrayControllerHigh
    removeObserver: self
    forKeyPath:@"selection.textSelectionStart"
  ] ;
//---
  [mStartBuildButton unbind: NSHiddenBinding] ;
  [mBuildProgressIndicator unbind: NSHiddenBinding] ;
  [mStopBuildButton unbind: NSEnabledBinding] ;
  [mStopBuildButton unbind: NSHiddenBinding ] ;
//---
  [[mDisplayDescriptorTableViewHigh tableColumnWithIdentifier:@"source"]
    unbind: NSValueBinding
  ] ;
  [[mDisplayDescriptorTableViewHigh tableColumnWithIdentifier:@"source"]
    unbind:@"fontBold"
  ] ;
  [[mDisplayDescriptorTableViewHigh tableColumnWithIdentifier:@"remove"]
    unbind: NSValueBinding
  ] ;
//---
  [mFoundEntryTreeController unbind:@"contentArray"] ;
  [mFoundEntryTreeController
    removeObserver:self 
    forKeyPath:@"selectionIndexPath"
  ] ;
  [[mResultOutlineView tableColumnWithIdentifier:@"count"]
    unbind: NSValueBinding
  ] ;
  [[mResultOutlineView tableColumnWithIdentifier:@"result"]
    unbind: NSValueBinding
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
  [mCaseSensitiveSearchCheckbox unbind: NSValueBinding] ;
  [ud
    removeObserver:self
    forKeyPath:[NSString stringWithFormat:@"searchMatrixFor:%@", mBaseFilePreferenceKey]
  ] ;
//---
  mSourceDisplayArrayControllerHigh = nil ;
  mDisplayDescriptorArray = nil ;
//--- Last call
  [OC_GGS_DocumentData cocoaDocumentWillClose: mDocumentData] ;
//---
  [super removeWindowController:inWindowController] ;
}

//--------------------------------------------------------------------------------------------------

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
}

//--------------------------------------------------------------------------------------------------

- (void) changeSelectedSourceViewAction: (NSButton *) inSender {
  [mSourceDisplayArrayControllerHigh setSelectionIndex:(NSUInteger) inSender.tag] ;
}

//--------------------------------------------------------------------------------------------------

- (IBAction) actionGotoLine: (id) inSender {
  [NSApp
    beginSheet: mGotoWindow
    modalForWindow: self.windowForSheet
    modalDelegate: self
    didEndSelector: @selector (gotoLineSheetDidEnd:returnCode:contextInfo:)
    contextInfo: nil
  ] ;
}

//--------------------------------------------------------------------------------------------------

- (void) collapseIssuesAction: (id) inSender {
  [mFirstSplitView setPosition:0.0 ofDividerAtIndex:0] ;
}

//--------------------------------------------------------------------------------------------------

- (void) gotoLineSheetDidEnd: (NSWindow *) inSheet
         returnCode: (int) inReturnCode
         contextInfo: (void *) inContextInfo {
  if (inReturnCode == 1) {
  //--- Get selected line
    const NSUInteger selectedLine = (NSUInteger) [mGotoLineTextField integerValue] ;
  //--- Goto selected line
    OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
    [selectedObject gotoLine: selectedLine] ;
  }
}

//--------------------------------------------------------------------------------------------------

- (IBAction) actionComment: (id) sender {
  OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  [selectedObject commentSelection] ;
}

//--------------------------------------------------------------------------------------------------

- (IBAction) actionUncomment: (id) sender {
  OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  [selectedObject uncommentSelection] ;
}

//--------------------------------------------------------------------------------------------------

- (IBAction) actionShiftLeft: (id) sender {
  OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  [selectedObject shiftLeftAction] ;
}

//--------------------------------------------------------------------------------------------------

- (IBAction) actionShiftRight: (id) sender {
  OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  [selectedObject shiftRightAction] ;
}

//--------------------------------------------------------------------------------------------------

- (BOOL) validateMenuItem:(NSMenuItem *) item {
  BOOL result = YES ;
  if ((item.action == @selector (actionComment:)) || (item.action == @selector (actionUncomment:))) {
    OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
    result = selectedObject.documentData.textSyntaxColoring.tokenizer.blockComment.length > 0 ;
  }else if (item.action == @selector (actionBuildRun:)) {
    result = buildRunOption ().length > 0 ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

- (IBAction) saveAllDocuments: (id) inSender {
  [OC_GGS_DocumentData saveAllDocuments] ;
}

//--------------------------------------------------------------------------------------------------

- (void) displaySourceWithURL: (NSURL *) inURL
         atLine: (NSUInteger) inLine {
  if (nil != inURL) {
    OC_GGS_TextDisplayDescriptor * tdd = [self findOrAddNewTabForFile:inURL.path] ;
    const NSRange r = {[tdd.documentData locationForLineInSource:inLine], 0} ;
    [tdd setSelectionRangeAndMakeItVisible:r] ;
  }
}

//--------------------------------------------------------------------------------------------------

- (IBAction) actionPathControl: (id) inSender {
  NSArray * cells = mSourceFilePathControl.pathComponentCells ;
  NSCell * clickedCell = mSourceFilePathControl.clickedPathComponentCell ;
  NSUInteger clickedCellIndex = [cells indexOfObject:clickedCell] ;
  NSMutableString * rootPath = [NSMutableString new] ;
  for (NSUInteger i=0 ; i<clickedCellIndex ; i++) {
    [rootPath appendFormat:@"/%@", [[cells objectAtIndex:i] title]] ;
  }
  NSWorkspace * ws = [NSWorkspace sharedWorkspace] ;
  NSString * path = [NSString stringWithFormat:@"%@/%@", rootPath, [[cells objectAtIndex:clickedCellIndex] title]] ; 
  [ws selectFile:path inFileViewerRootedAtPath:rootPath] ;
}

//--------------------------------------------------------------------------------------------------

- (IBAction) copyFilePath: (id) inSender {
  OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  NSString * filePath = selectedObject.sourceURL.path ;
  NSPasteboard * pasteboard = [NSPasteboard generalPasteboard] ;
  [pasteboard clearContents] ;
  [pasteboard writeObjects:[NSArray arrayWithObject:filePath]] ;
}

//--------------------------------------------------------------------------------------------------

- (IBAction) copyFileName: (id) inSender {
  OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  NSString * fileName = selectedObject.sourceURL.path.lastPathComponent ;
  NSPasteboard * pasteboard = [NSPasteboard generalPasteboard] ;
  [pasteboard clearContents] ;
  [pasteboard writeObjects:[NSArray arrayWithObject:fileName]] ;
}

//--------------------------------------------------------------------------------------------------

- (IBAction) copyFileDirectory: (id) inSender {
  OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  NSString * fileDirectory = selectedObject.sourceURL.path.stringByDeletingLastPathComponent ;
  NSPasteboard * pasteboard = [NSPasteboard generalPasteboard] ;
  [pasteboard clearContents] ;
  [pasteboard writeObjects:[NSArray arrayWithObject:fileDirectory]] ;
}

//--------------------------------------------------------------------------------------------------

- (void) actionInsertTextMacro: (NSMenuItem *) inSender {
  OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  [selectedObject actionInsertTextMacro:inSender] ;
}

//--------------------------------------------------------------------------------------------------

- (void) printDocument: (id) sender {
  OC_GGS_TextDisplayDescriptor * selectedObject = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  [selectedObject.textView print:sender] ;
}

//--------------------------------------------------------------------------------------------------

- (void) saveDocument:(id) inSender {
  NSURL * url = [self fileURL] ;
  [self setFileURL:mDocumentData.fileURL] ;
  [super saveDocument:inSender] ;
  [self setFileURL:url] ;
}

//--------------------------------------------------------------------------------------------------

- (BOOL) writeToURL: (NSURL *) inAbsoluteURL
         ofType: (NSString *) inTypeName
         error: (NSError * __autoreleasing *) outError {
  return [mDocumentData performSaveToURL: inAbsoluteURL] ;
}

//--------------------------------------------------------------------------------------------------

- (BOOL) readFromURL:(NSURL *) inAbsoluteURL
         ofType:(NSString *) inTypeName
         error:(NSError * __autoreleasing *) outError {
  mBaseFilePreferenceKey = [inAbsoluteURL.path identifierRepresentation] ;
  mDocumentData = [OC_GGS_DocumentData
    findOrAddDataForDocumentURL:inAbsoluteURL
    forCocoaDocument:self
 ] ;
  return mDocumentData != nil ;
}

//--------------------------------------------------------------------------------------------------

- (IBAction) stopBuild: (id) sender {
  mBuildTaskHasBeenAborted = YES ;
  [mBuildTask terminate] ;
}

//--------------------------------------------------------------------------------------------------

- (IBAction) actionBuildFirst: (id) inUnusedSender {
  if (nil == mBuildTask) {
    OC_GGS_TextDisplayDescriptor * tdd = [mDisplayDescriptorArray objectAtIndex: 0] ;
    [self compileFileAtPath: tdd.sourceURL.path isBuildRun: NO] ;
  }
}

//--------------------------------------------------------------------------------------------------

- (IBAction) actionBuildRun: (id) inUnusedSender {
  if (nil == mBuildTask) {
    OC_GGS_TextDisplayDescriptor * tdd = [mDisplayDescriptorArray objectAtIndex:0] ;
    [self compileFileAtPath:tdd.sourceURL.path isBuildRun:YES] ;
  }
}

//--------------------------------------------------------------------------------------------------

- (void) compileFileAtPath: (NSString *) inFilePath
         isBuildRun: (BOOL) inIsBuildRun {
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
    isBuildRun:inIsBuildRun
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
  [mOutputTextView.textStorage setAttributedString: attributedString] ;
  [mOutputTextView setAutomaticLinkDetectionEnabled:YES] ;
}

//--------------------------------------------------------------------------------------------------

- (void) enterIssue: (NSString *) inIssueMessage
         isError: (BOOL) inIsError
         locationInOutputData: (NSRange) inRangeInOutputData {
  NSArray * components = [inIssueMessage componentsSeparatedByString:@"\n"] ;
  NSString * issuePath = nil ;
  NSInteger issueLine = 0 ;
  NSInteger issueStartColumn = 0 ;
  NSInteger issueEndColumn = 0 ;
  if (components.count > 1) {
    NSArray * issueLocationArray = [[components objectAtIndex:0] componentsSeparatedByString:@":"] ;
    if (issueLocationArray.count > 4) {
      issuePath = [issueLocationArray objectAtIndex:0] ;
      issueLine = [[issueLocationArray objectAtIndex:1] integerValue] ;
      issueStartColumn = [[issueLocationArray objectAtIndex:2] integerValue] ;
      issueEndColumn = [[issueLocationArray objectAtIndex:3] integerValue] ;
    }
  }
  PMIssueDescriptor * issue = [[PMIssueDescriptor alloc]
    initWithMessage:inIssueMessage
    URL:(nil == issuePath) ? nil : [NSURL fileURLWithPath:issuePath]
    line:issueLine
    startColumn:issueStartColumn
    endColumn:issueEndColumn
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

//--------------------------------------------------------------------------------------------------

static const utf32 COCOA_WARNING_ID = TO_UNICODE (3) ;
static const utf32 COCOA_ERROR_ID   = TO_UNICODE (4) ;

//--------------------------------------------------------------------------------------------------

- (void) enterOutputData: (NSData *) inData {
  NSString * message = [[NSString alloc] initWithData:inData encoding: NSUTF8StringEncoding] ;
  NSArray * messageArray = [message componentsSeparatedByString:[NSString stringWithFormat: @"%c", 0x1B]] ;
//--- Enter first component with current attributes
  NSMutableAttributedString * outputAttributedString = [[NSMutableAttributedString alloc]
    initWithString: [messageArray objectAtIndex:0]
    attributes: mBuildStringAttributeDictionary
  ] ;
//--- Send other components
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
      case  0 :
        mBuildStringAttributeDictionary = [NSDictionary dictionaryWithObjectsAndKeys:
          mBuildTextFont, NSFontAttributeName,
          nil
        ].mutableCopy ;
        break ;
      case 30 : [mBuildStringAttributeDictionary setValue:[NSColor blackColor]   forKey:NSForegroundColorAttributeName] ; break ;
      case 31 : [mBuildStringAttributeDictionary setValue:[NSColor redColor]     forKey:NSForegroundColorAttributeName] ; break ;
      case 32 : [mBuildStringAttributeDictionary setValue:[NSColor colorWithCalibratedRed:0.0 green:0.5 blue:0.0 alpha:1.0] forKey:NSForegroundColorAttributeName] ; break ;
      case 33 : [mBuildStringAttributeDictionary setValue:[NSColor orangeColor]  forKey:NSForegroundColorAttributeName] ; break ;
      case 34 : [mBuildStringAttributeDictionary setValue:[NSColor blueColor]    forKey:NSForegroundColorAttributeName] ; break ;
      case 35 : [mBuildStringAttributeDictionary setValue:[NSColor magentaColor] forKey:NSForegroundColorAttributeName] ; break ;
      case 36 : [mBuildStringAttributeDictionary setValue:[NSColor cyanColor]    forKey:NSForegroundColorAttributeName] ; break ;
      case 37 : [mBuildStringAttributeDictionary setValue:[NSColor whiteColor]   forKey:NSForegroundColorAttributeName] ; break ;
      case 40 : [mBuildStringAttributeDictionary setValue:[NSColor whiteColor]   forKey:NSBackgroundColorAttributeName] ; break ;
      case 41 : [mBuildStringAttributeDictionary setValue:[NSColor redColor]     forKey:NSBackgroundColorAttributeName] ; break ;
      case 42 : [mBuildStringAttributeDictionary setValue:[NSColor colorWithCalibratedRed:0.0 green:0.5 blue:0.0 alpha:1.0] forKey:NSBackgroundColorAttributeName] ; break ;
      case 43 : [mBuildStringAttributeDictionary setValue:[NSColor orangeColor]  forKey:NSBackgroundColorAttributeName] ; break ;
      case 44 : [mBuildStringAttributeDictionary setValue:[NSColor blueColor]    forKey:NSBackgroundColorAttributeName] ; break ;
      case 45 : [mBuildStringAttributeDictionary setValue:[NSColor magentaColor] forKey:NSBackgroundColorAttributeName] ; break ;
      case 46 : [mBuildStringAttributeDictionary setValue:[NSColor cyanColor]    forKey:NSBackgroundColorAttributeName] ; break ;
      case 47 : [mBuildStringAttributeDictionary setValue:[NSColor whiteColor]   forKey:NSBackgroundColorAttributeName] ; break ;
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
        initWithString: s
        attributes: mBuildStringAttributeDictionary
      ] ;
      [outputAttributedString appendAttributedString:as] ;
    }
  }
  NSArray * stringArray = [outputAttributedString.string componentsSeparatedByString:@"\r"] ;
  if ([stringArray count] == 1) {
    [mOutputTextView.textStorage appendAttributedString: outputAttributedString] ;
  }else{
    [mOutputTextView.textStorage beginEditing] ;
    NSUInteger totalLength = 0 ;
    for (NSUInteger idx = 0 ; idx < [stringArray count] ; idx ++) {
      const NSUInteger length = [stringArray[idx] length] ;
      NSAttributedString * at = [outputAttributedString attributedSubstringFromRange: NSMakeRange (totalLength, length)] ;
      [mOutputTextView.textStorage appendAttributedString: at] ;
      totalLength += length + 1 ; // Add '\r'
    //--- Remove last line
      if (idx < ([stringArray count] - 1)) {
        NSRange lastLineRange = [mOutputTextView.textStorage.string lineRangeForRange: NSMakeRange (mOutputTextView.textStorage.string.length, 0)] ;
        [mOutputTextView.textStorage deleteCharactersInRange: lastLineRange] ;
      }
    }
    [mOutputTextView.textStorage endEditing] ;
  }
  [mOutputTextView scrollRangeToVisible: NSMakeRange (mOutputTextView.textStorage.length, 0)] ;
}

//--------------------------------------------------------------------------------------------------

- (void) buildCompletedWithStatus: (int) inTerminationStatus {
  self.mBuildTaskIsRunning = NO ;
//---
  [self enterOutputData: mBufferedOutputData] ;
  mBufferedOutputData = nil ;
//---
  [OC_GGS_DocumentData broadcastIssueArray: mIssueArray] ;
//---
  if (mBuildTaskHasBeenAborted) {
    NSDictionary * defaultDictionary = [NSDictionary dictionaryWithObjectsAndKeys:
      mBuildTextFont, NSFontAttributeName,
      [NSColor redColor], NSForegroundColorAttributeName,
      nil
    ] ;
    NSAttributedString * attributedString = [[NSAttributedString alloc]
      initWithString: @"Aborted.\n"
      attributes: defaultDictionary
    ] ;
    [mOutputTextView.textStorage appendAttributedString:attributedString] ;
  }else if (inTerminationStatus == 0) {
    NSDictionary * defaultDictionary = [NSDictionary dictionaryWithObjectsAndKeys:
      mBuildTextFont, NSFontAttributeName,
      [NSColor blueColor], NSForegroundColorAttributeName,
      nil
    ] ;
    NSAttributedString * attributedString = [[NSAttributedString alloc]
      initWithString: @"Done.\n"
      attributes: defaultDictionary
    ] ;
    [mOutputTextView.textStorage appendAttributedString:attributedString] ;
  }else{
    NSDictionary * defaultDictionary = [NSDictionary dictionaryWithObjectsAndKeys:
      mBuildTextFont, NSFontAttributeName,
      [NSColor redColor], NSForegroundColorAttributeName,
      nil
    ] ;
    NSAttributedString * attributedString = [[NSAttributedString alloc]
      initWithString: [NSString stringWithFormat: @"Error, termination status %d.\n", inTerminationStatus]
      attributes: defaultDictionary
    ] ;
    [mOutputTextView.textStorage appendAttributedString:attributedString] ;
  }
//---
  [[NSRunLoop mainRunLoop]
    performSelector:@selector (pmReleaseBuildTask)
    target:self
    argument:nil
    order:0
    modes:[NSArray arrayWithObject:NSDefaultRunLoopMode]
  ] ;
}

//--------------------------------------------------------------------------------------------------

- (void) pmReleaseBuildTask {
  mBuildTask = nil ;
  [NSApp requestUserAttention: NSInformationalRequest] ;
}

//--------------------------------------------------------------------------------------------------

- (void) appendBuildOutputData: (NSData *) inData {
  [mBufferedOutputData appendData: inData] ;
//--- Look for line feed
  BOOL ok = NO ;
  NSUInteger idx = mBufferedOutputData.length ;
  while ((! ok) && (idx > 0)) {
    idx -- ;
    const NSRange range = {idx, 1} ;
    uint16 c ;
    [mBufferedOutputData getBytes:& c range:range] ;
    ok = c == '\n' ;
  }
//--- If found, extract data
  if (ok) {
    idx += 1 ;
    NSData * data = [mBufferedOutputData subdataWithRange: NSMakeRange (0, idx)] ;
    NSData * remainingData = [mBufferedOutputData subdataWithRange: NSMakeRange (idx, mBufferedOutputData.length - idx)] ;
    [mBufferedOutputData setData: remainingData] ;
    [self enterOutputData: data] ;
  }
}

//--------------------------------------------------------------------------------------------------

- (void) triggerDocumentEditedStatusUpdate {
  BOOL isEdited = NO ;
  NSArray * sourceDisplayArray = mSourceDisplayArrayControllerHigh.arrangedObjects ;
  for (NSUInteger i=0 ; (i<sourceDisplayArray.count) && ! isEdited ; i++) {
    OC_GGS_TextDisplayDescriptor * textDisplay = [sourceDisplayArray objectAtIndex:i] ;
    OC_GGS_TextSyntaxColoring * textSyntaxColoring = textDisplay.documentData.textSyntaxColoring ;
    isEdited = textSyntaxColoring.isDirty ;
  }
  [self updateChangeCount:isEdited ? NSChangeDone : NSChangeCleared] ;
}

//--------------------------------------------------------------------------------------------------

- (void) clickOnSourceTableViewHigh: (id) inSender {
  if (mDisplayDescriptorTableViewHigh.clickedColumn == 1) {
    const NSInteger row = mDisplayDescriptorTableViewHigh.clickedRow ;
    if (row >= 0) {
      OC_GGS_TextDisplayDescriptor * desc = [mSourceDisplayArrayControllerHigh.arrangedObjects objectAtIndex: (NSUInteger) row] ;
      [self removeSelectedTabAction: desc] ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------

- (IBAction) duplicateSourceAction: (id) inSender {
  OC_GGS_TextDisplayDescriptor * d = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  OC_GGS_TextDisplayDescriptor * tdd = [[OC_GGS_TextDisplayDescriptor alloc]
    initWithDocumentData:d.documentData
    displayDocument:self
  ] ;
  [mSourceDisplayArrayControllerHigh addObject:tdd] ;
  [self registerConfigurationInPreferences] ;
}

//--------------------------------------------------------------------------------------------------

- (IBAction) revealInFinderAction: (id) inSender {
  OC_GGS_TextDisplayDescriptor * d = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  NSWorkspace * ws = [NSWorkspace sharedWorkspace] ;
  const BOOL ok = [ws selectFile:d.sourceURL.path inFileViewerRootedAtPath:@""] ;
  if (! ok) {
    NSBeep () ;
  }
}

//--------------------------------------------------------------------------------------------------

- (IBAction) closeAction: (id) inSender {
  OC_GGS_TextDisplayDescriptor * d = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  [self removeSelectedTabAction:d] ;
}

//--------------------------------------------------------------------------------------------------

- (IBAction) closeOthersAction: (id) inSender {
  OC_GGS_TextDisplayDescriptor * tdd = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
  for (OC_GGS_TextDisplayDescriptor * d in [mSourceDisplayArrayControllerHigh.arrangedObjects copy]) {
    if (tdd != d) {
      [self removeSelectedTabAction:d] ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

- (OC_GGS_DocumentData *) findOrAddDocumentWithPath: (NSString *) inPath {
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

//--------------------------------------------------------------------------------------------------

- (OC_GGS_TextDisplayDescriptor *) findOrAddNewTabForFile: (NSString *) inDocumentPath {
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

//--------------------------------------------------------------------------------------------------

- (void) appendTabForFile: (NSString *) inDocumentPath {
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

//--------------------------------------------------------------------------------------------------

- (void) removeSelectedTabAction: (OC_GGS_TextDisplayDescriptor *) inTextDisplayDescriptor {
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

//--------------------------------------------------------------------------------------------------

- (void) observeValueForKeyPath:(NSString *) inKeyPath
         ofObject: (id) inObject
         change:(NSDictionary *) inChange
         context:(void *) inContext {
  NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
  if ((inObject == ud) && [inKeyPath isEqualToString:GGS_build_text_font]) {
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

//--------------------------------------------------------------------------------------------------

- (NSString *) fileNameFromSelection {
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

//--------------------------------------------------------------------------------------------------

- (void) actionOpenFromSelectionInNewWindow: (id) sender {
  NSString * newDocumentPath = self.fileNameFromSelection ;
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

//--------------------------------------------------------------------------------------------------

- (void) actionOpenFromSelection: (id) sender {
  [self findOrAddNewTabForFile:self.fileNameFromSelection] ;
}

//--------------------------------------------------------------------------------------------------

- (double) positionOfDividerAtIndex:(NSInteger)dividerIndex {
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

//--------------------------------------------------------------------------------------------------
// NSPlitView delegate method

- (CGFloat) splitView:(NSSplitView *) inSplitView
            constrainMinCoordinate: (CGFloat) inProposedMin
            ofSubviewAt: (NSInteger) inDividerIndex {
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

//--------------------------------------------------------------------------------------------------
// NSPlitView delegate method

- (CGFloat) splitView:(NSSplitView *) inSplitView
            constrainMaxCoordinate: (CGFloat) inProposedMax
            ofSubviewAt: (NSInteger) inDividerIndex {
  CGFloat result = inProposedMax ;
  const CGFloat minSecondSplitViewValue = 250.0 ;
  CGFloat max = inSplitView.bounds.size.height - minSecondSplitViewValue ;
  if ((inDividerIndex == 0) && (inSplitView == mSecondSplitView) && (inProposedMax > max)) {
    result = max  ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

// http://stackoverflow.com/questions/17441877/nssplitview-fixed-splitter-on-window-resize

- (void) splitView:(NSSplitView *) inSplitView
         resizeSubviewsWithOldSize: (NSSize) inOldSize {
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

//--------------------------------------------------------------------------------------------------

- (IBAction) showSearchAndReplaceView: (id) inSender {
  const double position = [self positionOfDividerAtIndex:0] ;
  [mOutputScrollView removeFromSuperview] ;
  [mSecondSplitView addSubview:mSearchView] ;
  [mSecondSplitView adjustSubviews] ;
  [mSecondSplitView setPosition:position ofDividerAtIndex:0] ;
  [mGlobalSearchTextField.window makeFirstResponder:mGlobalSearchTextField] ;
}

//--------------------------------------------------------------------------------------------------

- (IBAction) closeSearchAndReplaceView: (id) inSender {
  const double position = [self positionOfDividerAtIndex:0] ;
  [mSearchView removeFromSuperview] ;
  [mSecondSplitView addSubview:mOutputScrollView] ;
  [mSecondSplitView adjustSubviews] ;
  [mSecondSplitView setPosition:position ofDividerAtIndex:0] ;
}

//--------------------------------------------------------------------------------------------------

- (void) updateOccurrenceFoundTextField {
  NSString * s = @"No Occurrence found" ;
  if (mResultCount == 1) {
    s = @"1 Occurrence found" ;
  }else if (mResultCount > 1) {
    s = [NSString stringWithFormat:@"%lu Occurrences found", mResultCount] ;
  }
  mOccurenceFoundCountTextField.stringValue = s ;
  [mOccurenceFoundCountTextField display] ;
}

//--------------------------------------------------------------------------------------------------

- (IBAction) globalFindAction: (id) inSender {
  [OC_GGS_DocumentData saveAllDocuments] ;
  [self willChangeValueForKey:@"mResultArray"] ;
  mResultArray = [NSMutableArray new] ;
  [self didChangeValueForKey:@"mResultArray"] ;
  mResultCount = 0 ;
  [self updateOccurrenceFoundTextField] ;
  [self findInOpenedFileDirectories] ;
}

//--------------------------------------------------------------------------------------------------

- (void) findInOpenedFileDirectories {
//--- Get all dir set
  NSMutableSet * directoryPathSet = [NSMutableSet new] ;
  for (OC_GGS_TextDisplayDescriptor * d in mSourceDisplayArrayControllerHigh.arrangedObjects) {
    NSString * dir = d.sourceURL.path.stringByDeletingLastPathComponent ;
    [directoryPathSet addObject:dir] ;
  }
//--- Retain only base directories, eliminate sub directories
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
//--- Explore dirs
  NSArray * extensionArray = gCocoaApplicationDelegate.allExtensionsOfCurrentApplication.allObjects ;
  for (NSString * directoryPath in directoryPathArray) {
    [self
      recursiveSearchInDirectory:directoryPath
      recursive: YES
      extensionList: extensionArray
    ] ;
  }
}

//--------------------------------------------------------------------------------------------------

- (void) recursiveSearchInDirectory: (NSString *) inDirectoryFullPath
         recursive: (BOOL) inRecursive
         extensionList: (NSArray *) inExtensionList {
  NSFileManager * fm = [NSFileManager new] ;
  NSArray * contents = [fm contentsOfDirectoryAtPath: inDirectoryFullPath error:nil] ;
  if (nil == contents) {
  
  }else{
    for (NSString * subPath in contents) {
      if ('.' != [subPath characterAtIndex: 0]) {
        NSString * fullPath = [NSString stringWithFormat:@"%@/%@", inDirectoryFullPath, subPath] ;
        BOOL isDirectory ;
        if ([fm fileExistsAtPath: fullPath isDirectory: & isDirectory]) {
          if (isDirectory && inRecursive) {
            [self recursiveSearchInDirectory:fullPath recursive:YES extensionList:inExtensionList] ;
          }else if ((! isDirectory) && [inExtensionList containsObject:[fullPath pathExtension]]) {
            [self findInFile: fullPath] ;
          }
        }
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

- (NSUInteger) searchOptions {
  NSUInteger searchOptions = 0 ;
  if (! mCaseSensitiveSearchCheckbox.state) {
    searchOptions |= NSCaseInsensitiveSearch ;
  }
  return searchOptions ;
}

//--------------------------------------------------------------------------------------------------

- (void) findInFile: (NSString *) inFilePath {
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

//--------------------------------------------------------------------------------------------------

- (void) addFindResult:(NSString *) inSourceFilePath
         sourceString: (NSString *) inSourceString
         range: (NSRange) inFoundRange
         toArray: (NSMutableArray *) ioFoundEntries {
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

//--------------------------------------------------------------------------------------------------

- (void) enterResult: (NSMutableArray *) inFoundEntries
         forFilePath:(NSString *) inSourceFilePath {
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

//--------------------------------------------------------------------------------------------------

- (void) changeSelectionInSearchResultView {
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

//--------------------------------------------------------------------------------------------------

- (void) updateSearchResultForFile: (NSString *) inFilePath
         previousRange: (NSRange) inPreviousRange
         changeInLength: (NSInteger) inChangeInLength {
  for (PMSearchResultDescriptor * d in mResultArray) {
    [d
      updateSearchResultForFile:inFilePath
      previousRange:inPreviousRange
      changeInLength:inChangeInLength
    ] ;
  }
} 

//--------------------------------------------------------------------------------------------------

- (IBAction) globalReplaceAllAction: (id) inSender {
  NSString * replaceString = mGlobalReplaceTextField.stringValue ;
  for (PMSearchResultDescriptor * d in mResultArray) {
    NSString * filePath = d.filePath ;
    NSArray * foundEntries = d.children ;
    OC_GGS_DocumentData * documentData = [OC_GGS_DocumentData findDocumentDataForFilePath:filePath] ;
    if (nil == documentData) {
      NSMutableString * contents = [[NSString stringWithContentsOfFile:filePath encoding:NSUTF8StringEncoding error:nil] mutableCopy] ;
      if (nil != contents) {
        for (PMSearchResultDescriptor * entry in foundEntries.reverseObjectEnumerator) {
          [contents replaceCharactersInRange: entry.range withString:replaceString] ;
        }
      }
      [contents writeToFile:filePath atomically:YES encoding:NSUTF8StringEncoding error:nil] ;
    }else{
      for (PMSearchResultDescriptor * entry in foundEntries.reverseObjectEnumerator) {
        [documentData replaceCharactersInRange: entry.range withString:replaceString] ;
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

- (id <NSPasteboardWriting>) tableView: (NSTableView *) inTableView
                             pasteboardWriterForRow: (NSInteger) inRowIndex {
  id <NSPasteboardWriting> result = nil ;
  if ((inRowIndex >= 0) && (inRowIndex < (NSInteger) mDisplayDescriptorArray.count)) {
    OC_GGS_TextDisplayDescriptor * tdd = [mSourceDisplayArrayControllerHigh.selectedObjects objectAtIndex:0] ;
    NSPasteboardItem * pasteboardItem = [[NSPasteboardItem alloc] init] ;
    [pasteboardItem
      setString: tdd.sourceURL.path
      forType: @"source.path.molinaro.name"
    ] ;
    result = pasteboardItem ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

- (NSDragOperation) tableView: (NSTableView*) tv
                    validateDrop: (id <NSDraggingInfo>) info
                    proposedRow: (NSInteger) row
                    proposedDropOperation: (NSTableViewDropOperation) op {
  return NSDragOperationEvery ;
}

//--------------------------------------------------------------------------------------------------

- (BOOL) tableView: (NSTableView *) inTableView
         acceptDrop: (id <NSDraggingInfo>) inDraggingInfo
         row: (NSInteger) inRow
         dropOperation: (NSTableViewDropOperation)operation {
  NSString * filePath = [inDraggingInfo.draggingPasteboard stringForType: @"source.path.molinaro.name"] ;
  if (filePath != nil) {
    OC_GGS_DocumentData * documentData = [self findOrAddDocumentWithPath: filePath] ;
    if (nil != documentData) { // Find a text display descriptor
      OC_GGS_TextDisplayDescriptor * tdd = [[OC_GGS_TextDisplayDescriptor alloc]
        initWithDocumentData: documentData
        displayDocument: self
      ] ;
      [mSourceDisplayArrayControllerHigh insertObject: tdd atArrangedObjectIndex: (NSUInteger) inRow] ;
      [mSourceDisplayArrayControllerHigh setSelectedObjects: [NSArray arrayWithObject:tdd]] ;
      [self registerConfigurationInPreferences] ;
    }
  }
//--- file pathes
  NSArray * pathClassArray = [NSArray arrayWithObject: [NSString class]]; // types of objects you are looking for
  NSArray * arrayOfPathes = [inDraggingInfo.draggingPasteboard readObjectsForClasses: pathClassArray options: nil] ; // read objects of those classes
//---
  for (NSString * path in arrayOfPathes) {
    OC_GGS_DocumentData * documentData = [self findOrAddDocumentWithPath: path] ;
    if (nil != documentData) { // Find a text display descriptor
      OC_GGS_TextDisplayDescriptor * tdd = [[OC_GGS_TextDisplayDescriptor alloc]
        initWithDocumentData: documentData
        displayDocument: self
      ] ;
      [mSourceDisplayArrayControllerHigh insertObject: tdd atArrangedObjectIndex: (NSUInteger) inRow] ;
      [mSourceDisplayArrayControllerHigh setSelectedObjects: [NSArray arrayWithObject:tdd]] ;
      [self registerConfigurationInPreferences] ;
    }
  }
//--- URLs
  NSArray * urlClassArray = [NSArray arrayWithObject:[NSURL class]]; // types of objects you are looking for
  NSArray * arrayOfURLs = [inDraggingInfo.draggingPasteboard readObjectsForClasses: urlClassArray options: nil]; // read objects of those classes
//---
  for (NSURL * url in arrayOfURLs) {
    OC_GGS_DocumentData * documentData = [self findOrAddDocumentWithPath:url.path] ;
    if (nil != documentData) { // Find a text display descriptor
      OC_GGS_TextDisplayDescriptor * tdd = [[OC_GGS_TextDisplayDescriptor alloc]
        initWithDocumentData: documentData
        displayDocument: self
      ] ;
      [mSourceDisplayArrayControllerHigh insertObject: tdd atArrangedObjectIndex: (NSUInteger) inRow] ;
      [mSourceDisplayArrayControllerHigh setSelectedObjects: [NSArray arrayWithObject: tdd]] ;
      [self registerConfigurationInPreferences] ;
    }
  }
//---
  return YES ;
}

//--------------------------------------------------------------------------------------------------

@end
