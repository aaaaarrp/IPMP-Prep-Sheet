// Program to sort an array of 0s 1s and 2s.

// simple counting
// Time complexity: O(n) - Auxiliary Space: O(1)

#include<bits/stdc++.h>
using namespace std;

void sort012(vector<int> &arr , int n){
    int count0 = 0, count1 =0, count2 =0;
    for(int i=0; i<n; i++){
        if(arr[i] == 0)
            count0++;
        if(arr[i] == 1)
            count1++;
        if(arr[i] == 2)
            count2++;
    }

    for(int i=0; i<n; i++){
        if(i >= 0 && i < count0)
            arr[i] = 0;
        if(i>= count0 && i < (count0+count1))
            arr[i] = 1;
        if(i >= (count0+count1) && i < n)
            arr[i] = 2;
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

