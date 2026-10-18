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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Builds a binary tree from a level-order vector representation.
// Use INT_MIN to represent null nodes (e.g., {1, 2, INT_MIN, INT_MIN, 3}).
// Time Complexity: O(n)
// Space Complexity: O(n)
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == INT_MIN) {
        return NULL;
    }

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (i < nodes.size() && !q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (i < nodes.size() && nodes[i] != INT_MIN) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < nodes.size() && nodes[i] != INT_MIN) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }

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
    TreeNode* p1 = buildTree({1, 2, 3});
    TreeNode* q1 = buildTree({1, 2, 3});
    cout << "Example 1: " << (sol.isSameTree(p1, q1) ? "true" : "false") << endl;

    // Example 2: p = [1,2], q = [1,null,2] -> false
    TreeNode* p2 = buildTree({1, 2});
    TreeNode* q2 = buildTree({1, INT_MIN, 2});
    cout << "Example 2: " << (sol.isSameTree(p2, q2) ? "true" : "false") << endl;

    // Example 3: p = [1,2,1], q = [1,1,2] -> false
    TreeNode* p3 = buildTree({1, 2, 1});
    TreeNode* q3 = buildTree({1, 1, 2});
    cout << "Example 3: " << (sol.isSameTree(p3, q3) ? "true" : "false") << endl;

    return 0;
}

