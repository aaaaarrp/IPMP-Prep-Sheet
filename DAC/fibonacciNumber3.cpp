// Program to print the nth fibonacci number - Time: O(n) - Space: O(1)
// Optimizing the space used in method 2 by storing the previous two numbers only because that is all we need to get the next Fibonacci number in series. 

#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    int a=0, b=1, c;
    if(n == 0)
        return a;
    for(int i=2; i<=n; i++){
        c = a+b;
        a = b;
        b = c;
    }
    return b;
}

int main(){
    int n = 10;
    cout << fib(n) <<endl;
    return 0;
}