//
//  OC_GGS_BuildTask.m
//  galgas-developer
//
//  Created by Pierre Molinaro on 30/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//
//---------------------------------------------------------------------------*

#import "OC_GGS_BuildTask.h"
#import "PMIssueDescriptor.h"
#import "OC_GGS_Document.h"
#import "OC_GGS_PreferencesController.h"
#import "PMDebug.h"

//---------------------------------------------------------------------------*

#include <netdb.h>
#include <netinet/in.h>

//---------------------------------------------------------------------------*

//#define DEBUG_MESSAGES

//---------------------------------------------------------------------------*

@implementation OC_GGS_BuildTask 

//---------------------------------------------------------------------------*

- (OC_GGS_BuildTask *) initWithDocument: (OC_GGS_Document *) inDocument {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  self = [super init] ;
  if (self) {
    noteObjectAllocation (self) ;
  //---
    mDocument = inDocument ;
  //---
    NSArray * commandLineArray = [gCocoaGalgasPreferencesController commandLineItemArray] ;
  //--- Command line tool does actually exist ? (First argument is not "?")
    if ([[commandLineArray objectAtIndex:0] isEqualToString:@"?"]) {
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
      NSMutableArray * arguments = [NSMutableArray new] ;
      [arguments addObjectsFromArray:[commandLineArray subarrayWithRange:NSMakeRange (1, [commandLineArray count]-1)]] ;
      [arguments addObject:inDocument.fileURL.path] ;
      [arguments addObject:@"--cocoa"] ;
   //--- Create task
      mTask = [NSTask new] ;
      [mTask setLaunchPath:[commandLineArray objectAtIndex:0]] ;
      [mTask setArguments:arguments] ;
      // NSLog (@"'%@' %@", [mTask launchPath], arguments) ;
    //--- Set standard output notification
      mPipe = [NSPipe pipe] ;
      [mTask setStandardOutput:mPipe] ;
      [mTask setStandardError:mPipe] ;
    //---
      [[NSNotificationCenter defaultCenter]
        addObserver:self
        selector:@selector (getDataFromTaskOutput:)
        name:NSFileHandleReadCompletionNotification
        object:[mPipe fileHandleForReading]
      ] ;
      [mPipe.fileHandleForReading readInBackgroundAndNotify] ;
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

- (void) FINALIZE_OR_DEALLOC {
  noteObjectDeallocation (self) ;
  macroSuperFinalize ;
}

//---------------------------------------------------------------------------*

- (void) getDataFromTaskOutput: (NSNotification *) inNotification {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSData * data = [[inNotification userInfo] objectForKey:NSFileHandleNotificationDataItem];
  if (data.length > 0) {
    [mDocument appendBuildOutputData:data] ;
    [inNotification.object readInBackgroundAndNotify] ;
  }else{
    [[NSNotificationCenter defaultCenter]
      removeObserver:self
      name:NSFileHandleReadCompletionNotification
      object:[mPipe fileHandleForReading]
    ] ;
    [[NSNotificationCenter defaultCenter]
      removeObserver:self
      name:NSTaskDidTerminateNotification
      object:mTask
    ] ;
    [[mPipe fileHandleForReading] closeFile] ;
    mOutputBufferedDataHasBeenTransmitted = YES ;
    mTask = nil ;
    mPipe = nil ;
    [mDocument buildCompleted] ;
//    mDocument = nil ;
  }
}

//---------------------------------------------------------------------------*

- (void) taskDidTerminate: (NSNotification *) inNotification {
  mTaskCompleted = YES ;
}

//---------------------------------------------------------------------------*

- (void) terminate {
  [mTask terminate] ;
}

//---------------------------------------------------------------------------*

- (BOOL) isCompleted {
  return mTaskCompleted && mOutputBufferedDataHasBeenTransmitted ;
}

//---------------------------------------------------------------------------*

@end
