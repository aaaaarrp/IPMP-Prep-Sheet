// Program to Rearrange positive and negative numbers alternatively

/*
Maintaining order -> Time: O(n^2) - Space: O(1)
    -> https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/

Maintaining order -> Time: O(nlogn) - Space: O(n1 + n2 + log n)/O(logn)
    -> https://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers/


Without maintaining order -> Time: O(n) - Auxiliary: O(1)
    -> Move negative elements in the begining
    -> Take two pointers - one from 0 and another from positive num
    -> Start swapping
*/

#include<bits/stdc++.h>
using namespace std;

void rearrange(vector<int> &arr, int n){
    int i = -1;
    for(int j=0; j<n; j++){
        if(arr[j] < 0){
            i++;
            swap(arr[j], arr[i]);
        }
    }

    int pos = i+1;
    int neg = 0;
    while(pos < n && neg < n && arr[neg] < 0){
        swap(arr[neg], arr[pos]);
        pos++;
        neg += 2;
    }
}

int main()
{
    vector<int> arr = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    rearrange(arr, arr.size());
    
    for(auto i: arr)
        cout << i << " ";
    cout << endl;
    return 0;
}