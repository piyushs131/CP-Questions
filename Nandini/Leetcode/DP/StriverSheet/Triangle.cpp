#include <bits/stdc++.h> 
using namespace std;
int MinPath(int n,int i,int j,vector<vector<int> > &t,vector<vector<int> > &dp)
{
	if(i==n-1) return t[i][j];
	if(dp[i][j]!=-1) return dp[i][j];

	int down = t[i][j]+MinPath(n,i+1,j,t,dp);
	int up = t[i][j]+MinPath(n,i+1,j+1,t,dp);
	return dp[i][j] = min(down,up);
}
int minimumPathSum(vector<vector<int>>& t, int n)
{
	vector<vector<int> > dp(n,vector<int> (n,-1));
	return MinPath(n,0,0,t,dp);
}
