#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> c(n+1,0);
    c[0]=c[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            c[i]+=c[j]*c[i-j-1];
        }
    }
    cout<< c[n] <<endl;
    return 0;
}