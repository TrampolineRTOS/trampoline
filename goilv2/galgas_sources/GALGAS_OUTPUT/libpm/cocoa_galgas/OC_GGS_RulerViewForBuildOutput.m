//
//  OC_GGS_RulerViewForBuildOutput.m
//  galgas-developer
//
//  Created by Pierre Molinaro on 31/07/12.
//  Copyright (c) 2012 IRCCyN. All rights reserved.
//
//---------------------------------------------------------------------------*

#import "OC_GGS_RulerViewForBuildOutput.h"
#import "PMIssueDescriptor.h"
#import "OC_GGS_Document.h"
#import "PMDebug.h"

//---------------------------------------------------------------------------*

@implementation OC_GGS_RulerViewForBuildOutput

//---------------------------------------------------------------------------*
//                                                                           *
//       I N I T                                                             *
//                                                                           *
//---------------------------------------------------------------------------*

- (id) initWithDocument: (OC_GGS_Document *) inDocument {
  self = [super init] ;
  if (self) {
    #ifdef DEBUG_MESSAGES
      NSLog (@"%s", __PRETTY_FUNCTION__) ;
    #endif
    noteObjectAllocation (self) ;
    mDocument = inDocument ;
  }
  return self;
}

//---------------------------------------------------------------------------*

- (void) FINALIZE_OR_DEALLOC {
  noteObjectDeallocation (self) ;
  macroSuperFinalize ;
}

//---------------------------------------------------------------------------*

- (void) setIssueArray: (NSArray *) inIssueArray {
  mIssueArray = inIssueArray.copy ;
  [self setNeedsDisplay:YES] ;
}

//---------------------------------------------------------------------------*

- (void) drawHashMarksAndLabelsInRect: (NSRect) inRect {
//--- Draw background
  [[NSColor windowBackgroundColor] setFill] ;
  [NSBezierPath fillRect:inRect] ;
//--- Draw right border
  const NSRect viewBounds = [self bounds] ;
  const NSPoint p1 = {viewBounds.size.width, 0.0} ;
  const NSPoint p2 = {viewBounds.size.width, viewBounds.size.height} ;
  [NSBezierPath strokeLineFromPoint:p1 toPoint:p2] ;
//--- Images
  NSImage * errorImage = [NSImage imageNamed:NSImageNameStatusUnavailable] ;
  NSImage * warningImage = [NSImage imageNamed:NSImageNameStatusPartiallyAvailable] ;
//--- Note: ruler view and text view are both flipped
  NSTextView * textView = self.scrollView.documentView ;
  NSLayoutManager * lm = textView.layoutManager ;
//--- Display bullets
  for (PMIssueDescriptor * issue in mIssueArray) {
    if (issue.locationInSourceStringStatus != kLocationInSourceStringInvalid) {
      const NSRect r = [lm lineFragmentUsedRectForGlyphAtIndex:issue.locationInOutputData effectiveRange:NULL] ;
      const NSPoint p = [self convertPoint:NSMakePoint (0.0, NSMidY (r) - 8.0) fromView:textView] ;
      const NSRect rImage = {{4.0, p.y}, {16.0, 16.0}} ;
      [issue.isError ? errorImage : warningImage
        drawInRect:rImage
        fromRect:NSZeroRect
        operation:NSCompositeSourceOver
        fraction:1.0
      ] ;
    }
  }
}

//---------------------------------------------------------------------------*

- (void) mouseDown: (NSEvent *) inMouseDownEvent {
//--- Note: ruler view and text view are both flipped
  NSTextView * textView = self.scrollView.documentView ;
  NSLayoutManager * lm = textView.layoutManager ;
  const NSPoint locationInView = [self convertPoint:inMouseDownEvent.locationInWindow fromView:nil] ;
  BOOL found = NO ;
  for (NSUInteger i=0 ; (i<mIssueArray.count) && ! found ; i++) {
    PMIssueDescriptor * issue = [mIssueArray objectAtIndex:i] ;
    if (issue.locationInSourceStringStatus != kLocationInSourceStringInvalid) {
      const NSRect r = [lm lineFragmentUsedRectForGlyphAtIndex:issue.locationInOutputData effectiveRange:NULL] ;
      const NSPoint p = [self convertPoint:NSMakePoint (0.0, NSMidY (r) - 8.0) fromView:textView] ;
      const NSRect rImage = {{4.0, p.y}, {16.0, 16.0}} ;
      if (NSPointInRect (locationInView, rImage)) {
        found = YES ;
        [mDocument
          displaySourceWithURL:issue.issueURL
          atLine:issue.issueLine
        ] ;
      }
    }
  }
}

//---------------------------------------------------------------------------*

- (void) detach {
  mDocument = nil ;
}

//---------------------------------------------------------------------------*

@end
