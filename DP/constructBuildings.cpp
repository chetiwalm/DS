#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> house(n,0);
    vector<int> empty(n,0);
    house[0]=1;
    empty[0]=1;
    for(int i=1;i<n;i++){
        house[i]=empty[i-1];
        empty[i]=house[i-1]+empty[i-1];
    }
    cout<< (house[n-1]+empty[n-1])*(house[n-1]+empty[n-1])<<endl;
    return 0;
}