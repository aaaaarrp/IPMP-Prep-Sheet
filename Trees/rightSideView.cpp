// Program to print the right side view of a binary tree

// Time: O(n) - Space: O(h)

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

void getRightSide(node* root, int level, vector<int> &res){
    if(root == NULL)
        return;
    
    if(res.size() == level)
        res.push_back(root->val);
    
    getRightSide(root->right, level+1, res);
    getRightSide(root->left, level+1, res);
}

vector<int> rightSideView(node *root){
    vector<int> res;
    getRightSide(root, 0, res);
    return res;
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);
    root->right->right = newNode(7);

    vector<int> res = rightSideView(root);
    for (auto i : res)
        cout << i << " ";

    return 0;
}