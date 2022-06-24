// Program to to Sort a nearly sorted (or K sorted) array

// Time complexity: O(nlogk)

#include<bits/stdc++.h>
using namespace std;

void kthLargest(vector<int> arr, int n, int k)
{
    int size = (n == k) ? k : k+1;
    priority_queue<int, vector<int>, greater<int>> minh(arr.begin(), arr.begin()+size);   // min_heap

    int index = 0;
    for(int i=k+1; i<n; i++){
        arr[index++] = minh.top();
        minh.pop();
        minh.push(arr[i]);

    }
    while(!minh.empty()){
        arr[index++] = minh.top();
        minh.pop();
    }

    for(auto i:arr)
        cout << i << " ";
    cout << endl;
    
}

int main(){
    vector<int> arr = { 2, 6, 3, 12, 56, 8 };
    int k = 3;
    kthLargest(arr, arr.size(), k);
    return 0;
}