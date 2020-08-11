#include<bits/stdc++.h>
using namespace std;

int superUgly(int n,vector<int>&factors){
    vector<int> dp(n,INT_MAX);
    dp[0]=1;
    vector<int> idx(factors.size(),0);
    for(int i=1;i<n;i++){
        for(int j=0;j<idx.size();j++){
            dp[i]=min(dp[i],dp[idx[j]]*factors[j]);
        }
        for(int j=0;j<idx.size();j++){
            if(dp[idx[j]]*factors[j]==dp[i])
            idx[j]++;
        }
    }
    return dp[n-1];
}

int main(){
    vector<int> factors = {2,3,5};
    int n=50;
    cout<<superUgly(n,factors)<<endl;
    return 0;
}