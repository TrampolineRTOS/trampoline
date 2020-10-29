//----------------------------------------------------------------------------------------------------------------------
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2001, ..., 2013 Pierre Molinaro.
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

#import "OC_GGS_RulerViewForTextView.h"
#import "OC_GGS_TextView.h"
#import "PMIssueDescriptor.h"
#import "PMIssueInRuler.h"
#import "OC_GGS_Document.h"
#import "PMDebug.h"

//----------------------------------------------------------------------------------------------------------------------

//#define DEBUG_MESSAGES

//----------------------------------------------------------------------------------------------------------------------

@implementation OC_GGS_RulerViewForTextView

//----------------------------------------------------------------------------------------------------------------------

- (OC_GGS_RulerViewForTextView *) init {
  self = [super init] ;
  if (self) {
    noteObjectAllocation (self) ;
  }
  return self ;
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

static NSUInteger imax (NSUInteger a, NSUInteger b) { return (a > b) ? a : b ; }
static NSUInteger imin (NSUInteger a, NSUInteger b) { return (a < b) ? a : b ; }

//----------------------------------------------------------------------------------------------------------------------

- (void) drawHashMarksAndLabelsInRect: (NSRect) inRect {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s %p [%g, %g ; %g, %g]", __PRETTY_FUNCTION__, self, inRect.origin.x, inRect.origin.y, inRect.size.width, inRect.size.height) ;
  #endif
  // NSDate * startDate = [NSDate date] ;
  const NSRect viewBounds = self.bounds ;
//-------- Draw background
  [[NSColor windowBackgroundColor] setFill] ;
  [NSBezierPath fillRect:self.bounds] ;
//-------- Set draw text attributes and find point size
  NSFont * font = [NSFont fontWithName:@"Courier" size:11.0] ;
  NSDictionary * attributes = [NSDictionary dictionaryWithObjectsAndKeys:
    font, NSFontAttributeName,
    [NSColor darkGrayColor], NSForegroundColorAttributeName,
    nil
  ] ;
//-------- Note: ruler view and text view are both flipped
  NSScrollView * __strong scrollView = self.scrollView ;
  OC_GGS_TextView * textView = scrollView.documentView ;
  NSLayoutManager * lm = textView.layoutManager ;
  NSTextContainer * textContainer = textView.textContainer ;
  const NSRange selectedRange = textView.selectedRange ;
  NSString * sourceString = textView.string ;
  const NSUInteger sourceStringLength = sourceString.length ;
//-------- Compute layout
 // [lm ensureLayoutForCharacterRange:NSMakeRange (0, sourceStringLength)] ;
  [lm ensureLayoutForTextContainer:textContainer] ;
//-------- Find the characters that are currently visible
  const NSRange visibleGlyphRange = [lm
    glyphRangeForBoundingRect:scrollView.contentView.bounds
    inTextContainer:textContainer
  ] ;
  const NSRange visibleRange = [lm characterRangeForGlyphRange:visibleGlyphRange actualGlyphRange:NULL] ;
//--- Find first line number to draw
  NSUInteger idx = 0 ;
  NSInteger lineIndex = 1 ;
//---
  BOOL maxYreached = NO ;
  NSMutableArray * bulletArray = [NSMutableArray new] ;
  while ((idx < sourceStringLength) && !maxYreached) {
    const NSRange lineRange = [sourceString lineRangeForRange:NSMakeRange (idx, 0)] ;
    const BOOL isVisible = imax (visibleRange.location, lineRange.location) <= imin (NSMaxRange(visibleRange), NSMaxRange(lineRange)) ;
    maxYreached = lineRange.location > NSMaxRange (visibleRange) ;
    if (isVisible) {
      const NSRect r = [lm lineFragmentRectForGlyphAtIndex:[lm glyphIndexForCharacterAtIndex:lineRange.location] effectiveRange:NULL] ;
      NSPoint p = [self convertPoint:NSMakePoint (0.0, NSMinY (r)) fromView:textView] ;
      const BOOL lineIntersectsSelection =
        imax (selectedRange.location, idx)
          <
        imin (selectedRange.location + selectedRange.length + 1, lineRange.location + lineRange.length)
      ;
    //--- Draw background if line selected
      if (lineIntersectsSelection) {
        const NSRect rBackground = {{0.0, p.y}, {viewBounds.size.width, r.size.height}} ;
        [[NSColor whiteColor] setFill] ;
        [NSBezierPath fillRect:rBackground] ;
      }
    //--- Draw line number
      NSString * str = [NSString stringWithFormat:@"%ld", lineIndex] ;
      const NSSize strSize = [str sizeWithAttributes:attributes] ;
      p.x = viewBounds.size.width - 2.0 - strSize.width ;
      p.y += 1.0 ;
      [str drawAtPoint:p withAttributes:attributes] ;
    //--- Error or warning at this line ?
      BOOL hasError = NO ;
      BOOL hasWarning = NO ;
      NSMutableString * allMessages = [NSMutableString new] ;
      for (PMIssueDescriptor * issue in mIssueArray) {
        if (NSLocationInRange (issue.startLocationInSourceString, lineRange) && (issue.locationInSourceStringStatus == kLocationInSourceStringSolved)) {
          [allMessages appendString:issue.fullMessage] ;
          if (issue.isError) {
            hasError = YES ;
          }else{
            hasWarning = YES ;
          }
        }
      }
      if (hasError || hasWarning) {
        const NSRect rImage = {{0.0, p.y}, {16.0, 16.0}} ;
        PMIssueInRuler * issueInRuler = [[PMIssueInRuler alloc]
          initWithRect:rImage
          message:allMessages
          isError:hasError
        ] ;
        [bulletArray addObject:issueInRuler] ;
      }
    }
    idx = lineRange.location + lineRange.length ;
    lineIndex ++ ;
  }
//--- Images
  NSImage * errorImage = [NSImage imageNamed:NSImageNameStatusUnavailable] ;
  NSImage * warningImage = [NSImage imageNamed:NSImageNameStatusPartiallyAvailable] ;
//---
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s:DISPLAY UNTIL LINE %ld", __PRETTY_FUNCTION__, lineIndex) ;
  #endif
  for (PMIssueInRuler * bullet in bulletArray) {
    [bullet.isError ? errorImage : warningImage
      drawInRect:bullet.rect
      fromRect:NSZeroRect
      operation:NSCompositeSourceOver
      fraction:1.0
    ] ;
  }
//-------- Draw right border
  const NSPoint p1 = {viewBounds.size.width, 0.0} ;
  const NSPoint p2 = {viewBounds.size.width, viewBounds.size.height} ;
  [NSBezierPath strokeLineFromPoint:p1 toPoint:p2] ;
//-------- End
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s:DONE", __PRETTY_FUNCTION__) ;
  #endif
//  NSLog (@"%f", [[NSDate date] timeIntervalSinceDate:startDate]) ;
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
      const NSRect r = [lm lineFragmentUsedRectForGlyphAtIndex:issue.startLocationInSourceString effectiveRange:NULL] ;
      const NSPoint p = [self convertPoint:NSMakePoint (0.0, NSMidY (r) - 8.0) fromView:textView] ;
      const NSRect rImage = {{4.0, p.y}, {16.0, 16.0}} ;
      if (NSPointInRect (locationInView, rImage)) {
        found = YES ;
        [issue scrollAndSelectErrorMessage] ;
      }
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

@end
