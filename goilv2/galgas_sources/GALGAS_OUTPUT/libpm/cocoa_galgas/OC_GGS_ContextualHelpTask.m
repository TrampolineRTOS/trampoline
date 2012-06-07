//
//  OC_GGS_ContextualHelpTask.m
//  galgas-developer
//
//  Created by Pierre Molinaro on 30/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//
//---------------------------------------------------------------------------*

#import "OC_GGS_ContextualHelpTask.h"
#import "OC_GGS_TextDisplayDescriptor.h"
#import "PMIssueDescriptor.h"
#import "PMCocoaCallsDebug.h"
#import "OC_GGS_TextDisplayDescriptor.h"
#import "OC_GGS_Document.h"
#import "OC_GGS_PreferencesController.h"

//---------------------------------------------------------------------------*

#include <netdb.h>
#include <netinet/in.h>

//---------------------------------------------------------------------------*

//#define DEBUG_MESSAGES

//---------------------------------------------------------------------------*

@implementation OC_GGS_ContextualHelpTask 

//---------------------------------------------------------------------------*

- (OC_GGS_ContextualHelpTask *) initWithDocument: (OC_GGS_Document *) inDocument
                                range: (NSRange) inRange
                                proxy : (OC_GGS_TextDisplayDescriptor *) inProxy
                                index: (NSUInteger) inIndex {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  self = [super init] ;
  if (self) {
  //---
    mProxy = inProxy ;
    mTaskIndex = inIndex ;
    mSocketBufferedData = [NSMutableData new] ;
  //---
    NSArray * commandLineArray = [gCocoaGalgasPreferencesController commandLineItemArray] ;
  //--- Command line tool does actually exist ? (First argument is not "?")
    if ([[commandLineArray objectAtIndex:0 HERE] isEqualToString:@"?"]) {
      NSAlert * alert = [NSAlert alertWithMessageText:@"Error: cannot compile"
        defaultButton: nil
        alternateButton: nil
        otherButton: nil
        informativeTextWithFormat:@"Compilation must be performed by an embedded Command line Tool; no command line Tool are currently embedded by application."
      ] ;
      [alert
        beginSheetModalForWindow:inDocument.windowForSheet
        modalDelegate:nil
        didEndSelector:0
        contextInfo:NULL
      ] ;
    }else{
    //--- Issue receiver socket
      mConnectionSocket = [[NSSocketPort alloc] initWithTCPPort:0] ; // A port number will be attributed
      struct sockaddr_in socketStruct ;
      socklen_t length = sizeof (socketStruct) ;
      getsockname (mConnectionSocket.socket, (struct sockaddr *) & socketStruct, & length) ;
      const UInt16 actualPort = ntohs (socketStruct.sin_port) ;
      // NSLog (@"actualPort %hu", actualPort) ;
      // NSLog (@"mConnectionSocket %p %d", mConnectionSocket, mConnectionSocket.socket) ;
      NSMutableArray * arguments = [NSMutableArray new] ;
      [arguments addObjectsFromArray:[commandLineArray subarrayWithRange:NSMakeRange (1, [commandLineArray count]-1)]] ;
      [arguments addObject:inDocument.fileURL.path] ;
      [arguments addObject:[NSString stringWithFormat:@"--mode=context-help:%hu:%lu:%lu", actualPort, inRange.location, inRange.length]] ;
   //--- Create task
      mTask = [NSTask new] ;
      [mTask setLaunchPath:[commandLineArray objectAtIndex:0 HERE]] ;
      [mTask setArguments:arguments] ;
      // NSLog (@"'%@' %@", [mTask launchPath], arguments) ;
    //--- Set standard output notification
      mPipe = [NSPipe pipe] ;
      [mTask setStandardOutput:mPipe] ;
      [mTask setStandardError:mPipe] ;
    //--- http://www.cocoadev.com/index.pl?NSSocketPort
      mConnectionSocketHandle = [[NSFileHandle alloc]
        initWithFileDescriptor:mConnectionSocket.socket
        closeOnDealloc:YES
      ] ;
      // NSLog (@"mConnectionSocketHandle %p", mConnectionSocketHandle) ;
      [[NSNotificationCenter defaultCenter]
        addObserver:self
        selector:@selector (newSocketConnection:) 
        name:NSFileHandleConnectionAcceptedNotification
        object:mConnectionSocketHandle
      ] ;
      [mConnectionSocketHandle acceptConnectionInBackgroundAndNotify] ;
    //---
      [[NSNotificationCenter defaultCenter]
        addObserver:self
        selector:@selector (taskDidTerminate:) 
        name:NSTaskDidTerminateNotification
        object:mTask
      ] ;
    //--- Start task
      [mTask launch] ;
    }
  }
  return self ;
}

//---------------------------------------------------------------------------*

- (void) newSocketConnection:(NSNotification *) inNotification {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
//---
  mRemoteSocketHandle = [inNotification.userInfo
    objectForKey:NSFileHandleNotificationFileHandleItem
  ] ;
//---
  [[NSNotificationCenter defaultCenter]
    addObserver:self
    selector:@selector (getDataFromTaskSocket:)
    name:NSFileHandleReadCompletionNotification
    object:mRemoteSocketHandle
  ] ;
  [mRemoteSocketHandle readInBackgroundAndNotify] ;
}

//---------------------------------------------------------------------------*

- (void) getDataFromTaskSocket: (NSNotification *) inNotification {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSData * d = [[inNotification userInfo] objectForKey:NSFileHandleNotificationDataItem];
  if ([d length] > 0) {
    [mSocketBufferedData appendData:d] ;
    [[inNotification object] readInBackgroundAndNotify] ;
  }else{
    [mProxy noteSocketData:mSocketBufferedData] ;
    mSocketBufferedDataHasBeenTransmitted = YES ;
  }
}

//---------------------------------------------------------------------------*

- (void) taskDidTerminate: (NSNotification *) inNotification {
  [mProxy noteBuildTaskTermination:self] ;
  mTaskCompleted = YES ;
}

//---------------------------------------------------------------------------*

- (void) terminate {
  mProxy = nil ;
  [mTask terminate] ;
}

//---------------------------------------------------------------------------*

- (NSString *) runningStatus {
  return [NSString stringWithFormat:@" %d:%lu", ! [mTask isRunning], mTaskIndex] ;
}

//---------------------------------------------------------------------------*

- (BOOL) isCompleted {
  return mTaskCompleted && mSocketBufferedDataHasBeenTransmitted ;
}

//---------------------------------------------------------------------------*

@end
