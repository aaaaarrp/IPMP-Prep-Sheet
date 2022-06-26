// Program to Remove characters from the first string which are present in the second string

// Time Complexity: O(m+n) - m length of 1st string and n length of 2nd string
// Space Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

#define NO_OF_CHARS 256

int* getCountArray(string str){
    int* count = (int*)calloc(NO_OF_CHARS, sizeof(int));
    for(int i=0; i<str.size(); i++)
        count[str[i]]++;

    return count;
}

string removeduplicates(string str1, string str2){
    int *count = getCountArray(str2);

    string res;
    int ip_index = 0;
    while(ip_index < str1.size()){
        char temp = str1[ip_index];
        if(count[temp] == 0)
            res.push_back(temp);
        ip_index++;
    }
    return res;
}

int main(){
    string str1 = "dljjnkjegnin";
    string str2 ="jkhfnek";
    cout << removeduplicates(str1, str2) << endl;
    return 0;
}