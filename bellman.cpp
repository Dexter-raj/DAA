#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Structure to represent an edge between two nodes
struct Edge {
    int src, dest, weight;
};

// Function to perform the Bellman-Ford algorithm
void bellmanFord(int vertices, int edges, vector<Edge> &edgeList, int source) {
    // Step 1: Initialize distances from the source to all vertices as infinity
    vector<int> distance(vertices, INT_MAX);
    distance[source] = 0; // Distance to the source is 0

    // Step 2: Relax all edges |V| - 1 times
    for (int i = 1; i <= vertices - 1; i++) {
        for (int j = 0; j < edges; j++) {
            int u = edgeList[j].src;
            int v = edgeList[j].dest;
            int weight = edgeList[j].weight;

            // If the edge can relax the distance, update it
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    for (int j = 0; j < edges; j++) {
        int u = edgeList[j].src;
        int v = edgeList[j].dest;
        int weight = edgeList[j].weight;

        // If a shorter path is still found, a negative cycle exists
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            cout << "Graph contains a negative weight cycle!" << endl;
            return;
        }
    }

    // Output the shortest distances from the source to all vertices
    cout << "Vertex distances from source " << source << ":\n";
    for (int i = 0; i < vertices; i++) {
        if (distance[i] == INT_MAX)
            cout << "Vertex " << i << ": Infinity\n";
        else
            cout << "Vertex " << i << ": " << distance[i] << "\n";
    }
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    vector<Edge> edgeList(edges);
    cout << "Enter each edge with source, destination, and weight:\n";
    for (int i = 0; i < edges; i++) {
        cout << "Edge " << i + 1 << " (src, dest, weight): ";
        cin >> edgeList[i].src >> edgeList[i].dest >> edgeList[i].weight;
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    bellmanFord(vertices, edges, edgeList, source);

    return 0;
}
