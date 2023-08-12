#ifndef GRAPH_H
#define GRAPH_H

class Node {
   public:
    int vertex;
    Node* next;

    Node(int vertex) {
        this->vertex = vertex;
        next = nullptr;
    }
};

class Graph {
   private:
    int** adj_matrix;
    Node** adj_list;
    int num_vertices;

   public:
    Graph(int num_vertices);
    ~Graph();
    void add_edge(int from, int to, int weight, bool directed);
    void remove_edge(int from, int to, bool directed);
    void print_graph_matrix() const;
    void print_graph_list() const;
    void DFS_matrix(int start) const;
    void DFS_list(int start) const;
    void BFS_matrix(int start) const;
    void BFS_list(int start) const;
    int*** path_matrix(int num_path);
    void bfs_shortest_path(int from, int to) const;
    void dijkstra(int start, int target) const;
    long long** floyd_warshall() const;
};

#endif