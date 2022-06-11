// Program to determine endianness of a machine

// Time Complexity: O(1) - Auxiliary Space: O(1)

#include<bits/stdc++.h>
using namespace std;

int main(){
    unsigned int i = 1;
    char *c = (char*)&i;
    if(*c)
        cout << "Little Endian" << endl;
    else
        cout << "Big Endian" << endl;
    
    return 0;
}