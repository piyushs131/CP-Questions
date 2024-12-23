#include <bits/stdc++.h>
using namespace std;
int minSum(vector<vector<int> > &grid,vector<vector<int> > &dp,int n,int m)
{
    if(n==0 && m==0) return grid[0][0];
    if(n<0 || m<0) return INT_MAX;
    if(dp[n][m]!=-1) return dp[n][m];

    int f1 =  minSum(grid,dp,n-1,m);
    int f2 =  minSum(grid,dp,n,m-1);
    return dp[n][m]= grid[n][m]+min(f1,f2);
}
int minSumPath(vector<vector<int>> &grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int> > dp(n,vector<int> (m,-1));
    return minSum(grid,dp,n-1,m-1);
}