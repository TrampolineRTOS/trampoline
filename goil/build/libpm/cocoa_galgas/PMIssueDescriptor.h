//----------------------------------------------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------------------------------------

#import <Cocoa/Cocoa.h>

//----------------------------------------------------------------------------------------------------------------------

@class OC_GGS_RulerViewForBuildOutput ;

//----------------------------------------------------------------------------------------------------------------------

typedef enum {
 kLocationInSourceStringNotSolved,
 kLocationInSourceStringSolved,
 kLocationInSourceStringInvalid
} enumLocationInSourceStringStatus ;

//----------------------------------------------------------------------------------------------------------------------

@interface PMIssueDescriptor : NSObject {
  @private BOOL mIsError ;
  @private NSString * mMessage ;
  @private NSURL * mURL ;
  @private NSUInteger mLine ;
  @private NSUInteger mColumn ;
  @private NSRange mRangeInOutputData ;
  @private NSUInteger mLocationInSourceString ;
  @private enumLocationInSourceStringStatus mLocationInSourceStringStatus ;
  @private OC_GGS_RulerViewForBuildOutput * mBuildOutputRuler ;
}

- (PMIssueDescriptor *) initWithMessage: (NSString *) inMessage
                        URL: (NSURL *) inURL
                        line: (NSInteger) inLine
                        column: (NSInteger) inColumn
                        isError: (BOOL) inIsError
                        rangeInOutputData: (NSRange) inRangeInOutputData
                        buildOutputRuler: (OC_GGS_RulerViewForBuildOutput *) inRuler ;

- (void) detach ;

- (NSString *) issueMessage ;

- (NSURL *) issueStandardizedURL ;

- (BOOL) isError ;

- (NSUInteger) issueLine ;

- (NSUInteger) issueColumn ;

- (NSUInteger) locationInOutputData ;

- (enumLocationInSourceStringStatus) locationInSourceStringStatus ;

- (NSUInteger) locationInSourceString ;
- (void) setLocationInSourceString: (NSUInteger) inLocationInSourceString ;

- (void) updateLocationForPreviousRange: (NSRange) inEditedRange
         changeInLength: (NSInteger) inChangeInLength ;

- (void) scrollAndSelectErrorMessage ;
@end

//----------------------------------------------------------------------------------------------------------------------
