#include <bits/stdc++.h>
using namespace std;
bool f(int i,int j,string a,string b,vector<vector<int> > &dp)
{
   if(i<0 && j<0) return true;
   if(i<0 && j>=0) return false;
   if(i>=0 && j<0)
   {
      for(int k =0 ; k<=i ; k++)
      {
         if(a[k]!='*') return false;
      }
      return true;
   }

   if(dp[i][j]!=-1) return dp[i][j];

   if(a[i]==b[j] || a[i]=='?') return dp[i][j] = f(i-1,j-1,a,b,dp);
   if(a[i]=='*')
   return dp[i][j] = f(i-1,j,a,b,dp) | f(i,j-1,a,b,dp);

   return dp[i][j] = false;
}
bool wildcardMatching(string pattern, string text)
{
   int n= pattern.size(),m = text.size();
   vector<vector<int> > dp(n,vector<int>(m,-1));
   return f(n-1,m-1,pattern,text,dp);
}
