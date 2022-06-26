// Program to Remove characters from the first string which are present in the second string

// Time Complexity: O(m*n) - m length of 1st string and n length of 2nd string
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

string removeduplicates(string str1, string str2){
    for(auto i:str2){
        while(find(str1.begin(), str1.end(), i) != str1.end()){
            auto it = find(str1.begin(), str1.end(), i);
                str1.erase(it);
        }
    }
    return str1;
}

int main()
{
    string str1 = "dlj";
    string str2 = "jk";
    cout << removeduplicates(str1, str2) << endl;
    return 0;
}