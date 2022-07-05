// Program to print boundary nodes of the binary tree Anti-Clockwise starting from the root

// Time: O(n) - Space: O(n)

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
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool isLeaf(node* root){
    return !root->left && !root->right;
}

void addLeftBoundary(node* root, vector<int> &res){
    node* curr = root->left;

    while(curr){
        if(!isLeaf(curr))
            res.push_back(curr->data);
        if(curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void addRightBoundary(node* root, vector<int> &res){
    node* curr = root->right;
    stack<int> st;

    while(curr){
        if(!isLeaf(curr))
            st.push(root->data);
        if(curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
}

void addLeaves(node* root, vector<int> &res){
    if(isLeaf(root))
        res.push_back(root->data);

    if(root->left)
        addLeaves(root->left, res);
    if(root->right)
        addLeaves(root->right, res);
}

vector<int> boundaryTraversal(node* root){
    vector<int> res;
    if(root == NULL)
        return res;
    
    if(!isLeaf(root))
        res.push_back(root->data);
    
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

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

    vector<int> result = boundaryTraversal(root);
    for(auto it:result)
        cout << it << " ";

    return 0;
}