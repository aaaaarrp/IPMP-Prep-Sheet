// Program to Determine if a tree is height balanced or not

// Optimized solution
// Time: O(n)

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

int dfsHeight(node* root){
    if(!root)
        return 0;

    int lh = dfsHeight(root->left);
    if(lh == -1)
        return -1;
         
    int rh = dfsHeight(root->right);
    if(rh == -1)
        return -1;
    
    if(abs(lh-rh) > 1)
        return -1;
    
    return max(lh, rh)+1;
}

bool isBalanced(node *root){
    if(dfsHeight(root) != -1)
        return true;
    else
        return false;
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    // root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    if (isBalanced(root))
        cout << "Tree is balanced" << endl;
    else
        cout << "Tree is not balanced" << endl;

    return 0;
}