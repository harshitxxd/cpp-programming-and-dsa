/*
 * File: binary_tree_paths.cpp
 * Description: Given the root of a binary tree, returns all root-to-leaf paths
 *              formatted as strings (e.g., "1->2->5").
 *
 * Time Complexity: O(n * h) - visits each of the n nodes; at each leaf, string
 *                  copying takes O(h) where h is the tree height.
 * Space Complexity: O(h) - recursion call stack depth bounded by tree height h
 *                   (excluding the result vector).
 *
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

static int idx = -1;

// Builds a binary tree recursively from a preorder vector representation.
// Use -1 to represent null nodes.
// Time Complexity: O(n)
// Space Complexity: O(h) for the recursion stack, where h is the tree height.
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
public:
    void allpaths(TreeNode* root, string path, vector<string>& ans) {
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }
        if (root->left) {
            allpaths(root->left, path + "->" + to_string(root->left->val), ans);
        }
        if (root->right) {
            allpaths(root->right, path + "->" + to_string(root->right->val), ans);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root) {
            return ans;
        }
        string path = to_string(root->val);
        allpaths(root, path, ans);
        return ans;
    }
};

void printPaths(const vector<string>& paths) {
    cout << '[';
    for (size_t i = 0; i < paths.size(); i++) {
        cout << '"' << paths[i] << '"';
        if (i + 1 < paths.size()) {
            cout << ", ";
        }
    }
    cout << ']' << endl;
}

int main() {
    Solution sol;

    // Example 1: root = [1,2,3,null,5] -> Output: ["1->2->5", "1->3"]
    // Preorder: 1 -> left(2 -> right(5)) -> right(3)
    vector<int> preorder1 = {1, 2, -1, 5, -1, -1, 3, -1, -1};
    idx = -1;
    TreeNode* root1 = buildTree(preorder1);
    vector<string> res1 = sol.binaryTreePaths(root1);
    cout << "Example 1: ";
    printPaths(res1);

    // Example 2: root = [1] -> Output: ["1"]
    vector<int> preorder2 = {1, -1, -1};
    idx = -1;
    TreeNode* root2 = buildTree(preorder2);
    vector<string> res2 = sol.binaryTreePaths(root2);
    cout << "Example 2: ";
    printPaths(res2);

    return 0;
}
