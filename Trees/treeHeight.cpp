// Program to Find the Maximum Depth or Height of a Tree

// Recursively calling left & right subtree & maximum of them+1
// Time Complexity: O(N) - Auxiliary Space : O(N)

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *newNode(int x)
{
    node *newNode = new node();
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int height(node *node)
{
    if (node == NULL)
        return 0;
    
    int left = height(node->left);
    int right = height(node->right);
    return max(left,right)+1;
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);

    cout << height(root) << endl;
    return 0;
}