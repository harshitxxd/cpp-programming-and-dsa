/*
 * File: diameter_of_binary_tree.cpp
 * Description: Given the root of a binary tree, return the length of the diameter
 *              of the tree. The diameter is the length of the longest path between
 *              any two nodes in a tree (represented by the number of edges).
 *
 * Time Complexity: O(n) - visits each node exactly once during post-order traversal while updating the maximum diameter.
 * Space Complexity: O(h) - recursion call stack depth bounded by tree height h (O(n) worst case, O(log n) balanced).
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
    int ans = 0;

    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftht = height(root->left);
        int rightht = height(root->right);
        ans = max(leftht + rightht, ans);
        return max(leftht, rightht) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        height(root);
        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1: root = [1,2,3,4,5] -> Output: 3
    // Preorder: 1 -> left(2 -> left(4), right(5)) -> right(3)
    vector<int> preorder1 = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    idx = -1;
    TreeNode* root1 = buildTree(preorder1);
    cout << "Example 1: " << sol.diameterOfBinaryTree(root1) << endl;

    // Example 2: root = [1,2] -> Output: 1
    // Preorder: 1 -> left(2) -> right(null)
    vector<int> preorder2 = {1, 2, -1, -1, -1};
    idx = -1;
    TreeNode* root2 = buildTree(preorder2);
    cout << "Example 2: " << sol.diameterOfBinaryTree(root2) << endl;

    return 0;
}

