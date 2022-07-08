/* Program for flattening a Linked List

->  Using the Merge() process of merge sort for linked lists.
    We use merge() to merge lists one by one.
    We recursively merge() the current list with the already flattened list.

->  Time complexity: O(N*N*M)
                where N is the no of nodes in main linked list (reachable using right pointer)
                and M is the no of node in a single sub linked list (reachable using down pointer).

->  Space complexity: O(N*M) - because of the recursion. 
                Recursion stack's size equivalent to total number of elements in the lists, which is N*M
                
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *right, *down;
};



Node *merge(Node *a, Node *b){
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
    
    Node* result;
    if(a->data < b->data){
        result = a;
        result->down = merge(a->down, b);
    } else {
        result = b;
        result->down = merge(a, b->down);
    }
    result->right = NULL;
    return result;
}

Node *flatten(Node *root){
    if(root == NULL || root->right == NULL)
        return root;
    root->right = flatten(root->right);
    root = merge(root, root->right);
    return root;
}

Node *push(Node *head_ref, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->right = NULL;
    new_node->down = head_ref;
    head_ref = new_node;

    return head_ref;
}

void printList(Node* head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->down;
    }
    cout << endl;
}

int main()
{
    /*
           5 -> 10 -> 19 -> 28
           |    |     |     |
           7   20    22    35
          |          |     |
          8         50    40
         |                |
        30               45
    */
    
    Node *head = NULL;
    head = push(head, 30);
    head = push(head, 8);
    head = push(head, 7);
    head = push(head, 5);

    head->right = push(head->right, 20);
    head->right = push(head->right, 10);

    head->right->right = push(head->right->right, 50);
    head->right->right = push(head->right->right, 22);
    head->right->right = push(head->right->right, 19);

    head->right->right->right = push(head->right->right->right, 45);
    head->right->right->right = push(head->right->right->right, 40);
    head->right->right->right = push(head->right->right->right, 35);
    head->right->right->right = push(head->right->right->right, 20);

    head = flatten(head);

    printList(head);
    return 0;
}

