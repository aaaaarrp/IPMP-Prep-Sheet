// Program to find the max no of ways that coins in the given array can makeup the given amount
// Also known as Coin Change II problem on LeetCode

// Variation of unbounded knapsack & Count Subset Sum problem of 0/1 knapsack
// Bottom up approach


#include<bits/stdc++.h>
using namespace std;

int maxCoinCombinations(int n, int amount, vector<int> &coins){
    vector<vector<int>> table(n+1, vector<int> (amount+1));
    for(int i=1; i<amount+1; i++)
        table[0][i] = 0;
    for(int i=0; i<n+1; i++)
        table[i][0] = 1;
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<amount+1; j++){
            if(coins[i-1] <= j)
                table[i][j] = table[i][j-coins[i-1]] + table[i-1][j];
            else
                table[i][j] = table[i-1][j];
        }
    }
    return table[n][amount];
}

int main(){
    vector<int> coins = {1, 2, 9, 10};
    int amount = 12;

    cout << maxCoinCombinations(coins.size(), amount, coins) << endl;
}