/*
 * File: flatten_binary_tree_to_linked_list.cpp
 * Description: Flattens a binary tree in place into a right-skewed linked list
 *              following preorder traversal.
 *
 * Time Complexity: O(n) - each node is visited once.
 * Space Complexity: O(h) - recursion stack, where h is the tree height.
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

static int idx = -1;

TreeNode* buildTree(const vector<int>& preorder) {
    idx++;
    if (idx >= static_cast<int>(preorder.size()) || preorder[idx] == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

class Solution {
    TreeNode* nextright = nullptr;

    void flattenReversePreorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        flattenReversePreorder(root->right);
        flattenReversePreorder(root->left);

        root->left = nullptr;
        root->right = nextright;
        nextright = root;
    }

public:
    void flatten(TreeNode* root) {
        nextright = nullptr;
        flattenReversePreorder(root);
    }
};

void printFlattened(TreeNode* root) {
    cout << '[';
    while (root != nullptr) {
        cout << root->val;
        if (root->right != nullptr) {
            cout << ", null, ";
        }
        root = root->right;
    }
    cout << "]\n";
}

void deleteFlattened(TreeNode* root) {
    while (root != nullptr) {
        TreeNode* next = root->right;
        delete root;
        root = next;
    }
}

int main() {
    Solution solution;

    vector<int> preorder1 = {1, 2, 3, -1, -1, 4, -1, -1, 5, -1, 6, -1, -1};
    idx = -1;
    TreeNode* root1 = buildTree(preorder1);
    solution.flatten(root1);
    cout << "Example 1: ";
    printFlattened(root1);
    deleteFlattened(root1);

    vector<int> preorder2;
    idx = -1;
    TreeNode* root2 = buildTree(preorder2);
    solution.flatten(root2);
    cout << "Example 2: ";
    printFlattened(root2);
    deleteFlattened(root2);

    vector<int> preorder3 = {0, -1, -1};
    idx = -1;
    TreeNode* root3 = buildTree(preorder3);
    solution.flatten(root3);
    cout << "Example 3: ";
    printFlattened(root3);
    deleteFlattened(root3);

    return 0;
}
