// Program for unbounded knapsack

/*  Differece between 0/1 knapsack & unbounded knapsack is that 
    In 0/1 knapsack we can take one item only once
    In unbounded knapsack we take one item as many times as we want
    So instead of taking 'n-1' items while including we'll take 'n' items
*/

// Bottop up approach

#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(vector<int> &value, vector<int> &wt, int sum, int n){
    vector<vector<int>> table (n+1, vector<int> (sum+1));

    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if (i == 0 || j == 0)
                table[i][j] = 0;
            else if(wt[i-1] <= j)
                table[i][j] = max(value[i-1]+table[i][j-wt[i-1]], table[i-1][j]);
            else
                table[i][j] = table[i-1][j];
        }
    }

    return table[n][sum];
}

int main() {
    vector<int> value = {10, 30, 20};
    vector<int> weight = {5, 10, 15};
    int capacity = 100;

    cout << unboundedKnapsack(value, weight, capacity, value.size()) << endl;
}