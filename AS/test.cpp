#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int maximumswap(int num){
   string str=to_string(num);
   int a=-1;
   for(int i=0;i<str.size()-1;i++){
       if(str[i]<str[i+1]){
          a=i;
          break;
       }
   }

   if(a==-1)
   return stoi(str);

   int maxidx=a+1;
   char maxc=str[a+1];
   for(int i=a+1;i<str.size(); i++){
        if(str[i]>=maxc){
           maxc=str[i];
           maxidx=i;
        }
   }

   for(int i=0;i<=a;i++){
      if(str[i]<maxc){
         swap(str[maxidx],str[i]);
         break;
      }
   }
   int ans = stoi(str);
   return ans;
}

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

int main(){
   int n; cin>>n;
   cout<<maximumswap(n)<<endl;
   cout<<maximumSwap(n)<<endl;
   return 0;
}
// 90909011