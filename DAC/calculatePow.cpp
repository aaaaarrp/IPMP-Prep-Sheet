// Program to calculate pow(x,n) - Time : O(n) 
// Below solution divides the problem into subproblems of size y/2 and call the subproblems recursively. 

#include<bits/stdc++.h>
using namespace std;

class power
{
public:
int pow(int x, unsigned int y){
    if(y == 0)
        return 1;
    else if(y%2 == 0)
        return pow(x, y/2) * pow(x, y/2);
    else
        return x * pow(x, y/2) * pow(x, y/2);
}
};

int main(){
    power g;
    int x = 2;
    unsigned int y = 5;

    cout << g.pow(x,y) << endl;
    return 0;

}