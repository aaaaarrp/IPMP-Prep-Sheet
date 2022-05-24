
// This C++ program tells if there exists a pair in array whose sum results in x.
// Sorting and Two-Pointers technique - depends on sorting

#include <bits/stdc++.h>
using namespace std;

bool checkPairs(int A[], int n, int sum){
    
    sort(A, A+n);
    int left = 0;
    int right = n-1;
    while(left < right){
        if(A[left] + A[right] == sum)
            return 1;
        else if(A[left] + A[right] < sum)
            left++;
        else
            right--;
    }
    return 0;
}

int main(void) {
    int A[] = {0, -1, 2, -3, 1};
    int sum = -9;
    int size = sizeof(A) / sizeof(A[0]);
 
    if (checkPairs(A, size, sum)) {
        cout << "Valid pair exists!" << endl;
    }
    else {
        cout << "No valid pair exists for " << sum << endl;
    }
 
    return 0;
}