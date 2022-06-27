// Program to Find subarray with given sum

// Time Complexity: O(n^2) - Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

int subArraySum(int arr[], int n, int sum){
    int curr_sum;
    for(int i=0; i<n; i++){
        curr_sum = arr[i];
        for(int j=i+1; j<=n; j++){
            if(curr_sum == sum){
                cout << "Sum found between: " << i << " & " << j - 1 << endl;
                return 1;
            }
            if(curr_sum > sum || j == n)
                break;
            curr_sum += arr[j];
        }
    }
    cout << " No subarray found" << endl;
    return 0;
}

int main(){
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 23;
    subArraySum(arr, n, sum);
    return 0;
}