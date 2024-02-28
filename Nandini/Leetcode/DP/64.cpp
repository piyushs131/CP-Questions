#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
      int n = grid.size(),m = grid[0].size();
        vector<vector<int> > dp(n,vector<int> (m,-1));
        return minPath(n-1,m-1,dp,grid);
    }
    int minPath(int i,int j,vector<vector<int> > &dp,vector<vector<int> > &grid)
    {
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up = grid[i][j] + minPath(i-1,j,dp,grid);
        int left = grid[i][j] + minPath(i,j-1,dp,grid);
        
        return dp[i][j] = min(up,left);
        
    }
};