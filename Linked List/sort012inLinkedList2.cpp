// Program to Sort a linked list of 0s, 1s and 2s -> Changing links

// Take 3 pointers zero, one, two
// compare data and make three diff list by connecting next
// connect these three list

// Time: O(n) - Space: O(1)

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

Node* newNode(int data){
    Node* newNode = new Node;

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void printList(struct Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

Node* sortList(Node* head){
    if(!head || !head->next)
        return head;

    Node* zeroD = newNode(0);
    Node* oneD = newNode(0);
    Node* twoD = newNode(0);

    Node *zero = zeroD, *one = oneD, *two = twoD;

    Node* curr = head;
    while(curr){
        if(curr->data == 0){
            zero->next = curr;
            zero = zero->next;
            curr = curr->next;
        }
        else if(curr->data == 1){
            one->next = curr;
            one = one->next;
            curr = curr->next;
        }
        else {
            two->next = curr;
            two = two->next;
            curr = curr->next;
        }
    }
    zero->next = (oneD->next) ? oneD->next : twoD->next;
    one->next = twoD->next;
    two->next = NULL;

    head = zeroD->next;

    delete zeroD;
    delete oneD;
    delete twoD;

    return head;

}

int main(void)
{
    // 1->2->4->5
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(0);
    head->next->next->next = newNode(1);
 
    printf("Linked List Before Sorting: ");
    printList(head);
 
    head = sortList(head);
 
    printf("Linked List After Sorting: ");
    printList(head);
 
    return 0;
}