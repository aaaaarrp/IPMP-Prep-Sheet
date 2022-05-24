

#include <bits/stdc++.h>
using namespace std;

void pattern5(int n){
    for(int row = 1; row <= 2*n; row++){

        int totalColsInrow = row > n ? 2*n - row : row;

        for(int s = 0; s < n - totalColsInrow; s++)
            cout << "  ";

        for(int col = totalColsInrow; col >= 1; col--){
            cout << col << " ";
        }
        for(int col = 2; col <= totalColsInrow; col++){
            cout << col << " "; 
        }
        
        cout << "\n";
    }
}

int main(){
    pattern5(5);
}