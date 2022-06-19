// Program to Count set bits in an integer

// Brian Kernighan’s Algorithm
// Time Complexity: O(logn)

#include<bits/stdc++.h>
using namespace std;

unsigned int countSetBits(unsigned int num){
    unsigned int count = 0;
    while(num){
        num &= num-1;
        count++;
    }
    return count;
}

int main(){
    int x = 9;
    cout << countSetBits(x) << endl;
    return 0;
}