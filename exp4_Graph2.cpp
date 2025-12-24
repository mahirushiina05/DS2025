#include "Graph2.h"
#include <iostream>
#include <algorithm>

Graph2::Graph2(int v) : Graph(v) {}

void Graph2::tarjan(int u, int parent) {
    disc[u] = low[u] = ++timer;
    int children = 0;
    bool art = false;

    for (auto& p : adj[u]) {
        int v = p.first;
        if (disc[v] == -1) {
            children++;
            st.push({ u, v });
            tarjan(v, u);
            low[u] = min(low[u], low[v]);

            if (parent != -1 && low[v] >= disc[u]) art = true;
            if (low[v] >= disc[u]) {
                vector<pair<int, int>> comp;
                while (true) {
                    auto e = st.top(); st.pop();
                    comp.push_back(e);
                    if (e.first == u && e.second == v) break;
                }
                bcc.push_back(comp);
            }
        }
        else if (v != parent && disc[v] < disc[u]) {
            st.push({ u, v });
            low[u] = min(low[u], disc[v]);
        }
    }

    if ((parent == -1 && children > 1) || art)
        isAP[u] = true;
}

void Graph2::findBCCandAP(int start) {
    timer = 0;
    disc.assign(V, -1);
    low.assign(V, -1);
    isAP.assign(V, false);
    bcc.clear();
    while (!st.empty()) st.pop();

    tarjan(start, -1);

    cout << "=== 从 " << char('A' + start) << " 出发 ===\n";
    cout << "关节点: ";
    for (int i = 0; i < V; i++)
        if (isAP[i]) cout << char('A' + i) << " ";
    cout << "\n边双连通分量数: " << bcc.size() << "\n";

    for (size_t i = 0; i < bcc.size(); i++) {
        cout << "  BCC " << i + 1 << ": ";
        set<pair<int, int>> edges;
        for (auto& e : bcc[i]) {
            int a = min(e.first, e.second);
            int b = max(e.first, e.second);
            edges.insert({ a,b });
        }
        for (auto& e : edges)
            cout << char('A' + e.first) << "-" << char('A' + e.second) << " ";
        cout << endl;
    }
    cout << endl;
}
