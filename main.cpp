#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <chrono>
#include "graph.h"
#include "Prim.h"
#include "Kruskal.h"

// Load the graph from a specified file
Graph loadGraph(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {                  // check if file is openable or not
        throw std::runtime_error("Unable to open file.");
    }

    std::vector<std::vector<int>> matrix;   // to store input from file
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<int> row;
        int weight;
        while (iss >> weight) {
            row.push_back(weight);
        }
        matrix.push_back(row);
    }
    file.close();

    // Initialize graph from the weight matrix
    Graph g(matrix.size());
    for (int i = 0; i < g.V; ++i) {
        for (int j = 0; j < g.V; ++j) {
            int w = matrix[i][j];
            if (w > 0) {  // Add edge if weight is positive
                g.addEdge(i, j, w);
            }
        }
    }
    return g;
}

// Calculate total cost of the Minimum Spanning Tree (MST)
int totalCost(const Graph& mst) {
    int cost = 0;
    for (int u = 0; u < mst.V; ++u) {
        for (const auto& [v, weight] : mst.adj[u]) {
            if (u < v) {  // Count each edge only once
                cost += weight;
            }
        }
    }
    return cost;
}

// Save the MST results to a specified file
void saveMST(const std::string& filename, const Graph& mst, const std::string& algoName, int cost, double runtimeMs) {
    std::ofstream file(filename, std::ios_base::app);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open output file.");
    }

    // Log algorithm results
    file << algoName << " MST (total cost: " << cost << "; runtime: " << runtimeMs << " ms)\n";
    for (int u = 0; u < mst.V; ++u) {
        for (const auto& [v, weight] : mst.adj[u]) {
            if (u < v) {  // Ensure each edge is printed only once
                file << "(" << u + 1 << "," << v + 1 << ")\n";
            }
        }
    }
    file << "\n";
    file.close();
}

int main() {
    const std::string inputFile = "input.txt";
    const std::string outputFile = "output.txt";

    try {
        // Load the graph from the input file
        Graph g = loadGraph(inputFile);

        // Execute Prim's algorithm and measure its runtime
        auto startPrim = std::chrono::high_resolution_clock::now();
        Graph primMSTResult = primMST(g);  // Renamed variable to avoid conflict
        auto endPrim = std::chrono::high_resolution_clock::now();
        double primDuration = std::chrono::duration<double, std::milli>(endPrim - startPrim).count();

        // Calculate and save results for Prim's algorithm
        saveMST(outputFile, primMSTResult, "Prim’s algorithm", totalCost(primMSTResult), primDuration);

        // Execute Kruskal's algorithm and measure its runtime
        auto startKruskal = std::chrono::high_resolution_clock::now();
        Graph kruskalMSTResult = kruskalMST(g);  // Renamed variable to avoid conflict
        auto endKruskal = std::chrono::high_resolution_clock::now();
        double kruskalDuration = std::chrono::duration<double, std::milli>(endKruskal - startKruskal).count();

        // Calculate and save results for Kruskal's algorithm
        saveMST(outputFile, kruskalMSTResult, "Kruskal’s algorithm", totalCost(kruskalMSTResult), kruskalDuration);

        std::cout << "Results saved to " << outputFile << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
