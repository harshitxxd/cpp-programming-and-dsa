/*
 * File: identical_tree.cpp
 * Description: Checks whether two binary trees are structurally identical and
 *              contain identical node values at corresponding positions.
 *
 * Time Complexity: O(min(n1, n2)) - visits nodes of both trees simultaneously until mismatch or termination.
 * Space Complexity: O(min(h1, h2)) - recursion stack bounded by the smaller tree height.
 *
 */

#include <iostream>
#include <vector>
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
// Space Complexity: O(h) for the recursion stack, where h is tree height.
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

// Time Complexity: O(min(n1, n2))
// Space Complexity: O(min(h1, h2))
bool isIdentical(node* r1, node* r2) {
    if (r1 == NULL || r2 == NULL) {
        return r1 == r2;
    }

    return (r1->data == r2->data) &&
           isIdentical(r1->left, r2->left) &&
           isIdentical(r1->right, r2->right);
}

int main() {
    // Tree 1: 1 -> 2, 3
    vector<int> preorder1 = {1, 2, -1, -1, 3, -1, -1};
    idx = -1;
    node* root1 = buildtree(preorder1);

    // Tree 2: 1 -> 2, 3 (identical to Tree 1)
    vector<int> preorder2 = {1, 2, -1, -1, 3, -1, -1};
    idx = -1;
    node* root2 = buildtree(preorder2);

    // Tree 3: 1 -> 2 (different structure)
    vector<int> preorder3 = {1, 2, -1, -1, -1};
    idx = -1;
    node* root3 = buildtree(preorder3);

    cout << "Tree 1 and Tree 2 identical: " << (isIdentical(root1, root2) ? "true" : "false") << endl;
    cout << "Tree 1 and Tree 3 identical: " << (isIdentical(root1, root3) ? "true" : "false") << endl;

    return 0;
}

