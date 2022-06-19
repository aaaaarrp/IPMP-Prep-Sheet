// Program to rotate bits of a number

// Time Complexity: O(1) - Auxiliary Space: O(1)

// For 16 bit number

#include<bits/stdc++.h>
using namespace std;

#define SHORT_SIZE 16

short leftRotate(short n, short d){
    return (n << d) | (n >> (SHORT_SIZE-d));
}

short rightRotate(short n, short d){
    return (n >> d) | (n << (SHORT_SIZE-d));
}

int main()
{
    short n = 28;
    short d = 2;
    cout << "Left Rotation of " << n <<
            " by " << d << " is: ";
    cout << leftRotate(n, d) << endl;
    cout << "Right Rotation of " << n <<
            " by " << d << " is: ";
    cout << rightRotate(n, d) << endl;

}