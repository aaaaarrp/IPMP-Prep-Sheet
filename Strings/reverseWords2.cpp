// Program to Reverse words in a given string

// Time Complexity: O(n), Auxiliary Space: O(1)
// removes the whitespace from the output

#include <bits/stdc++.h>
using namespace std;

void reverseWords(string str){
    int i=0, j=0, left = 0, word_count = 0;
    int len = str.length();

    while(true){
        while(i<len && str[i] == ' ')
            i++;
        if(i == len)
            break;
        if(word_count)
            str[j++] = ' ';
        left = j;
        while(i < len && str[i] != ' '){
            str[j++] = str[i++];
        }
        reverse(str.begin()+left, str.begin()+j);
        word_count++;
    }
    str.resize(j);
    reverse(str.begin(), str.end());
    cout << str;
}

int main()
{
    string s = "    i like this program very much";
    reverseWords(s);
    return 0;
}