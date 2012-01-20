//
//  PMDownloadData.h
//  canari
//
//  Created by Pierre Molinaro on 20/08/06.
//  Copyright 2006 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface PMDownloadData : NSObject {
  @protected NSURL * mURL ;
  @protected id mDelegate ;
  @protected SEL mDownloadDidEndSelector ; // - (void) downloadDidEnd: (PMDownloadData *) inDownloader
  @protected NSError * mDownloadError ; // nil if no error
  @protected NSMutableData * mDownloadedData ;
  @protected id mUserInfo ;
  @protected NSURLConnection * mDownloadConnection ;
}

- (id) initDownloadWithURLString: (NSString *) inURLString
       delegate: (id) inDelegate
       downloadDidEndSelector: (SEL) inDownloadDidEndSelector
       userInfo: (id) inUserInfo ;

- (NSError *) downloadError ;
- (NSData *) downloadedData ;
- (id) userInfo ;
- (NSString *) urlString ;

@end
