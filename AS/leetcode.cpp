#include<bits/stdc++.h>
using namespace std;

//leetcode 925
//long pressed name
bool isLongPressedName(string name, string typed) {
        int i=0,j=0;
        while(j<typed.size()){
            if(i<name.size() && name[i]==typed[j]){
                ++i,++j;
            }
            else if(i>0 && name[i-1]==typed[j]) 
                ++j;
            else
                return false;
        }
        return i==name.size();
    }

//lintcode 903
//range addition
vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        // Write your code here
        vector<int> arr(length,0);
        for(int i=0;i<updates.size();i++){
            int x=updates[i][0];
            int y=updates[i][1];
            int val=updates[i][2];
            arr[x]+=val;
            if(y+1<arr.size())
            arr[y+1]-=(val);
        }
    
        for(int i=1;i<length;i++){
            arr[i]+=arr[i-1];
        }
        return arr;
    }

//leetcode 189
//reverse array
void reverse(vector<int>&arr,int li,int ri){
    while(li < ri ){
        swap(arr[li],arr[ri]);
        li++;
        ri--;
    }
}
    void rotate(vector<int>& arr, int x) {
     x=x%arr.size();
    reverse(arr,0,arr.size()-1);
    reverse(arr,0,x-1);
    reverse(arr,x,arr.size()-1); 
    }


//leetcode 556
//next greater element III
int nextGreaterElement(int num) {
string str = to_string(num);
    int n=str.size();
     if(n>=10)
         return -1;
    int x=-1;
    for(int i=n-1;i>=1;i--){
        if(str[i]>str[i-1]){
        x=i;
        break;
    }
    }
        if(x==-1)
            return -1;
    int y=INT_MAX;
    int t;
    for(int i=x;i<str.size();i++){
        if(str[i]>str[x-1]){
           y=min(str[i]-str[x-1],y);
           t=i;
        }
    }
    swap(str[x-1],str[t]);
    reverse(str.begin()+x,str.end());
    return stoi(str);
   }

//leetcode 899
string orderlyQueue(string str, int k) {
        if(k==1){
            string ans=str;
            for(int i=0;i<str.size();i++){
                string x=str.substr(i)+str.substr(0,i);
                if(x.compare(ans)<0)
                    ans=x;
            }
            return ans;
        }
            else{
                sort(str.begin(),str.end());
                return str;
            }
    }


//leetcode 53
//maximum subarray
 int maxSubArray(vector<int>& v) {
        if (v.size() == 0)
        return 0;
    int  cmax = v[0];
    int omax = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        cmax = max(v[i], cmax + v[i]);
        omax = max(cmax, omax);
    }

    return omax;
    }

//leetcode 11
//container with most water
int maxArea(vector<int>& arr) {
        int li=0,ri=arr.size()-1,area=0;
        while(li<ri){
            if(arr[li]<arr[ri]) {
                 area=max(area,(ri-li)*arr[li]);
                li++;
            }
            else{
                  area=max(area,(ri-li)*arr[ri]);
                ri--;
            }
        }
        return area;
    }

//leetcode 26
//remove dupli from sorted arrays
//https://www.geeksforgeeks.org/find-the-number-of-jumps-to-reach-x-in-the-number-line-from-zero/
int removeDuplicates(vector<int>& nums) {
          if (nums.size() == 0) return 0;
    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
    }

// leetcode 238 
// Product of Array Except Self
 vector<int> productExceptSelf(vector<int>& nums) {
  int n=nums.size();
  vector<int> left(n,1);
  vector<int> right(n,1);

    for(int i=1;i<n;i++)
    left[i]=left[i-1]*nums[i-1];

    for(int i=n-1;i>=1;i--)
    right[i-1]=right[i]*nums[i];
    
    for(int i = 0;i<nums.size() ;i++){
        nums[i] = left[i] * right[i];
    }
    return nums;
  
}

