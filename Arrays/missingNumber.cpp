
// C++ program to find the Find the Missing Number

#include<bits/stdc++.h>
using namespace std;

int getMissingNo(int a[], int n){       // summation formula - Time Complexity: O(n)
                                        // This causes overflow if the sum goes large (solution in gfg)
    int sum = ((n+1)*(n+2))/2;

    for(int i = 0; i < n; i++){
        sum -= a[i];
    }

    return sum;
}

int main()
{
    int arr[] = { 1, 2, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int miss = getMissingNo(arr, n);
    cout << miss;
}