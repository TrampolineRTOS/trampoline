//
//  OC_GGS_BuildTaskProxy.h
//  galgas-developer
//
//  Created by Pierre Molinaro on 30/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//

#import <Foundation/Foundation.h>

@class OC_GGS_Document ;
@class OC_GGS_BuildTask ;

@interface OC_GGS_BuildTaskProxy : NSObject {
  @private OC_GGS_BuildTask * mBuildTask ;
  @private NSMutableSet * mPreviousBuildTasks ;

  @private NSUInteger mErrorCount ;
  @private NSUInteger mWarningCount ;
  @private NSUInteger mTaskIndex ;
  @private OC_GGS_Document * mDocument ;
}

- (OC_GGS_BuildTaskProxy *) initWithDocument: (OC_GGS_Document *) inDocument ;

- (BOOL) buildTaskIsRunning ;
- (BOOL) buildTaskIsNotRunning ;

- (void) build ;

- (void) abortBuild ;

- (NSString *) errorCountString ;

- (NSString *) warningCountString ;

- (void) noteBuildTaskTermination: (OC_GGS_BuildTask *) inBuildTask ;

- (void) noteStandardOutputData: (NSData *) inData ;

- (void) noteSocketData: (NSData *) inData ;
@end
