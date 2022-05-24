// Using Binary Search to check if a given element is majority element (appearing more than size/2 times)

#include<bits/stdc++.h>
using namespace std;

int leftPosition(vector<int>nums, int low, int high, int key){
    int mid;
    
    while(high-low > 1){
        mid = low + (high-low)/2;
    if(nums[mid] >= key)
        high = mid;
    else
        low = mid;
    }

    return high;
}

int rightPosition(vector<int>nums, int low, int high, int key)
{
    int mid;

    while(high-low > 1){
        mid = low + (high-low)/2;

        if(nums[mid] <= key)
            low = mid;
        else
            high = mid;
        
    }

    return low;
}

int main(){
    vector<int> nums = {1, 2, 3, 3, 3, 3, 10};
    int size = nums.size();
    int key = 3;
    int left = leftPosition(nums, -1, size-1, key);
    int right = rightPosition(nums, 0, size, key);

    if(nums[left] == key && key == nums[right]){
            if((right-left+1) > size/2)
                cout << "True! A majority element, occurring " << right-left+1 << " times." << endl;
            else
                cout << "False! Not a majority element" << endl;
    }


}