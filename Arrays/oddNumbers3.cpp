
// C++ program to find the element occurring odd number of times


#include<bits/stdc++.h>
using namespace std;

int getOddOccurrence(int a[], int n){       // bitwise XOR - Time Complexity: O(n)

    int res = 0;

    for(int i = 0; i < n; i++){
        res = res ^ a[i];
    }

    return res;
}

int main()
    {
        int arr[] = { 2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2 };
        int n = sizeof(arr) / sizeof(arr[0]);
 
        cout << getOddOccurrence(arr, n);
 
        return 0;
    }