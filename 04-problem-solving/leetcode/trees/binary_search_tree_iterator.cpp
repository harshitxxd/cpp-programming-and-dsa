/*
 * File: binary_search_tree_iterator.cpp
 * Description: Iterates over a binary search tree in inorder using a stack.
 *
 * Time Complexity: O(1) amortized per next() call and O(1) for hasNext().
 * Space Complexity: O(h) - the stack stores at most one path from root to leaf.
 *
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

static int idx = -1;

TreeNode* buildTree(const vector<int>& preorder) {
    idx++;
    if (idx >= static_cast<int>(preorder.size()) || preorder[idx] == -1) {
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

class BSTIterator {
    stack<TreeNode*> nodes;

    void storeLeftNodes(TreeNode* root) {
        while (root != NULL) {
            nodes.push(root);
            root = root->left;
        }
    }

public:
    explicit BSTIterator(TreeNode* root) {
        storeLeftNodes(root);
    }

    // Time Complexity: O(1) amortized.
    int next() {
        TreeNode* current = nodes.top();
        nodes.pop();
        storeLeftNodes(current->right);
        return current->val;
    }

    // Time Complexity: O(1).
    bool hasNext() const {
        return !nodes.empty();
    }
};

void deleteTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // Example 1: root = [7,3,15,null,null,9,20]
    vector<int> preorder = {7, 3, -1, -1, 15, 9, -1, -1, 20, -1, -1};
    idx = -1;
    TreeNode* root = buildTree(preorder);

    BSTIterator iterator(root);
    cout << "Example 1: ";
    cout << iterator.next() << ", ";
    cout << iterator.next() << ", ";
    cout << (iterator.hasNext() ? "true" : "false") << ", ";
    cout << iterator.next() << ", ";
    cout << (iterator.hasNext() ? "true" : "false") << ", ";
    cout << iterator.next() << ", ";
    cout << (iterator.hasNext() ? "true" : "false") << ", ";
    cout << iterator.next() << ", ";
    cout << (iterator.hasNext() ? "true" : "false") << '\n';

    deleteTree(root);
    return 0;
}
