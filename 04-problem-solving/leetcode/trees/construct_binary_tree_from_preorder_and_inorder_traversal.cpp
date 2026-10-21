/*
 * File: construct_binary_tree_from_preorder_and_inorder_traversal.cpp
 * Description: Constructs a binary tree from its preorder and inorder
 *              traversals, whose node values are unique.
 *
 * Time Complexity: O(n^2) worst case because each root is searched for in the
 *                  current inorder range.
 * Space Complexity: O(h) recursion stack, where h is the tree height.
 *
 */

#include <iostream>
#include <queue>
#include <string>
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

class Solution {
public:
    int search(const vector<int>& inorder, int left, int right, int val) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* helper(const vector<int>& preorder, const vector<int>& inorder,
                     int& preidx, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preidx]);
        int inidx = search(inorder, left, right, preorder[preidx]);
        preidx++;

        root->left = helper(preorder, inorder, preidx, left, inidx - 1);
        root->right = helper(preorder, inorder, preidx, inidx + 1, right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preidx = 0;
        return helper(preorder, inorder, preidx, 0,
                      static_cast<int>(inorder.size()) - 1);
    }
};

void printLevelOrder(TreeNode* root) {
    if (root == nullptr) {
        cout << "[]\n";
        return;
    }

    queue<TreeNode*> nodes;
    vector<string> values;
    nodes.push(root);

    while (!nodes.empty()) {
        TreeNode* current = nodes.front();
        nodes.pop();

        if (current == nullptr) {
            values.push_back("null");
            continue;
        }

        values.push_back(to_string(current->val));
        nodes.push(current->left);
        nodes.push(current->right);
    }

    while (!values.empty() && values.back() == "null") {
        values.pop_back();
    }

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

    vector<int> preorder1 = {3, 9, 20, 15, 7};
    vector<int> inorder1 = {9, 3, 15, 20, 7};
    TreeNode* root1 = solution.buildTree(preorder1, inorder1);
    cout << "Example 1: ";
    printLevelOrder(root1);
    deleteTree(root1);

    vector<int> preorder2 = {-1};
    vector<int> inorder2 = {-1};
    TreeNode* root2 = solution.buildTree(preorder2, inorder2);
    cout << "Example 2: ";
    printLevelOrder(root2);
    deleteTree(root2);

    return 0;
}
