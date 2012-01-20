//
//  OC_GGS_searchInFolders.m
//  galgas
//
//  Created by Pierre Molinaro on 14/07/11.
//  Copyright 2011 IRCCyN. All rights reserved.
//

#import "OC_GGS_searchInFolders.h"
#import "OC_GGS_Document.h"
#import "PMCocoaCallsDebug.h"

//---------------------------------------------------------------------------*

@implementation OC_GGS_searchInFolders

//---------------------------------------------------------------------------*

- (id) init {
  self = [super init] ;
  if (self) {
    mResultArray = [NSMutableArray new] ;
    NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
    mSearchPathArray = [ud valueForKey:@"searchPathArray"] ;
    if (nil == mSearchPathArray) {
      mSearchPathArray = [NSMutableArray new] ;
    }
  //---
    NSNotificationCenter * nc = [NSNotificationCenter defaultCenter] ;
    [nc
      addObserver:self
      selector:@selector(applicationWillTerminateAction:)
      name:NSApplicationWillTerminateNotification
      object:nil
    ] ;
  }
  return self ;
}

//---------------------------------------------------------------------------*

- (NSArray *) allTypesOfCurrentApplication {
  NSMutableArray * allTypes = [NSMutableArray new] ;
  NSDictionary * infoDictionary = [[NSBundle mainBundle] infoDictionary] ;
  NSArray * allDocumentTypes = [infoDictionary objectForKey:@"CFBundleDocumentTypes"] ;
  for (NSDictionary * type in allDocumentTypes) {
    NSArray * a = [type objectForKey:@"CFBundleTypeExtensions"] ;
    [allTypes addObjectsFromArray:a] ;  
  }
  return allTypes ;
}

//---------------------------------------------------------------------------*

- (void) awakeFromNib {
  [mResultTextField setStringValue:@""] ;
  [mReplacementTextField setStringValue:@""] ;
//---
  NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
  [self willChangeValueForKey:@"mExtensionChoice"] ;
  mExtensionChoice = [ud integerForKey:@"extensionChoice"] ;
  [self didChangeValueForKey:@"mExtensionChoice"] ;
//---
  [self willChangeValueForKey:@"mFolderChoice"] ;
  mFolderChoice = [ud integerForKey:@"folderChoice"] ;
  [self didChangeValueForKey:@"mFolderChoice"] ;
//---
  NSArray * extensionList = [self allTypesOfCurrentApplication] ;
  NSString * commaSeparatedExtensionListFromApplication = [extensionList componentsJoinedByString:@", "] ;
  [mCommaSeparatedExtensionListFromApplicationTextField setStringValue:commaSeparatedExtensionListFromApplication] ;
//--- 
  NSNotificationCenter * nc = [NSNotificationCenter defaultCenter] ;
  [nc
    addObserver:self
    selector:@selector(refreshOpenedSourceFileFolderTableViewAction:)
    name:NSWindowDidBecomeKeyNotification
    object:[mResultTextField window]
  ] ;
}

//---------------------------------------------------------------------------*

- (void) refreshOpenedSourceFileFolderTableViewAction: (id) inSender {
  NSDocumentController * dc = [NSDocumentController sharedDocumentController] ;
  NSMutableSet * directorySet = [NSMutableSet new] ;
  for (OC_GGS_Document * document in [dc documents]) {
    NSString * filePath = [[document fileURL] path] ;
    [directorySet addObject:[filePath stringByDeletingLastPathComponent]] ;  
  }
  // NSLog (@"directorySet %@", directorySet) ;
//---
  NSMutableArray * folderFromOpenedSourceArray = [NSMutableArray new] ;
  for (NSString * path in directorySet) {
    [folderFromOpenedSourceArray addObject:[NSDictionary
      dictionaryWithObject:path
      forKey:@"sourcePath"
    ]] ;
  }
//---
  [self willChangeValueForKey:@"mFolderFromOpenedSourceArray"] ;
  mFolderFromOpenedSourceArray = folderFromOpenedSourceArray ;
  [self didChangeValueForKey:@"mFolderFromOpenedSourceArray"] ;
}

//---------------------------------------------------------------------------*

