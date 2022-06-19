// Program to Add two numbers without using arithmetic operators

// Recursive approach
// Time Complexity: O(log b) - Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int add(int a, int b){
    if(b == 0)
        return a;
    else    
        return add((a ^ b), unsigned ((a&b) << 1));
}
int main()
{
    cout << add(15, 32) << endl;
    return 0;
}