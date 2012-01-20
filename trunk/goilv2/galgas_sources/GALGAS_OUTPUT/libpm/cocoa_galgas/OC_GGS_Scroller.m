//
//  OC_GGS_Scroller.m
//  galgas-developer
//
//  Created by Pierre Molinaro on 27/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//
//---------------------------------------------------------------------------*

#import "OC_GGS_Scroller.h"
#import "OC_GGS_TextView.h"
#import "PMErrorOrWarningDescriptor.h"
#import "PMCocoaCallsDebug.h"

//---------------------------------------------------------------------------*

@implementation OC_GGS_Scroller

//---------------------------------------------------------------------------*

- (void) drawRect:(NSRect) inRect {
  [super drawRect:inRect] ;
//---
  const NSRect viewBounds = self.bounds ;
//  NSLog (@"viewBounds %g, %g, %g, %g", viewBounds.origin.x, viewBounds.origin.y, viewBounds.size.width, viewBounds.size.height) ;
  NSScrollView * scrollView = (NSScrollView *) self.superview ;
  // NSLog (@"scrollView %@", scrollView) ;
  OC_GGS_TextView * textView = scrollView.documentView ;
  const NSRect textBounds = textView.bounds ;
//  NSLog (@"textBounds %g, %g, %g, %g", textBounds.origin.x, textBounds.origin.y, textBounds.size.width, textBounds.size.height) ;
  // NSLog (@"textView %@", textView) ;
  NSArray * issueArray = textView.issueArray ;
  NSLayoutManager * lm = textView.layoutManager ;
  NSString * sourceString = textView.string ;
  const NSUInteger sourceStringLength = sourceString.length ;
  NSUInteger idx = 0 ;
  while (idx < sourceStringLength) {
    const NSRange lineRange = [sourceString lineRangeForRange:NSMakeRange (idx, 1)] ;
  //--- Error or warning at this line ?
    BOOL hasError = NO ;
    BOOL hasWarning = NO ;
    for (NSUInteger i=0 ; (i<issueArray.count) && ! hasError ; i++) {
      PMErrorOrWarningDescriptor * issue = [issueArray objectAtIndex:i HERE] ;
      if ([issue isInRange:lineRange]) {
        hasError = issue.isError ;
        if (! issue.isError) {
          hasWarning = YES ;
        }
      }
    }
    if (hasError || hasWarning) {
      const NSRect r = [lm lineFragmentUsedRectForGlyphAtIndex:idx effectiveRange:NULL] ;
      const double y = NSMidY (r) * viewBounds.size.height / textBounds.size.height ;
      NSBezierPath * bp = [NSBezierPath bezierPath] ;
      [bp moveToPoint:NSMakePoint (0.0, y)] ;
      [bp lineToPoint:NSMakePoint (viewBounds.size.width, y)] ;
      [bp setLineWidth:1.0] ;
      [hasError ? [NSColor redColor] : [NSColor orangeColor] setStroke] ;
      [bp stroke] ;
    }
  //---
    // NSLog (@"New line range: [%u, %u] for idx %u", lineRange.location, lineRange.length, idx) ;
    idx = lineRange.location + lineRange.length ;
  }
}

//---------------------------------------------------------------------------*

- (void) setDoubleValue: (double) inValue {
  [super setDoubleValue:inValue] ;
  [self setNeedsDisplay] ;
}

//---------------------------------------------------------------------------*

- (void) setKnobProportion: (CGFloat) inValue {
  [super setKnobProportion:inValue] ;
  [self setNeedsDisplay] ;
}

//---------------------------------------------------------------------------*

@end
