//-----------------------------------------------------------------------------*
//                                                                             *
//  C_DirectedGraph : algorithms on ordered graphs                           *
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

void C_DirectedGraph::addNode (const PMUInt32 inNodeIndex) {
  mNodeDefinition.add (inNodeIndex) ;
  while (((PMSInt32) inNodeIndex) >= mEdges.count ()) {
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
  const PMUInt32 lastPlusOne = mNodeDefinition.firstValueNotIsSet () ;
  while (lastPlusOne > (PMUInt32) mEdges.count ()) {
    mEdges.addObject (C_UIntSet ()) ;
    mReverseEdges.addObject (C_UIntSet ()) ;
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkGraph (HERE) ;
  #endif
}

//-----------------------------------------------------------------------------*

void C_DirectedGraph::removeNode (const PMUInt32 inNodeIndex) {
  if (inNodeIndex < (PMUInt32) mEdges.count ()) {
    mNodeDefinition.remove (inNodeIndex) ;
    const C_UIntSet targetSet = mEdges ((PMSInt32) inNodeIndex COMMA_HERE) ;
    TC_Array <PMUInt32> targetList ; targetSet.getValueArray (targetList) ;
    for (PMSInt32 i=0 ; i<targetList.count () ; i++) {
      const PMUInt32 targetIndex = targetList (i COMMA_HERE) ;
      mReverseEdges ((PMSInt32) targetIndex COMMA_HERE).remove (inNodeIndex) ;
    }
    mEdges ((PMSInt32) inNodeIndex COMMA_HERE) = C_UIntSet () ;
  }
  const PMUInt32 f = mNodeDefinition.firstValueNotIsSet () ;
  while (f < (PMUInt32) mEdges.count ()) {
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

void C_DirectedGraph::getNodeValueArray (TC_UniqueArray <PMUInt32> & outNodes) const {
  mNodeDefinition.getValueArray (outNodes) ;
}

//-----------------------------------------------------------------------------*

bool C_DirectedGraph::isNodeDefined (const PMUInt32 inNodeIndex) const {
  return mNodeDefinition.contains (inNodeIndex) ;
}

//-----------------------------------------------------------------------------*

PMUInt32 C_DirectedGraph::nodeCount (void) const {
  return mNodeDefinition.count () ;
}

//-----------------------------------------------------------------------------*

PMUInt32 C_DirectedGraph::edgeCount (void) const {
  PMUInt32 result = 0 ;
  for (PMSInt32 i=0 ; i<mEdges.count () ; i++) {
    if (isNodeDefined ((PMUInt32) i)) {
      result += mEdges (i COMMA_HERE).count () ;
    }
  }
  return result ;
}

//-----------------------------------------------------------------------------*

PMUInt32 C_DirectedGraph::unusedNodeIndex (void) const {
  PMUInt32 result = nodeCount () ;
  while (isNodeDefined (result)) {
    result ++ ;
  }
  return result ;
}

//-----------------------------------------------------------------------------*

C_String C_DirectedGraph::graphvizString (const TC_UniqueArray <C_String> & inNodeNameArray) const {
  C_String s = "digraph G {\n" ;
  for (PMSInt32 i=0 ; i<mEdges.count () ; i++) {
    if (isNodeDefined ((PMUInt32) i)) {
      s << "  \"" << inNodeNameArray (i COMMA_HERE) << "\" ;\n" ;
      const C_UIntSet targetSet = mEdges (i COMMA_HERE) ;
      TC_Array <PMUInt32> targetList ; targetSet.getValueArray (targetList) ;
      for (PMSInt32 j=0 ; j<targetList.count () ; j++) {
        const PMUInt32 targetIndex = targetList (j COMMA_HERE) ;
        s << "  \"" << inNodeNameArray (i COMMA_HERE) << "\" -> \"" << inNodeNameArray ((PMSInt32) targetIndex COMMA_HERE) << "\" ;\n" ;
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
    MF_AssertThere (mNodeDefinition.firstValueNotIsSet () == (PMUInt32) (mEdges.count ()), "mNodeDefinition.firstValueNotIsSet () %lld != mEdges.count () %lld", mNodeDefinition.firstValueNotIsSet (), mEdges.count ()) ;
  //---
    for (PMUInt32 i=0 ; i<(PMUInt32) mEdges.count () ; i++) {
      TC_UniqueArray <PMUInt32> targetList ; mEdges ((PMSInt32) i COMMA_HERE).getValueArray (targetList) ;
      for (PMSInt32 j=0 ; j<targetList.count () ; j++) {
        const PMUInt32 target = targetList (j COMMA_HERE) ;
        MF_AssertThere (mReverseEdges ((PMSInt32) target COMMA_HERE).contains (i), "! mReverseEdges (%lld COMMA_HERE).contains (%lld)", target, i) ;
      }
    }
  //---
    for (PMUInt32 i=0 ; i<(PMUInt32) mReverseEdges.count () ; i++) {
      TC_UniqueArray <PMUInt32> sourceList ; mReverseEdges ((PMSInt32) i COMMA_HERE).getValueArray (sourceList) ;
      for (PMSInt32 j=0 ; j<sourceList.count () ; j++) {
        const PMUInt32 source = sourceList (j COMMA_HERE) ;
        MF_AssertThere (mEdges ((PMSInt32) source COMMA_HERE).contains (i), "! mEdges (%lld COMMA_HERE).contains (%lld)", source, i) ;
      }
    }
  }
#endif

//-----------------------------------------------------------------------------*

void C_DirectedGraph::getEdges (TC_UniqueArray <cEdge> & outEdges) const {
  outEdges.setCountToZero () ;
  for (PMSInt32 i=0 ; i<mEdges.count () ; i++) {
    TC_UniqueArray <PMUInt32> targetList ; mEdges (i COMMA_HERE).getValueArray (targetList) ;
    for (PMSInt32 j=0 ; j<targetList.count () ; j++) {
      const cEdge edge = {(PMUInt32) i, targetList (j COMMA_HERE)} ;
      outEdges.addObject (edge) ;
    }
  }
}

//-----------------------------------------------------------------------------*

void C_DirectedGraph::getNodesWithNoPredecessor (TC_UniqueArray <PMUInt32> & outNodes) const {
  outNodes.setCountToZero () ;
  for (PMUInt32 i=0 ; i<(PMUInt32) mReverseEdges.count () ; i++) {
    if (isNodeDefined (i) && mReverseEdges ((PMSInt32) i COMMA_HERE).isEmpty ()) {
      outNodes.addObject (i) ;
    }
  }
}

//-----------------------------------------------------------------------------*

void C_DirectedGraph::getNodesWithNoSuccessor (TC_UniqueArray <PMUInt32> & outNodes) const {
  outNodes.setCountToZero () ;
  for (PMUInt32 i=0 ; i<(PMUInt32) mEdges.count () ; i++) {
    if (isNodeDefined (i) && mEdges ((PMSInt32) i COMMA_HERE).isEmpty ()) {
      outNodes.addObject (i) ;
    }
  }
}

//-----------------------------------------------------------------------------*

void C_DirectedGraph::getNodesInvolvedInCircularities (TC_UniqueArray <PMUInt32> & outNodes) const {
  outNodes.setCountToZero () ;
//--- Get working copies
  TC_UniqueArray <bool> nodes ; getNodeBoolArray (nodes) ;
  TC_UniqueArray <PMUInt32> successorCount ;
  TC_UniqueArray <PMUInt32> predecessorCount ;
  for (PMSInt32 i=0 ; i<mEdges.count () ; i++) {
    successorCount.addObject (mEdges (i COMMA_HERE).count ()) ;
  }
  for (PMSInt32 i=0 ; i<mReverseEdges.count () ; i++) {
    predecessorCount.addObject (mReverseEdges (i COMMA_HERE).count ()) ;
  }
//--- Eliminate nodes that have no successor or no predecessor
  bool loop = true ;
  while (loop) {
    loop = false ;
    for (PMSInt32 i=0 ; i<nodes.count () ; i++) {
      if (nodes (i COMMA_HERE) && ((successorCount (i COMMA_HERE) == 0) || (predecessorCount (i COMMA_HERE) == 0))) {
        loop = true ;
        nodes (i COMMA_HERE) = false ;
        TC_UniqueArray <PMUInt32> s ; mEdges (i COMMA_HERE).getValueArray (s) ;
        for (PMSInt32 j=0 ; j<s.count () ; j++) {
          predecessorCount ((PMSInt32) s (j COMMA_HERE) COMMA_HERE) -- ;
        }
        mReverseEdges (i COMMA_HERE).getValueArray (s) ;
        for (PMSInt32 j=0 ; j<s.count () ; j++) {
          successorCount ((PMSInt32) s (j COMMA_HERE) COMMA_HERE) -- ;
        }
      }
    }
  }

//--- Add circular nodes
  for (PMSInt32 i=0 ; i<nodes.count () ; i++) {
    if (nodes (i COMMA_HERE)) {
      outNodes.addObject ((PMUInt32) i) ;
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
    TC_UniqueArray <PMUInt32> sourceNodeArray ; nodeSet.getValueArray (sourceNodeArray) ;
    for (PMSInt32 i=0 ; i<sourceNodeArray.count () ; i++) {
      const PMUInt32 sourceNodeIndex = sourceNodeArray (i COMMA_HERE) ;
      if (nodeBoolArray ((PMSInt32) sourceNodeIndex COMMA_HERE)) {
        loop = true ;
        nodeBoolArray ((PMSInt32) sourceNodeIndex COMMA_HERE) = false ;
        C_UIntSet s = mEdges ((PMSInt32) sourceNodeIndex COMMA_HERE) ;
        s -= inNodesToExclude ;
        nodeSet |= s ;
        TC_UniqueArray <PMUInt32> targetNodeArray ; s.getValueArray (targetNodeArray) ;
        for (PMSInt32 j=0 ; j<targetNodeArray.count () ; j++) {
          result.addEdge (sourceNodeIndex, targetNodeArray (j COMMA_HERE)) ;
        }
      }
    }
  }
  return result ;
}

//-----------------------------------------------------------------------------*

void C_DirectedGraph::removeEdgesToNode (const PMUInt32 inNodeIndex
                                         COMMA_LOCATION_ARGS) {
//--- get nodes that have edges to this node
  const C_UIntSet nodeSet = mReverseEdges ((PMSInt32) inNodeIndex COMMA_THERE) ;
//--- Remove edges in reverse egde array
  mReverseEdges ((PMSInt32) inNodeIndex COMMA_THERE) = C_UIntSet () ;
//--- Remove edge in direct edge array
  TC_UniqueArray <PMUInt32> sourceNodeArray ; nodeSet.getValueArray (sourceNodeArray) ;
  for (PMSInt32 i=0 ; i<sourceNodeArray.count () ; i++) {
    const PMUInt32 sourceNodeIndex = sourceNodeArray (i COMMA_HERE) ;
    mEdges ((PMSInt32) sourceNodeIndex COMMA_HERE).remove (inNodeIndex) ;
  }
//--- Check
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkGraph (HERE) ;
  #endif
}

//-----------------------------------------------------------------------------*

void C_DirectedGraph::addEdge (const PMUInt32 inSourceNodeIndex,
                              const PMUInt32 inTargetNodeIndex) {
  addNode (inSourceNodeIndex) ;
  addNode (inTargetNodeIndex) ;
  mEdges ((PMSInt32) inSourceNodeIndex COMMA_HERE).add (inTargetNodeIndex) ;
  mReverseEdges ((PMSInt32) inTargetNodeIndex COMMA_HERE).add (inSourceNodeIndex) ;
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkGraph (HERE) ;
  #endif
}

//-----------------------------------------------------------------------------*

void C_DirectedGraph::print (void) const {
  for (PMSInt32 i=0 ; i<mEdges.count () ; i++) {
    if (isNodeDefined ((PMUInt32) i)) {
      printf ("Node %d:\n", i) ;
      TC_UniqueArray <PMUInt32> s ; mEdges (i COMMA_HERE).getValueArray (s) ;
      for (PMSInt32 j=0 ; j<s.count () ; j++) {
        printf ("  %d --> %d\n", i, s (j COMMA_HERE)) ;
      }
    }
  }
}

//-----------------------------------------------------------------------------*

void C_DirectedGraph::topologicalSort (TC_UniqueArray <PMUInt32> & outSortedNodes,
                                       TC_UniqueArray <PMUInt32> & outUnsortedNodes) const {
  outSortedNodes.setCountToZero () ;
  outUnsortedNodes.setCountToZero () ;
//--- Get working copies
  TC_UniqueArray <bool> nodes ; getNodeBoolArray (nodes) ;
  TC_UniqueArray <PMUInt32> dependencyCount (mReverseEdges.count (), 0 COMMA_HERE) ;
  for (PMSInt32 i=0 ; i<mReverseEdges.count () ; i++) {
    TC_UniqueArray <PMUInt32> s ; mReverseEdges (i COMMA_HERE).getValueArray (s) ;
    for (PMSInt32 j=0 ; j<s.count () ; j++) {
      dependencyCount ((PMSInt32) s (j COMMA_HERE) COMMA_HERE) ++ ;
    }
  }
//--- Loop
  bool loop = true ;
  TC_UniqueArray <PMUInt32> s ;
  while (loop) {
    loop = false ;
    for (PMSInt32 i=0 ; i<nodes.count () ; i++) {
      if (nodes (i COMMA_HERE) && (dependencyCount (i COMMA_HERE) == 0)) {
        loop = true ;
        outSortedNodes.addObject ((PMUInt32) i) ;
        nodes (i COMMA_HERE) = false ;
        mReverseEdges (i COMMA_HERE).getValueArray (s) ;
        for (PMSInt32 j=0 ; j<s.count () ; j++) {
          dependencyCount ((PMSInt32) s (j COMMA_HERE) COMMA_HERE) -- ;
        }
      }
    }
  }
//--- Add unusorted nodes
  for (PMSInt32 i=0 ; i<nodes.count () ; i++) {
    if (nodes (i COMMA_HERE)) {
      outUnsortedNodes.addObject ((PMUInt32) i) ;
    }
  }
}

//-----------------------------------------------------------------------------*

void C_DirectedGraph::depthFirstTopologicalSort (TC_UniqueArray <PMUInt32> & outSortedNodes,
                                                 TC_UniqueArray <PMUInt32> & outUnsortedNodes) const {
  outSortedNodes.setCountToZero () ;
  outUnsortedNodes.setCountToZero () ;
//--- Get working copies
  TC_UniqueArray <bool> nodes ; getNodeBoolArray (nodes) ;
  TC_UniqueArray <PMUInt32> dependencyCount (mReverseEdges.count (), 0 COMMA_HERE) ;
  for (PMSInt32 i=0 ; i<mReverseEdges.count () ; i++) {
    TC_UniqueArray <PMUInt32> s ; mReverseEdges (i COMMA_HERE).getValueArray (s) ;
    for (PMSInt32 j=0 ; j<s.count () ; j++) {
      dependencyCount ((PMSInt32) s (j COMMA_HERE) COMMA_HERE) ++ ;
    }
  }
//--- Loop
  TC_UniqueArray <PMUInt32> workingArray ;
  TC_UniqueArray <PMUInt32> s ;
  bool loop = true ;
  while (loop) {
  //--- Find a node without any dependence  
    for (PMSInt32 i=0 ; (i<dependencyCount.count ()) && (workingArray.count () == 0) ; i++) {
      if (nodes (i COMMA_HERE) && (dependencyCount (i COMMA_HERE) == 0)) {
        nodes (i COMMA_HERE) = false ;
        workingArray.addObject ((PMUInt32) i) ;
      }
    }
    loop = workingArray.count () > 0 ;
    if (loop) {
      const PMUInt32 node = workingArray.lastObject (HERE) ;
      workingArray.removeLastObject (HERE) ;
      outSortedNodes.addObject (node) ;
      mReverseEdges ((PMSInt32) node COMMA_HERE).getValueArray (s) ;
      for (PMSInt32 j=0 ; j<s.count () ; j++) {
        const PMUInt32 candidate = s (j COMMA_HERE) ;
        dependencyCount ((PMSInt32) candidate COMMA_HERE) -- ;
        if (dependencyCount ((PMSInt32) candidate COMMA_HERE) == 0) {
          workingArray.addObject (candidate) ;
          nodes ((PMSInt32) candidate COMMA_HERE) = false ;
        }
      }
    }
  }
//--- Add unusorted nodes
  for (PMSInt32 i=0 ; i<nodes.count () ; i++) {
    if (nodes (i COMMA_HERE)) {
      outUnsortedNodes.addObject ((PMUInt32) i) ;
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
  for (PMSInt32 i=0 ; i<mEdges.count () ; i++) {
    startNodeFlag.addObject (false) ;
    outDominators.addObject (isNodeDefined ((PMUInt32)i) ? mNodeDefinition : C_UIntSet ()) ;
  }
//--- Start nodes are their own dominator
  TC_UniqueArray <PMUInt32> startNodeArray ;
  getNodesWithNoPredecessor (startNodeArray) ;
  MF_AssertThere (startNodeArray.count () == 1, "startNodeArray.count () == %lld != 1", startNodeArray.count (), 0) ;
  for (PMSInt32 i=0 ; i<startNodeArray.count () ; i++) {
    const PMUInt32 startNode = startNodeArray (i COMMA_HERE) ;
    outDominators ((PMSInt32) startNode COMMA_HERE) = C_UIntSet (startNode) ;
    startNodeFlag ((PMSInt32) startNode COMMA_HERE) = true ;
  }
//--- 
  bool loop = true ;
  while (loop) {
    loop = false ;
    for (PMSInt32 node=0 ; node<mEdges.count () ; node++) {
      if (isNodeDefined ((PMUInt32) node) && ! startNodeFlag (node COMMA_HERE)) {
        C_UIntSet newDominators = mNodeDefinition ;
      //--- Add dominators of predecessor nodes
        TC_UniqueArray <PMUInt32> s ; mReverseEdges (node COMMA_HERE).getValueArray (s) ;
        for (PMSInt32 j=0 ; j<s.count () ; j++) {
          const PMUInt32 aPredecessor = s (j COMMA_HERE) ;
          newDominators &= outDominators ((PMSInt32) aPredecessor COMMA_HERE) ;
        }
      //--- A node dominates itself
        newDominators.add ((PMUInt32) node) ;
      //--- Replace if not equal
        if (newDominators != outDominators (node COMMA_HERE)) {
          outDominators (node COMMA_HERE) = newDominators ;
          loop = true ;
        }
      }    
    }
  }
}

//-----------------------------------------------------------------------------*

void C_DirectedGraph::removeEdgesToDominator (LOCATION_ARGS) {
  TC_UniqueArray <C_UIntSet> dominators ; getDominators (dominators COMMA_THERE) ;
  for (PMSInt32 node=0 ; node<mEdges.count () ; node++) {
    if (isNodeDefined ((PMUInt32) node)) {
      const C_UIntSet dom = dominators (node COMMA_HERE) ;
      TC_UniqueArray <PMUInt32> s ; mEdges (node COMMA_HERE).getValueArray (s) ;
      for (PMSInt32 i=0 ; i<s.count () ; i++) {
        const PMUInt32 target = s (i COMMA_HERE) ;
        if (dom.contains (target)) {
          mEdges (node COMMA_HERE).remove (target) ;
          mReverseEdges ((PMSInt32) target COMMA_HERE).remove ((PMUInt32) node) ;
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
//    E X A M P L E                                                          *
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
  TC_UniqueArray <PMUInt32> nodes ;
  g.getNodesWithNoPredecessor (nodes) ;
  for (PMSInt32 i=0 ; i<nodes.count () ; i++) {
    printf (" %u", nodes (i COMMA_HERE)) ;
  }
  printf ("\n") ;
  printf ("--- Nodes with no successor:") ;
  g.getNodesWithNoSuccessor (nodes) ;
  for (PMSInt32 i=0 ; i<nodes.count () ; i++) {
    printf (" %u", nodes (i COMMA_HERE)) ;
  }
  printf ("\n") ;
  printf ("--- Circularities:") ;
  g.getNodesInvolvedInCircularities (nodes) ;
  for (PMSInt32 i=0 ; i<nodes.count () ; i++) {
    printf (" %u", nodes (i COMMA_HERE)) ;
  }
  printf ("\n") ;
  TC_UniqueArray <C_UIntSet> dominators  ;
  g.getDominators (dominators COMMA_HERE) ;
  printf ("--- Dominators:\n") ;
  for (PMSInt32 i=0 ; i<dominators.count () ; i++) {
    if (g.isNodeDefined ((PMUInt32) i)) {
      printf ("  Node %u:", i) ;
      dominators (i COMMA_HERE).getValueArray (nodes) ;
      for (PMSInt32 j=0 ; j<nodes.count () ; j++) {
        printf (" %u", nodes (j COMMA_HERE)) ;
      }
      printf ("\n") ;
    }
  }
  printf ("--- Topological sort\n") ;
  TC_UniqueArray <PMUInt32> sortedNodes ;
  TC_UniqueArray <PMUInt32> unsortedNodes ;
  g.topologicalSort (sortedNodes, unsortedNodes) ;
  printf ("  Sorted nodes:") ;
  for (PMSInt32 i=0 ; i<sortedNodes.count () ; i++) {
    printf (" %u", sortedNodes (i COMMA_HERE)) ;
  }
  printf ("\n") ;
  printf ("  Unsorted nodes:") ;
  for (PMSInt32 i=0 ; i<unsortedNodes.count () ; i++) {
    printf (" %u", unsortedNodes (i COMMA_HERE)) ;
  }
  printf ("\n") ;
  printf ("--- Remove edges to dominators:\n") ;
  g.removeEdgesToDominator (HERE) ;
  g.print () ;
  printf ("--- Reverse topological sort\n") ;
  g.reversedGraph ().topologicalSort (sortedNodes, unsortedNodes) ;
  printf ("  Sorted nodes:") ;
  for (PMSInt32 i=0 ; i<sortedNodes.count () ; i++) {
    printf (" %u", sortedNodes (i COMMA_HERE)) ;
  }
  printf ("\n") ;
  printf ("  Unsorted nodes:") ;
  for (PMSInt32 i=0 ; i<unsortedNodes.count () ; i++) {
    printf (" %u", unsortedNodes (i COMMA_HERE)) ;
  }
  printf ("\n") ;
  printf ("--- Reverse depth first topological sort\n") ;
  g.reversedGraph ().depthFirstTopologicalSort (sortedNodes, unsortedNodes) ;
  printf ("  Sorted nodes:") ;
  for (PMSInt32 i=0 ; i<sortedNodes.count () ; i++) {
    printf (" %u", sortedNodes (i COMMA_HERE)) ;
  }
  printf ("\n") ;
  printf ("  Unsorted nodes:") ;
  for (PMSInt32 i=0 ; i<unsortedNodes.count () ; i++) {
    printf (" %u", unsortedNodes (i COMMA_HERE)) ;
  }
  printf ("\n") ;
  printf ("Remove nodes\n") ;
  bool loop = true ;
  while (loop) {
    TC_UniqueArray <PMUInt32> nodes ; g.getNodeValueArray (nodes) ;
    loop = nodes.count () > 0 ;
    if (loop) {
      g.removeNode (nodes (nodes.count () / 2 COMMA_HERE)) ;
    }
  }
}

//-----------------------------------------------------------------------------*
