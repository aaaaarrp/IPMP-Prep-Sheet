
// C++ program to find intersection of two sorted arrays


#include <bits/stdc++.h>        // Time Complexity : O(m + n)
#include <sys/time.h>
#include <sys/resource.h>
using namespace std;

void printIntersection(int a1[], int a2[], int m, int n){
    int i = 0, j = 0;
    while(i < m && j < n){
        if(a1[i] < a2[j])
            i++;
        else if(a1[i] > a2[j])
            j++;
        else{
            cout << a2[j] << " ";
            i++;
            j++;
        }
    }
}

int main()
{
    int arr1[] = { 1, 2, 4, 5, 6 };
    int arr2[] = { 2, 3, 5, 7 };
 
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
 
    // Function calling
    printIntersection(arr1, arr2, m, n);

    int getrusage(int who, struct rusage *usage);
    cout << sizeof(arr1);
 
    return 0;
}