- (IBAction) addFolderAction: (id) inSender {
  NSOpenPanel * openPanel = [NSOpenPanel openPanel] ;
  [openPanel setCanChooseFiles:NO] ;
  [openPanel setCanChooseDirectories:YES] ;
  [openPanel setAllowsMultipleSelection:YES] ;
  [openPanel
    beginSheetForDirectory:nil
    file:nil
    types:nil
    modalForWindow:[inSender window]
    modalDelegate:self
    didEndSelector:@selector(openPanelDidEnd:returnCode:contextInfo:)
    contextInfo:NULL
  ] ;
}

//---------------------------------------------------------------------------*

- (void) openPanelDidEnd: (NSOpenPanel *) inPanel
         returnCode: (int) inReturnCode
         contextInfo: (void  *) inContextInfo {
  if (NSOKButton == inReturnCode) {
    NSArray * resultArray = [inPanel URLs] ;
    for (NSURL * url in resultArray) {
      if ([url isFileURL]) {
        NSMutableDictionary * d = [NSMutableDictionary new] ;
        [d setObject:[NSNumber numberWithBool:YES] forKey:@"pathSelected"] ;
        [d setObject:[NSNumber numberWithBool:YES] forKey:@"recursive"] ;
        [d setObject:[url path] forKey:@"path"] ;
        [self willChangeValueForKey:@"mSearchPathArray"] ;
        [mSearchPathArray addObject:d] ;
        [self didChangeValueForKey:@"mSearchPathArray"] ;
      }
    }
  }
}

//---------------------------------------------------------------------------*

- (void) insertObject: (NSDictionary *) inObject
         inMSearchPathArrayAtIndex: (NSUInteger) inIndex {
  [mSearchPathArray insertObject:inObject atIndex:inIndex] ;
}

//---------------------------------------------------------------------------*

- (void) removeObjectFromMSearchPathArrayAtIndex: (NSUInteger) inIndex {
  [mSearchPathArray removeObjectAtIndex:inIndex] ;
}

//---------------------------------------------------------------------------*

 - (void) applicationWillTerminateAction: (NSNotification *) inNotification {
  NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
  [ud setObject:mSearchPathArray forKey:@"searchPathArray"] ;  
  //---
  [ud setInteger:mExtensionChoice forKey:@"extensionChoice"] ;
  [ud setInteger:mFolderChoice forKey:@"folderChoice"] ;
}

//---------------------------------------------------------------------------*

- (void) findInFile: (NSString *) inFileFullPath {
  NSMutableArray * foundEntries = [NSMutableArray new] ;
  NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
  NSString * searchString = [ud objectForKey:@"stringToFind"] ;
  // NSLog (@"searchString '%@'", searchString) ;
  NSUInteger searchOptions = NSCaseInsensitiveSearch ;
  if ([[ud objectForKey:@"caseSensitiveSearch"] boolValue]) {
    searchOptions = 0 ;
  }
  NSDocumentController * dc = [NSDocumentController sharedDocumentController] ;
  OC_GGS_Document * document = [dc documentForURL:[NSURL fileURLWithPath:inFileFullPath]] ;
  NSString * fileContents = nil ;
  if (nil == document) {
    fileContents = [NSString
      stringWithContentsOfFile:inFileFullPath
      usedEncoding:NULL
      error:NULL
    ] ;
  }else{
    fileContents = [document sourceStringForGlobalSearch] ;
  }
  NSRange searchRange = {0, [fileContents length]} ;
  while (searchRange.length > 0) {
    const NSRange r = [fileContents rangeOfString:searchString options:searchOptions range:searchRange] ;
    if (r.length > 0) { // Found
      const NSRange lineRange = [fileContents lineRangeForRange:r] ;
      // NSLog (@"Found at location %u in file '%@'", r.location, inFileFullPath) ;
      searchRange.location = r.location + r.length ;
      searchRange.length = [fileContents length] - searchRange.location ;
      NSDictionary * d = [NSDictionary dictionaryWithObjectsAndKeys:
        [fileContents substringWithRange:lineRange], @"foundItem",
        inFileFullPath, @"filePath",
        NSStringFromRange (r), @"rangeString",
        nil
      ] ;
      [foundEntries addObject:d] ;
      mMatchCount ++ ;
    }else{
      searchRange.length = 0 ; // For exiting
    }
  }
//---
  if ([foundEntries count] > 0) {
    [self willChangeValueForKey:@"mResultArray"] ;
    [mResultArray addObject:[NSDictionary dictionaryWithObjectsAndKeys:
      [NSNumber numberWithInteger:[foundEntries count]], @"countString",
      [NSNumber numberWithBool:YES], @"boldDisplay",
      foundEntries, @"children",
      inFileFullPath, @"foundItem",
      inFileFullPath, @"filePath",
      nil
    ]] ;
    [self didChangeValueForKey:@"mResultArray"] ;
  }
}

