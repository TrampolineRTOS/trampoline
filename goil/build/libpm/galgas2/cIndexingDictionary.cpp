//--------------------------------------------------------------------------------------------------
//
//  'cIndexingDictionary': dictionary for indexing soures
//
//  This file is part of libpm library
//
//  Copyright (C) 2010, ..., 2023 Pierre Molinaro.
//
//  e-mail : pierre@pcmolinaro.name
//
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)
//  any later version.
//
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//  more details.
//
//--------------------------------------------------------------------------------------------------

#include "cIndexingDictionary.h"
#include "String-class.h"
#include "FileManager.h"

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Entry Dictionary
#endif

//--------------------------------------------------------------------------------------------------
//  cIndexEntryNode
//--------------------------------------------------------------------------------------------------

class cIndexEntryNode final {
  public: cIndexEntryNode * mInfPtr ;
  public: cIndexEntryNode * mSupPtr ;
  public: int32_t mBalance ;
  public: const String mKey ;
  public: TC_UniqueArray <String> mDescriptorArray ;

//--- Constructor
  public: cIndexEntryNode (const String & inKey) ;

//--- Destructor
  public: ~ cIndexEntryNode (void) ;

//--- No copy
  private: cIndexEntryNode (const cIndexEntryNode &) = delete ;
  private: cIndexEntryNode & operator = (const cIndexEntryNode &) = delete ;
} ;

//--------------------------------------------------------------------------------------------------

cIndexEntryNode::cIndexEntryNode (const String & inKey) :
mInfPtr (nullptr),
mSupPtr (nullptr),
mBalance (0),
mKey (inKey),
mDescriptorArray () {
}

//--------------------------------------------------------------------------------------------------

cIndexEntryNode::~ cIndexEntryNode (void) {
  macroMyDelete (mInfPtr) ;
  macroMyDelete (mSupPtr) ;
}

//--------------------------------------------------------------------------------------------------

static void rotateLeft (cIndexEntryNode * & ioRootPtr) {
  cIndexEntryNode * b = ioRootPtr->mSupPtr ;
  ioRootPtr->mSupPtr = b->mInfPtr ;
  b->mInfPtr = ioRootPtr;

  if (b->mBalance >= 0) {
    ioRootPtr->mBalance++ ;
  }else{
    ioRootPtr->mBalance += 1 - b->mBalance ;
  }

  if (ioRootPtr->mBalance > 0) {
    b->mBalance += ioRootPtr->mBalance + 1 ;
  }else{
    b->mBalance++ ;
  }
  ioRootPtr = b ;
}

//--------------------------------------------------------------------------------------------------

static void rotateRight (cIndexEntryNode * & ioRootPtr) {
  cIndexEntryNode * b = ioRootPtr->mInfPtr ;
  ioRootPtr->mInfPtr = b->mSupPtr ;
  b->mSupPtr = ioRootPtr ;

  if (b->mBalance > 0) {
    ioRootPtr->mBalance += -b->mBalance - 1 ;
  }else{
    ioRootPtr->mBalance-- ;
  }
  if (ioRootPtr->mBalance >= 0) {
    b->mBalance-- ;
  }else{
    b->mBalance += ioRootPtr->mBalance - 1 ;
  }
  ioRootPtr = b ;
}

//--------------------------------------------------------------------------------------------------

