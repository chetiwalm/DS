#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n,0);
        vector<int> b(n,0);
        a[0]=1;
        b[0]=1;
        for(int i=1;i<n;i++){
            a[i]=a[i-1]+b[i-1];
            b[i]=a[i-1];
        }
        cout<<a[n-1]+b[n-1]<<endl;
    }
    return 0;
}