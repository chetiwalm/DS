//spoj
#include<bits/stdc++.h>
using namespace std;

void seive(int n){
    vector<bool> prime(true,n+1);
    for(int i=2;i*i<=n;i++){
        if(prime[i]){
            for(int j=i*i;j<=n;j+=i)
            prime[j]=false;
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i])
        cout<<i<<endl;
    }
}

int main(){  
  seive(200);
}