//----------------------------------------------------------------------------------------------------------------------
//
//  AC_GALGAS_graph : Base class for GALGAS graph                                                
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2008, ..., 2022 Pierre Molinaro.
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

#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include "galgas2/AC_GALGAS_root.h"
#include "galgas2/typeComparisonResult.h"
#include "galgas2/cCollectionElement.h"

//----------------------------------------------------------------------------------------------------------------------
//
//  A C _ G A L G A S _ g r a p h                                                                
//
//----------------------------------------------------------------------------------------------------------------------

class AC_GALGAS_graph : public AC_GALGAS_root {
//--- Private Data member
  private: class cSharedGraph * mSharedGraph ;

//--- Default constructor
  public: AC_GALGAS_graph (void) ;
  
//--- Virtual destructor
  public: virtual ~ AC_GALGAS_graph (void) ;

//--- count
  public: VIRTUAL_IN_DEBUG uint32_t count (void) const ;

//--- isValid
  public: VIRTUAL_IN_DEBUG inline bool isValid (void) const { return mSharedGraph != NULL ; }

//--- drop
  public: VIRTUAL_IN_DEBUG void drop (void) ;

//--- Handle copy
  public: AC_GALGAS_graph (const AC_GALGAS_graph & inSource) ;
  public: AC_GALGAS_graph & operator = (const AC_GALGAS_graph & inSource) ;

//--- Create a new list
  protected: VIRTUAL_IN_DEBUG void makeNewEmptyGraph (LOCATION_ARGS) ;

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG GALGAS_uint getter_count (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_bool getter_isNodeDefined (const GALGAS_string & inKey COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_stringlist getter_keyList (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_lstringlist getter_lkeyList (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_uint getter_undefinedNodeCount (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_stringlist getter_undefinedNodeKeyList (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_location getter_locationForKey (const GALGAS_string & inKey,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_addEdge (const GALGAS_lstring & inSourceNodeKey,
                                                 const GALGAS_lstring & inTargetNodeKey
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeEdgesToNode (const GALGAS_string & inNodeName,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeEdgesToDominators (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const AC_GALGAS_graph & inOperand) const ;

//--- introspection
  public: virtual const C_galgas_type_descriptor * staticTypeDescriptor (void) const = 0 ;

//--- Description
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;

//--- Internal methods for handling graph
  protected: VIRTUAL_IN_DEBUG void reversedGraphFromGraph (const AC_GALGAS_graph & inGraph
                                                            COMMA_LOCATION_ARGS) ;

  protected: VIRTUAL_IN_DEBUG void subGraph (AC_GALGAS_graph & outResultingGraph,
                                              const GALGAS_lstringlist & inStartNodes,
                                              const GALGAS_stringset & inNodesToExclude,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;


  protected: VIRTUAL_IN_DEBUG capCollectionElementArray graph (void) const ;

  private: VIRTUAL_IN_DEBUG void insulateGraph (LOCATION_ARGS) ;

  protected: VIRTUAL_IN_DEBUG void internalAddNode (const GALGAS_lstring & inKey,
                                                     const char * inErrorMessage,
                                                     const capCollectionElement & inAttributes,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_noteNode (const GALGAS_lstring & inKey
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG GALGAS_lstringlist getter_undefinedNodeReferenceList (LOCATION_ARGS) const ;

  protected: VIRTUAL_IN_DEBUG void internalTopologicalSort (capCollectionElementArray & outSortedList,
                                                             GALGAS_lstringlist & outSortedNodeKeyList,
                                                             capCollectionElementArray & outUnsortedList,
                                                             GALGAS_lstringlist & outUnsortedNodeKeyList,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;

  protected: VIRTUAL_IN_DEBUG void internalFindCircularities (capCollectionElementArray & outInfoList,
                                                               GALGAS_lstringlist & outNodeKeyList
                                                               COMMA_UNUSED_LOCATION_ARGS) const ;

  protected: VIRTUAL_IN_DEBUG void internalNodesWithNoPredecessor (capCollectionElementArray & outSortedList,
                                                                    GALGAS_lstringlist & outSortedNodeKeyList
                                                                    COMMA_LOCATION_ARGS) const ;

  protected: VIRTUAL_IN_DEBUG void internalNodesWithNoSuccessor (capCollectionElementArray & outSortedList,
                                                                  GALGAS_lstringlist & outSortedNodeKeyList
                                                                  COMMA_LOCATION_ARGS) const ;


  protected: VIRTUAL_IN_DEBUG void internalDepthFirstTopologicalSort (capCollectionElementArray & outSortedList,
                                                                       GALGAS_lstringlist & outSortedNodeKeyList,
                                                                       capCollectionElementArray & outUnsortedList,
                                                                       GALGAS_lstringlist & outUnsortedNodeKeyList,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_string getter_graphviz (UNUSED_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS__32_stringlist getter_edges (UNUSED_LOCATION_ARGS) const ;

  friend class cSharedGraph ;
} ;

//----------------------------------------------------------------------------------------------------------------------
#pragma once
