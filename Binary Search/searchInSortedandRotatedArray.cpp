// Using Binary Search to search for an element in a sorted and rotated array

#include<bits/stdc++.h>
using namespace std;

int search(vector<int>nums, int low, int high, int key){

    if(low > high)
        return -1;
    int mid = low+(high-low)/2;

    if(nums[mid] == key)
        return mid;
    
    if(nums[low] <= nums[mid]){
        if(nums[low] <= key && key <= nums[mid])
            return search(nums, low, mid-1, key);
        return search(nums, mid+1, high, key);
    }

    if(key >=nums[mid+1] && key <= nums[high])
        return search(nums, mid+1, high, key);
    return search(nums, low, mid-1, key);

}

int main(){
    vector<int> nums = {5,6,7,8,1,2};
    int size = nums.size();
    int key = 12;
    int i = search(nums, 0, size-1, key);

    if( i != -1)
        cout << "At index " << i << endl;
    else
        cout << "Key not found" << endl;
}