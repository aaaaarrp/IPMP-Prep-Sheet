// Program to Print reverse of a Linked List without actually reversing

// Using recursive function
// Time Complexity: O(n) 
// Auxiliary Space: O(n) for stack space since using recursion

#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
};

void printReverse(node* head){
    if(!head)
        return;
    printReverse(head->next);
    cout << head->data << " ";
}

void printll(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insert_back(node** head, int data){
    node* new_node = new node();
    new_node->data = data;
    new_node->next = NULL;

    if(!*head){
        *head = new_node;
        return;
    }
    else {
        node* last_node = *head;
        while(last_node->next != NULL)
            last_node = last_node->next;
        last_node->next = new_node;
        return;
    }
}

int main(){
    node* head = NULL;
    insert_back(&head, 1);
    insert_back(&head, 2);
    insert_back(&head, 3);
    insert_back(&head, 4);

    printll(head);

    printReverse(head);

    return 0;
}