//---------------------------------------------------------------------------*
//                                                                           *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2001, ..., 2009 Pierre Molinaro.                           *
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

#import "OC_GGS_RulerViewForCompileMessageView.h"
#import "PMCocoaCallsDebug.h"
#import "OC_GGS_Document.h"
#import "OC_GGS_ErrorOrWarningDescriptor.h"

//---------------------------------------------------------------------------*

//#define DEBUG_MESSAGES

//---------------------------------------------------------------------------*

@implementation OC_GGS_RulerViewForCompileMessageView

//---------------------------------------------------------------------------*

- (id) initWithDocument: (OC_GGS_Document *) inDocument {
  self = [super init] ;
  if (self) {
    mDocument = inDocument ;
  }
  return self ;
}

//---------------------------------------------------------------------------*

- (void) refresh {
  [self setNeedsDisplay:YES] ;
}

//---------------------------------------------------------------------------*

- (NSRect) rectForDescriptor: (OC_GGS_ErrorOrWarningDescriptor *) inDescriptor {
//--- Note: ruler view and text view are both flipped
  NSScrollView * scrollView = [self scrollView] ;
  NSTextView * textView = [scrollView documentView] ;
  NSLayoutManager * lm = [textView layoutManager] ;
  const NSRange range = [inDescriptor rangeInCompileMessageText] ;
  const NSRect rStart = [lm lineFragmentUsedRectForGlyphAtIndex:range.location effectiveRange:NULL] ;
  const NSPoint pStart = [self convertPoint:NSMakePoint (0.0f, NSMinY (rStart)) fromView:textView] ;
  const NSRect rEnd = [lm lineFragmentUsedRectForGlyphAtIndex:range.location + range.length - 1 effectiveRange:NULL] ;
  const NSPoint pEnd = [self convertPoint:NSMakePoint (0.0f, NSMaxY (rEnd)) fromView:textView] ;
  const NSRect viewBounds = [self bounds] ;
  NSRect r ;
  r.origin.x = 0.0f ;
  r.size.width = viewBounds.size.width - 1.0f ;
  r.origin.y = pStart.y ;
  r.size.height = pEnd.y - pStart.y ;
  return r ;
}

//---------------------------------------------------------------------------*

- (void) mouseDown: (NSEvent *) inEvent {
  // NSLog (@"%s, [inEvent clickCount] %d", __PRETTY_FUNCTION__, [inEvent clickCount]) ;
  const NSPoint eventLocation = [inEvent locationInWindow];
  const NSPoint localPoint = [self convertPoint:eventLocation fromView:nil];
  BOOL found = NO ;
  NSUInteger i ;
  NSArray * warningArray = [mDocument warningDescriptorArray] ;
  for (i=0 ; (i<[warningArray count]) && ! found ; i++) {
    OC_GGS_ErrorOrWarningDescriptor * descriptor = [warningArray objectAtIndex:i HERE OFCLASS (OC_GGS_ErrorOrWarningDescriptor)] ;
    const NSRect r = [self rectForDescriptor:descriptor] ;
    if (NSPointInRect (localPoint, r)) {
      [mDocument showWarningAtIndex:i display:[inEvent clickCount] > 1] ;
      found = YES ;
    }
  }
  NSArray * errorArray = [mDocument errorDescriptorArray] ;
  for (i=0 ; (i<[errorArray count]) && ! found ; i++) {
    OC_GGS_ErrorOrWarningDescriptor * descriptor = [errorArray objectAtIndex:i HERE OFCLASS (OC_GGS_ErrorOrWarningDescriptor)] ;
    const NSRect r = [self rectForDescriptor:descriptor] ;
    if (NSPointInRect (localPoint, r)) {
      [mDocument showErrorAtIndex:i display:[inEvent clickCount] > 1] ;
      found = YES ;
    }
  }
}

//---------------------------------------------------------------------------*

