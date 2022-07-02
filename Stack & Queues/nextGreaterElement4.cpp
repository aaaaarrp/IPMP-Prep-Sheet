// Program to Print the First Greater Element on the right side for each element in a circular array

// Usinging Stack & 2*n numbers
// Time Complexity: O(n) - Auxiliary Space: O(n)

#include <bits/stdc++.h>
using namespace std;

vector <int> NGE(vector<int> nums, int n)
{
    stack<int> st;
    vector<int> res(n);

    for(int i=2*n-1; i>=0; i--){
        while(!st.empty() && st.top() <= nums[i%n]){
            st.pop();
        }
        if(i < n){
            if(!st.empty())
                res[i%n] = st.top();
            else
                res[i%n] = -1;
        }
        st.push(nums[i%n]);
    }
    return res;
    
}

int main()
{
    vector<int> nums = {11, 13, 21, 3};
    vector<int> res = NGE(nums, nums.size());
    for(auto i:res)
        cout << i << " ";
    return 0;
}