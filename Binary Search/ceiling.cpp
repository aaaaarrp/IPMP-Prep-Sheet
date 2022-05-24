// Using Binary Search to find the ceiling of any element in a sorted array

#include<bits/stdc++.h>
using namespace std;


int binarySearch(vector<int> A, int l, int r, int key){

    int m;
    while(r-l > 1){
        m = l + (r-l)/2;
        if(A[m] <= key)
            l = m;
        else
            r = m;
    }

    return A[r];        
}

int main(){
    vector<int> nums = { 2, 3, 5, 6, 8, 9, 10};
    int key = 2;
    int l = -1;
    int r = nums.size();
    if(key >= nums[r-1])
        cout << "Ceiling doesn't exist." << endl;
    else
        cout << binarySearch(nums,l,r,key) << endl;
    
}