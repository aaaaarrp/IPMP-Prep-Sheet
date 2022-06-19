// Program to Reverse Bits of a Number

// Time: O(logn) - Space: O(1)
// We can reverse bit using LOOKUP TABLE in O(1) time.

#include<bits/stdc++.h>
using namespace std;

unsigned int reverseBits(unsigned int num){
    unsigned int count = sizeof(num)*8-1;
    unsigned int reversed_num = num;

    num >>= 1;
    while(num){
        reversed_num <<= 1;
        reversed_num |= num & 1;
        num >>= 1;
        count--;
    }
    reversed_num <<= count;
    return reversed_num;
}

int main(){
    unsigned int x = 2;
    cout << reverseBits(x) << endl;
    return 0;
}


