// Uisng Binary Search to find the maximum element in an array which is first increasing and then decreasing
// Time: O(logn)
// Iterative solution

#include<bits/stdc++.h>
using namespace std;

int search(vector<int>nums, int low, int high){
    while (low <= high){
        int mid = low + (high-low)/2;

    if((high == low+1) && (nums[high] > nums[low]))
        return nums[high];
    
    if((high == low+1) && (nums[high] < nums[low]))
        return nums[low];
    
    if((nums[mid] > nums[mid+1]) && (nums[mid] > nums[mid-1]))
        return nums[mid];

    if((nums[mid] > nums[mid+1]) && (nums[mid] < nums[mid-1]))
        high = mid-1;
    else    
        low = mid+1;

    }

    return -1;
    
}

int main(void){
    vector<int> nums = { 1, 3, 50, 10, 9, 7, 6 };
    int size = nums.size();

    cout << " The maximum element is " << search(nums, 0, size-1) << endl;

    return 0;
}