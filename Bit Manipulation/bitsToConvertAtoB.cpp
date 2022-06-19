// Program to Count number of bits to be flipped to convert A to B

// countSetBits(num1 XOR num2)

// Time Complexity: O(logn)

#include <iostream>
using namespace std;

int countSetBits(int num){
    int count = 0;
    while(num){
        num &= num-1;
        count++;
    }
    return count;
}

int flippedCount(int num1, int num2){
    return countSetBits(num1 ^ num2);
}

int main()
{
    int a = 10;
    int b = 20;
    cout << flippedCount(a, b) << endl;
    return 0;
}