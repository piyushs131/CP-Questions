#include <bits/stdc++.h>
using namespace std;
int maxPrice(vector<int> &price,int ind,int N,vector<vector<int> > &dp)
{
	if(ind==0)
    return N*price[0];

	if(dp[ind][N]!=-1) return dp[ind][N];
	int notPick = maxPrice(price,ind-1,N,dp);
	int pick = INT_MIN;
	int rodlength = ind+1;
	if(ind+1<=N) pick = price[ind]+maxPrice(price,ind,N-rodlength,dp);

	return dp[ind][N] = max(pick,notPick);
}
int cutRod(vector<int> &price, int n)
{
	vector<vector<int> > dp(n,vector<int> (n+1,-1));
	return maxPrice(price,n-1,n,dp);
}
