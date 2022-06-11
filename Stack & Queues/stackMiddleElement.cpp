// Program to Design a stack with operations on middle element

/* Operations:
    1) push() which adds an element to the top of stack. 
    2) pop() which removes an element from top of stack. 
    3) findMiddle() which will return middle element of the stack. 
    4) deleteMiddle() which will delete the middle element. 
*/

// O(1) time complexity on all operations

#include<bits/stdc++.h>
using namespace std;

class myStack {

    struct Node {
        int val;
        Node *next;
        Node *prev;

        Node(int val) {
            this->val = val;
        }
    };

    Node *head = NULL;
    Node *mid = NULL;
    int size = 0;

public:

    void push(int x){
        Node *temp = new Node(x);
        if(size == 0){
            head = temp;
            mid = temp;
            size++;
            return;
        }

        head->next = temp;
        temp->prev = head;

        head = head->next;
        if(size % 2 == 1)
            mid = mid->next;
        size++;
    }

    int pop(){
        int x = -1;
        if(size != 0){
            x = head->val;
            if(size == 1){
                head = NULL;
                mid = NULL;
            }
            else {
                head = head->prev;
                head->next = NULL;
                if(size % 2 == 0)
                    mid = mid->prev;
            }
            size--;
        }
        return x;
    }

    int findMiddle(){
        if(size == 0)
            return -1;
        else 
            return mid->val;
    }

    void deleteMiddle(){
        if(size != 0){
            if(size == 1){
                head = NULL;
                mid = NULL;
            }
            else if(size == 2){
                head = head->prev;
                mid = mid->prev;
                head->next = NULL;
            }
            else {
                mid->next->prev = mid->prev;
                mid->prev->next = mid->next;
                if(size % 2 == 0)
                    mid = mid->prev;
                else
                    mid = mid->next;
            }
            size--;
        }
    }
};

int main()
{
    myStack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    st.push(66);
    st.push(77);
    st.push(88);
    st.push(99);
    cout <<"Popped : "<< st.pop() << endl;
    cout <<"Popped : "<< st.pop() << endl;
    cout <<"Middle Element : "<< st.findMiddle() << endl;
    st.deleteMiddle();
    cout <<"New Middle Element : "<< st.findMiddle() << endl;
    return 0;
}