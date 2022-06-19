// Program to swap values without using extra space

// Time Complexity: O(1) - Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 6;
    int b = 5;
    (((a) ^ (b)) && ((b) ^= (a) ^= (b), (a) ^= (b)));
    cout << a << " " << b << endl;
    return 0;
}