//
//  PMDownloadFile.h
//  canari
//
//  Created by Pierre Molinaro on 19/08/06.
//  Copyright 2006 __MyCompanyName__. All rights reserved.
//
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#import <Cocoa/Cocoa.h>

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

@class PMDownloadFile ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

@protocol PMDownloadDelegate
  - (void) downloadDidEnd: (PMDownloadFile *) inDownloader info: (NSUInteger) inInfo ;
@end

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

@interface PMDownloadFile : NSObject
  #if MAC_OS_X_VERSION_MIN_REQUIRED > MAC_OS_X_VERSION_10_6
    <NSURLDownloadDelegate>
  #endif
{
  @protected NSURL * mURL ;
  @protected id <PMDownloadDelegate> mDelegate ;
  @protected NSUInteger mDelegateInfo ;
  @protected NSURLDownload * mDownload ;
  @protected NSButton * mCancelButton ;
  @protected NSTextField * mSubTitle ;
  @protected NSProgressIndicator * mProgressIndicator ;
  @protected NSError * mDownloadError ; // nil if no error
  @protected long long mExpectedContentLength ;
  @protected long long mReceivedLength ;
  @protected NSString * mDestinationFileName ;
  @protected id mUserInfo ;
  @protected BOOL mDownloadHasBeenCancelled ;
}

- (id) initWithURLString: (NSString *) inURLString
       destinationFileName: (NSString *) inDestinationFileName
       downloadDelegate: (id <PMDownloadDelegate>) inDelegate
       info : (NSUInteger) inInfo
       cancelButton: (NSButton *) inCancelButton
       subtitle: (NSTextField *) inSubtitle
       progressIndicator: (NSProgressIndicator *) inProgressIndicator
       userInfo: (id) inUserInfo ;

- (id) initWithURLString: (NSString *) inURLString
       postDictionary: (NSDictionary *) inPOSTDictionary
       destinationFileName: (NSString *) inDestinationFileName
       downloadDelegate: (id <PMDownloadDelegate>) inDelegate
       info : (NSUInteger) inInfo
       cancelButton: (NSButton *) inCancelButton
       subtitle: (NSTextField *) inSubtitle
       progressIndicator: (NSProgressIndicator *) inProgressIndicator
       userInfo: (id) inUserInfo ;

- (NSError *) downloadError ;

- (NSString *) destinationFileName ;

- (id) userInfo ;

- (BOOL) downloadHasBeenCancelled ;

@end

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
