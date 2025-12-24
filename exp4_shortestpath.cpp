#include "ShortestPath.h"
#include <iostream>
#include <queue>
#include <climits>

void Dijkstra(Graph& g, int start) {
    vector<int> dist(g.V, INT_MAX);
    dist[start] = 0;

    priority_queue<pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>> pq;

    pq.push({ 0, start });

    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        for (auto& p : g.adj[u]) {
            int v = p.first, w = p.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
            }
        }
    }

    cout << "从 A 最短路径: ";
    for (int i = 0; i < g.V; i++)
        cout << char('A' + i) << ":" << dist[i] << " ";
    cout << endl;
}
