// Program to Print the elements greater than all the elements to its right

// Output is not in order
// Time: O(n^2) - Space: O(1)

#include<bits/stdc++.h>
using namespace std;

void printLeaders(vector<int> arr, int n){
    int max = arr[n-1];
    cout << max << " ";
    for(int i = n-2; i >= 0; i--){
        if(arr[i] > max){
            max = arr[i];
            cout << max << " ";
        }
    }
}

int main(){
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    printLeaders(arr, arr.size());
    return 0;
}