/*
 * File: top_view.cpp
 * Description: Computes and prints the top view and bottom view of a binary tree
 *              using horizontal distance (HD) and level-order (BFS) traversal with std::map.
 *
 * Time Complexity: O(n log n) - visits all n nodes in BFS; map insertions take O(log k) where k <= n.
 * Space Complexity: O(n) - queue for BFS traversal and map storing horizontal distance mappings.
 *
 */

#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
    if (idx >= static_cast<int>(preorder.size()) || preorder[idx] == -1) {
        return NULL;
    }

    node* root = new node(preorder[idx]);
    root->left = buildtree(preorder);
    root->right = buildtree(preorder);
    return root;
}

void topview(node* root){
    if (root == NULL) {
        return;
    }

    queue<pair<node*,int>>q;
    map<int,int>m;
    q.push({root,0});

    while(q.size() > 0){
        node* curr = q.front().first;
        int  currhd = q.front().second;
        q.pop();

        if(m.find(currhd) == m.end()){
            m[currhd] = curr->data;
        }

        if(curr->left != NULL){
            q.push({curr->left,currhd-1});
        }

        if(curr->right != NULL){
            q.push({curr->right,currhd +1});
        }
    }
    for(auto it : m){
        cout << it.second <<" ";
    }

    cout << endl;
}
void bottomview(node* root){
    if (root == NULL) {
        return;
    }

    queue<pair<node*,int>>q;
    map<int,int>m;
    q.push({root,0});

    while(q.size() > 0){
        node* curr = q.front().first;
        int  currhd = q.front().second;
        q.pop();

        m[currhd] = curr->data;

        if(curr->left != NULL){
            q.push({curr->left,currhd-1});
        }

        if(curr->right != NULL){
            q.push({curr->right,currhd +1});
        }
    }
    for(auto it : m){
        cout << it.second <<" ";
    }

    cout << endl;
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    idx = -1;
    node* root = buildtree(preorder);
    topview(root);
    bottomview(root);
    return 0;
}
