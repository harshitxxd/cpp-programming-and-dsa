/*
 * File: recover_binary_search_tree.cpp
 * Description: Recovers a BST with two swapped node values using recursive
 *              inorder traversal to find the misplaced nodes.
 *
 * Time Complexity: O(n) - each node is visited once.
 * Space Complexity: O(h) - recursive call stack, where h is the tree height.
 *
 */

#include <iostream>
#include <optional>
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

TreeNode* buildTree(const vector<optional<int>>& preorder, int& index) {
    if (index >= static_cast<int>(preorder.size()) || !preorder[index].has_value()) {
        index++;
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[index].value());
    index++;
    root->left = buildTree(preorder, index);
    root->right = buildTree(preorder, index);
    return root;
}

class Solution {
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* sec = NULL;

    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        inorder(root->left);

        if (prev != NULL && prev->val > root->val) {
            if (first == NULL) {
                first = prev;
            }
            sec = root;
        }

        prev = root;
        inorder(root->right);
    }

public:
    // Time Complexity: O(n)
    // Space Complexity: O(h) for the recursion stack.
    void recoverTree(TreeNode* root) {
        prev = NULL;
        first = NULL;
        sec = NULL;

        inorder(root);

        if (first != NULL && sec != NULL) {
            int temp = first->val;
            first->val = sec->val;
            sec->val = temp;
        }
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

    // Example 1: root = [1,3,null,null,2]
    vector<optional<int>> preorder1 = {
        1, 3, nullopt, 2, nullopt, nullopt, nullopt
    };
    int index1 = 0;
    TreeNode* root1 = buildTree(preorder1, index1);
    solution.recoverTree(root1);
    cout << "Example 1: ";
    printLevelOrder(root1);
    deleteTree(root1);

    // Example 2: root = [3,1,4,null,null,2]
    vector<optional<int>> preorder2 = {
        3, 1, nullopt, nullopt, 4, 2, nullopt, nullopt, nullopt
    };
    int index2 = 0;
    TreeNode* root2 = buildTree(preorder2, index2);
    solution.recoverTree(root2);
    cout << "Example 2: ";
    printLevelOrder(root2);
    deleteTree(root2);

    return 0;
}
