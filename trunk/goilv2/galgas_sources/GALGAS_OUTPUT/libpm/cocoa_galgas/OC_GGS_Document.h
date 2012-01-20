//---------------------------------------------------------------------------*
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2003, ..., 2010 Pierre Molinaro.                           *
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

#import <Cocoa/Cocoa.h>

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

//---------------------------------------------------------------------------*

@interface OC_GGS_Document : NSDocument <NSTextViewDelegate, NSSplitViewDelegate, NSWindowDelegate> {

  @private IBOutlet NSSplitView * mIssueSplitView ;

  @private IBOutlet NSView * mSourceHostView ;

  @private IBOutlet NSPopUpButton * mEntryListPopUpButton ;
  
  @private IBOutlet NSButton * mCurrentLineButton ;

  @private IBOutlet NSTableView * mIssueTableView ;
  @private IBOutlet NSTableColumn * mIssueTableViewColumn ;

  @private IBOutlet NSPanel * mUpdateFromFileSystemPanel ;

  @private IBOutlet NSTextField * mSourceEncodingTextField ;
  @private NSStringEncoding mFileEncoding ;

  @private OC_GGS_BuildTask * mBuildTask ;
//---  
  @private OC_GGS_TextSyntaxColoring * mSourceTextWithSyntaxColoring ;
  @private NSArrayController * mSourceDisplayArrayController ;

//---
  @private IBOutlet PMTabBarView * mTabBarView ;

//--- "Goto Line" sheet
  @private IBOutlet NSWindow * mGotoWindow ;
  @private IBOutlet NSTextField * mGotoLineTextField ;

//--- Detailled issue message
  @private IBOutlet NSTextView * mDetailedIssueTextView ;
  @private IBOutlet NSSplitView * mDetailedIssueSplitView ;

//--- Build, stop button
  @private IBOutlet NSButton * mStartBuildButton ;
  @private IBOutlet NSProgressIndicator * mBuildProgressIndicator ;
  @private IBOutlet NSButton * mStopBuildButton ;
  @private IBOutlet NSTextField * mErrorCountTextField ;
  @private IBOutlet NSTextField * mWarningCountTextField ;
}

- (IBAction) collapseDetailledMessageAction: (id) inSender ;
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

- (OC_GGS_TextSyntaxColoring *) textSyntaxColoring ;

- (void) displayIssueDetailedMessage: (NSString *) inDetailledMessage ;

- (void) triggerLiveCompilation ;

- (BOOL) buildTaskIsRunning ;
@end
