/*
 * File: populating_next_right_pointers_in_each_node.cpp
 * Description: Connects each node to its next right node in a perfect binary
 *              tree.
 *
 * Time Complexity: O(n) - each node is visited once.
 * Space Complexity: O(1) auxiliary space.
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
    Node(int x, Node* left, Node* right, Node* next)
        : val(x), left(left), right(right), next(next) {}
};

static int idx = -1;

Node* buildTree(const vector<int>& preorder) {
    idx++;
    if (idx >= static_cast<int>(preorder.size()) || preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(1) auxiliary space.
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }

        Node* levelStart = root;
        while (levelStart->left != NULL) {
            for (Node* curr = levelStart; curr != NULL; curr = curr->next) {
                curr->left->next = curr->right;
                curr->right->next =
                    curr->next == NULL ? NULL : curr->next->left;
            }
            levelStart = levelStart->left;
        }

        return root;
    }
};

void printNextPointers(Node* root) {
    if (root == NULL) {
        cout << "[]\n";
        return;
    }

    cout << '[';
    for (Node* levelStart = root; levelStart != NULL;
         levelStart = levelStart->left) {
        for (Node* curr = levelStart; curr != NULL; curr = curr->next) {
            cout << curr->val << ',';
        }
        cout << "#";
        if (levelStart->left != NULL) {
            cout << ',';
        }
    }
    cout << "]\n";
}

void deleteTree(Node* root) {
    if (root == NULL) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Solution solution;

    // Example 1: root = [1,2,3,4,5,6,7]
    vector<int> preorder1 = {1, 2, 4, -1, -1, 5, -1, -1,
                             3, 6, -1, -1, 7, -1, -1};
    idx = -1;
    Node* root1 = buildTree(preorder1);
    solution.connect(root1);
    cout << "Example 1: ";
    printNextPointers(root1);
    deleteTree(root1);

    // Example 2: root = []
    vector<int> preorder2 = {-1};
    idx = -1;
    Node* root2 = buildTree(preorder2);
    solution.connect(root2);
    cout << "Example 2: ";
    printNextPointers(root2);
    deleteTree(root2);

    return 0;
}
