// Program to Detect and Remove Loop in a Linked List

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void removeLoop(Node* loop_node, Node* head){
    
}

int detectAndRemoveLoop(Node* head){
       
}

void printList(struct Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

struct Node* newnode(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main(){
    struct Node *head = newnode(50);
    head->next = newnode(20);
    head->next->next = newnode(15);
    head->next->next->next = newnode(4);
    head->next->next->next->next = newnode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    detectAndRemoveLoop(head);
 
    cout << "Linked List after removing loop \n";
    printList(head);
    return 0;


}