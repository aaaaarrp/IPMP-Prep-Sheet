/* Program for flattening a Linked List

->  Using Priority Queues
    The idea is to build min-heap
    then use Extract-min property to get minimum element from priority queue.

->  Time complexity: O(N*N*M)
                where N is the no of nodes in main linked list (reachable using right pointer)
                and M is the no of node in a single sub linked list (reachable using down pointer).

->  Space complexity: O(N).
                where N is the no of nodes in main linked list (reachable using next pointer).

*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

struct mycomp
{
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

void flatten(Node *root)
{
    priority_queue<Node *, vector<Node *>, mycomp> p;
    // pushing main link nodes into priority_queue.
    while (root != NULL)
    {
        p.push(root);
        root = root->next;
    }

    while (!p.empty())
    {
        // extracting min
        auto k = p.top();
        p.pop();
        // printing least element
        cout << k->data << " ";
        if (k->bottom)
            p.push(k->bottom);
    }
}

int main(void)
{
    Node *head = new Node(5);
    auto temp = head;
    auto bt = head;
    bt->bottom = new Node(7);
    bt->bottom->bottom = new Node(8);
    bt->bottom->bottom->bottom = new Node(30);
    temp->next = new Node(10);

    temp = temp->next;
    bt = temp;
    bt->bottom = new Node(20);
    temp->next = new Node(19);
    temp = temp->next;
    bt = temp;
    bt->bottom = new Node(22);
    bt->bottom->bottom = new Node(50);
    temp->next = new Node(28);
    temp = temp->next;
    bt = temp;
    bt->bottom = new Node(35);
    bt->bottom->bottom = new Node(40);
    bt->bottom->bottom->bottom = new Node(45);

    flatten(head);
    cout << endl;
    return 0;
}
