/* Program to find the sum of the contiguous subarray
within a one-dimensional array of numbers that has the largest sum */

// Kadane's Algorithm 
// To print the subarray
// Time Complexity : O(n) - Auxiliary Space : O(1)

#include <bits/stdc++.h>
using namespace std;

void maxSubArraySum(int arr[], int size){
    int max_sum = INT_MIN, curr_sum = 0;
    int start =0, end = 0, s = 0;

    for(int i = 0; i<size; i++){
        curr_sum += arr[i];
        if(curr_sum > max_sum){
            max_sum = curr_sum;
            start = s;
            end = i;
        }
        if(curr_sum < 0)
            curr_sum = 0;
    }
    cout << "Sum: " << max_sum << endl;
    cout << "Starting index: " << start << " Ending index: " << end << endl;
}

int main()
{
    int a[] = { -2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);
    maxSubArraySum(a, n);
    return 0;
}
