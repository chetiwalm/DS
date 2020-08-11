#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
    vector<int> arr(n,0);
    vector<int> dep(n,0);
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) cin>>dep[i];
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int i=0,j=0;
    int cplat=0;
    int ans=INT_MIN;
    while(i<arr.size() && j<dep.size()){
        if(arr[i]<=dep[j]){
            cplat++;
            i++;
        }
        else{
            cplat--;
            j++;
        }
        ans=max(ans,cplat);
    }
    cout << ans << endl;
    }
    return 0;
}