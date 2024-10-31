#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include<vector>
#include<utility>

class PriorityQueue {
public:
    void insert(int vertex, int priority);
    std::pair<int, int> deleteMin();
    void decreaseKey(int vertex, int newPriority);
    bool isEmpty() const;

private:
    std::vector<std::pair<int, int> > heap;
    std::vector<int> position;
    void heapifyUp(int index);
    void heapifyDown(int index);
    void swap(int i, int j);
};

#endif
