// Program to implement Queue using two Stacks

// By making dequeue operation costly
// Time: enqueue O(1) - dequeue O(n)

#include<bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:

    void enQueue(int x){
        s1.push(x);
    }

    int deQueue(){
        if(s1.empty() && s2.empty()){
            cout << "Queue is empty!" << endl;
            exit(0);
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
};

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
  
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
  
    return 0;
}