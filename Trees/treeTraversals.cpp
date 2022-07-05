
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

void printPreorder(node* root){
    if(!root)
        return;
    
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(node* root){
    if(!root)
        return;
    
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

void printPostorder(node* root){
    if(!root)
        return;
    
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}


int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);

    cout << "Preorder traversal of binary tree is: ";
    printPreorder(root);

    cout << "\nInorder traversal of binary tree is: ";
    printInorder(root);

    cout << "\nPostorder traversal of binary tree is: ";
    printPostorder(root);

    return 0;
}