#include "Prim.h"
#include "PriorityQueue.h"
#include <vector>
#include <limits>
using namespace std;

// Prim's algorithm 
Graph primMST(const Graph& g) {
    Graph mst(g.V);  
    vector<int> minEdge(g.V, numeric_limits<int>::max());  // Minimum edge weights to each vertex
    vector<bool> inMST(g.V, false);  
    vector<int> parent(g.V, -1);  
    PriorityQueue pq;  // Priority queue for selecting edges with minimum weights

    // Start from vertex 0 with an initial weight of 0
    pq.insert(0, 0);
    minEdge[0] = 0;

    while (!pq.isEmpty()) {
        // Extract the vertex u with the smallest edge weight that is not yet in MST
        auto [minWeight, u] = pq.deleteMin();
        if (inMST[u]) continue;  // Skip if already added to MST due to priority queue updates

        inMST[u] = true;  // Mark u as included in MST

        // For all adjacent vertices v of u, update the MST if v is not in MST and has a smaller edge weight
        for (const auto& [v, weight] : g.adj[u]) {
            // Check if v is not in MST and (u,v) offers a cheaper connection
            if (!inMST[v] && weight < minEdge[v]) {
                minEdge[v] = weight;  // Update minimum edge weight for v
                pq.insert(v, weight);  // Insert or update priority queue with the new weight
                parent[v] = u;  // Set u as the parent of v in the MST
            }
        }
    }

    // Construct the MST using the parent array
    for (int v = 1; v < g.V; ++v) {  // Start from 1 as vertex 0 has no parent
        if (parent[v] != -1) {  // Only add valid edges
            mst.addEdge(parent[v], v, minEdge[v]);
        }
    }

    return mst;
}
