#include<bits/stdc++.h>
using namespace std;

int largestSq(vector<vector<int>>&arr,int n,int m){
    vector<vector<int>> dp (n,vector<int>(m,0));
    int ans=1;
    dp[0]=arr[0];
    for(int i=0;i<n;i++)
        dp[i][0]=arr[i][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0)
            continue;
            if(arr[i][j]==1)
            dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
            else
            dp[i][j]=0;
            ans=max(ans,dp[i][j]);
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> arr (n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        cin>>arr[i][j];
        cout<<largestSq(arr,n,m)<<endl;
    }
    return 0;
}