#include<bits/stdc++.h>
using namespace std;

pair<int,int> minmax(vector<int>& symb,vector<char>& oper){
    int n=symb.size();
    vector<vector<int>> minval(n,vector<int>(n,INT_MAX));
    vector<vector<int>> maxval(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        minval[i][i]=symb[i];
        maxval[i][i]=symb[i];            
    }
    for(int gap=1;gap<n;gap++){
        for(int left=0;left+gap<n;left++){
            int right=left+gap;
            for(int i=left;i<right;i++){
                if(oper[i]=='+'){
                    minval[left][right]=min(minval[left][right],minval[left][i]+minval[i+1][right]);
                    maxval[left][right]=max(maxval[left][right],maxval[left][i]+maxval[i+1][right]);
                }
                else{
                    minval[left][right]=min(minval[left][right],minval[left][i]*minval[i+1][right]);
                    maxval[left][right]=max(maxval[left][right],maxval[left][i]*maxval[i+1][right]);
                }
            }
        }
    }
    return {minval[0][n-1],maxval[0][n-1]};
}

int main(){
    vector<int> symb = {1,2,3,4,5};
    vector<char> oper = {'+','*','+','*'};
    auto a = minmax(symb,oper);
    cout<<"MIN : "<<a.first<<endl;
    cout<<"MAX : "<<a.second<<endl;
    return 0;
}