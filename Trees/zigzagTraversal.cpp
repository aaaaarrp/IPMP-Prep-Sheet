// Program to print ZigZag order traversal of a binary tree

// Time: O(n) - Space: O(n)

#include<bits/stdc++.h>
using namespace std;

struct node{
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

vector<vector<int>> zigzagTraversal(node* root){
    vector<vector<int>> result;
    if(root == NULL)
        return result;
    
    queue<node*> q;
    q.push(root);
    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> row(size);
        for(int i=0; i<size; i++){
            node* temp = q.front();
            q.pop();

            int index = (leftToRight) ? i : size-1-i;
            row[index] = temp->data;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}

int main(){
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(5);
    root->left->right = newNode(4);
    root->left->right->left = newNode(6);

    vector<vector<int>> result = zigzagTraversal(root);
    
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}