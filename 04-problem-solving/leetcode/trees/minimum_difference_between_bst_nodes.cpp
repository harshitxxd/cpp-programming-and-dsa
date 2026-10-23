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
#include <optional>
#include <queue>
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

TreeNode* buildTree(const vector<optional<int>>& levelOrder) {
    if (levelOrder.empty() || !levelOrder[0].has_value()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(*levelOrder[0]);
    queue<TreeNode*> nodes;
    nodes.push(root);
    size_t index = 1;

    while (index < levelOrder.size() && !nodes.empty()) {
        TreeNode* current = nodes.front();
        nodes.pop();

        if (levelOrder[index].has_value()) {
            current->left = new TreeNode(*levelOrder[index]);
            nodes.push(current->left);
        }
        index++;

        if (index < levelOrder.size() && levelOrder[index].has_value()) {
            current->right = new TreeNode(*levelOrder[index]);
            nodes.push(current->right);
        }
        index++;
    }

    return root;
}

class Solution {
    TreeNode* prev = nullptr;

    int traverseInorder(TreeNode* root) {
        if (root == nullptr) {
            return INT_MAX;
        }

        int ans = INT_MAX;
        if (root->left != nullptr) {
            int leftmin = traverseInorder(root->left);
            ans = min(ans, leftmin);
        }

        if (prev != nullptr) {
            ans = min(ans, root->val - prev->val);
        }

        prev = root;

        if (root->right != nullptr) {
            int rightmin = traverseInorder(root->right);
            ans = min(ans, rightmin);
        }
        return ans;
    }

public:
    // Time Complexity: O(n)
    // Space Complexity: O(h) for the recursion stack.
    int minDiffInBST(TreeNode* root) {
        prev = nullptr;
        return traverseInorder(root);
    }
};

void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Solution solution;

    vector<optional<int>> levelOrder1 = {4, 2, 6, 1, 3};
    TreeNode* root1 = buildTree(levelOrder1);
    cout << "Example 1: " << solution.minDiffInBST(root1) << '\n';
    deleteTree(root1);

    vector<optional<int>> levelOrder2 = {1, 0, 48, nullopt, nullopt, 12, 49};
    TreeNode* root2 = buildTree(levelOrder2);
    cout << "Example 2: " << solution.minDiffInBST(root2) << '\n';
    deleteTree(root2);

    return 0;
}
