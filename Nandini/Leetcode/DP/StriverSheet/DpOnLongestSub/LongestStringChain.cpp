#include <bits/stdc++.h>
using namespace std;
bool compare(string &s1 , string &s2)
{
   if(s1.size()!=s2.size()+1) return false;

   int f1=0,f2=0;
   while(f1<s1.size())
   {
       if(s1[f1] == s2[f2])
       {
           f1++,f2++;
       }
       else 
       {
           f1++;
       }
   }

   if(f1==s1.size() && f2==s2.size()) return true;
   return false;
}
bool cmp(string &s1,string &s2)
{
    return s1.size()<s2.size();
}
int longestStrChain(vector<string> &arr)
{
    int n = arr.size();
   vector<int> dp(n,1);
   int maxi = 1;
   sort(arr.begin(),arr.end(),cmp);
   for(int i=0 ; i<n ; i++)
   {
       for(int j=0 ; j<i ; j++)
       {
           if(compare(arr[i],arr[j]) && dp[i]<dp[j]+1)
           {
               dp[i] = dp[j]+1;
           }
       }
       maxi = max(maxi,dp[i]);
   }
   return maxi;
}