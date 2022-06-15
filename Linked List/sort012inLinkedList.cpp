// Program to Sort a linked list of 0s, 1s and 2s -> inplace

// count the 0s,1s,2s
// traverse again and fill them
// Time: O(n) - Space: O(1)

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

void sortList(Node* head){
    int count[3] = {0,0,0};  
    Node* temp = head;
    while(temp){
        count[temp->data] += 1;
        temp = temp->next;
    }

    int i = 0;
    temp = head;

    while(temp){
        if(count[i] == 0) 
            i++;
        else{
            temp->data = i;
            count[i]--;
            temp = temp->next;
        }
    }
}

int main(){
    Node *head = NULL;
    push(&head, 0);
    push(&head, 1);
    push(&head, 0);
    push(&head, 2);
    push(&head, 1);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    push(&head, 2);
 
    cout << "\nLinked List Before Sorting: ";
    printList(head);
 
    sortList(head);
 
    cout << "\nLinked List After Sorting: ";
    printList(head);
 
    return 0;
}