// Program to Turn off the rightmost set bit

// Time Complexity: O(1) - Auxiliary Space: O(1)

#include<bits/stdc++.h>
using namespace std;

int fun(int n){
    return n & (n-1);
}

int main(){
    int n = 7;
    cout<<"The number after unsetting the";
    cout<<" rightmost set bit: "<<fun(n) << endl;
    return 0;
}