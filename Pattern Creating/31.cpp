
#include <bits/stdc++.h>
using namespace std;

void pattern5(int n){
    n = 2 * n;
    for(int row = 0; row <= n; row++){
        for(int col = 0; col <= n; col++){
            int atEveryIndex = min(min(row, col), min(n-row, n-col));
            cout << atEveryIndex << " ";
        }

        cout << "\n";
    }
}

int main(){
    pattern5(4);
}