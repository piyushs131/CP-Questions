#include <bits/stdc++.h>
using namespace std;
int findAll(vector<vector<int> > &points,vector<vector<int> > &dp,int last,int ind)
{
    if(ind==0)
    {
        int ans =0;
        for(int i=0 ;i<=2 ;i++)
        {
            if(i!=last)
            {
                ans = max(ans,points[ind][i]);
            }
        }
        return ans;
    }
    if(dp[ind][last]!=-1) return dp[ind][last];

   int maxi = 0;
    for(int i=0 ; i<=2 ; i++)
    {
        if(i!=last)
        {
           int k= points[ind][i] + findAll(points,dp,i,ind-1);
           maxi = max(maxi,k);
        }
    }
    return dp[ind][last] =  maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int> > dp(n,vector<int>(4,-1));
    return findAll(points,dp,3,n-1);
}
