
// Brute-Force: A Naive recursive implementation of 0-1 Knapsack problem : Time O(2^n) : Space O(1)

#include <bits/stdc++.h>
using namespace std;

// A utility function that returns maximum of two integers
int maxiMum(int a, int b){
    return (a > b) ? a : b;
}

// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack(int value[], int weight[], int W, int n){
    // Base case
    if( n == 0 || W == 0)
    return 0;

    // If weight of the nth item is more than Knapsack capacity W,
    // then this item cannot be included in the optimal solution
    if(weight[n-1] > W)
        return knapsack(value, weight, W, n-1);
    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else{
        return maxiMum(value[n-1]+knapsack(value, weight, W - weight[n-1], n-1), knapsack(value, weight, W, n-1));
    }
}

int main(){
    int value[] = { 60, 50, 20 };
    int weight[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(value)/sizeof(value[0]);
    cout << knapsack(value, weight, W, n);

    return 0;
}