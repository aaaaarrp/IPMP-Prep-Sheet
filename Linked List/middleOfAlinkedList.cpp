// Program to Find the middle of a given linked list

// Count no of nodes and then traverse till half
// Time: O(n) - Space: O(1)

//1->2->3->4->5  :3
//1->2->3->4->5->6  :4

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

    Node* temp = head;
    int len = 0;

    while(temp != NULL){
        temp = temp->next;
        len++;
    }

    int i = 1;
    while(i<=len/2){
        head = head->next;
        i++;
    }
        
    cout << head->data << endl;
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