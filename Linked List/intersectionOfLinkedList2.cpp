// Program to get the intersection point of two Linked Lists

// Using hashing
// This method requires O(n) additional space and not very efficient if one list is large.

#include <bits/stdc++.h>
using namespace std;
 
class Node {
public:
    int data;
    Node* next;
};

int getIntersectionNode(Node* head1, Node* head2){
    unordered_set<Node*> hash;
    int node;
    while(head1){
        hash.insert(head1);
        head1 = head1->next;
    }
    while(head2){
        if(hash.find(head2) != hash.end()){
            node = head2->data;
            break;
        }
        head2 = head2->next;
    }
    return node;
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
 
    cout << "The node of intersection is: " << getIntersectionNode(head1, head2) << endl;
}