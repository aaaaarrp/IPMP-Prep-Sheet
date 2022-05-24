
// Find a sorted subsequence of size 3 in linear time - 3 terms traversing : O(n)

#include <bits/stdc++.h>
using namespace std;

void find3Numbers(vector<int>& nums){
    if(nums.size() < 3){
        cout << "No such triplet found" << endl;
        return;
    }

    //int seq = 1;
    int min_num = nums[0];
    int max_seq = INT_MAX;
    int store_min = min_num;

    for(int i=1; i < nums.size(); i++){
        if(nums[i] == min_num)
            continue;
        else if(nums[i] < min_num){
            min_num = nums[i];
            continue;
        }
        else if(nums[i] < max_seq){
            max_seq = nums[i];
            store_min = min_num;
        }
        else if(nums[i] > max_seq){
            cout << "Triplet: " << store_min << ", " << max_seq << ", " << nums[i] << endl;
            return;
        }
    }

    cout << "No such triplet found" << endl;
    
}

int main(){
    vector<int> nums {1,2,-1,7,5};
    find3Numbers(nums);
}