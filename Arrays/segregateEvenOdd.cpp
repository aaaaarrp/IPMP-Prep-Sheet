// Program to Segregate Even and Odd numbers

// Using two pointers
// Time Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

void segregateEvenOdd(vector<int>& arr, int n){
    int left = 0, right = n-1;

    while(left < right){
        while(arr[left] % 2 == 0 && left < right)
            left++;
        while(arr[right] % 2 != 0 && left < right)
            right--;
        
        if(left < right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }

    }
}

int main()
{
    vector<int> arr = {12, 34, 45, 9, 8, 90, 3};
    int i = 0;
 
    segregateEvenOdd(arr, arr.size());
 
    cout <<"Array after segregation ";
    for (i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
 
    return 0;
}