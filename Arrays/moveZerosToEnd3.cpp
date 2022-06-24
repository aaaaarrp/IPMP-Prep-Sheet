// Program to Move all zeroes to end of array

/*  We will count no of zeroes
    while counting we'll delete the zeroes,
    which results in shifting the non-zero elements left.
    we will push those 0s later after counting.
*/

// Time Complexity: O(n) - Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;

void push_zeros_to_end(vector<int>& arr, int n){
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            count++;
            arr.erase(arr.begin()+i);
            i--;
        }
    }
    for(int i=0; i<count; i++)
        arr.push_back(0);
}

int main(){
    vector<int> arr{1,9,8,4,0,0,2,7,0,6,0,9};

    push_zeros_to_end(arr, arr.size());

    for(auto i : arr)
        cout << i << ' ';
    cout << endl;

    return 0;
}
