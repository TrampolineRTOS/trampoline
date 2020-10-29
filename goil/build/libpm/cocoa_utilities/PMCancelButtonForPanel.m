//
//  PMCancelButtonForPanel.m
//  canari
//
//  Created by Pierre Molinaro on 06/03/05.
//
//----------------------------------------------------------------------------------------------------------------------

#import "PMCancelButtonForPanel.h"

//----------------------------------------------------------------------------------------------------------------------

@implementation PMCancelButtonForPanel

- (BOOL) sendAction:(SEL)theAction to:(id)theTarget {
  NSWindow * myWindow = [self window] ;
  if ([myWindow isKindOfClass:[NSPanel class]]) {
    [myWindow orderOut:nil] ;
    [NSApp endSheet:myWindow returnCode:NO] ;
  }
  return [super sendAction:theAction to:theTarget] ;
}

@end

//----------------------------------------------------------------------------------------------------------------------
