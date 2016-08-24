//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2011, ..., 2014 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes, ECN, École Centrale de Nantes (France)  *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#import "OC_GGS_BuildTask.h"
#import "PMIssueDescriptor.h"
#import "OC_GGS_Document.h"
#import "OC_GGS_ApplicationDelegate.h"
#import "PMDebug.h"

//---------------------------------------------------------------------------------------------------------------------*

#include <netdb.h>
#include <netinet/in.h>

//---------------------------------------------------------------------------------------------------------------------*

//#define DEBUG_MESSAGES

//---------------------------------------------------------------------------------------------------------------------*

@implementation OC_GGS_BuildTask 

//---------------------------------------------------------------------------------------------------------------------*

- (OC_GGS_BuildTask *) initWithDocument: (OC_GGS_Document *) inDocument
                       filePath: (NSString *) inFilePath {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  self = [super init] ;
  if (self) {
    noteObjectAllocation (self) ;
  //---
    mDocument = inDocument ;
  //---
    NSArray * commandLineArray = [gCocoaApplicationDelegate commandLineItemArray] ;
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
      [arguments addObject:inFilePath] ;
      [arguments addObject:@"--cocoa"] ;
   //--- Create task
      mTask = [NSTask new] ;
      if ([gCocoaApplicationDelegate prefixByToolUtility]) {
        [mTask setLaunchPath:[gCocoaApplicationDelegate toolUtilityPrefix]] ;
        NSArray * allArguments = [NSArray arrayWithObject:[commandLineArray objectAtIndex:0]] ;
        allArguments = [allArguments arrayByAddingObjectsFromArray:arguments] ;
        [mTask setArguments:allArguments] ;
      }else{
        [mTask setLaunchPath:[commandLineArray objectAtIndex:0]] ;
        [mTask setArguments:arguments] ;
      }
    //--- Set standard output notification
      mTaskOutputPipe = [NSPipe pipe] ;
      [mTask setStandardOutput:mTaskOutputPipe] ;
      [mTask setStandardError:mTaskOutputPipe] ;
    //---
      [[NSNotificationCenter defaultCenter]
        addObserver:self
        selector:@selector (getDataFromTaskOutput:)
        name:NSFileHandleReadCompletionNotification
        object:mTaskOutputPipe.fileHandleForReading
      ] ;
      [mTaskOutputPipe.fileHandleForReading readInBackgroundAndNotify] ;
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

//---------------------------------------------------------------------------------------------------------------------*

- (void) FINALIZE_OR_DEALLOC {
  noteObjectDeallocation (self) ;
  macroSuperFinalize ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) getDataFromTaskOutput: (NSNotification *) inNotification {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSData * data = [inNotification.userInfo objectForKey:NSFileHandleNotificationDataItem];
  if (data.length > 0) {
    [mDocument appendBuildOutputData:data] ;
    [inNotification.object readInBackgroundAndNotify] ;
  }else{
    [[NSNotificationCenter defaultCenter]
      removeObserver:self
      name:NSFileHandleReadCompletionNotification
      object:mTaskOutputPipe.fileHandleForReading
    ] ;
    [[NSNotificationCenter defaultCenter]
      removeObserver:self
      name:NSTaskDidTerminateNotification
      object:mTask
    ] ;
    [mTaskOutputPipe.fileHandleForReading closeFile] ;
    mOutputBufferedDataHasBeenTransmitted = YES ;
    mTask = nil ;
    mTaskOutputPipe = nil ;
    [mDocument buildCompleted] ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) taskDidTerminate: (NSNotification *) inNotification {
  mTaskCompleted = YES ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) terminate {
  [mTask terminate] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (BOOL) isCompleted {
  return mTaskCompleted && mOutputBufferedDataHasBeenTransmitted ;
}

//---------------------------------------------------------------------------------------------------------------------*

@end
