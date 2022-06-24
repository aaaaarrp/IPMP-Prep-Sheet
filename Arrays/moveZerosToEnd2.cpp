// Program to Move all zeroes to end of array

/*  We will use 0 as a pivot element -
    whenever we see a non zero element,
    we will swap it with the pivot element.
    So all the non zero element will come at the beginning.
*/

// Time Complexity: O(n) - Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;

void push_zeros_to_end(vector<int>& arr, int n){
    int j = 0;
    for(int i=0; i<n; i++){
        if(arr[i] != 0){
            swap(arr[j], arr[i]);
            j++;
        }
    }
}

int main(){
    vector<int> arr{1,9,8,4,0,0,2,7,0,6,0,9};

    push_zeros_to_end(arr, arr.size());

    for(auto i : arr)
        cout << i << ' ';
    cout << endl;

    return 0;
}
