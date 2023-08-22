#include <iostream>

#include "graph.h"
using namespace std;

int main() {
    int n = 4;
    Graph g(n);

    g.add_edge(0, 3, 1);
    g.add_edge(1, 0, 1);
    g.add_edge(1, 2, 1);
    g.add_edge(1, 3, 1);
    g.add_edge(2, 0, 1);
    g.add_edge(2, 3, 1);
    g.add_edge(3, 2, 1);

    g.print_graph_matrix();

    // path matrix
    int** path = g.path_matrix();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << path[i][j] << ' ';
        }
        cout << '\n';
    }

    // shortest path matrix
    // long long** shortest_path = g.floyd_warshall();
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << shortest_path[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    // cout << '\n';
    // g.print_graph_matrix();
    // g.remove_edge(0, 5, 0);
    // g.bfs_shortest_path(0, 3);
    // g.dijkstra(0, 3);
}
