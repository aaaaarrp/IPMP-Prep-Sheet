
// A dynamic programming based solution for 0-1 Knapsack problem 

// Time O(N*W) : Space O(W)
// we are using 1-D array instead of 2-D array.

#include <bits/stdc++.h>
using namespace std;

int maximum(int a, int b){
    return (a > b) ? a : b;
}

int knapsack(int value[], int weight[], int W, int n){
    // making and initializing dp array
    int dp[W+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i < n+1; i++){
        for(int w=W; w >= 0; w--){
            if(weight[i-1] <= w)        
                dp[w] = maximum(value[i-1]+dp[w-weight[i-1]], dp[w]);   // finding the maximum value
        }
    }
    return dp[W];
}

int main(){
    int value[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50;
    int size = sizeof(value)/sizeof(value[0]);
    cout << knapsack(value, weight, W, size);
}