#include <bits/stdc++.h>
using namespace std;
int maxValue(vector<int> &pft,vector<int> &wt,int ind,int w,vector<vector<int> > &dp)
{
    if(ind==0)
    {
        return (w/wt[0]) * pft[0];
    }
 
    if(dp[ind][w]!=-1) return dp[ind][w];

    int notPick = maxValue(pft,wt,ind-1,w,dp);
    int pick = INT_MIN;
    if(w>=wt[ind]) pick = pft[ind]+ maxValue(pft,wt,ind,w-wt[ind],dp);

    return dp[ind][w] = max(pick,notPick);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
   vector<vector<int> > dp(n,vector<int>(w+1,-1));
   return maxValue(profit,weight,n-1,w,dp);
}