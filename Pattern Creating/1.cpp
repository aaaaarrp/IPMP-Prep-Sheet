#include <bits/stdc++.h>
using namespace std;

void pattern1(int n){
    for(int row = 1; row <= n; row++){
        for(int col = 1; col <= row; col++){
            cout << "* "; 
        }
        cout << "\n";
    }
}

int main(){
    pattern1(5);
}