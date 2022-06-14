// Program to reverse the linked list by changing the links between nodes

// Tail Recursive method 
// Time Complexity: O(n) - Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void reverseLL(Node* curr, Node* prev, Node** head){
    if(!curr->next){
        *head = curr;
        curr->next = prev;
        return;
    }
    Node* next = curr->next;
    curr->next = prev;
    reverseLL(next, curr, head);
}

void reverse(Node** head){
    if(!head)
        return;
    reverseLL(*head, NULL, head);
}

Node* newNode(int data){
    struct Node* new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void printlist(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);
    head1->next->next->next->next->next = newNode(6);
    head1->next->next->next->next->next->next = newNode(7);
    head1->next->next->next->next->next->next->next = newNode(8);

    cout << "Given linked list: ";
    printlist(head1);

    reverse(&head1);

    cout << "Reversed linked list: ";
    printlist(head1);

    return 0;

}