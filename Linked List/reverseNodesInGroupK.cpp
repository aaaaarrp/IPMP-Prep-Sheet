/* Program to reverse a linked list in groups of given size k
If the number of nodes is not a multiple of k then left-out nodes,
in the end, should remain as it is.     */

// Time: O(n) - Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int num;
    node *next;
    node(int a)
    {
        num = a;
        next = NULL;
    }
};

void insertNode(node *&head, int val){
    node *newNode = new node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return;
}

int length(node* head){
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}

node *reverseKNodes(node *head, int k){
    if(head == NULL)
        return NULL;
        
    node *curr = head, *prev = NULL, *next = NULL;
    node *tail = NULL, *join = NULL, *new_head = NULL;
    int count = 0;
    int len = length(head);

    while (len >= k)
    {
        count = k;
        join = curr;
        prev = NULL;

        while (curr && count--)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        if (!new_head)
            new_head = prev;

        if (tail)
            tail->next = prev;

        tail = join;
        len = len-k;
    }
    if(next)
        tail->next = next;

    return new_head;
}

void printLinkedList(node *head){
    while (head->next != NULL)
    {
        cout << head->num << "->";
        head = head->next;
    }
    cout << head->num << "\n";
}

int main(){
    node *head = NULL;
    int k = 3;
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    insertNode(head, 6);
    insertNode(head, 7);
    insertNode(head, 8);

    cout << "Original Linked List: ";
    printLinkedList(head);
    cout << "After Reversal of k nodes: ";
    node *newHead = reverseKNodes(head, k);
    printLinkedList(newHead);

    return 0;
}