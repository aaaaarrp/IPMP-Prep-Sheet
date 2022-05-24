// Binary search with lesser comparisons

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

    if(A[l] == key)
        return A[l];
    if(A[r] == key)
        return A[r];
    else
        return -1;   // Element not in the array        
}

int main(){
    vector<int> nums = { 2, 3, 5, 6, 8, 9, 10};
    int key = 2;
    int l = 0;
    int r = nums.size();
    
    cout << binarySearch(nums,l,r,key) << endl;
    
}