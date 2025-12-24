#pragma once
#ifndef GRAPH2_H
#define GRAPH2_H

#include "Graph.h"
#include <stack>
#include <set>

class Graph2 : public Graph {
public:
    Graph2(int v);

    void findBCCandAP(int start);

private:
    vector<int> disc, low;
    vector<bool> isAP;
    stack<pair<int, int>> st;
    vector<vector<pair<int, int>>> bcc;
    int timer;

    void tarjan(int u, int parent);
};

#endif
