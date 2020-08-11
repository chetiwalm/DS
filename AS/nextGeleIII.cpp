#include<bits/stdc++.h>
using namespace std;

int nextele(int num){
    string str = to_string(num);
    int n=str.size();
    int x=-1;
    for(int i=n-1;i>=1;i--){
        if(str[i]>str[i-1]){
        x=i;
        break;
    }
    }
    int y=INT_MAX;
    int tbk;
    for(int i=x;i<str.size();i++){
        if(str[i]>str[x-1]){
           y=min(str[i]-str[x-1],y);
           tbk=i;
        }
    }
    swap(str[x-1],str[tbk]);
    reverse(str.begin()+x,str.end());
    return stoi(str);
}

int main(){
    int n=12347653;
    cout<<nextele(n)<<endl;
    // string s="12347653";
    // reverse(s.begin()+4,s.end());
    // cout<<s<<endl;

}