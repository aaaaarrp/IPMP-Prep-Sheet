// Program to reverse a linked list in groups of given size

// Time: O(n) - Space: O(n/k) for recursion

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

Node *reverse(Node *head, int k){
    if(head == NULL)
        return NULL;
    Node* curr = head, *prev = NULL, *next = NULL;
    int count = 0;
    while(curr && count<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next != NULL)
        head->next = reverse(next, k);
    
    return prev;
}

void push(Node **head_ref, int new_data){
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main(){

    Node *head = NULL;

    /* 1->2->3->4->5->6->7->8->9 */
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout << "Given linked list \n";
    printList(head);
    head = reverse(head, 3);

    cout << "\nReversed Linked list \n";
    printList(head);

    return (0);
}

