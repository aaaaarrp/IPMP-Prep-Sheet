// Program to Find the smallest window in a string containing all characters of another string

// Sliding Window/Two pointers
// Time: O(|s|) where s is the length of string
// Space: O(1)

#include<bits/stdc++.h>
using namespace std;

string Minimum_Window(string str, string pat){
    vector<int> map (128,0);

    // Statistic for count of char in t
    for(auto i:pat)
        map[i]++;
    // count represents the number of chars of t to be found in s.
    size_t start = 0, end = 0, str_size = str.size(), count = pat.size(), minStart = 0, min_len = INT_MAX;

    // Move end to find a valid window.
    while(end < str_size){
        // If char in s exists in t, decrease counter
        if(map[str[end]] > 0)
            count--;
        // Decrease m[s[end]].If char does not exist in t, m[s[end]] will be negative.
        map[str[end]]--;
        end++;
        // When we found a valid window, move start to find smaller window.
        while(count == 0){
            if(end-start < min_len){
                min_len = end-start;
                minStart = start;
            }
            map[str[start]]++;
            // When char exists in t, increase counter.
            if(map[str[start]] > 0)
                count++;
            start++;
        }
    }
    if(min_len != INT_MAX)
        return str.substr(minStart, min_len);
    return "";
}

int wmain()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << "Smallest window that contain all character: " << Minimum_Window(s, t) << endl;
}