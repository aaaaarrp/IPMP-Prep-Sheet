// Program to implement Stack using one Queue

// Time: push O(n) - pop O(1)

#include<bits/stdc++.h>
using namespace std;

class Stack {
    queue<int> q;

public:
    void push(int x){
        int size = q.size();
        q.push(x);
        for(int i=0; i<size; i++){
            q.push(q.front());
            q.pop();
        }
    };

    void pop(){
        if(q.empty())
            cout << "No elements!" << endl;
        else
            q.pop();
    };

    int top(){
        if(q.empty())
            return -1;
        else
            return q.front();
    };

    bool empty(){
        return (q.empty());
    };
};


int main()
{
    Stack st;
    st.push(40);
    st.push(50);
    st.push(70);
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.push(80);
    st.push(90);
    st.push(100);
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    return 0;
}
