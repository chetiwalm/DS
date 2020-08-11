#include<bits/stdc++.h>
using namespace std;

int helper(vector<int>&arr,int n,int l,int r){
    int x = ceil(sqrt(n));
    vector<int> v(x,0);
    for(int i=0;i<n;i++){
        int j=i/n;
		v[j]=min(v[j],arr[i]);
    }
    int ans=INT_MAX;
    while(l%n!=0){
		ans=min(ans,arr[l]);
		l++;
	}
	while(r>=l+n-1){
		ans=min(ans,v[l/n]);
		l=l+n;
	}
	while(l<=r){
		ans=min(ans,arr[l]);
		l++;
	}
	return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int q;
    cin>>n;
    int l,r;
    while(q--){
        cin>>l>>r;
        cout<<helper(arr,n,l,r)<<endl;
    }
    return 0;
}