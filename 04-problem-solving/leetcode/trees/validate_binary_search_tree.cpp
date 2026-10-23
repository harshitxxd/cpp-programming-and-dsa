/*
 * File: validate_binary_search_tree.cpp
 * Description: Checks whether every node in a binary tree satisfies the
 *              strict lower and upper bounds required for a valid BST.
 *
 * Time Complexity: O(n) - each of the n nodes is checked once.
 * Space Complexity: O(h) - recursive call stack, where h is the tree height.
 *
 */

#include <iostream>
#include <limits>
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
    if (idx >= (int)preorder.size() || preorder[idx] == -1) {
        return NULL;
    }
    TreeNode* root = new TreeNode(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(h) for the recursion stack.
    bool helper(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (root == NULL) {
            return true;
        }
        if (minNode != NULL && root->val <= minNode->val) {
            return false;
        }
        if (maxNode != NULL && root->val >= maxNode->val) {
            return false;
        }

        return helper(root->left, minNode, root) &&
               helper(root->right, root, maxNode);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
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
    Solution solution;

    // Example 1: root = [2, 1, 3]
    vector<int> preorder1 = {2, 1, -1, -1, 3, -1, -1};
    idx = -1;
    TreeNode* root1 = buildTree(preorder1);
    cout << "Example 1: " << (solution.isValidBST(root1) ? "true" : "false") << '\n';
    deleteTree(root1);

    // Example 2: root = [5, 1, 4, null, null, 3, 6]
    vector<int> preorder2 = {5, 1, -1, -1, 4, 3, -1, -1, 6, -1, -1};
    idx = -1;
    TreeNode* root2 = buildTree(preorder2);
    cout << "Example 2: " << (solution.isValidBST(root2) ? "true" : "false") << '\n';
    deleteTree(root2);

    // Example 3: root = [INT_MIN, null, INT_MAX]
    vector<int> preorder3 = {numeric_limits<int>::min(), -1, numeric_limits<int>::max(), -1, -1};
    idx = -1;
    TreeNode* root3 = buildTree(preorder3);
    cout << "Integer bounds: "
         << (solution.isValidBST(root3) ? "true" : "false") << '\n';
    deleteTree(root3);

    return 0;
}
