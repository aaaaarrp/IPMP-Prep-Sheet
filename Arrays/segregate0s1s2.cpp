// PRogram to Segregate 0s and 1s in an array

// Using two pointers
// Time complexity: O(n) - Auxiliary Space: O(1)

#include<bits/stdc++.h>
using namespace std;

void segregate0s1s(vector<int> &arr, int n){
    int left = 0, right = n-1;

    while(left < right){
        while(arr[left] == 0 && left < right)
            left++;
        while(arr[right] == 1 && left < right)
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
    vector<int> arr = {1, 0, 1, 0, 1, 1, 0, 0, 0};
    int i = 0;
 
    segregate0s1s(arr, arr.size());
 
    cout <<"Array after segregation ";
    for (i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
 
    return 0;
}