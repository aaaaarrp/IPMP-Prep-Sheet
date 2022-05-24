
// https://www.geeksforgeeks.org/two-elements-whose-sum-is-closest-to-zero/
// STL implementation of Method 2(Sorting) - O(nlogn)

#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b){
    return abs(a) < abs(b);
}

void findMinSum(int A[], int size) {
    sort(A, A+size, compare);
    int min = INT_MAX, x, y;

    for(int i=0; i < size-1; i++){
        if(abs(A[i] + A[i+1]) <= min){
            min = abs(A[i] + A[i+1]);
            x = i;
            y = i+1;
        }
    }

    cout << "The two elements whose sum is minimum are " << A[x] << " & " << A[y] << endl;
    
}

int main() {
 
    int arr[] = { 1, 60, -10, 70, -80, 85 };
    int n = sizeof(arr) / sizeof(arr[0]);
    findMinSum(arr, n);
    return 0;

}