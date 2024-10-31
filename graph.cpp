/*

                        ELL781 - Software Fundamentals for Computer Technology 
                                             Assignment - 3
 Prim and Kruskal algorithms for finding a Minimum Spanning Tree (MST) of an undirected, weighted graph.

Submitted By: Avadhesh Kumar
Entry Number: 2024EET2799

This cpp code control the operations on the Graph instance that are going to be 
used by Prims and Kruskal Algorithms. It has 
Constructor, 
addEdge, 
hasLoop: check loop in givem instance of graph
printGraph 

*/

#include "graph.h"

// Constructor to initialize a graph 
Graph::Graph(int V) : V(V), adj(V) {}

// Adds an undirected edge between vertices u and v with a given weight
void Graph::addEdge(int u, int v, int weight) {
    adj[u].push_back(std::make_pair(v, weight)); 
    adj[v].push_back(std::make_pair(u, weight));  
}

// Detects if the graph contains any cycles
bool Graph::hasLoop() {
    std::vector<bool> visited(V, false);                 // Track visited nodes
    for (int i = 0; i < V; i++) {                        // Iterate over all vertices
        if (!visited[i]) {                               // If vertex i hasn't been visited
            std::stack<std::pair<int, int>> stack;       // Stack for DFS traversal
            stack.push(std::make_pair(i, -1));           // Push current node with parent as -1
            while (!stack.empty()) {
                int node = stack.top().first;           // Current node
                int parent = stack.top().second;        // Parent of the current node
                stack.pop();
                
                if (visited[node]) return true;         // Cycle detected if node is revisited
                visited[node] = true;                   // Mark node as visited
                
                // Traverse all neighbors of the current node
                for (auto& [neighbor, weight] : adj[node]) {
                    if (!visited[neighbor]) {           // Visit unvisited neighbors
                        stack.push(std::make_pair(neighbor, node));
                    } else if (neighbor != parent) {    // If visited neighbor is not the parent, a cycle exists
                        return true;
                    }
                }
            }
        }
    }
    return false;  // No cycles detected
}

// Prints the adjacency list of each vertex in the graph
void Graph::printGraph() const {
    for (int u = 0; u < V; u++) {                
        std::cout << "Node " << u << ": ";       
        for (const auto& [v, weight] : adj[u]) {
            std::cout << "(" << v << ", " << weight << ") ";  
        }
        std::cout << "\n";                     
    }
}
