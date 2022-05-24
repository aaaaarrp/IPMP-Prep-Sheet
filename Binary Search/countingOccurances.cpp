// Using Binary Search to find the number of occurances of any element in a sorted array - Time: O(logn)

#include <bits/stdc++.h>
using namespace std;

int leftPosition(vector<int>nums, int l, int r, int key){
    int m;

    while(r-l > 1){
        m = l + (r-l)/2;

        if(nums[m] >= key)
            r = m;
        else
            l = m;
    }

    return r;

}
int rightPosition(vector<int>nums, int l, int r, int key){
    int m;

    while(r-l > 1){
        m = l+(r-l)/2;

        if(nums[m] <= key)
            l = m;
        else
            r = m;
    }

    return l;

}

int main(){
    vector<int> nums = {1,2,3,6,7,7,7,7,7,7,10,13,16,17,17,19};
    int size = nums.size();
    int key = 17;
    int left = leftPosition(nums, -1, size-1, key);
    int right = rightPosition(nums, 0, size, key);

    if(nums[left] == key && key == nums[right])
            cout << (right-left+1) << endl;
    else
        cout << 0 << endl;

}