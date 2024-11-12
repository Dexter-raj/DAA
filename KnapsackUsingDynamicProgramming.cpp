#include <iostream>
#include <vector>

using namespace std;

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapsack(const vector<int>& weights, const vector<int>& profits, int capacity) {
    int n = weights.size(); // Number of items
    
    // Create a 2D dp table to store maximum profit values for each subproblem
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the dp table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                // Choose the maximum between including the item or excluding it
                dp[i][w] = max(profits[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                // If item weight exceeds current capacity, exclude it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Display the dp table (optional, for understanding or debugging)
    cout << "\nKnapsack Table:\n";
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }

    // The bottom-right cell contains the maximum profit for the given capacity
    return dp[n][capacity];
}

int main() {
    int n, capacity;
    
    // Input the number of items and knapsack capacity
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    // Input the weights and profits of each item
    vector<int> weights(n), profits(n);
    
    cout << "\nEnter the weights of the items:\n";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "\nEnter the profits of the items:\n";
    for (int i = 0; i < n; i++) {
        cin >> profits[i];
    }

    // Calculate and display the maximum profit
    int maxProfit = knapsack(weights, profits, capacity);
    cout << "\nMaximum profit is: " << maxProfit << endl;

    return 0;
}
