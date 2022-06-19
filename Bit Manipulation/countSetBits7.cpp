// Program to Count set bits in an integer

// Mapping numbers with the bit
// Time Complexity: O(logn) - Space: O(1)

#include<bits/stdc++.h>
using namespace std;

int num_to_bits[16] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 };

unsigned int countSetBits(unsigned int num){
    int nibble = 0;
    if(num == 0)
        return num_to_bits[0];
    
    nibble = num & 0xf;
    return num_to_bits[nibble]+countSetBits(num >> 4);
}

int main(){
    int x = 9;
    cout << countSetBits(x) << endl;
    return 0;
}