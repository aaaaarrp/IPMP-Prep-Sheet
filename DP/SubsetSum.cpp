// Program to find if the subset sum equal to k
// Variation of 0/1 knapsack
// Bottom up approach - O(n^2)

#include<bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int sum, vector<int> &arr){
    vector<vector<int>> table(n + 1, vector<int>(sum + 1));

    for (int j = 1; j < sum + 1; j++){
        table[0][j] = false;
    }
    for (int i = 0; i < n + 1; i++){
        table[i][0] = true;
    }

    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < sum + 1; j++){
            if (arr[i - 1] <= j)
                table[i][j] = table[i - 1][j - arr[i - 1]] || table[i - 1][j];
            else
                table[i][j] = table[i - 1][j];
        }
    }

    return table[n][sum];
}

int main()
{
    vector<int> arr = {1, 7, 2, 9, 10};
    int k = 13;

    if(subsetSumToK(arr.size(), k, arr))
        cout << "True\n";
    else
        cout << "False\n";
}