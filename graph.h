/*

                        ELL781 - Software Fundamentals for Computer Technology 
                                             Assignment - 3
 Prim and Kruskal algorithms for finding a Minimum Spanning Tree (MST) of an undirected, weighted graph.

Submitted By: Avadhesh Kumar
Entry Number: 2024EET2799

*/

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <utility>
#include <iostream>

/*
    Graph class representing an undirected, weighted graph.
    
    Structure:
    - 'V': Number of vertices in the graph.
    - 'adj': Adjacency list where each element is a vector of pairs.
      Each pair represents an edge, storing the connected vertex and the edge weight.

    Main Functions:
    - Constructor: Initializes a graph with 'V' vertices.
    - addEdge: Adds an undirected edge between two vertices with a specified weight.
    - hasLoop: Detects if the graph contains any cycles.
    - printGraph: Outputs the adjacency list of each vertex, displaying neighbors and edge weights.
*/

class Graph {
public:
    int V;  // Number of vertices
    std::vector<std::vector<std::pair<int, int>>> adj;  // Adjacency list: adj[u] contains pairs {v, weight}

    // Constructor: initializes graph with given number of vertices
    Graph(int V);

    // Adds an undirected edge between vertices u and v with a specified weight
    void addEdge(int u, int v, int weight);

    // Checks if the graph contains any cycles
    bool hasLoop();

    // Prints the adjacency list of each vertex in the graph
    void printGraph() const;
};

#endif
