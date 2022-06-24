// Program to Find the two repeating elements in a given array

// Using  Count array
// Time: O(n) - Space: O(n)

#include<bits/stdc++.h>
using namespace std;

void getTwoElements(vector<int> nums, int size){
    int *count = new int[sizeof(int)*(size-2)];
    int i;

    cout << " Repeating elements are ";

    for(i=0; i<size; i++){
        if(count[nums[i]] == 1)
            cout << nums[i] << " ";
        else
            count[nums[i]]++;
    }
}

int main(){
    vector<int> nums = {4, 2, 4, 5, 2, 3, 1};
    getTwoElements(nums, nums.size());
}