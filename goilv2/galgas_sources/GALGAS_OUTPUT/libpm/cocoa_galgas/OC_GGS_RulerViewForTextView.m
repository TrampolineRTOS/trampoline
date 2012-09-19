//---------------------------------------------------------------------------*
//                                                                           *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2001, ..., 2011 Pierre Molinaro.                           *
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

- (void) FINALIZE_OR_DEALLOC {
  noteObjectDeallocation (self) ;
  macroSuperFinalize ;
}

//---------------------------------------------------------------------------*

- (OC_GGS_RulerViewForTextView *) init {
  self = [super init] ;
  if (self) {
    noteObjectAllocation (self) ;
  }
  return self ;
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
  // NSLog (@"sourceStringLength %u", sourceStringLength) ;
  NSUInteger idx = 0 ;
  NSInteger lineIndex = 0 ;
  const double minYforDrawing = inRect.origin.y - (2.0 * ([font ascender] + [font descender])) ;
  const double maxYforDrawing = NSMaxY ([self visibleRect]) ;
  BOOL maxYreached = NO ;
  mBulletArray = [NSMutableArray new] ;
  while ((idx < sourceStringLength) && ! maxYreached) {
    lineIndex ++ ;
  //--- Draw line numbers
    // NSLog (@"%u is valid glyph index: %@", idx, [lm isValidGlyphIndex:idx] ? @"yes" : @"no") ;
    const NSRect r = [lm lineFragmentUsedRectForGlyphAtIndex:idx effectiveRange:NULL] ;
    NSPoint p = [self convertPoint:NSMakePoint (0.0, NSMaxY (r)) fromView:textView] ;
    // NSLog (@"%f for line %u (%@)", p.y, line, ((inRect.origin.y - [font ascender])) ? @"yes" : @"no") ;
    const NSRange lineRange = [sourceString lineRangeForRange:NSMakeRange (idx, 1)] ;
    if (p.y >= minYforDrawing) {
      const BOOL intersect =
        imax (selectedRange.location, lineRange.location)
          <=
        imin (selectedRange.location + selectedRange.length, lineRange.location + lineRange.length)
      ; 
    //--- Draw line number
      NSString * str = [NSString stringWithFormat:@"%ld", lineIndex] ;
      const NSSize strSize = [str sizeWithAttributes:intersect ? attributesForSelection : attributes] ;
      p.x = viewBounds.size.width - 2.0 - strSize.width ;
      p.y -= strSize.height ;
      [str drawAtPoint:p withAttributes:intersect ? attributesForSelection : attributes] ;
      maxYreached = p.y > maxYforDrawing ;
    //--- Error or warning at this line ?
      BOOL hasError = NO ;
      BOOL hasWarning = NO ;
      NSMutableString * allMessages = [NSMutableString stringWithCapacity:100] ;
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
        [mBulletArray addObject:issueInRuler] ;
      }
    }
    idx = lineRange.location + lineRange.length ;
  }
//--- Images
  NSImage * errorImage = [NSImage imageNamed:NSImageNameStatusUnavailable] ;
  NSImage * warningImage = [NSImage imageNamed:NSImageNameStatusPartiallyAvailable] ;
//---
  for (PMIssueInRuler * bullet in mBulletArray) {
    [bullet.isError ? errorImage : warningImage
      drawInRect:bullet.rect
      fromRect:NSZeroRect
      operation:NSCompositeSourceOver
      fraction:1.0
    ] ;
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
