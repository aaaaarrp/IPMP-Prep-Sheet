// Program to Search in a row wise and column wise sorted matrix

// Time: O(n) - Space: O(1)

#include<bits/stdc++.h>
using namespace std;

void search(vector<vector<int>> mat, int n, int x){
    if(n == 0)
        return;

    int smallest = mat[0][0];
    int largest = mat[n-1][n-1];

    if(x < smallest || x > largest)
        return;

    int i=0, j=n-1;
    while(i < n && j >= 0){
        if(mat[i][j] == x){
            cout << "Position: " << i << "x" << j <<endl;
            return;
        }
        else if(mat[i][j] > x)
            j--;
        else
            i++; 
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