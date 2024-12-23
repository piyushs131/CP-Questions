#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
class Solution {
  public:
    
    int findAll(string &str,int ind,vector<vector<ll> > &dp,char last_char)
    {
        if(ind>=str.length())return 1;
        if(dp[ind][last_char-'a']!=-1) return dp[ind][last_char-'a'];
        
        // not pick 
        ll ans = findAll(str,ind+1,dp,last_char);
        // pick
        if(str[ind]>=last_char)
        {
           ans += findAll(str,ind+1,dp,str[ind]);
           ans = ans%mod;
        }
    
        return dp[ind][last_char-'a'] = ans;
    }
    int cntExotic(string S) 
    {
        int n = S.size();
        vector<vector<ll> > dp(n,vector<ll> (26,-1));
        return findAll(S,0,dp,'a')-1;
    }
};