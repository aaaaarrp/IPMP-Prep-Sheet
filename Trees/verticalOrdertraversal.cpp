// Program to for vertical order traversal

// Time: O(N*logN*logN*logN) - Space: O(n)

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

vector<vector<int>> verticalTraversal(node* root){
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<node*, pair<int, int>>> q;
    q.push({root, {0,0}});

    while(!q.empty()){
        auto p = q.front();
        q.pop();
        node* node = p.first;
        int v = p.second.first;
        int l = p.second.second;
        nodes[v][l].insert(node->val);
        if(node->left)
            q.push({node->left, {v-1, l+1}});
        if(node->right)
            q.push({node->right, {v+1, l+1}});
    }

    vector<vector<int>> ans;
    for(auto i:nodes){
        vector<int> col;
        for(auto j:i.second){
            col.insert(col.end(),j.second.begin(), j.second.end());
        }
        ans.push_back(col);
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

    vector<vector<int>> res = verticalTraversal(root);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }

    return 0;
}