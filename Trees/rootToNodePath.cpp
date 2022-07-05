// Program to print the nodes from root to leaf path

// Using inorder traversal
// Time: O(n) - Space: O(h) where h is height for recusion stack space

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *left;
    node *right;
};

node *newNode(int x)
{
    node *newNode = new node();
    newNode->val = x;
    newNode->left = newNode->right = NULL;

    return newNode;
}

bool getPath(node* root, vector<int> &arr, int node){
    if(root == NULL)
        return false;
    
    arr.push_back(root->val);

    if(root->val == node)
        return true;

    if(getPath(root->left, arr, node) || getPath(root->right, arr, node))
        return true;

    arr.pop_back();
    return false;
}

vector<int> rootToNodePath(node* root, int node){
    vector<int> arr;
    if(root == NULL)
        return arr;
    getPath(root, arr, node);
    return arr;
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);

    vector<int> res = rootToNodePath(root, 6);
    for(auto i: res)
        cout << i << " ";

    return 0;
}