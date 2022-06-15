// Program to get the intersection point of two Linked Lists

// count length of both linked list
// get the difference (abs value)
// move the bigger linked list's head till the difference
// now start comparing

// Time Complexity: O(m+n) - Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;
 
class Node {
public:
    int data;
    Node* next;
};

int length(Node* head){
    int len = 0;
    while(head){
        head = head->next;
        len++;
    }
    return len;
}

int intersection(int diff, Node* max_head, Node* min_head){
    for(int i=0; i<diff; i++){
        if(max_head == NULL)
            return -1;
        max_head = max_head->next;
    }

    while(max_head && min_head){
        if(max_head == min_head)
            return max_head->data;
        max_head = max_head->next;
        min_head = min_head->next;
    }
    return -1;
}

int getIntersectionNode(Node* head1, Node* head2){
    int len1 = length(head1);
    int len2 = length(head2);

    int diff;

    if(len1 > len2){
        diff = len1-len2;
        return intersection(diff, head1, head2);
    } else {
        diff = len2 - len1;
        return intersection(diff, head2, head1);
    }
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