// Program to Find the two repeating elements in a given array

// Using naive method - two nested loops
// Time: O(n^2)

#include<bits/stdc++.h>
using namespace std;

void getTwoRepeatingElements(vector<int> nums, int n){
    int count = 0;
    vector<int> arr;
    for(int i=0; i < n; i++){
        for(int j=0; j<n; j++){
            if(nums[i] == nums[j]){
                count++;
            }
        }
        if(count >= 2 && arr.size() < 2)
            arr.push_back(nums[i]);
        count = 0;
    }
    for(auto i:arr)
        cout << i << " ";
    cout <<  endl;
}

int main(){
    vector<int> nums = {4, 2, 5, 2, 3, 3, 4, 4, 1, 1};
    getTwoRepeatingElements(nums, nums.size());
}