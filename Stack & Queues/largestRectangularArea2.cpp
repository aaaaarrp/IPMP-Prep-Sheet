// Program to Find the largest rectangular area possible in a given histogram

// Time: O(n) - Space: O(n)

#include<bits/stdc++.h>
using namespace std;

int getMaxArea(vector<int> hist, int n){

    stack<int> st;
    st.push(-1);

    int area = hist[0];
    int i = 0;
    
    vector<int> left_smaller(n, -1);
    vector<int> right_smaller(n, n);

    while(i<n){
        while(!st.empty() && st.top() != -1 && hist[st.top()] > hist[i]){
            right_smaller[st.top()] = i;
            st.pop();
        }
        if(i>0 && hist[i] == hist[i-1]){
            left_smaller[i] = left_smaller[i-1];
        }
        else {
            left_smaller[i] = st.top();
        }
        st.push(i++);
    }

    for(int j=0; j<n; j++)
        area = max(area, hist[j]*(right_smaller[j]-left_smaller[j]-1));

    return area;

}

int main()
{
    vector<int> hist = {6, 2, 5, 4, 5, 1, 6};
    cout << "Maximum area is " << getMaxArea(hist, hist.size()) << endl;
    return 0;
}