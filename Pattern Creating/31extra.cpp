
#include <bits/stdc++.h>
using namespace std;

void pattern5(int n){
    int N = 2 * n;
    for(int row = 0; row <= N; row++){
        for(int col = 0; col <= N; col++){
            int atEveryIndex = n - min(min(row, col), min(N-row, N-col));
            cout << atEveryIndex << " ";
        }

        cout << "\n";
    }
}

int main(){
    pattern5(4);
}