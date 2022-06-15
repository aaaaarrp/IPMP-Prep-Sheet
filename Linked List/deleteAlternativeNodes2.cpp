// Program to delete alternative nodes of a linked list

// Recursive way
// Time: O(n)

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void deleteAlt(Node* head){
    if(head == NULL)
        return;
    
    Node* curr = head->next;
    if(curr == NULL)
        return;
    head->next = curr->next;
    free(curr);
    deleteAlt(head->next);
}

void push(Node** head, int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void printList(Node* head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() 
{ 
    Node* head = NULL; 

    // 1->2->3->4->5->6
    push(&head, 6);
    push(&head, 5); 
    push(&head, 4); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 1); 
  
    cout<<"List before calling deleteAlt() \n"; 
    printList(head); 
  
    deleteAlt(head); 
  
    cout<<"\nList after calling deleteAlt() \n"; 
    printList(head); 
  
    return 0; 
}