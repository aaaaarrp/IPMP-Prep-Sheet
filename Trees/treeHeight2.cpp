// Program to Find the Maximum Depth or Height of a Tree

// Using Level Order Traversal
// Time Complexity: O(N) - Auxiliary Space : O(N)

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

int height(node *root){
    if(!root)
        return 0;
    queue<node*> q;
    q.push(root);
    int level = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            node* temp = q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        level++;
    }
    return level;
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);

    cout << height(root) << endl;
    return 0;
}