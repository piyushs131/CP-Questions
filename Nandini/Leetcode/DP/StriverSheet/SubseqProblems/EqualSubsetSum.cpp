#include <bits/stdc++.h>
using namespace std;
bool checkSub(vector<int> &arr,int ind,int k,vector<vector<int> > &dp)
{
    if(k==0) return true;
	if(ind==0) return arr[0]==k;
	if(dp[ind][k]!=-1) return dp[ind][k];

	bool notTake = checkSub(arr,ind-1,k,dp);
	bool take = false;
	if(arr[ind]<=k) take = checkSub(arr,ind-1,k-arr[ind], dp);

	return dp[ind][k] = take | notTake;
}
bool canPartition(vector<int> &arr, int n)
{
   int total = 0;
   for(int i=0 ; i<n ; i++)total+= arr[i];

   if(total%2!=0) return false;
   vector<vector<int> > dp(n,vector<int> (total/2+1,-1));
   return checkSub(arr,n-1,total/2,dp);
}
