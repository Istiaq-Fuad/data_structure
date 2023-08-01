#include <iostream>

#include "graph.h"
using namespace std;

int main() {
    int n = 9;
    Graph g(n);

    g.add_edge(0, 1, 0);
    g.add_edge(0, 2, 0);
    g.add_edge(0, 5, 0);
    g.add_edge(1, 2, 0);
    g.add_edge(1, 6, 0);
    g.add_edge(2, 5, 0);
    g.add_edge(3, 2, 0);
    g.add_edge(4, 2, 0);
    g.add_edge(4, 3, 0);
    g.add_edge(4, 7, 0);
    g.add_edge(5, 3, 0);
    g.add_edge(6, 2, 0);
    g.add_edge(6, 4, 0);
    g.add_edge(7, 3, 0);
    g.add_edge(7, 8, 0);
    g.add_edge(8, 4, 0);
    g.add_edge(8, 6, 0);
    // g.add_edge(4, 5, 0);
    // g.add_edge(4, 6, 0);

    // g.DFS_matrix(0);

    // int*** path = g.path_matrix(4);
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << path[3][i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    g.print_graph_matrix();
    g.bfs_shortest_path(0, 7);
}
