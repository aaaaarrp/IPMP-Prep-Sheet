// Program to Check for Balanced Brackets in an expression (well-formedness) using Stack

// Time Complexity: O(n) - Auxiliary Space: O(n) for stack. 

#include<bits/stdc++.h>
using namespace std;

bool areBracketsBalanced(string expr){
    stack<char> temp;
    for(int i=0; i<expr.length(); i++){
        if(temp.empty())
            temp.push(expr[i]);
        else if((temp.top() == '(' && expr[i] == ')') || (temp.top() == '{' && expr[i] == '}') || (temp.top() == '[' && expr[i] == ']'))
            temp.pop();
        else
            temp.push(expr[i]);
    }

    if(temp.empty())
        return true;
    else
        return false;
}

int main()
{
    string expr = "{()}[]{}";
 
    // Function call
    if (areBracketsBalanced(expr))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;
    return 0;
}