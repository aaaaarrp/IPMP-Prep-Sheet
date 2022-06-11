// Program to Print the First Greater Element on the right side for each element

// Using Stack & element order changed
// Time Complexity: O(n) - Auxiliary Space: O(n)

#include<bits/stdc++.h>
using namespace std;

void NGE(vector<int> nums, int n, vector<int> &res){
    stack<int> st;
    st.push(nums[0]);
    for(int i=1; i<n; i++){
        if(st.empty()){
            st.push(nums[i]);
            continue;
        }
        if(!st.empty()){
            while(!st.empty() && st.top() <= nums[i]){
                cout << nums[i] << " -> " << st.top() << endl;
                st.pop();
            }      
        }
        st.push(nums[i]);
    }
    while(!st.empty()){
        cout << st.top() << " -> -1" << endl;
        st.pop();
    }

}

int main(){
    vector<int> nums = {11, 13, 21, 3};
    vector<int> res(nums.size());
    NGE(nums, nums.size(), res);
    return 0;
}