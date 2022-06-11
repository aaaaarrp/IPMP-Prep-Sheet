// Program to Print the First Greater Element on the right side for each element

// Naive method
// Time Complexity: O(n^2) - Auxiliary Space: O(1)

#include<bits/stdc++.h>
using namespace std;

void NGE(vector<int> nums, int n){
    int next;
    for(int i=0; i<n; i++){
        next = -1;
        for(int j=i+1; j<n; j++){
            if(nums[i] < nums[j]){
                next = nums[j];
                break;
            }
        }
        cout << nums[i] << " -> " << next << endl;
    }
}

int main(){
    vector<int> nums = {11, 13, 21, 3};
    NGE(nums, nums.size());
    return 0;
}