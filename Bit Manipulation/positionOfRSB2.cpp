// Program to return the position of the first 1 from right to left, in the binary representation of an Integer. 

// ffs() function returns the index of first least significant set bit.
// Time Complexity: O(log2n) - Auxiliary Space: O(1)

#include<bits/stdc++.h>
using namespace std;

int getFirstSetBitPos(int n){
    return ffs(n);
}
int main(){
    int n = 12;
    cout << getFirstSetBitPos(n) << endl;
    return 0;
}