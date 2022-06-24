// Program to sort an array of 0s 1s and 2s.

// Using Dutch National Flag problem approach
// Time complexity: O(n) - Auxiliary Space: O(1)

#include<bits/stdc++.h>
using namespace std;

void sort012(vector<int> &arr , int n){
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid <= high){
        switch (arr[mid]){
            case 0:
                swap(arr[low++], arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high--]);
                break;
        }
    }
}

int main()
{
	vector<int> arr = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
	sort012(arr, arr.size());

    for (int num : arr)
        cout << num << " ";
	return 0;
}

