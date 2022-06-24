// Find the two numbers with odd occurrences in an unsorted array

// Using map
// Time: O(n) - Space: O(n)

#include<bits/stdc++.h>
using namespace std;

void getOddOccurrences(vector<int> nums, int n){
    map<int, int> hash;

    for(int i=0; i<n; i++){
        hash[nums[i]]++;
    }

    cout << "Odd elements are: ";
    for(auto i:hash){
        if(i.second % 2 != 0)
            cout << i.first << " ";
    }

    cout << endl;
}

int main(){
    vector<int> nums = {4, 2, 4, 5, 2, 3, 3, 1};
    getOddOccurrences(nums, nums.size());
}