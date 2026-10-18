#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;

// Time Complexity: O(n)
// Space Complexity: O(h) for the recursion stack, where h is the tree height.
node* buildtree(const vector<int>& preorder) {
    idx++;
    if (preorder[idx] == -1) {
        return NULL;
    }

    node* root = new node(preorder[idx]);
    root->left = buildtree(preorder);
    root->right = buildtree(preorder);
    return root;
}

int height(node* root){
    if(root == NULL){
        return 0;
    }
    int leheight = height(root->left);
    int riheight = height(root->right);
    return max(leheight,riheight)+1;
}

int count(node* root){
    if(root == NULL){
        return 0;
    }
    int leftcount = count(root->left);
    int rightcount = count(root->right);
    return leftcount + rightcount +1;
}

int sum(node* root){
    if(root == NULL){
        return 0;
    }
    int leftsum = sum(root->left);
    int rightsum = sum(root->right);
    return rightsum + leftsum + root->data;  
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    idx = -1;
    node* root = buildtree(preorder);
    cout << "height: " << height(root) << endl;
    cout << "count: " << count (root) << endl;
    cout << "sum : " << sum(root) << endl;
    return 0;
}