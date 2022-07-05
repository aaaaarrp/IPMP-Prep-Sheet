// Program to print bottom view of a tree

// Time: O(n) - Space: O(n)

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

vector<int> bottomView(node *root)
{
    vector<int> ans;
    if(root == NULL)
        return ans;
    map<int, int> map; // line - value
    queue<pair<node*, int>> q;  // node - line
    q.push({root, 0});

    while(!q.empty()){
        auto i = q.front();
        q.pop();
        node* temp = i.first;
        int line = i.second;
        map[line] = temp->val;
        if(temp->left)
            q.push({temp->left, line-1});
        if(temp->right)
            q.push({temp->right, line+1}); 
    }
    for(auto it: map){
        ans.push_back(it.second);
    }
    return ans;
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

    vector<int> res = bottomView(root);
    for(auto i:res)
        cout << i << " ";

    return 0;
}