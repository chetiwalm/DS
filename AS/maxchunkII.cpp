#include<bits/stdc++.h>
using namespace std;

int maxChunksToSorted(vector<int>& arr) {
    int n=arr.size();
    vector<int> min_from_end (n+1,0);
    min_from_end.back()=INT_MAX;
    for(int i=n-1;i>=0;i--)
        min_from_end[i]=min(arr[i],min_from_end[i+1]);
    int cnt=0;
    int v=INT_MIN;
    for(int i=0;i<n;i++){
        v=max(v,arr[i]);
        if(v<=min_from_end[i+1])
        cnt++;
    }
   return cnt;
}

int main(){
    vector<int> arr = {18,12,16,22,20,24,30,28};
    cout<<maxChunksToSorted(arr)<<endl;
    return 0;
}