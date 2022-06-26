// Program to return the Run Length Encoded string for the input string.

// Time Complexity: O(n) - Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;

void printRLE(string str){
    int n = str.length();
    for(int i=0; i<n; i++){
        int count = 1;
        while(i < n-1 && str[i] == str[i+1]){
            count++;
            i++;
        }
        cout << str[i] << count;
    }
    cout << endl;
}

int main()
{
    string str = "wwwwaaadexxxxxxywww";
    printRLE(str);
    return 0;
}