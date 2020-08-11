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
};

// Lowest Common Ancestor

/*
1. O(n) time 
   O(n) space
   using rootToNodePath
*/
vector<TreeNode*> rootToNodePath(TreeNode* root,TreeNode *tnode){
    if(root==nullptr)
    return {};
    vector<TreeNode*> v;
    if(root==tnode){
        vector<TreeNode*> base;
        base.push_back(root);
        return base;
    }
    vector<TreeNode*> left=rootToNodePath(root->left,tnode);
    if(left.size()>0){
        left.push_back(root);
        return left;
    }
    
    vector<TreeNode*> right=rootToNodePath(root->right,tnode);
    if(right.size()>0){
        right.push_back(root);
        return right;
    }
    return {};
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
   vector<TreeNode*> first=rootToNodePath(root,p);
   vector<TreeNode*> second=rootToNodePath(root,q);
   TreeNode* ans=nullptr;
   int i=first.size()-1;
   int j=second.size()-1;
   while(i>=0 && j>=0){
    if(first[i]!=second[j])
    break;
    ans=first[i];
    i--;
    j--;
   }    
   return ans; 
}


/*
2.   O(n) time
     Recusive
*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==nullptr) 
        return nullptr;
        
        if (root == p || root == q)
            return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left && right)
            return root;
        
        return left ? left : right;
    }

/*
3. O(h) time 
*/
 TreeNode* parent(TreeNode *root,unordered_map<TreeNode*,TreeNode*>&mp){
     if(root==nullptr)
     return nullptr;
     TreeNode *lsub=parent(root->left,mp);
     if(lsub)
     mp[lsub]=root;
     TreeNode *rsub=parent(root->right,mp);
     if(rsub)
     mp[rsub]=root;
    return root;     
 }

 void levelfn(TreeNode *root,unordered_map<TreeNode*,int>&level){
     queue<TreeNode*> q;
     q.push(root);
     int lvl=0;
     while(!q.empty()){
         int size=q.size();
         while(size--){
            auto tnode = q.front();
            q.pop();
            level[tnode]=lvl;
             if(tnode->left)
                 q.push(tnode->left);
             if(tnode->right)
                 q.push(tnode->right);
         }
         lvl++;
     }
 }
 
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    unordered_map<TreeNode*,TreeNode*> par; 
    unordered_map<TreeNode*,int> level;
    parent(root,par);
    levelfn(root,level);
    int h1=level[p];
    int h2=level[q];
    int diff = h1-h2;
    if(diff > 0){
        while(diff--){
            p=par[p];
        }
    }
    else if (diff < 0) {
        int x=-(diff);
        while(x--){
            q=par[q];
        }
    }
    if(p==q)
         return p;
    while(par[p]!=par[q]){
        p=par[p];
        q=par[q];
    }
    return par[p];
}

/*
4. lca using Square root Decomposition
*/
TreeNode* parent(TreeNode *root,unordered_map<TreeNode*,TreeNode*>&mp){
     if(root==nullptr)
     return nullptr;
     TreeNode *lsub=parent(root->left,mp);
     if(lsub)
     mp[lsub]=root;
     TreeNode *rsub=parent(root->right,mp);
     if(rsub)
     mp[rsub]=root;
    return root;     
 }

 void levelfn(TreeNode *root,unordered_map<TreeNode*,int>&level){
     queue<TreeNode*> q;
     q.push(root);
     int lvl=0;
     while(!q.empty()){
         int size=q.size();
         while(size--){
            auto tnode = q.front();
            q.pop();
            level[tnode]=lvl;
             if(tnode->left)
                 q.push(tnode->left);
             if(tnode->right)
                 q.push(tnode->right);
         }
         lvl++;
     }
 }

TreeNode* grandparent(TreeNode *root,unordered_map<TreeNode*,TreeNode*>&par,unordered_map<TreeNode*,int>&level,unordered_map<TreeNode*,TreeNode*>&gpar,int h){
     if(root==nullptr)
     return nullptr;
     TreeNode *lsub=grandparent(root->left,par,level,gpar,h);
     if(lsub){
         if(level[lsub]%h==0)
         gpar[lsub]=par[lsub];
         else{
            gpar[lsub]=gpar[par[lsub]];
         }  
     }
     TreeNode *rsub=grandparent(root->right,par,level,gpar,h);
     if(rsub){
         if(level[rsub]%h==0)
         gpar[rsub]=par[rsub];
         else{
         gpar[rsub]=gpar[par[rsub]];
         }  
     }
     return root;
 }
 

TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p, TreeNode* q) {
    unordered_map<TreeNode*,TreeNode*> par; 
    unordered_map<TreeNode*,int> level;
    unordered_map<TreeNode*,TreeNode*> gpar;
    parent(root,par);
    levelfn(root,level);
    int h=INT_MIN;
    for(auto ele:level)
    h=max(h,ele.second);
    grandparent(root,par,level,gpar,h);
    int h1=level[p];
    int h2=level[q];
    int diff = h1-h2;
    if(diff>0){
        while(gpar[p]!=gpar[q])
        p=gpar[p];
    }
    else if(diff<0){
        while(gpar[p]!=gpar[q])
        q=gpar[q];
    }
    int h11=level[p];
    int h22=level[q];
    int diff2 = h11-h22;
    if(diff2 > 0){
        while(diff2--){
            p=par[p];
        }
    }
    else if (diff2 < 0) {
        int x=-(diff2);
        while(x--){
            q=par[q];
        }
    }
    if(p==q)
         return p;
    while(par[p]!=par[q]){
        p=par[p];
        q=par[q];
    }
    return par[p];
}