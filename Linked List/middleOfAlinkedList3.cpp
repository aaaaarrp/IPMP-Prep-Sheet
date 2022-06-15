// Program to Find the middle of a given linked list

// Take a counter = 0, mid = head
// Travers the list
// move mid only when the counter is odd
// This way mid will move till only half

// Time: O(n) - Space: O(1)


#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val){
        data = val;
    }

};

void middle(Node* head){
    Node* mid = head;
    int counter = 0;

    while(head != NULL){
        if(counter%2 == 0)
            mid = mid->next;
        head = head->next;
        counter++;
        
    }
    if(mid != NULL)
        cout << mid->data << endl;
}


int main(){
    Node one =  Node(1);
    Node two = Node(2);
    Node three = Node(3);
    Node four = Node(4);
    Node five = Node(5);
    Node six = Node(6);

    six.next = NULL;
    five.next = &six;
    one.next = &two;
    two.next = &three;
    three.next = &four;
    four.next =  &five;   
    Node* head = &one;
 
    middle(&one);
 
return 0;
}