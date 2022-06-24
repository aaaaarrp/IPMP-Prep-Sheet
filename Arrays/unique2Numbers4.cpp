// Program to find the two non-repeating elements in an array of repeating elements/ Unique Numbers 2 

// Using Sets
// Time Complexity: O(nlogn) - Auxiliary Space: O(n)

#include<bits/stdc++.h>
using namespace std;

void get2NonRepeatingNos(vector<int> nums, int n){
    set<int> s;

    for(int i=0; i<n; i++){
        if(s.find(nums[i]) != s.end())
            s.erase(nums[i]);
        else
            s.insert(nums[i]);
    }

    cout << "The non-repeating elements are: ";

    for(auto i : s)
        cout << i << " ";
    
    cout << endl;
}

int main(){
    vector<int> nums = { 2, 3, 7, 9, 11, 2, 3, 11 };
    get2NonRepeatingNos(nums, nums.size());
}