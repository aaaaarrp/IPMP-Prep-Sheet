// Program to Swap all odd and even bits

// Time Complexity: O(1) - Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;

unsigned int swapBits(unsigned int n){
    unsigned int even_bits = n & 0xAAAAAAAA;
    unsigned int odd_bits = n & 0x55555555;
    even_bits >>= 1;
    odd_bits <<= 1;
    return (even_bits | odd_bits);
}

int main()
{
    unsigned int x =23; // 00010111
 
    // Output is 43 (00101011)
    cout << swapBits(x) << endl;
 
    return 0;
}