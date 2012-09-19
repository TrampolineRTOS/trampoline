//
//  OC_GGS_Scroller.h
//  galgas-developer
//
//  Created by Pierre Molinaro on 27/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//

#import <AppKit/AppKit.h>

@interface OC_GGS_Scroller : NSScroller {
   @private NSArray * mIssueArray ; // Of PMIssueDescriptor
   @private BOOL mIsSourceTextViewScroller ;
}

- (void) setIssueArray: (NSArray *) inIssueArray ;
- (void) setIsSourceTextViewScroller: (BOOL) inIsSourceTextViewScroller ;
@end
