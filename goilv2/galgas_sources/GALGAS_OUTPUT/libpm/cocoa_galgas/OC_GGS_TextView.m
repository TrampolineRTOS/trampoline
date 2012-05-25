//
//  OC_GGS_TextView.m
//  galgas-developer
//
//  Created by Pierre Molinaro on 27/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//
//---------------------------------------------------------------------------*

#import "OC_GGS_TextView.h"
#import "PMErrorOrWarningDescriptor.h"
#import "PMCocoaCallsDebug.h"
#import "OC_GGS_TextSyntaxColoring.h"
#import "OC_GGS_TextDisplayDescriptor.h"
#import "OC_Token.h"
#import "OC_GGS_Document.h"
#import "OC_GGS_PreferencesController.h"

//---------------------------------------------------------------------------*

@implementation OC_GGS_TextView

//---------------------------------------------------------------------------*

- (void) setDisplayDescriptor: (OC_GGS_TextDisplayDescriptor *) inDisplayDescriptor {
  mDisplayDescriptor = inDisplayDescriptor ;
}

//---------------------------------------------------------------------------*

- (void) setIssueArray: (NSArray *) inIssueArray {
  mIssueArray = inIssueArray.copy ;
//--- Tell ruler to refresh
  NSScrollView * scrollView = (NSScrollView *) self.superview.superview ;
  // NSLog (@"scrollView %@", scrollView) ;
  NSRulerView * ruler = scrollView.verticalRulerView ;
  // NSLog (@"ruler %@", ruler) ;
  [ruler setNeedsDisplay:YES] ;
  [self setNeedsDisplay:YES] ;
  [scrollView.verticalScroller setNeedsDisplay:YES] ;
}

//---------------------------------------------------------------------------*

- (NSArray *) issueArray {
  return mIssueArray ;
}

//---------------------------------------------------------------------------*

- (NSColor *) errorHiliteColor {
  return [NSColor colorWithCalibratedRed:1.0 green:0.0 blue:0.0 alpha:0.2] ;
}

//---------------------------------------------------------------------------*

- (NSColor *) warningHiliteColor {
  return [NSColor colorWithCalibratedRed:1.0 green:0.5 blue:0.0 alpha:0.2] ;
}

//---------------------------------------------------------------------------*

#define BULLET_SIZE (4.0)

//---------------------------------------------------------------------------*

- (void) drawRect: (NSRect) inRect {
  [super drawRect:inRect] ;
//--- Draw issues
  NSBezierPath * errorHiliteBezierPath = [NSBezierPath bezierPath] ;
  NSBezierPath * errorBulletBezierPath = [NSBezierPath bezierPath] ;
  NSBezierPath * warningHiliteBezierPath = [NSBezierPath bezierPath] ;
  NSBezierPath * warningBulletBezierPath = [NSBezierPath bezierPath] ;
  for (PMErrorOrWarningDescriptor * issue in mIssueArray) {
    // NSLog (@"lineRange [%u, %u]", lineRange.location, lineRange.length) ;
    NSRect lineRect = [self.layoutManager lineFragmentUsedRectForGlyphAtIndex:issue.location effectiveRange:NULL] ;
    lineRect.size.width = self.visibleRect.size.width ;
    // NSLog (@"r1 {{%g, %g}, {%g, %g}}", r1.origin.x, r1.origin.y, r1.size.width, r1.size.height) ;
    [issue.isError ? errorHiliteBezierPath : warningHiliteBezierPath appendBezierPathWithRect:lineRect] ;
    const NSPoint p1 = [self.layoutManager locationForGlyphAtIndex:issue.location] ;
    const NSPoint p2 = [self.layoutManager locationForGlyphAtIndex:issue.location + 1] ;
    // NSLog (@"p: %g, %g", p.x, p.y) ;
    const NSRect r = {{(p1.x + p2.x) / 2.0 - BULLET_SIZE / 2.0, lineRect.origin.y + lineRect.size.height - BULLET_SIZE / 2.0}, {BULLET_SIZE, BULLET_SIZE}} ;
    [issue.isError ? errorBulletBezierPath : warningBulletBezierPath appendBezierPathWithOvalInRect:r] ;
  }
//--- Draw warning hilite
  [[self warningHiliteColor] setFill] ;
  [warningHiliteBezierPath fill] ;
//--- Draw error hilite
  [[self errorHiliteColor] setFill] ;
  [errorHiliteBezierPath fill] ;
//--- Draw warning bullets
  [[NSColor orangeColor] setFill] ;
  [warningBulletBezierPath fill] ;
//--- Draw error bullets
  [[NSColor redColor] setFill] ;
  [errorBulletBezierPath fill] ;
}

//---------------------------------------------------------------------------*

#pragma mark Key Down

//---------------------------------------------------------------------------*

