//---------------------------------------------------------------------------*
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2003, ..., 2012 Pierre Molinaro.                           *
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

#import "PMTabBarView.h"

//---------------------------------------------------------------------------*

@class OC_GGS_TextView ;
@class OC_GGS_DelegateForSyntaxColoring ;
@class OC_Lexique ;
@class OC_GGS_RulerViewForCompileMessageView ;
@class OC_GGS_ErrorOrWarningDescriptor ;
@class OC_GGS_TextSyntaxColoring ;
@class PMTabBarView ;
@class OC_GGS_SourceScrollView ;
@class OC_GGS_BuildTask ;
@class OC_GGS_TextDisplayDescriptor ;
@class OC_GGS_DocumentData ;
@class OC_GGS_RulerViewForBuildOutput ;

//---------------------------------------------------------------------------*

@interface OC_GGS_Document : NSDocument <PMTabBarViewDelegateProtocol
#if MAC_OS_X_VERSION_MIN_REQUIRED > MAC_OS_X_VERSION_10_5
  , NSTextViewDelegate, NSSplitViewDelegate, NSWindowDelegate
#endif
> {
  @private IBOutlet NSSplitView * mIssueSplitView ;

  @private IBOutlet NSView * mSourceHostView ;
  
  @private IBOutlet NSTextView * mOutputTextView ;
  @private IBOutlet NSScrollView * mOutputScrollView ;

  @private IBOutlet NSPanel * mUpdateFromFileSystemPanel ;

  @private OC_GGS_BuildTask * mBuildTask ;
  @private BOOL mBuildTaskHasBeenAborted ;
  @private NSMutableData * mBufferedOutputData ;
  @private BOOL mHasSpoken ;
//---  
  @private NSArrayController * mSourceDisplayArrayController ;
  @private OC_GGS_DocumentData * mDocumentData ;
  @private NSArray * mDisplayDescriptorArray ;
//---
  @private IBOutlet PMTabBarView * mTabBarView ;

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
}

@property (assign PROPERTY_COMMA_ATOMIC) BOOL mBuildTaskIsRunning ;

- (OC_GGS_TextDisplayDescriptor *) findOrAddNewTabForFile: (NSString *) inDocumentPath ;

- (IBAction) collapseIssuesAction: (id) inSender ;

- (IBAction) actionGotoLine: (id) inSender ;

- (IBAction) duplicateSelectedSourceViewAction: (id) inSender ;

- (IBAction) actionComment: (id) sender ;
- (IBAction) actionUncomment: (id) sender ;
- (IBAction) actionShiftLeft: (id) sender  ;
- (IBAction) actionShiftRight: (id) sender ;

- (IBAction) actionBuild: (id) sender ;
- (IBAction) stopBuild: (id) sender ;

- (NSString *) sourceStringForGlobalSearch ;
- (void) replaceSourceStringWithString: (NSString *) inString ;

- (void) triggerDocumentEditedStatusUpdate ;

- (void) displaySourceWithURL: (NSURL *) inURL
         atLine: (NSUInteger) inLine ;

- (void) appendBuildOutputData: (NSData *) inData ;
- (void) buildCompleted ;
@end
