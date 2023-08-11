#include "graph.h"

#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
typedef pair<int, int> pi;

Graph::Graph(int num_vertices) {
    this->num_vertices = num_vertices;

    // for adjacency matrix representation
    adj_matrix = new int*[num_vertices];
    for (int i = 0; i < num_vertices; i++) {
        adj_matrix[i] = new int[num_vertices];
        for (int j = 0; j < num_vertices; j++) {
            adj_matrix[i][j] = 0;
        }
    }

    // for adjacency list representation
    adj_list = new Node*[num_vertices];
    for (int i = 0; i < num_vertices; i++) adj_list[i] = nullptr;
}

Graph::~Graph() {
    // delete allocated memory for both adjacency matrix and list
    for (int i = 0; i < num_vertices; i++) {
        delete[] adj_matrix[i];
        delete[] adj_list[i];
    }

    delete[] adj_matrix;
    delete[] adj_list;
}

void Graph::print_graph_matrix() const {
    for (int i = 0; i < num_vertices; i++) {
        cout << i << " : ";
        for (int j = 0; j < num_vertices; j++)
            cout << adj_matrix[i][j] << " ";
        cout << "\n";
    }
}

void Graph::add_edge(int from, int to, int weight, bool directed) {
    // for adding element in adjacency matrix
    adj_matrix[from][to] = weight;
    if (!directed) adj_matrix[to][from] = weight;

    // for adding element in adjacency list
    Node* new_node = new Node(to);
    new_node->next = adj_list[from];
    adj_list[from] = new_node;

    if (!directed) {
        new_node = new Node(from);
        new_node->next = adj_list[to];
        adj_list[to] = new_node;
    }
}

void Graph::remove_edge(int i, int j, bool directed) {
    // remove edge from adjacency matrix
    adj_matrix[i][j] = 0;
    if (!directed) adj_matrix[j][i] = 0;

    // remove edge from adjacency list
    auto temp = adj_list[i];
    auto prev = temp;
    while (temp->vertex != j && temp != nullptr) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
        cout << "no such edge exist";
    else
        prev->next = temp->next, delete temp;

    if (directed) return;
    temp = adj_list[j];
    prev = temp;
    while (temp->vertex != i && temp != nullptr)
        prev = temp, temp = temp->next;

    if (temp == nullptr)
        cout << "no such edge exist";
    else
        prev->next = temp->next, delete temp;
}

void Graph::print_graph_list() const {
    for (int i = 0; i < num_vertices; i++) {
        cout << i << ": ";
        Node* temp = adj_list[i];
        while (temp != nullptr) {
            cout << " -> " << temp->vertex;
            temp = temp->next;
        }
        cout << '\n';
    }
}

void Graph::DFS_matrix(int start) const {
    bool visited[num_vertices] = {0};
    stack<int> s;

    s.push(start);
    visited[start] = true;
    while (!s.empty()) {
        int v = s.top();
        s.pop();
        cout << v << ' ';
        for (int i = 0; i < num_vertices; i++) {
            if (adj_matrix[v][i] != 0 && !visited[i]) {
                s.push(i);
                visited[i] = true;
            }
        }
    }
    cout << '\n';
}

void Graph::DFS_list(int start) const {
    bool visited[num_vertices] = {0};
    stack<int> s;

    s.push(start);
    visited[start] = true;
    while (!s.empty()) {
        int v = s.top();
        s.pop();
        cout << v << ' ';

        Node* temp = adj_list[start];
        while (temp != nullptr) {
            int data = temp->vertex;
            if (!visited[data]) s.push(data);
            temp = temp->next;
        }
    }
    cout << '\n';
}

void Graph::BFS_matrix(int start) const {
    bool visited[num_vertices] = {0};
    queue<int> q;

    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << ' ';
        for (int i = 0; i < num_vertices; i++) {
            if (adj_matrix[v][i] != 0 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void Graph::BFS_list(int start) const {
    bool visited[num_vertices] = {0};
    queue<int> q;

    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << ' ';

        Node* temp = adj_list[start];
        while (temp != nullptr) {
            int data = temp->vertex;
            if (!visited[data]) q.push(data);
            temp = temp->next;
        }
    }
    cout << '\n';
}

int*** Graph::path_matrix(int num_path) {
    int*** m = new int**[num_path];
    for (int i = 0; i < num_path; i++) {
        m[i] = new int*[num_vertices];
        for (int j = 0; j < num_vertices; j++) {
            m[i][j] = new int[num_vertices];
            memset(m[i][j], 0, sizeof(int) * num_vertices);
            // for (int k = 0; k < num_vertices; k++)
            //     m[i][j][k] = 0;
        }
    }

    m[0] = adj_matrix;

    for (int l = 1; l < num_path; l++) {
        for (int i = 0; i < num_vertices; i++) {
            for (int j = 0; j < num_vertices; j++) {
                for (int k = 0; k < num_vertices; k++) {
                    m[l][i][j] += m[0][i][k] * m[l - 1][k][j];
                }
            }
        }
    }

    return m;
}

void Graph::bfs_shortest_path(int from, int to) const {
    bool visited[num_vertices] = {0};
    queue<int> q;

    q.push(from);
    visited[from] = true;
    int prev[num_vertices];
    memset(prev, -1, sizeof(int) * num_vertices);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        // cout << v << ' ';
        for (int i = 0; i < num_vertices; i++) {
            if (adj_matrix[v][i] != 0 && !visited[i]) {
                q.push(i);
                visited[i] = true;
                prev[i] = v;
                if (i == to) break;
            }
        }
    }

    stack<int> path;
    int temp = to;
    while (temp != -1) {
        path.push(temp);
        temp = prev[temp];
    }

    if (path.top() != from) {
        cout << "there is no path from " << from << " to " << to << '\n';
    } else {
        cout << path.top();
        path.pop();
        while (!path.empty()) {
            cout << " -> " << path.top();
            path.pop();
        }
    }

    cout << '\n';
}

void Graph::dijkstra(int start, int target) const {
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    int distance[num_vertices];
    bool visited[num_vertices];
    int pred[num_vertices];

    for (int i = 0; i < num_vertices; i++)
        distance[i] = INT_MAX, visited[i] = false, pred[i] = start;

    distance[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int current = pq.top().second;
        visited[current] = true;
        pq.pop();
        for (int i = 0; i < num_vertices; i++) {
            int weight = adj_matrix[current][i];
            if (weight == 0 || visited[i]) continue;

            // distance[i] = min(distance[i], weight + distance[current]);
            int min_distance = weight + distance[current];
            if (distance[i] > min_distance)
                distance[i] = min_distance, pred[i] = current;
            pq.push(make_pair(distance[i], i));
        }
    }

    cout << distance[target] << '\n';
    // for (int i : pred) cout << i << ' ';

    // print the path from start to target
    stack<int> path;
    int temp = target;
    while (temp != start) {
        path.push(temp);
        temp = pred[temp];
        if (temp == start) path.push(temp);
    }

    if (path.top() != start) {
        cout << "there is no path from " << start << " to " << target << '\n';
    } else {
        cout << path.top();
        path.pop();
        while (!path.empty()) {
            cout << " -> " << path.top();
            path.pop();
        }
    }

    cout << '\n';
}
