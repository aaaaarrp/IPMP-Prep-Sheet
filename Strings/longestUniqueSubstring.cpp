// Program to find Length of the longest substring without repeating characters

// Time: O(n^3)

#include <bits/stdc++.h>
using namespace std;

bool areDistinct(string s, int i, int j){
    vector<bool> visited(256);

    for(int k =i; k<=j; k++){
        if(visited[s[k]] == true)
            return false;
        visited[s[k]] = true;
    }
    return true;
}

int longestUniqueSubsttr(string s){
    int n = s.length();
    int res = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(areDistinct(s,i,j))
                res = max(res, j-i+1);
        }
    }
    return res;
}

int main()
{
    string str = "  ";
    cout << "The input string is " << str << endl;
    int len = longestUniqueSubsttr(str);
    cout << "The length of the longest non-repeating "
            "character substring is " << len;
    return 0;
}