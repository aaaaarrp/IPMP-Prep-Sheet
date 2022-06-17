// Program to Swap Kth node from beginning with Kth node from end in a Linked List

// count nodes
// get x and x_prev
// get y & y_prev
// swap

// Time: O(n) - Space: O(1)

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int countNodes(Node* temp){
    int count = 0;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}

void swapKth(Node** head, int k){
    int n = countNodes(*head);

    if(n < k)   
        return;
    if(2*k-1 == n)  // x & y same
        return;
    
    Node* x = *head;
    Node* x_prev = NULL;
    for(int i=1; i<k; i++){
        x_prev = x;
        x = x->next;
    }

    Node* y = *head;
    Node* y_prev = NULL;
    for(int i=1; i<n-k+1; i++){
        y_prev = y;
        y = y->next;
    }

    if(x_prev)
        x_prev->next = y;
    if(y_prev)
        y_prev->next = x;
    
    Node* temp = x->next;
    x->next = y->next;
    y->next = temp;

    if(k == 1)
        *head = y;
    if(k == n)
        *head = x;

}

void push(Node** head, int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void printList(Node* head){
    while(head){
        cout << head->data <<" ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    Node* head = NULL;
    for(int i = 7; i>0; i--)
        push(&head, i);

    cout << "Original List: ";
    printList(head);

    swapKth(&head, 2);
    cout << "Modified List: ";
    printList(head);
}