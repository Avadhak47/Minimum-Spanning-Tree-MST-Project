# Minimum Spanning Tree (MST) Project

ELL781 - Software Fundamentals for Computer Technology
Assignment - 3
Prim and Kruskal algorithms for finding a Minimum Spanning Tree (MST) of an undirected, weighted graph.
Submitted By: Avadhesh Kumar
Entry Number: 2024EET2799

## Project Overview

This C++ project implements Prim's and Kruskal's algorithms to find the Minimum Spanning Tree (MST) of an undirected, weighted graph. The program reads a graph's adjacency matrix from a text file, processes it using both algorithms, and outputs the MST along with the total cost and execution time for each algorithm. 

### Key Components
- **Graph Representation**: The graph is represented using an adjacency list.
- **Algorithms**: 
  - **Prim's Algorithm**: A greedy algorithm that builds the MST by adding the cheapest edge from the graph that connects a vertex in the MST to a vertex outside the MST.
  - **Kruskal's Algorithm**: A greedy algorithm that sorts all edges and adds them to the MST if they don't form a cycle, utilizing a union-find structure for cycle detection.
- **Priority Queue**: A binary heap implementation for efficiently retrieving the minimum weight edge in Prim's algorithm.
- **Union-Find**: A data structure that helps track and unify the components of the graph to avoid cycles in Kruskal's algorithm.

## How to Run the Project

### Prerequisites
Ensure you have the following installed on your system:
- A C++ compiler that supports C++17 (e.g., `clang++` for macOS)
- Standard C++ libraries

### Steps to Run the Project

1. **Unzip **
  Download and unzip the project files to a directory of your choice.

2. **Prepare Input File**
   Create a text file named `input.txt` in the root directory of the project, formatted as follows (using -1 for non-edges):
   ```
   0 6 1 5 -1 -1
   6 0 5 -1 3 -1
   1 5 0 5 6 4
   5 -1 5 0 -1 2
   -1 3 6 -1 0 6
   -1 -1 4 2 6 0
   ```

3. **Compile the Code**
   Use the following command to compile the code. This command is tailored for macOS on an M1 Air (ARM64):
   ```bash
   clang++ -std=c++17 main.cpp graph.cpp Prim.cpp Kruskal.cpp PriorityQueue.cpp UnionFind.cpp -isystem /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1 -stdlib=libc++
   ```

4. **Run the Executable**
   After compilation, run the executable:
   ```bash
   ./a.out
   ```

5. **Output**
   The program will generate an `output.txt` file in the same directory, containing the MST results for both Prim's and Kruskal's algorithms, including the total cost and runtime for each.

## Summary
This project serves as an educational tool for understanding graph algorithms and their implementations in C++. It demonstrates key concepts in data structures and algorithms, making it a suitable reference for students and developers interested in graph theory.
