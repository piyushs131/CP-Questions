#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int total(int n,vector<int> &dp)
    {
        if(n==0)
        return 1;

        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];

        return dp[n] = total(n-1,dp) +total(n-2,dp);
        
    }
    int climbStairs(int n) 
    {
        vector<int> dp(n+1,-1);
       return total(n,dp);
    }
};