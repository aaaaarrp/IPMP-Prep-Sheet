// Program to check if a singly linked list is palindrome

// Find middle
// Reverse the second half
// Compare first half and reversed second half
// Reverse the second half again to construct the original linked list

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

void reverse(Node** head){
    Node* prev = NULL, *curr = *head, *next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next; 
    }
    *head = prev;
}

bool compare(Node* head1, Node* head2){
    Node* temp1 = head1, *temp2 = head2;
    while(temp1 && temp2){
        if(temp1->data == temp2->data){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
            return 0;
    }

    if(!temp1 && !temp2)
        return 1;
    return 0;
}

bool isPalindrome(Node* head){
    Node *slow = head, *fast = head;
    Node *second_half, *prev_of_slow = head;
    Node* midnode = NULL;

    bool res = true;

    if(head != NULL){
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            prev_of_slow = slow;
            slow = slow->next;
        }
    }

    if(fast != NULL){   // in case list is odd
        midnode = slow;
        slow = slow->next;
    }

    second_half = slow;
    prev_of_slow->next = NULL;    // NULL terminate of first half
    reverse(&second_half);
    res = compare(head, second_half);
    reverse(&second_half);

    if(midnode != NULL){    // odd case
        prev_of_slow-> next = midnode;
        midnode->next = second_half;
    }else
        prev_of_slow->next = second_half;   // even case
    
    return res;
    
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