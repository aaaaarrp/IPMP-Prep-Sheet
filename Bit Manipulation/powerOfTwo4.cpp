// Program to find whether a given number is power of 2

// All power of two numbers has only a one-bit set.
// So count the no. of set bits and if we get 1 then the number is a power of 2.

// Time: O(logn)
// Counting of set bits can be done in O(1) time.

#include<bits/stdc++.h>
using namespace std;

int countSetBits(int num){

    if(num == 0)
        return 0;
    else 
        return 1 + countSetBits(num & (num-1));

}

int main() {
    (countSetBits(31) == 1) ? cout << "Yes" << endl : cout << "No" << endl;
    (countSetBits(64) == 1) ? cout << "Yes" << endl : cout << "No" << endl;
}