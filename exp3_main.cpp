#include <iostream>
#include "Graph.h"
#include "Traversal.h"
#include "ShortestPath.h"

using namespace std;

int main() {
    Graph g(8); // 8 个顶点

    g.addEdge(0, 1, 4);  g.addEdge(0, 3, 6);  g.addEdge(0, 7, 7);
    g.addEdge(1, 2, 12);
    g.addEdge(2, 3, 9);  g.addEdge(2, 4, 1);  g.addEdge(2, 5, 2);
    g.addEdge(3, 4, 5);
    g.addEdge(4, 5, 3);  g.addEdge(4, 6, 13); g.addEdge(4, 7, 11);
    g.addEdge(5, 6, 8);
    g.addEdge(6, 7, 14);

    cout << "Adjacency Matrix of Graph:" << endl;
    g.printAdjMatrix();

    cout << "\nBFS from node A (0):" << endl;
    BFS(g, 0);

    cout << "\n\nDFS from node A (0):" << endl;
    DFS(g, 0);

    cout << "\n\nDijkstra's Shortest Path from node A (0):" << endl;
    dijkstra(g, 0);

    return 0;
}
