// Program to check if a singly linked list is palindrome

// Using two pointers with recursion

// Time: O(n) - Space: O(n)

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val){
        data = val;
    }

};

bool isPalindromeUtil(Node** left, Node* right){
    if(right == NULL)
        return true;
    
    bool isp = isPalindromeUtil(left, right->next); // sublist checking
    if(isp == false)
        return false;
    
    bool isp1 = (right->data == (*left)->data); // value checking
    *left = (*left)->next;
    return isp1;
}

bool isPalindrome(Node* head){
    return isPalindromeUtil(&head, head);
}

int main(){
    Node one =  Node(1);
    Node two = Node(2);
    Node three = Node(3);
    Node four = Node(2);
    Node five = Node(1);

    five.next = NULL;
    one.next = &two;
    two.next = &three;
    three.next = &four;
    four.next = &five;
    Node* head = &one;
 
    int result = isPalindrome(head);
   
    if(result == 1)
            cout<<"isPalindrome: true\n";
    else
        cout<<"isPalindrome: false\n";
 
return 0;
}