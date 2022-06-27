// Program to Find subarray with given sum

// Time Complexity: O(n) - Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int subArraySum(int arr[], int n, int sum){
    int start = 0;
    int curr_sum = arr[0];
    for(int i=1; i<=n; i++){
        while (curr_sum > sum && start < i - 1)
        {
            curr_sum -= arr[start];
            start++;
        }
        if(curr_sum == sum){
            cout << "Sum found between: " << start << " & " << i-1 << endl;
            return 1;
        }
        if(i < n){
            curr_sum += arr[i];
        }
    }
    cout << "Subarray not found" << endl;
    return 0;
}

int main(){
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 24};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 34;
    subArraySum(arr, n, sum);
    return 0;
}