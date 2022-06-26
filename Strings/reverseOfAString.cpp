// Recursive function to print reverse of a given string - Time: O(n^2)

#include<bits/stdc++.h>
using namespace std;

void reverse(string str){

    if(str.size() == 0)
        return;

    reverse(str.substr(1));
    cout << str[0];
}

int main(){
    string a = "arpon kapuria";
    reverse(a);
    cout <<  endl;
    return 0;
}
