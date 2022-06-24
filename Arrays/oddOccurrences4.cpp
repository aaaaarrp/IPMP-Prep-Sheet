// Find the two numbers with odd occurrences in an unsorted array

// Using set
// Time: O(n) - Space: O(n)

#include<bits/stdc++.h>
using namespace std;

void getOddOccurrences(vector<int> nums, int n){
    set<int> odd;

    for(int i=0; i<n; i++){
        if(odd.find(nums[i]) != odd.end())
            odd.erase(nums[i]);
        else
            odd.insert(nums[i]);
    }
    cout << "Two odd number of times occurring elements are: ";
    for(auto i:odd)
        cout << i << " ";
    cout << endl;
}

int main(){
    vector<int> nums = {4, 2, 4, 5, 2, 3, 3, 1};
    getOddOccurrences(nums, nums.size());
}