// Program to check if the linked list has loop or not

// Floyd’s Cycle-Finding Algorithm
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

bool isLoopThere(Node** head){
    Node* fast = *head, *slow = *head;
    if(*head == NULL)
        return false;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            return true;
    }

    return false;
}

int main(){
    Node one = Node(1);
    Node two = Node(2);
    Node three = Node(3);
    Node four = Node(4);
    Node five = Node(5);

    Node* head = &one;
    one.next = &two;
    two.next = &three;
    three.next = &four;
    four.next = &five;
    five.next = &two;

    isLoopThere(&head) ? cout << "Yes" : cout << "No";
    cout << endl;
}