- (void) drawHashMarksAndLabelsInRect: (NSRect) inRect {
  #ifdef DEBUG_MESSAGES
    NSLog (@"OC_GGS_RulerViewForCompileMessageView <drawHashMarksAndLabelsInRect:>") ;
  #endif
//--- Draw background
  [[NSColor whiteColor] setFill] ;
  [NSBezierPath fillRect:inRect] ;
//--- Draw right border
  const NSRect viewBounds = [self bounds] ;
  const NSPoint p1 = {viewBounds.size.width, 0.0f} ;
  const NSPoint p2 = {viewBounds.size.width, viewBounds.size.height} ;
  [NSBezierPath strokeLineFromPoint:p1 toPoint:p2] ;
//--- Set draw text attributes and find point size
  NSFont * font = [NSFont fontWithName:@"Courier-Bold" size:14.0f] ;
  NSDictionary * attributesForWarning = [NSDictionary dictionaryWithObjectsAndKeys:
    font, NSFontAttributeName,
    [NSColor orangeColor], NSForegroundColorAttributeName,
    nil
  ] ;
  NSDictionary * attributesForError = [NSDictionary dictionaryWithObjectsAndKeys:
    font, NSFontAttributeName,
    [NSColor redColor], NSForegroundColorAttributeName,
    nil
  ] ;
//--- Display warning knobs
  const NSUInteger currentWarning = [mDocument currentWarning] ;
  NSArray * warningArray = [mDocument warningDescriptorArray] ;
  NSUInteger i ;
  for (i=0 ; i<[warningArray count] ; i++) {
    OC_GGS_ErrorOrWarningDescriptor * descriptor = [warningArray objectAtIndex:i HERE OFCLASS (OC_GGS_ErrorOrWarningDescriptor)] ;
    const NSRect r = [self rectForDescriptor:descriptor] ;
    NSString * s = [NSString stringWithFormat:@"%u", [descriptor index] + 1] ;
    const NSSize size = [s sizeWithAttributes:attributesForError] ;
    const NSPoint p = {
      r.origin.x + (r.size.width - size.width) / 2.0f,
      r.origin.y + (r.size.height - size.height) / 2.0f
    } ;
    if (currentWarning == i) {
      [[NSColor colorWithDeviceWhite: 0.8f alpha: 1.0f] setFill] ;
    }else{
      [[NSColor colorWithDeviceWhite: 0.9f alpha: 1.0f] setFill] ;
    }
    [NSBezierPath fillRect:r] ;
    [NSBezierPath setDefaultLineWidth:1.0f] ;
    [[NSColor orangeColor] setStroke] ;
    [NSBezierPath strokeRect:r] ;
    [s drawAtPoint:p withAttributes:attributesForWarning] ;
  }
//--- Display error knobs
  const NSUInteger currentError = [mDocument currentError] ;
  NSArray * errorArray = [mDocument errorDescriptorArray] ;
  for (i=0 ; i<[errorArray count] ; i++) {
    OC_GGS_ErrorOrWarningDescriptor * descriptor = [errorArray objectAtIndex:i HERE OFCLASS (OC_GGS_ErrorOrWarningDescriptor)] ;
    const NSRect r = [self rectForDescriptor:descriptor] ;
    NSString * s = [NSString stringWithFormat:@"%u", [descriptor index] + 1] ;
    const NSSize size = [s sizeWithAttributes:attributesForError] ;
    const NSPoint p = {
      r.origin.x + (r.size.width - size.width) / 2.0f,
      r.origin.y + (r.size.height - size.height) / 2.0f
    } ;
    if (currentError == i) {
      [[NSColor colorWithDeviceWhite: 0.8f alpha: 1.0f] setFill] ;
    }else{
      [[NSColor colorWithDeviceWhite: 0.9f alpha: 1.0f] setFill] ;
    }
    [NSBezierPath fillRect:r] ;
    [NSBezierPath setDefaultLineWidth:1.0f] ;
    [[NSColor redColor] setStroke] ;
    [NSBezierPath strokeRect:r] ;
    [s drawAtPoint:p withAttributes:attributesForError] ;
  }
  
  /* BOOL maxYreached = NO ;
  while ((idx < sourceStringLength) && ! maxYreached) {
    line ++ ;
  //--- Draw line numbers
    // NSLog (@"%u is valid glyph index: %@", idx, [lm isValidGlyphIndex:idx] ? @"yes" : @"no") ;
    const NSRect r = [lm lineFragmentUsedRectForGlyphAtIndex:idx effectiveRange:NULL] ;
    NSPoint p = [self convertPoint:NSMakePoint (0.0f, NSMinY (r)) fromView:textView] ;
    // NSLog (@"%f for line %u (%@)", p.y, line, ((inRect.origin.y - [font ascender])) ? @"yes" : @"no") ;
    if (p.y >= minYforDrawing) { 
      NSString * str = [NSString stringWithFormat:@"%u", line] ;
      const NSSize strSize = [str sizeWithAttributes:attributes] ;
      p.x = viewBounds.size.width - 2.0f - strSize.width ;
      [str drawAtPoint:p withAttributes:attributes] ;
      maxYreached = p.y > maxYforDrawing ;
    }
  //---
    const NSRange lineRange = [sourceString lineRangeForRange:NSMakeRange (idx, 1)] ;
    // NSLog (@"New line range: [%u, %u] for idx %u", lineRange.location, lineRange.length, idx) ;
    idx = lineRange.location + lineRange.length ;
  }
   */
  #ifdef DEBUG_MESSAGES
    NSLog (@"OC_GGS_RulerViewForCompileMessageView <drawHashMarksAndLabelsInRect:> DONE") ;
  #endif
}

//---------------------------------------------------------------------------*

@end
