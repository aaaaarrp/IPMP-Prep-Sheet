// Programt to get the Diameter of a Binary Tree

#include<bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node* left;
    node* right; 
};

node* newNode(int x){
    node* newNode = new node();
    newNode->val = x;
    newNode->left = newNode->right = NULL;

    return newNode;
}

int height(node* root, int &diameter){
    if (!root)
        return 0;

    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);

    diameter = max(diameter, lh + rh);

    return 1 + max(lh, rh);
}


int main()
{

    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int diameter = 0;
    cout << "Diameter: " << height(root, diameter);

    return 0;
}