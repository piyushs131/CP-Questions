#include <bits/stdc++.h>
using namespace std;
int AllWays(vector<int> &weight,vector<int> &value,vector<vector<int> > &dp,int ind,int w)
{
	if(ind==0)
	{
		if(w>=weight[0]) return value[0];
		return 0;
	}
	if(dp[ind][w]!=-1) return dp[ind][w];
	
	int notTake = 0+AllWays(weight,value,dp,ind-1,w);
	int take= INT_MIN;
	if(w>=weight[ind]) take = value[ind] + AllWays(weight,value,dp,ind-1,w-weight[ind]);

	return dp[ind][w] = max(take,notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int> > dp(n,vector<int> (maxWeight+1,-1));
	return AllWays(weight,value,dp,n-1,maxWeight);
}