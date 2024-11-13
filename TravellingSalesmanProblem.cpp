#include <iostream>
using namespace std;

#define INF 999

int n, cost = 0;
int costMatrix[10][10];
bool visited[10] = {false};

void TSP(int city) {
    visited[city] = true;
    cout << city + 1 << " --> ";

    int nextCity = -1, minCost = INF;

    for (int i = 0; i < n; ++i) {
        if (!visited[i] && costMatrix[city][i] && costMatrix[city][i] < minCost) {
            minCost = costMatrix[city][i];
            nextCity = i;
        }
    }

    if (nextCity == -1) { // No unvisited cities left, return to start
        cout << "1";
        cost += costMatrix[city][0];
    } else {
        cost += minCost;
        TSP(nextCity);
    }
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter Cost Matrix (use 0 for no direct path):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> costMatrix[i][j];
            if (costMatrix[i][j] == 0 && i != j) // Set non-paths to INF
                costMatrix[i][j] = INF;
        }
    }

    cout << "\nThe Best Path is:\n";
    TSP(0);
    cout << "\nMinimum Cost: " << cost << endl;

    return 0;
}
