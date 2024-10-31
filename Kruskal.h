/*
    Kruskal's Algorithm for Finding Minimum Spanning Tree (MST)
    
    Dependencies:
    - Graph class: Represents the undirected, weighted graph.
    - UnionFind class: Supports efficient cycle detection while adding edges to the MST.

    Function:
    - kruskalMST: Computes and returns the Minimum Spanning Tree of the given graph using Kruskal's algorithm.
*/

#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "graph.h"
#include "UnionFind.h"


// Function prototype for Kruskal's algorithm
Graph kruskalMST(const Graph& graph);

#endif
