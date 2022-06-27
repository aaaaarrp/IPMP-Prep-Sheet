/* Program to find the sum of the contiguous subarray
within a one-dimensional array of numbers that has the largest sum */

// Kadane's Algorithm - Dynamic programming
// Time Complexity : O(n) - Auxiliary Space : O(1)

#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(int arr[], int size)
{
    int max_sum = arr[0];
    int curr_sum = arr[0];

    for(int i=1; i<size; i++){
        curr_sum = max(arr[i], curr_sum+arr[i]);
        max_sum = max(max_sum, curr_sum);
    }
    
    return max_sum;
}

int main()
{
    int a[] = {-2, -3, -4, -1, -2, -1, -5, -3};
    int n = sizeof(a) / sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum << endl;
    return 0;
}
