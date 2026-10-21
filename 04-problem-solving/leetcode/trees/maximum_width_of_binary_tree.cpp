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
        queue<pair<TreeNode*, unsigned long long>> q;
        if (root == nullptr) {
            return 0;
        }

        q.push({root, 0});
        unsigned long long maxwidth = 0;

        while (!q.empty()) {
            size_t currlevelsize = q.size();
            unsigned long long stidx = q.front().second;
            unsigned long long endidx = q.back().second;
            maxwidth = max(maxwidth, endidx - stidx + 1);

            for (size_t i = 0; i < currlevelsize; i++) {
                auto curr = q.front();
                q.pop();

                if (curr.first->left) {
                    q.push({curr.first->left, curr.second * 2 + 1});
                }
                if (curr.first->right) {
                    q.push({curr.first->right, curr.second * 2 + 2});
                }
            }
        }

        return static_cast<int>(maxwidth);
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
