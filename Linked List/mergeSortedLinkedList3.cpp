// Program to Merge two sorted linked lists

// Using recursion
// Time Complexity: O(m+n) - Space: O(m+n)

#include <bits/stdc++.h>
using namespace std;
 
class Node
{
    public:
    int data;
    Node* next;
};

Node* SortedMerge(Node* head1, Node* head2){
    Node* res = NULL;
    if(!head1)
        return head2;
    if(!head2)
        return head1;
    
    if(head1->data <= head2->data){
        res = head1;
        res->next = SortedMerge(head1->next, head2);
    }
    else{
        res = head2;
        res->next = SortedMerge(head1, head2->next);
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