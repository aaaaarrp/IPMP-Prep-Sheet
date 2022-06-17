// Program to Merge two sorted linked lists

// Using local reference
// Time Complexity: O(m+n)

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

Node* SortedMerge(Node* head1, Node* head2){
    Node* res = NULL;
    Node** tail = &res;

    while(1){
        if(!head1){
            *tail = head2;
            break;
        }
        else if(!head2){
            *tail = head1;
            break;
        }   
        else if(head1->data <= head2->data)
            moveNode(tail, &head1);
        else 
            moveNode(tail, &head2);
        tail = &((*tail)->next);
    }
    return res;
}

void printList(Node *node)
{
    while (node!=NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
}

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    Node* res = NULL;
    Node* a = NULL;
    Node* b = NULL;
 
    // 5->10->15
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);

    // 2->3->20
    push(&b, 20);
    push(&b, 3);
    push(&b, 2);
 
    res = SortedMerge(a, b);
 
    cout << "Merged Linked List is: \n";
    printList(res);
 
    return 0;
}