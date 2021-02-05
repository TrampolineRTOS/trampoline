//----------------------------------------------------------------------------------------------------------------------
//
//  C_DirectedGraph : algorithms on ordered graphs                                               
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2013, ..., 2016 Pierre Molinaro.
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

#include "collections/TC_Array.h"
#include "C_UIntSet.h"
#include "strings/C_String.h"

//----------------------------------------------------------------------------------------------------------------------

//#define USE_NODE_NAMES_WITH_SUBGRAPH_COMPUTATION

//----------------------------------------------------------------------------------------------------------------------

typedef struct {
  uint32_t mSource ;
  uint32_t mTarget ;
} cEdge ;

//----------------------------------------------------------------------------------------------------------------------

class C_DirectedGraph {
//--- Default constructor
  public : C_DirectedGraph (void) ;

//--- Example
  public : static void example (void) ;
  
//--- Methods
  public : void addNode (const uint32_t inNodeIndex) ;

  public : void addNodes (const C_UIntSet inNodes) ;

  public : void removeNode (const uint32_t inNodeIndex) ;

  public : void addEdge (const uint32_t inSourceNodeIndex,
                         const uint32_t inTargetNodeIndex) ;

  public : void print (void) const ;

//--- Accessors
  public : uint32_t unusedNodeIndex (void) const ;

  public : C_String graphvizString (const TC_UniqueArray <C_String> & inNodeNameArray) const ;
  
  public : void getNodeBoolArray (TC_UniqueArray <bool> & outNodes) const ;
  
  public : void getNodeValueArray (TC_UniqueArray <uint32_t> & outNodes) const ;
  
  public : bool isNodeDefined (const uint32_t inNodeIndex) const ;
  
  public : uint32_t nodeCount (void) const ;
  
  public : uint32_t edgeCount (void) const ;
  
  public : void getNodesWithNoPredecessor (TC_UniqueArray <uint32_t> & outNodes) const ;
  
  public : void getNodesWithNoSuccessor (TC_UniqueArray <uint32_t> & outNodes) const ;
  
  public : void getNodesInvolvedInCircularities (TC_UniqueArray <uint32_t> & outNodes) const ;
  
  public : void getDominators (TC_UniqueArray <C_UIntSet> & outDominators
                               COMMA_LOCATION_ARGS) const ;
  
  public : void removeEdgesToDominator (LOCATION_ARGS) ;
  
  public : void removeEdgesToNode (const uint32_t inNodeIndex COMMA_LOCATION_ARGS) ;
  
  public : void getEdges (TC_UniqueArray <cEdge> & outEdges) const ;
  
  public : void topologicalSort (TC_UniqueArray <uint32_t> & outSortedNodes,
                                 TC_UniqueArray <uint32_t> & outUnsortedNodes) const ;
  
  public : void depthFirstTopologicalSort (TC_UniqueArray <uint32_t> & outSortedNodes,
                                           TC_UniqueArray <uint32_t> & outUnsortedNodes) const ;
  
  public : C_DirectedGraph reversedGraph (void) const ;
  
  public : C_DirectedGraph subGraphFromNodes (const C_UIntSet & inStartNodes,
                                              #ifdef USE_NODE_NAMES_WITH_SUBGRAPH_COMPUTATION
                                                const TC_UniqueArray <C_String> & inNodeNames,
                                              #endif
                                              const C_UIntSet & inNodesToExclude) const ;
  
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : void checkGraph (LOCATION_ARGS) const ;
  #endif

//--- Attributes
  private : C_UIntSet mNodes ;
  private : TC_Array <C_UIntSet> mEdges ;
  private : TC_Array <C_UIntSet> mReverseEdges ;
} ;

//----------------------------------------------------------------------------------------------------------------------
