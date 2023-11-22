//----------------------------------------------------------------------------------------------------------------------
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2012, ..., 2014 Pierre Molinaro.
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

#import "OC_GGS_RulerViewForBuildOutput.h"
#import "PMIssueDescriptor.h"
#import "OC_GGS_Document.h"
#import "PMDebug.h"

//----------------------------------------------------------------------------------------------------------------------

//#define DEBUG_MESSAGES

//----------------------------------------------------------------------------------------------------------------------

@implementation OC_GGS_RulerViewForBuildOutput

//----------------------------------------------------------------------------------------------------------------------
//
//       I N I T                                                                                 
//
//----------------------------------------------------------------------------------------------------------------------

- (id) initWithDocument: (OC_GGS_Document *) inDocument {
  self = [super init] ;
  if (self) {
    #ifdef DEBUG_MESSAGES
      NSLog (@"%s", __PRETTY_FUNCTION__) ;
    #endif
    noteObjectAllocation (self) ;
    mDocument = inDocument ;
  // See https://developer.apple.com/forums/thread/739492
  //    self.clipsToBounds = YES ;
  }
  return self;
}

//----------------------------------------------------------------------------------------------------------------------

- (void) dealloc {
  noteObjectDeallocation (self) ;
}

//----------------------------------------------------------------------------------------------------------------------

- (void) setIssueArray: (NSArray *) inIssueArray {
  mIssueArray = inIssueArray.copy ;
  [self setNeedsDisplay:YES] ;
}

//----------------------------------------------------------------------------------------------------------------------

- (void) drawHashMarksAndLabelsInRect: (NSRect) inRect {
  const NSRect viewBounds = [self bounds] ;
//--- Draw background
  [[NSColor windowBackgroundColor] setFill] ;
  [NSBezierPath fillRect: viewBounds] ;
//--- Draw right border
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
        drawInRect: rImage
        fromRect: NSZeroRect
        operation: NSCompositeSourceOver
        fraction: 1.0
      ] ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

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
          displaySourceWithURL:issue.issueStandardizedURL
          atLine:issue.issueLine
        ] ;
      }
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

- (void) detach {
  mDocument = nil ;
}

//----------------------------------------------------------------------------------------------------------------------

@end
