// Program to get the intersection point of two Linked Lists

// Using two pointers
// Time Complexity: O(m+n) - Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;
 
class Node {
public:
    int data;
    Node* next;
};

Node* getIntersectionNode(Node* head1, Node* head2){
    Node* first = head1, *second = head2;
    if(!first && !second)
        return NULL;

    while(first != second){
        first = first->next;
        second = second->next;

        if(first == second)
            return first;
        
        if(first == NULL)
            first = head1;
        if(second == NULL)
            second = head2;
    }
    return NULL;
}


int main(){
    Node* newNode;
    
    //      10->
    //           ->15->30->NULL
    // 3->6->9->

    Node* head1 = new Node();
    head1->data = 10;
 
    Node* head2 = new Node();
    head2->data = 3;
 
    newNode = new Node();
    newNode->data = 6;
    head2->next = newNode;
 
    newNode = new Node();
    newNode->data = 9;
    head2->next->next = newNode;
 
    newNode = new Node();
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;
 
    newNode = new Node();
    newNode->data = 30;
    head1->next->next = newNode;
 
    head1->next->next->next = NULL;
 
    Node* node = getIntersectionNode(head1, head2);
    (node == NULL) ? cout << "No intersetion" : cout << node->data;
    cout << endl;
}