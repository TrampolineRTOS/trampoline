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
#import "PMCocoaCallsDebug.h"
#import "OC_GGS_TextDisplayDescriptor.h"
#import "OC_GGS_Document.h"
#import "OC_GGS_PreferencesController.h"

//---------------------------------------------------------------------------*

//#define DEBUG_MESSAGES

//---------------------------------------------------------------------------*

@implementation OC_GGS_BuildTask 

//---------------------------------------------------------------------------*

- (id) init {
  self = [super init] ;
  if (self) {
    mIssueArrayController = [NSArrayController new] ;
  }
  return self ;
}

//---------------------------------------------------------------------------*

- (BOOL) buildTaskIsRunning {
  return nil != mTask ;
}

//---------------------------------------------------------------------------*

- (BOOL) buildTaskIsNotRunning {
  return nil == mTask ;
}

//---------------------------------------------------------------------------*

- (NSArrayController *) issueArrayController {
  return mIssueArrayController ;
}

//---------------------------------------------------------------------------*

- (void) setWarningCount: (NSUInteger) inCount {
  [self willChangeValueForKey:@"warningCountString"] ;
  mWarningCount = inCount ;
  [self didChangeValueForKey:@"warningCountString"] ;
}

//---------------------------------------------------------------------------*

- (NSString *) warningCountString {
  NSString * result = @"" ;
  if (mWarningCount > 0) {
    result = [NSString stringWithFormat:@"%lu", mWarningCount] ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

- (void) setErrorCount: (NSUInteger) inCount {
  [self willChangeValueForKey:@"errorCountString"] ;
  mErrorCount = inCount ;
  [self didChangeValueForKey:@"errorCountString"] ;
}

//---------------------------------------------------------------------------*

- (NSString *) errorCountString {
  NSString * result = @"" ;
  if (mErrorCount > 0) {
    result = [NSString stringWithFormat:@"%lu", mErrorCount] ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

- (void) XMLIssueAnalysis {
  if (mBufferedInputData.length > 0) {
    NSError * error = nil ;
    NSXMLDocument * xmlDoc = [[NSXMLDocument alloc]
      initWithData:mBufferedInputData
      options:0
      error:& error
    ] ;
    mBufferedInputData = nil ;
    NSArray * issues = nil ;
    if (nil == error) {
      issues = xmlDoc.rootElement.children ;
    }
    NSMutableArray * issueArray = [NSMutableArray new] ;
    NSUInteger errorCount = 0 ;
    NSUInteger warningCount = 0 ;
    for (NSXMLNode * node in issues) {
      if (nil == node.name) {
        NSString * message = [node stringValue] ;
        PMIssueDescriptor * issue = [[PMIssueDescriptor alloc] initWithMessage:message] ;
        [issueArray addObject:issue] ;
      }else if ([@"message" isEqualToString:node.name]) {
        NSString * message = [[[node nodesForXPath:@"./@message" error:nil] objectAtIndex:0 HERE] stringValue] ;
        PMIssueDescriptor * issue = [[PMIssueDescriptor alloc] initWithMessage:message] ;
        [issueArray addObject:issue] ;
      }else if ([@"fileOperation" isEqualToString:node.name]) {
        NSString * message = [[[node nodesForXPath:@"./@message" error:nil] objectAtIndex:0 HERE] stringValue] ;
        PMIssueDescriptor * issue = [[PMIssueDescriptor alloc] initWithFileOperation:message] ;
        [issueArray addObject:issue] ;
      }else if ([@"error" isEqualToString:node.name]) {
        errorCount ++ ;
        NSArray * a = [node nodesForXPath:@"./@file" error:nil] ;
        NSString * file = (a.count == 1) ? [[a objectAtIndex:0 HERE] stringValue] : @"" ;
        a = [node nodesForXPath:@"./@line" error:nil] ;
        NSInteger line = (a.count == 1) ? [[[a objectAtIndex:0 HERE] stringValue] integerValue] : 0 ;
        a = [node nodesForXPath:@"./@column" error:nil] ;
        NSInteger column = (a.count == 1) ? [[[a objectAtIndex:0 HERE] stringValue] integerValue] : 0 ;
        NSString * message = [[[node nodesForXPath:@"./@message" error:nil] objectAtIndex:0 HERE] stringValue] ;
        PMIssueDescriptor * issue = [[PMIssueDescriptor alloc]
          initWithErrorMessage:message
          URL:[NSURL fileURLWithPath:file]
          line:line
          column:column
        ] ;
        [issueArray addObject:issue] ;
      }else if ([@"warning" isEqualToString:node.name]) {
        warningCount ++ ;
        NSString * file = [[[node nodesForXPath:@"./@file" error:nil] objectAtIndex:0 HERE] stringValue] ;
        NSInteger line = [[[[node nodesForXPath:@"./@line" error:nil] objectAtIndex:0 HERE] stringValue] integerValue] ;
        NSInteger column = [[[[node nodesForXPath:@"./@column" error:nil] objectAtIndex:0 HERE] stringValue] integerValue] ;
        NSString * message = [[[node nodesForXPath:@"./@message" error:nil] objectAtIndex:0 HERE] stringValue] ;
        PMIssueDescriptor * issue = [[PMIssueDescriptor alloc]
          initWithWarningMessage:message
          URL:[NSURL fileURLWithPath:file]
          line:line
          column:column
        ] ;
        [issueArray addObject:issue] ;
      }
    }
    [mIssueArrayController setContent:issueArray] ;
  //--- Send issues to concerned text source coloring objects
    for (OC_GGS_Document * doc in [[NSDocumentController sharedDocumentController] documents]) {
      [doc.textSyntaxColoring setIssueArray:issueArray] ;
    }
  //---
    if (nil != error) {
      [NSApp presentError:error] ;
    }
  //---
    [self setErrorCount:errorCount] ;
    [self setWarningCount:warningCount] ;
  }
}

//---------------------------------------------------------------------------*

#pragma mark Build

//---------------------------------------------------------------------------*
//                                                                           *
//    C O M P I L E                                                          *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) notifyTaskCompleted {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [self willChangeValueForKey:@"buildTaskIsRunning"] ;
  [self willChangeValueForKey:@"buildTaskIsNotRunning"] ;
  mTask = nil ;
  [self didChangeValueForKey:@"buildTaskIsNotRunning"] ;
  [self didChangeValueForKey:@"buildTaskIsRunning"] ;
}

//---------------------------------------------------------------------------*

- (void) getDataFromTaskOutput: (NSNotification *) inNotification {
  NSData * data = [inNotification.userInfo objectForKey:NSFileHandleNotificationDataItem];
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s (%lu bytes)", __PRETTY_FUNCTION__, (unsigned long) data.length) ;
  #endif
  if (data.length > 0) {
    [mBufferedInputData appendData:data] ;
    [inNotification.object readInBackgroundAndNotify] ;
  }else{
    NSNotificationCenter * center = [NSNotificationCenter defaultCenter] ;
    [center removeObserver:self name:NSFileHandleReadCompletionNotification object: [[mTask standardOutput] fileHandleForReading]] ;
    [center removeObserver:self name:NSTaskDidTerminateNotification object:mTask] ;
    [self notifyTaskCompleted] ;
    if (! mAbortRequested) {
      [self XMLIssueAnalysis] ;
      [NSApp requestUserAttention:NSInformationalRequest] ;
    }
    mAbortRequested = NO ;
    if (nil != mDocumentToBuild) {
      [self buildDocument:mDocumentToBuild] ;
      mDocumentToBuild = nil ;
    }
  }
}

//---------------------------------------------------------------------------*

- (void) stopBuild {
  if ((nil != mTask) && ! mAbortRequested) {
    mAbortRequested = YES ;
    mDocumentToBuild = nil ;
    [mTask terminate] ;
    [mTask waitUntilExit] ;
    [self notifyTaskCompleted] ;
  }
}

//---------------------------------------------------------------------------*

- (void) abortAndBuildDocument: (OC_GGS_Document *) inDocument {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s:%@", __PRETTY_FUNCTION__, inDocument) ;
  #endif
  if (nil == mTask) {
    [self buildDocument:inDocument] ;
  }else{
    mDocumentToBuild = inDocument ;
    if (! mAbortRequested) {
      mAbortRequested = YES ;
      [mTask terminate] ;
      [mTask waitUntilExit] ;
    }
  }
}

//---------------------------------------------------------------------------*

- (void) buildDocument: (OC_GGS_Document *) inDocument {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  if (mTask == nil) {
    [[NSDocumentController sharedDocumentController] saveAllDocuments:self] ;
    [inDocument displayIssueDetailedMessage:nil] ;
    mBufferedInputData = [NSMutableData new] ;
    [mIssueArrayController setContent:[NSArray array]] ;
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
      NSMutableArray * arguments = [NSMutableArray new] ;
      [arguments addObjectsFromArray:[commandLineArray subarrayWithRange:NSMakeRange (1, [commandLineArray count]-1)]] ;
      [arguments addObject:inDocument.fileURL.path] ;
   //--- Create task
      [self willChangeValueForKey:@"buildTaskIsRunning"] ;
      [self willChangeValueForKey:@"buildTaskIsNotRunning"] ;
      mTask = [NSTask new] ;
      [self didChangeValueForKey:@"buildTaskIsNotRunning"] ;
      [self didChangeValueForKey:@"buildTaskIsRunning"] ;
      [mTask setLaunchPath:[commandLineArray objectAtIndex:0 HERE]] ;
      [mTask setArguments:arguments] ;
      [self setWarningCount:0] ;
      [self setErrorCount:0] ;
      // NSLog (@"'%@' %@", [mTask launchPath], arguments) ;
    //--- Set standard output notification
      NSPipe * taskOutput = [NSPipe pipe] ;
      [mTask setStandardOutput:taskOutput] ;
      [mTask setStandardError:taskOutput] ;
      [[NSNotificationCenter defaultCenter]
        addObserver:self
        selector:@selector (getDataFromTaskOutput:)
        name:NSFileHandleReadCompletionNotification
        object:[taskOutput fileHandleForReading]
      ] ;
      [taskOutput.fileHandleForReading readInBackgroundAndNotify] ;
    //--- Start task
      [mTask launch] ;
    }
  }
}

//---------------------------------------------------------------------------*

@end
