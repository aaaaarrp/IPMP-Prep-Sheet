// Program to find whether a given number is power of 2

// Bitwise & of num and num-1
// Time: O(1) - Space: O(1)

#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int num){
    return num && (!(num & (num-1)));
}

int main() {
    isPowerOfTwo(31) ? cout << "Yes" << endl : cout << "No" << endl;
    isPowerOfTwo(64) ? cout << "Yes" << endl : cout << "No" << endl;
}