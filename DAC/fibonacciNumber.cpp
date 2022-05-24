// In fibonacci number, Fn = Fn-1 + Fn-2 where, F0 = 0 and F1 = 1 

// Program to print the nth fibonacci number (Recursion) - Time: O(n) - Space: O(n)

#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n <= 1)
        return n;
    else   
        return fib(n-1) + fib(n-2);
}

int main(void){
    int n = 9;
    cout << fib(n) << endl;
    return 0;
}
