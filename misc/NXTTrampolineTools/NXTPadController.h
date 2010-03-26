//
//  NXTPadController.h
//
//  Created by Jean-Luc Béchennec on 18/03/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import  <IOBluetoothUI/objc/IOBluetoothDeviceSelectorController.h>
#define NXT_RFCOMM_CHANNEL_ID   1

@interface NXTPadController : NSObject {
  IBOutlet id padBox;
  int connectionState;
  int position;
	IOBluetoothDeviceRef btDevice;
	BluetoothDeviceName         btName;
	CFStringRef                 name;
	char                        raw_name[100];
	char	cmd[100];
	IOBluetoothRFCOMMChannelRef rfcommChannel;
	int                         new_data;
}
- (IBAction)backward:(id)sender;
- (IBAction)forward:(id)sender;
- (IBAction)turnLeft:(id)sender;
- (IBAction)turnRight:(id)sender;
- (IBAction)toggleConnect:(id)sender;
@end
void listener(IOBluetoothRFCOMMChannelRef rfcommChannel, void *data, UInt16 length, void *refCon);

