// Program to create and return a new list representing the intersection of the two given sorted linked lists.

// Recursive solution
// Time Complexity: O(m+n) - Auxiliary Space: O(max(m,n))

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node** head, int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void printList(Node* node){
    while (node != NULL) {
        cout << node->data <<" ";
        node = node->next;
    }
}

Node* sortedIntersect(Node* head1, Node* head2){
    if(!head1 || !head2)
        return NULL;
    
    if(head1->data < head2->data)
        return sortedIntersect(head1->next, head2);
    if(head1->data > head2->data)
        return sortedIntersect(head1, head2->next);
    
    Node* temp = new Node();
    temp->data = head1->data;
    temp->next = sortedIntersect(head1->next, head2->next);
    
    return temp;
}

int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* intersect = NULL;
 
    // 1->2->3->4->5->6 
    push(&head1, 6);
    push(&head1, 5);
    push(&head1, 4);
    push(&head1, 3);
    push(&head1, 2);
    push(&head1, 1);
 
    // 2->4->6->8 
    push(&head2, 8);
    push(&head2, 6);
    push(&head2, 4);
    push(&head2, 2);
 
    intersect = sortedIntersect(head1, head2);
    printList(intersect);
    cout << endl;
}