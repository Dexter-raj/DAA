#include <iostream>
using namespace std;

struct obj {
    double profit;
    double weight;
    double ratio;
};

void input(obj arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter weight of object " << i + 1 << ": ";
        cin >> arr[i].weight;
        cout << "Enter profit of object " << i + 1 << ": ";
        cin >> arr[i].profit;
        arr[i].ratio = arr[i].profit / arr[i].weight;
    }
}

void sort(obj arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].ratio < arr[j + 1].ratio) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void calculateMaxProfit(obj arr[], int n, double maxWeight) {
    sort(arr, n);
    double totalProfit = 0.0;
    double remainingWeight = maxWeight;

    for (int i = 0; i < n; i++) {
        if (remainingWeight == 0) break;
        
        if (arr[i].weight <= remainingWeight) {
            totalProfit += arr[i].profit;
            remainingWeight -= arr[i].weight;
        } else {
            totalProfit += arr[i].profit * (remainingWeight / arr[i].weight);
            remainingWeight = 0;
        }
    }

    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    int n;
    double maxWeight;

    cout << "Enter number of objects: ";
    cin >> n;
    cout << "Enter total knapsack capacity: ";
    cin >> maxWeight;

    obj arr[n];
    input(arr, n);
    calculateMaxProfit(arr, n, maxWeight);

    return 0;
}
