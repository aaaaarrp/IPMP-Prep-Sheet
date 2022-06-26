// Program to Print all the duplicates in the input string

// Hashmap
// Time Complexity: O(nlogn), unordered map can do it in O(n) time
// Space Complexity: O(k), k size of the map (o <= k <= string length)

#include <bits/stdc++.h>
using namespace std;

void duplicates(char *str)
{
    map<char, int> map;
    for (int i = 0; i < strlen(str); i++)
        map[str[i]]++;
    for (auto it : map)
    {
        if (it.second > 1)
            cout << it.first << " - count: " << it.second << endl;
    }
}


int main(){
    char str[] = "test string";
    duplicates(str);
    return 0;
}