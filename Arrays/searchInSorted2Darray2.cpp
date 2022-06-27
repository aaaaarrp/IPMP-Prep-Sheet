// Program to Search in a row wise and column wise sorted matrix

// Time: O(n) - Space: O(1)

#include<bits/stdc++.h>
using namespace std;

void search(vector<vector<int>> matrix, int row_size, int x){
    if(row_size == 0)
        return;

    int col_size = matrix[0].size();

    int smallest = matrix[0][0];
    int largest = matrix[row_size - 1][col_size - 1];

    if(x < smallest || x > largest)
        return;

    int i = 0, j = col_size - 1;
    while(i < row_size && j >= 0){
        if(matrix[i][j] == x){
            cout << "Position: " << i << "x" << j <<endl;
            return;
        }
        else if(matrix[i][j] > x)
            j--;
        else
            i++; 
    }
    cout << "Element not found" << endl;
}

int main(){
    // vector<vector<int>> mat = { { 10, 20, 30, 40 },
    //                             { 15, 25, 35, 45 },
    //                             { 27, 29, 37, 48 },
    //                             { 32, 33, 39, 50 } };

    vector<vector<int>> mat = {{1,29}};
    int num = 29;
    search(mat, mat.size(), num);
    return 0;
}