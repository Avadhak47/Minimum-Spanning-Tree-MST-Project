/*
                        ELL781 - Software Fundamentals for Computer Technology 
                                             Assignment - 3
 Prim and Kruskal algorithms for finding a Minimum Spanning Tree (MST) of an undirected, weighted graph.

Submitted By: Avadhesh Kumar
Entry Number: 2024EET2799

Kruskal's Algorithm for Finding Minimum Spanning Tree (MST)
control and defines the Kruskal Algorithms by using graph and unionfind.
The algorithm works by sorting all the edges of the graph in non-decreasing 
order of their weights and adding them one by one to the MST, provided that 
they do not form a cycle.
*/

#include "Kruskal.h"
#include <algorithm>
#include <vector>

using namespace std;

Graph kruskalMST(const Graph& graph) {
    // Initialize a new graph to store the resulting Minimum Spanning Tree (MST)
    Graph mst(graph.V);

    // Define a vector of pairs to store all edges in the format (weight, (u, v))
    vector<pair<int, pair<int, int> > > edges;

    // Collect all edges in the graph, represented by (weight, (u, v))
    for (int u = 0; u < graph.V; ++u) {
        // Iterate through all adjacent vertices (v) and their corresponding weights
        for (const auto& neighbor : graph.adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // To avoid duplicate edges, only consider edges (u, v) where u < v
            if (u < v) {
                edges.push_back(std::make_pair(weight, std::make_pair(u, v)));
            }
        }
    }

    // Sort all edges in ascending order by weight
    sort(edges.begin(), edges.end());

    // Initialize the Union-Find data structure to manage connected components
    UnionFind uf(graph.V);

    // Iterate over each edge in sorted order
    for (const auto& edge : edges) {
        int weight = edge.first;        
        int u = edge.second.first;      
        int v = edge.second.second;     

        // If vertices u and v are in different components, add this edge to the MST
        if (uf.find(u) != uf.find(v)) {
            mst.addEdge(u, v, weight);  
            uf.unite(u, v);             
        }
    }

    return mst;
}
