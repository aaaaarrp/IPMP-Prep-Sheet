// Program to find the fewest no of coins needed to make up the given amount
// This problem is also known as Coin Change on leetCode

// Variation of Unbounded knapsack & Extension of Coin Change
// Bottom up approach

#include<bits/stdc++.h>
using namespace std;

int minCoinNeeded(int n, int amount, vector<int> &coins){

    // storing no of coins = table[x][y]
    vector<vector<int>> table(n+1, vector<int> (amount+1));

    for(int i=0; i<amount+1; i++)
        table[0][i] = INT_MAX-1;    // INT_MAX-1 to avoid overflow
    for(int i=0; i<n+1; i++)
        table[i][0] = 0;

    for(int i=1; i<n+1; i++){
        for(int j=1; j<amount+1; j++){
            if(coins[i-1] <= j)
                table[i][j] = min(1+table[i][j-coins[i-1]], table[i-1][j]);
            else
                table[i][j] = table[i-1][j];
        }
    }
    
    return table[n][amount] = (table[n][amount] > amount) ? -1 : table[n][amount];
}

int main(){
    vector<int> coins = {1, 2, 9, 10};
    int amount = 12;

    cout << minCoinNeeded(coins.size(), amount, coins) << endl;
}