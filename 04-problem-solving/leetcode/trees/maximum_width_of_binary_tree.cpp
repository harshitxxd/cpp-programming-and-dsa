/*
 * File: maximum_width_of_binary_tree.cpp
 * Description: Finds the maximum width of a binary tree, counting gaps between
 *              the leftmost and rightmost nodes at each level.
 *
 * Time Complexity: O(n) - each of the n nodes is processed once.
 * Space Complexity: O(n) - the level-order queue can hold up to n nodes.
 *
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
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

TreeNode* buildTree(const vector<int>& levelOrder) {
    if (levelOrder.empty() || levelOrder[0] == INT_MIN) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(levelOrder[0]);
    queue<TreeNode*> nodes;
    nodes.push(root);
    size_t i = 1;

    while (i < levelOrder.size() && !nodes.empty()) {
        TreeNode* current = nodes.front();
        nodes.pop();

        if (levelOrder[i] != INT_MIN) {
            current->left = new TreeNode(levelOrder[i]);
            nodes.push(current->left);
        }
        i++;

        if (i < levelOrder.size() && levelOrder[i] != INT_MIN) {
            current->right = new TreeNode(levelOrder[i]);
            nodes.push(current->right);
        }
        i++;
    }

    return root;
}

class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        using Index = unsigned long long;
        queue<pair<TreeNode*, Index>> nodes;
        nodes.push({root, 0});
        Index maxWidth = 0;

        while (!nodes.empty()) {
            size_t levelSize = nodes.size();
            Index firstIndex = nodes.front().second;
            Index lastIndex = nodes.back().second;
            maxWidth = max(maxWidth, lastIndex - firstIndex + 1);

            for (size_t i = 0; i < levelSize; i++) {
                TreeNode* current = nodes.front().first;
                Index index = nodes.front().second - firstIndex;
                nodes.pop();

                if (current->left != nullptr) {
                    nodes.push({current->left, index * 2});
                }
                if (current->right != nullptr) {
                    nodes.push({current->right, index * 2 + 1});
                }
            }
        }

        return static_cast<int>(maxWidth);
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

    vector<int> levelOrder1 = {1, 3, 2, 5, 3, INT_MIN, 9};
    TreeNode* root1 = buildTree(levelOrder1);
    cout << "Example 1: " << solution.widthOfBinaryTree(root1) << '\n';
    deleteTree(root1);

    vector<int> levelOrder2 = {1, 3, 2, 5, INT_MIN, INT_MIN, 9, 6, INT_MIN, 7};
    TreeNode* root2 = buildTree(levelOrder2);
    cout << "Example 2: " << solution.widthOfBinaryTree(root2) << '\n';
    deleteTree(root2);

    vector<int> levelOrder3 = {1, 3, 2, 5};
    TreeNode* root3 = buildTree(levelOrder3);
    cout << "Example 3: " << solution.widthOfBinaryTree(root3) << '\n';
    deleteTree(root3);

    return 0;
}
