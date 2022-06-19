// Program to find whether a given number is power of 2

// Using the logic to find the rightmost bit set of a given number
// Time: O(1) - Space: O(1)

#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int num){
    if(num == 0)
        return 0;
    if((num & ~(num-1)) == num)
        return 1;
    return 0;
}

int main() {
    isPowerOfTwo(31) ? cout << "Yes" << endl : cout << "No" << endl;
    isPowerOfTwo(64) ? cout << "Yes" << endl : cout << "No" << endl;
}