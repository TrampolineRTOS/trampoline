//
//  NXTPadController.m
//
//  Created by Jean-Luc Béchennec on 18/03/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "NXTPadController.h"

@implementation NXTPadController
- (void)sendCommand:(char) c1{
					 //v1:(char) c2{
	cmd[0] = 3; //LSB de taille 
	cmd[1] = 0x00; //MSB fde taille 
	cmd[2] = c1;
	cmd[3] = 0x00;
	cmd[4] = 0x20; // Joke
	if ( IOBluetoothRFCOMMChannelWrite(rfcommChannel,cmd,5,cmd[80]) ==0 )
	//if (IOBluetoothRFCOMMChannelWriteSync(rfcommChannel,cmd,1 )) //Error si marche pas 
	//if (IOBluetoothRFCOMMChannelWriteSync(rfcommChannel,cmd,2)) //Error si marche pas 
	//while(!(IOBluetoothRFCOMMChannelWriteAsync(rfcommChannel,cmd,2,0 ))){
	///	while(!(IOBluetoothRFCOMMChannelWriteAsync(rfcommChannel,cmd,2,0 )));
	{ 
		printf("Successfully sent command! %d %d\n", cmd[2]);
	}
	else
	{
		fprintf(stderr,"IOBluetoothRFCOMMChannelWrite() failed.\n");
	}
	//IOBluetoothRFCOMMChannelWriteSimple(<#IOBluetoothRFCOMMChannelRef rfcommChannel#>, <#void * data#>, <#UInt16 length#>, <#Boolean sleepFlag#>, <#UInt32 * numBytesSent#>)
	new_data = 0;
	
}
- (IBAction)backward:(id)sender {
  NSLog(@"On freine !\n");
	[self sendCommand:0x02];
	
}

- (IBAction)forward:(id)sender {
  NSLog(@"En avant !\n");
	
	[self sendCommand:0x01];

}

- (IBAction)turnLeft:(id)sender {
	[sender setTitle:[NSString stringWithFormat:@"%d",position--]];
  NSLog(@"À gauche !\n");
		[self sendCommand:0x03];
}

- (IBAction)turnRight:(id)sender {
	[sender setTitle:[NSString stringWithFormat:@"%d",position++]];
  NSLog(@"À droite !\n");
		[self sendCommand:0x04];
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
    //[button setEnabled:connectionState];
	  [button setEnabled:TRUE];
  }
	
	//[button setEnabled:TRUE];
	//TEST
	IOBluetoothDeviceSelectorController *deviceSelector;
	NSArray *deviceArray;
	deviceSelector = [IOBluetoothDeviceSelectorController
					  deviceSelector];
	[deviceSelector runModal];
	deviceArray = [deviceSelector getResults];
	btDevice= [deviceArray objectAtIndex:0];
	NSLog(@"--%@",[btDevice getNameOrAddress])	;
	
	NSLog(@"--%@",IOBluetoothDeviceGetName(btDevice));
	NSLog(@"--%X",IOBluetoothDeviceGetAddress(btDevice));
	//
	//CHECK BLUETOOTH COM
	if
		( IOBluetoothDeviceRemoteNameRequest(btDevice,NULL,NULL,btName) !=
		 kIOReturnSuccess )
	{
		fprintf(stderr,"IOBluetoothDeviceRemoteNameRequest() failed.\n");
		return 1;
	}
	else
	{
		name = IOBluetoothDeviceGetName(btDevice);
		printf("CFString name = %p\n",name);
		if ( CFStringGetCString(name,raw_name,
								100,kCFStringEncodingISOLatin1) )
			printf("Device name = %s\n",raw_name);
		else
			fprintf(stderr,"CFStringGetCString() failed.\n");
	}
	/* Open an RFCOMM channel to the NXT.  The underlying baseband
	 connection is automatically opened if needed.  The process
	 isn't finished until a listener callback function is
	 registered,
	 since synchronous reads are not supported. */
	if
		( IOBluetoothDeviceOpenRFCOMMChannel(btDevice,NXT_RFCOMM_CHANNEL_ID,
											 &rfcommChannel) != kIOReturnSuccess )
	{
		fprintf(stderr,"IOBluetoothDeviceOpenRFCOMMChannel() failed.\n");
		return 1;
	}
	else
	{
		printf("Successfully opened RFCOMM channel!\n");
	}
	
	/* Check Max Transmission unit, just for kicks. */
	printf("MTU = %d\n",IOBluetoothRFCOMMChannelGetMTU(rfcommChannel));
	
	
	if ( IOBluetoothRFCOMMChannelRegisterIncomingDataListener(rfcommChannel,listener,&new_data) == 0 )
	{
		/* Get battery level */
		cmd[0] = 0x00;
		cmd[1] = 0x0B;
		new_data = 0;   /* Make use of the refCon arg by setting a
		 flag. */
		[self sendCommand:0x00];
	
	}
	else
	{
		
		fprintf(stderr,"IOBluetoothRFCOMMChannelRegisterIncomingDataListener()failed.\n");
	}
	
	
	
}
/**
 COMM BLUETOOTH TEST READ 
 */
void    listener(IOBluetoothRFCOMMChannelRef rfcommChannel, void *data, UInt16 length, void *refCon)
{
	int     c,
	*new_data = refCon;
	
	puts("Got data!");
	for (c=0; c<length; ++c)
	printf("%02X ",((char *)data)[c]);
	putchar('\n');
	*new_data = 1;
	//CFRunLoopStop(CFRunLoopGetCurrent());
}
/**
 */

- (void)awakeFromNib {
  connectionState = 0;
	position = 0;
}
@end
