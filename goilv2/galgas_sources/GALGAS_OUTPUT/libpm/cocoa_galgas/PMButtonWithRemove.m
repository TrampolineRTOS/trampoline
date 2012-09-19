//
//  PMButtonWithRemove.m
//  galgas-developer
//
//  Created by Pierre Molinaro on 25/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//
//---------------------------------------------------------------------------*

#import "PMButtonWithRemove.h"
#import "PMTabBarView.h"
#import "PMDebug.h"

//---------------------------------------------------------------------------*

@implementation PMButtonWithRemove

//---------------------------------------------------------------------------*
//                                                                           *
//       I N I T                                                             *
//                                                                           *
//---------------------------------------------------------------------------*

- (id) initWithFrame: (NSRect) inFrame {
  self = [super initWithFrame:inFrame] ;
  if (self) {
    #ifdef DEBUG_MESSAGES
      NSLog (@"%s", __PRETTY_FUNCTION__) ;
    #endif
    noteObjectAllocation (self) ;
  }
  return self;
}

//---------------------------------------------------------------------------*

- (void) FINALIZE_OR_DEALLOC {
  noteObjectDeallocation (self) ;
  macroSuperFinalize ;
}

//---------------------------------------------------------------------------*

- (void) setDisplayRemoveImage: (BOOL) inDisplay {
  mDisplayRemoveImage = inDisplay ;
}

//---------------------------------------------------------------------------*

- (void) setFilePathForDragOperation: (NSString *) inFilePath {
  mFilePath = inFilePath.copy ;
}

//---------------------------------------------------------------------------*

#define IMAGE_SIZE (10.0)

//---------------------------------------------------------------------------*

- (NSRect) trackingRect {
  const NSRect r = {{4.0, (self.bounds.size.height - IMAGE_SIZE) / 2}, {IMAGE_SIZE, IMAGE_SIZE}} ;
  return r ;
}

//---------------------------------------------------------------------------*

#define DIRTY_SIZE (4.0)

//---------------------------------------------------------------------------*

- (NSRect) dirtyRect {
  const NSRect r = {{NSMaxX (self.bounds) - DIRTY_SIZE * 2.0, DIRTY_SIZE}, {DIRTY_SIZE, DIRTY_SIZE}} ;
  return r ;
}

//---------------------------------------------------------------------------*

- (void) updateTrackingAreas {
//--- Remove tracking area
  if (nil != mTrackingArea) {
    [self removeTrackingArea:mTrackingArea] ;
  }
//--- Add Updated tracking area
  if (mDisplayRemoveImage) {
    mTrackingArea = [[NSTrackingArea alloc]
      initWithRect:[self trackingRect]
      options:NSTrackingMouseEnteredAndExited | NSTrackingActiveInKeyWindow
      owner:self
      userInfo:nil
    ] ;
    [self addTrackingArea:mTrackingArea] ;
  }
//---
  [super updateTrackingAreas] ;
}

//---------------------------------------------------------------------------*

- (void) drawRect:(NSRect) inDirtyRect {
  [super drawRect:inDirtyRect] ;
  if (mMouseWithin) {
    const NSRect r = [self trackingRect] ;
    NSImage * image = [NSImage imageNamed:mMouseDown ? NSImageNameStopProgressFreestandingTemplate : NSImageNameStopProgressTemplate] ;
    [image
      drawInRect:r
      fromRect:NSZeroRect
      operation:NSCompositeSourceOver
      fraction:1.0
    ] ;
  }
  if (mIsDirty) {
    [[NSColor blackColor] setFill] ;
    NSBezierPath * bp = [NSBezierPath bezierPathWithOvalInRect:[self dirtyRect]] ;
    [bp fill] ;
  }
}

//---------------------------------------------------------------------------*

- (void) mouseEntered:(NSEvent *) inEvent {
  if (self.isEnabled) {
    mMouseWithin = YES ;
    [self setNeedsDisplay:YES] ;
  }
  [super mouseEntered:inEvent] ;
}

//---------------------------------------------------------------------------*

- (void) mouseExited:(NSEvent *) inEvent {
  if (self.isEnabled) {
    mMouseWithin = NO ;
    [self setNeedsDisplay:YES] ;
  }
  [super mouseExited:inEvent] ;
}

//---------------------------------------------------------------------------*

- (void) mouseDown:(NSEvent *) inEvent {
  if ((inEvent.modifierFlags & NSAlternateKeyMask) == 0) {
    mMouseDown = YES ;
    if (mMouseWithin) {
      [self setNeedsDisplay:YES] ;
    }else{
      [super mouseDown:inEvent] ;
    }
  }else if (mFilePath.length > 0) {
/*    NSString * dragTypeUTI = @"fr.ec-nantes.fr.COCOA" ;
    NSPasteboard * pboard = [NSPasteboard pasteboardWithName:NSDragPboard] ;
    [pboard declareTypes:[NSArray arrayWithObject:dragTypeUTI] owner:self] ;
    [pboard setData:[mFilePath dataUsingEncoding:NSUTF8StringEncoding] forType:dragTypeUTI] ;
    NSData * imageData = [self dataWithPDFInsideRect:self.bounds] ;
    NSImage * image = [[NSImage alloc] initWithData:imageData] ;
    [self
       dragImage:image
       at:NSMakePoint (0.0, self.bounds.size.height)
       offset:NSMakeSize (0.0, 0.0) // Ignored
       event:inEvent
       pasteboard:pboard
       source:self
       slideBack:YES
    ] ;*/
/*    [self
       dragFile:mFilePath
       fromRect:self.bounds
       slideBack:YES
       event:inEvent
    ] ;*/
  }
}

//---------------------------------------------------------------------------*

- (void) mouseUp: (NSEvent *) inEvent {
  mMouseDown = NO ;
  if (mMouseWithin) {
    [self setNeedsDisplay:YES] ;
    [self.target removeTabAction:self] ;
  }else{
    [super mouseUp:inEvent] ;
  }
}

//---------------------------------------------------------------------------*

- (void) sizeToFit {
  NSRect frame = self.frame ;
  [super sizeToFit] ;
  frame.size.width = self.frame.size.width + IMAGE_SIZE * 3.0 ;
  self.frame = frame ;
}

//---------------------------------------------------------------------------*

- (void) setIsDirty: (BOOL) inFlag {
  if (mIsDirty != inFlag) {
    mIsDirty = inFlag ;
    [self setNeedsDisplay] ;
  }
}

//---------------------------------------------------------------------------*

@end
