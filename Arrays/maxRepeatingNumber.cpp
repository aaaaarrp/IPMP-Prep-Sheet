// Program to Find the maximum repeating number

// Time: O(n) - Space: O(k)

#include<bits/stdc++.h>
using namespace std;

int maxRepeating(vector<int> &arr, int n, int k){
    vector<int> temp(k, 0);
    for(int i=0; i<n; i++){
        temp[arr[i]]++;
    }
    return *max_element(temp.begin(), temp.end());
}

int main()
{
    vector<int> arr = {2, 3, 3, 5, 3, 4, 1, 7};
    int k = 8;
    cout << "The maximum repeating number is " << maxRepeating(arr, arr.size(), k) << endl;
 
    return 0;
}