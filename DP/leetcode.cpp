#include<bits/stdc++.h>
using namespace std;


// leetcode 70
// climbing stairs
int climbStairs(int n) {
   if(n==0)
            return 0;
        vector<int> ans(n+1,0);
        ans[0]=1;
        ans[1]=1;
        for(int i=2;i<=n;i++){
            ans[i]=ans[i-1]+ans[i-2];
        }
        return ans[n];       
}

// leetcode 45
// jump game 2

// o(n^2) using DP

   int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        vector<int> ans(n,INT_MAX);
        ans[0]=0;
        for(int i=0;i<nums.size();i++){
             if(i > 0 && nums[i] < nums[i-1]){
                continue;
            }
            for(int j=1;j<=nums[i];j++){
                if(i+j<n)
                    ans[i+j]=min(ans[i+j],ans[i]+1);
            }
        }
        return ans[n-1];
    }

// O(n) greedy solution (bfs)

int jump(vector<int>& nums) {
     int ans=0,cend=0,cmax=0;
        for(int i=0;i<nums.size()-1;i++){
            cmax=max(cmax,i+nums[i]);
            if(i==cend){
                ans++;
                cend=max(cmax,cend);
            }
            
        }
        return ans;
    }

// leetcode 64
// Minimum Path Sum

int minPathSum(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();  
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0)
            continue;
            int a = (i+1<n)?grid[i+1][j]:1e7;
            int b = (j+1<m)?grid[i][j+1]:1e7;
            grid[i][j]+=min(a,b);
        }
    }      
    return grid[n][m];
}

// leetcode 300
// Longest Increasing Subsequence

// O(n^2) 
// using DP

int lengthOfLIS(vector<int>& nums) {
   int n=nums.size();
   if(n==0)
   return 0;
   int ans=INT_MIN;
   vector<int> dp(n,1);
   for(int i=1;i<n;i++){
       for(int j=0;j<i;j++){
           if(nums[i]>nums[i])
           dp[i]=max(dp[i],dp[j]+1);
       }
       ans=max(ans,dp[i]);
   }
   return ans;
}

// O(nlogn)
int lengthOfLIS(vector<int>& nums) {
  int n=nums.size();
  if(n==0)
  return 0;
  int ans=0;
  vector<int> minval(n,0);
  for(int ele:nums){
      int li=0;
      int ri=ans;
      while(li<ri){
          int mid=(li+ri)/2;
          if(minval[mid]<ele)
          li=mid+1;
          else
          ri=mid;
      }
      minval[li]=ele;
      if(li==ans)
      ans++;
  }        
  return ans;
}

int LIS(vector<int>&nums){
    int n=nums.size();
   if(n==0)
   return 0;
   int ans=INT_MIN;
   vector<int> dp(n,1);
   for(int i=1;i<n;i++){
       for(int j=0;j<i;j++){
           if(nums[i]>nums[i])
           dp[i]=max(dp[i],dp[j]+1);
       }
       ans=max(ans,dp[i]);
   }
   return ans;
}

// Leetcode 354
// Russian Doll Envelope 

bool mycomp(vector<int>&a,vector<int>&b){
    if(a[0]==b[0])
    return a[1]>b[1];
    return a[1]<b[1];
}
int maxEnvelopes(vector<vector<int>>& envelopes) {
    int n=envelopes.size();
    sort(envelopes.begin(),envelopes.end(),mycomp);
    vector<int> v(n);
    for(int i=0;i<n;i++)
    v[i]=envelopes[i][1];
    return LIS(v);
}



// 29 june class 3

// leetcode 121
// Best Time to Buy and Sell Stock

int maxProfit(vector<int>& prices) {
        int T_i10=0;
        int T_i11=INT_MIN;
        for(int val:prices){
            int nextT_i10=max(T_i10,T_i11+val);
            int nextT_i11=max(T_i11,-val);
            T_i10=nextT_i10;
            T_i11=nextT_i11;
        }
        return T_i10;
    }


// leetcode 122
// Best Time to Buy and Sell Stock II
int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        int T_ik0=0;
        int T_ik1=INT_MIN;
        for(int val:prices){
            int temp=T_ik0;
            T_ik0=max(T_ik0,T_ik1+val);
            T_ik1=max(T_ik1,temp-val);
        }
        return T_ik0;
    }


// leetcode 123
// Best Time to Buy and Sell Stock III
int maxProfit(vector<int>& prices) {
  int T_i20=0;
  int T_i21=INT_MIN;
  int T_i10=0;
  int T_i11=INT_MIN;
  for(int val:prices){
      T_i20=max(T_i20,T_i21+val);
      T_i21=max(T_i21,T_i10-val);
      T_i10=max(T_i10,T_i11+val);
      T_i11=max(T_i11,-val);
  }        
  return T_i20;
}


