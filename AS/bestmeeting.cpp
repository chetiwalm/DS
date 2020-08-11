#include<bits/stdc++.h>
using namespace std;

int dist(vector<int>&row,vector<int>&col,int x,int y){
        int d=0;
        for(int i=0;i<row.size();i++){
            d+=abs(x-row[i])+abs(y-col[i]);
        }
        return d;
    }

int main(){
    vector<vector<int>> arr = {{1,0,0,0,1},{0,0,0,0,0},{0,0,1,0,0}};
    int n=arr.size();
        int m=arr[0].size();
        vector<int> row;
        vector<int> col;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==1){
                    row.push_back(i);
                }
            }
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(arr[i][j]==1)
                col.push_back(j);
            }
        }
        int x=row[row.size()/2];
        int y=col[col.size()/2];
        cout<<x<<" "<<y<<endl;
        int ans=dist(row,col,x,y);
        cout<<ans<<endl;
}