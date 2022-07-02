// Program to find Length of the longest substring without repeating characters

// Time: O(n^2)

#include <bits/stdc++.h>
using namespace std;

int longestUniqueSubsttr(string s)
{
    int n = s.length();
    int res = 0;
    
    for(int i=0; i<n; i++){
        vector<bool> visited(256);
        for(int j=i; j<n; j++){
            if(visited[s[j]] == true)
                break;
            else{
                visited[s[j]] = true;
                res = max(res, j-i+1);
            }
        }
        visited[i] = false;
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