// Program to find the Kth smallest element in an array

// Time complexity: O(nlogk)

#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int> arr, int n, int k)
{
    priority_queue<int> maxh;   // max_heap
    for(int i=0; i<n; i++){
        maxh.push(arr[i]);
        if(maxh.size() > k)
            maxh.pop();
    }
    return maxh.top();
}

int main(){
    vector<int> arr = {4,10,7,20,13,6};
    int k = 3;
    cout << kthSmallest(arr, arr.size(), k) << endl;
    return 0;
}