- (void) keyDown:(NSEvent *) inEvent {
  NSString * keys = [inEvent characters];
  if ([keys isEqualToString:@"\x09"]) { // A Tab Character ?
    const NSRange selectedRange = [self selectedRange] ;
    if ((selectedRange.location & 1) !=0) {
      [self insertText:@"  "] ; // Odd location: insert 2 spaces
    }else{
      [self insertText:@" "] ; // Even location: insert 1 space
    }
  }else if ([keys isEqualToString:@"\x0D"]) { // A Carriage Return Character ?
    const NSRange selectedRange = [self selectedRange] ;
    NSString * s = [[self textStorage] string] ;
    NSRange currentLineRange = [s lineRangeForRange:selectedRange] ;
  //--- Find the number of spaces at the beginning of the line
    if (currentLineRange.length > selectedRange.location - currentLineRange.location) {
      currentLineRange.length = selectedRange.location - currentLineRange.location ;
    }
  //--- Insert string
    NSMutableString * stringToInsert = [NSMutableString new] ;
    [stringToInsert appendString:@"\n"] ;
    while ((currentLineRange.length > 0) && ([s characterAtIndex:currentLineRange.location] == ' ')) {
      currentLineRange.location ++ ;
      currentLineRange.length -- ;
      [stringToInsert appendString:@" "] ;
    }
    [self insertText:stringToInsert] ;
  }else{
    [super keyDown:inEvent] ;
  }
}

//---------------------------------------------------------------------------*

#pragma mark Token selection

//---------------------------------------------------------------------------*

- (NSRange) selectionRangeForProposedRange:(NSRange) inProposedSelRange
            granularity: (NSSelectionGranularity) inGranularity {

  NSRange result = inProposedSelRange ;
  if ((inGranularity == NSSelectByWord) && (inProposedSelRange.length == 0)) {
    // NSLog (@"inProposedSelRange: [%u, %u], granularity: %d", inProposedSelRange.location, inProposedSelRange.length, inGranularity) ;
    OC_GGS_TextSyntaxColoring * dsc = [mDisplayDescriptor textSyntaxColoring] ;
    NSArray * tokenArray = [dsc tokenArray] ;
    BOOL found = NO ;
    for (NSUInteger i=0 ; (i<[tokenArray count]) && ! found ; i++) {
      OC_Token * token = [tokenArray objectAtIndex:i HERE] ;
      const NSRange range = [token range] ;
      found = ((range.location + range.length) > inProposedSelRange.location) && (range.location <= inProposedSelRange.location) ;
      if (found) {
        if ([dsc selectionByWordSelectsAllCharactersForTokenIndex:[token tokenCode]]) {
          result = range ;
        }else{
          const NSUInteger modifierFlags = [[NSApp currentEvent] modifierFlags] ;
          const BOOL altAndCmdOn = ((modifierFlags & NSCommandKeyMask) != 0) && ((modifierFlags & NSAlternateKeyMask) != 0) ;
          if (altAndCmdOn) {
            result = range ;
          }else{
            result = [super selectionRangeForProposedRange:inProposedSelRange granularity:inGranularity] ;
          }
        }
      }
    }
    if (! found) {
      result = [super selectionRangeForProposedRange:inProposedSelRange granularity:inGranularity] ;
    }
  }else{
    result = [super selectionRangeForProposedRange:inProposedSelRange granularity:inGranularity] ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

#pragma mark Source Indexing

//---------------------------------------------------------------------------*

- (void) selectAllTokenCharacters: (id) inSender  {
  const NSRange r = [[inSender representedObject] rangeValue] ;
  [mDisplayDescriptor setSelectionRangeAndMakeItVisible:r] ;
}

//---------------------------------------------------------------------------*

- (void) indexingMenuAction: (id) inSender {
  NSString * descriptor = [inSender representedObject] ;
  // NSLog (@"descriptor '%@'", descriptor) ;
  NSArray * components = [descriptor componentsSeparatedByString:@":"] ;
  const NSUInteger tokenLocation = [[components objectAtIndex:2] integerValue] ;
  const NSUInteger tokenLength = [[components objectAtIndex:3] integerValue] ;
  NSString * filePath = [components objectAtIndex:4] ;
  OC_GGS_TextDisplayDescriptor * tdd = [mDisplayDescriptor.document findOrAddNewTabForFile:filePath] ;
  [tdd setSelectionRangeAndMakeItVisible:NSMakeRange (tokenLocation, tokenLength)] ;
}

//---------------------------------------------------------------------------*

#pragma mark mouse Down (for source indexing)

//---------------------------------------------------------------------------*

- (void) mouseDown:(NSEvent *) inEvent {
  if ((inEvent.modifierFlags & NSCommandKeyMask) != 0) {
    const NSPoint local_point = [self convertPoint:[inEvent locationInWindow] fromView:nil] ;
    const NSUInteger characterIndex = [self characterIndexForInsertionAtPoint:local_point] ;
    const NSRange selectedRange = {characterIndex, 0} ;
    const NSRange r = [self selectionRangeForProposedRange:selectedRange granularity:NSSelectByWord] ;
    [self setSelectedRange:r] ;
    OC_GGS_TextSyntaxColoring * dsc = [mDisplayDescriptor textSyntaxColoring] ;
    NSMenu * menu = [dsc indexMenuForRange:r textDisplayDescriptor:mDisplayDescriptor] ;
    [NSMenu
      popUpContextMenu:menu
      withEvent:inEvent
      forView:self
      withFont:[NSFont systemFontOfSize:[NSFont smallSystemFontSize]]
    ] ;
  }else{
    [super mouseDown:inEvent] ;
  }
}

//---------------------------------------------------------------------------*

@end
