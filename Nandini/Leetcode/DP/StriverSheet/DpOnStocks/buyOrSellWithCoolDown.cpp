#include <bits/stdc++.h>
using namespace std;
int f(int ind,int buy,vector<int> &arr,vector<vector<int> > &dp,int n)
{ 
    if(ind>=n) return 0;
    if(dp[ind][buy]!=-1) return dp[ind][buy];

    if(buy)
    return dp[ind][buy] = max(-arr[ind]+f(ind+1,0,arr,dp,n),f(ind+1,1,arr,dp,n));
    else 
    return dp[ind][buy] = max(arr[ind]+f(ind+2,1,arr,dp,n),f(ind+1,0,arr,dp,n));
}
int stockProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int> > dp(n,vector<int> (2,-1));
    return f(0,1,prices,dp,n);
}