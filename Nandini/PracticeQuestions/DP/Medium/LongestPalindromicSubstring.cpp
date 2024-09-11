#include<bits/stdc++.h>
using namespace std;
class Solution {
public: 
   int start=0,end=0,maxi=0;
   bool longestSubstring(string &s,int left,int right,vector<vector<int> > &dp)
   {
     if(left>=right) return 1;
     if(dp[left][right]!=-1) return dp[left][right];

     if(s[left]==s[right] && longestSubstring(s,left+1,right-1,dp))
     {
        if(right-left>=maxi)
        {
            maxi = right-left;
            start = left,end = right;
        }
        return dp[left][right]=1;
     }
     longestSubstring(s,left+1,right,dp);
     longestSubstring(s,left,right-1,dp);
     return dp[left][right] =0;
   }
    string longestPalindrome(string s) 
    {
      int n = s.size();
      vector<vector<int> > dp(n+1,vector<int> (n+1,-1));
      longestSubstring(s,0,n-1,dp);
      string final = "";
      for(int i=start;i<=end; i++) final+=s[i];
      return final;  
    }
};