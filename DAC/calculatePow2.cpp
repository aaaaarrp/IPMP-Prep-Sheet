// Program to calculate pow(x,n) using Divide & Conquer - Time : O(logn) 
// first program's function can be optimized to O(logn) by calculating power(x, y/2) only once and storing it. 

#include<bits/stdc++.h>
using namespace std;

class power
{

public:
int pow(int x, unsigned int y){
    int temp;
    if(y == 0)
        return 1;
    temp = pow(x, y/2);
    if(y%2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}
};

int main(){
    power g;
    int x = 2;
    unsigned int y = 5;

    cout << g.pow(x,y) << endl;
    return 0;
}