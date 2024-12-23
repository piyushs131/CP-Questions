#include <bits/stdc++.h>
using namespace std;
int allWays(vector<int> &num,int ind,int t,vector<vector<int> > &dp)
{
    if(ind==0)
    {
        if(t%num[ind]==0) return t/num[ind];
        return 1e9;
    }
    if(dp[ind][t]!=-1) return dp[ind][t];

    int notTake = allWays(num,ind-1,t,dp);
    int take= INT_MAX;
    if(num[ind]<=t) take = 1+allWays(num,ind,t-num[ind],dp);

    return dp[ind][t] = min(take,notTake);
}
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int> > dp(n,vector<int> (x+1,-1));
    int ans = allWays(num,n-1,x,dp);
    return ans==1e9?-1:ans;
}