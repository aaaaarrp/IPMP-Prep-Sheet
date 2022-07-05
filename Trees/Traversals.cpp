// Program to print Preorder Inorder Postorder Traversals in One Traversal

// Time: O(3*N) - Space: O(4*N)

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

void PreInPostTraversals(node *root, vector<int> &pre, vector<int> &in, vector<int> &post){
    stack<pair<node*, int>> st;
    st.push({root,1});
    if(root == NULL)
        return;
    
    while(!st.empty()){
        auto it = st.top();
        st.pop();

        if(it.second == 1){
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->left)
                st.push({it.first->left, 1});
        }
        else if(it.second == 2){
            in.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->right)
                st.push({it.first->right, 1});
        }
        else
            post.push_back(it.first->val);
    }
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);

    vector<int> pre,in,post;
    PreInPostTraversals(root,pre,in,post);

    cout << "PreOrder: ";
    for(auto i:pre)
        cout << i << " ";
    
    cout << "\nInOrder: ";
    for(auto i: in)
        cout << i << " ";
    
    cout << "\nPostOrder: ";
    for(auto i: post)
        cout << i << " ";

    return 0;
}