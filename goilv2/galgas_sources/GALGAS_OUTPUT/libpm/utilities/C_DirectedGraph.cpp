//-----------------------------------------------------------------------------*
//                                                                             *
//  C_DirectedGraph : algorithms on ordered graphs                             *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2013, ..., 2013 Pierre Molinaro.                             *
//                                                                             *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
//                                                                             *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes  *
//  ECN, École Centrale de Nantes (France)                                     *
//                                                                             *
//  This library is free software; you can redistribute it and/or modify it    *
//  under the terms of the GNU Lesser General Public License as published      *
//  by the Free Software Foundation; either version 2 of the License, or       *
//  (at your option) any later version.                                        *
//                                                                             *
//  This program is distributed in the hope it will be useful, but WITHOUT     *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or      *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for   *
//  more details.                                                              *
//                                                                             *
//-----------------------------------------------------------------------------*

#include "utilities/C_DirectedGraph.h"

//-----------------------------------------------------------------------------*

#include <stdio.h>

//-----------------------------------------------------------------------------*

C_DirectedGraph::C_DirectedGraph (void) :
mNodeDefinition (),
mEdges (),
mReverseEdges () {
}

//-----------------------------------------------------------------------------*

C_DirectedGraph C_DirectedGraph::reversedGraph (void) const {
  C_DirectedGraph result ;
  result.mNodeDefinition = mNodeDefinition ;
  result.mEdges = mReverseEdges ;
  result.mReverseEdges = mEdges ;
  #ifndef DO_NOT_GENERATE_CHECKINGS
    result.checkGraph (HERE) ;
  #endif
  return result ;
}

//-----------------------------------------------------------------------------*

