// Program to find the largest subarray which contains equal no of 0s and 1s.

// Using hashmap
// Time: O(n) - Space: O(n)

#include<bits/stdc++.h>
using namespace std;

void largestSubarray(vector<int> &arr, int n){
    unordered_map<int, int> hash;
    int sum = 0;
    int max_length = 0;
    int end = -1;

    for(int i=0; i<n; i++)
        arr[i] = (arr[i] == 0) ? -1 : 1;
    
    for(int i=0; i<n; i++){
        sum += arr[i];

        if(sum == 0){
            max_length = i+1;
            end = i;
        }

        if(hash.find(sum) != hash.end()){
            if(max_length < i - hash[sum]){
                max_length = i - hash[sum];
                end = i;
            }
        }
        else {
            hash[sum] = i;
        }
    }

    for(int i=0; i<n; i++){
        arr[i] = (arr[i] == 0) ? 0 : 1;
    }

    cout << end-max_length+1 << " to " << end << endl;
}

int main(){
    vector<int> arr = {1,0,1,1,1,0,0};
    largestSubarray(arr, arr.size());
    return 0;
}