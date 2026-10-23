/*
 * File: minimum_difference_between_bst_nodes.cpp
 * Description: Finds the minimum difference between values of distinct nodes
 *              in a binary search tree using inorder traversal.
 *
 * Time Complexity: O(n) - each of the n nodes is visited once.
 * Space Complexity: O(h) - recursive call stack, where h is the tree height.
 *
 */

#include <climits>
#include <algorithm>
#include <iostream>
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
    TreeNode* prev = NULL;

    int traverseInorder(TreeNode* root) {
        if (root == NULL) {
            return INT_MAX;
        }

        int ans = INT_MAX;
        if (root->left != NULL) {
            int leftmin = traverseInorder(root->left);
            ans = min(ans, leftmin);
        }

        if (prev != NULL) {
            ans = min(ans, root->val - prev->val);
        }

        prev = root;

        if (root->right != NULL) {
            int rightmin = traverseInorder(root->right);
            ans = min(ans, rightmin);
        }
        return ans;
    }

public:
    // Time Complexity: O(n)
    // Space Complexity: O(h) for the recursion stack.
    int minDiffInBST(TreeNode* root) {
        prev = NULL;
        return traverseInorder(root);
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

    // Example 1: root = [4,2,6,1,3]
    vector<int> preorder1 = {4, 2, 1, -1, -1, 3, -1, -1, 6, -1, -1};
    idx = -1;
    TreeNode* root1 = buildTree(preorder1);
    cout << "Example 1: " << solution.minDiffInBST(root1) << '\n';
    deleteTree(root1);

    // Example 2: root = [1,0,48,null,null,12,49]
    vector<int> preorder2 = {1, 0, -1, -1, 48, 12, -1, -1, 49, -1, -1};
    idx = -1;
    TreeNode* root2 = buildTree(preorder2);
    cout << "Example 2: " << solution.minDiffInBST(root2) << '\n';
    deleteTree(root2);

    return 0;
}
