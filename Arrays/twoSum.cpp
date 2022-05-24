// This C++ program tells if there exists a pair in array whose sum results in x.
//Brute force - O(n^2)

#include <bits/stdc++.h>
using namespace std;

bool checkPair(int A[], int n, int x){
    for(int i=0; i < (n-1); i++){
        for(int j=(i+1); j < n; j++){
            if(A[i]+A[j] == x){
                cout << "Pair with the given sum " << x << " is " << A[i] << " & " << A[j] << endl;
                return 1;
            }
        }
    }
    return 0;
}

int main(void) {
    int A[] = {0, -1, 2, -3, 1};
    int sum = -2;
    int size = sizeof(A) / sizeof(A[0]);
 
    if (checkPair(A, size, sum)) {
        cout << "Valid pair exists!" << endl;
    }
    else {
        cout << "No valid pair exists for " << sum << endl;
    }
 
    return 0;
}