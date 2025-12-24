#include "Graph.h"
#include <iostream>
#include <queue>
#include <stack>

Graph::Graph(int vertices) : V(vertices), adj(vertices) {}

void Graph::addEdge(int u, int v, int weight) {
    adj[u].push_back({ v, weight });
    adj[v].push_back({ u, weight });
}

void Graph::printAdjacencyMatrix() {
    vector<vector<int>> matrix(V, vector<int>(V, 0));
    for (int u = 0; u < V; ++u) {
        for (auto& p : adj[u]) {
            matrix[u][p.first] = p.second ? p.second : 1;
        }
    }
    cout << "邻接矩阵:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

void Graph::BFS(int start) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "BFS: ";
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << char('A' + u) << " ";
        for (auto& p : adj[u]) {
            if (!visited[p.first]) {
                visited[p.first] = true;
                q.push(p.first);
            }
        }
    }
    cout << endl;
}

void Graph::DFS(int start) {
    vector<bool> visited(V, false);
    stack<int> st;
    st.push(start);

    cout << "DFS: ";
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (visited[u]) continue;
        visited[u] = true;
        cout << char('A' + u) << " ";
        for (auto& p : adj[u]) {
            if (!visited[p.first])
                st.push(p.first);
        }
    }
    cout << endl;
}
