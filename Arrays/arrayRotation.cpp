// Program to rotate an array by d elements

// Time: O(n*d) - Space: O(1)

#include <bits/stdc++.h>
using namespace std;

void Rotate(vector<int> &arr, int d, int n){
    int times = 1;
    while(times <= d){
        int last = arr[0];
        for(int i=0; i<n-1; i++)
            arr[i] = arr[i+1];
        arr[n-1] = last;
        times++;
    }
}

int main()
{
	vector<int> arr = { 1, 2, 3, 4, 5, 6, 7 };
    int d = 2;
    Rotate(arr, d, arr.size());

    for(auto &it:arr)
        cout << it << " ";
    cout << endl;

	return 0;
}
