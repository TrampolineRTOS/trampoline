//
//  NXTPadController.h
//
//  Created by Jean-Luc Béchennec on 18/03/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface NXTPadController : NSObject {
  IBOutlet id padBox;
  int connectionState;
}
- (IBAction)backward:(id)sender;
- (IBAction)forward:(id)sender;
- (IBAction)turnLeft:(id)sender;
- (IBAction)turnRight:(id)sender;
- (IBAction)toggleConnect:(id)sender;
@end
