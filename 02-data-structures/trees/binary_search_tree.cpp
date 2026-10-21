/*
 * File: binary_search_tree.cpp
 * Description: Implementation of a Binary Search Tree (BST) supporting node insertion,
 *              building BST from an array, inorder traversal, searching for a key,
 *              and node deletion using inorder successor replacement.
 *
 * Time Complexity: O(h) per operation (insert, search, delete), where h is the tree height.
 *                  O(log n) average for balanced BST, O(n) worst-case for skewed BST.
 * Space Complexity: O(n) to store n nodes in the tree; O(h) auxiliary recursion stack depth.
 *
 */

#include<iostream>
#include<vector>
using namespace std;

class node{
    public :
    int data;
    node* left;
    node* right;

    node(int val){
        data = val ;
        left = right = NULL;
    }
};

node* insert(node* root,int val){
    if(root == NULL){
        return new node(val);
    }
    if(val < root->data){
        root->left = insert(root->left,val);
    }else{
        root->right = insert(root->right,val);
    }
    return root;
}

node* buildbst(vector<int> arr){
    node* root = NULL;
    for(int val : arr){
        root = insert(root,val);
    }

    return root ;
}

void inorder(node* root){
    if(root == NULL){
        return ;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}

bool search(node* root, int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(key < root->data){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}

node* getinordersuccessor(node* root){
    while(root != NULL && root->left != NULL){
        root = root->left;
    }
    return root;
}
node* delnode(node* root,int key){
    if(root == NULL){
        return NULL;
    }

    if(key < root->data){
        root->left = delnode(root->left, key);
    }else if(key > root->data){
        root->right = delnode(root->right,key);   
    }else {
        if(root->left == NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }else if (root->right == NULL){
            node* temp = root->left ;
            delete root ;
            return temp;
        }else {
            node* IS = getinordersuccessor(root->right);
            root->data = IS->data;
            root->right = delnode(root->right, IS ->data);
        }
    }
    return root;

}

int main(){
    vector<int> arr = {3,2,1,5,6,4};
    node* root = buildbst(arr);
    cout << "before: ";
    inorder(root);
    cout << endl;
    delnode(root,6);
    cout << "after: ";
    inorder(root);
    cout << endl;
    return 0;
}

