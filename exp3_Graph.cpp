#include "Graph.h"
#include <iostream>
using namespace std;

Graph::Graph(int vertices)
    : V(vertices), adjMatrix(vertices, vector<int>(vertices, 0)) {
}

void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight; // 无向图
}

void Graph::printAdjMatrix() {
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
