// Using Binary Search to find a Fixed Point (Value equal to index) in a given array - Time: O(logn)

#include<bits/stdc++.h>
using namespace std;

int fixedPoint(vector<int> nums, int low, int high){
    if(high >= low){
        int mid = low + (high-low)/2;

        if(mid == nums[mid])
            return mid;

        int res = -1;

        if(mid+1 <= high)
            res =  fixedPoint(nums, mid+1, high);
        
        if(res != -1)
            return res;
        
        if(mid-1 >= low)
            return fixedPoint(nums, low, mid-1); 
    }

    return -1;
}

int main(void){
    vector<int> nums = { -10, -1, 1, 3, 10, 11, 30, 50, 100 };
    int n = nums.size();
    cout << "Fixed point is " << fixedPoint(nums, 0, n-1) << endl; 

    return 0;

}