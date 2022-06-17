// Program to Pairwise swap elements of a given linked list - changing links

// Iterative method
// Time: O(n) - Space: O(1)


#include <bits/stdc++.h>
using namespace std;
 
class Node
{
    public:
    int data;
    Node* next;
};

Node* pairwiseSwap(Node* head){
    if(!head || !head->next)
        return head;
    Node* prev = head;
    Node* curr = head->next;
    head = curr;
    while(true){
        Node* next = curr->next;
        curr->next = prev;
        if(!next || !next->next){
            prev->next = next;
            break;
        }
        prev->next = next->next;
        prev = next;
        curr = prev->next;
    }
    return head;
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
    Node* head = NULL;
    Node* start = NULL;
 
    // 2->3->5->10->15->20
    push(&head, 20);
    push(&head, 15);
    push(&head, 10);
    push(&head, 5);
    push(&head, 3);
    push(&head, 2);
 
    cout << "Linked list "
         << "before calling pairWiseSwap(): ";
    printList(head);
 
    start = pairwiseSwap(head);
 
    cout << "\nLinked list "
         << "after calling pairWiseSwap(): ";
    printList(start);
 
    return 0;
}