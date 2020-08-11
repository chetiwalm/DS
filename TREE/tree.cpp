#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  int val=0;
  Node *left=nullptr;
  Node *right=nullptr;
  Node(){

  }
  Node(int val){
      this->val=val;
  }
  Node(int val,Node *left,Node *right){
      this->val=val;
      this->left=left;
      this->right=right;
  }
};
int idx=0;

Node *createTree(vector<int>&arr){
    if(idx==arr.size() || arr[idx]==-1){
        idx++;
        return nullptr;
    }
    Node *node = new Node(arr[idx++]);
    node->left=createTree(arr);
    node->right=createTree(arr);
    return node;
}

void display(Node *node){
    if(node==nullptr)
    return;
    string str="";
    str += (node->left)?to_string(node->left->val):" . ";
    str += " -> "+to_string(node->val)+" <- ";
    str += (node->right)?to_string(node->right->val):" . ";
    cout<<str<<endl;
    display(node->left);
    display(node->right);
}

//          inOrder Traversal

//1.recursive
void inOrder_01(Node *node){
    if(node){
     inOrder_01(node->left);;
     cout<<node->val<<" ";
     inOrder_01(node->right);
    }
}

//2.iterative(using stack)
void inOrder_02(Node *node){
    stack<Node*> st;
    Node *curr=node;
    while(curr!=nullptr || !st.empty()){
        while(curr!=nullptr){
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        cout<<curr->val<<" ";
        curr=curr->right;
    }
}


//           preOrder Traversal
//1.Recursive
void preOrder_01(Node *node){
    if(node){
        cout<<node->val<<" ";
        preOrder_01(node->left);
        preOrder_01(node->right);
    }
}

//2.Iterative (using stack)
void preOrder_02(Node *node){
    stack<Node*> st;
    st.push(node);
    while(!st.empty()){
        Node *rmv=st.top();
        st.pop();
        cout<<rmv->val<<" ";
        if(rmv->right) 
        st.push(rmv->right);
        if(rmv->left)
        st.push(rmv->left);
    }
}

//     postOrder
void postOrder_01(Node *node){
    if(node){
        postOrder_01(node->left);
        postOrder_01(node->right);
        cout<<node->val<<" ";
    }
}

void levelorder(Node *node){
    queue<Node*> q;
    while(!q.empty()){
        int size=q.size();
        while(size--){
           Node *top = q.front();
           q.pop();
           cout<<top->val<<" ";
           if(top->left) 
           q.push(top->left);
           if(top->right)
           q.push(top->right);
        }
    }
}

void solve(){
    //  vector<int> arr = {10, 20, 40, -1, -1, 50, 80, -1, -1, 90, -1, -1, 30, 60, 
    //                     100, -1, -1, -1, 70, 110, -1, -1, 120, -1, -1};
    vector<int> arr= {3,9,-1,-1,20,15,-1,-1,7,-1,-1};
    Node *root=createTree(arr);
    // display(root);
    // inOrder_01(root);
    // cout<<endl;
    // inOrder_02(root);
    // cout<<endl;
    // preOrder_01(root);
    // cout<<endl;
    // preOrder_02(root);
    // cout<<endl;
    // postOrder_01(root);
    // cout<<endl;
}
int main(){
  solve();
}