// leetcode 188
// Best Time to Buy and Sell Stock IV
    int maxProfit(int k, vector<int>& prices) {
   if(k >= prices.size() >> 1){
    // same as infinite transaction 122
      int T_ik0=0;
      int T_ik1=INT_MIN;
      for(int val:prices){
          int temp=T_ik0;
          T_ik0=max(T_ik0,T_ik1+val);
          T_ik1=max(T_ik1,temp-val);
      }
      return T_ik0;
   }
   vector<int> T_ik0(k+1,0);
   vector<int> T_ik1(k+1,INT_MIN);
   for(int val:prices){
       for(int j=k;j>=1;j--){
           T_ik0[j]=max(T_ik0[j],T_ik1[j]+val);
           T_ik1[j]=max(T_ik1[j],T_ik0[j-1]-val);
       }
   }        
   return T_ik0[k];
}

// leetcode 309
// Best Time to Buy and Sell Stock with Cooldown
int maxProfit(vector<int>& prices) {
   int T_ik0=0;
   int T_ik1=INT_MIN;
   int T_ik0_old=0;
   for(int val:prices){
       int temp=T_ik0;
       int T_ik0=max(T_ik0,T_ik1+val);
       int T_ik1=max(T_ik1,T_ik0_old-val);
       int T_ik0_old=temp;
   }        
   return T_ik0;
}

// leetcode 741
// Best Time to Buy and Sell Stock with Transaction Fee
int maxProfit(vector<int>& prices,int fee) {
        if(prices.size()==0)
            return 0;
        int T_ik0=0;
        int T_ik1=INT_MIN;
        for(int val:prices){
            int temp=T_ik0;
            T_ik0=max(T_ik0,T_ik1+val);
            T_ik1=max(T_ik1,temp-val-fee);
        }
        return T_ik0;
    }


// ****************************************************************
// class - 4
// ****************************************************************


// lintcode 514
// paint fence
int numWays(int n, int k) {
        // write your code here
        if(n==1)
        return k;
        int samecolor = k;
        int diffcolor = k*(k-1);
        for(int i=2;i<n;i++){
            int tempcolor=samecolor;
            samecolor=diffcolor;
            diffcolor=(tempcolor+diffcolor)*(k-1);
        }
        return diffcolor+samecolor;
    }

// lintcode 515
// paint house 
int minCost(vector<vector<int>> &costs) {
    int n=costs.size();
    if(n==0)
    return 0;
    vector<vector<int>> dp(n,vector<int>(3,0));
    dp[0]=costs[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
           if(j==0)
           dp[i][j]=costs[i][j]+min(dp[i-1][1],dp[i-1][2]);
           else if(j==1)
           dp[i][j]=costs[i][j]+min(dp[i-1][0],dp[i-1][2]);
           else
           dp[i][j]=costs[i][j]+min(dp[i-1][0],dp[i-1][1]);
        }
    }
    return min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
}

// lintcode 516
// Paint House II

pair<int,int> getmin1min2(vector<vector<int>>&dp,int i,int j,int n,int k){
    int min1=INT_MAX;
    int min2=INT_MAX;
    for(int a=0;a<k;a++){
        if(dp[i-1][a]<min1){
            min2=min1;
            min1=dp[i-1][a];
        }
        else if(dp[i-1][a] < min2 && dp[i-1][a] != min1)
        min2=dp[i-1][a];
    }
    return {min1,min2};
}

int minCostII(vector<vector<int>> &costs) {
    int n=costs.size();
    if(n==0)
    return 0;
    int k=costs[0].size();
    if(k==0)
    return 0;
    vector<vector<int>> dp(n,vector<int>(k,0));
    dp[0]=costs[0];
    int min1=INT_MAX,min2=INT_MAX;
    // for(int i=0;i<k;i++){
    //     if(dp[0][i] < min1){
    //         min2=min1;
    //         min1=dp[0][i];
    //     }
    //     else if(dp[0][i] < min2 && dp[0][i] !=min1)
    //     min2=dp[0][i];
    // }

    for(int i=1;i<n;i++){
        for(int j=0;j<k;j++){
                auto a = getmin1min2(dp,i,j,n,k);
                min1=a.first;
                min2=a.second;
            if(dp[i-1][j]!=min1)
            dp[i][j]=costs[i][j]+min1;
            else
            dp[i][j]=costs[i][j]+min2;
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<k;i++)
    ans=min(ans,dp[n-1][i]);
    return ans;
}


// **************************************
// class 5
// **************************************

// leetcode 311
// Burst Balloons
int maxCoins(vector<int>& nums) {
    int n=nums.size();
    if(n==0)
    return 0;
    nums.resize(nums.size()+2);      
    n=nums.size();
    nums[n-1]=1;
    for(int i=n-2;i>=1;i--)
    nums[i]=nums[i-1];
    nums[0]=1;
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int gap=2;gap<=n;gap++){
      for(int left=0;left<=n-gap-1;left++){
          int right=left+gap;
          for(int i=left+1;i<right;i++){
              dp[left][right]=max(dp[left][right],
              dp[left][i]+dp[i][right]+nums[i]*nums[left]*nums[right]);
          }
      }
    }
    return dp[0][n-1];
}

