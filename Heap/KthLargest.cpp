// Program to find the Kth largest element in an array

// Time complexity: O(nlogk)

#include<bits/stdc++.h>
using namespace std;

int kthLargest(vector<int> arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> minh;    // min_heap
    for(int i=0; i<n; i++){
        minh.push(arr[i]);
        if(minh.size() > 3)
            minh.pop();
    }
    return minh.top();
}

int main(){
    vector<int> arr = {4,10,7,20,13,6,11,23,12};
    int k = 3;
    cout << kthLargest(arr, arr.size(), k) << endl;
    return 0;
}