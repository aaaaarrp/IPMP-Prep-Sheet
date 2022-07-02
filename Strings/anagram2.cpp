// Programt to Check whether two strings are anagram of each other

// Sort & Compare
// Time: O(n) - space: O(1)

#include <bits/stdc++.h>
using namespace std;

bool areAnagram(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();

    if(n1 != n2)
        return false;
    
    vector<int> freq(26,0);

    for(int i=0; i<n1; i++){
        freq[s1[i]-'a']++;
    }

    for(int i=0; i<n2; i++){
        freq[s2[i]-'a']--;
    }

    for(auto it: freq){
        if(it != 0)
            return false;
    }

    return true;
}

int main()
{
    string str1 = "test";
    string str2 = "ttes";

    if (areAnagram(str1, str2))
        cout << "The two strings are anagram of each other";
    else
        cout << "The two strings are not anagram of each "
                "other";

    return 0;
}