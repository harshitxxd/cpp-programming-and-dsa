/*
 * File: transform_to_sum_tree.cpp
 * Description: Transforms each node in a binary tree to store the sum of its own
 *              value plus all values in its left and right subtrees.
 *
 * Time Complexity: O(n) - post-order traversal visits each node once.
 * Space Complexity: O(h) - recursion call stack depth bounded by tree height h.
 *
 */

#include <iostream>
#include <vector>
#include <queue>
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
    if (idx >= (int)preorder.size() || preorder[idx] == -1) {
        return NULL;
    }

    node* root = new node(preorder[idx]);
    root->left = buildtree(preorder);
    root->right = buildtree(preorder);
    return root;
}

void printPreorder(node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << ' ';
    printPreorder(root->left);
    printPreorder(root->right);
}

int sumtree(node* root) {
    if (root == NULL) {
        return 0;
    }

    int sumleft = sumtree(root->left);
    int sumright = sumtree(root->right);

    root->data += sumleft + sumright;
    return root->data;
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    idx = -1;
    node* root = buildtree(preorder);
    sumtree(root);
    printPreorder(root);
    cout << endl;
    return 0;
}
