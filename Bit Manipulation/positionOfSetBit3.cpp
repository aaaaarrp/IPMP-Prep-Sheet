// Program to Find position of the only set bit

// Time Complexity: O(log2n) - Space Complexity: O(log2n)

#include <bits/stdc++.h>
using namespace std;

int isPowerOfTwo(unsigned int n){
    return n && (!(n & (n-1)));
}

unsigned int log2n(unsigned int n){
    return (n > 1) ? 1 + log2n(n/2) : 0;
}

int findPosition(unsigned int n){
    if(!isPowerOfTwo(n))
        return -1;

    return log2n(n)+1;
}

int main(void)
{
    int n = 16;
    int pos = findPosition(n);
    (pos == -1) ? cout << "n = " << n << ", Invalid number" << endl : cout << "n = " << n << ", Position " << pos << endl;
 
    n = 12;
    pos = findPosition(n);
    (pos == -1) ? cout << "n = " << n << ", Invalid number" << endl : cout << "n = " << n << ", Position " << pos << endl;
 
    n = 128;
    pos = findPosition(n);
    (pos == -1) ? cout << "n = " << n << ", Invalid number" << endl : cout << "n = " << n << ", Position " << pos << endl;
 
    return 0;
}