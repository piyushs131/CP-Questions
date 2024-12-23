#include <bits/stdc++.h> 
using namespace std;
int allPaths(int m,int n,vector<vector<int> > &dp)
{
	if(m==0 && n==0) return 1;
	if(dp[m][n]!=-1) return dp[m][n];
	int p1=0,p2=0;
	if(m-1>=0)
	 p1 = allPaths(m-1,n,dp);
	if(n-1>=0)
	 p2 = allPaths(m,n-1,dp);
	return dp[m][n] = p1+p2;
}
int uniquePaths(int m, int n) 
{
	vector<vector<int> > dp(m,vector<int> (n,-1));
	return allPaths(m-1,n-1,dp);
}
