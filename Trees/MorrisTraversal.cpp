// Program for Morris Traversal

// Time: O(n) - Space: O(1)

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

vector<int> getPreorder(node* root){
    vector<int> preorder;
    node* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            preorder.push_back(curr->val);
            curr = curr->right;
        }
        else {
            node* prev = curr->left;
            while(prev->right && prev->right != curr){
                prev = prev->right;
            }
            if(prev->right == NULL){
                prev->right = curr;
                preorder.push_back(curr->val);
                curr = curr->left;
            }
            else {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return preorder;
}

vector<int> getInorder(node *root){
    vector<int> inorder;
    node* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        else {
            node* prev = curr->left;
            while(prev->right && prev->right != curr){
                prev = prev->right;
            }
            if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
            }
            else {
                prev->right = NULL;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return inorder;
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);

     vector<int> in = getInorder(root);
     vector<int> pre = getPreorder(root);

     cout << "PreOrder: ";
     for (auto i : pre)
         cout << i << " ";

     cout << "\nInOrder: ";
     for (auto i : in)
         cout << i << " ";

     return 0;
}