void C_DirectedGraph::addNode (const uint32_t inNodeIndex) {
  mNodeDefinition.add (inNodeIndex) ;
  while (((int32_t) inNodeIndex) >= mEdges.count ()) {
    mEdges.addObject (C_UIntSet ()) ;
    mReverseEdges.addObject (C_UIntSet ()) ;
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkGraph (HERE) ;
  #endif
}

//-----------------------------------------------------------------------------*

void C_DirectedGraph::addNodes (const C_UIntSet inNodes) {
  mNodeDefinition |= inNodes ;
  const uint32_t lastPlusOne = mNodeDefinition.firstValueNotIsSet () ;
  while (lastPlusOne > (uint32_t) mEdges.count ()) {
    mEdges.addObject (C_UIntSet ()) ;
    mReverseEdges.addObject (C_UIntSet ()) ;
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkGraph (HERE) ;
  #endif
}

//-----------------------------------------------------------------------------*

void C_DirectedGraph::removeNode (const uint32_t inNodeIndex) {
  if (inNodeIndex < (uint32_t) mEdges.count ()) {
    mNodeDefinition.remove (inNodeIndex) ;
    const C_UIntSet targetSet = mEdges ((int32_t) inNodeIndex COMMA_HERE) ;
    TC_Array <uint32_t> targetList ; targetSet.getValueArray (targetList) ;
    for (int32_t i=0 ; i<targetList.count () ; i++) {
      const uint32_t targetIndex = targetList (i COMMA_HERE) ;
      mReverseEdges ((int32_t) targetIndex COMMA_HERE).remove (inNodeIndex) ;
    }
    mEdges.setObjectAtIndex (C_UIntSet (), (int32_t) inNodeIndex COMMA_HERE) ;
  }
  const uint32_t f = mNodeDefinition.firstValueNotIsSet () ;
  while (f < (uint32_t) mEdges.count ()) {
    mEdges.removeLastObject (HERE) ;
    mReverseEdges.removeLastObject (HERE) ;
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkGraph (HERE) ;
  #endif
}

//-----------------------------------------------------------------------------*

void C_DirectedGraph::getNodeBoolArray (TC_UniqueArray <bool> & outNodes) const {
  mNodeDefinition.getBoolValueArray (outNodes) ;
}

//-----------------------------------------------------------------------------*

void C_DirectedGraph::getNodeValueArray (TC_UniqueArray <uint32_t> & outNodes) const {
  mNodeDefinition.getValueArray (outNodes) ;
}

//-----------------------------------------------------------------------------*

bool C_DirectedGraph::isNodeDefined (const uint32_t inNodeIndex) const {
  return mNodeDefinition.contains (inNodeIndex) ;
}

//-----------------------------------------------------------------------------*

uint32_t C_DirectedGraph::nodeCount (void) const {
  return mNodeDefinition.count () ;
}

//-----------------------------------------------------------------------------*

uint32_t C_DirectedGraph::edgeCount (void) const {
  uint32_t result = 0 ;
  for (int32_t i=0 ; i<mEdges.count () ; i++) {
    if (isNodeDefined ((uint32_t) i)) {
      result += mEdges (i COMMA_HERE).count () ;
    }
  }
  return result ;
}

//-----------------------------------------------------------------------------*

uint32_t C_DirectedGraph::unusedNodeIndex (void) const {
  uint32_t result = nodeCount () ;
  while (isNodeDefined (result)) {
    result ++ ;
  }
  return result ;
}

//-----------------------------------------------------------------------------*

C_String C_DirectedGraph::graphvizString (const TC_UniqueArray <C_String> & inNodeNameArray) const {
  C_String s = "digraph G {\n" ;
  for (int32_t i=0 ; i<mEdges.count () ; i++) {
    if (isNodeDefined ((uint32_t) i)) {
      s << "  \"" << inNodeNameArray (i COMMA_HERE) << "\" ;\n" ;
      const C_UIntSet targetSet = mEdges (i COMMA_HERE) ;
      TC_Array <uint32_t> targetList ; targetSet.getValueArray (targetList) ;
      for (int32_t j=0 ; j<targetList.count () ; j++) {
        const uint32_t targetIndex = targetList (j COMMA_HERE) ;
        s << "  \"" << inNodeNameArray (i COMMA_HERE) << "\" -> \"" << inNodeNameArray ((int32_t) targetIndex COMMA_HERE) << "\" ;\n" ;
      }
    }
  }
  s << "}\n" ;
  return s ;
}

//-----------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void C_DirectedGraph::checkGraph (LOCATION_ARGS) const {
    MF_AssertThere (mEdges.count () == mReverseEdges.count (), "mEdges.count () %lld != mReverseEdges.count () %lld", mEdges.count (), mReverseEdges.count ()) ;
    MF_AssertThere (mNodeDefinition.firstValueNotIsSet () == (uint32_t) (mEdges.count ()), "mNodeDefinition.firstValueNotIsSet () %lld != mEdges.count () %lld", mNodeDefinition.firstValueNotIsSet (), mEdges.count ()) ;
  //---
    for (uint32_t i=0 ; i<(uint32_t) mEdges.count () ; i++) {
      TC_UniqueArray <uint32_t> targetList ; mEdges ((int32_t) i COMMA_HERE).getValueArray (targetList) ;
      for (int32_t j=0 ; j<targetList.count () ; j++) {
        const uint32_t target = targetList (j COMMA_HERE) ;
        MF_AssertThere (mReverseEdges ((int32_t) target COMMA_HERE).contains (i), "! mReverseEdges (%lld COMMA_HERE).contains (%lld)", target, i) ;
      }
    }
  //---
    for (uint32_t i=0 ; i<(uint32_t) mReverseEdges.count () ; i++) {
      TC_UniqueArray <uint32_t> sourceList ; mReverseEdges ((int32_t) i COMMA_HERE).getValueArray (sourceList) ;
      for (int32_t j=0 ; j<sourceList.count () ; j++) {
        const uint32_t source = sourceList (j COMMA_HERE) ;
        MF_AssertThere (mEdges ((int32_t) source COMMA_HERE).contains (i), "! mEdges (%lld COMMA_HERE).contains (%lld)", source, i) ;
      }
    }
  }
#endif

//-----------------------------------------------------------------------------*

void C_DirectedGraph::getEdges (TC_UniqueArray <cEdge> & outEdges) const {
  outEdges.setCountToZero () ;
  for (int32_t i=0 ; i<mEdges.count () ; i++) {
    TC_UniqueArray <uint32_t> targetList ; mEdges (i COMMA_HERE).getValueArray (targetList) ;
    for (int32_t j=0 ; j<targetList.count () ; j++) {
      const cEdge edge = {(uint32_t) i, targetList (j COMMA_HERE)} ;
      outEdges.addObject (edge) ;
    }
  }
}

//-----------------------------------------------------------------------------*

void C_DirectedGraph::getNodesWithNoPredecessor (TC_UniqueArray <uint32_t> & outNodes) const {
  outNodes.setCountToZero () ;
  for (uint32_t i=0 ; i<(uint32_t) mReverseEdges.count () ; i++) {
    if (isNodeDefined (i) && mReverseEdges ((int32_t) i COMMA_HERE).isEmpty ()) {
      outNodes.addObject (i) ;
    }
  }
}

//-----------------------------------------------------------------------------*

void C_DirectedGraph::getNodesWithNoSuccessor (TC_UniqueArray <uint32_t> & outNodes) const {
  outNodes.setCountToZero () ;
  for (uint32_t i=0 ; i<(uint32_t) mEdges.count () ; i++) {
    if (isNodeDefined (i) && mEdges ((int32_t) i COMMA_HERE).isEmpty ()) {
      outNodes.addObject (i) ;
    }
  }
}

//-----------------------------------------------------------------------------*

void C_DirectedGraph::getNodesInvolvedInCircularities (TC_UniqueArray <uint32_t> & outNodes) const {
  outNodes.setCountToZero () ;
//--- Get working copies
  TC_UniqueArray <bool> nodes ; getNodeBoolArray (nodes) ;
  TC_UniqueArray <uint32_t> successorCount ;
  TC_UniqueArray <uint32_t> predecessorCount ;
  for (int32_t i=0 ; i<mEdges.count () ; i++) {
    successorCount.addObject (mEdges (i COMMA_HERE).count ()) ;
  }
  for (int32_t i=0 ; i<mReverseEdges.count () ; i++) {
    predecessorCount.addObject (mReverseEdges (i COMMA_HERE).count ()) ;
  }
//--- Eliminate nodes that have no successor or no predecessor
  bool loop = true ;
  while (loop) {
    loop = false ;
    for (int32_t i=0 ; i<nodes.count () ; i++) {
      if (nodes (i COMMA_HERE) && ((successorCount (i COMMA_HERE) == 0) || (predecessorCount (i COMMA_HERE) == 0))) {
        loop = true ;
        nodes.setObjectAtIndex (false, i COMMA_HERE) ;
        TC_UniqueArray <uint32_t> s ; mEdges (i COMMA_HERE).getValueArray (s) ;
        for (int32_t j=0 ; j<s.count () ; j++) {
          predecessorCount.decrementAtIndex ((int32_t) s (j COMMA_HERE) COMMA_HERE) ;
        }
        mReverseEdges (i COMMA_HERE).getValueArray (s) ;
        for (int32_t j=0 ; j<s.count () ; j++) {
          successorCount.decrementAtIndex ((int32_t) s (j COMMA_HERE) COMMA_HERE) ;
        }
      }
    }
  }

//--- Add circular nodes
  for (int32_t i=0 ; i<nodes.count () ; i++) {
    if (nodes (i COMMA_HERE)) {
      outNodes.addObject ((uint32_t) i) ;
    }
  }
}

//-----------------------------------------------------------------------------*

C_DirectedGraph C_DirectedGraph::subGraphFromNodes (const C_UIntSet & inStartNodes,
                                                    const C_UIntSet & inNodesToExclude) const {
  TC_UniqueArray <bool> nodeBoolArray ; mNodeDefinition.getBoolValueArray (nodeBoolArray) ;
  C_DirectedGraph result ;  
  C_UIntSet nodeSet = inStartNodes ;
  nodeSet -= inNodesToExclude ;
  result.addNodes (nodeSet) ;
  bool loop = true ;
  while (loop) {
    loop = false ;
    TC_UniqueArray <uint32_t> sourceNodeArray ; nodeSet.getValueArray (sourceNodeArray) ;
    for (int32_t i=0 ; i<sourceNodeArray.count () ; i++) {
      const uint32_t sourceNodeIndex = sourceNodeArray (i COMMA_HERE) ;
      if (nodeBoolArray ((int32_t) sourceNodeIndex COMMA_HERE)) {
        loop = true ;
        nodeBoolArray.setObjectAtIndex (false, (int32_t) sourceNodeIndex COMMA_HERE) ;
        C_UIntSet s = mEdges ((int32_t) sourceNodeIndex COMMA_HERE) ;
        s -= inNodesToExclude ;
        nodeSet |= s ;
        TC_UniqueArray <uint32_t> targetNodeArray ; s.getValueArray (targetNodeArray) ;
        for (int32_t j=0 ; j<targetNodeArray.count () ; j++) {
          result.addEdge (sourceNodeIndex, targetNodeArray (j COMMA_HERE)) ;
        }
      }
    }
  }
  return result ;
}

//-----------------------------------------------------------------------------*

void C_DirectedGraph::removeEdgesToNode (const uint32_t inNodeIndex
                                         COMMA_LOCATION_ARGS) {
//--- get nodes that have edges to this node
  const C_UIntSet nodeSet = mReverseEdges ((int32_t) inNodeIndex COMMA_THERE) ;
//--- Remove edges in reverse egde array
  mReverseEdges.setObjectAtIndex (C_UIntSet (), (int32_t) inNodeIndex COMMA_THERE) ;
//--- Remove edge in direct edge array
  TC_UniqueArray <uint32_t> sourceNodeArray ; nodeSet.getValueArray (sourceNodeArray) ;
  for (int32_t i=0 ; i<sourceNodeArray.count () ; i++) {
    const uint32_t sourceNodeIndex = sourceNodeArray (i COMMA_HERE) ;
    mEdges ((int32_t) sourceNodeIndex COMMA_HERE).remove (inNodeIndex) ;
  }
//--- Check
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkGraph (HERE) ;
  #endif
}

//-----------------------------------------------------------------------------*

void C_DirectedGraph::addEdge (const uint32_t inSourceNodeIndex,
                              const uint32_t inTargetNodeIndex) {
  addNode (inSourceNodeIndex) ;
  addNode (inTargetNodeIndex) ;
  mEdges ((int32_t) inSourceNodeIndex COMMA_HERE).add (inTargetNodeIndex) ;
  mReverseEdges ((int32_t) inTargetNodeIndex COMMA_HERE).add (inSourceNodeIndex) ;
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkGraph (HERE) ;
  #endif
}

//-----------------------------------------------------------------------------*

void C_DirectedGraph::print (void) const {
  for (int32_t i=0 ; i<mEdges.count () ; i++) {
    if (isNodeDefined ((uint32_t) i)) {
      printf ("Node %d:\n", i) ;
      TC_UniqueArray <uint32_t> s ; mEdges (i COMMA_HERE).getValueArray (s) ;
      for (int32_t j=0 ; j<s.count () ; j++) {
        printf ("  %d --> %d\n", i, s (j COMMA_HERE)) ;
      }
    }
  }
}

//-----------------------------------------------------------------------------*

void C_DirectedGraph::topologicalSort (TC_UniqueArray <uint32_t> & outSortedNodes,
                                       TC_UniqueArray <uint32_t> & outUnsortedNodes) const {
  outSortedNodes.setCountToZero () ;
  outUnsortedNodes.setCountToZero () ;
//--- Get working copies
  TC_UniqueArray <bool> nodes ; getNodeBoolArray (nodes) ;
  TC_UniqueArray <uint32_t> dependencyCount (mReverseEdges.count (), 0 COMMA_HERE) ;
  for (int32_t i=0 ; i<mReverseEdges.count () ; i++) {
    TC_UniqueArray <uint32_t> s ; mReverseEdges (i COMMA_HERE).getValueArray (s) ;
    for (int32_t j=0 ; j<s.count () ; j++) {
      dependencyCount.incrementAtIndex ((int32_t) s (j COMMA_HERE) COMMA_HERE) ;
    }
  }
//--- Loop
  bool loop = true ;
  TC_UniqueArray <uint32_t> s ;
  while (loop) {
    loop = false ;
    for (int32_t i=0 ; i<nodes.count () ; i++) {
      if (nodes (i COMMA_HERE) && (dependencyCount (i COMMA_HERE) == 0)) {
        loop = true ;
        outSortedNodes.addObject ((uint32_t) i) ;
        nodes.setObjectAtIndex (false, i COMMA_HERE) ;
        mReverseEdges (i COMMA_HERE).getValueArray (s) ;
        for (int32_t j=0 ; j<s.count () ; j++) {
          dependencyCount.decrementAtIndex ((int32_t) s (j COMMA_HERE) COMMA_HERE) ;
        }
      }
    }
  }
//--- Add unusorted nodes
  for (int32_t i=0 ; i<nodes.count () ; i++) {
    if (nodes (i COMMA_HERE)) {
      outUnsortedNodes.addObject ((uint32_t) i) ;
    }
  }
}

//-----------------------------------------------------------------------------*

void C_DirectedGraph::depthFirstTopologicalSort (TC_UniqueArray <uint32_t> & outSortedNodes,
                                                 TC_UniqueArray <uint32_t> & outUnsortedNodes) const {
  outSortedNodes.setCountToZero () ;
  outUnsortedNodes.setCountToZero () ;
//--- Get working copies
  TC_UniqueArray <bool> nodes ; getNodeBoolArray (nodes) ;
  TC_UniqueArray <uint32_t> dependencyCount (mReverseEdges.count (), 0 COMMA_HERE) ;
  for (int32_t i=0 ; i<mReverseEdges.count () ; i++) {
    TC_UniqueArray <uint32_t> s ; mReverseEdges (i COMMA_HERE).getValueArray (s) ;
    for (int32_t j=0 ; j<s.count () ; j++) {
      dependencyCount.incrementAtIndex ((int32_t) s (j COMMA_HERE) COMMA_HERE) ;
    }
  }
//--- Loop
  TC_UniqueArray <uint32_t> workingArray ;
  TC_UniqueArray <uint32_t> s ;
  bool loop = true ;
  while (loop) {
  //--- Find a node without any dependence  
    for (int32_t i=0 ; (i<dependencyCount.count ()) && (workingArray.count () == 0) ; i++) {
      if (nodes (i COMMA_HERE) && (dependencyCount (i COMMA_HERE) == 0)) {
        nodes.setObjectAtIndex (false, i COMMA_HERE) ;
        workingArray.addObject ((uint32_t) i) ;
      }
    }
    loop = workingArray.count () > 0 ;
    if (loop) {
      const uint32_t node = workingArray.lastObject (HERE) ;
      workingArray.removeLastObject (HERE) ;
      outSortedNodes.addObject (node) ;
      mReverseEdges ((int32_t) node COMMA_HERE).getValueArray (s) ;
      for (int32_t j=0 ; j<s.count () ; j++) {
        const uint32_t candidate = s (j COMMA_HERE) ;
        dependencyCount.decrementAtIndex ((int32_t) candidate COMMA_HERE) ;
        if (dependencyCount ((int32_t) candidate COMMA_HERE) == 0) {
          workingArray.addObject (candidate) ;
          nodes.setObjectAtIndex (false, (int32_t) candidate COMMA_HERE) ;
        }
      }
    }
  }
//--- Add unusorted nodes
  for (int32_t i=0 ; i<nodes.count () ; i++) {
    if (nodes (i COMMA_HERE)) {
      outUnsortedNodes.addObject ((uint32_t) i) ;
    }
  }
}

//-----------------------------------------------------------------------------*
// http://en.wikipedia.org/wiki/Dominator_(graph_theory)
// a node d dominates a node n if every path from the start node to n must go through d

void C_DirectedGraph::getDominators (TC_UniqueArray <C_UIntSet> & outDominators
                                     COMMA_LOCATION_ARGS) const {
  outDominators.setCountToZero () ;
//--- Enter initial dominators
  TC_UniqueArray <bool> startNodeFlag ;
  for (int32_t i=0 ; i<mEdges.count () ; i++) {
    startNodeFlag.addObject (false) ;
    outDominators.addObject (isNodeDefined ((uint32_t)i) ? mNodeDefinition : C_UIntSet ()) ;
  }
//--- Start nodes are their own dominator
  TC_UniqueArray <uint32_t> startNodeArray ;
  getNodesWithNoPredecessor (startNodeArray) ;
  MF_AssertThere (startNodeArray.count () == 1, "startNodeArray.count () == %lld != 1", startNodeArray.count (), 0) ;
  for (int32_t i=0 ; i<startNodeArray.count () ; i++) {
    const uint32_t startNode = startNodeArray (i COMMA_HERE) ;
    outDominators.setObjectAtIndex (C_UIntSet (startNode), (int32_t) startNode COMMA_HERE) ;
    startNodeFlag.setObjectAtIndex (true, (int32_t) startNode COMMA_HERE) ;
  }
//--- 
  bool loop = true ;
  while (loop) {
    loop = false ;
    for (int32_t node=0 ; node<mEdges.count () ; node++) {
      if (isNodeDefined ((uint32_t) node) && ! startNodeFlag (node COMMA_HERE)) {
        C_UIntSet newDominators = mNodeDefinition ;
      //--- Add dominators of predecessor nodes
        TC_UniqueArray <uint32_t> s ; mReverseEdges (node COMMA_HERE).getValueArray (s) ;
        for (int32_t j=0 ; j<s.count () ; j++) {
          const uint32_t aPredecessor = s (j COMMA_HERE) ;
          newDominators &= outDominators ((int32_t) aPredecessor COMMA_HERE) ;
        }
      //--- A node dominates itself
        newDominators.add ((uint32_t) node) ;
      //--- Replace if not equal
        if (newDominators != outDominators (node COMMA_HERE)) {
          outDominators.setObjectAtIndex (newDominators, node COMMA_HERE) ;
          loop = true ;
        }
      }    
    }
  }
}

//-----------------------------------------------------------------------------*

void C_DirectedGraph::removeEdgesToDominator (LOCATION_ARGS) {
  TC_UniqueArray <C_UIntSet> dominators ; getDominators (dominators COMMA_THERE) ;
  for (int32_t node=0 ; node<mEdges.count () ; node++) {
    if (isNodeDefined ((uint32_t) node)) {
      const C_UIntSet dom = dominators (node COMMA_HERE) ;
      TC_UniqueArray <uint32_t> s ; mEdges (node COMMA_HERE).getValueArray (s) ;
      for (int32_t i=0 ; i<s.count () ; i++) {
        const uint32_t target = s (i COMMA_HERE) ;
        if (dom.contains (target)) {
          mEdges (node COMMA_HERE).remove (target) ;
          mReverseEdges ((int32_t) target COMMA_HERE).remove ((uint32_t) node) ;
          // printf ("  %u --> %u\n", node, s (i COMMA_HERE)) ;
        }
      }
    }
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkGraph (HERE) ;
  #endif
}

//-----------------------------------------------------------------------------*
//                                                                             *
//    E X A M P L E                                                            *
//                                                                             *
//-----------------------------------------------------------------------------*

void C_DirectedGraph::example (void) {
  C_DirectedGraph g ;
/*  g.addEdge (1, 2) ;
  g.addEdge (1, 3) ;
  g.addEdge (2, 3) ;
  g.addEdge (3, 4) ;
  g.addEdge (4, 6) ;
  g.addEdge (6, 4) ;
  g.addEdge (10, 4) ;
  g.addEdge (10, 9) ;
  g.addEdge (6, 9) ;
  g.addEdge (100, 0) ;
  g.addEdge (100, 1) ;
  g.addEdge (100, 10) ; */

  g.addEdge (17, 33) ;
  g.addEdge (17, 35) ;
  g.addEdge (17, 36) ;
  g.addEdge (33, 37) ;
  g.addEdge (37, 39) ;
  g.addEdge (36, 35) ;
  g.addEdge (37, 40) ;
  g.addEdge (40, 35) ;
  g.addEdge (39, 35) ;
  g.addEdge (40, 42) ;
  g.addEdge (42, 35) ;
  g.addEdge (35, 45) ;
  g.addEdge (35, 46) ;
  g.addEdge (45, 47) ;
  g.addEdge (45, 48) ;
  g.addEdge (46, 51) ;
  g.addEdge (46, 52) ;
  g.addEdge (51, 54) ;
  g.addEdge (51, 47) ;
  g.addEdge (52, 57) ;
  g.addEdge (52, 58) ;
  g.addEdge (54, 47) ;
  g.addEdge (57, 47) ;
  g.addEdge (57, 60) ;
  g.addEdge (58, 63) ;
  g.addEdge (58, 64) ;
  g.addEdge (60, 47) ;
  g.addEdge (63, 47) ;
  g.addEdge (63, 66) ;
  g.addEdge (64, 69) ;
  g.addEdge (64, 70) ;
  g.addEdge (66, 47) ;
  g.addEdge (69, 47) ;
  g.addEdge (69, 72) ;
  g.addEdge (70, 47) ;
  g.addEdge (70, 75) ;
  g.addEdge (72, 47) ;
  g.addEdge (75, 47) ;
  g.addEdge (75, 78) ;
  g.addEdge (78, 47) ;
  g.addEdge (78, 47) ;

//--- Print
  printf ("--- Graph\n") ;
  g.print () ;
  printf ("--- Nodes with no predecessor:") ;
  TC_UniqueArray <uint32_t> nodes ;
  g.getNodesWithNoPredecessor (nodes) ;
  for (int32_t i=0 ; i<nodes.count () ; i++) {
    printf (" %u", nodes (i COMMA_HERE)) ;
  }
  printf ("\n") ;
  printf ("--- Nodes with no successor:") ;
  g.getNodesWithNoSuccessor (nodes) ;
  for (int32_t i=0 ; i<nodes.count () ; i++) {
    printf (" %u", nodes (i COMMA_HERE)) ;
  }
  printf ("\n") ;
  printf ("--- Circularities:") ;
  g.getNodesInvolvedInCircularities (nodes) ;
  for (int32_t i=0 ; i<nodes.count () ; i++) {
    printf (" %u", nodes (i COMMA_HERE)) ;
  }
  printf ("\n") ;
  TC_UniqueArray <C_UIntSet> dominators  ;
  g.getDominators (dominators COMMA_HERE) ;
  printf ("--- Dominators:\n") ;
  for (int32_t i=0 ; i<dominators.count () ; i++) {
    if (g.isNodeDefined ((uint32_t) i)) {
      printf ("  Node %u:", i) ;
      dominators (i COMMA_HERE).getValueArray (nodes) ;
      for (int32_t j=0 ; j<nodes.count () ; j++) {
        printf (" %u", nodes (j COMMA_HERE)) ;
      }
      printf ("\n") ;
    }
  }
  printf ("--- Topological sort\n") ;
  TC_UniqueArray <uint32_t> sortedNodes ;
  TC_UniqueArray <uint32_t> unsortedNodes ;
  g.topologicalSort (sortedNodes, unsortedNodes) ;
  printf ("  Sorted nodes:") ;
  for (int32_t i=0 ; i<sortedNodes.count () ; i++) {
    printf (" %u", sortedNodes (i COMMA_HERE)) ;
  }
  printf ("\n") ;
  printf ("  Unsorted nodes:") ;
  for (int32_t i=0 ; i<unsortedNodes.count () ; i++) {
    printf (" %u", unsortedNodes (i COMMA_HERE)) ;
  }
  printf ("\n") ;
  printf ("--- Remove edges to dominators:\n") ;
  g.removeEdgesToDominator (HERE) ;
  g.print () ;
  printf ("--- Reverse topological sort\n") ;
  g.reversedGraph ().topologicalSort (sortedNodes, unsortedNodes) ;
  printf ("  Sorted nodes:") ;
  for (int32_t i=0 ; i<sortedNodes.count () ; i++) {
    printf (" %u", sortedNodes (i COMMA_HERE)) ;
  }
  printf ("\n") ;
  printf ("  Unsorted nodes:") ;
  for (int32_t i=0 ; i<unsortedNodes.count () ; i++) {
    printf (" %u", unsortedNodes (i COMMA_HERE)) ;
  }
  printf ("\n") ;
  printf ("--- Reverse depth first topological sort\n") ;
  g.reversedGraph ().depthFirstTopologicalSort (sortedNodes, unsortedNodes) ;
  printf ("  Sorted nodes:") ;
  for (int32_t i=0 ; i<sortedNodes.count () ; i++) {
    printf (" %u", sortedNodes (i COMMA_HERE)) ;
  }
  printf ("\n") ;
  printf ("  Unsorted nodes:") ;
  for (int32_t i=0 ; i<unsortedNodes.count () ; i++) {
    printf (" %u", unsortedNodes (i COMMA_HERE)) ;
  }
  printf ("\n") ;
  printf ("Remove nodes\n") ;
  bool loop = true ;
  while (loop) {
    TC_UniqueArray <uint32_t> nodes ; g.getNodeValueArray (nodes) ;
    loop = nodes.count () > 0 ;
    if (loop) {
      g.removeNode (nodes (nodes.count () / 2 COMMA_HERE)) ;
    }
  }
}

//-----------------------------------------------------------------------------*
