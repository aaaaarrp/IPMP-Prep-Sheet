// Program to find Length of the longest substring without repeating characters

// Time: O(n+d) - Space: O(d), d is number of characters in input string alphabet

#include <bits/stdc++.h>
using namespace std;

int longestUniqueSubsttr(string s)
{
    int n = s.length();

    map<char,int> seen;
    int start=0;
    int res = 0;

    for (int end = 0; end < n; end++){
        if(seen.find(s[end]) != seen.end()){
            start = max(start, seen[s[end]]+1);
        }
        seen[s[end]] = end;
        res = max(res, end-start+1);
    }
    return res;
}

int main()
{
    string str = "fkenlkfnwef";
    cout << "The input string is " << str << endl;
    int len = longestUniqueSubsttr(str);
    cout << "The length of the longest non-repeating "
            "character substring is "
         << len;
    return 0;
}