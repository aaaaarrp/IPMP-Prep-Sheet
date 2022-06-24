// Program to rotate an array by d elements

// Block swap algorithm
// Time: O(n) - Space: O(1)

#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> arr, int start, int end, int d){
   int temp;
   for(int i = 0; i < d; i++){
      temp = arr[start + i];
      arr[start + i] = arr[end + i];
      arr[end + i] = temp;
   }
}

void Rotate(vector<int> &arr, int d, int n){
    int i, j;
    if (d == 0 || d == n)
        return;

    if(d > n)
    d = d % n;
   
    i = d;
    j = n - d;
    while (i != j)
    {
        if (i < j)
        {
            swap(arr, d - i, d + j - i, i);
            j -= i;
        }
        else
        {
            swap(arr, d - i, d, j);
            i -= j;
        }
    }

    swap(arr, d - i, d, i);
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
