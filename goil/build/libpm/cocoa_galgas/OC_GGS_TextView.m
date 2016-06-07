//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2011, ..., 2014 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes, ECN, École Centrale de Nantes (France)  *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

#import "OC_GGS_TextView.h"
#import "OC_GGS_TextDisplayDescriptor.h"
#import "OC_GGS_RulerViewForTextView.h"
#import "OC_GGS_TextSyntaxColoring.h"
#import "PMIssueDescriptor.h"
#import "OC_Token.h"
#import "OC_GGS_DocumentData.h"
#import "OC_GGS_Document.h"
#import "OC_GGS_ApplicationDelegate.h"
#import "OC_GGS_Scroller.h"
#import "PMDebug.h"

//----------------------------------------------------------------------------------------------------------------------

//#define DEBUG_MESSAGES

//----------------------------------------------------------------------------------------------------------------------

@implementation OC_GGS_TextView

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//       I N I T                                                                                                       *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

- (id) initWithFrame: (NSRect) inFrame
       documentUsedForDisplaying: (OC_GGS_Document *) inDocumentUsedForDisplaying
       displayDescriptor: (OC_GGS_TextDisplayDescriptor *) inDisplayDescriptor {
  self = [super initWithFrame:inFrame] ;
  if (self) {
    #ifdef DEBUG_MESSAGES
      NSLog (@"%s", __PRETTY_FUNCTION__) ;
    #endif
    noteObjectAllocation (self) ;
    mDocumentUsedForDisplaying = inDocumentUsedForDisplaying ;
    mDisplayDescriptor = inDisplayDescriptor ;
    NSUserDefaults * df = [NSUserDefaults standardUserDefaults] ;
    [df
      addObserver:self
      forKeyPath:GGS_uses_page_guide
      options:NSKeyValueObservingOptionNew
      context:NULL
    ] ;
    [df
      addObserver:self
      forKeyPath:GGS_page_guide_column
      options:NSKeyValueObservingOptionNew
      context:NULL
    ] ;
    [df
      addObserver:self
      forKeyPath:GGS_editor_background_color
      options:NSKeyValueObservingOptionNew
      context:NULL
    ] ;
  }
  return self;
}

//----------------------------------------------------------------------------------------------------------------------

- (void) FINALIZE_OR_DEALLOC {
  NSUserDefaults * df = [NSUserDefaults standardUserDefaults] ;
  [df
    removeObserver:self
    forKeyPath:GGS_uses_page_guide
  ] ;
  [df
    removeObserver:self
    forKeyPath:GGS_page_guide_column
  ] ;
  [df
    removeObserver:self
    forKeyPath:GGS_editor_background_color
  ] ;
  noteObjectDeallocation (self) ;
  macroSuperFinalize ;
}

//----------------------------------------------------------------------------------------------------------------------

- (void) detachTextView {
  mDocumentUsedForDisplaying = nil ;
  mDisplayDescriptor = nil ;
}

//----------------------------------------------------------------------------------------------------------------------

