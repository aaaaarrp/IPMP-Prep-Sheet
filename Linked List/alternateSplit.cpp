/*  Program to alternately split one list by dividing its nodes to make two smaller lists,
    The sublists should be made from alternating elements in the original list.
    If the original list is 0->1->0->1->0->1,
    Then one sublist should be 0->0->0 and the other should be 1->1->1. 
*/

// Time Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

void moveNode(Node** dest, Node** source){
    Node* newnode = *source;
    assert(newnode != NULL);

    *source = newnode->next;
    newnode->next = *dest;
    *dest = newnode;
}

void alternatingSplit(Node* head, Node** headA, Node** headB){
    Node* a = NULL;
    Node* b = NULL;

    Node *curr = head;
    while(curr){
        moveNode(&a, &curr);
        if(curr)
            moveNode(&b, &curr);
    }
    *headA = a;
    *headB = b;
}

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 
void printList(Node *node)
{
    while(node!=NULL)
    {
    cout<<node->data<<" ";
    node = node->next;
    }
}
 
int main()
{
    Node* head = NULL;
    Node* a = NULL;
    Node* b = NULL;
     
    /* 0->1->2->3->4->5 */
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);                                
    push(&head, 0);
     
    cout<<"Original linked List: ";
    printList(head);
     
    alternatingSplit(head, &a, &b);
     
    cout<<"\nResultant Linked List 'a' : ";
    printList(a);        
     
    cout<<"\nResultant Linked List 'b' : ";
    printList(b);        
     
    return 0;
}