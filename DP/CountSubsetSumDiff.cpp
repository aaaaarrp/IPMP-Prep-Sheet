// Program to count the number of subsets with a given difference in an array

// Variation of 0/1 knapsack & Extension of Counting subsets with a given sum
// This problem is also knows as Target Sum on LeetCode
// Bottom up -> Time O(n^2)

#include<bits/stdc++.h>
using namespace std;

int countSubsets(vector<int> &nums, int n, int sum){
    vector<vector<int>> table(n + 1, vector<int>(sum + 1)); 
    for (int i = 0; i < n + 1; i++)
        table[i][0] = 1;
    for (int j = 1; j < sum + 1; j++)
        table[0][j] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (nums[i - 1] <= j)
                table[i][j] = table[i - 1][j - nums[i - 1]] + table[i - 1][j];
            else
                table[i][j] = table[i - 1][j];
        }
    }

    return table[n][sum];
}

int countSubsetSumDiff(vector<int> &nums, int n, int diff){
    
    int total_sum = 0;
    for(auto it: nums)
        total_sum += it;

    if(total_sum < diff || (total_sum+diff)%2 != 0)
        return 0;

    int sum = (total_sum + diff) / 2;

    return countSubsets(nums, n, sum);
}

int main(){
    vector<int> nums = {1,1,1,1,1};
    int diff = 3;
    cout << countSubsetSumDiff(nums, nums.size(), diff) << endl;
}