//
//  PMButtonWithRemove.m
//  galgas-developer
//
//  Created by Pierre Molinaro on 25/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//
//---------------------------------------------------------------------------*

#import "PMButtonWithRemove.h"

//---------------------------------------------------------------------------*

@implementation PMButtonWithRemove

//---------------------------------------------------------------------------*

- (void) setDisplayRemoveImage: (BOOL) inDisplay {
  mDisplayRemoveImage = inDisplay ;
}

//---------------------------------------------------------------------------*

- (void) setRemoveAction: (SEL) inRemoveAction {
  mRemoveAction = inRemoveAction ;
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
    NSImageRep * imageRep = [image
      bestRepresentationForRect:r
      context:[NSGraphicsContext currentContext]
      hints:nil
    ] ;
    [imageRep drawInRect:r] ;
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
  mMouseDown = YES ;
  if (mMouseWithin) {
    [self setNeedsDisplay:YES] ;
  }else{
    [super mouseDown:inEvent] ;
  }
}

//---------------------------------------------------------------------------*

- (void) mouseUp:(NSEvent *) inEvent {
  mMouseDown = NO ;
  if (mMouseWithin) {
    [self setNeedsDisplay:YES] ;
    [self.target performSelector:mRemoveAction withObject:self] ;
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
