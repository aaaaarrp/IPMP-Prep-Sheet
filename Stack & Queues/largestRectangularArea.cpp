// Program to Find the largest rectangular area possible in a given histogram

// Time: O(n) 

#include<bits/stdc++.h>
using namespace std;

int getMaxArea(vector<int> hist, int n){
    stack<int> st;
    int max_area = 0;
    int top;
    int area_with_top;
    int i=0;
    
    while(i<n){

        if(st.empty() || hist[st.top()] <= hist[i])
            st.push(i++);

        else {
            top = st.top();
            st.pop();
            area_with_top = hist[top] * (st.empty() ? i : i-st.top()-1);

            if(max_area < area_with_top)
                max_area = area_with_top;
        }
    }
    while(st.empty()){
        top = st.top();
        st.pop();
        area_with_top = hist[top] * (st.empty() ? i : i-st.top()-1);

        if(max_area < area_with_top)
            max_area = area_with_top;
    }

    return max_area;
}

int main()
{
    vector<int> hist = {6, 2, 5, 4, 5, 1, 6};
    cout << "Maximum area is " << getMaxArea(hist, hist.size()) << endl;
    return 0;
}