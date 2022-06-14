// Program to reverse the linked list by changing the links between nodes

// Using array
// Time complexity: O(n) : Space complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};
 
Node* reverse(Node* head)
{
    Node* temp = head, *temp2 = head;
    long int len = 1;
    while (temp2 != NULL) {
        temp2 = temp2->next;
        len++;
    }

    long int j = 1;
    long int arr[len];
    while (len && temp != NULL) {
        arr[j++] = temp->data;
        temp = temp->next;
        len--;
    }
    j--;

    cout << "\nReversed Linked list: ";
    while (j)
        cout << arr[j--] << " ";
        
    return head;
}

void printll(Node* head){
    Node* temp = head;
    cout << "Given linked list: ";
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

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

int main()
{
    Node* head = NULL;
    insert_back(&head, 1);
    insert_back(&head, 2);
    insert_back(&head, 3);
    insert_back(&head, 4);

    printll(head);
    reverse(head);

    return 0;
}