// Program to Count set bits in an integer

// Checking each bit in a number
// Time Complexity: O(logn)

#include<bits/stdc++.h>
using namespace std;

int countSetBits(int num){
    int count = 0;
    for(int i =0; i<sizeof(int)*8; i++){
        if(num & (1 << i))      // pow(2, i) = (1 << i)
            count++;
    }
    return count;
}

int main(){
    int x = 9;
    cout << countSetBits(x) << endl;
    return 0;
}