// leetcode 1039  
// Minimum Score Triangulation of Polygon
int minScoreTriangulation(vector<int>& nums) {
   int n=nums.size();
   if(n==0)
   return 0;
   vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
    for(int gap=2;gap<=n;gap++){
      for(int left=0;left<=n-gap-1;left++){
          int right=left+gap;
          dp[left][right]=INT_MAX;
          for(int i=left+1;i<right;i++){
             dp[left][right]=min(dp[left][right],
             nums[left]*nums[i]*nums[right]+dp[left][i]+dp[i][right]);
          }
      }
    }
    return dp[0][n-1];
}


// *********************************************
// class 5
// *********************************************


// lintcode 725
// Boolean Parenthesization
int countParenth(string &symb, string &oper) {
        // write your code here
        int n=symb.size();
    vector<vector<int>> True(n,vector<int>(n,0));
    vector<vector<int>> False(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        if(symb[i]=='T'){
            True[i][i]=1;
            False[i][i]=0;
        }
        else{
            True[i][i]=0;
            False[i][i]=1;
        }
    }
    for(int gap=1;gap<n;gap++){
        for(int left=0;left+gap<n;left++){
            int right=left+gap;
            for(int i=left;i<right;i++){
                  if(oper[i]=='|'){
                        True[left][right] += True[left][i]*False[i+1][right] + False[left][i]*True[i+1][right] + True[left][i]*True[i+1][right];
                        False[left][right] += False[left][i]*False[i+1][right];
                    }
                else if(oper[i]=='&'){
                    
                        True[left][right] += True[left][i]*True[i+1][right];
                        False[left][right] += True[left][i]*False[i+1][right] + False[left][i]*True[i+1][right] + False[left][i]*False[i+1][right];
                    }
                else{
                        
                        True[left][right]+=True[left][i]*False[i+1][right]+False[left][i]*True[i+1][right];
                        False[left][right]+=True[left][i]*True[i+1][right]+False[left][i]*False[i+1][right];
                }
            }
        }
    }
    return True[0][n-1];
    }


// *********************************************
// class - 8
// *********************************************

// leetcode 741
// Cherry Pickup
int dp[50][50][50];

int helper(vector<vector<int>>&grid,int r1,int c1,int r2,int n){
    int c2=r1-r2+c1;
    
    if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
    return INT_MIN;
    
    if(dp[r1][c1][r2]!=-1)
    return dp[r1][c1][r2];

    if(r1==n-1 && c1==n-1)
    return grid[r1][c1];

    int ans = grid[r1][c1];

    if(r1!=r2 || c1!=c2)
    ans+=grid[r2][c2];

    int temp1=helper(grid,r1,c1+1,r2+1,n);
    int temp2=helper(grid,r1+1,c1,r2,n);
    int temp3=helper(grid,r1,c1+1,r2,n);
    int temp4=helper(grid,r1+1,c1,r2+1,n);

    ans+=max(temp1,max(temp2,max(temp3,temp4)));
    dp[r1][c1][r2]=ans;
    return ans;
}

int cherryPickup(vector<vector<int>>& grid) {
    int n=grid.size();
    memset(dp,-1,sizeof(dp));
    return max(0,helper(grid,0,0,0,n));
}

// leetcode 1143 
// Longest Common Subsequence
int longestCommonSubsequence(string s1, string s2) {
   int n=s1.size();
   int m=s2.size();
   vector<vector<int>> dp(n+1,vector<int>(m+1,0));
   for(int i=s1.size()-1;i>=0;i--){
       for(int j=s2.size()-1;j>=0;j--){
           if(s1[i]==s2[j])
           dp[i][j]=1+dp[i+1][j+1];
           else
           dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
       }
   }
   return dp[0][0];
}

// leetcode 516
// longest palindromic subsequence

int longestPalindromeSubseq(string s1) {
        string s2=s1;
        reverse(s2.begin(),s2.end());
        return longestCommonSubsequence(s1,s2);  //using leetcode 1143
}