// Program to return the position of the first 1 from right to left, in the binary representation of an Integer. 

// Using right Shift (>>)
// Time Complexity: O(log2n) - Auxiliary Space: O(1)

#include<bits/stdc++.h>
using namespace std;
#define INT_SIZE 32

int getFirstSetBitPos(int n){
    int position = 1;
    while(n > 0){
        if(n&1)
            return position;
        position++;
        n >>= 1;
    }
    return -1;
}
int main(){
    int n = 12;
    int pos = getFirstSetBitPos(n);
    if(pos == -1)
        cout << 0 << endl;
    else
        cout << pos << endl;
    
}