#include "Traversal.h"
#include <iostream>
#include <queue>
using namespace std;

void BFS(Graph& graph, int start) {
    vector<bool> visited(graph.V, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < graph.V; ++i) {
            if (graph.adjMatrix[node][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void DFSUtil(Graph& graph, int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < graph.V; ++i) {
        if (graph.adjMatrix[node][i] && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

void DFS(Graph& graph, int start) {
    vector<bool> visited(graph.V, false);
    DFSUtil(graph, start, visited);
}
