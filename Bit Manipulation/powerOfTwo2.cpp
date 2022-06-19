// Program to find whether a given number is power of 2

// Dividing the number by two, i.e, do n = n/2 iteratively. In any iteration,
// if n%2 becomes non-zero and n is not 1 then n is not a power of 2.
// If n becomes 1 then it is a power of 2. 

// Time: O(log2n) - Space: O(1)

#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int num){
    if(num == 0)
        return 0;
    while(num != 1){
        if(num % 2 != 0)
            return 0;
        num = num/2;
    }
    return 1;
}

int main() {
    isPowerOfTwo(31) ? cout << "Yes" << endl : cout << "No" << endl;
    isPowerOfTwo(64) ? cout << "Yes" << endl : cout << "No" << endl;
}
