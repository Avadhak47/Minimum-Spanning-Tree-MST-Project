#ifndef UNIONFIND_H
#define UNIONFIND_H

#include<vector>

class UnionFind {
public:
    UnionFind(int n);
    int find(int x);
    void unite(int x, int y);

private:
    std::vector<int> parent;
    std::vector<int> rank;
};

#endif
