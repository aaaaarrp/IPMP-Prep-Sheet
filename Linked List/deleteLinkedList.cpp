// function to delete a Linked List

//Time Complexity: O(n) - Auxiliary Space: O(1)

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void deleteLinkedList(Node** head){
    Node* curr = *head;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        free(curr);
        curr = next;
    }
    *head = NULL;
}

void push(Node** head, int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}



int main(){
    Node* head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    deleteLinkedList(&head);
    cout << "Linked list deleted" << endl;
}