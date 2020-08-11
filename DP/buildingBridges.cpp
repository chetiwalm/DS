#include<bits/stdc++.h>
using namespace std;

int LIS(vector<int>&arr){
    int n=arr.size();
    int ans=INT_MIN;
    vector<int> dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j])
            dp[i]=max(dp[i],dp[j]+1);
        }
        ans=max(ans,dp[i]);
    }
    return ans;
}

int main(){
    
    vector<int> north = {8,1,4,3,5,2,6,7};
    // we can also apply LIS on north for ans

    
    vector<int> south(north.size());

    for(int i=0;i<north.size();i++)
    south[i]=i+1;

    vector<pair<int,int>> ns(north.size());
    for(int i=0;i<north.size();i++){
        ns[i].first = north[i];
        ns[i].second = south[i];
    }

    sort(ns.begin(),ns.end());

    vector<int> a(north.size());

    for(int i=0;i<north.size();i++){
        a[i]=ns[i].second;
    }
    
    for(int ele:a)
    cout<<ele<<" ";cout<<endl;

    cout<<LIS(a)<<endl;

    return 0;
}