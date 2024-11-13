#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define INF INT_MAX

int n; // Number of cities
int costMatrix[10][10]; // Cost matrix
int finalCost = INF; // Minimum cost found
vector<int> bestPath; // Path that gives the minimum cost

// Function to calculate minimum outgoing edge from a city
int findMinEdge(int city) {
    int minEdge = INF;
    for (int i = 0; i < n; i++) {
        if (costMatrix[city][i] < minEdge && costMatrix[city][i] != 0)
            minEdge = costMatrix[city][i];
    }
    return minEdge;
}

// Function to estimate the minimum cost with the current path
int calculateBound(const vector<int>& path, int currentCost) {
    int bound = currentCost;
    for (int i = 0; i < n; i++) {
        if (find(path.begin(), path.end(), i) == path.end()) // Unvisited cities
            bound += findMinEdge(i);
    }
    return bound;
}

// Recursive Branch and Bound for TSP
void branchAndBound(vector<int>& path, int currentCost) {
    int level = path.size(); // Current depth in the search tree

    if (level == n) { // All cities visited, complete cycle
        int totalCost = currentCost + costMatrix[path.back()][path[0]];
        if (totalCost < finalCost) {
            finalCost = totalCost;
            bestPath = path;
            bestPath.push_back(0); // Complete the cycle back to the start
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (find(path.begin(), path.end(), i) == path.end() && costMatrix[path.back()][i] != INF) { // Unvisited city
            int tempCost = currentCost + costMatrix[path.back()][i];
            int bound = calculateBound(path, tempCost);

            if (bound < finalCost) { // Proceed only if bound is promising
                path.push_back(i);
                branchAndBound(path, tempCost);
                path.pop_back(); // Backtrack
            }
        }
    }
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter Cost Matrix (use 0 for no path):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> costMatrix[i][j];
            if (costMatrix[i][j] == 0 && i != j) costMatrix[i][j] = INF; // Non-paths set to INF
        }
    }

    vector<int> path = {0}; // Start from city 0
    branchAndBound(path, 0);

    cout << "\nBest Path: ";
    for (int city : bestPath) cout << city + 1 << " --> ";
    cout << "1\nMinimum Cost: " << finalCost << endl;

    return 0;
}
