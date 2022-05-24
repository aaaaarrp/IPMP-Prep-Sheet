
// A Divide and Conquer based program for maximum subarray sum problem: Time: O(nLogn)

#include<bits/stdc++.h>
using namespace std;

int maximum(int a, int b){
    return (a > b) ? a : b;
}

int maximum(int a, int b, int c){
    return (maximum(maximum(a, b), c));
}

int maxCrossingSum(int array[], int left, int mid, int right){
    int sum = 0;
    int left_sum = INT_MIN;
    for(int i=mid; i >= left; i--){
        sum += array[i];
        if(sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;
    for(int i=mid+1; i <= right; i++){
        sum += array[i];
        if(sum > right_sum)
            right_sum = sum;
    }

    return maximum((left_sum + right_sum), left_sum, right_sum);
}

int maxSubArraySum(int array[], int left, int right){
    if(left == right)
        return array[left];
    int mid = (left+right)/2;
    return maximum(maxSubArraySum(array, left, mid),
                   maxSubArraySum(array, mid+1, right),
                   maxCrossingSum(array, left, mid, right));
}

int main()
{
    int arr[] = { 2, 3, 4, 5, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = maxSubArraySum(arr, 0, n - 1);
    printf("Maximum contiguous sum is %d\n", max_sum);
    getchar();
    return 0;
}