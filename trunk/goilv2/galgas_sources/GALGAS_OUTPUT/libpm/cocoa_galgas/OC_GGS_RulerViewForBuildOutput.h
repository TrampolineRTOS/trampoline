//
//  OC_GGS_RulerViewForBuildOutput.h
//  galgas-developer
//
//  Created by Pierre Molinaro on 31/07/12.
//  Copyright (c) 2012 IRCCyN. All rights reserved.
//
//---------------------------------------------------------------------------*

#import <Foundation/Foundation.h>

//---------------------------------------------------------------------------*

@class OC_GGS_Document ;

//---------------------------------------------------------------------------*

@interface OC_GGS_RulerViewForBuildOutput : NSRulerView {
  @private NSArray * mIssueArray ;
  @private OC_GGS_Document * mDocument ;
}

- (id) initWithDocument: (OC_GGS_Document *) inDocument ;

- (void) setIssueArray: (NSArray *) inIssueArray ;

- (void) detach ;
@end

//---------------------------------------------------------------------------*