//leetcode 754
//reach a number
int getsum(int n){
        return n*(n+1)/2;
    }
    int reachNumber(int n) {
        n=abs(n);
        int ans=0;
         while (getsum(ans) < n or (getsum(ans) - n) & 1) 
        ans++; 
        return ans;
    }


//leetcode 296
//best meeting point
    
    int dist(vector<int>&row,vector<int>&col,int x,int y){
        int d=0;
        for(int i=0;i<row.size();i++){
            d+=abs(x-row[i])+abs(y-col[i]);
        }
        return d;
    } 
     
    int minTotalDistance(vector<vector<int>> &arr) {
        // Write your code here
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
        return ans;
    }


//leetcode 670
//maximum swap
int maximumSwap(int num) {
    string str=to_string(num);
   int a=-1;
   for(int i=0;i<str.size()-1;i++){
       if(str[i]<str[i+1] ){
          a=i;
          break;
       } 
   }
        
   if(a==-1)
   return stoi(str);
        
   int maxidx=a+1;
   char maxc=str[a+1];
   for(int i=a+1;i<str.size();i++){
        if(str[i]>=maxc){
           maxc=str[i];
           maxidx=i;
        }
   }
        
    for(int i=0;i<=a;i++){
      if(str[i] < maxc){
        swap(str[maxidx],str[i]);
        break;
      }
   }
    
   
   int ans = stoi(str);
   return ans;
    }


//leetcode 881
//boats maximum
int numRescueBoats(vector<int>& arr, int limit) {
        if(arr.size()==1) return 1;
        if(limit==1) return arr.size();
        sort(arr.begin(),arr.end());
        int li=0;
        int ri=arr.size()-1;
        int cnt=0;
        while(li<=ri){
            if(arr[li]+arr[ri]<=limit)
                li++;
             ri--;
             cnt++;
        }
        return cnt;
    }


//leetcode 169
//majority element
int majorityElement(vector<int>& arr) {
        int n=arr.size();
        int val=arr[0];
        int cnt=0;
        for(int i=0;i<n;i++){
            if(val==arr[i])
                cnt++;
            else{
                if(cnt>0) cnt--;
                else{
                    val=arr[i];
                    cnt=0;
                }
            }
        }
        return val;
    }

//leetcode 229
//maximum element II
vector<int> majorityElementII(vector<int>& arr) { //function name - majorityElement
        int n=arr.size();
        if(n==0) return {};
        int val1=arr[0];
        int val2;
        int cnt1=1;
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(arr[i]==val1) cnt1++;
            else if(arr[i]==val2) cnt2++;
            else if(cnt1==0){
                val1=arr[i];
                cnt1=1;
            }
            else if(cnt2==0){
                val2=arr[i];
                cnt2=1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        if(count(arr.begin(),arr.end(),val1)>n/3)
           ans.push_back(val1);
        if(count(arr.begin(),arr.end(),val2)>n/3)
            ans.push_back(val2);
        return ans;
    }


//https://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/


//leetcode 769
//maximum chunks
int maxChunksToSorted(vector<int>& arr) {
        int cnt=0; //chunk count
        int maxele=arr[0];
        for(int i=0;i<arr.size();i++){
            maxele=max(arr[i],maxele);
            if(maxele==i) cnt++;
        }
        return cnt;
    }

//leetcode 768
//maximum chunks II
 int maxChunksToSorted(vector<int>& arr) {
           int n=arr.size();
    vector<int> max_from_start(n,0);
    vector<int> min_from_end (n,0);
    max_from_start[0]=arr[0];
    for(int i=1;i<arr.size();i++)
        max_from_start[i]=max(arr[i],max_from_start[i-1]);
    min_from_end[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
        min_from_end[i]=min(arr[i],min_from_end[i+1]);
    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(max_from_start[i]<=min_from_end[i+1])
        cnt++;
    }       
    
    return cnt+1;
    }    

int main(){
    cout<<"tbk"<<endl;
}