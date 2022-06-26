// Program to write our own atoi function "atoi()"
// atoi() is used to convert a string argument to an integer.

// Time Complexity: O(n)

/* Corner cases handled: 
    -> Discards all leading whitespaces
    -> Sign of the number
    -> Overflow
    -> Invalid input
*/

#include<bits/stdc++.h>
using namespace std;

int myAtoi(char *str){
    int base = 0, sign = 1, i = 0;

    while(str[i] == ' ')    // ignores whitespaces
        i++;
    
    if(str[i] == '-')   // for negative numbers
        sign = -1;
        i++;

    while(str[i] >= '0' && str[i] <= '9') {     // checking for valid input
        // handling overflow test case
        if(base > INT_MAX/10 || (base == INT_MAX/10 && str[i] - '0' > 7)){
            if(sign == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }
        // Iterate through all characters of input string and update result
        // take ASCII character of corresponding digit and
        // subtract the code from '0' to get numerical
        // value and multiply res by 10 to shuffle digits left to update running total
        base = base*10 + str[i++] - '0';
    }
        
    return base * sign;
}

int main(){
    int val;
    char str1[] = "-123";
    val = myAtoi(str1);
    cout << val << endl;
}