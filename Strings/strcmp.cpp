/* Program to write a strcmp function which ignores cases
    and returns -1 if s1 < s2,
                 0 if s1 = s2, 
                 else returns 1. */

// Time Complexity: O(min(|string1|, |string2|))
// Auxiliary Space: O(1)

#include<bits/stdc++.h>
                      using namespace std;

int ic_strcmp(string str1, string str2){
    int i;
    for(i=0; str1[i] && str2[i]; i++){
        if(str1[i] == str2[i] || (str1[i] ^ 32) == str2[i])
            continue;
        else
            break;
    }

    if(str1[i] == str2[i])
        return 0;
    if((str1[i] | 32) < (str2[i] | 32))
        return -1;
    return 1;
}

int main(){
    cout << "First: " << ic_strcmp("Geeks", "apple") << endl;
    cout << "Second: " << ic_strcmp("", "ABCD") << endl;
    cout << "Third: " << ic_strcmp("ABCD", "zdl") << endl;
    cout << "Fourth: " << ic_strcmp("ABCD", "abcdEghe") << endl;
    cout << "Fifth: " << ic_strcmp("appleforlife", "AppleForLife") << endl;
    cout << "Sixth: " << ic_strcmp("whatdoyouwant", "whatdoyouwant") << endl;
    return 0;
}
