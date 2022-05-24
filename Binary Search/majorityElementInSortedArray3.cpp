// Using DAC paradigm to check for majority element in a sorted array - Time: O(1)
// Improved version from bianry Search

#include<bits/stdc++.h>
using namespace std;

bool isMajorityElement(vector<int> nums, int size, int key){

    if(nums[size/2] == key)
        return true;
    else
        return false;
}

int main()
{
    vector<int> nums = { 1, 2, 3, 3, 3, 3, 10 };
    int size = nums.size();
    int x = 2;
    if (isMajorityElement(nums, size, x))
        cout << x << " appears more than "
             << size / 2 << "times in array."
             << endl;
    else
        cout << x << " does not appear more than "
             << size / 2 << "  times in array." << endl;
   
    return 0;
}