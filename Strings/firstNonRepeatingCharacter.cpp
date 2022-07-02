// Program to find a string's first non-repeating character

// Two string traversal
// Time: O(n) - Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int firstNonRepeating(char* str){
    vector<int> freq(26,0);

    for(int i=0; str[i] != '\0'; i++)
        freq[str[i]-'a']++;
    
    for(int i=0; str[i] != '\0'; i++){
        if(freq[str[i]-'a'] == 1)
            return i;
    }

    return -1;

}

int main(){
    char str[] = "dfnndksjnvs";
    int index = firstNonRepeating(str);
    if(index == INT_MAX)
        cout << "Either all characters are "
               "repeating or string is empty" << endl;
    else
        cout << str[index] << endl;
    return 0;
}