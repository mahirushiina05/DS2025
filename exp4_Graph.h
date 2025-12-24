#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <utility>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<pair<int, int>>> adj;

    Graph(int vertices);

    void addEdge(int u, int v, int weight = 0);
    void printAdjacencyMatrix();
    void BFS(int start);
    void DFS(int start);
};

#endif
