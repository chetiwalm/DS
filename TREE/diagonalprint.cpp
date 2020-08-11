#include<bits/stdc++.h>
using namespace std;

class Node{
public:
 int data=0;
 Node *left=nullptr;
 Node *right=nullptr;
 Node(){

 }
 Node(int data){
    this->data=data;
 }
};

vector<vector<int>> diagonalTraverse(Node *root){
    queue<pair<int,Node*>> q;
    unordered_map<int,vector<int>> mp;
    q.push(make_pair(0,root));
    while(!q.empty()){
        int size=q.size();
        while(size--){
            auto t=q.front();
            q.pop();
            int dlevel=t.first;
            Node* tnode=t.second;
            mp[dlevel].push_back(tnode->data);
            if(tnode->left)
            q.push({dlevel-1,tnode->left});
            if(tnode->right)
            q.push({dlevel,tnode->right});
        }
    }
    int mini=0;
    int maxi=0;
    for(auto ele:mp){
        mini=min(mini,ele.first);
        maxi=max(maxi,ele.first);
    }
    vector<vector<int>> ans;
    for(int i=maxi;i>=mini;i--){
        vector<int> a;
        a=mp[i];
        ans.push_back(a);
    }
    return ans;
}

int main(){
    Node *root=new Node(8);
    root->left = new Node(3); 
    root->right = new Node(10); 
    root->left->left = new Node(1); 
    root->left->right = new Node(6); 
    root->right->right = new Node(14); 
    root->right->right->left = new Node(13); 
    root->left->right->left = new Node(4); 
    root->left->right->right = new Node(7);

    vector<vector<int>> ans=diagonalTraverse(root);
    for(vector<int> v:ans){
        for(int ele:v){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}