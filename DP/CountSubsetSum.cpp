// Program to count the no of subsets whose sum equal to k 

// Variation of 0/1 knapsack & Extension of Subset Sum problem
// Bottom up approach - O(n^2)

#include <bits/stdc++.h>
using namespace std;

int countSubsetSum(int n, int sum, vector<int> &nums){
    vector<vector<int>> table(n+1, vector<int> (sum+1));
    for(int j=1; j<sum+1; j++)
        table[0][j] = 0;
    for(int i=0; i<n+1; i++)
        table[i][0] = 1;
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(nums[i-1] <= j)
                table[i][j] = table[i-1][j-nums[i-1]] + table[i-1][j];
            else
                table[i][j] = table[i-1][j];
        }
    }
    return table[n][sum];
}

int main()
{
    vector<int> arr = {1, 2, 2, 9, 10};
    int k = 12;

    cout << countSubsetSum(arr.size(), k, arr) << endl;
}