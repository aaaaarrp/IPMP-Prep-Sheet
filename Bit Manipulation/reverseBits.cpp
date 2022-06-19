// Program to Reverse Bits of a Number

// Time: O(logn) - Space: O(1)
// We can reverse bit using LOOKUP TABLE in O(1) time.

#include<bits/stdc++.h>
using namespace std;

unsigned int reverseBits(unsigned int num){
    unsigned int NO_OF_BITS = sizeof(num)*8;
    unsigned int reversed_num = 0;
    for(int i=0; i<NO_OF_BITS; i++){
        if((num &(1 << i)))
            reversed_num |= 1 << ((NO_OF_BITS-1)-i);
    }
    return reversed_num;
}

int main(){
    unsigned int x = 2;
    cout << reverseBits(x) << endl;
    return 0;
}