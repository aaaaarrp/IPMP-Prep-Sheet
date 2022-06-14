// Program to reverse the linked list by changing the links between nodes

// Using stack
// Time complexity: O(n) : Space complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void reverse(Node** head){
    stack<Node*> st;
    Node* temp = *head;
    while(temp->next != NULL){
        st.push(temp);
        temp = temp->next;
    }
    *head = temp;
    while(!st.empty()){
        temp->next = st.top();
        st.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

void insert_back(Node** head, int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;

    if(*head == NULL){
        *head = new_node;
        return;
    }
    else {
        Node* last_node = *head;
        while(last_node->next != NULL){
            last_node = last_node->next;
        }
        last_node->next = new_node;
        return;
    }

}

void printlist(Node* head){
    Node* temp = head;
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node* head = NULL;
    insert_back(&head, 1);
    insert_back(&head, 2);
    insert_back(&head, 3);
    insert_back(&head, 4);
    cout << "Given linked list\n";
    printlist(head);
    reverse(&head);
    cout << "\nReversed linked list\n";
    printlist(head);
    return 0;
}