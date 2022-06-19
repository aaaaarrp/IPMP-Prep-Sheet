// Program to Compute the integer absolute value (abs) without branching

/*  mask = n >> charBit
    return ((mask+n)^mask)
*/

// Time Complexity: O(1) - Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;
#define CHARBIT 8

int getAbs(int n){
    int const mask = n >> (sizeof(int)*(CHARBIT-1));
    return ((mask+n)^mask);
}

int main()
{
    int n = -6;
    cout << "Absolute value of " << n << " is " << getAbs(n);
    return 0;
}