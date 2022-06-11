// Program to see memory representation of multibyte data types on your machine

// Time Complexity: O(1) - Auxiliary Space: O(1)

// When above program is run on little endian machine, gives “67 45 23 01” as output,
// while if it is run on big endian machine, gives “01 23 45 67” as output.


#include<bits/stdc++.h>
using namespace std;

void show_mem_rep(char *start, int n){
    int i;
    for(i=0; i<n; i++)
        printf(" %.2x",start[i]);
    cout << endl;
}

int main(){
    int i = 0x1234567;
    show_mem_rep((char*)&i, sizeof(i));
    return 0;
}