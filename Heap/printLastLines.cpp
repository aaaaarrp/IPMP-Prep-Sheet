// Program to print last 'N' no of lines

#include <bits/stdc++.h>
using namespace std; 

void print_last_lines(char *str, int n){
    if(n <= 0)
        return;
    
    size_t count = 0;
    char *target_pos = NULL;

    target_pos = strrchr(str, '\n');
    if(target_pos == NULL){
        cout << "ERROR" << endl;
        return;
    }

    while(count < n){
        while(str < target_pos && *target_pos != '\n')
            target_pos--;
        if(*target_pos == '\n'){
            target_pos--;
            count++;
        }
        else
            break;
    }

    if(str < target_pos)
        target_pos +=2;

    cout << target_pos << endl;
}

int main(void) 
{ 
    char str1[] ="str1\nstr2\nstr3\nstr4\nstr5\nstr6\nstr7\nstr8\nstr9"
                "\nstr10\nstr11\nstr12\nstr13\nstr14\nstr15\nstr16\nstr17"
                "\nstr18\nstr19\nstr20\nstr21\nstr22\nstr23\nstr24\nstr25"; 
    char str2[] ="str1\nstr2\nstr3\nstr4\nstr5\nstr6\nstr7"; 
    char str3[] ="\n"; 
    char str4[] = ""; 

    int N = 10;
  
    print_last_lines(str1, N); 
    cout << "-----------------\n"; 
  
    print_last_lines(str2, N); 
    cout << "-----------------\n";
  
    print_last_lines(str3, N); 
    cout << "-----------------\n";; 
  
    print_last_lines(str4, N); 
    cout << "-----------------\n";
  
    return 0; 
}