#include <iostream>
#include "Graph.h"
#include "Graph2.h"
#include "ShortestPath.h"
#include "MST.h"

int main() {
    Graph g1(8);

    g1.addEdge(0, 1, 4); g1.addEdge(0, 2, 12); g1.addEdge(0, 3, 6);
    g1.addEdge(0, 6, 7); g1.addEdge(1, 4, 9);  g1.addEdge(1, 5, 1);
    g1.addEdge(2, 4, 2); g1.addEdge(2, 5, 5);  g1.addEdge(3, 4, 13);
    g1.addEdge(3, 6, 2); g1.addEdge(4, 6, 11); g1.addEdge(4, 7, 8);
    g1.addEdge(5, 7, 10); g1.addEdge(6, 7, 18); g1.addEdge(5, 6, 3);

    cout << "=== 图1 ===\n";
    g1.printAdjacencyMatrix();
    g1.BFS(0);
    g1.DFS(0);
    Dijkstra(g1, 0);
    Prim(g1);

    Graph2 g2(12);
    g2.addEdge(0, 1); g2.addEdge(0, 4);
    g2.addEdge(1, 2); g2.addEdge(1, 5);
    g2.addEdge(2, 3); g2.addEdge(2, 6);
    g2.addEdge(3, 7); g2.addEdge(4, 5);
    g2.addEdge(4, 9); g2.addEdge(5, 6);
    g2.addEdge(5, 10); g2.addEdge(6, 7);
    g2.addEdge(6, 10); g2.addEdge(7, 10);
    g2.addEdge(8, 9); g2.addEdge(8, 10);
    g2.addEdge(9, 10); g2.addEdge(10, 11);

    cout << "\n=== 图2 ===\n";
    g2.findBCCandAP(0);
    g2.findBCCandAP(3);
    g2.findBCCandAP(11);

    return 0;
}
