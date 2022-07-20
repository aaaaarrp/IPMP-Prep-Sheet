/* Program to find if the array can be partitioned into two subsets,
   such that the sum of elements in both subsets is equal.  */

// Variation of 0/1 knapsack & Extension of Subset Sum problem
// Bottom up approach - O(n^2)

#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int> &nums)
{
    int n = nums.size();

    long sum = 0;
    for (int i = 0; i < n; i++)
        sum += nums[i];
    if (sum % 2 != 0)
        return false;

    sum = sum / 2;  // subset sum problem starts

    vector<vector<int>> table(n + 1, vector<int>(sum + 1));
    for (int j = 0; j < sum + 1; j++)
        table[0][j] = false;
    for (int i = 0; i < n + 1; i++)
        table[i][0] = true;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (nums[i - 1] <= j)
                table[i][j] = table[i - 1][j - nums[i - 1]] || table[i - 1][j];
            else
                table[i][j] = table[i - 1][j];
        }
    }

    return table[n][sum];
}

int main()
{
    vector<int> arr = {1, 2, 2, 9, 10};

    if (canPartition(arr))
        cout << "True\n";
    else
        cout << "False\n";
}