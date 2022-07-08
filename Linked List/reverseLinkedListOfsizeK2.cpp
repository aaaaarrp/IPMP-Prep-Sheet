// Program to reverse a linked list in groups of given size

// Time: O(n) - Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *reverse(Node *head, int k)
{
    Node* curr = head, *prev = NULL, *next = NULL;
    Node* tail = NULL, *join = NULL, *new_head = NULL;
    int count = 0;

    while(curr){
        count = k;
        join = curr;
        prev = NULL;

        while(curr && count--){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        if(!new_head)
            new_head = prev;

        if(tail)
            tail->next = prev;
        
        tail = join;
    } 
    return new_head;
}

void push(Node **head_ref, int new_data)
{
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

int main()
{

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
