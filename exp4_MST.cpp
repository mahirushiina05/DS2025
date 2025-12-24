#include "MST.h"
#include <iostream>
#include <queue>
#include <climits>

void Prim(Graph& g) {
    vector<int> key(g.V, INT_MAX);
    vector<bool> inMST(g.V, false);

    priority_queue<pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>> pq;

    key[0] = 0;
    pq.push({ 0, 0 });

    int total = 0;
    cout << "最小生成树边权总和: ";

    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        total += key[u];

        for (auto& p : g.adj[u]) {
            int v = p.first, w = p.second;
            if (!inMST[v] && key[v] > w) {
                key[v] = w;
                pq.push({ key[v], v });
            }
        }
    }
    cout << total << endl;
}
