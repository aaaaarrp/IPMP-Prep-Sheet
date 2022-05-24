
#include <bits/stdc++.h>
using namespace std;

void pattern3(int n){
    for(int row = 1; row <= n; row++){
        for(int col = 1; col <= n-row+1 ; col++ ){
            cout << "* ";
        }
        cout << "\n";
    }
}

int main(){
    pattern3(5);
}