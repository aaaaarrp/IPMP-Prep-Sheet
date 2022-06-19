// Program to Swap all odd and even bits

// Time Complexity: O(constant) - Auxiliary Space: O(1)
#include <bits/stdc++.h>
using namespace std;

unsigned int swapBits(unsigned int n){
    for(int i=0; i<32; i+=2){
        int i_bit = (n >> i) & 1;
        int i1_bit = (n >> (i+1)) & 1;
        n = n - (i_bit << i)
                - (i1_bit << (i+1)) 
                + (i_bit << (i+1)) 
                + (i1_bit << i);
    }
    return n;
}

int main()
{
    unsigned int x =23; // 00010111
 
    // Output is 43 (00101011)
    cout << swapBits(x) << endl;
 
    return 0;
}