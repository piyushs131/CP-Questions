#include <bits/stdc++.h>
using namespace std;
int MOD  = 1e9+7;
int numWays(vector<int> &arr,int ind,int sum,vector<vector<int> > &dp)
{
	if(sum==0) return 1;
	if(ind==0) return (arr[0] == sum || sum == 0) ? 1 : 0; 
    if(dp[ind][sum]!=-1) return dp[ind][sum];

	int notPick = numWays(arr,ind-1,sum,dp);
	int pick = 0;
	if (sum >= arr[ind]) {
        pick = numWays(arr, ind - 1, sum - arr[ind], dp);  
    }
    dp[ind][sum] = (pick + notPick) % MOD; 
    return dp[ind][sum];
}
int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int> > dp(n,vector<int> (k+1,-1));
	return numWays(arr,n-1,k,dp);
}