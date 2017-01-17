//
//  PMDownloadFile.m
//  canari
//
//  Created by Pierre Molinaro on 19/08/06.
//  Copyright 2006 __MyCompanyName__. All rights reserved.
//

#import "PMDownloadFile.h"
#import <objc/objc-runtime.h>

//---------------------------------------------------------------------------------------------------------------------*

@implementation PMDownloadFile

//---------------------------------------------------------------------------------------------------------------------*

- (id) initWithURLString: (NSString *) inURLString
       postDictionary: (NSDictionary *) inPOSTDictionary
       destinationFileName: (NSString *) inDestinationFileName
       downloadDelegate: (id) inDelegate
       downloadDidEndSelector: (SEL) inDownloadDidEndSelector
       cancelButton: (NSButton *) inCancelButton
       subtitle: (NSTextField *) inSubtitle
       progressIndicator: (NSProgressIndicator *) inProgressIndicator
       userInfo: (id) inUserInfo {
  self = [super init] ;
  if (self) {
    mDownloadDidEndSelector = inDownloadDidEndSelector ;
    mURL = [NSURL URLWithString:inURLString] ;
    mDelegate = inDelegate ;
    mDestinationFileName = inDestinationFileName ;
    mUserInfo = inUserInfo ;
  //--- Subtitle
    mSubTitle = inSubtitle ;
    [mSubTitle setStringValue:@""] ;
  //--- Progress Indicator
    mProgressIndicator = inProgressIndicator ;
    [mProgressIndicator setIndeterminate:YES] ;
  //--- Cancel button
    mCancelButton = inCancelButton ;
    [mCancelButton setTarget:self] ;
    [mCancelButton setAction:@selector (cancelAction:)] ;
    [mCancelButton setEnabled:YES] ;
  //--- Create the request
    NSMutableURLRequest * theRequest = [NSMutableURLRequest
      requestWithURL:mURL
      cachePolicy:NSURLRequestReloadIgnoringCacheData
      timeoutInterval:60.0
    ] ;
  //--- set method POST
    [theRequest setHTTPMethod:@"POST"] ;
  //--- set HTTP body
    NSMutableString * body = [NSMutableString new] ;
    NSEnumerator * enumerator = [inPOSTDictionary keyEnumerator] ;
    NSString * key ;
    while ((key = [enumerator nextObject])) {
      NSString * parameter = [[inPOSTDictionary objectForKey:key] stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding] ;
      if ([body length] > 0) {
        [body appendString:@"&"] ;
      }
      [body appendFormat:@"%@=%@", key, parameter] ;
    }
    //NSLog (@"HTTP body: '%@'", body) ;
    [theRequest setHTTPBody:[body dataUsingEncoding:NSASCIIStringEncoding]] ;
  //--- Create the connection with the request, and start loading the data
    mDownload = [[NSURLDownload alloc] initWithRequest:theRequest delegate:self] ;
  //--- Set destination file name
    [mDownload setDestination:inDestinationFileName allowOverwrite:YES];
  }
  return self ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (id) initWithURLString: (NSString *) inURLString
       destinationFileName: (NSString *) inDestinationFileName
       downloadDelegate: (id) inDelegate
       downloadDidEndSelector: (SEL) inDownloadDidEndSelector
       cancelButton: (NSButton *) inCancelButton
       subtitle: (NSTextField *) inSubtitle
       progressIndicator: (NSProgressIndicator *) inProgressIndicator
       userInfo: (id) inUserInfo {
  self = [super init] ;
  if (self) {
    mDownloadDidEndSelector = inDownloadDidEndSelector ;
    mURL = [NSURL URLWithString:inURLString] ;
    mDelegate = inDelegate ;
    mDestinationFileName = inDestinationFileName ;
    mUserInfo = inUserInfo ;
  //--- Subtitle
    mSubTitle = inSubtitle ;
    [mSubTitle setStringValue:@""] ;
  //--- Progress Indicator
    mProgressIndicator = inProgressIndicator ;
    [mProgressIndicator setIndeterminate:YES] ;
  //--- Cancel button
    mCancelButton = inCancelButton ;
    [mCancelButton setTarget:self] ;
    [mCancelButton setAction:@selector (cancelAction:)] ;
    [mCancelButton setEnabled:YES] ;
  //--- Create the request
    NSURLRequest * theRequest = [NSURLRequest
      requestWithURL:mURL
      cachePolicy:NSURLRequestReloadIgnoringCacheData
      timeoutInterval:60.0
    ] ;
  //--- Create the connection with the request, and start loading the data
    mDownload = [[NSURLDownload alloc] initWithRequest:theRequest delegate:self] ;
  //--- Set destination file name
    [mDownload setDestination:inDestinationFileName allowOverwrite:YES];
  }
  return self ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) download:(NSURLDownload *)download didReceiveResponse:(NSURLResponse *)response {
  mReceivedLength = 0 ;
  mExpectedContentLength = [response expectedContentLength] ;
//--- Update progress Indicator
  [mProgressIndicator setMinValue:0.0] ;
  [mProgressIndicator setMaxValue: (double) mExpectedContentLength] ;
  [mProgressIndicator setDoubleValue:0.0] ;
  [mProgressIndicator setIndeterminate:NO] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void)download: (NSURLDownload *) inDownload didReceiveDataOfLength:(NSUInteger) inLength {
//  NSLog (@"download:didReceiveDataOfLength: received %lu bytes", inLength) ;
  mReceivedLength += inLength ;
//--- Update Progress Indicator
  [mProgressIndicator setDoubleValue: (double) mReceivedLength] ;
//--- Update subtitle
  NSString * subtitle = [NSString
    stringWithFormat:@"%lld KB of %lld KB",
    (mReceivedLength >> 10),
    (mExpectedContentLength >> 10)
  ] ;
  [mSubTitle setStringValue:subtitle] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) downloadingProcessDidEnd {
  [mCancelButton setTarget:nil] ;
  [mCancelButton setAction:NULL] ;
  [mCancelButton setEnabled:NO] ;
//  objc_msgSend (mDelegate, mDownloadDidEndSelector, self) ;
  [mDelegate performSelector:@selector (mDownloadDidEndSelector:) withObject:self] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) cancelAction: (id) inSender {
  [mDownload cancel] ;
  mDownloadHasBeenCancelled = YES ;
  [self downloadingProcessDidEnd] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) download:(NSURLDownload *)download didFailWithError:(NSError *) inError {
  // NSLog (@"Download failed") ;
  mDownloadError = inError ;
  [self downloadingProcessDidEnd] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) downloadDidFinish:(NSURLDownload *)download {
  // NSLog (@"Download completed") ;
  [self downloadingProcessDidEnd] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSError *) downloadError {
  return mDownloadError ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSString *) destinationFileName {
  return mDestinationFileName ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (id) userInfo {
  return mUserInfo ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (BOOL) downloadHasBeenCancelled {
  return mDownloadHasBeenCancelled ;
}

//---------------------------------------------------------------------------------------------------------------------*

@end
