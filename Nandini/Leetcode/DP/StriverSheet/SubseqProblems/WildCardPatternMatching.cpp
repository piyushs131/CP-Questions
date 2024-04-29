#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMatch(string b, string a) 
    {
       int n = a.size(),m = b.size();
        bool flag = true;
        vector<vector<bool> > dp(n+1,vector<bool> (m+1,false));
        dp[0][0] = true;
        for(int j=1 ; j<=m ; j++) dp[0][j] = false;
        for(int i=1 ; i<=n ; i++)
        {
            flag = true;
            for(int k=1 ; k<=i ; k++)
            {
                if(a[k-1]!='*') {flag= false;
                                break;}
            }
            dp[i][0] = flag;
        }
        
        for(int i=1 ; i<=n ; i++)
        {
            for(int j=1 ; j<=m ; j++)
            {
                if(a[i-1]==b[j-1] || a[i-1]=='?') dp[i][j] = dp[i-1][j-1];
                
                else if(a[i-1]=='*') dp[i][j] = dp[i-1][j] | dp[i][j-1];
                else dp[i][j] = false;
            }
        }
        
        return dp[n][m];
    }
};
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
