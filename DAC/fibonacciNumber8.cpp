// Program to print the nth fibonacci number - Time: O(logn) - Space: O(1)
// DP using memoization(Top down approach)

#include<bits/stdc++.h>
using namespace std;
int dp[10];

int fib(int n){

    if(n <= 1)
        return n;
        
    int first, second;

    if(dp[n-1] != -1)
        first = dp[n-1];
    else
        first = fib(n-1);
    
    if(dp[n-2] != -1)
        second = dp[n-2];
    else
        second = fib(n-2);

    return dp[n] = first + second;
}

int main(void){
    int n = 9;
    memset(dp, -1, sizeof(dp));
    cout << fib(n) << endl;
    return 0;
}