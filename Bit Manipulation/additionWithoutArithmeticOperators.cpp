// Program to Add two numbers without using arithmetic operators

// Time Complexity: O(log b) - Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int add(int a, int b){
    while(b){
        unsigned carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}
int main()
{
    cout << add(15, 32) << endl;
    return 0;
}