cIndexEntryNode * cIndexingDictionary::findOrAddEntry (cIndexEntryNode * & ioRootPtr,
                                                       const String & inKey,
                                                       bool & ioExtension) {
  cIndexEntryNode * result = nullptr ;
  if (ioRootPtr == nullptr) {
    macroMyNew (ioRootPtr, cIndexEntryNode (inKey)) ;
    ioExtension = true ;
    result = ioRootPtr ;
  }else{
    macroValidPointer (ioRootPtr) ;
    const int32_t comparaison = ioRootPtr->mKey.compare (inKey) ;
    if (comparaison > 0) {
      result = findOrAddEntry (ioRootPtr->mInfPtr, inKey, ioExtension) ;
      if (ioExtension) {
        ioRootPtr->mBalance ++ ;
        if (ioRootPtr->mBalance == 0) {
          ioExtension = false;
        }else if (ioRootPtr->mBalance == 2) {
          if (ioRootPtr->mInfPtr->mBalance == -1) {
            rotateLeft (ioRootPtr->mInfPtr) ;
          }
          rotateRight (ioRootPtr) ;
          ioExtension = false;
        }
      }
    }else if (comparaison < 0) {
      result = findOrAddEntry (ioRootPtr->mSupPtr, inKey, ioExtension) ;
      if (ioExtension) {
        ioRootPtr->mBalance-- ;
        if (ioRootPtr->mBalance == 0) {
          ioExtension = false ;
        }else if (ioRootPtr->mBalance == -2) {
          if (ioRootPtr->mSupPtr->mBalance == 1) {
            rotateRight (ioRootPtr->mSupPtr) ;
          }
          rotateLeft (ioRootPtr) ;
          ioExtension = false;
        }
      }
    }else{ // Entry already exists
      result = ioRootPtr ;
      ioExtension = false ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark cIndexingDictionary
#endif

//--------------------------------------------------------------------------------------------------
//                 cIndexingDictionary
//--------------------------------------------------------------------------------------------------

cIndexingDictionary::cIndexingDictionary (void) :
mEntryRoot (nullptr) {
}

//--------------------------------------------------------------------------------------------------

cIndexingDictionary::~ cIndexingDictionary (void) {
  macroMyDelete (mEntryRoot) ;
}

//--------------------------------------------------------------------------------------------------

void cIndexingDictionary::addIndexedKey (const uint32_t inIndexingKind,
                                         const String & inIndexedString,
                                         const String & inSourceFilePath,
                                         const uint32_t inTokenLineInSource,
                                         const uint32_t inTokenLocationInSource,
                                         const uint32_t inTokenLengthInSource) {
//--- Entry registering
  bool extension = false ;
  cIndexEntryNode * entryNode = findOrAddEntry (mEntryRoot, inIndexedString, extension) ;
//--- Register index
  String entryDescriptor ;
  entryDescriptor.appendUnsigned (inIndexingKind) ;
  entryDescriptor.appendCString (":") ;
  entryDescriptor.appendUnsigned (inTokenLineInSource) ;
  entryDescriptor.appendCString (":") ;
  entryDescriptor.appendUnsigned (inTokenLocationInSource) ;
  entryDescriptor.appendCString (":") ;
  entryDescriptor.appendUnsigned (inTokenLengthInSource) ;
  entryDescriptor.appendCString (":") ;
  entryDescriptor.appendString (inSourceFilePath) ;
  entryNode->mDescriptorArray.appendObject (entryDescriptor) ;
}

//--------------------------------------------------------------------------------------------------

static void enumerateEntries (const cIndexEntryNode * inNode,
                              String & ioContents) {
  if (nullptr != inNode) {
    enumerateEntries (inNode->mInfPtr, ioContents) ;
    ioContents.appendCString ("<key>") ;
    ioContents.appendString (inNode->mKey.HTMLRepresentation ()) ;
    ioContents.appendCString ("</key>") ;
    ioContents.appendCString ("<array>") ;
    for (int32_t i=0 ; i<inNode->mDescriptorArray.count () ; i++) {
      ioContents.appendCString ("<string>") ;
      ioContents.appendString (inNode->mDescriptorArray (i COMMA_HERE).HTMLRepresentation ()) ;
      ioContents.appendCString ("</string>") ;
    }
    ioContents.appendCString ("</array>") ;
    enumerateEntries (inNode->mSupPtr, ioContents) ;
  }
}

//--------------------------------------------------------------------------------------------------

void cIndexingDictionary::generateIndexFile (const String & inOutputIndexFilePath) const {
  String contents = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                    "<!DOCTYPE plist PUBLIC \"-//Apple Computer//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">"
                    "<plist version=\"1.0\">" ;
//--- Write entries as dictionary
  contents.appendCString ("<dict>") ;
  enumerateEntries (mEntryRoot, contents) ;
  contents.appendCString ("</dict>") ;
//--- End of file
  contents.appendCString ("</plist>") ;
  FileManager::writeStringToFile (contents, inOutputIndexFilePath) ;
}

//--------------------------------------------------------------------------------------------------
