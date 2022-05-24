
// Implement two stacks in an array


#include<bits/stdc++.h>
using namespace std;

class twoStacks {
    int* array;
    int size;
    int top1, top2;

public: 
    twoStacks (int n){
        size = n;
        array = new int[n];
        top1 = -1;
        top2 = size;
    }

    void push1(int x){
        if(top1 < top2 - 1){
            top1++;
            array[top1] = x;
        }
        else{
            cout << "Stack Overflow";
        }
    }

    void push2(int x){
        if(top1 < top2 - 1){
            top2--;
            array[top2] = x;
        }
        else{
            cout << "Stack Overflow";
        }
    }

    int pop1(){
        if(top1 >= 0){
            int x = array[top1];
            top1--;
            return x;
        }
        else{
            cout << "Stack Underflow";
            exit(1);
        }
    }

    int pop2(){
        if(top2 <= size - 1){
            int x = array[top2];
            top2++;
            return x;
        }
        else{
            cout << "Stack Underflow";
            exit(1);
        }
    }
};

int main()
{
    twoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is " << ts.pop1();
    ts.push2(40);
    cout << "\nPopped element from stack2 is " << ts.pop2() << endl;
    return 0;
}