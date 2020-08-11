#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
    vector<pair<int,int>> arr (n);
    int length=100001;
    
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    vector<int> res (length,0);
    for(int i=0;i<arr.size();i++){
      int x=arr[i].first;
      int y=arr[i].second;
      res[x]+=1;
      if(y+1<res.size())
      res[y+1]-=1;
    }
    for(int i=1;i<res.size();i++)
    res[i]+=res[i-1];
    
    int cntk=0;
    for(int ele:res){
        if(ele==k)
        cntk++;
    }
    vector<int> ark(length,0);    //number of k
    vector<int> ark1(length,0);   //number of k+1
    
    for(int i=1;i<length;i++){
        if(res[i]==k)
        ark[i]=ark[i-1]+1;
        else
        ark[i]=ark[i-1];
    }
    
    for(int i=1;i<length;i++){
        if(res[i]==k+1)
        ark1[i]=ark1[i-1]+1;
        else
        ark1[i]=ark1[i-1];
    }
    
    int ans=INT_MIN;
    for(int i=0;i<arr.size();i++){
        int x=arr[i].first;
        int y=arr[i].second;
        int loss = ark[y]-ark[x-1];
        int gain = ark1[y]-ark1[x-1];
        ans=max(ans,cntk-loss+gain);
    }
    cout<<ans<<endl;
    }
    
    return 0;
}