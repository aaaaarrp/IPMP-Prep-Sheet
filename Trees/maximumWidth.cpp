// Program to find the Maximum Width of A Binary Tree

// Using level order traversal -> Marking nodes by index and the subtracting indexes levelwise (rightmost-leftmost)
// Time: O(n) - Space: O(n)

/*  WHY USING 2LL ?
 2LL guarantee us that answer will definitely exist in the 32 signed integer range, but multiplication can be more than that of, so we used 2LL that makes 2 as of long long type. But since then we already know the answer exists in the 32 signed integer range, so we declare our variables as integer type only.
*/

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

int maximumWidth(node *root){
    if(!root)
        return 0;
    queue<pair<node*,int>> q;
    q.push({root, 0});
    int width = 0;

    while(!q.empty()){
        int size = q.size();
        int min = q.front().second;
        int leftmost,rightmost;
        for(int i=0; i<size; i++){
            int curr_id = q.front().second-min;
            node* temp = q.front().first;
            q.pop();
            if(i == 0)
                leftmost = curr_id;
            if(i == size-1)
                rightmost = curr_id;
            if(temp->left)
                q.push({temp->left, (2LL*curr_id+1)});
            if(temp->right)
                q.push({temp->right, (2LL*curr_id+2)});
        }
        width = max(width, rightmost-leftmost+1);
    }
    return width;
    
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(3);
    root->left->left = newNode(5);
    root->left->left->left = newNode(7);
    root->right = newNode(2);
    root->right->right = newNode(4);
    root->right->right->right = newNode(6);

    cout << maximumWidth(root) << endl;
    

    return 0;
}