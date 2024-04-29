#include <bits/stdc++.h>
using namespace std;
long maxProfit(int ind,int buy,long *values,int n,vector<vector<long> > &dp)
{
    if(ind==n) return 0;

    if(dp[ind][buy]!=-1) return dp[ind][buy];

    long profit=0 ;
    if(buy)
    {
        profit = max(-values[ind]+maxProfit(ind+1,0,values,n,dp),maxProfit(ind+1,true,values,n,dp));
    }
    else 
    {
        profit = max(values[ind]+maxProfit(ind+1,true,values,n,dp),maxProfit(ind+1,false,values,n,dp));
    }

    return dp[ind][buy] = profit;
}
long getMaximumProfit(long *values, int n)
{
    vector<vector<long> > dp(n,vector<long>(2,-1));
    return maxProfit(0,1,values,n,dp);
}