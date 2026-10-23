/*
 * File: lowest_common_ancestor_of_a_binary_tree.cpp
 * Description: Given a binary tree and two nodes p and q, find the lowest common
 *              ancestor (LCA) of p and q. The lowest common ancestor is defined
 *              between two nodes p and q as the lowest node in T that has both
 *              p and q as descendants (where a node can be a descendant of itself).
 *
 * Time Complexity: O(n) - where n is the number of nodes in the binary tree. In
 *                  the worst case, every node is visited once during traversal.
 * Space Complexity: O(h) - recursion call stack depth bounded by tree height h
 *                   (O(n) worst case for skewed tree, O(log n) for balanced tree).
 *
 */

#include <iostream>
#include <vector>
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

// Helper function to find a pointer to the node with a given value in the binary tree.
TreeNode* findNode(TreeNode* root, int val) {
    if (root == NULL) {
        return NULL;
    }
    if (root->val == val) {
        return root;
    }
    TreeNode* leftSearch = findNode(root->left, val);
    if (leftSearch != NULL) {
        return leftSearch;
    }
    return findNode(root->right, val);
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }

        if (root->val == p->val || root->val == q->val) {
            return root;
        }

        TreeNode* leftlca = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightlca = lowestCommonAncestor(root->right, p, q);

        if (leftlca && rightlca) {
            return root;
        } else if (leftlca != NULL) {
            return leftlca;
        } else {
            return rightlca;
        }
    }
};

int main() {
    Solution sol;

    // Example 1: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1 -> Output: 3
    // Preorder: 3 -> left(5 -> left(6), right(2 -> left(7), right(4))) -> right(1 -> left(0), right(8))
    vector<int> preorder1 = {3, 5, 6, -1, -1, 2, 7, -1, -1, 4, -1, -1, 1, 0, -1, -1, 8, -1, -1};
    idx = -1;
    TreeNode* root1 = buildTree(preorder1);
    TreeNode* p1 = findNode(root1, 5);
    TreeNode* q1 = findNode(root1, 1);
    TreeNode* ans1 = sol.lowestCommonAncestor(root1, p1, q1);
    cout << "Example 1: " << (ans1 != NULL ? ans1->val : -1) << endl;

    // Example 2: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4 -> Output: 5
    TreeNode* p2 = findNode(root1, 5);
    TreeNode* q2 = findNode(root1, 4);
    TreeNode* ans2 = sol.lowestCommonAncestor(root1, p2, q2);
    cout << "Example 2: " << (ans2 != NULL ? ans2->val : -1) << endl;

    // Example 3: root = [1,2], p = 1, q = 2 -> Output: 1
    // Preorder: 1 -> left(2) -> right(null)
    vector<int> preorder3 = {1, 2, -1, -1, -1};
    idx = -1;
    TreeNode* root3 = buildTree(preorder3);
    TreeNode* p3 = findNode(root3, 1);
    TreeNode* q3 = findNode(root3, 2);
    TreeNode* ans3 = sol.lowestCommonAncestor(root3, p3, q3);
    cout << "Example 3: " << (ans3 != NULL ? ans3->val : -1) << endl;

    return 0;
}

