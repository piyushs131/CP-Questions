#include <bits/stdc++.h>
using namespace std;
string findLCS(int n, int m,string &s1, string &s2)
{
	vector<vector<int> > dp(n+1,vector<int> (m+1,-1));
	for(int i=0 ; i<=n ; i++)dp[i][0] = 0;
	for(int j=0 ; j<=m ; j++)dp[0][j] = 0;

	for(int i=1 ; i<=n ; i++)
	{
		for(int j=1 ; j<=m ; j++)
		{
			if(s1[i-1]==s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
			else 
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}	

	int i=n ,j=m,index = 0;
	string ans ="";
	for(int k=0 ; k<dp[n][m] ; k++)
	ans+='$';

	index = dp[n][m]-1;

	while(i>0 && j>0)
	{
		if(s1[i-1]==s2[j-1]) 
		{
			ans[index] = s1[i-1];
			index--;
			i--;
			j--;
		}
		else if(dp[i][j-1] < dp[i-1][j])
		i--;
		else
		j--;
	}
	return ans;
}