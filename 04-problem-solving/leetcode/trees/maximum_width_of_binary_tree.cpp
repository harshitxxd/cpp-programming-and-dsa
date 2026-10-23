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

static int idx = -1;

TreeNode* buildTree(const vector<int>& preorder) {
    idx++;
    if (idx >= (int)preorder.size() || preorder[idx] == -1) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
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

    // Example 1: root = [1,3,2,5,3,null,9]
    vector<int> preorder1 = {1, 3, 5, -1, -1, 3, -1, -1, 2, -1, 9, -1, -1};
    idx = -1;
    TreeNode* root1 = buildTree(preorder1);
    cout << "Example 1: " << solution.widthOfBinaryTree(root1) << '\n';
    deleteTree(root1);

    // Example 2: root = [1,3,2,5,null,null,9,6,null,7]
    vector<int> preorder2 = {1, 3, 5, 6, -1, -1, -1, -1, 2, -1, 9, 7, -1, -1, -1};
    idx = -1;
    TreeNode* root2 = buildTree(preorder2);
    cout << "Example 2: " << solution.widthOfBinaryTree(root2) << '\n';
    deleteTree(root2);

    // Example 3: root = [1,3,2,5]
    vector<int> preorder3 = {1, 3, 5, -1, -1, -1, 2, -1, -1};
    idx = -1;
    TreeNode* root3 = buildTree(preorder3);
    cout << "Example 3: " << solution.widthOfBinaryTree(root3) << '\n';
    deleteTree(root3);

    return 0;
}
