// C++ program to print all permutations of a string 
// Time: O(n*n!) - Space: O(|s|)

#include<bits/stdc++.h>
using namespace std;

void permute(string str, string answer){
    if(str.length() == 0){
        cout << answer << endl;
        return;
    }
    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        string left_substr = str.substr(0,i);
        string right_substr = str.substr(i+1);
        string rest = left_substr + right_substr;
        permute(rest, answer+ch);
    }
}

int main(void){
    string str = "ACC";
    string answer = " ";
    permute(str, answer);
    return 0;
}

