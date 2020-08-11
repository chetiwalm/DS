#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val=0;
    TreeNode *left=nullptr;
    TreeNode *right=nullptr;

    TreeNode(){

    }
    TreeNode(int val){
        this->val=val;
    }
    TreeNode(int val,TreeNode *left,TreeNode *right){
        this->val=val;
        this->left=left;
        this->right=right;
    }
};

TreeNode *findmn(TreeNode *root){
    if(root==nullptr)
    return nullptr;
    while(root->left!=nullptr)
    root=root->left;
    return root;
}

TreeNode *deletefn(TreeNode *root){
    if(!root->left && !root->right)
    return nullptr;
    else if(root->left && !root->right)
    return root=root->left;
    else if(!root->left && root->right)
    return root=root->right;
    else{
       TreeNode *temp=findmn(root->right);
       temp->left =  root->left;
    }
    return root;
}

TreeNode *findfn(TreeNode *root,int key){
    if(root==nullptr)
    return nullptr;
    if(root->val==key){

    }
    if(root->val > key)
    root->left = findfn(root->left,key);
    else
        root->right=findfn(root->right,key);
        return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *t=root;
        findfn(root,key);
        return t;
    }