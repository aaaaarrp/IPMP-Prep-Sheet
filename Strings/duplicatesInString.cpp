// Program to Print all the duplicates in the input string

// Time Complexity: O(n) - Space Complexity: O(NO_OF_CHARS)

#include<bits/stdc++.h>
using namespace std;

#define NO_OF_CHARS 256

void fillCharCount(char *str, int *count){
    for(int i=0; *(str+i); i++){
        count[*(str+i)]++;
    }
}

void duplicates(char *str){
    int *count = (int *)calloc(NO_OF_CHARS, sizeof(int));

    fillCharCount(str, count);

    for(int i=0; i<NO_OF_CHARS; i++){
        if(count[i] > 1)
            cout << char(i) << " - count: " << count[i] << endl;
    }
    free(count);
}

int main(){
    char str[] = "test string";
    duplicates(str);
    return 0;

}