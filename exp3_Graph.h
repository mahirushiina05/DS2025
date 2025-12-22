#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using namespace std;

class Graph {
public:
    int V;                             
    vector<vector<int>> adjMatrix;     

    Graph(int vertices);

    void addEdge(int u, int v, int weight);
    void printAdjMatrix();
};
#endif
