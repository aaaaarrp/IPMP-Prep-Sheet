// Program to calculate pow(x,n) using Divide & Conquer - Time : O(log|n|)
// Extending the pow function to work for negative y and float x. 


#include<bits/stdc++.h>
using namespace std;

float power(float x, int y){
    float temp;
    if(y == 0)
        return 1;
    temp = power(x, y/2);
    if(y%2 == 0)
        return temp * temp;
    else
        if(y > 0)
            return x * temp * temp;
        else    
            return (temp * temp) / x;
}

int main(){
    float x = 2;
    int y = 3;
    cout << power(x, y) << endl;
    return 0;
}


