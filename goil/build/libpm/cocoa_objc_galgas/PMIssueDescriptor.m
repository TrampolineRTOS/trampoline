//--------------------------------------------------------------------------------------------------
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2011, ..., 2016 Pierre Molinaro.
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
//--------------------------------------------------------------------------------------------------

#import "PMIssueDescriptor.h"
#import "PMDebug.h"
#import "OC_GGS_RulerViewForBuildOutput.h"
#import "OC_GGS_TextDisplayDescriptor.h"

//--------------------------------------------------------------------------------------------------

@implementation PMIssueDescriptor

//--------------------------------------------------------------------------------------------------

- (void) normalizeMessage {
  while ((mFullMessage.length > 1) && ([mFullMessage characterAtIndex:mFullMessage.length-1] == '\n')) {
    mFullMessage = [mFullMessage substringToIndex:mFullMessage.length-1] ;
  }
  while ((mFullMessage.length > 0) && ([mFullMessage characterAtIndex:0] == '\n')) {
    mFullMessage = [mFullMessage substringFromIndex:1] ;
  }
}

//--------------------------------------------------------------------------------------------------

- (PMIssueDescriptor *) initWithMessage: (NSString *) inMessage
                        URL: (NSURL *) inURL
                        line: (NSInteger) inLine
                        startColumn: (NSInteger) inStartColumn
                        endColumn: (NSInteger) inEndColumn
                        isError: (BOOL) inIsError
                        rangeInOutputData: (NSRange) inRangeInOutputData
                        buildOutputRuler: (OC_GGS_RulerViewForBuildOutput *) inRuler {
  self = [self init] ;
  if (self) {
    noteObjectAllocation (self) ;
    mFullMessage = inMessage.copy ;
    mURL = inURL.standardizedURL ;
    mLine = (NSUInteger) inLine ;
    mStartColumn = (NSUInteger) inStartColumn ;
    mEndColumn = (NSUInteger) inEndColumn ;
    mIsError = inIsError ;
    mRangeInOutputData = inRangeInOutputData ;
    mLocationInSourceStringStatus = kLocationInSourceStringNotSolved ;
    mBuildOutputRuler = inRuler ;
    [self normalizeMessage] ;
  }
  return self ;
}

//--------------------------------------------------------------------------------------------------

- (void) dealloc {
  noteObjectDeallocation (self) ;
}

//--------------------------------------------------------------------------------------------------

- (NSString *) fullMessage {
  return mFullMessage ;
}

//--------------------------------------------------------------------------------------------------

- (NSURL *) issueStandardizedURL {
  return mURL ;
}

//--------------------------------------------------------------------------------------------------

- (BOOL) isError {
  return mIsError ;
}

//--------------------------------------------------------------------------------------------------

- (NSUInteger) issueLine {
  return mLine ;
}

//--------------------------------------------------------------------------------------------------

- (NSUInteger) issueStartColumn {
  return mStartColumn ;
}

//--------------------------------------------------------------------------------------------------

- (NSUInteger) issueEndColumn {
  return mEndColumn ;
}

//--------------------------------------------------------------------------------------------------

- (NSUInteger) locationInOutputData {
  return mRangeInOutputData.location ;
}

//--------------------------------------------------------------------------------------------------

- (enumLocationInSourceStringStatus) locationInSourceStringStatus {
  return mLocationInSourceStringStatus ;
}

//--------------------------------------------------------------------------------------------------

- (NSUInteger) startLocationInSourceString {
  return mStartLocationInSourceString ;
}

//--------------------------------------------------------------------------------------------------

- (NSUInteger) endLocationInSourceString {
  return mEndLocationInSourceString ;
}

//--------------------------------------------------------------------------------------------------

- (void) setStartLocationInSourceString: (NSUInteger) inStartLocationInSourceString
         endLocation: (NSUInteger) inEndLocationInSourceString {
  mStartLocationInSourceString = inStartLocationInSourceString ;
  mEndLocationInSourceString = inEndLocationInSourceString ;
  mLocationInSourceStringStatus = kLocationInSourceStringSolved ;
}

//--------------------------------------------------------------------------------------------------

