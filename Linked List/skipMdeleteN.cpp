// Program to Delete N nodes after M nodes of a linked list

// Time: O(n) - Space: O(1)

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void skipMdeleteN(Node* head, int m, int n){
    Node* curr = head, *t;
    int count;

    while(curr){
        for(int count = 1; count < m && curr != NULL; count++){
            curr = curr->next;
        }
        if(!curr)
            return;
        t = curr->next;
        for(int count=1; count <= n && t != NULL; count++){
            Node* temp = t;
            t = t->next;
            free(temp);
        }
        curr->next = t;
        curr = t;

    }
}

void push(Node** head, int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void printList(Node* head){
    while(head){
        cout << head->data <<" ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    int M=2, N=3;
    Node* head = NULL;
    for(int i = 9; i>0; i--)
        push(&head, i);

    cout << "Original List: ";
    printList(head);

    skipMdeleteN(head, M, N);
    cout << "Modified List: ";
    printList(head);
}