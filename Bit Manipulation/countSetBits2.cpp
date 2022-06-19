// Program to Count set bits in an integer

// Recursive approach
// Time Complexity: Θ(logn) (Theta of logn) - Auxiliary Space: O(1)

#include<bits/stdc++.h>
using namespace std;

int countSetBits(int num){
    if(num == 0)
        return 0;
    else
        return (num & 1) + countSetBits(num >> 1);
}

int main(){
    int x = 9;
    cout << countSetBits(x) << endl;
    return 0;
}