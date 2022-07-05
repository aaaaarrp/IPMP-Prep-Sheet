// Program for level order traversal

// Time: O(n) - Space: O(n)

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

void levelOrderTraversal(node* root){
    if(!root)
        return;
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            node* temp = q.front();
            cout << temp->val << " ";
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->left->right->left = newNode(5);

    levelOrderTraversal(root);
    return 0;
}