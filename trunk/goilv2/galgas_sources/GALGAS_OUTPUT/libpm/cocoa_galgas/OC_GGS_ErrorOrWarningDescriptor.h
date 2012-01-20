//
//  OC_GGS_ErrorOrWarningDescriptor.h
//  galgas
//
//  Created by Pierre Molinaro on 16/12/09.
//  Copyright 2009 IRCCyN. All rights reserved.
//
//---------------------------------------------------------------------------*

#import <Cocoa/Cocoa.h>

//---------------------------------------------------------------------------*

@interface OC_GGS_ErrorOrWarningDescriptor : NSObject {
  @private NSRange mCompileMessageTextRange ;
  @private NSUInteger mIndex ;
  @private NSString * mDocumentPath ;
  @private NSInteger mLocation ;
}

- (id) initWithRange: (NSRange) inRange
       index: (NSUInteger) inIndex
       documentPath : (NSString *) inDocumentPath
       locationInSourceString: (NSUInteger) inLocation ;

- (NSRange) rangeInCompileMessageText ;

- (NSUInteger) index ;

- (NSInteger) locationInSourceString ;

- (NSString *) documentPath ;


- (void) editedFilePath:(NSString *) inDocPath
         editedRange: (NSRange) inEditedRange
         changeInLength: (NSInteger) inChangeInLength ;
@end

//---------------------------------------------------------------------------*
