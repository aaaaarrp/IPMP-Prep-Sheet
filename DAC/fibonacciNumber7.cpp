// Program to print the nth fibonacci number - Time: O(logn) - Space: O(1)
// Fn = round({[(√5 + 1)/2] ^ n} / √5)

#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    double phi = (1+sqrt(5))/2;
    return round(pow(phi, n)/sqrt(5));
}

int main(void){
    int n = 9;
    cout << fib(n) << endl;
    return 0;
}