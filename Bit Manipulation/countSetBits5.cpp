// Program to Count set bits in an integer

// Using LookUp table
// Time Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

int BitSetTable256[256];

void initialize(){
    BitSetTable256[0] = 0;
    for(int i=0; i<256; i++){
        BitSetTable256[i] = (i & 1) + BitSetTable256[i/2];
    }
}

int countSetBits(int num){
    return (BitSetTable256[num & 0xff]+
            BitSetTable256[(num >> 8) & 0xff]+
            BitSetTable256[(num >> 16) & 0xff]+
            BitSetTable256[num >> 24]);
}

int main(){
    initialize();
    int x = 9;
    cout << countSetBits(x) << endl;
    return 0;
}