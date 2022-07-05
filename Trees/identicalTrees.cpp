// Program to Determine if Two Trees are Identical

// time: O(m) where, (m < n) & m and n are no of tree nodes

#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

bool identicalTrees(node* root1, node* root2){
    if(!root1 && !root2)
        return 1;
    if(root1 && root2)
        return (root1->data == root2->data 
                && identicalTrees(root1->left, root2->left) 
                && identicalTrees(root1->right, root2->right));
    return 0;
}

int main()
{
    node *root1 = newNode(1);
    node *root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);

    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    if (identicalTrees(root1, root2))
        cout << "Both trees are identical." << endl;
    else
        cout << "Trees are not identical." << endl;

    return 0;
}