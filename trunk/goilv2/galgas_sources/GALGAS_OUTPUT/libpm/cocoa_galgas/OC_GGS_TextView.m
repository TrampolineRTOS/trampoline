//
//  OC_GGS_TextView.m
//  galgas-developer
//
//  Created by Pierre Molinaro on 27/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//
//-----------------------------------------------------------------------------*

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

//-----------------------------------------------------------------------------*

//#define DEBUG_MESSAGES

//-----------------------------------------------------------------------------*

@implementation OC_GGS_TextView

//-----------------------------------------------------------------------------*
//                                                                             *
//       I N I T                                                             *
//                                                                             *
//-----------------------------------------------------------------------------*

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
  }
  return self;
}

//-----------------------------------------------------------------------------*

- (void) FINALIZE_OR_DEALLOC {
  noteObjectDeallocation (self) ;
  macroSuperFinalize ;
}

//-----------------------------------------------------------------------------*

- (void) detachTextView {
  mDocumentUsedForDisplaying = nil ;
  mDisplayDescriptor = nil ;
}

//-----------------------------------------------------------------------------*

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

//-----------------------------------------------------------------------------*

- (NSColor *) errorHiliteColor {
  return [NSColor colorWithCalibratedRed:1.0 green:0.0 blue:0.0 alpha:0.2] ;
}

//-----------------------------------------------------------------------------*

- (NSColor *) warningHiliteColor {
  return [NSColor colorWithCalibratedRed:1.0 green:0.5 blue:0.0 alpha:0.2] ;
}

//-----------------------------------------------------------------------------*

#define BULLET_SIZE (4.0)

//-----------------------------------------------------------------------------*

- (void) drawRect: (NSRect) inRect {
  [super drawRect:inRect] ;
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

//-----------------------------------------------------------------------------*

#pragma mark Key Down

//-----------------------------------------------------------------------------*

- (void) keyDown: (NSEvent *) inEvent {
  NSString * keys = inEvent.characters ;
  if (keys.length == 0) {
    [super keyDown:inEvent] ;
  }else{
    const unichar c = [keys characterAtIndex:0] ;
    // NSLog (@"%d", c) ;
    switch (c) {
    case 9 : // A Tab Character ?
      { const NSRange selectedRange = self.selectedRange ;
        if ((selectedRange.location & 1) !=0) {
          [self insertText:@"  "] ; // Odd location: insert 2 spaces
        }else{
          [self insertText:@" "] ; // Even location: insert 1 space
        }
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

//-----------------------------------------------------------------------------*

#pragma mark Token selection

//-----------------------------------------------------------------------------*

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

//-----------------------------------------------------------------------------*

#pragma mark Source Indexing

//-----------------------------------------------------------------------------*

- (void) selectAllTokenCharacters: (id) inSender  {
  const NSRange r = [[inSender representedObject] rangeValue] ;
  [mDisplayDescriptor setSelectionRangeAndMakeItVisible:r] ;
}

//-----------------------------------------------------------------------------*

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

//-----------------------------------------------------------------------------*

#pragma mark mouse Down (for source indexing)

//-----------------------------------------------------------------------------*

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

//-----------------------------------------------------------------------------*

#pragma mark Autocompletion

//-----------------------------------------------------------------------------*

// http://www.cocoabuilder.com/archive/cocoa/97892-can-select-nstextview-completion-when-partial-word-length-2.html

//-----------------------------------------------------------------------------*

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

//-----------------------------------------------------------------------------*

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

//-----------------------------------------------------------------------------*

@end
