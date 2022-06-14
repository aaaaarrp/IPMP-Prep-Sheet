// Program to reverse the linked list by changing the links between nodes

// Iterative method - using 3 pointers
// Time Complexity: O(n) - Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

struct LinkedList {
    Node *head;
    LinkedList(){
        head = NULL;
    }

    void reverse(){
        Node *prev = NULL, *next = NULL;
        Node *curr = head;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void print(){
        struct Node *temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void push(int data){
        struct Node *new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }
};

int main(){
    LinkedList ll;
    ll.push(20);
    ll.push(30);
    ll.push(26);
    ll.push(14);    

    cout << "Given linked list: ";  // 14->26->30->20
    ll.print();

    ll.reverse();

    cout << "Reversed linked list: ";   // 20->30->26->14
    ll.print();

}