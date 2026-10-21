/*
 * File: binary_tree_inorder_traversal.cpp
 * Description: Returns the inorder traversal of a binary tree using Morris
 *              traversal, which temporarily threads and restores tree links.
 *
 * Time Complexity: O(n) - each node and temporary thread is processed a
 *                  constant number of times.
 * Space Complexity: O(1) auxiliary space, excluding the returned vector.
 *
 */

#include <climits>
#include <iostream>
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
    // Space Complexity: O(1) auxiliary space.
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* IP = curr->left;
                while (IP->right != nullptr && IP->right != curr) {
                    IP = IP->right;
                }

                if (IP->right == nullptr) {
                    IP->right = curr;
                    curr = curr->left;
                } else {
                    IP->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};

void printVector(const vector<int>& values) {
    cout << '[';
    for (size_t i = 0; i < values.size(); i++) {
        if (i > 0) {
            cout << ", ";
        }
        cout << values[i];
    }
    cout << "]\n";
}

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

    vector<vector<int>> examples = {
        {1, INT_MIN, 2, 3},
        {1, 2, 3, 4, 5, INT_MIN, 8, INT_MIN, INT_MIN, 6, 7, 9},
        {},
        {1}
    };

    for (size_t i = 0; i < examples.size(); i++) {
        TreeNode* root = buildTree(examples[i]);
        cout << "Example " << i + 1 << ": ";
        printVector(solution.inorderTraversal(root));
        deleteTree(root);
    }

    return 0;
}
