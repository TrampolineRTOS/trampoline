//
//  OC_GGS_BuildTaskProxy.m
//  galgas-developer
//
//  Created by Pierre Molinaro on 30/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//
//---------------------------------------------------------------------------*

#import "OC_GGS_BuildTaskProxy.h"
#import "OC_GGS_BuildTask.h"
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

@implementation OC_GGS_BuildTaskProxy

//---------------------------------------------------------------------------*

- (OC_GGS_BuildTaskProxy *) initWithDocument: (OC_GGS_Document *) inDocument {
  self = [super init] ;
  if (self) {
    mPreviousBuildTasks = [NSMutableSet new] ;
    mDocument = inDocument ;
  }
  return self ;
}

//---------------------------------------------------------------------------*

- (void) purgePreviousBuildTasks {
  // const NSUInteger n = mPreviousBuildTasks.count ;
  NSMutableString * s = [NSMutableString new] ;
  NSArray * allTasks = mPreviousBuildTasks.allObjects.copy ;
  [mPreviousBuildTasks removeAllObjects] ;
  for (OC_GGS_BuildTask * task in allTasks) {
    if (! task.isCompleted) {
      [mPreviousBuildTasks addObject:task] ;
      [s appendString:task.runningStatus] ;
    }  
  }
  // NSLog (@"BUILD TASKS : %lu -> %lu%@", n, mPreviousBuildTasks.count, s) ;
}

//---------------------------------------------------------------------------*

- (void) noteBuildTaskTermination: (OC_GGS_BuildTask *) inBuildTask {
  [mPreviousBuildTasks addObject:inBuildTask] ;
  if (mBuildTask == inBuildTask) {
    [self willChangeValueForKey:@"buildTaskIsRunning"] ;
    [self willChangeValueForKey:@"buildTaskIsNotRunning"] ;
    mBuildTask = nil ;
    [self didChangeValueForKey:@"buildTaskIsNotRunning"] ;
    [self didChangeValueForKey:@"buildTaskIsRunning"] ;
  }
  [self purgePreviousBuildTasks] ;
}

//---------------------------------------------------------------------------*

- (BOOL) buildTaskIsRunning {
  return nil != mBuildTask ;
}

//---------------------------------------------------------------------------*

