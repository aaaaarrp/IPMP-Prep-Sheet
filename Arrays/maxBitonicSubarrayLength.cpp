// Program to print the Maximum Length Bitonic Subarray 

// Time: O(n) - Space: O(n)

#include<bits/stdc++.h>
using namespace std;

int bitonicSubarray(vector<int> &arr, int n){
    vector<int> inc(n);
    inc[0] = 1; 

    for(int i = 1; i < n; i++){
        int prev = i-1;
        if(arr[i] >= arr[prev])
            inc[i] = inc[prev]+1;
        else
            inc[i] = 1;
    }

    vector<int> dec(n);
    dec[n-1] = 1;

    for(int i = n-2; i >= 0; i--){
        int next = i+1;
        if(arr[i] >= arr[next])
            dec[i] = dec[next]+1;
        else
            dec[i] = 1;
    }

    int length = inc[0]+dec[0]-1;
    for(int i = 1; i < n-1; i++){
        int new_length = inc[i] + dec[i] - 1;
        if(new_length > length)
            length = new_length;
    }

    return length;
}

int main(){
    vector<int> arr = {12, 4, 78, 90, 45, 23};
    cout << "Length of max length Bitonic Subarray is " << bitonicSubarray(arr, arr.size()) << endl;
    return 0;
}