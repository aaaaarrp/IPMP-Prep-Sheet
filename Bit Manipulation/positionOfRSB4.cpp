// Program to return the position of the first 1 from right to left, in the binary representation of an Integer. 

// Using Left Shift (<<)
// Time Complexity: O(log2n) - Auxiliary Space: O(1)

#include<bits/stdc++.h>
using namespace std;
#define INT_SIZE 32

int getFirstSetBitPos(int n){
    if(n == 0)
        return 0;
    else {
        int position = 1;
        for(int i=0; i<INT_SIZE; i++){
            if(!(n & (1 << i)))
                position++;
            else
                break;
        }
        return position;
    }   
}
int main(){
    int n = 12;
    cout << getFirstSetBitPos(n) << endl;
    return 0;
}