- (void) updateLocationForPreviousRange: (NSRange) inEditedRange
         changeInLength: (NSInteger) inChangeInLength {
  if (mEndLocationInSourceString >= (inEditedRange.location + inEditedRange.length)) {
    if (inChangeInLength >= 0) {
      mEndLocationInSourceString += (NSUInteger) inChangeInLength ;
    }else{
      mEndLocationInSourceString -= (NSUInteger) -inChangeInLength ;
    }
  }
  if (mStartLocationInSourceString >= (inEditedRange.location + inEditedRange.length)) {
    if (inChangeInLength >= 0) {
      mStartLocationInSourceString += (NSUInteger) inChangeInLength ;
    }else{
      mStartLocationInSourceString -= (NSUInteger) -inChangeInLength ;
    }
  }else if (((NSUInteger) mStartLocationInSourceString) >= inEditedRange.location) {
    mLocationInSourceStringStatus = kLocationInSourceStringInvalid ;
    [mBuildOutputRuler setNeedsDisplay:YES] ;
  }
}

//--------------------------------------------------------------------------------------------------

- (void) detach {
  mBuildOutputRuler = nil ;
}

//--------------------------------------------------------------------------------------------------

- (void) scrollAndSelectErrorMessage {
  NSTextView * errorMessageTextView = mBuildOutputRuler.scrollView.documentView ;
  [errorMessageTextView setSelectedRange:mRangeInOutputData] ;
  [errorMessageTextView scrollRangeToVisible:mRangeInOutputData] ;
}

//--------------------------------------------------------------------------------------------------

