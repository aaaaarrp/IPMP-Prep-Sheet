// Program to rotate bits of a number

// Time Complexity: O(1) - Auxiliary Space: O(1)

#include<iostream> 
using namespace std;

#define INT_BITS 32

int leftRotate(int n, unsigned int d){
    return (n << d) | (n >> (INT_BITS-d));
}

int rightRotate(int n, unsigned int d){
    return (n >> d) | (n << (INT_BITS-d));
}

int main()
{
    int n = 16;
    int d = 2;
    cout << "Left Rotation of " << n <<
            " by " << d << " is: ";
    cout << leftRotate(n, d) << endl;
    cout << "Right Rotation of " << n <<
            " by " << d << " is: ";
    cout << rightRotate(n, d) << endl;

}