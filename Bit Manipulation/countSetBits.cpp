// Program to Count set bits in an integer

// Time Complexity: Θ(logn) (Theta of logn) - Auxiliary Space: O(1)

#include<bits/stdc++.h>
using namespace std;

unsigned int countSetBits(unsigned int num){
    unsigned int count = 0;
    while(num){
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int main(){
    int x = 9;
    cout << countSetBits(x) << endl;
    return 0;
}