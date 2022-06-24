// Program to Find the two repeating elements in a given array

// Using sets
// Time: O(n) - Space: O(n)

#include<bits/stdc++.h>
using namespace std;

void getTwoRepeatingElements(vector<int> nums, int size){
    unordered_set<int> s;

    cout<<"The two Repeating elements are : ";

    for(int i=0; i<size; i++){
        if(s.empty() == false && s.find(nums[i]) != s.end())
            cout << nums[i] << " ";
        s.insert(nums[i]);
    }
}

int main(){
    vector<int> nums = {4, 2, 4, 5, 2, 3, 1};
    getTwoRepeatingElements(nums, nums.size());
}