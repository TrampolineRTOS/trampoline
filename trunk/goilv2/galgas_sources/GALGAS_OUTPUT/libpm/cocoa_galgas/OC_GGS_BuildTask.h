//
//  OC_GGS_BuildTask.h
//  galgas-developer
//
//  Created by Pierre Molinaro on 30/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//

#import <Foundation/Foundation.h>

@class OC_GGS_Document ;

@interface OC_GGS_BuildTask : NSObject {
  @private NSMutableData * mBufferedInputData ;
  @private NSArrayController * mIssueArrayController ;
  @private NSTask * mTask ;
  @private NSUInteger mErrorCount ;
  @private NSUInteger mWarningCount ;
  @private BOOL mAbortRequested ;
  @private OC_GGS_Document * mDocumentToBuild ;
}

- (BOOL) buildTaskIsRunning ;
- (BOOL) buildTaskIsNotRunning ;

- (NSArrayController *) issueArrayController ;

- (void) buildDocument: (OC_GGS_Document *) inDocument ;
- (void) abortAndBuildDocument: (OC_GGS_Document *) inDocument ;

- (void) stopBuild ;

- (NSString *) errorCountString ;

- (NSString *) warningCountString ;
@end
