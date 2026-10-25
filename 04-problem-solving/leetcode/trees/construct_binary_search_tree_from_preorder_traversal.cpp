/*
 * File: construct_binary_search_tree_from_preorder_traversal.cpp
 * Description: Constructs a binary search tree from its preorder traversal
 *              using recursive upper bounds.
 *
 * Time Complexity: O(n) - each preorder value is processed once.
 * Space Complexity: O(h) - recursion stack, where h is the tree height,
 *                  excluding the O(n) output tree.
 *
 */

#include <climits>
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

    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* helper(vector<int>& preorder, int& i, int bound) {
        if (i >= static_cast<int>(preorder.size()) || preorder[i] > bound) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = helper(preorder, i, root->val);
        root->right = helper(preorder, i, bound);
        return root;
    }

public:
    // Time Complexity: O(n)
    // Space Complexity: O(h) for the recursion stack.
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return helper(preorder, i, INT_MAX);
    }
};

void printLevelOrder(TreeNode* root) {
    if (root == NULL) {
        cout << "[]\n";
        return;
    }

    queue<TreeNode*> nodes;
    vector<string> values;
    nodes.push(root);

    while (!nodes.empty()) {
        TreeNode* current = nodes.front();
        nodes.pop();

        if (current == NULL) {
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
    if (root == NULL) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Solution solution;

    vector<int> preorder1 = {8, 5, 1, 7, 10, 12};
    TreeNode* root1 = solution.bstFromPreorder(preorder1);
    cout << "Example 1: ";
    printLevelOrder(root1);
    deleteTree(root1);

    vector<int> preorder2 = {1, 3};
    TreeNode* root2 = solution.bstFromPreorder(preorder2);
    cout << "Example 2: ";
    printLevelOrder(root2);
    deleteTree(root2);

    return 0;
}
