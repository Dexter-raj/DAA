#include <iostream>
using namespace std;

int knapSack(int weight[], int profit[], int n, int cap) {
    int arr[n+1][cap+1];

    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= cap; w++) {  // Corrected initialization of 'w'
            if(i == 0 || w == 0) {
                arr[i][w] = 0;
            }
            else if(weight[i-1] <= w) {
                arr[i][w] = max(profit[i-1] + arr[i-1][w - weight[i-1]], arr[i-1][w]);
            }
            else {
                arr[i][w] = arr[i-1][w];
            }
        }
    } 

    cout << "\nDP Table\n";
    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= cap; w++) {
            cout << arr[i][w] << "\t";
        }
        cout << endl;
    }
    
    return arr[n][cap];
}

int main() {
    int n, cap;

    cout << "Enter the number of objects and capacity of the knapSack: ";
    cin >> n >> cap;

    int profit[n], weight[n];

    cout << "\nEnter the weights: ";
    for(int i = 0; i < n; i++) cin >> weight[i];

    cout << "\nEnter the profits: ";
    for(int i = 0; i < n; i++) cin >> profit[i];

    int maxProfit = knapSack(weight, profit, n, cap);
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