- (BOOL) buildTaskIsNotRunning {
  return nil == mBuildTask ;
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

- (void) XMLIssueAnalysis: (NSData *) inXMLdata {
  if (inXMLdata.length > 0) {
    NSError * error = nil ;
    NSXMLDocument * xmlDoc = [[NSXMLDocument alloc]
      initWithData:inXMLdata
      options:0
      error:& error
    ] ;
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
        NSString * file = @"" ;
        if ([node nodesForXPath:@"./@file" error:nil].count > 0) {
          file = [[[node nodesForXPath:@"./@file" error:nil] objectAtIndex:0 HERE] stringValue] ;
        }
        NSInteger line = 0 ;
        if ([node nodesForXPath:@"./@line" error:nil].count > 0) {
          line = [[[[node nodesForXPath:@"./@line" error:nil] objectAtIndex:0 HERE] stringValue] integerValue] ;
        }
        NSInteger column = 0 ;
        if ([node nodesForXPath:@"./@column" error:nil].count > 0) {
          column = [[[[node nodesForXPath:@"./@column" error:nil] objectAtIndex:0 HERE] stringValue] integerValue] ;
        }
        NSString * message = @"" ;
        if ([node nodesForXPath:@"./@message" error:nil].count > 0) {
          message = [[[node nodesForXPath:@"./@message" error:nil] objectAtIndex:0 HERE] stringValue] ;
        }
        PMIssueDescriptor * issue = [[PMIssueDescriptor alloc]
          initWithWarningMessage:message
          URL:[NSURL fileURLWithPath:file]
          line:line
          column:column
        ] ;
        [issueArray addObject:issue] ;
      }
    }
    //NSLog (@"issueArray %lu", issueArray.count) ;
  //--- Send issues to concerned text source coloring objects
    [mDocument setDocumentIssueArray:issueArray] ;
  //---
  //  if (nil != error) {
  //    [NSApp presentError:error] ;
  //  }
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

- (void) sendTaskOutputString: (NSString *) inString {
  NSDictionary * d = [NSDictionary dictionaryWithObjectsAndKeys:
    [NSFont fontWithName:@"Courier" size:13.0], NSFontAttributeName,
    [NSColor orangeColor], NSForegroundColorAttributeName,
    nil
  ] ;
  NSAttributedString * as = [[NSAttributedString alloc]
    initWithString:inString
    attributes:d
  ] ;
  [mDocument setRawOutputString:as] ;
}

//---------------------------------------------------------------------------*

- (void) abortBuild {
  if (nil != mBuildTask) {
    #ifdef DEBUG_MESSAGES
      NSLog (@"%s", __PRETTY_FUNCTION__) ;
    #endif
  //---
    [mBuildTask terminate] ;
    [mPreviousBuildTasks addObject:mBuildTask] ;
  //---    
    [self willChangeValueForKey:@"buildTaskIsRunning"] ;
    [self willChangeValueForKey:@"buildTaskIsNotRunning"] ;
    mBuildTask = nil ;
    [self didChangeValueForKey:@"buildTaskIsNotRunning"] ;
    [self didChangeValueForKey:@"buildTaskIsRunning"] ;
  //---
    [self sendTaskOutputString:@"Build has been aborted"] ;
  }
}

//---------------------------------------------------------------------------*

- (void) noteStandardOutputData: (NSData *) inData {
  NSString * message = [[NSString alloc] initWithData:inData encoding:NSUTF8StringEncoding] ;
  NSArray * messageArray = [message componentsSeparatedByString:[NSString stringWithFormat:@"%c", 0x1B]] ;
//  NSLog (@"%lu", messageArray.count) ;
//--- Enter first part (without any attribute)
  NSDictionary * defaultDictionary = [NSDictionary dictionaryWithObjectsAndKeys:
    [NSFont fontWithName:@"Courier" size:13.0], NSFontAttributeName,
    nil
  ] ;
  NSMutableAttributedString * attributedString = [NSMutableAttributedString new] ;
  [attributedString
    appendAttributedString:[[NSAttributedString alloc]
      initWithString:[messageArray objectAtIndex:0 HERE]
      attributes:defaultDictionary
    ]
  ] ;
//--- Send other components
  NSMutableDictionary * componentAttributeDictionary = defaultDictionary.mutableCopy ;
  for (NSUInteger i=1 ; i<messageArray.count ; i++) {
    NSString * component = [messageArray objectAtIndex:i HERE] ;
    NSUInteger idx = 0 ;
    while ((idx < component.length) && ([component characterAtIndex:idx] == '[')) {
      idx ++ ;
      NSUInteger code = 0 ;
      while ((idx < component.length) && isdigit ([component characterAtIndex:idx])) {
        code *= 10 ;
        code += [component characterAtIndex:idx] - '0' ;
        idx ++ ;
      }
      if ((idx < component.length) && ([component characterAtIndex:idx] == 'm')) {
        idx ++ ;
      }
      switch (code) {
      case 0 : componentAttributeDictionary = defaultDictionary.mutableCopy ; break ;
      case 30 : [componentAttributeDictionary setValue:[NSColor blackColor]   forKey:NSForegroundColorAttributeName] ; break ;
      case 31 : [componentAttributeDictionary setValue:[NSColor redColor]     forKey:NSForegroundColorAttributeName] ; break ;
      case 32 : [componentAttributeDictionary setValue:[NSColor greenColor]   forKey:NSForegroundColorAttributeName] ; break ;
      case 33 : [componentAttributeDictionary setValue:[NSColor orangeColor]  forKey:NSForegroundColorAttributeName] ; break ;
      case 34 : [componentAttributeDictionary setValue:[NSColor blueColor]    forKey:NSForegroundColorAttributeName] ; break ;
      case 35 : [componentAttributeDictionary setValue:[NSColor magentaColor] forKey:NSForegroundColorAttributeName] ; break ;
      case 36 : [componentAttributeDictionary setValue:[NSColor cyanColor]    forKey:NSForegroundColorAttributeName] ; break ;
      case 37 : [componentAttributeDictionary setValue:[NSColor whiteColor]   forKey:NSForegroundColorAttributeName] ; break ;
      case 40 : [componentAttributeDictionary setValue:[NSColor whiteColor]   forKey:NSBackgroundColorAttributeName] ; break ;
      case 41 : [componentAttributeDictionary setValue:[NSColor redColor]     forKey:NSBackgroundColorAttributeName] ; break ;
      case 42 : [componentAttributeDictionary setValue:[NSColor greenColor]   forKey:NSBackgroundColorAttributeName] ; break ;
      case 43 : [componentAttributeDictionary setValue:[NSColor orangeColor]  forKey:NSBackgroundColorAttributeName] ; break ;
      case 44 : [componentAttributeDictionary setValue:[NSColor blueColor]    forKey:NSBackgroundColorAttributeName] ; break ;
      case 45 : [componentAttributeDictionary setValue:[NSColor magentaColor] forKey:NSBackgroundColorAttributeName] ; break ;
      case 46 : [componentAttributeDictionary setValue:[NSColor cyanColor]    forKey:NSBackgroundColorAttributeName] ; break ;
      case 47 : [componentAttributeDictionary setValue:[NSColor whiteColor]   forKey:NSBackgroundColorAttributeName] ; break ;
      default: break ;
      }
    }
    [attributedString
      appendAttributedString:[[NSAttributedString alloc]
        initWithString:[component substringFromIndex:idx]
        attributes:componentAttributeDictionary
      ]
    ] ;
  }
//---
  [mDocument setRawOutputString:attributedString] ;
}

//---------------------------------------------------------------------------*

- (void) noteSocketData: (NSData *) inData {
  [self XMLIssueAnalysis:inData] ;
}

//---------------------------------------------------------------------------*

- (void) build {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  if (nil != mBuildTask) {
    [mPreviousBuildTasks addObject:mBuildTask] ;
    [mBuildTask terminate] ;
  }
  [self purgePreviousBuildTasks] ;
//---
  [self sendTaskOutputString:@"Compiling…"] ;
  [[NSDocumentController sharedDocumentController] saveAllDocuments:self] ;
  [mDocument displayIssueDetailedMessage:nil] ;
//--- Create task
  [self willChangeValueForKey:@"buildTaskIsRunning"] ;
  [self willChangeValueForKey:@"buildTaskIsNotRunning"] ;
  mBuildTask = [[OC_GGS_BuildTask alloc]
    initWithDocument:mDocument
    proxy:self
    index:mTaskIndex
  ] ;
  mTaskIndex ++ ;
  [self didChangeValueForKey:@"buildTaskIsNotRunning"] ;
  [self didChangeValueForKey:@"buildTaskIsRunning"] ;
  [self setWarningCount:0] ;
  [self setErrorCount:0] ;
}

//---------------------------------------------------------------------------*

@end
