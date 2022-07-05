// Program to find the lowest common ancestor in a Binary Tree

// Time: O(n) 

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
    newNode->left = newNode->right = NULL;

    return newNode;
}

node* lowestCommonAncestor(node* root, int p, int q){
    if(root == NULL || root->data == p || root->data == q)
        return root;

    node* left = lowestCommonAncestor(root->left, p, q);
    node* right = lowestCommonAncestor(root->right, p, q);

    if(left == NULL)
        return right;
    else if(right == NULL)
        return left;
    else
        return root;
}

int main(){
    /*        
                1
              /  \
            2     3
          /  \
        4     5
            /
          6

    */
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);

    node *LCA = lowestCommonAncestor(root, 4, 6); 
    cout << LCA->data << endl;

    return 0;
}