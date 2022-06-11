// The Stock Span Problem

// Linear time complexity solution using stack
// Time: O(n) - Space: O(n)

#include<bits/stdc++.h>
using namespace std;

void calculateSpan(vector<int> price, int n, vector<int> &span){
    stack<int> st;
    st.push(0);
    span[0] = 1;
    for(int i=1; i<n; i++){
        while(!st.empty() && price[st.top()] <= price[i])
            st.pop();
        if(st.empty())
            span[i] = i+1;
        else
            span[i] = i-st.top();
        st.push(i);
    }
    for(int i=0; i<n; i++)
        cout << span[i] << " ";
    cout << endl;
}

int main(){
    vector<int> price = { 10, 4, 5, 90, 120, 80 };
    vector<int> span(price.size());
    calculateSpan(price, price.size(), span);
    return 0;
}