/*
 * File: convert_sorted_array_to_binary_search_tree.cpp
 * Description: Converts a sorted integer array into a height-balanced
 *              binary search tree by recursively choosing each range's midpoint.
 *
 * Time Complexity: O(n) - each array element becomes one tree node.
 * Space Complexity: O(log n) auxiliary recursion stack for the balanced tree,
 *                   excluding the O(n) output tree.
 *
 */

#include <iostream>
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

class Solution {
public:
    TreeNode* helper(vector<int>& nums, int st, int end) {
        if (st > end) {
            return NULL;
        }

        int mid = st + (end - st) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = helper(nums, st, mid - 1);
        root->right = helper(nums, mid + 1, end);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, static_cast<int>(nums.size()) - 1);
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

    vector<int> nums1 = {-10, -3, 0, 5, 9};
    TreeNode* root1 = solution.sortedArrayToBST(nums1);
    cout << "Example 1: ";
    printLevelOrder(root1);
    deleteTree(root1);

    vector<int> nums2 = {1, 3};
    TreeNode* root2 = solution.sortedArrayToBST(nums2);
    cout << "Example 2: ";
    printLevelOrder(root2);
    deleteTree(root2);

    return 0;
}
