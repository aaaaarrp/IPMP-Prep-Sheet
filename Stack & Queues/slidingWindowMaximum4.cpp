// Program to find the maximum for each and every contiguous subarray of size k, Given an array and an integer K.

// By modifying queue implementation of two stack
// Time Complexity: O(N) - Space Complexity: O(K)

#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    int maximum;
};

void insertion(stack<node> &s2, int val){
    node st;
    st.data = val;

    if(s2.empty())
        st.maximum = val;
    else{
        node front = s2.top();
        st.maximum = max(val, front.maximum);
    }
    s2.push(st);
    return;
}

void deletion(stack<node> &s1, stack<node> &s2){
    if(s1.size())
        s1.pop();
    else {
        while(!s2.empty()){
            node val = s2.top();
            insertion(s1, val.data);
            s2.pop();
        }
        s1.pop();
    }
}

int get_max(stack<node> &s1, stack<node> &s2){
    int ans = -1;
    if(s1.size())
        ans = max(ans, s1.top().maximum);
    if(s2.size())
        ans = max(ans, s2.top().maximum);
    return ans;
}

vector<int> printKMax(int arr[], int n, int k){
    vector<int> res;
    stack<node> s1, s2;

    for(int i=0; i<k-1; i++)
        insertion(s2, arr[i]);
    
    for(int i=0; i<=n-k; i++){
        if(i-k >= 0)
            deletion(s1,s2);
        insertion(s2, arr[i+k-1]);
        res.push_back(get_max(s1, s2));
    }
    return res;
}

int main()
{
    int arr[] = { 8, 5, 10, 7, 9, 4, 15, 12, 90, 13 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    vector<int> result = printKMax(arr, n, k);
    for(auto i:result)
        cout << i << " ";
    return 0;
}