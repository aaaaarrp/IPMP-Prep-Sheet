// Find the two numbers with odd occurrences in an unsorted array

// Naive method - using two nested loops
// Time: O(n^2)

#include<bits/stdc++.h>
using namespace std;

void getOddOccurrences(vector<int> nums, int n){
    int count=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(nums[i] == nums[j])
                count++;
        }
        if(count % 2 != 0){
            cout << nums[i] << " ";
        }
        count = 0;
            
    }
    cout << endl;
}

int main(){
    vector<int> nums = {4, 2, 5, 2, 3, 3, 1};
    getOddOccurrences(nums, nums.size());

}

