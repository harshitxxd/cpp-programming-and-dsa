/*
 * File: binary_tree_inorder_traversal.cpp
 * Description: Returns the inorder traversal of a binary tree using Morris
 *              traversal, which temporarily threads and restores tree links.
 *
 * Time Complexity: O(n) - each node and temporary thread is processed a
 *                  constant number of times.
 * Space Complexity: O(1) auxiliary space, excluding the returned vector.
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
    if (idx >= (int)preorder.size() || preorder[idx] == -1) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(1) auxiliary space.
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* IP = curr->left;
                while (IP->right != nullptr && IP->right != curr) {
                    IP = IP->right;
                }

                if (IP->right == nullptr) {
                    IP->right = curr;
                    curr = curr->left;
                } else {
                    IP->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};

void printVector(const vector<int>& values) {
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
    if (root == nullptr) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Solution solution;

    // Example 1: root = [1,null,2,3]
    vector<int> preorder1 = {1, -1, 2, 3, -1, -1, -1};
    idx = -1;
    TreeNode* root1 = buildTree(preorder1);
    cout << "Example 1: ";
    printVector(solution.inorderTraversal(root1));
    deleteTree(root1);

    // Example 2: root = [1,2,3,4,5,null,8,null,null,6,7,9]
    vector<int> preorder2 = {1, 2, 4, -1, -1, 5, 6, -1, -1, 7, -1, -1, 3, -1, 8, 9, -1, -1, -1};
    idx = -1;
    TreeNode* root2 = buildTree(preorder2);
    cout << "Example 2: ";
    printVector(solution.inorderTraversal(root2));
    deleteTree(root2);

    // Example 3: root = []
    vector<int> preorder3 = {-1};
    idx = -1;
    TreeNode* root3 = buildTree(preorder3);
    cout << "Example 3: ";
    printVector(solution.inorderTraversal(root3));
    deleteTree(root3);

    // Example 4: root = [1]
    vector<int> preorder4 = {1, -1, -1};
    idx = -1;
    TreeNode* root4 = buildTree(preorder4);
    cout << "Example 4: ";
    printVector(solution.inorderTraversal(root4));
    deleteTree(root4);

    return 0;
}
