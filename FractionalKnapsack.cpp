//Greedy approach to solve Fractional Knapsack problem

#include <iostream>
using namespace std;

struct obj{
    double profit;
    double weight;
    double ratio;
};

void input (obj arr[] , int n){
   
    for(int i=0; i<n; i++){

        cout<<"Enter the weight of Object "<<i+1<<": ";
        cin>>arr[i].weight;
        cout<<"Enter the profit of Object "<<i+1<<": ";
        cin>>arr[i].profit;
        arr[i].ratio = arr[i].profit / arr[i].weight;

    }
}

void sort (obj arr[] , int n){

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j].ratio > arr[j+1].ratio){
                int temp = arr[j].ratio;
                arr[j].ratio = arr[j+1].ratio;
                arr[j+1].ratio = temp;
            }
        }
    }
}

void calculateMaxProfit (obj arr[], int n, double maxWeight){

    cout<<"weight\tprofit\tratio";
    for(int i=0; i<n; i++){
        cout<<"\n"<<arr[i].weight<<"\t"<<arr[i].profit<<"\t"<<arr[i].ratio;
    }
    
    sort (arr , n);
    double totalProfit = 0.0;
    double remainingWeight = maxWeight;

    for(int i=0; i<n; i++){

        if(remainingWeight == 0){ //if the knapsack is full
            break;
        }
        if(arr[i].weight <= remainingWeight){
            totalProfit += arr[i].profit;
            remainingWeight -= arr[i].weight;
        }else{
            totalProfit += arr[i].profit * (remainingWeight / arr[i].weight);
            remainingWeight = 0;
        }    
    }
    
    cout<<"\nTotal Profit : "<<totalProfit<<endl;
}

int main () {
    int n;
    double maxWeight;

    cout<<"\nEnter the number of Objects : ";
    cin>>n;
    cout<<"\nEnter the max capacity of Knapsack : ";
    cin>>maxWeight;

    obj arr[n];
    input(arr , n);
    calculateMaxProfit(arr, n, maxWeight);
}
