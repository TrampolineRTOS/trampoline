//
//  OC_GGS_searchInFolders.h
//  galgas
//
//  Created by Pierre Molinaro on 14/07/11.
//  Copyright 2011 IRCCyN. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface OC_GGS_searchInFolders : NSObject {

  @private NSMutableArray * mSearchPathArray ; // Array of NSMutableDictionary
//--- The element dictionary contains 3 keys:
//      - pathSelected
//      - recursive
//      - path

 @private NSMutableArray * mResultArray ;
 @private IBOutlet NSTreeController * mResultArrayTreeController ;
 @private IBOutlet NSTextField * mResultTextField ;
 @private NSUInteger mMatchCount ;
 
 @private NSUInteger mExtensionChoice ;

//--- Extension views
 @private IBOutlet NSView * mSelectedExtensionView ;
 @private IBOutlet NSView * mApplicationExtensionsView ;
 @private IBOutlet NSView * mExplicitExtensionsView ;
 @private IBOutlet NSTextField * mCommaSeparatedExtensionListFromApplicationTextField ;

//--- 
 @private NSUInteger mFolderChoice ;
 @private IBOutlet NSView * mSelectedFolderChoiceView ;
 @private IBOutlet NSView * mFolderFromOpenedSourceFilesView ;
 @private IBOutlet NSView * mExplicitFolderListView ;
 @private IBOutlet NSTableView * mFolderFromOpenedSourceFieldTableView ;
 @private NSMutableArray * mFolderFromOpenedSourceArray ;

//---
  @private NSUInteger mReplaceCount ;
  @private IBOutlet NSTextField * mReplacementTextField ;
}

- (IBAction) addFolderAction: (id) inSender ;

- (IBAction) findAction: (id) inSender ;

- (IBAction) replaceAllAction: (id) inSender ;

- (IBAction) refreshOpenedSourceFileFolderTableViewAction: (id) inSender ;

@end
