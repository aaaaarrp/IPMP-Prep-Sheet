// Program for Expression Evaluation with operator priority and multiple braces

// Time: O(n) - space: O(n)

#include<bits/stdc++.h>
using namespace std;

int precedence(char op){
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    return 0;
}

int applyOp(int val1, int val2, char op){
    switch(op){
        case '+': return val1 + val2;
        case '-': return val1 - val2;
        case '*': return val1 * val2;
        case '/': return val1 / val2;
    }
    return 0;
}

int evaluate(string token){

    int i;
    stack<int> values;
    stack<char> ops;

    for(i=0; i<token.length(); i++){

        if(token[i] == ' ')
            continue;

        else if(token[i] == '(')
            ops.push(token[i]);

        else if(isdigit(token[i])){
            int val = 0;

            while(i < token.length() && isdigit(token[i])){
                val = (val*10) + (token[i]-'0');
                i++;
            }

            values.push(val);
            i--;
        }

        else if(token[i] == ')'){
            while(!ops.empty() && ops.top() != '('){

                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            if(!ops.empty())
                ops.pop();
        }

        else {
            while(!ops.empty() && precedence(ops.top()) >= precedence(token[i])){

                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }
            ops.push(token[i]);
        }
    }

    while(!ops.empty()){

        int val2 = values.top();
        values.pop();

        int val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }
    return values.top();

}

int main() {
    cout << evaluate("10 + 2 * 6") << "\n";
    cout << evaluate("100 * 2 + 12") << "\n";
    cout << evaluate("100 * ( 2 + 12 )") << "\n";
    cout << evaluate("100 * ( 2 + 12 ) / 14") << endl;
    return 0;
}