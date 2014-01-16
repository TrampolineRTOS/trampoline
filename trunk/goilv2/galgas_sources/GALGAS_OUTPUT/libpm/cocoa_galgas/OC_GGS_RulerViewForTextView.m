//---------------------------------------------------------------------------*
//                                                                           *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2001, ..., 2013 Pierre Molinaro.                           *
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

#import "OC_GGS_RulerViewForTextView.h"
#import "OC_GGS_TextView.h"
#import "PMIssueDescriptor.h"
#import "PMIssueInRuler.h"
#import "OC_GGS_Document.h"
#import "PMDebug.h"

//---------------------------------------------------------------------------*

//#define DEBUG_MESSAGES

//---------------------------------------------------------------------------*

@implementation OC_GGS_RulerViewForTextView

//---------------------------------------------------------------------------*

- (OC_GGS_RulerViewForTextView *) init {
  self = [super init] ;
  if (self) {
    noteObjectAllocation (self) ;
  }
  return self ;
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

static NSUInteger imax (NSUInteger a, NSUInteger b) { return (a > b) ? a : b ; }
static NSUInteger imin (NSUInteger a, NSUInteger b) { return (a < b) ? a : b ; }

//---------------------------------------------------------------------------*

- (void) drawHashMarksAndLabelsInRect: (NSRect) inRect {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s %p", __PRETTY_FUNCTION__, self) ;
  #endif
//--- Draw background
  [[NSColor windowBackgroundColor] setFill] ;
  [NSBezierPath fillRect:inRect] ;
//--- Draw right border
  const NSRect viewBounds = [self bounds] ;
  const NSPoint p1 = {viewBounds.size.width, 0.0} ;
  const NSPoint p2 = {viewBounds.size.width, viewBounds.size.height} ;
  [NSBezierPath strokeLineFromPoint:p1 toPoint:p2] ;
//--- Set draw text attributes and find point size
  NSFont * font = [NSFont fontWithName:@"Courier" size:11.0] ;
  NSDictionary * attributes = [NSDictionary dictionaryWithObjectsAndKeys:
    font, NSFontAttributeName,
    [NSColor darkGrayColor], NSForegroundColorAttributeName,
    nil
  ] ;
  NSDictionary * attributesForSelection = [NSDictionary dictionaryWithObjectsAndKeys:
    font, NSFontAttributeName,
    [NSColor blackColor], NSForegroundColorAttributeName,
    [NSColor selectedControlColor], NSBackgroundColorAttributeName,
    nil
  ] ;
//--- Note: ruler view and text view are both flipped
  OC_GGS_TextView * textView = self.scrollView.documentView ;
  NSLayoutManager * lm = textView.layoutManager ;
  const NSRange selectedRange = textView.selectedRange ;
  NSString * sourceString = textView.string ;
  const NSUInteger sourceStringLength = sourceString.length ;
//---
  const NSUInteger firstCharacterIndex = [lm
    characterIndexForPoint:textView.visibleRect.origin
    inTextContainer:textView.textContainer
    fractionOfDistanceBetweenInsertionPoints:NULL
  ] ;
//--- Find first line number to draw
  NSUInteger idx = 0 ;
  NSInteger lineIndex = 0 ;
  BOOL found = NO ;
  while ((idx < sourceStringLength) && ! found) {
    lineIndex ++ ;
    const NSRange lineRange = [sourceString lineRangeForRange:NSMakeRange (idx, 0)] ;
    found = (lineRange.location + lineRange.length) > firstCharacterIndex ;
    if (! found) {
      idx = lineRange.location + lineRange.length ;
    }
  }
//---
  const double maxYforDrawing = NSMaxY (self.visibleRect) ;
  BOOL maxYreached = NO ;
  NSMutableArray * bulletArray = [NSMutableArray new] ;
  while ((idx < sourceStringLength) && ! maxYreached) {
    const NSRect r = [lm lineFragmentRectForGlyphAtIndex:idx effectiveRange:NULL] ;
    NSUInteger startIndex = 0 ;
    NSUInteger lineEndIndex = 0 ;
    NSUInteger contentsEndIndex = 0 ;
    [sourceString getLineStart:&startIndex end:&lineEndIndex contentsEnd:&contentsEndIndex forRange:NSMakeRange (idx, 0)] ;
    const BOOL intersect =
      imax (selectedRange.location, startIndex)
        <=
      imin (selectedRange.location + selectedRange.length, contentsEndIndex)
    ; 
  //--- Draw line number
    NSString * str = [NSString stringWithFormat:@"%ld", lineIndex] ;
    const NSSize strSize = [str sizeWithAttributes:intersect ? attributesForSelection : attributes] ;
    NSPoint p = [self convertPoint:NSMakePoint (0.0, NSMaxY (r)) fromView:textView] ;
    p.x = viewBounds.size.width - 2.0 - strSize.width ;
    p.y -= strSize.height ;
    maxYreached = (p.y > maxYforDrawing) ;
    [str drawAtPoint:p withAttributes:intersect ? attributesForSelection : attributes] ;
  //--- Error or warning at this line ?
    BOOL hasError = NO ;
    BOOL hasWarning = NO ;
    NSMutableString * allMessages = [NSMutableString new] ;
    const NSRange lineRange = NSMakeRange (startIndex, lineEndIndex - startIndex) ;
    for (PMIssueDescriptor * issue in mIssueArray) {
      if (NSLocationInRange (issue.locationInSourceString, lineRange) && (issue.locationInSourceStringStatus == kLocationInSourceStringSolved)) {
        [allMessages appendString:issue.issueMessage] ;
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
    idx = lineEndIndex ;
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
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s:DONE", __PRETTY_FUNCTION__) ;
  #endif
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
      const NSRect r = [lm lineFragmentUsedRectForGlyphAtIndex:issue.locationInSourceString effectiveRange:NULL] ;
      const NSPoint p = [self convertPoint:NSMakePoint (0.0, NSMidY (r) - 8.0) fromView:textView] ;
      const NSRect rImage = {{4.0, p.y}, {16.0, 16.0}} ;
      if (NSPointInRect (locationInView, rImage)) {
        found = YES ;
        [issue scrollAndSelectErrorMessage] ;
      }
    }
  }
}

//---------------------------------------------------------------------------*

@end
