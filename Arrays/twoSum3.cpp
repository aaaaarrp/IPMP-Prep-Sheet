

// This C++ program tells if there exists a pair in array whose sum results in x.
// hashing - O(n)

#include <bits/stdc++.h>
using namespace std;

void printPair(int A[], int n, int sum){
    unordered_set<int> s;

    for(int i=0; i<n; i++){
        int temp = sum - A[i];
        if(s.find(temp) != s.end())
            cout << "Pair exits with given sum is " << temp << " & " << A[i] << endl;
        s.insert(A[i]);
    }
    
}

int main(void) {
    int A[] = {0, -5, 2, -3, 1};
    int sum = 1;
    int size = sizeof(A) / sizeof(A[0]);
 
    printPair(A, size, sum);
    
 
    return 0;
}