// Program to return the position of the first 1 from right to left, in the binary representation of an Integer. 

// Using XOR and & operator 
// Time Complexity: O(log2n) - Auxiliary Space: O(1)

#include<bits/stdc++.h>
using namespace std;

int getFirstSetBitPos(int n){
    if(n == 0)
        return 0;
    
    int m = 1;
    int position = 1;

    while(!(n&m)){
        m <<= 1;
        position++;
    }
    return position;
}
int main(){
    int n = 12;
    cout << getFirstSetBitPos(n) << endl;
    return 0;
}