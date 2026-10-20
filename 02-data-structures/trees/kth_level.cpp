/*
 * File: kth_level.cpp
 * Description: Traverses a binary tree recursively and prints all node values
 *              present at the k-th level (1-indexed).
 *
 * Time Complexity: O(n) - in the worst case visits nodes up to depth k.
 * Space Complexity: O(h) - recursion call stack depth bounded by tree height h.
 *
 */

#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;

// Time Complexity: O(n)
// Space Complexity: O(h) for the recursion stack, where h is the tree height.
node* buildtree(const vector<int>& preorder) {
    idx++;
    if (idx >= static_cast<int>(preorder.size()) || preorder[idx] == -1) {
        return NULL;
    }

    node* root = new node(preorder[idx]);
    root->left = buildtree(preorder);
    root->right = buildtree(preorder);
    return root;
}

void kthlevel(node* root,int k){
    if( root == NULL){
        return ;
    }
    if(k == 1){
        cout << root->data <<" ";
    }

    kthlevel(root->left, k-1);
    kthlevel(root->right,k-1);
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    idx = -1;
    node* root = buildtree(preorder);
    kthlevel(root,3);
    return 0;
}
