/*
 * File: merge_two_sorted_bst.cpp
 * Description: Merges two Binary Search Trees into a single balanced BST
 *              by extracting sorted inorders, merging them into one sorted array,
 *              and constructing a balanced BST from the merged array.
 *
 * Time Complexity: O(n1 + n2) - linear time to traverse both trees, merge arrays,
 *                  and construct the balanced BST.
 * Space Complexity: O(n1 + n2) - storage for inorder vectors and merged elements,
 *                   plus O(log(n1 + n2)) recursive call stack for building the balanced tree.
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

Node* buildBST(const vector<int>& arr) {
    Node* root = NULL;
    for (int val : arr) {
        root = insert(root, val);
    }
    return root;
}

void inorder(Node* root, vector<int>& arr) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

Node* buildBSTfromsorted(const vector<int>& arr, int st, int end) {
    if (st > end) {
        return NULL;
    }
    int mid = st + (end - st) / 2;
    Node* root = new Node(arr[mid]);
    root->left = buildBSTfromsorted(arr, st, mid - 1);
    root->right = buildBSTfromsorted(arr, mid + 1, end);

    return root;
}

Node* merge2BST(Node* root1, Node* root2) {
    vector<int> arr1, arr2;
    inorder(root1, arr1);
    inorder(root2, arr2);

    vector<int> temp;

    size_t i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            temp.push_back(arr1[i++]);
        } else {
            temp.push_back(arr2[j++]);
        }
    }

    while (i < arr1.size()) {
        temp.push_back(arr1[i++]);
    }

    while (j < arr2.size()) {
        temp.push_back(arr2[j++]);
    }

    return buildBSTfromsorted(temp, 0, (int)temp.size() - 1);
}

int main() {
    vector<int> arr1 = {8, 2, 1, 10};
    vector<int> arr2 = {5, 3, 0};

    Node* root1 = buildBST(arr1);
    Node* root2 = buildBST(arr2);

    Node* root = merge2BST(root1, root2);
    vector<int> seq;
    inorder(root, seq);
    for (int v : seq) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
