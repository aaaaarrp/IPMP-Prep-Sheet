// Program to swap two nibbles in a byte
// For 8 bit

#include <bits/stdc++.h>
using namespace std;

unsigned int nibbleSwap(unsigned int x)
{
    return ((x >> 4) & 0x0F0F0F0F) | ((x & 0x0F0F0F0F) << 4);

}

int main()
{
    int a = 64;
    
    cout << nibbleSwap(a) << endl;

    
    return 0;
}


// 64 = 1000 0000
// 4 = 0000 1000
