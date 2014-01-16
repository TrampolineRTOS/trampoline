//---------------------------------------------------------------------------*
//                                                                           *
//  AC_GALGAS_graph : Base class for GALGAS graph                            *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2010, ..., 2010 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//                                                                           *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes (France)                                   *
//                                                                           *
//  This library is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU Lesser General Public License as published    *
//  by the Free Software Foundation; either version 2 of the License, or     *
//  (at your option) any later version.                                      *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//  more details.                                                            *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef AC_GALGAS_GRAPH_CLASS_DEFINED
#define AC_GALGAS_GRAPH_CLASS_DEFINED

//---------------------------------------------------------------------------*

#include "AC_GALGAS_root.h"
#include "typeComparisonResult.h"
#include "cCollectionElement.h"

//---------------------------------------------------------------------------*

class GALGAS_uint ;
class GALGAS_string ;
class GALGAS_object ;
class GALGAS_stringlist ;
class C_Compiler ;
class capCollectionElementArray ;
class C_galgas_type_descriptor ;
class capCollectionElement ;
class cSharedGraph ;
class GALGAS__32_stringlist ;

//---------------------------------------------------------------------------*
//                                                                           *
//  A C _ G A L G A S _ g r a p h                                            *
//                                                                           *
//---------------------------------------------------------------------------*

class AC_GALGAS_graph : public AC_GALGAS_root {
//--- Private Data member
  private : cSharedGraph * mSharedGraph ;

//--- Default constructor
  public : AC_GALGAS_graph (void) ;
  
//--- Virtual destructor
  public : virtual ~ AC_GALGAS_graph (void) ;

//--- count
  public : VIRTUAL_IN_DEBUG PMUInt32 count (void) const ;

//--- isValid
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return mSharedGraph != NULL ; }

//--- drop
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--- Handle copy
  public : AC_GALGAS_graph (const AC_GALGAS_graph & inSource) ;
  public : AC_GALGAS_graph & operator = (const AC_GALGAS_graph & inSource) ;

//--- Create a new list
  protected : VIRTUAL_IN_DEBUG void makeNewEmptyGraph (LOCATION_ARGS) ;

//--------------------------------- Readers
  public : VIRTUAL_IN_DEBUG GALGAS_uint reader_count (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_stringlist reader_keyList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_uint reader_undefinedNodeCount (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_stringlist reader_undefinedNodeKeyList (LOCATION_ARGS) const ;

//--------------------------------- Modifiers
  public : VIRTUAL_IN_DEBUG void modifier_addEdge (const GALGAS_lstring & inSourceNodeKey,
                                                   const GALGAS_lstring & inTargetNodeKey
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeEdgesToNode (const GALGAS_string & inNodeName,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeEdgesToDominators (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const AC_GALGAS_graph & inOperand) const ;

//--- introspection
  public : virtual const C_galgas_type_descriptor * staticTypeDescriptor (void) const = 0 ;

//--- Description
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const PMSInt32 inIndentation) const ;

//--- Internal methods for handling graph
  protected : VIRTUAL_IN_DEBUG void reversedGraphFromGraph (const AC_GALGAS_graph & inGraph
                                                            COMMA_LOCATION_ARGS) ;

  protected : VIRTUAL_IN_DEBUG void subGraph (AC_GALGAS_graph & outResultingGraph,
                                              const GALGAS_lstringlist & inStartNodes,
                                              const GALGAS_stringset & inNodesToExclude,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  private : VIRTUAL_IN_DEBUG void insulateGraph (LOCATION_ARGS) ;

  protected : VIRTUAL_IN_DEBUG void internalAddNode (const GALGAS_lstring & inKey,
                                                     const char * inErrorMessage,
                                                     const capCollectionElement & inAttributes,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_noteNode (const GALGAS_lstring & inKey
                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG GALGAS_lstringlist reader_undefinedNodeReferenceList (LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG void internalTopologicalSort (cSharedList * & outSortedList,
                                                             GALGAS_lstringlist & outSortedNodeKeyList,
                                                             cSharedList * & outUnsortedList,
                                                             GALGAS_lstringlist & outUnsortedNodeKeyList,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG void internalNodesWithNoPredecessor (cSharedList * & outSortedList,
                                                                    GALGAS_lstringlist & outSortedNodeKeyList
                                                                    COMMA_LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG void internalNodesWithNoSuccessor (cSharedList * & outSortedList,
                                                                  GALGAS_lstringlist & outSortedNodeKeyList
                                                                  COMMA_LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG void internalDepthFirstTopologicalSort (cSharedList * & outSortedList,
                                                                       GALGAS_lstringlist & outSortedNodeKeyList,
                                                                       cSharedList * & outUnsortedList,
                                                                       GALGAS_lstringlist & outUnsortedNodeKeyList,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_string reader_graphviz (UNUSED_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS__32_stringlist reader_edges (UNUSED_LOCATION_ARGS) const ;

  friend class cSharedGraph ;
} ;

//---------------------------------------------------------------------------*

#endif
