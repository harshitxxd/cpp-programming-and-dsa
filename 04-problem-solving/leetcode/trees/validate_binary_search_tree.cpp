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
public:
    // Time Complexity: O(n)
    // Space Complexity: O(h) for the recursion stack.
    bool helper(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (root == nullptr) {
            return true;
        }
        if (minNode != nullptr && root->val <= minNode->val) {
            return false;
        }
        if (maxNode != nullptr && root->val >= maxNode->val) {
            return false;
        }

        return helper(root->left, minNode, root) &&
               helper(root->right, root, maxNode);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, nullptr, nullptr);
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

    vector<optional<int>> levelOrder1 = {2, 1, 3};
    TreeNode* root1 = buildTree(levelOrder1);
    cout << "Example 1: " << (solution.isValidBST(root1) ? "true" : "false") << '\n';
    deleteTree(root1);

    vector<optional<int>> levelOrder2 = {5, 1, 4, nullopt, nullopt, 3, 6};
    TreeNode* root2 = buildTree(levelOrder2);
    cout << "Example 2: " << (solution.isValidBST(root2) ? "true" : "false") << '\n';
    deleteTree(root2);

    TreeNode* minValueRoot = new TreeNode(numeric_limits<int>::min());
    minValueRoot->right = new TreeNode(numeric_limits<int>::max());
    cout << "Integer bounds: "
         << (solution.isValidBST(minValueRoot) ? "true" : "false") << '\n';
    deleteTree(minValueRoot);

    return 0;
}
