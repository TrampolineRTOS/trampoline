//
//  PMOkButtonForPanel.m
//  canari
//
//  Created by Pierre Molinaro on 06/03/05.
//

#import "PMOkButtonForPanel.h"


@implementation PMOkButtonForPanel

- (void) awakeFromNib {
  if ([[self superclass] instancesRespondToSelector:@selector(awakeFromNib)]) {
    [super awakeFromNib];
  }
  NSWindow * myWindow = [self window] ;
  if ([myWindow isKindOfClass:[NSPanel class]]) {
    [myWindow setDefaultButtonCell:[self cell]] ;
  }
}


- (BOOL) sendAction:(SEL)theAction to:(id)theTarget {
  NSWindow * myWindow = [self window] ;
  if ([myWindow isKindOfClass:[NSPanel class]]) {
    [myWindow orderOut:nil] ;
    [NSApp endSheet:myWindow returnCode:YES] ;
  }
  return [super sendAction:theAction to:theTarget] ;
}

@end
