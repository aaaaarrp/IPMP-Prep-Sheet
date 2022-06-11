// Program to implement Queue using one user stack and one Function Call Stack

// Modified method-2: dequeue operation costly & recursion used
// Time: enqueue O(1) - dequeue O(n)

#include<bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s;

public:
    void enQueue(int x){
        s.push(x);
    }

    int deQueue(){
        if(s.empty()){
            cout << "Queue is empty!" << endl;
            exit(0);
        }

        int x = s.top();
        s.pop();

        if(s.empty())
            return x;
        
        int item = deQueue();
        s.push(x);

        return item;
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