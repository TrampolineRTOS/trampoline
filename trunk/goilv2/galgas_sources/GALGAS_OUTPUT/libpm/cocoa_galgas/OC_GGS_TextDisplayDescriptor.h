//
//  OC_GGS_TextDisplayDescriptor.h
//  galgas-developer
//
//  Created by Pierre Molinaro on 24/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//
//---------------------------------------------------------------------------*

#import <Foundation/Foundation.h>

//---------------------------------------------------------------------------*

@class OC_GGS_TextSyntaxColoring ;
@class OC_GGS_Document ;
@class OC_GGS_TextView ;
@class PMIssueDescriptor ;
@class OC_GGS_RulerViewForTextView ;
@class OC_GGS_ContextualHelpTask ;

//---------------------------------------------------------------------------*

@interface OC_GGS_TextDisplayDescriptor : NSObject
#if MAC_OS_X_VERSION_MIN_REQUIRED > MAC_OS_X_VERSION_10_5
  <NSTextViewDelegate, NSPortDelegate>
#endif
{

  @private OC_GGS_TextSyntaxColoring * mTextSyntaxColoring ;
  @private OC_GGS_TextView * mTextView ;
  @private OC_GGS_RulerViewForTextView * mRulerView ;
  @private NSScrollView * mScrollView ;
  @private NSUInteger mTextSelectionStart ;
  @private OC_GGS_Document * mDocument ;
  @private NSArray * mIssueArray ;
  @private OC_GGS_ContextualHelpTask * mContextualHelpTask ;
  @private NSMutableSet * mPreviousBuildTasks ;
  @private NSUInteger mTaskIndex ;
}

- (OC_GGS_TextDisplayDescriptor *) initWithDelegateForSyntaxColoring: (OC_GGS_TextSyntaxColoring *) inDelegate
                                   document: (OC_GGS_Document *) inDocument ;

- (void) setSyntaxColoringDelegate: (OC_GGS_TextSyntaxColoring *) inDelegate ;

- (OC_GGS_TextSyntaxColoring *) textSyntaxColoring ;

- (NSURL *) sourceURL ;

- (NSTextView *) textView ;

- (NSScrollView *) scrollView ;

- (OC_GGS_Document *) document ;

- (NSMenu *) menuForEntryPopUpButton ;

- (NSUInteger) textSelectionStart ;

- (void) gotoLine: (NSUInteger) inLine ;

- (void) selectEntryPopUp ;

- (void) populatePopUpButton ;

- (void) commentSelection ;
- (void) uncommentSelection ;
- (void) shiftLeftAction ;
- (void) shiftRightAction ;

- (void) noteUndoManagerCheckPointNotification ;

- (void) setTextDisplayIssueArray: (NSArray *) inIssueArray ; 

- (BOOL) makeVisibleIssue: (PMIssueDescriptor *) inIssue ;

- (void) setSelectionRangeAndMakeItVisible: (NSRange) inRange ;

- (void) noteBuildTaskTermination: (OC_GGS_ContextualHelpTask *) inBuildTask ;

- (void) noteSocketData: (NSData *) inData ;
@end

//---------------------------------------------------------------------------*
