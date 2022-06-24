// Program to Segregate Even and Odd numbers

//  Lomuto partition based
// Time Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

void segregateEvenOdd(vector<int>& arr, int n){
    int j = -1;
    for(int i=0; i<n; i++){
        if(arr[i] % 2 == 0){
            j++;
            swap(arr[i], arr[j]);
        }
    }
}

int main()
{
    vector<int> arr = { 12, 10, 9, 45, 2, 10, 10, 45 };
    int i = 0;
 
    segregateEvenOdd(arr, arr.size());
 
    cout <<"Array after segregation ";
    for (i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
 
    return 0;
}