// Program to check if the linked list has loop or not

// Brent's Cycle Detection Algorithm (The Teleporting Turtle)
// Time: O(n) - Space: O(1)
// faster than Floyd’s Cycle-Finding Algorithm

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
    if(*head == NULL)
        return false;
    int taken = 0, limit = 2;
    Node* fast = *head, *slow = *head;
    while(fast->next){
        fast = fast->next;
        taken++;
        if(fast == slow)
            return true;
        if(taken == limit){
            taken = 0;
            limit *= 2;
            slow = fast;
        }
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