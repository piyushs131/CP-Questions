#include <bits/stdc++.h> 
using namespace std;
int findMax(int n,int m,vector<vector<int> > &grid,int i,int j1,int j2,vector<vector<vector<int> > > &dp)
{
    if(j1<0 || j2<0 || j1>=m || j2>=m) return -1e8;
    if(i==n-1)
    {
       if(j1==j2) return grid[i][j1] ;
       return grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    int maxi = -1e8;
    for(int d1=-1 ; d1<=1 ; d1++)
    {
        for(int d2=-1 ; d2<=1 ; d2++)
        {
            if(j1==j2)
            maxi = max(maxi,grid[i][j1] +findMax(n,m,grid,i+1,j1+d1,j2+d2,dp));
            else 
            maxi = max(maxi,grid[i][j1] + grid[i][j2] + findMax(n,m,grid,i+1,j1+d1,j2+d2,dp));
        }
    }

    return dp[i][j1][j2] = maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) 
{
    vector<vector<vector<int> > > dp(r,vector<vector<int> > (c,vector<int> (c,-1)));
    return findMax(r,c,grid,0,0,c-1,dp);
}