- (void) observeValueForKeyPath:(NSString *) inKeyPath
         ofObject:(id) inObject
         change:(NSDictionary *) inChange
         context:(void *) inContext {
  NSUserDefaults * df = [NSUserDefaults standardUserDefaults] ;
  if ((inObject == df) && [inKeyPath isEqualToString:GGS_uses_page_guide]) {
    [self setNeedsDisplay:YES] ;
  }else if ((inObject == df) && [inKeyPath isEqualToString:GGS_page_guide_column]) {
    [self setNeedsDisplay:YES] ;
  }else if ((inObject == df) && [inKeyPath isEqualToString:GGS_editor_background_color]) {
    [self setNeedsDisplay:YES] ;
  }else{
    [super
      observeValueForKeyPath:inKeyPath
      ofObject:inObject
      change:inChange
      context:inContext
    ] ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

- (void) setIssueArray: (NSArray *) inIssueArray {
//--- Tell ruler to refresh
  NSScrollView * scrollView = (NSScrollView *) self.superview.superview ;
  OC_GGS_RulerViewForTextView * ruler = (OC_GGS_RulerViewForTextView *) scrollView.verticalRulerView ;
  [ruler setIssueArray:inIssueArray] ;
//---
  OC_GGS_Scroller * scroller = (OC_GGS_Scroller *) scrollView.verticalScroller ;
  [scroller setIssueArray:inIssueArray] ;
//---
  mIssueArray = inIssueArray.copy ;
  [self setNeedsDisplay:YES] ;
}

//----------------------------------------------------------------------------------------------------------------------

- (NSColor *) errorHiliteColor {
  return [NSColor colorWithCalibratedRed:1.0 green:0.0 blue:0.0 alpha:0.2F] ;
}

//----------------------------------------------------------------------------------------------------------------------

- (NSColor *) warningHiliteColor {
  return [NSColor colorWithCalibratedRed:1.0 green:0.5 blue:0.0 alpha:0.2F] ;
}

//----------------------------------------------------------------------------------------------------------------------

#define BULLET_SIZE (4.0)

//----------------------------------------------------------------------------------------------------------------------

- (void) drawRect: (NSRect) inRect {
  // NSLog (@"%s", __PRETTY_FUNCTION__) ;
//--- Draw page guide
  NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
  if ([ud boolForKey:GGS_uses_page_guide] && (self.string.length > 0)) {
    NSDictionary * attributes = [self.textStorage fontAttributesInRange:NSMakeRange(0, 0)] ;
    const NSInteger pageGuideColumn = [ud integerForKey:GGS_page_guide_column] ;
    NSMutableString * str = [NSMutableString new] ;
    for (NSInteger i=0 ; i<=pageGuideColumn ; i++) {
      [str appendString:@"0"] ;
    }
    const NSSize s = [str sizeWithAttributes:attributes] ;
    const double column = rint (s.width) + 0.5 ;
  //--- Page rect
    const NSRect pageRect = {{0.0, 0.0}, {column, NSMaxY (self.frame)}} ;
    const NSRect pageRectToDraw = NSIntersectionRect (inRect, pageRect) ;
    if (! NSIsEmptyRect (pageRectToDraw)) {
      NSData * data = [[NSUserDefaults standardUserDefaults] valueForKey:GGS_editor_background_color] ;
      // NSLog (@"DATA %@", data) ;
      NSColor * color = [NSUnarchiver unarchiveObjectWithData:data] ;
      // NSLog (@"color %@", color) ;
      [color setFill] ;
      NSRectFill (pageRectToDraw) ;
    }
    const NSRect outsidePageRect = {{column, 0.0}, {NSMaxX (self.frame) - column, NSMaxY (self.frame)}} ;
    const NSRect outsidePageRectToDraw = NSIntersectionRect (inRect, outsidePageRect) ;
    if (! NSIsEmptyRect (outsidePageRectToDraw)) {
      [[NSColor windowBackgroundColor] setFill] ;
      NSRectFill (outsidePageRectToDraw) ;
    }
    NSBezierPath * bp = [NSBezierPath bezierPath] ;
    [bp moveToPoint:NSMakePoint (column, NSMinY (inRect))] ;
    [bp lineToPoint:NSMakePoint (column, NSMaxY (inRect))] ;
    [bp setLineWidth:0.0] ;
    [[NSColor windowFrameColor] setStroke] ;
    [bp stroke] ;
  }
//--- Draw text
  // NSDate * startDate = [NSDate date] ;
  [super drawRect:inRect] ;
  // NSLog (@"%f", [[NSDate date] timeIntervalSinceDate:startDate]) ;
//--- Draw issues
  NSBezierPath * errorHiliteBezierPath = [NSBezierPath bezierPath] ;
  NSBezierPath * errorBulletBezierPath = [NSBezierPath bezierPath] ;
  NSBezierPath * warningHiliteBezierPath = [NSBezierPath bezierPath] ;
  NSBezierPath * warningBulletBezierPath = [NSBezierPath bezierPath] ;
  for (PMIssueDescriptor * issue in mIssueArray) {
    if (issue.locationInSourceStringStatus == kLocationInSourceStringSolved) {
      // NSLog (@"lineRange [%u, %u]", lineRange.location, lineRange.length) ;
      NSRect lineRect = [self.layoutManager lineFragmentUsedRectForGlyphAtIndex:issue.locationInSourceString effectiveRange:NULL] ;
      lineRect.size.width = self.visibleRect.size.width ;
      // NSLog (@"r1 {{%g, %g}, {%g, %g}}", r1.origin.x, r1.origin.y, r1.size.width, r1.size.height) ;
      [issue.isError ? errorHiliteBezierPath : warningHiliteBezierPath appendBezierPathWithRect:lineRect] ;
      const NSPoint p1 = [self.layoutManager locationForGlyphAtIndex:issue.locationInSourceString] ;
      const NSRect r = {{p1.x - BULLET_SIZE / 2.0, lineRect.origin.y + lineRect.size.height - BULLET_SIZE}, {BULLET_SIZE, BULLET_SIZE}} ;
      [issue.isError ? errorBulletBezierPath : warningBulletBezierPath appendBezierPathWithOvalInRect:r] ;
    }
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

//----------------------------------------------------------------------------------------------------------------------

#pragma mark Key Down

//----------------------------------------------------------------------------------------------------------------------

- (void) keyDown: (NSEvent *) inEvent {
  NSString * keys = inEvent.characters ;
  if (keys.length == 0) {
    [super keyDown:inEvent] ;
  }else{
    const unichar c = [keys characterAtIndex:0] ;
    switch (c) {
    case 9 : // A Tab Character ?
      { const NSRange selectedRange = self.selectedRange ;
        const NSInteger alignment = [[NSUserDefaults standardUserDefaults] integerForKey:GGS_editor_space_for_tab] ;
        NSInteger spacesToInsert = alignment - ((NSInteger) selectedRange.location) % alignment ;
        NSInteger characterAfterSelection = (NSInteger) (selectedRange.location + selectedRange.length) ;
        while ((spacesToInsert > 0)
            && (characterAfterSelection < (NSInteger) self.string.length)
            && ([self.string characterAtIndex:(NSUInteger)characterAfterSelection] == ' ')) {
          characterAfterSelection ++ ;
          spacesToInsert -- ;
        }
        if (spacesToInsert == 0) {
          spacesToInsert = alignment ;
        }
        NSMutableString * s = [NSMutableString new] ;
        for (NSInteger i=0 ; i<spacesToInsert ; i++) {
          [s appendString:@" "] ;
        }
        [self insertText:s] ;
      }break ;
    case 13 : // A Carriage Return Character ?
      { const NSRange selectedRange = [self selectedRange] ;
        NSString * s = self.textStorage.string ;
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
      }break ;
    case 127 : // A Back Character ?
    case 63232 : // Up arrow
    case 63233 : // Down arrow
    case 63234 : // Left arrow
    case 63235 : // Right arrow
    case 63272 : // Suppr
    case 63273 : // Home
    case 63275 : // Goto end
    case 63276 : // Page Up
    case 63277 : // Page Down
      [super keyDown:inEvent] ;
      break ;
    default:
      [super keyDown:inEvent] ;
    //--- Perform completion
       if ([[NSUserDefaults standardUserDefaults] boolForKey:GGS_enable_completion]) {
         [self complete:nil] ;
      }
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

#pragma mark Token selection

//----------------------------------------------------------------------------------------------------------------------

- (NSRange) selectionRangeForProposedRange:(NSRange) inProposedSelRange
            granularity: (NSSelectionGranularity) inGranularity {
  // NSLog (@"%s", __PRETTY_FUNCTION__) ;
  NSRange result = inProposedSelRange ;
  if ((inGranularity == NSSelectByWord) && (inProposedSelRange.length == 0)) {
    // NSLog (@"inProposedSelRange: [%u, %u], granularity: %d", inProposedSelRange.location, inProposedSelRange.length, inGranularity) ;
    OC_GGS_TextSyntaxColoring * dsc = mDisplayDescriptor.documentData.textSyntaxColoring ;
    NSArray * tokenArray = [dsc tokenArray] ;
    BOOL found = NO ;
    for (NSUInteger i=0 ; (i<[tokenArray count]) && ! found ; i++) {
      OC_Token * token = [tokenArray objectAtIndex:i] ;
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

//----------------------------------------------------------------------------------------------------------------------

#pragma mark Source Indexing

//----------------------------------------------------------------------------------------------------------------------

- (void) selectAllTokenCharacters: (id) inSender  {
  const NSRange r = [[inSender representedObject] rangeValue] ;
  [mDisplayDescriptor setSelectionRangeAndMakeItVisible:r] ;
}

//----------------------------------------------------------------------------------------------------------------------

- (void) indexingMenuAction: (id) inSender {
  NSString * descriptor = [inSender representedObject] ;
  // NSLog (@"descriptor '%@'", descriptor) ;
  NSArray * components = [descriptor componentsSeparatedByString:@":"] ;
  const NSUInteger tokenLocation = (NSUInteger) [[components objectAtIndex:2] integerValue] ;
  const NSUInteger tokenLength = (NSUInteger) [[components objectAtIndex:3] integerValue] ;
  NSString * filePath = [components objectAtIndex:4] ;
  OC_GGS_TextDisplayDescriptor * tdd = [mDocumentUsedForDisplaying findOrAddNewTabForFile:filePath] ;
  [tdd setSelectionRangeAndMakeItVisible:NSMakeRange (tokenLocation, tokenLength)] ;
}

//----------------------------------------------------------------------------------------------------------------------

#pragma mark mouse Down (for source indexing)

//----------------------------------------------------------------------------------------------------------------------

- (void) mouseDown:(NSEvent *) inEvent {
  if ((inEvent.modifierFlags & NSCommandKeyMask) != 0) {
    const NSPoint local_point = [self convertPoint:[inEvent locationInWindow] fromView:nil] ;
    const NSUInteger characterIndex = [self characterIndexForInsertionAtPoint:local_point] ;
    const NSRange selectedRange = {characterIndex, 0} ;
    const NSRange r = [self selectionRangeForProposedRange:selectedRange granularity:NSSelectByWord] ;
    [self setSelectedRange:r] ;
    OC_GGS_TextSyntaxColoring * dsc = mDisplayDescriptor.documentData.textSyntaxColoring ;
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

//----------------------------------------------------------------------------------------------------------------------

#pragma mark Autocompletion

//----------------------------------------------------------------------------------------------------------------------

// http://www.cocoabuilder.com/archive/cocoa/97892-can-select-nstextview-completion-when-partial-word-length-2.html

//----------------------------------------------------------------------------------------------------------------------

- (NSRange) rangeForUserCompletion {
  NSRange charRange = {NSNotFound, 0} ;
  const NSRange selectedRange = self.selectedRange ;
  if (selectedRange.length == 0) {
    NSArray * tokenArray = mDisplayDescriptor.documentData.textSyntaxColoring.tokenArray ;
    for (OC_Token * token in tokenArray) {
      const NSRange tokenRange = token.range ;
      if ((tokenRange.location < selectedRange.location)
       && ((tokenRange.location + tokenRange.length) == selectedRange.location)) {
        charRange = tokenRange ;
      }
    }
  }
  // NSLog (@"charRange [%ld, %ld]", charRange.location, charRange.length) ;
  return charRange ;
}

//----------------------------------------------------------------------------------------------------------------------

- (NSArray *) completionsForPartialWordRange: (NSRange) inCharRange
              indexOfSelectedItem: (NSInteger *) outIndex {
  * outIndex = -1 ;
  NSMutableSet * completionSet = [NSMutableSet new] ;
//--- Completions from current file tokens
  NSArray * tokenArray = mDisplayDescriptor.documentData.textSyntaxColoring.tokenArray ;
  NSString * sourceString = self.string ;
  NSString * stringToComplete = [sourceString substringWithRange:inCharRange] ;
  const NSRange compareRange = {0, stringToComplete.length} ;
  for (OC_Token * token in tokenArray) {
    NSString * s = [sourceString substringWithRange:token.range] ;
    if (s.length > stringToComplete.length) {
      if ([s compare:stringToComplete options:NSLiteralSearch range:compareRange] == NSOrderedSame) {
        [completionSet addObject:s] ;
      }
    }
  }
//---
  NSArray * dictionaryArray = mDisplayDescriptor.documentData.textSyntaxColoring.buildIndexingDictionaryArray ;
  for (NSDictionary * dict in dictionaryArray) {
    for (NSString * key in dict.allKeys) {
      if (key.length > stringToComplete.length) {
        if ([key compare:stringToComplete options:NSLiteralSearch range:compareRange] == NSOrderedSame) {
          [completionSet addObject:key] ;
        }
      }
    }
  }
//---
  return [completionSet.allObjects sortedArrayUsingSelector:@selector (compare:)] ;
}

//----------------------------------------------------------------------------------------------------------------------

@end
