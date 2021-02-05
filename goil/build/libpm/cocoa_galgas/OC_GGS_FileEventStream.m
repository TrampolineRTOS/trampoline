//
//  OC_GGS_FileEventStream.m
//  galgas-developer-v3
//
//  Created by Pierre Molinaro on 14/07/2015.
//----------------------------------------------------------------------------------------------------------------------

// https://stackoverflow.com/questions/22981497/fseventstream-filter-events-generated-from-my-own-application

//----------------------------------------------------------------------------------------------------------------------

#import "OC_GGS_DocumentData.h"
#import "OC_GGS_FileEventStream.h"

//----------------------------------------------------------------------------------------------------------------------

static NSMutableArray * gFileEventStreamArray = nil ;

//----------------------------------------------------------------------------------------------------------------------

@interface OC_GGS_FileEventStream : NSObject {
  @private FSEventStreamRef mFSEventStream ;
  @private NSMutableArray * mDocuments ;
}

- (instancetype) initWithDocument: (OC_GGS_DocumentData *) inDocument ;

@end

//----------------------------------------------------------------------------------------------------------------------

@implementation OC_GGS_FileEventStream

  //····················································································································

  - (void) callbackMethodForPath: (NSString *) inPath
           flag: (FSEventStreamEventFlags) inEventFlag {
   // NSLog (@"path '%@' flag:%X", inPath, inEventFlag) ; // §
    for (OC_GGS_DocumentData * document in mDocuments) {
      if ([document.fileURL.path isEqualToString: inPath]) {
        [document fileDidChangeInFileSystem] ;
      }
    }
  }

  //····················································································································

  static void mycallback (ConstFSEventStreamRef streamRef,
                          void* clientCallBackInfo,
                          size_t numEvents,
                          void *eventPaths,
                          const FSEventStreamEventFlags eventFlags[],
                          const FSEventStreamEventId eventIds[]) {
    OC_GGS_FileEventStream * object = (__bridge OC_GGS_FileEventStream *) clientCallBackInfo ;
    NSArray * eventPathArray = (__bridge NSArray *) eventPaths ;
    NSUInteger idx = 0 ;
    for (NSString * path in eventPathArray) {
      [object callbackMethodForPath:path flag:eventFlags [idx]] ;
      idx ++ ;
    }
  }

  //····················································································································

  - (instancetype) initWithDocument: (OC_GGS_DocumentData *) inDocument {
    self = [super init] ;
    if (self) {
      mDocuments = [NSMutableArray new] ;
      [mDocuments addObject:inDocument] ;
      NSString * path = inDocument.fileURL.path ;
      NSArray * pathsToWatch = [NSArray arrayWithObject: path] ;
    //  NSLog (@"pathsToWatch %@", pathsToWatch) ;
      const CFAbsoluteTime latency = 1.0 ; // Latency in seconds
      FSEventStreamContext context = {
        0,
        (__bridge void *) self,
        CFRetain,
        CFRelease,
        CFCopyDescription
      } ;
      const FSEventStreamCreateFlags creationFlags =
          kFSEventStreamCreateFlagNoDefer
        | kFSEventStreamCreateFlagUseCFTypes
        | kFSEventStreamCreateFlagWatchRoot
        | kFSEventStreamCreateFlagFileEvents
        | kFSEventStreamCreateFlagMarkSelf // §§
        | kFSEventStreamCreateFlagIgnoreSelf // Do not report events from current application
      ;
//      const FSEventStreamCreateFlags creationFlags = kFSEventStreamCreateFlagNone ;
       mFSEventStream = FSEventStreamCreate (
        NULL,
        mycallback,
        & context,
        (__bridge CFArrayRef) pathsToWatch,
        kFSEventStreamEventIdSinceNow,
        latency,
        creationFlags
      ) ;
      FSEventStreamScheduleWithRunLoop (mFSEventStream, CFRunLoopGetMain(), kCFRunLoopDefaultMode);
      FSEventStreamStart (mFSEventStream) ;
    }
    return self ;
  }

  //····················································································································

  - (BOOL) tryToAddDocument: (OC_GGS_DocumentData *) inDocument {
    NSString * path = inDocument.fileURL.path.stringByDeletingLastPathComponent ;
    OC_GGS_DocumentData * firstDocument = [mDocuments objectAtIndex: 0] ;
    NSString * referencePath = firstDocument.fileURL.path.stringByDeletingLastPathComponent ;
    const BOOL result = [path isEqualToString: referencePath] ;
    if (result) {
      [mDocuments addObject: inDocument] ;
    }
    return result ;
  }

  //····················································································································

  - (BOOL) tryToRemoveDocument: (OC_GGS_DocumentData *) inDocument { // Yes if current object should be removed
    const NSUInteger idx = [mDocuments indexOfObject:inDocument] ;
    if (idx != NSNotFound) {
      [mDocuments removeObjectAtIndex:idx] ;
    }
    return mDocuments.count == 0 ;
  }

  //····················································································································

  - (void) uninstallFileSystemMonitoring {
    FSEventStreamStop (mFSEventStream) ;
    FSEventStreamInvalidate (mFSEventStream) ;
    FSEventStreamRelease (mFSEventStream) ;
    mFSEventStream = NULL ;
  }

  //····················································································································

@end

//----------------------------------------------------------------------------------------------------------------------

void addFileEventStreamForDocument (OC_GGS_DocumentData * inDocument) {
  if (nil == gFileEventStreamArray) {
    gFileEventStreamArray = [NSMutableArray new] ;
  }
  BOOL found = NO ;
  for (OC_GGS_FileEventStream * fes in gFileEventStreamArray) {
    found = [fes tryToAddDocument:inDocument] ;
    if (found) {
      break ;
    }
  }
  if (! found) {
    OC_GGS_FileEventStream * fes = [[OC_GGS_FileEventStream alloc] initWithDocument:inDocument] ;
    [gFileEventStreamArray addObject:fes] ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void removeFileEventStreamForDocument (OC_GGS_DocumentData * inDocument) {
  OC_GGS_FileEventStream * objectToRemove = nil ;
  for (OC_GGS_FileEventStream * fes in gFileEventStreamArray) {
    const BOOL remove = [fes tryToRemoveDocument:inDocument] ;
    if (remove) {
      objectToRemove = fes ;
    }
  }
  if (nil != objectToRemove) {
    [gFileEventStreamArray removeObject:objectToRemove] ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
