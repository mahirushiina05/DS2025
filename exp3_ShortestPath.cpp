#include "ShortestPath.h"
#include <iostream>
#include <limits>
using namespace std;

void dijkstra(Graph& graph, int src) {
    vector<int> dist(graph.V, numeric_limits<int>::max());
    vector<bool> visited(graph.V, false);

    dist[src] = 0;

    for (int count = 0; count < graph.V - 1; ++count) {
        int u = -1;

        for (int i = 0; i < graph.V; ++i) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        visited[u] = true;

        for (int v = 0; v < graph.V; ++v) {
            if (!visited[v] && graph.adjMatrix[u][v] &&
                dist[u] != numeric_limits<int>::max()) {

                int newDist = dist[u] + graph.adjMatrix[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                }
            }
        }
    }

    for (int i = 0; i < graph.V; ++i) {
        cout << "Distance from " << src << " to " << i
            << " is " << dist[i] << endl;
    }
}
