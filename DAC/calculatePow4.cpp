// Program to calculate pow(x,n) using Recursion - Time : O(n)


#include<bits/stdc++.h>
using namespace std;

int power(int x, int y){
    if(y == 0)
        return 1;
    if(x == 0)
        return 0;
    
    return x * power(x, y-1);
}

int main(){
    int x = 3;
    int y = 2;
    cout << power(x,y) << endl;
    return 0;
}