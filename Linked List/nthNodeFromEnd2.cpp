// Program to return the value at the n’th node from the end of the Linked List.

/* Using Two Pointers
   -> First move ref pointer to n'th node
   -> Then move ref and main both pointers until ref pointer reaches the end
   -> Then print main pointer's data 
*/

// Time: O(n), n is the length of the linked list

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

void printNthFromLast(struct Node* head, int n){
    struct Node *ref_ptr = head;
    struct Node *main_ptr = head;

    if(head == NULL){
        cout << "List is empty" << endl;
        return;
    }

    for(int i=1; i<n; i++){
        ref_ptr = ref_ptr->next;
        if(ref_ptr == NULL){
            cout << "Not Possible. Enter a valid node no !" << endl;
            return;
        }
    }

    while(ref_ptr != NULL && ref_ptr->next != NULL){
        ref_ptr = ref_ptr->next;
        main_ptr = main_ptr->next;
    }
    cout << main_ptr->data << endl;
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