//
//  OC_GGS_BuildTask.h
//  galgas-developer
//
//  Created by Pierre Molinaro on 30/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//
//-----------------------------------------------------------------------------*

#import <Foundation/Foundation.h>

//-----------------------------------------------------------------------------*

@class OC_GGS_Document ;

//-----------------------------------------------------------------------------*

@interface OC_GGS_BuildTask : NSObject {
  @private NSTask * mTask ;
  @private NSPipe * mPipe ;

  @private BOOL mOutputBufferedDataHasBeenTransmitted ;

  @private BOOL mTaskCompleted ;
  
  @private OC_GGS_Document * mDocument ;
}

- (id) initWithDocument: (OC_GGS_Document *) inDocument
       filePath: (NSString *) inFilePath ;

- (void) terminate ;

@end

//-----------------------------------------------------------------------------*
