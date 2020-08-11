#include<bits/stdc++.h>
using namespace std;

int LCS(string s1,string s2,string s3){
    int n=s1.size();
    int m=s2.size();
    int o=s3.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(o+1,0)));
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            for(int k=o-1;k>=0;k--){
                if(s1[i]==s2[j] && s2[j]==s3[k])
                dp[i][j][k]=1+dp[i+1][j+1][k+1];
                else
                dp[i][j][k]=max(dp[i+1][j][k],max(dp[i][j+1][k],dp[i][j][k+1]));
            }
        }
    }
    return dp[0][0][0];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,o;
        cin>>n>>m>>o;
        string s1,s2,s3;
        cin>>s1>>s2>>s3;
        cout<<LCS(s1,s2,s3)<<endl;
    }
    return 0;
}