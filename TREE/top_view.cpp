// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        topView(root);
        cout << endl;
    }
    return 0;
}




// } Driver Code Ends


//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
void topView(struct Node *root)
{
    unordered_map<int,int> mp;
    queue<pair<int,Node*>> q;
    int vlevel=0;
    q.push(make_pair(0,root));
    while(!q.empty()){
        int size=q.size();
        while(size--){
           auto t=q.front();
           q.pop();
           if(mp.find(t.first)==mp.end())
            mp[t.first]=t.second->data;
            if(t.second->left)
            q.push(make_pair(t.first-1,t.second->left));
            if(t.second->right)
            q.push(make_pair(t.first+1,t.second->right));
        }
    }
    int mini=0;
    int maxi=0;
    for(auto ele:mp){
        maxi=max(maxi,ele.first);
        mini=min(mini,ele.first);
    }
    for(int i=mini;i<=maxi;i++)
    cout<<mp[i]<<" ";
}


