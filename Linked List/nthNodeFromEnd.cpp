// Program to return the value at the n’th node from the end of the Linked List.

// Double pointer concept - Print the (len – n + 1)th node from the beginning of the Linked List. 
// Time: O(n) , n is the length of the linked list

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

void printNthFromLast(struct Node* head, int n){
    int len = 0, i;
    struct Node *temp = head;

    while(temp != NULL){
        temp = temp->next;
        len++;
    }

    if(len < n){
        cout << "Not Possible. Enter a valid node no !" << endl;
        return;
    }

    temp = head;

    for(i=1; i<len-n+1; i++){
        temp = temp->next;
    }
        
    cout << temp->data << endl;
    return;
}

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int main(){
    struct Node *head = NULL;
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);    // 35->15->4->20

    printNthFromLast(head, 3);
    
}