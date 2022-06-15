// Program to check if a singly linked list is palindrome

// Using stack
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

bool isPalindrome(Node* head){
    Node* temp = head;
    stack<int> st;

    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    
    while(head != NULL){
        int i = st.top();
        st.pop();
        if(head->data != i)
            return false;
        head = head->next;
    }
    return true;
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
 
    int result = isPalindrome(&one);
   
    if(result == 1)
            cout<<"isPalindrome: true\n";
    else
        cout<<"isPalindrome: false\n";
 
return 0;
}