// Program to calculate pow(x,n) using non-Recursive Method - T(n)= O(log(n))
// Time Complexity: O(log2y)

#include<bits/stdc++.h>
using namespace std;

int power(int x, int y){
    int result = 1;
    while(y > 0){
        if( y%2 == 0){
            x = x * x;
            y = y/2;
        }
        else{
            result = result * x;
            y = y - 1;
        }
    }

    return result;
}

int main(){
    int x = 2;
    int y = 3;
    cout << power(x,y) << endl;
    return 0;
}