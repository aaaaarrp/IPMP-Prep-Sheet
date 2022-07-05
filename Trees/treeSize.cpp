// Program to calculate the size of a tree

// Time: O(N) - Auxiliary: O(N)

#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* newNode(int x){
    node* newNode = new node();
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int size(node *node){
    if(node == NULL)
        return 0;
    return (size(node->left)+1+size(node->right));
}

int main(){
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << size(root) << endl;
    return 0;
}