//---------------------------------------------------------------------------*

- (void) recursiveSearchInDirectory: (NSString *) inDirectoryFullPath
         recursive: (BOOL) inRecursive
         extensionList: (NSArray *) inExtensionList {
  NSFileManager * fm = [NSFileManager new] ;
  NSArray * contents = [fm contentsOfDirectoryAtPath:inDirectoryFullPath error:nil] ;
  if (nil == contents) {
  
  }else{
    for (NSString * subPath in contents) {
      if ('.' != [subPath characterAtIndex:0]) {
        NSString * fullPath = [NSString stringWithFormat:@"%@/%@", inDirectoryFullPath, subPath] ;
        BOOL isDirectory ;
        if ([fm fileExistsAtPath:fullPath isDirectory: & isDirectory]) {
          if (isDirectory && inRecursive) {
            [self recursiveSearchInDirectory:fullPath recursive:YES extensionList:inExtensionList] ;
          }else if ((! isDirectory) && [inExtensionList containsObject:[fullPath pathExtension]]) {
            [self findInFile:fullPath] ;
          }
        }
      }
    }
  }
}

//---------------------------------------------------------------------------*

- (NSArray *) extensionList {
  NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
  NSString * extensionListString = [ud objectForKey:@"explicitExtensionList"] ;
  NSArray * elements = [extensionListString componentsSeparatedByString:@","] ;
  NSMutableArray * result = [NSMutableArray new] ;
  for (NSString * ext in elements) {
    [result addObject:[ext stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]]] ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

- (IBAction) findAction: (id) inSender {
  [mResultTextField setStringValue:@""] ;
  mMatchCount = 0 ;
  // NSLog (@"self %p", self) ;
  [self willChangeValueForKey:@"mResultArray"] ;
  [mResultArray removeAllObjects] ;
  [self didChangeValueForKey:@"mResultArray"] ;
  NSArray * extensionList = nil ;
  switch (mExtensionChoice) {
  case 0 : extensionList = [self allTypesOfCurrentApplication] ; break ;
  case 1 : extensionList = [self extensionList] ; break ;
  default: break ;
  }
//  NSLog (@"extensionList %@", extensionList) ;
//---
  switch (mFolderChoice) {
  case 0 :
    for (NSDictionary * entry in mFolderFromOpenedSourceArray) {
      NSString * path = [entry objectForKey:@"sourcePath"] ;
      [self recursiveSearchInDirectory:path recursive:YES extensionList:extensionList] ;
    }
    break ;
  case 1 :
    for (NSDictionary * entry in mSearchPathArray) {
      const BOOL pathSelected = [[entry objectForKey:@"pathSelected"] boolValue] ;
      if (pathSelected) {
        NSString * path = [entry objectForKey:@"path"] ;
        const BOOL recursive = [[entry objectForKey:@"recursive"] boolValue] ;
        [self recursiveSearchInDirectory:path recursive:recursive extensionList:extensionList] ;
      }
    }
    break ;
  default:
    break ;
  }
//---
  if (0 == mMatchCount) {
    [mResultTextField setStringValue:@"No match"] ;
  }else if (1 == mMatchCount) {
    [mResultTextField setStringValue:@"1 match"] ;
  }else{
    [mResultTextField setStringValue:[NSString stringWithFormat:@"%u matches", mMatchCount]] ;
  }
}

//---------------------------------------------------------------------------*

- (void) doubleClickInResultAction {
  NSDocumentController * dc = [NSDocumentController sharedDocumentController] ;
  NSArray * allDocumentTypes = [self allTypesOfCurrentApplication] ;
  // NSLog (@"allDocumentTypes %@", allDocumentTypes) ;
  NSWorkspace * ws = [NSWorkspace sharedWorkspace] ;
//--- Find selection
  for (NSDictionary * selectedObject in [mResultArrayTreeController selectedObjects]) {
   // NSLog (@"selectedObject %@", selectedObject) ;
    NSString * filePath = [selectedObject valueForKey:@"filePath"] ;
    if ([allDocumentTypes containsObject:[filePath pathExtension]]) {
      OC_GGS_Document * document = [dc documentForURL:[NSURL fileURLWithPath:filePath]] ;
      [[document windowForSheet] makeKeyAndOrderFront:nil] ;
      if (nil == document) {
        /* document = */ [dc
          openDocumentWithContentsOfURL:[NSURL fileURLWithPath:filePath]
          display:YES
          error:nil
        ] ;
      }
      // NSLog (@"document %@", document) ;
      NSString * rangeString = [selectedObject valueForKey:@"rangeString"] ;
      if (nil != rangeString) {
      //  const NSRange searchRange = NSRangeFromString (rangeString) ;
     //   [document setSelectionRange:searchRange] ;
       NSBeep () ; NSLog (@"%s", __PRETTY_FUNCTION__) ;
      }
    }else{
      [ws openFile:filePath] ;
    }
  }
}

//---------------------------------------------------------------------------*

- (void) extensionChoiceDidChange {
  NSArray * allSubviews = [[mSelectedExtensionView subviews] copy] ;
  for (NSView * view in allSubviews) {
    [view removeFromSuperview] ;
  }
  switch (mExtensionChoice) {
  case 0 : [mSelectedExtensionView addSubview:mApplicationExtensionsView] ; break ;
  case 1 : [mSelectedExtensionView addSubview:mExplicitExtensionsView] ; break ;
  default : break ;
  }
  for (NSView * view in [mSelectedExtensionView subviews]) {
    [view setFrame:[mSelectedExtensionView bounds]] ;
  }
}

//---------------------------------------------------------------------------*

- (void) folderChoiceDidChange {
  NSArray * allSubviews = [[mSelectedFolderChoiceView subviews] copy] ;
  for (NSView * view in allSubviews) {
    [view removeFromSuperview] ;
  }
  switch (mFolderChoice) {
  case 0 : [mSelectedFolderChoiceView addSubview:mFolderFromOpenedSourceFilesView] ; break ;
  case 1 : [mSelectedFolderChoiceView addSubview:mExplicitFolderListView] ; break ;
  default : break ;
  }
  for (NSView * view in [mSelectedFolderChoiceView subviews]) {
    [view setFrame:[mSelectedFolderChoiceView bounds]] ;
  }
}

//---------------------------------------------------------------------------*

- (void) didChangeValueForKey:(NSString *) inKey {
  [super didChangeValueForKey:inKey] ;
//---
  if ([inKey isEqualToString:@"mExtensionChoice"]) {
    [self extensionChoiceDidChange] ;
  }else if ([inKey isEqualToString:@"mFolderChoice"]) {
    [self folderChoiceDidChange] ;
  }
}

//---------------------------------------------------------------------------*

#pragma mark Replace all

//---------------------------------------------------------------------------*

- (void) replaceInFile: (NSString *) inFileFullPath {
  NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
  NSString * searchString = [ud objectForKey:@"stringToFind"] ;
  // NSLog (@"searchString '%@'", searchString) ;
  NSString * replacementString = [ud objectForKey:@"replaceString"] ;
  if (nil == replacementString) {
    replacementString = @"" ;
  }
  NSUInteger searchOptions = NSCaseInsensitiveSearch ;
  if ([[ud objectForKey:@"caseSensitiveSearch"] boolValue]) {
    searchOptions = 0 ;
  }
//--- Get file contents
  NSDocumentController * dc = [NSDocumentController sharedDocumentController] ;
  OC_GGS_Document * document = [dc documentForURL:[NSURL fileURLWithPath:inFileFullPath]] ;
  NSString * fileContents = nil ;
  NSStringEncoding usedEncoding ;
  if (nil == document) {
    fileContents = [NSString
      stringWithContentsOfFile:inFileFullPath
      usedEncoding:& usedEncoding
      error:NULL
    ] ;
  }else{
    fileContents = [document sourceStringForGlobalSearch] ;
  }
//--- Perform find and replace
  BOOL contentsShouldChange = NO ;
  NSMutableString * newContents = [NSMutableString new] ;
  NSRange searchRange = {0, [fileContents length]} ;
  while (searchRange.length > 0) {
    const NSRange r = [fileContents rangeOfString:searchString options:searchOptions range:searchRange] ;
    if (r.length > 0) { // Found
      mReplaceCount ++ ;
      contentsShouldChange = YES ;
      [newContents appendString:[fileContents substringWithRange:NSMakeRange (searchRange.location, r.location - searchRange.location)]] ;
      [newContents appendString:replacementString] ;
      // NSLog (@"Found at location %u in file '%@'", r.location, inFileFullPath) ;
      searchRange.location = r.location + r.length ;
      searchRange.length = [fileContents length] - searchRange.location ;
    }else{
      [newContents appendString:[fileContents substringWithRange:searchRange]] ;
      searchRange.length = 0 ; // For exiting
    }
  }
//--- Perform replacement
  if (contentsShouldChange) {
    if (nil == document) {
      [newContents
        writeToFile:inFileFullPath
        atomically:YES
        encoding:usedEncoding
        error:nil
      ] ;
    }else{
      [document replaceSourceStringWithString:newContents] ;
    }
  }
}

//---------------------------------------------------------------------------*

- (void) recursiveReplaceInDirectory: (NSString *) inDirectoryFullPath
         recursive: (BOOL) inRecursive
         extensionList: (NSArray *) inExtensionList {
  NSFileManager * fm = [NSFileManager new] ;
  NSArray * contents = [fm contentsOfDirectoryAtPath:inDirectoryFullPath error:nil] ;
  if (nil == contents) {
  
  }else{
    for (NSString * subPath in contents) {
      if ('.' != [subPath characterAtIndex:0]) {
        NSString * fullPath = [NSString stringWithFormat:@"%@/%@", inDirectoryFullPath, subPath] ;
        BOOL isDirectory ;
        if ([fm fileExistsAtPath:fullPath isDirectory: & isDirectory]) {
          if (isDirectory && inRecursive) {
            [self recursiveReplaceInDirectory:fullPath recursive:YES extensionList:inExtensionList] ;
          }else if ((! isDirectory) && [inExtensionList containsObject:[fullPath pathExtension]]) {
            [self replaceInFile:fullPath] ;
          }
        }
      }
    }
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//   replaceAllAction                                                        *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) replaceAllAction: (id) inSender {
  mReplaceCount = 0 ;
  [mReplacementTextField setStringValue:@""] ;
//---
  NSArray * extensionList = nil ;
  switch (mExtensionChoice) {
  case 0 : extensionList = [self allTypesOfCurrentApplication] ; break ;
  case 1 : extensionList = [self extensionList] ; break ;
  default: break ;
  }
//  NSLog (@"extensionList %@", extensionList) ;
//---
  switch (mFolderChoice) {
  case 0 :
    for (NSDictionary * entry in mFolderFromOpenedSourceArray) {
      NSString * path = [entry objectForKey:@"sourcePath"] ;
      [self recursiveReplaceInDirectory:path recursive:YES extensionList:extensionList] ;
    }
    break ;
  case 1 :
    for (NSDictionary * entry in mSearchPathArray) {
      const BOOL pathSelected = [[entry objectForKey:@"pathSelected"] boolValue] ;
      if (pathSelected) {
        NSString * path = [entry objectForKey:@"path"] ;
        const BOOL recursive = [[entry objectForKey:@"recursive"] boolValue] ;
        [self recursiveReplaceInDirectory:path recursive:recursive extensionList:extensionList] ;
      }
    }
    break ;
  default:
    break ;
  }
//---
  if (0 == mReplaceCount) {
    [mReplacementTextField setStringValue:@"No replacement"] ;
  }else if (1 == mReplaceCount) {
    [mReplacementTextField setStringValue:@"1 replacement"] ;
  }else{
    [mReplacementTextField setStringValue:[NSString stringWithFormat:@"%u replacements", mReplaceCount]] ;
  }
}

//---------------------------------------------------------------------------*

@end
