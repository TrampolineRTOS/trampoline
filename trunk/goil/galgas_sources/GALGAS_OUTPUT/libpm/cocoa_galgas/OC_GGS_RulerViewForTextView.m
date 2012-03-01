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
#import "PMErrorOrWarningDescriptor.h"
#import "PMCocoaCallsDebug.h"
#import "PMIssueInRuler.h"
#import "OC_GGS_Document.h"

//---------------------------------------------------------------------------*

//#define DEBUG_MESSAGES

//---------------------------------------------------------------------------*

@implementation OC_GGS_RulerViewForTextView

//---------------------------------------------------------------------------*

- (OC_GGS_RulerViewForTextView *) initWithDocument: (OC_GGS_Document *) inDocument {
  self = [self init] ;
  if (self) {
    mDocument = inDocument ;
  }
  return self ;
}

//---------------------------------------------------------------------------*

static NSUInteger imax (NSUInteger a, NSUInteger b) { return (a > b) ? a : b ; }
static NSUInteger imin (NSUInteger a, NSUInteger b) { return (a < b) ? a : b ; }

//---------------------------------------------------------------------------*

- (void) drawHashMarksAndLabelsInRect: (NSRect) inRect {
  NSMutableArray * issues = [NSMutableArray new] ;
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
//--- Images
  NSImage * errorImage = [NSImage imageNamed:NSImageNameStatusUnavailable] ;
  NSImage * warningImage = [NSImage imageNamed:NSImageNameStatusPartiallyAvailable] ;
//--- Note: ruler view and text view are both flipped
  OC_GGS_TextView * textView = [self.scrollView documentView] ;
  NSArray * issueArray = textView.issueArray ; // Array of PMErrorOrWarningDescriptor
  NSLayoutManager * lm = textView.layoutManager ;
  const NSRange selectedRange = textView.selectedRange ;
  NSString * sourceString = textView.string ;
  const NSUInteger sourceStringLength = sourceString.length ;
  // NSLog (@"sourceStringLength %u", sourceStringLength) ;
  NSUInteger idx = 0 ;
  NSInteger line = 0 ;
  const double minYforDrawing = inRect.origin.y - (2.0 * ([font ascender] + [font descender])) ;
  const double maxYforDrawing = NSMaxY ([self visibleRect]) ;
  BOOL maxYreached = NO ;
  while ((idx < sourceStringLength) && ! maxYreached) {
    line ++ ;
  //--- Draw line numbers
    // NSLog (@"%u is valid glyph index: %@", idx, [lm isValidGlyphIndex:idx] ? @"yes" : @"no") ;
    const NSRect r = [lm lineFragmentUsedRectForGlyphAtIndex:idx effectiveRange:NULL] ;
    NSPoint p = [self convertPoint:NSMakePoint (0.0, NSMinY (r)) fromView:textView] ;
    // NSLog (@"%f for line %u (%@)", p.y, line, ((inRect.origin.y - [font ascender])) ? @"yes" : @"no") ;
    const NSRange lineRange = [sourceString lineRangeForRange:NSMakeRange (idx, 1)] ;
    if (p.y >= minYforDrawing) {
      const BOOL intersect =
        imax (selectedRange.location, lineRange.location)
          <=
        imin (selectedRange.location + selectedRange.length, lineRange.location + lineRange.length)
      ; 
    //--- Draw line number
      NSString * str = [NSString stringWithFormat:@"%ld", line] ;
      const NSSize strSize = [str sizeWithAttributes:intersect ? attributesForSelection : attributes] ;
      p.x = viewBounds.size.width - 2.0 - strSize.width ;
      [str drawAtPoint:p withAttributes:intersect ? attributesForSelection : attributes] ;
      maxYreached = p.y > maxYforDrawing ;
    //--- Error or warning at this line ?
      BOOL hasError = NO ;
      BOOL hasWarning = NO ;
      NSMutableString * allMessages = [NSMutableString stringWithCapacity:100] ;
      for (NSUInteger i=0 ; (i<issueArray.count) ; i++) {
        PMErrorOrWarningDescriptor * issue = [issueArray objectAtIndex:i HERE] ;
        if ([issue isInRange:lineRange]) {
          [allMessages appendFormat:issue.message] ;
          if (issue.isError) {
            hasError = YES ;
          }else{
            hasWarning = YES ;
          }
        }
      }
      if (hasError || hasWarning) {
        const NSRect rImage = {{0.0, p.y}, {16.0, 16.0}} ;
        NSImageRep * imageRep = [hasError ? errorImage : warningImage
          bestRepresentationForRect:rImage
          context:[NSGraphicsContext currentContext]
          hints:nil
        ] ;
        [imageRep drawInRect:rImage] ;
        [issues addObject:
          [[PMIssueInRuler alloc]
            initWithRect:rImage
            message:allMessages
          ]
        ] ;
      }
    }
  //---
    // NSLog (@"New line range: [%u, %u] for idx %u", lineRange.location, lineRange.length, idx) ;
    idx = lineRange.location + lineRange.length ;
  }
//---
  mIssues = issues ;
}

//---------------------------------------------------------------------------*

- (void) mouseDown: (NSEvent *) inEvent {
  const NSPoint localPoint = [self convertPoint:[inEvent locationInWindow] fromView:nil] ;
  PMIssueInRuler * foundIssue = nil ;
  for (NSUInteger i=0 ; (i<mIssues.count) && (nil == foundIssue) ; i++) {
    PMIssueInRuler * issue = [mIssues objectAtIndex:i] ;
    if (NSPointInRect (localPoint, issue.rect)) {
      foundIssue = issue ;
    }
  }
//---
  if (nil != foundIssue) {
    [mDocument displayIssueDetailedMessage:foundIssue.message] ;
  }
}

//---------------------------------------------------------------------------*

@end
