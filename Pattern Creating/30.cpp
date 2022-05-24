

#include <bits/stdc++.h>
using namespace std;

void pattern5(int n){
    for(int row = 1; row <= n; row++){

        for(int s = 0; s < n - row; s++)
            cout << "  ";

        for(int col = row; col >= 1; col--){
            cout << col << " ";
        }
        for(int col = 2; col <= row; col++){
            cout << col << " "; 
        }
        cout << "\n";
    }
}

int main(){
    pattern5(5);
}