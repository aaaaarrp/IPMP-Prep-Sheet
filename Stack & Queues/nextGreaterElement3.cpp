// Program to Print the First Greater Element on the right side for each element

// Using Stack & element order not changed
// Time Complexity: O(n) - Auxiliary Space: O(n)

#include<bits/stdc++.h>
using namespace std;

void NGE(vector<int> nums, int n, vector<int> &res){
    stack<int> st;
    for(int i = n-1; i >= 0; i--){
        if(!st.empty()){
            while(!st.empty() && st.top() <= nums[i])
                st.pop();
        }
        if(st.empty())
            res[i] = -1;
        else
            res[i] = st.top();
        st.push(nums[i]);
    }
    for(int i=0; i<n; i++)
        cout << nums[i] << " -> " << res[i] << endl;
}

int main(){
    vector<int> nums = {11, 13, 21, 3};
    vector<int> res(nums.size());
    NGE(nums, nums.size(), res);
    return 0;
}