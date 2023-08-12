#include <iostream>

#include "graph.h"
using namespace std;

int main() {
    int n = 4;
    Graph g(n);

    g.add_edge(0, 0, 7, 1);
    g.add_edge(0, 1, 5, 1);
    g.add_edge(1, 0, 7, 1);
    g.add_edge(1, 3, 2, 1);
    g.add_edge(2, 1, 3, 1);
    g.add_edge(3, 0, 4, 1);
    g.add_edge(3, 2, 1, 1);
    // g.add_edge(4, 2, 7, 0);
    // g.add_edge(4, 3, 6, 0);
    // g.add_edge(4, 7, 0);
    // g.add_edge(5, 3, 0);
    // g.add_edge(6, 2, 0);
    // g.add_edge(6, 4, 0);
    // g.add_edge(7, 3, 0);
    // g.add_edge(7, 8, 0);
    // g.add_edge(8, 4, 0);
    // g.add_edge(8, 6, 0);
    // g.add_edge(4, 5, 0);
    // g.add_edge(4, 6, 0);

    // g.DFS_matrix(0);

    // path matrix
    // int*** path = g.path_matrix(4);
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << path[3][i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    // shortest path matrix
    long long** shortest_path = g.floyd_warshall();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << shortest_path[i][j] << ' ';
        }
        cout << '\n';
    }

    g.print_graph_matrix();
    // g.remove_edge(0, 5, 0);
    g.bfs_shortest_path(0, 3);
    g.dijkstra(0, 3);
}
