#include <iostream>
#include <climits>
using namespace std;

struct Edge {
    int src, dest, wgt;
};

void bellmanFord(int V, int E, Edge edges[], int src) {
    int dist[V];
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src, v = edges[j].dest, w = edges[j].wgt;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // Check for negative weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j].src, v = edges[j].dest, w = edges[j].wgt;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Graph contains a negative weight cycle\n";
            return;
        }
    }

    // Print distances
    cout << "Vertex Distance from Source:\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dist[i] << "\n";
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    Edge edges[E];

    cout << "Enter each edge (src dest weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].wgt;
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    bellmanFord(V, E, edges, src);
    return 0;
}
