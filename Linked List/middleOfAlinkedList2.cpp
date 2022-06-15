// Program to Find the middle of a given linked list

// Using two pointers, slow moves 1x, fast moves 2x
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
    Node* slow = head;
    Node* fast = head;

    if(head != NULL){
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << slow->data << endl;
    }

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