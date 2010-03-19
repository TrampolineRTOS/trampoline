//
//  NXTPadController.m
//
//  Created by Jean-Luc Béchennec on 18/03/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "NXTPadController.h"

@implementation NXTPadController
- (IBAction)backward:(id)sender {
  NSLog(@"On freine !\n");
}

- (IBAction)forward:(id)sender {
  NSLog(@"En avant !\n");
}

- (IBAction)turnLeft:(id)sender {
  NSLog(@"À gauche !\n");
}

- (IBAction)turnRight:(id)sender {
  NSLog(@"À droite !\n");
}

- (IBAction)toggleConnect:(id)sender {
  connectionState = [sender state];
  NSArray *padButtons = [[padBox contentView] subviews];
  if (connectionState) {
    NSLog(@"Bouton Enfoncé\n");
  }
  else {
    NSLog(@"Bouton Relâché\n");
  }

  NSEnumerator *en = [padButtons objectEnumerator];
  id button;
  while (button = [en nextObject]) {
    NSLog(@"bouton\n");
    [button setEnabled:connectionState];
  }
}

- (void)awakeFromNib {
  connectionState = 0;
}
@end
