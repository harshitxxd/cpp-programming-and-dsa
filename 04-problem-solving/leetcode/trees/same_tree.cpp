/*
 * File: same_tree.cpp
 * Description: Given the roots of two binary trees p and q, check if they are
 *              the same. Two binary trees are considered the same if they are
 *              structurally identical and the nodes have the same value.
 *
 * Time Complexity: O(n) - where n is the minimum number of nodes in either tree,
 *                  since we visit each node exactly once in the worst case.
 * Space Complexity: O(h) - where h is the height of the tree, due to the
 *                   recursive call stack. O(n) in the worst case (skewed tree),
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) {
            return p == q;
        }
        bool isleftsame = isSameTree(p->left, q->left);
        bool isrightsame = isSameTree(p->right, q->right);

        return isleftsame && isrightsame && p->val == q->val;
    }
};

int main() {
    Solution sol;

    // Example 1: p = [1,2,3], q = [1,2,3] -> true
    vector<int> p1Nodes = {1, 2, -1, -1, 3, -1, -1};
    idx = -1;
    TreeNode* p1 = buildTree(p1Nodes);

    vector<int> q1Nodes = {1, 2, -1, -1, 3, -1, -1};
    idx = -1;
    TreeNode* q1 = buildTree(q1Nodes);

    cout << "Example 1: " << (sol.isSameTree(p1, q1) ? "true" : "false") << endl;

    // Example 2: p = [1,2], q = [1,null,2] -> false
    vector<int> p2Nodes = {1, 2, -1, -1, -1};
    idx = -1;
    TreeNode* p2 = buildTree(p2Nodes);

    vector<int> q2Nodes = {1, -1, 2, -1, -1};
    idx = -1;
    TreeNode* q2 = buildTree(q2Nodes);

    cout << "Example 2: " << (sol.isSameTree(p2, q2) ? "true" : "false") << endl;

    // Example 3: p = [1,2,1], q = [1,1,2] -> false
    vector<int> p3Nodes = {1, 2, -1, -1, 1, -1, -1};
    idx = -1;
    TreeNode* p3 = buildTree(p3Nodes);

    vector<int> q3Nodes = {1, 1, -1, -1, 2, -1, -1};
    idx = -1;
    TreeNode* q3 = buildTree(q3Nodes);

    cout << "Example 3: " << (sol.isSameTree(p3, q3) ? "true" : "false") << endl;

    return 0;
}
