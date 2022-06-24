// Program to find the largest subarray which contains equal no of 0s and 1s.

// Time: O(n^2) - Space: O(1)

#include<bits/stdc++.h>
using namespace std;

void largestSubarray(vector<int> &arr, int n){
    int sum = 0;
    int max_size = -1, start;
    for(int i=0; i<n-1;i++){
        if(arr[i] == 0)
            sum = -1;
        else
            sum = 1;
        for(int j=i+1; j<n; j++){
            if(sum == 0)
                sum += -1;
            else
                sum += 1;
            if(sum == 0 && max_size < j-i+1){
                max_size = j-i+1;
                start = i;
            }
        }
    }
    cout << start << " to " << start+max_size-1 << endl;
}

int main(){
    vector<int> arr = {1,0,1,1,1,0,0};
    largestSubarray(arr, arr.size());
    return 0;
}