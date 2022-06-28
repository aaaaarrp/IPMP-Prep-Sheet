// Program to Turn an image by 90 degree

// row major order
// Time Complexity: O(N*M) - Auxiliary Space: O(N*M)


#include<bits/stdc++.h>
                      using namespace std;

void display(unsigned int *dest, unsigned int row, unsigned int col){
    unsigned int r, c;
    for (r = 0; r < row; r++){
        for (c = 0; c < col; c++){
            cout << *(dest + r*col + c) << "\t";
        }
        cout << endl;
    }
}

void rotate(unsigned int* source, unsigned int* dest, unsigned int row, unsigned int col){
    unsigned int r, c;
    for(r=0; r<row; r++){
        for(c=0; c<col;c++){
            *(dest + c*row + (row-r-1)) = *(source + r*col + c);
        }
    }
}

int main(){
    unsigned int image[][4] = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12}};
    
    unsigned int *source;
    unsigned int *dest;
    unsigned int m, n;

    m = 3, n = 4;
    source = (unsigned int*)image;
    dest = (unsigned int*)malloc(sizeof(int)*m*n);

    display(source, m, n);
    rotate(source, dest, m, n);
    cout << endl;
    display(dest, n, m);
    free(dest);
    return 0;
}