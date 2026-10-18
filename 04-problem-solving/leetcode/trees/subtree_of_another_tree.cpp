/*
 * File: subtree_of_another_tree.cpp
 * Description: Given the roots of two binary trees root and subRoot, return
 *              true if there is a subtree of root with the same structure and
 *              node values of subRoot, and false otherwise.
 *
 * Time Complexity: O(n * m) - where n is the number of nodes in root and m is
 *                  the number of nodes in subRoot. In the worst case, for each node
 *                  in root, we may check if the subtree is identical taking O(m) time.
 * Space Complexity: O(h_root) - recursion stack depth bounded by the height of
 *                   root, which is O(n) in the worst case (skewed tree) and
 *                   O(log n) in the best case (balanced tree).
 *
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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
    bool isidentical(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) {
            return p == q;
        }
        return p->val == q->val && isidentical(p->left, q->left) && isidentical(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL || subRoot == NULL) {
            return root == subRoot;
        }

        if (root->val == subRoot->val && isidentical(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

int main() {
    Solution sol;

    // Example 1: root = [3,4,5,1,2], subRoot = [4,1,2] -> true
    // Preorder: root(3) -> left(4 -> left(1), right(2)) -> right(5)
    vector<int> rootPre1 = {3, 4, 1, -1, -1, 2, -1, -1, 5, -1, -1};
    idx = -1;
    TreeNode* root1 = buildTree(rootPre1);

    vector<int> subRootPre1 = {4, 1, -1, -1, 2, -1, -1};
    idx = -1;
    TreeNode* subRoot1 = buildTree(subRootPre1);

    cout << "Example 1: " << (sol.isSubtree(root1, subRoot1) ? "true" : "false") << endl;

    // Example 2: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2] -> false
    // Node 2 has left child 0
    vector<int> rootPre2 = {3, 4, 1, -1, -1, 2, 0, -1, -1, -1, 5, -1, -1};
    idx = -1;
    TreeNode* root2 = buildTree(rootPre2);

    vector<int> subRootPre2 = {4, 1, -1, -1, 2, -1, -1};
    idx = -1;
    TreeNode* subRoot2 = buildTree(subRootPre2);

    cout << "Example 2: " << (sol.isSubtree(root2, subRoot2) ? "true" : "false") << endl;

    return 0;
}
