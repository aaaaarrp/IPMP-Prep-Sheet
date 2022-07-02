// Program to Reverse words in a given string

// Time Complexity: O(n), Auxiliary Space: O(1)
// Keeps the whitespace in the output

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string str){
    int left = 0, i=0, n = str.size();

    while(str[i] == ' ')
        i++;
    left = i;

    while(i<n){
        if(i+1 == n || str[i] == ' '){
            int j = i-1;
            if(i+1 == n)
                j++;
            while(left<j){
                swap(str[left++], str[j--]);
            }
            left = i+1;
        }
        if(str[left] == ' ' && i > left)
            left = i;
        i++;
    }
    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    string s = "    i like this program very much";
    string str = reverseWords(s);
    cout << str;
    return 0;
}