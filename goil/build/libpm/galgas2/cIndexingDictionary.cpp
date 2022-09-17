//----------------------------------------------------------------------------------------------------------------------
//
//  'cIndexingDictionary': dictionary for indexing soures                                        
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2010, ..., 2012 Pierre Molinaro.
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
//----------------------------------------------------------------------------------------------------------------------

#include "galgas2/cIndexingDictionary.h"
#include "strings/C_String.h"
#include "files/C_FileManager.h"

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Entry Dictionary
#endif

//----------------------------------------------------------------------------------------------------------------------
//
//  c I n d e x E n t r y N o d e                                                                
//
//----------------------------------------------------------------------------------------------------------------------

class cIndexEntryNode {
  public: cIndexEntryNode * mInfPtr ;
  public: cIndexEntryNode * mSupPtr ;
  public: int32_t mBalance ;
  public: const C_String mKey ;
  public: TC_UniqueArray <C_String> mDescriptorArray ;

//--- Constructor
  public: cIndexEntryNode (const C_String & inKey) ;

//--- Destructor
  public: virtual ~ cIndexEntryNode (void) ;

//--- No copy
  private: cIndexEntryNode (const cIndexEntryNode &) ;
  private: cIndexEntryNode & operator = (const cIndexEntryNode &) ;
} ;

//----------------------------------------------------------------------------------------------------------------------

cIndexEntryNode::cIndexEntryNode (const C_String & inKey) :
mInfPtr (NULL),
mSupPtr (NULL),
mBalance (0),
mKey (inKey),
mDescriptorArray () {
}

//----------------------------------------------------------------------------------------------------------------------

cIndexEntryNode::~ cIndexEntryNode (void) {
  macroMyDelete (mInfPtr) ;
  macroMyDelete (mSupPtr) ;
}

//----------------------------------------------------------------------------------------------------------------------

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

//---------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

cIndexEntryNode * cIndexingDictionary::findOrAddEntry (cIndexEntryNode * & ioRootPtr,
                                                       const C_String & inKey,
                                                       bool & ioExtension) {
  cIndexEntryNode * result = NULL ;
  if (ioRootPtr == NULL) {
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

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark cIndexingDictionary
#endif

//----------------------------------------------------------------------------------------------------------------------
//
//                 cIndexingDictionary                                                           
//
//----------------------------------------------------------------------------------------------------------------------

cIndexingDictionary::cIndexingDictionary (void) :
mEntryRoot (NULL) {
}

//----------------------------------------------------------------------------------------------------------------------

cIndexingDictionary::~ cIndexingDictionary (void) {
  macroMyDelete (mEntryRoot) ;
}

//----------------------------------------------------------------------------------------------------------------------

void cIndexingDictionary::addIndexedKey (const uint32_t inIndexingKind,
                                         const C_String & inIndexedKey,
                                         const C_String & inSourceFilePath,
                                         const uint32_t inTokenLineInSource,
                                         const uint32_t inTokenLocationInSource,
                                         const uint32_t inTokenLengthInSource) {
  // printf ("INDEXING '%s', kind %d, file '%s' at [%d, %d]\n", inIndexedKey.cString (HERE), inIndexingKind, inSourceFilePath.cString (HERE), inTokenLocationInSource, inTokenLocationInSource + inTokenLengthInSource) ;
//--- File Path registering
//  bool extension = false ; // Unused here
//  const uint32_t filePathID = findOrAddFilePath (mFilePathRoot, inSourceFilePath, extension) ;
//--- Entry registering
  bool extension = false ;
  cIndexEntryNode * entryNode = findOrAddEntry (mEntryRoot, inIndexedKey, extension) ;
//--- Register index
  C_String entryDescriptor ;
  entryDescriptor << cStringWithUnsigned (inIndexingKind) ;
  entryDescriptor << ":" ;
  entryDescriptor << cStringWithUnsigned (inTokenLineInSource) ;
  entryDescriptor << ":" ;
  entryDescriptor << cStringWithUnsigned (inTokenLocationInSource) ;
  entryDescriptor << ":" ;
  entryDescriptor << cStringWithUnsigned (inTokenLengthInSource) ;
  entryDescriptor << ":" ;
  entryDescriptor << inSourceFilePath ;
  entryNode->mDescriptorArray.appendObject (entryDescriptor) ;
}

//---------------------------------------------------------------------

static void enumerateEntries (const cIndexEntryNode * inNode,
                              C_String & ioContents) {
  if (NULL != inNode) {
    enumerateEntries (inNode->mInfPtr, ioContents) ;
    ioContents << "<key>" << inNode->mKey.HTMLRepresentation () << "</key>" ;
    ioContents << "<array>" ;
    for (int32_t i=0 ; i<inNode->mDescriptorArray.count () ; i++) {
      ioContents << "<string>" << inNode->mDescriptorArray (i COMMA_HERE).HTMLRepresentation () << "</string>" ;
    }
    ioContents << "</array>" ;
    enumerateEntries (inNode->mSupPtr, ioContents) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cIndexingDictionary::generateIndexFile (const C_String & inOutputIndexFilePath) const {
  C_String contents = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                      "<!DOCTYPE plist PUBLIC \"-//Apple Computer//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">"
                      "<plist version=\"1.0\">" ;
//--- Write entries as dictionary
  contents << "<dict>" ;
  enumerateEntries (mEntryRoot, contents) ;
  contents << "</dict>" ;
//--- End of file
  contents << "</plist>" ;
  C_FileManager::writeStringToFile (contents, inOutputIndexFilePath) ;
}

//----------------------------------------------------------------------------------------------------------------------
