// Program to find whether a given number is power of 2

// Take the log of the number on base 2 and if you get an integer then the number is the power of 2
// Time: O(1) - Space: O(1)

#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int num){
    if(num == 0)
        return false;
    return (ceil(log2(num)) == floor(log2(num)));   // integer checking
}

int main(){
    isPowerOfTwo(31) ? cout << "Yes" << endl : cout << "No" << endl;
    isPowerOfTwo(64) ? cout << "Yes" << endl : cout << "No" << endl;
    cout << ceil(log2(31)) << endl;
    cout << floor(log2(31)) << endl;
    cout << ceil(log2(64)) << endl;
    cout << floor(log2(64)) << endl;
}