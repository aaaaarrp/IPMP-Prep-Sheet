// Program to Move all zeroes to end of array

// Stable Partition with lambda expression
// Time Complexity: O(n) - Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;

void push_zeros_to_end(vector<int>& arr)
{
    stable_partition(arr.begin(), arr.end(), [](int n) { return n != 0; });
}

int main(){
    vector<int> arr{1,9,8,4,0,0,2,7,0,6,0,9};

    push_zeros_to_end(arr);

    for(auto i : arr)
        cout << i << ' ';
    cout << endl;

    return 0;
}
