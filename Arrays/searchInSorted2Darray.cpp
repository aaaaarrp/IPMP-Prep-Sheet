// Program to Search in a row wise and column wise sorted matrix

// Time: O(n^2) - Space: O(1)

#include<bits/stdc++.h>
using namespace std;

void search(vector<vector<int>> mat, int n, int x){
    for(int i=0; i<n; i++){
        for(int j=0; j<mat[i].size(); j++){
            if(mat[i][j] == x){
                cout << "Position: " << i << "x" << j << endl;
                return;
            }
        }
    }
    cout << "Element not found" << endl;
}

int main(){
    vector<vector<int>> mat = { { 10, 20, 30, 40 },
                                { 15, 25, 35, 45 },
                                { 27, 29, 37, 48 },
                                { 32, 33, 39, 50 } };
    int num = 29;
    search(mat, mat.size(), num);
    return 0;
}