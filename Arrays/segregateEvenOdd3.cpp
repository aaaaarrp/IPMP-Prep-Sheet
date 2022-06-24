// Program to Segregate Even and Odd numbers

// Stable Partition with lambda expression
// Time Complexity: O(n)/O(nlogn)

#include<bits/stdc++.h>
using namespace std;

void segregateEvenOdd(vector<int> arr){
    stable_partition(arr.begin(), arr.end(), [](int n) { return n % 2 == 0; });
    for (int num : arr)
        cout << num << " ";
}

int main(){
    vector<int> arr = { 12, 10, 9, 45, 2, 10, 10, 45 };
 
    segregateEvenOdd(arr);
    return 0;
}