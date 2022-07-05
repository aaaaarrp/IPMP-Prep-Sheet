// Program to Determine if a tree is height balanced or not

// Time: O(n^2)
// Space: O(n) space for call stack since using recursion

#include <bits/stdc++.h>
using namespace std;

class node
{
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

int height(node* root){
    if(!root)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);

    return 1+max(lh,rh);
}

bool isBalanced(node *root){
    if(!root)
        return true;
    
    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;

    return false;
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    //root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    if (isBalanced(root))
        cout << "Tree is balanced" << endl;
    else
        cout << "Tree is not balanced" << endl;

    return 0;
}