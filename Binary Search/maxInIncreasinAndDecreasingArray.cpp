// Uisng Binary Search to find the maximum element in an array which is first increasing and then decreasing
// Time: O(logn)


#include<bits/stdc++.h>
using namespace std;

int search(vector<int>nums, int low, int high){

        if(low == high)
            return nums[low];
        
        if((high == low+1) && (nums[low] > nums[high]))
            return nums[low];
        
        if((high == low+1) && (nums[low] < nums[high]))
            return nums[high];
        
        int mid = low + (high-low)/2;

        if((nums[mid] > nums[mid+1]) && (nums[mid] > nums[mid-1]))
            return nums[mid];
        
        if((nums[mid] > nums[mid+1]) && (nums[mid] < nums[mid-1]))
            return search(nums, low, mid-1);
        else
            return search(nums, mid+1, high);
        

}

int main(void){
    vector<int> nums = { 1, 3, 50, 10, 9, 7, 6 };
    int size = nums.size();

    cout << " The maximum element is " << search(nums, 0, size-1) << endl;

    return 0;
}