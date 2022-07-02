// Program to find a string's first non-repeating character

// Improved One string traversal
// Time: O(n) - Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int firstNonRepeating(char *str)
{
    vector<pair<int, int>> freq(26);

    for (int i = 0; str[i] != '\0'; i++){
        freq[str[i] - 'a'].first++;     // count
        freq[str[i] - 'a'].second = i;  // index
    }

    for (int i = 0; i<freq.size(); i++)
    {
        if (freq[str[i] - 'a'].first == 1)
            return freq[str[i] - 'a'].second;
    }

    return -1;
}

int main()
{
    char str[] = "dfnndksjnvs";
    int index = firstNonRepeating(str);
    if (index == INT_MAX)
        cout << "Either all characters are "
                "repeating or string is empty"
             << endl;
    else
        cout << str[index] << endl;
    return 0;
}