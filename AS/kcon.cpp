#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll kadane(vector<ll>&nums){
      ll cmax=0;
        ll omax=INT_MIN;
        for(ll i=0;i<nums.size();i++){
            cmax=max(nums[i],cmax+nums[i]);
            omax=max(omax,cmax);
        }
        return omax; 
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<ll> arr(n,0);
        for(ll i=0;i<n;i++) 
        cin>>arr[i];
        ll sum=0;
        for(ll ele:arr) sum+=ele;
        if(k==1){
            cout<<kadane(arr)<<endl;
            continue;
        }
        arr.insert(arr.end(),arr.begin(),arr.end());
        if(sum>=0)
        cout<<kadane(arr)+((k-2)*sum)<<endl;
        else 
        cout<<kadane(arr)<<endl;
    }
    return 0;
}