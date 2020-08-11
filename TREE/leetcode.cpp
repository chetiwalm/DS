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

//inorder Traversal
//leetcode 94
vector<int> ans;
    void inOrder(TreeNode *root){
        if(root){
            inOrder(root->left);
            ans.push_back(root->val);
            inOrder(root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inOrder(root);
        return ans;
    }

// leetcode 102
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ans;
    if(root=nullptr)
    return ans;
    queue<TreeNode*> q;
    vector<vector<int>> ans;
    if(root==nullptr)
    return ans;
    q.push(root);
    while(q.size()!=0){
        int size=q.size();
        vector<int> v;
        while(size--){
            TreeNode* t=q.front();
            q.pop();
            v.push_back(t->val);
            if(t->left)
            q.push(t->left);
            if(t->right)
            q.push(t->right);
        }
        ans.push_back(v);
    }
    reverse(ans.begin(),ans.end());
    return ans;       
}


//leetcode 107
vector<vector<int>> levelOrderBottom(TreeNode* root) {
 queue<TreeNode*> q;
    vector<vector<int>> ans;
    if(root==nullptr)
    return ans;
    q.push(root);
    while(q.size()!=0){
        int size=q.size();
        vector<int> v;
        while(size--){
            TreeNode* t=q.front();
            q.pop();
            v.push_back(t->val);
            if(t->left)
            q.push(t->left);
            if(t->right)
            q.push(t->right);
        }
        ans.push_back(v);
    }
    reverse(ans.begin(),ans.end());
    return ans;       
}


//preorder Traversal
//leetcode 144
vector<int> ans;
    void preorder(TreeNode* node){
        if(node){
        ans.push_back(node->val);
        preorder(node->left);
        preorder(node->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
     preorder(root);
        return ans;
    }



//postOrder Traversal
//leetcode 145
vector<int> ans;
    void post(TreeNode *root){
        if(root){
            post(root->left);
            post(root->right);
            ans.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        post(root);
        return ans;
    }

// leetcode 199
// right side view
vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)
            return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            int m=size;
            while(size--){
                TreeNode *t=q.front();
                q.pop();
                if(size==0)
                    ans.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
        }
        return ans;
    }

    
// leetcode 236
// lowest common ascestor
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




// leetcode 863
//k disrance away
TreeNode *dfs(TreeNode *root,unordered_map<TreeNode*,TreeNode*>&mp){
    if(root==nullptr)
    return nullptr;
    TreeNode *lsub=dfs(root->left,mp);
    if(lsub)
    mp[lsub]=root;
    TreeNode *rsub=dfs(root->right,mp);
    if(rsub)
    mp[rsub]=root;
    return root;
}


vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
   unordered_map<TreeNode*,TreeNode*> mp;
   unordered_set<TreeNode*> s;
   vector<int>ans;
   if(root==nullptr || target==nullptr || k<0)
   return ans;
   dfs(root,mp);
   queue<TreeNode*> q;
   q.push(target);
   s.insert(target);
   int level=0;
   while(!q.empty()){
       int size=q.size();
       while(size--){
           if(level==k){
               while(!q.empty()){
                   TreeNode* t=q.front();
                   q.pop();
                   ans.push_back(t->val);
               }
               break;
           }
           TreeNode* x=q.front();
           q.pop();
           if(x->left!=nullptr && s.find(x->left)==s.end()){
           q.push(x->left);
           s.insert(x->left);
           }
           if(x->right!=nullptr && s.find(x->right)==s.end()){
           q.push(x->right);
           s.insert(x->right);
           }
           if(mp[x]!=nullptr && s.find(mp[x])==s.end()){
            q.push(mp[x]);
            s.insert(mp[x]);
           }
       }
       level++;
   }       
   return ans;
}

// leetcode 987
// vertical order
static bool mycmp(pair<int,int>&a,pair<int,int>&b){
    if(a.first!=b.first)
    return a.first<b.first;
    else
        return a.second<b.second;
}
vector<vector<int>> verticalTraversal(TreeNode* root) {
  vector<vector<int>> ans;
  unordered_map<int,vector<pair<int,int>>> mp;
  queue<pair<int,TreeNode*>> q;
  q.push(make_pair(0,root));
  int level=0;
  while(!q.empty()){
      int size=q.size();
      while(size--){
        auto t=q.front();
        q.pop();
        int vlevel=t.first;
        TreeNode* tnode=t.second;
        mp[vlevel].push_back(make_pair(level,tnode->val));
        if(tnode->left)
        q.push(make_pair(vlevel-1,tnode->left));
        if(tnode->right)
        q.push(make_pair(vlevel+1,tnode->right));
      }
      level++;
  }
  int mini=0;
  int maxi=0;
    for(auto ele:mp){
        maxi=max(ele.first,maxi);
        mini=min(ele.first,mini);
    }
  for(int i=mini;i<=maxi;i++){
      vector<pair<int,int>> v;
      v=mp[i];
      sort(v.begin(),v.end(),mycmp);
      vector<int> a;
      for(auto e:v){
          a.push_back(e.second);
      }
      ans.push_back(a);
  }
  return ans;
}

// lintcode 448
// inorder successor
TreeNode *tempans=nullptr;
    
    void findfn(TreeNode *root,TreeNode *p){
        if(root==nullptr)
        return;
        if(root->val > p->val){
            tempans=root;
            findfn(root->left,p);
            return;
        }
        if(root->val <= p->val){
            findfn(root->right,p);
            return;
        }
    }
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
       findfn(root,p);
       return tempans;
    }

