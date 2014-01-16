//---------------------------------------------------------------------------*
//                                                                           *
//  C_DirectedGraph : algorithms on ordered graphs                           *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2013, ..., 2013 Pierre Molinaro.                           *
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

#ifndef C_DIRECTED_GRAPH_CLASS_DEFINED
#define C_DIRECTED_GRAPH_CLASS_DEFINED

//---------------------------------------------------------------------------*

#include "collections/TC_Array.h"
#include "utilities/C_UIntSet.h"
#include "strings/C_String.h"

//---------------------------------------------------------------------------*

typedef struct {
  PMUInt32 mSource ;
  PMUInt32 mTarget ;
} cEdge ;

//---------------------------------------------------------------------------*

class C_DirectedGraph {
//--- Default constructor
  public : C_DirectedGraph (void) ;

//--- Example
  public : static void example (void) ;
  
//--- Methods
  public : void addNode (const PMUInt32 inNodeIndex) ;

  public : void addNodes (const C_UIntSet inNodes) ;

  public : void removeNode (const PMUInt32 inNodeIndex) ;

  public : void addEdge (const PMUInt32 inSourceNodeIndex,
                         const PMUInt32 inTargetNodeIndex) ;

  public : void print (void) const ;

//--- Accessors
  public : PMUInt32 unusedNodeIndex (void) const ;

  public : C_String graphvizString (const TC_UniqueArray <C_String> & inNodeNameArray) const ;
  
  public : void getNodeBoolArray (TC_UniqueArray <bool> & outNodes) const ;
  
  public : void getNodeValueArray (TC_UniqueArray <PMUInt32> & outNodes) const ;
  
  public : bool isNodeDefined (const PMUInt32 inNodeIndex) const ;
  
  public : PMUInt32 nodeCount (void) const ;
  
  public : PMUInt32 edgeCount (void) const ;
  
  public : void getNodesWithNoPredecessor (TC_UniqueArray <PMUInt32> & outNodes) const ;
  
  public : void getNodesWithNoSuccessor (TC_UniqueArray <PMUInt32> & outNodes) const ;
  
  public : void getNodesInvolvedInCircularities (TC_UniqueArray <PMUInt32> & outNodes) const ;
  
  public : void getDominators (TC_UniqueArray <C_UIntSet> & outDominators
                               COMMA_LOCATION_ARGS) const ;
  
  public : void removeEdgesToDominator (LOCATION_ARGS) ;
  
  public : void removeEdgesToNode (const PMUInt32 inNodeIndex COMMA_LOCATION_ARGS) ;
  
  public : void getEdges (TC_UniqueArray <cEdge> & outEdges) const ;
  
  public : void topologicalSort (TC_UniqueArray <PMUInt32> & outSortedNodes,
                                 TC_UniqueArray <PMUInt32> & outUnsortedNodes) const ;
  
  public : void depthFirstTopologicalSort (TC_UniqueArray <PMUInt32> & outSortedNodes,
                                           TC_UniqueArray <PMUInt32> & outUnsortedNodes) const ;
  
  public : C_DirectedGraph reversedGraph (void) const ;
  
  public : C_DirectedGraph subGraphFromNodes (const C_UIntSet & inStartNodes,
                                              const C_UIntSet & inNodesToExclude) const ;
  
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : void checkGraph (LOCATION_ARGS) const ;
  #endif

//--- Attributes
  private : C_UIntSet mNodeDefinition ;
  private : TC_Array <C_UIntSet> mEdges ;
  private : TC_Array <C_UIntSet> mReverseEdges ;
} ;

//---------------------------------------------------------------------------*

#endif
