//----------------------------------------------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------------------------------------

#import <Cocoa/Cocoa.h>

//----------------------------------------------------------------------------------------------------------------------

@class OC_GGS_TextView ;
@class OC_GGS_DelegateForSyntaxColoring ;
@class OC_Lexique ;
@class OC_GGS_RulerViewForCompileMessageView ;
@class OC_GGS_ErrorOrWarningDescriptor ;
@class OC_GGS_TextSyntaxColoring ;
@class OC_GGS_SourceScrollView ;
@class OC_GGS_BuildTask ;
@class OC_GGS_TextDisplayDescriptor ;
@class OC_GGS_DocumentData ;
@class OC_GGS_RulerViewForBuildOutput ;

//----------------------------------------------------------------------------------------------------------------------

@interface OC_GGS_Document : NSDocument <NSTextViewDelegate,
                                         NSSplitViewDelegate,
                                         NSWindowDelegate,
                                         NSTableViewDataSource,
                                         NSFilePresenter> {
  @private IBOutlet NSSplitView * mFirstSplitView ;
  @private IBOutlet NSSplitView * mSecondSplitView ;

  @private IBOutlet NSView * mSourceHostView ;
  
  @private IBOutlet NSTextView * mOutputTextView ;
  @private IBOutlet NSScrollView * mOutputScrollView ;
  @private NSFont * mBuildTextFont ;

  @private IBOutlet NSPanel * mUpdateFromFileSystemPanel ;

  @private OC_GGS_BuildTask * mBuildTask ;
  @private BOOL mBuildTaskHasBeenAborted ;
  @private NSMutableData * mBufferedOutputData ;
//---  
  @private NSArrayController * mSourceDisplayArrayControllerHigh ;
  @private IBOutlet NSTableView * mDisplayDescriptorTableViewHigh ;
  @private NSMutableArray * mDisplayDescriptorArray ;
//---  
  @private OC_GGS_DocumentData * mDocumentData ;
  @private IBOutlet NSPathControl * mSourceFilePathControl ;

//--- "Goto Line" sheet
  @private IBOutlet NSWindow * mGotoWindow ;
  @private IBOutlet NSTextField * mGotoLineTextField ;

//--- Build, stop button
  @private IBOutlet NSButton * mStartBuildButton ;
  @private IBOutlet NSProgressIndicator * mBuildProgressIndicator ;
  @private IBOutlet NSButton * mStopBuildButton ;
  @private NSUInteger mErrorCount ;
  @private IBOutlet NSTextField * mErrorCountTextField ;
  @private NSUInteger mWarningCount ;
  @private IBOutlet NSTextField * mWarningCountTextField ;
  @private OC_GGS_RulerViewForBuildOutput * mRulerViewForBuildOutput ;
  @private NSMutableArray * mIssueArray ;

//--- Search view
  @private IBOutlet NSView * mSearchView ;
  @private IBOutlet NSButton * mCaseSensitiveSearchCheckbox ;
  @private IBOutlet NSSearchField * mGlobalSearchTextField ;
  @private IBOutlet NSTextField * mGlobalReplaceTextField ;
  @private IBOutlet NSTextField * mOccurenceFoundCountTextField ;
  @private IBOutlet NSOutlineView * mResultOutlineView ;
  @private NSMutableArray * mResultArray ;
  @private NSUInteger mResultCount ;
  @private NSTreeController * mFoundEntryTreeController ;
  @private NSMutableDictionary * mBuildStringAttributeDictionary ;

  @private NSString * mBaseFilePreferenceKey ;
}

@property (assign, atomic) BOOL mBuildTaskIsRunning ;

- (IBAction) openSourceInNewWindowAction: (id) inSender ;
- (IBAction) moveSourceInNewWindowAction: (id) inSender ;
- (IBAction) duplicateSourceAction: (id) inSender ;
- (IBAction) revealInFinderAction: (id) inSender ;
- (IBAction) closeAction: (id) inSender ;
- (IBAction) closeOthersAction: (id) inSender ;

- (IBAction) closeSearchAndReplaceView: (id) inSender ;
- (IBAction) globalFindAction: (id) inSender ;
- (IBAction) globalReplaceAllAction: (id) inSender ;

- (IBAction) copyFilePath: (id) inSender ;
- (IBAction) copyFileName: (id) inSender ;
- (IBAction) copyFileDirectory: (id) inSender ;

- (void) actionOpenFromSelectionInNewWindow: (id) sender ;
- (void) actionOpenFromSelection: (id) sender ;

- (void) updateSearchResultForFile: (NSString *) inFilePath
         previousRange: (NSRange) inPreviousRange
         changeInLength: (NSInteger) inChangeInLength ; 

- (OC_GGS_TextDisplayDescriptor *) findOrAddNewTabForFile: (NSString *) inDocumentPath ;

- (IBAction) collapseIssuesAction: (id) inSender ;

- (IBAction) actionPathControl: (id) inSender ;

- (IBAction) actionGotoLine: (id) inSender ;

- (IBAction) actionComment: (id) sender ;
- (IBAction) actionUncomment: (id) sender ;
- (IBAction) actionShiftLeft: (id) sender  ;
- (IBAction) actionShiftRight: (id) sender ;

- (IBAction) actionBuildFirst: (id) sender ;
- (IBAction) actionBuildRun: (id) sender ;
- (IBAction) stopBuild: (id) sender ;

- (NSString *) sourceStringForGlobalSearch ;

- (void) triggerDocumentEditedStatusUpdate ;

- (void) displaySourceWithURL: (NSURL *) inURL
         atLine: (NSUInteger) inLine ;

- (void) appendBuildOutputData: (NSData *) inData ;
- (void) buildCompletedWithStatus: (int) inTerminationStatus ;
@end

//----------------------------------------------------------------------------------------------------------------------

