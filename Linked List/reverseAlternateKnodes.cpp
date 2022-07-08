// Program to reverse alternate k nodes in a linked list

// Time Complexity: O(n) - Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

Node* _kAltReverse(Node* head, int k, bool flag){
    if(head == NULL)
        return NULL;

    Node* curr = head, *prev = NULL, * next;
    int count = 1;

    while(curr && count <= k){
        next = curr->next;
        if(flag == true)
            curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(flag == true){
        head->next = _kAltReverse(curr, k, !flag);
        return prev;
    } else {
        prev->next = _kAltReverse(curr, k, !flag);
        return head;
    }
}

Node *kAltReverse(Node *head, int k){
    return _kAltReverse(head, k, true);
}

void push(Node **head_ref, int new_data){
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node *node){
    int count = 0;
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
        count++;
    }
}

int main(void){
    Node *head = NULL;
    int i;

    // 1->2->3->4->5...... ->20
    for (i = 20; i > 0; i--)
        push(&head, i);

    cout << "Given linked list \n";
    printList(head);
    head = kAltReverse(head, 3);

    cout << "\n Modified Linked list \n";
    printList(head);
    return (0);
}


