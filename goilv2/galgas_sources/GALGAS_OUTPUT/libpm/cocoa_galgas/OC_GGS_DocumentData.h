//
//  OC_GGS_DocumentData.h
//  galgas-developer
//
//  Created by Pierre Molinaro on 31/07/12.
//  Copyright (c) 2012 IRCCyN. All rights reserved.
//
//-----------------------------------------------------------------------------*

#import <Foundation/Foundation.h>

//-----------------------------------------------------------------------------*

@class OC_GGS_TextSyntaxColoring ;
@class OC_GGS_TextDisplayDescriptor ;
@class OC_GGS_Document ;

//-----------------------------------------------------------------------------*

@interface OC_GGS_DocumentData : NSObject {
  @private NSMutableArray * mIssueArray ; // Of PMIssueDescriptor
  @private OC_GGS_TextSyntaxColoring * mTextSyntaxColoring ;
//--- Document encoding
  @private NSStringEncoding mFileEncoding ;
}

@property (assign, readonly PROPERTY_COMMA_ATOMIC) OC_GGS_Document * document ; // May be nil
@property (copy, readonly PROPERTY_COMMA_ATOMIC) NSURL * fileURL ;

+ (void) saveAllDocuments ;

+ (void) cocoaDocumentWillClose: (OC_GGS_DocumentData *) inDocumentData ;

+ (OC_GGS_DocumentData *) findOrAddDataForDocumentURL: (NSURL *) inDocumentURL
                          forCocoaDocument: (OC_GGS_Document *) inDocument ;

+ (OC_GGS_DocumentData *) findDocumentDataForFilePath: (NSString *) inFilePath ;

- (OC_GGS_TextDisplayDescriptor *) newSourceDisplayDescriptorForDocument: (OC_GGS_Document *) inDocumentUsedForDisplaying ;

- (NSString *) sourceString ;

- (OC_GGS_TextSyntaxColoring *) textSyntaxColoring ;

- (void) replaceCharactersInRange: (NSRange) inRange withString: (NSString *) inReplaceString ;

- (BOOL) performSaveToURL: (NSURL *) inAbsoluteURL ;

- (NSUInteger) locationForLineInSource: (NSUInteger) inLine ;

+ (void) broadcastIssueArray: (NSArray *) inIssueArray ;

- (void) save ;

@end

//-----------------------------------------------------------------------------*
