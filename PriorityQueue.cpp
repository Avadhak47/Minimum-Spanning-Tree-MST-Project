#include "PriorityQueue.h"
#include <algorithm>
#include <limits>
#include <vector>

// Insert a vertex with a specified priority into the heap
void PriorityQueue::insert(int vertex, int priority) {
    if (vertex >= position.size()) {
        position.resize(vertex + 1, -1);  // Resize position array if vertex is out of bounds
    }

    // Insert new element at the end of the heap and set its position
    heap.push_back(std::make_pair(priority, vertex));
    position[vertex] = heap.size() - 1;  // Track index of the vertex in position array
    heapifyUp(heap.size() - 1);          // Maintain min-heap property by moving up
}

// Remove and return the element with the minimum priority (root of the heap)
std::pair<int, int> PriorityQueue::deleteMin() {
    if (heap.empty()) {
        throw std::out_of_range("Heap is empty");
    }

    // Store the minimum element (root), swap it with the last element
    std::pair<int, int> minElement = heap[0];
    swap(0, heap.size() - 1);
    heap.pop_back();       // Remove the last element (which was the root)
    position[minElement.second] = -1;  // Mark as removed in position array

    if (!heap.empty()) {
        heapifyDown(0);  // Restore min-heap property by moving down from root
    }

    return minElement;
}

// Decrease the priority of a given vertex and adjust its position in the heap
void PriorityQueue::decreaseKey(int vertex, int newPriority) {
    int index = position[vertex];
    if (index == -1 || heap[index].first <= newPriority) {
        return;  // Do nothing if vertex not in heap or new priority is not lower
    }
    heap[index].first = newPriority;
    heapifyUp(index);  // Maintain min-heap property by moving up
}

// Check if the heap is empty
bool PriorityQueue::isEmpty() const {
    return heap.empty();
}

// Move the element at index up to restore the min-heap property
void PriorityQueue::heapifyUp(int index) {
    while (index > 0 && heap[index].first < heap[(index - 1) / 2].first) {
        swap(index, (index - 1) / 2);  // Swap with parent if out of order
        index = (index - 1) / 2;       // Move up to parent index
    }
}

// Move the element at index down to restore the min-heap property
void PriorityQueue::heapifyDown(int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    // Find the smallest among index and its children
    if (leftChild < heap.size() && heap[leftChild].first < heap[smallest].first) {
        smallest = leftChild;
    }
    if (rightChild < heap.size() && heap[rightChild].first < heap[smallest].first) {
        smallest = rightChild;
    }

    // If the smallest is not the current index, swap and continue heapifying down
    if (smallest != index) {
        swap(index, smallest);
        heapifyDown(smallest);
    }
}

// Swap two elements in the heap and update their positions in the position array
void PriorityQueue::swap(int i, int j) {
    std::swap(heap[i], heap[j]);  // Swap elements in heap
    position[heap[i].second] = i; // Update position for vertex at index i
    position[heap[j].second] = j; // Update position for vertex at index j
}
