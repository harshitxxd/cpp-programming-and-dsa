/*
 * File: kth_smallest_element_in_a_bst.cpp
 * Description: Finds the kth smallest value in a binary search tree using
 *              recursive inorder traversal.
 *
 * Time Complexity: O(h + k) - visits nodes along the path and the first k
 *                  inorder nodes.
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

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

static int idx = -1;

TreeNode* buildTree(const vector<int>& preorder) {
    idx++;
    if (idx >= static_cast<int>(preorder.size()) || preorder[idx] == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

class Solution {
    int prevOrder = 0;

    int kthSmallestRecursive(TreeNode* root, int k) {
        if (root == nullptr) {
            return -1;
        }

        if (root->left != nullptr) {
            int leftAnswer = kthSmallestRecursive(root->left, k);
            if (leftAnswer != -1) {
                return leftAnswer;
            }
        }

        if (prevOrder + 1 == k) {
            return root->val;
        }
        prevOrder++;

        if (root->right != nullptr) {
            int rightAnswer = kthSmallestRecursive(root->right, k);
            if (rightAnswer != -1) {
                return rightAnswer;
            }
        }
        return -1;
    }

public:
    // Time Complexity: O(h + k)
    // Space Complexity: O(h) for the recursion stack.
    int kthSmallest(TreeNode* root, int k) {
        prevOrder = 0;
        return kthSmallestRecursive(root, k);
    }
};

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

    // Example 1: root = [3,1,4,null,2], k = 1
    vector<int> preorder1 = {3, 1, -1, 2, -1, -1, 4, -1, -1};
    idx = -1;
    TreeNode* root1 = buildTree(preorder1);
    cout << "Example 1: " << solution.kthSmallest(root1, 1) << '\n';
    deleteTree(root1);

    // Example 2: root = [5,3,6,2,4,null,null,1], k = 3
    vector<int> preorder2 = {5, 3, 2, 1, -1, -1, -1, 4, -1, -1, 6, -1, -1};
    idx = -1;
    TreeNode* root2 = buildTree(preorder2);
    cout << "Example 2: " << solution.kthSmallest(root2, 3) << '\n';
    deleteTree(root2);

    return 0;
}
