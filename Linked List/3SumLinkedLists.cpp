// Program to Find a triplet from three linked lists with sum equal to a given number

/* sort list b in ascending order   ->O(nlogn)
   sort list c in descending order  ->O(nlogn)
   pick an element from a and find the pair from b & c  ->O(n*n)
*/

// Time: O(nlogn) + O(nlogn) + O(n*n) = O(n*n)

// This solution is for sorted b & c
// Use merge sort for in case given linked lists are unsorted

#include <bits/stdc++.h>
using namespace std;
 
class Node
{
    public:
    int data;
    Node* next;
};

void push (Node** head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

bool isSumSorted(Node* headA, Node* headB, Node* headC, int num){
    Node* a = headA;

    while(a != NULL){
        Node *b = headB;
        Node* c = headC;

        while(b != NULL && c != NULL){
            int sum = a->data+b->data+c->data;
            if(sum == num){
                cout << "Triplet: " << a->data << " " << b->data << " " << c->data << endl;
                return true; 
            }
            if(sum < num)
                b = b->next;
            else 
                c = c->next;
        }
        a = a->next;
    }
    cout << "Triplet not found" << endl;
    return false;
}

int main(){
    Node* headA = NULL;
    Node* headB = NULL;
    Node* headC = NULL;
 
    /* 10->15->5->20 */
    push (&headA, 20);
    push (&headA, 4);
    push (&headA, 15);
    push (&headA, 10);
 
    /* 2->4->9->10 */
    push (&headB, 10);
    push (&headB, 9);
    push (&headB, 4);
    push (&headB, 2);
 
    /* 8->4->2->1 */
    push (&headC, 1);
    push (&headC, 2);
    push (&headC, 4);
    push (&headC, 8);
 
    int givenNumber = 25;
 
    isSumSorted (headA, headB, headC, givenNumber);
 
    return 0;
}