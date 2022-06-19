// Program to Count set bits in an integer

// Brian Kernighan’s Algorithm - Recursive approach
// Time Complexity: O(logn)

#include<bits/stdc++.h>
using namespace std;

unsigned int countSetBits(unsigned int num){
    if(num == 0)
        return 0;
    else
        return 1+countSetBits(num&num-1);
}

int main(){
    int x = 9;
    cout << countSetBits(x) << endl;
    return 0;
}