- (BOOL) intersectWithRange: (NSRange) inRange {
  BOOL result = mLocationInSourceStringStatus == kLocationInSourceStringSolved ;
  if (result) {
    const NSUInteger start = (mStartLocationInSourceString > inRange.location)
      ? mStartLocationInSourceString
      : inRange.location ;
    const NSUInteger end = (mEndLocationInSourceString < NSMaxRange (inRange))
      ? mEndLocationInSourceString
      : NSMaxRange (inRange) ;
    result = start < end ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

- (void) storeItemsToMenu: (NSMenu *) inMenu
         displayDescriptor: (OC_GGS_TextDisplayDescriptor *) inDisplayDescriptor {
//--- Extract
  NSString * title = @"???" ;
  NSArray * components = [mFullMessage componentsSeparatedByString:@"\n"] ;
  // NSLog (@"%@", components) ;
  if (components.count > 1) {
    NSString * s = [components objectAtIndex:1] ;
    NSArray * c = [s componentsSeparatedByString:@": "] ;
    if (c.count > 1) {
      title = [c objectAtIndex:1] ;
    }
  }
//--- Suggestion Attributes
  NSDictionary * suggestionAttributes = [NSDictionary dictionaryWithObjectsAndKeys:
    [NSColor brownColor], NSForegroundColorAttributeName,
    [NSFont boldSystemFontOfSize:[NSFont smallSystemFontSize]], NSFontAttributeName,
    nil
  ] ;
//--- Title Attributes
  NSDictionary * issueAttributes = [NSDictionary dictionaryWithObjectsAndKeys:
    self.isError ? [NSColor redColor] : [NSColor orangeColor], NSForegroundColorAttributeName,
    [NSFont boldSystemFontOfSize:[NSFont smallSystemFontSize]], NSFontAttributeName,
    nil
  ] ;
//--- Title
  NSAttributedString * as = [[NSAttributedString alloc]
    initWithString:[@"\u27A4 " stringByAppendingString:title] // ➤
    attributes:issueAttributes
  ] ;
  NSMenuItem * menuItem = [[NSMenuItem alloc] initWithTitle:@"" action:NULL keyEquivalent:@""] ;
  menuItem.attributedTitle = as ;
  [inMenu addItem:menuItem] ;
//--- Suggestions
  NSString * ZeroWidthSpace = @"\u200B" ;
  for (NSUInteger i=4 ; i<components.count ; i++) {
    title = [components objectAtIndex:i] ;
    menuItem = nil ;
    if ([title hasPrefix:@"Fix-it, remove"]) {
      const NSRange issueRange = NSMakeRange (
        self.startLocationInSourceString,
        self.endLocationInSourceString - self.startLocationInSourceString + 1
      ) ;
      NSValue * issueRangeValue = [NSValue valueWithRange:issueRange] ;
      menuItem = [[NSMenuItem alloc] initWithTitle:title action:@selector (actionFixItReplace:) keyEquivalent:@""] ;
      menuItem.representedObject = [NSArray arrayWithObjects:inDisplayDescriptor, @"", issueRangeValue, nil] ;
    }else if ([title hasPrefix:@"Fix-it, replace with "]) {
      const NSRange issueRange = NSMakeRange (
        self.startLocationInSourceString,
        self.endLocationInSourceString - self.startLocationInSourceString + 1
      ) ;
      NSValue * issueRangeValue = [NSValue valueWithRange:issueRange] ;
      NSArray * array = [title componentsSeparatedByString:ZeroWidthSpace] ;
      if (array.count == 2) {
        NSMutableAttributedString * titleAS = [[NSMutableAttributedString alloc] initWithString:[array objectAtIndex:0]] ;
        [titleAS appendAttributedString:
          [[NSAttributedString alloc] initWithString:[array objectAtIndex:1] attributes:suggestionAttributes]
        ] ;
        NSString * replacement = [array objectAtIndex:1] ;
        menuItem = [[NSMenuItem alloc] initWithTitle:@"" action:@selector (actionFixItReplace:) keyEquivalent:@""] ;
        menuItem.attributedTitle = titleAS ;
        menuItem.representedObject = [NSArray arrayWithObjects:inDisplayDescriptor, replacement, issueRangeValue, nil] ;
      }
    }else if ([title hasPrefix:@"Fix-it, insert after: "]) {
      const NSRange issueRange = NSMakeRange (
        self.endLocationInSourceString + 1,
        0
      ) ;
      NSValue * issueRangeValue = [NSValue valueWithRange:issueRange] ;
      NSArray * array = [title componentsSeparatedByString:ZeroWidthSpace] ;
      if (array.count == 2) {
        NSMutableAttributedString * titleAS = [[NSMutableAttributedString alloc] initWithString:[array objectAtIndex:0]] ;
        [titleAS appendAttributedString:
          [[NSAttributedString alloc] initWithString:[array objectAtIndex:1] attributes:suggestionAttributes]
        ] ;
        NSString * replacement = [array objectAtIndex:1] ;
        menuItem = [[NSMenuItem alloc] initWithTitle:@"" action:@selector (actionFixItReplace:) keyEquivalent:@""] ;
        menuItem.attributedTitle = titleAS ;
        menuItem.representedObject = [NSArray arrayWithObjects:inDisplayDescriptor, replacement, issueRangeValue, nil] ;
      }
    }else if ([title hasPrefix:@"Fix-it, insert before: "]) {
      const NSRange issueRange = NSMakeRange (
        self.startLocationInSourceString,
        0
      ) ;
      NSValue * issueRangeValue = [NSValue valueWithRange:issueRange] ;
      NSArray * array = [title componentsSeparatedByString:ZeroWidthSpace] ;
      if (array.count == 2) {
        NSMutableAttributedString * titleAS = [[NSMutableAttributedString alloc] initWithString:[array objectAtIndex:0]] ;
        [titleAS appendAttributedString:
          [[NSAttributedString alloc] initWithString:[array objectAtIndex:1] attributes:suggestionAttributes]
        ] ;
        NSString * replacement = [array objectAtIndex:1] ;
        menuItem = [[NSMenuItem alloc] initWithTitle:@"" action:@selector (actionFixItReplace:) keyEquivalent:@""] ;
        menuItem.attributedTitle = titleAS ;
        menuItem.representedObject = [NSArray arrayWithObjects:inDisplayDescriptor, replacement, issueRangeValue, nil] ;
      }
    }
    if (menuItem != nil) {
      menuItem.target = self ;
      [inMenu addItem:menuItem] ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

- (void) actionFixItReplace: (NSMenuItem *) inSender {
  NSArray * array = inSender.representedObject ;
  OC_GGS_TextDisplayDescriptor * textViewDescriptor = [array objectAtIndex:0] ;
  NSString * replacementString = [array objectAtIndex:1] ;
  NSValue * issueRangeValue = [array objectAtIndex:2] ;
  const NSRange issueRange = issueRangeValue.rangeValue ;
  [textViewDescriptor replaceRange:issueRange withString:replacementString] ;
}

//--------------------------------------------------------------------------------------------------

@end
