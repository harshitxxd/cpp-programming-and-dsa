/*
 * File: lowest_common_ancestor_of_a_bst.cpp
 * Description: Finds the lowest common ancestor of two nodes in a binary
 *              search tree using recursive BST search.
 *
 * Time Complexity: O(h) - follows at most one root-to-leaf path, where h is
 *                  the height of the tree.
 * Space Complexity: O(h) - recursive call stack, where h is the tree height.
 *
 */

#include <iostream>
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

static int idx = -1;

TreeNode* buildTree(const vector<int>& preorder) {
    idx++;
    if (idx >= static_cast<int>(preorder.size()) || preorder[idx] == -1) {
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

TreeNode* findNode(TreeNode* root, int val) {
    if (root == NULL || root->val == val) {
        return root;
    }

    TreeNode* leftNode = findNode(root->left, val);
    if (leftNode != NULL) {
        return leftNode;
    }
    return findNode(root->right, val);
}

class Solution {
public:
    // Time Complexity: O(h)
    // Space Complexity: O(h) for the recursion stack.
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }

        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
};

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

    // Example 1: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
    vector<int> preorder1 = {
        6, 2, 0, -1, -1, 4, 3, -1, -1, 5, -1, -1,
        8, 7, -1, -1, 9, -1, -1
    };
    idx = -1;
    TreeNode* root1 = buildTree(preorder1);
    TreeNode* p1 = findNode(root1, 2);
    TreeNode* q1 = findNode(root1, 8);
    TreeNode* answer1 = solution.lowestCommonAncestor(root1, p1, q1);
    cout << "Example 1: " << (answer1 != NULL ? answer1->val : -1) << '\n';
    deleteTree(root1);

    // Example 2: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
    vector<int> preorder2 = {
        6, 2, 0, -1, -1, 4, 3, -1, -1, 5, -1, -1,
        8, 7, -1, -1, 9, -1, -1
    };
    idx = -1;
    TreeNode* root2 = buildTree(preorder2);
    TreeNode* p2 = findNode(root2, 2);
    TreeNode* q2 = findNode(root2, 4);
    TreeNode* answer2 = solution.lowestCommonAncestor(root2, p2, q2);
    cout << "Example 2: " << (answer2 != NULL ? answer2->val : -1) << '\n';
    deleteTree(root2);

    // Example 3: root = [2,1], p = 2, q = 1
    vector<int> preorder3 = {2, 1, -1, -1, -1};
    idx = -1;
    TreeNode* root3 = buildTree(preorder3);
    TreeNode* p3 = findNode(root3, 2);
    TreeNode* q3 = findNode(root3, 1);
    TreeNode* answer3 = solution.lowestCommonAncestor(root3, p3, q3);
    cout << "Example 3: " << (answer3 != NULL ? answer3->val : -1) << '\n';
    deleteTree(root3);

    return 0;
}
