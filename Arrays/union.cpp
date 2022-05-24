
// C++ program to find union of two sorted arrays


#include <bits/stdc++.h>        // Time Complexity : O(m + n)
using namespace std;

void printUnion(int a1[], int a2[], int m, int n){
    int i = 0, j = 0;

    while(i < m && i < n){
        if(a1[i] < a2[j]){
            cout << a1[i++] << " ";
        }
        else if(a1[i] > a2[j]){
            cout << a2[j++] << " ";
            j++;
        }
        else{
            cout << a1[i++] << " ";
            j++;
        }

    }

    while( i < m)
        cout << a1[i++] << " ";
    while(j < n)
        cout << a2[j++] << " ";
}

int main()
{
    int arr1[] = { 1, 2, 4, 5, 6 };
    int arr2[] = { 2, 3, 5, 7 };
 
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
 
    // Function calling
    printUnion(arr1, arr2, m, n);
 
    return 0;
}