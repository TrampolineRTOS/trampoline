//
//  PMDownloadFile.h
//  canari
//
//  Created by Pierre Molinaro on 19/08/06.
//  Copyright 2006 __MyCompanyName__. All rights reserved.
//
//-----------------------------------------------------------------------------*

#import <Cocoa/Cocoa.h>

//-----------------------------------------------------------------------------*

@interface PMDownloadFile : NSObject
  #if MAC_OS_X_VERSION_MIN_REQUIRED > MAC_OS_X_VERSION_10_6
    <NSURLDownloadDelegate>
  #endif
{
  @protected NSURL * mURL ;
  @protected id mDelegate ;
  @protected NSURLDownload * mDownload ;
  @protected SEL mDownloadDidEndSelector ;
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
       downloadDelegate: (id) inDelegate
       downloadDidEndSelector: (SEL) inDownloadDidEndSelector // - (void) downloadDidEnd: (PMDownloadFile *) inDownloader
       cancelButton: (NSButton *) inCancelButton
       subtitle: (NSTextField *) inSubtitle
       progressIndicator: (NSProgressIndicator *) inProgressIndicator
       userInfo: (id) inUserInfo ;

- (id) initWithURLString: (NSString *) inURLString
       postDictionary: (NSDictionary *) inPOSTDictionary
       destinationFileName: (NSString *) inDestinationFileName
       downloadDelegate: (id) inDelegate
       downloadDidEndSelector: (SEL) inDownloadDidEndSelector // - (void) downloadDidEnd: (PMDownloadFile *) inDownloader
       cancelButton: (NSButton *) inCancelButton
       subtitle: (NSTextField *) inSubtitle
       progressIndicator: (NSProgressIndicator *) inProgressIndicator
       userInfo: (id) inUserInfo ;

- (NSError *) downloadError ;

- (NSString *) destinationFileName ;

- (id) userInfo ;

- (BOOL) downloadHasBeenCancelled ;

@end

//-----------------------------------------------------------------------------*
