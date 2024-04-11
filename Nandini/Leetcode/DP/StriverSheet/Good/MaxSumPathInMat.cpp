#include <bits/stdc++.h> 
using namespace std;
int MaxPath(vector<vector<int> > &mat,int i,int j,vector<vector<int> > &dp,int m)
{
    if(j<0 || j>=m) return -1e9;
    if(i==0) return mat[i][j];
    if(dp[i][j]!=-1) return dp[i][j];

    int up = mat[i][j] + MaxPath(mat,i-1,j,dp,m);
    int topRight = mat[i][j]+MaxPath(mat,i-1,j+1,dp,m);
    int topLeft = mat[i][j] + MaxPath(mat,i-1,j-1,dp,m);

    return dp[i][j] = max(up,max(topRight,topLeft) );
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(),m = matrix[0].size();
    vector<vector<int> > dp(n,vector<int> (m,-1));
    int ans = INT_MIN;
    for(int i=0 ;i<m ; i++)
    {
        ans = max(ans,MaxPath(matrix,n-1,i,dp,m));
    }
    return ans;
}