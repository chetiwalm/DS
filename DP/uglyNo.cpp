#include<bits/stdc++.h>
using namespace std;

int uglyfn(int n){
    vector<int> ugly(n+1,0);
    ugly[0]=1;
    int i2=0,i5=0,i3=0;
    int n2=2,n3=3,n5=5;
    int nextugly=1;
    for(int i=1;i<n;i++){
      nextugly=min(n2,min(n3,n5));
      ugly[i]=nextugly;
      if(nextugly==n2){
          i2++;
          n2=ugly[i2]*2;
      }
      if(nextugly==n3){
          i3++;
          n3=ugly[i3]*3;
      }
      if(nextugly==n5){
          i5++;
          n5=ugly[i5]*5;
      }
    }
    return ugly[n-1];
}

int main(){
   int n;
   cin>>n;
   cout<<uglyfn(n)<<endl;
   return 0;
}