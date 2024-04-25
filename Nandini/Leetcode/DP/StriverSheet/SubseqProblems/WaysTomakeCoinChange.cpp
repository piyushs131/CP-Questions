#include <bits/stdc++.h>
using namespace std;
long totalWays(int *arr,int ind,int t,vector<vector<long> > &dp)
{
    if(ind==0)
    {
        return (t%arr[ind]==0);
    }

    if(dp[ind][t]!=-1) return dp[ind][t];

    long  notTake = totalWays(arr,ind-1,t,dp);
    long take = 0;
    if(t>=arr[ind]) take = totalWays(arr,ind,t-arr[ind],dp);

    return dp[ind][t]= notTake + take;
}
long countWaysToMakeChange(int *demos, int n, int value)
{
    vector<vector<long> > dp(n,vector<long> (value+1,-1));
    return totalWays(demos,n-1,value,dp);
}