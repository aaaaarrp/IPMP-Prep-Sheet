// Program to print the nth fibonacci number (DP) - Time: O(n) - Space: O(n)
// Avoiding the repeated work done in recursion method

#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    int f[n+2];
    int i;

    f[0] = 0;
    f[1] = 1;

    for(int i=2; i <= n; i++){
        f[i] = f[i-1]+f[i-2];
    }

    return f[n];
}

int main(void){
    int n = 9;
    cout << fib(n) << endl;
    return 0;
}