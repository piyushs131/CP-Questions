#include <bits/stdc++.h>
using namespace std;
int findAll(vector<int> &height,vector<int> &dp,int k,int ind)
{
    if(ind<=0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int mini = INT_MAX;
    for(int i=1 ;i<=k ; i++)
    {
         if(ind-i >=0)
         {
            int cost = abs(height[ind]-height[ind-i]) + findAll(height,dp,k,ind-i);
            mini = min(mini,cost);
         }
         
    }
    return dp[ind] = mini;
}
int minimizeCost(int n, int k, vector<int> &height)
{
    vector<int> dp(n+1,-1);
    return findAll(height,dp,k,n-1);
}