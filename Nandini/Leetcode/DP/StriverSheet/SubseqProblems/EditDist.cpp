#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int i,int j,string s,string t,vector<vector<int> > &dp)
    {
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j]) return dp[i][j] = f(i-1,j-1,s,t,dp);
        int a = 1+f(i,j-1,s,t,dp);
        int b = 1+f(i-1,j,s,t,dp);
        int c = 1+f(i-1,j-1,s,t,dp);
        
        return dp[i][j]= min(a,min(b,c));
    }
    int minDistance(string s1, string s2) 
    {
        int n1 = s1.size(),n2 = s2.size();
        vector<vector<int> > dp(n1,vector<int> (n2,-1));
        return f(n1-1,n2-1,s1,s2,dp);
    }
};