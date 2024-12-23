#include <bits/stdc++.h>
using namespace std;
class Tabulation {
public:
    int longestCommonSubsequence(string s, string t) 
    {
       int n1 = s.size(),n2 = t.size();
        vector<vector<int> > dp(n1+1,vector<int> (n2+1,-1));
       for(int i=0 ;i <=n1 ; i++)
           dp[i][0] = 0;
        
        for(int j=0 ;j <=n2 ; j++)
           dp[0][j] = 0;
        
        for(int i=1 ;i<=n1 ; i++)
        {
            for(int j=1 ; j<=n2 ; j++)
            {
                if(s[i-1]==t[j-1])  dp[i][j] = 1+ dp[i-1][j-1];

                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[n1][n2];
    }
};
int longestSub(string s,string t,int i,int j,vector<vector<int> > &dp)
{
   if(i<0 || j<0) return 0;
   if(dp[i][j]!=-1) return dp[i][j];

   if(s[i]==t[j]) return dp[i][j] = 1+longestSub(s,t,i-1,j-1,dp);

   return dp[i][j] = max(longestSub(s,t,i-1,j,dp),longestSub(s,t,i,j-1,dp));
}
int lcs(string s, string t)
{
	  int n1 = s.size(),n2= t.size();
    vector<vector<int> > dp(n1 ,vector<int>(n2,-1));
    return longestSub(s,t,n1-1,n2-1,dp);
}
