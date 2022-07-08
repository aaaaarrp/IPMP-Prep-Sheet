// Program to rotate a linked list counter clock wise

/*  
    Traverse till last node
    Connect last node with first node
    Go to head node
    Traverse till kth node
    Update the kth node's next as new head
    make kth node's next Null
    return new head
*/

// Time: O(n) - Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

void rotate(Node **head_ref, int k){
    if(k == 0)
        return;
    
    Node* curr = *head_ref;
    while(curr->next != NULL)
        curr = curr->next;
    
    curr->next = *head_ref;
    curr = *head_ref;

    for(int i=0; i<k-1; i++)
        curr = curr->next;

    *head_ref = curr->next;
    curr->next = NULL;
}

void push(Node **head_ref, int new_data){
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node *node){
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main(void){
    Node *head = NULL;

    // 10->20->30->40->50->60
    for (int i = 60; i > 0; i -= 10)
        push(&head, i);

    cout << "Given linked list: ";
    printList(head);
    rotate(&head, 4);

    cout << "\nRotated Linked list: ";
    printList(head);

    return (0);
}

