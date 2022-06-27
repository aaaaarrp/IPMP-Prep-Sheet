/* Program to find the sum of the contiguous subarray
within a one-dimensional array of numbers that has the largest sum */

// Kadane's Algorithm
// Doesn't work with array containg all negative numbers
// Time Complexity : O(n) - Auxiliary Space : O(1)

#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(int arr[], int size){
    int max = INT_MIN;
    int curr_sum = 0;

    for(int i=0; i<size; i++){
        curr_sum += arr[i];
        if(curr_sum > max)
            max = curr_sum;
        if(curr_sum < 0)
            curr_sum = 0;
    }

    return max;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum << endl;
    return 0;
}
