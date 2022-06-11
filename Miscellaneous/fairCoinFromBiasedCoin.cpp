// Program to Make a fair coin from a biased coin

// Time Complexity: O(1) - Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int foo(){
    //return 0;
}

int my_fun(){
    int val1 = foo();
    int val2 = foo();
    if(val1 == 0 && val2 == 1)
        return 0;
    if(val1 == 1 && val2 == 0)
        return 1;
    
    return my_fun();
}

int main(){
    cout << my_fun();
    return 0;
}