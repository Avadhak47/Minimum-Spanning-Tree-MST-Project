#include "UnionFind.h"

// Constructor to initialize the Union-Find structure
// Initializes 'parent' to point to itself for each node
// 'rank' is used to keep track of the tree depth
UnionFind::UnionFind(int n) : parent(n), rank(n, 0) {
    for (int i = 0; i < n; i++) 
        parent[i] = i;  // Each element is its own parent (root)
}

// Find the root of the element 'x' with path compression
// This means that all nodes directly point to the root for faster future queries
int UnionFind::find(int x) {
    if (parent[x] != x) {
        // Recursively find the root and compress the path
        parent[x] = find(parent[x]);
    }
    return parent[x];  
}

// Unite the sets that contain 'x' and 'y'
// This uses union by rank to attach the shorter tree under the root of the taller tree
void UnionFind::unite(int x, int y) {
    int rootX = find(x);  
    int rootY = find(y);  
    
    if (rootX != rootY) {  // Only unite if they are in different sets
        // Union by rank to maintain a balanced tree structure
        if (rank[rootX] > rank[rootY]) 
            parent[rootY] = rootX;  
        else if (rank[rootX] < rank[rootY]) 
            parent[rootX] = rootY; 
        else {
            parent[rootY] = rootX;  
            rank[rootX]++;  
        }
    }
}
