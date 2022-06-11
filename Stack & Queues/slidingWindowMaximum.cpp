// Program to find the maximum for each and every contiguous subarray of size k, Given an array and an integer K.

// Time Complexity: O(N * K) - Space Complexity: O(1).
// The outer loop runs n-k+1 times
// the inner loop runs k times for every iteration of outer loop.
// So time complexity is O((n-k+1)*k) which can also be written as O(N * K).


#include<bits/stdc++.h>
using namespace std;

void printKMax(int arr[], int n, int k){
    int i, j , max;
    
    for(i = 0; i <= n-k; i++){
        max = arr[i];
        for(j=1; j<k; j++){
            if(arr[i+j] > max)
                max = arr[i+j];
        }
        cout << max << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    clock_t tStart = clock();
    printKMax(arr, n, k);
    printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}