// leetcode 235
// lca in bst
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)
            return nullptr;
        while(root){
            if(root->val > p->val && root->val > q->val)
                root=root->left;
            else if(root->val < p->val && root->val < q->val)
                root=root->right;
            else{
                break;
            }
        }
        return root;
    }


// leetcode 979
// distribute coins
    int a;
    int dfs(TreeNode *root){
         if(root==nullptr)
            return 0;
        int left=dfs(root->left);
        int right=dfs(root->right);
        a+=abs(left)+abs(right);
        return root->val+left+right-1;
    }
    int distributeCoins(TreeNode* root) {
        a=0;
        dfs(root);
        return a;
    }

// leetcode 450
// delete node in a BST
TreeNode *findmn(TreeNode *root){
    if(root==nullptr)
    return nullptr;
    while(root->left!=nullptr)
    root=root->left;
    return root;
}

TreeNode *deletefn(TreeNode *root){
    if(!root->left && !root->right){
    return nullptr;
    delete root;
    }
     if(root->left && !root->right){
    return root->left;
    delete root;
    }
     if(!root->left && root->right){
    return root->right;
    delete root;
    }
    if(root->left && root->right){
       TreeNode *temp=findmn(root->right);
       temp->left =  root->left;
        return root->right;
        delete root;
    }
    return root;
}

TreeNode *findfn(TreeNode *root,int key){
    if(root==nullptr)
    return nullptr;
    if(root->val==key){
     return root=deletefn(root);
    }
    if(root->val > key)
          root->left = findfn(root->left,key);
    else if(root->val < key)
          root->right=findfn(root->right,key);
        return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
        return findfn(root,key);
    }

// leetcode 105
// construct BT with preorder and inorder traversal
unordered_map<int,int> mp;
TreeNode *constructPI(vector<int>&preorder,int psi,int pei,vector<int>&inOrder,int isi,int iei){
    if(psi > pei && isi > iei)
    return nullptr;
    TreeNode *root = new TreeNode (preorder[psi]);
    int idx=mp[preorder[psi]];
    int cnt=idx-isi;
    root->left = constructPI(preorder,psi+1,psi+cnt,inOrder,isi,idx-1);
    root->right= constructPI(preorder,psi+cnt+1,pei,inOrder,idx+1,iei);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  for(int i=0;i<inorder.size();i++)
  mp[inorder[i]]=i;
  return constructPI(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
}

// leetcode 106
// construct BT with inorder and postorder traversal
unordered_map<int,int> mp;
TreeNode *constructIP(vector<int>&postorder,int psi,int pei,vector<int>&inOrder,int isi,int iei){
    if(psi>pei && isi>iei)
    return nullptr;
    int idx = mp[postorder[pei]];
    int cnt = idx - isi ;
    TreeNode *root = new TreeNode (postorder[pei]);
    root->left = constructIP(postorder,psi,psi+cnt-1,inOrder,isi,idx-1);
    root->right= constructIP(postorder,psi+cnt,pei-1,inOrder,idx+1,iei);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    for(int i=0;i<inorder.size();i++)
    mp[inorder[i]]=i;
    return constructIP(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1);
}