//
//  OC_GGS_BuildTask.h
//  galgas-developer
//
//  Created by Pierre Molinaro on 30/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//

#import <Foundation/Foundation.h>

@class OC_GGS_Document ;
@class OC_GGS_TextDisplayDescriptor ;

@interface OC_GGS_ContextualHelpTask : NSObject {
  @private OC_GGS_TextDisplayDescriptor * mProxy ;
  @private NSUInteger mTaskIndex ;

  @private NSTask * mTask ;
  @private NSPipe * mPipe ;
  @private NSSocketPort * mConnectionSocket ;
  @private NSFileHandle * mConnectionSocketHandle ;
  @private NSFileHandle * mRemoteSocketHandle ;
  @private NSMutableData * mSocketBufferedData ;  
  @private BOOL mSocketBufferedDataHasBeenTransmitted ;
  
  @private BOOL mTaskCompleted ;
}

- (id) initWithDocument: (OC_GGS_Document *) inDocument
       range: (NSRange) inRange
       proxy: (OC_GGS_TextDisplayDescriptor *) inProxy
       index: (NSUInteger) inIndex ;

- (void) terminate ;

- (BOOL) isCompleted ;

- (NSString *) runningStatus ;
@end
