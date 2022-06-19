// Program to Count number of bits to be flipped to convert A to B

// & each bits of num1 && num2 with 1
// store them in t1 and t2
// if t1 != t2, flips count increses

#include <iostream>
using namespace std;

int flipCount(int num1, int num2){
    int flips = 0;
    while(num1 > 0 || num2 > 0){
        int t1 = (num1 & 1);
        int t2 = (num2 & 1);

        if(t1 != t2)
            flips++;
        
        num1 >>= 1;
        num2 >>= 1;
    }
    return flips;
}

int main()
{
    int a = 10;
    int b = 20;
    cout << flipCount(a, b) << endl;
    return 0;
}