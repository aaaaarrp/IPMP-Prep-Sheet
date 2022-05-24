// Using Binary Search to check if a given element is majority element (appearing more than size/2 times)

#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> nums, int low, int high, int key){

    if(high >= low){
        int mid = low + (high-low)/2;

        if(mid == 0 || key > nums[mid-1] && nums[mid] == key)
            return mid;
        else if(key > nums[mid])
            return binarySearch(nums, mid+1, high, key);
        else
            return binarySearch(nums, low, mid-1, key);
    }

    return -1;
}

bool isMajority(vector<int> nums, int size, int key){

    int i = binarySearch(nums, 0, size-1, key);

    if(i == -1)
        return false;
    
    if((i+size/2) <= (size-1) && nums[(i+size/2)] == key)
        return true;
    else 
        return false; 
}

int main(){
    vector<int> nums = { 1, 2, 3, 3, 3, 3, 10 };
    int size = nums.size();
    int x = 3;

    if(isMajority(nums, size, x))
        cout << x << " appears more than " << size/2 << " times in the array." << endl;
    else
        cout << x << "doesn't appear more than " << size/2 << " times in the array." << endl;

}