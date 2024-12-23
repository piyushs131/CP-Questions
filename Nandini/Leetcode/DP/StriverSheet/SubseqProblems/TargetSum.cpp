#include <bits/stdc++.h>
using namespace std;
int numSubsets(vector<int> &arr,int ind,int t,vector<vector<int> > &dp)
{
    if(ind==0)
    {
        if(t==arr[0] && arr[0]==0) return 2;
        if(t==0 || arr[0]==t) return 1;
        return 0;
    }

    if(dp[ind][t]!=-1) return dp[ind][t];

    int notPick = numSubsets(arr,ind-1, t, dp);
    int pick = 0;
    if(t>=arr[ind]) pick = numSubsets(arr,ind-1,t-arr[ind],dp);

    return dp[ind][t] =pick+notPick; 
}
int targetSum(int n, int target, vector<int>& arr) 
{
    int total = 0;
    for(int i=0 ; i<n ; i++)
    total+=arr[i];

    if(total-target<0 || (total-target)%2) return false;
    int sum = (total - target)/2;
     vector<vector<int> > dp(n,vector<int> (sum+1,-1));
    return numSubsets(arr,n-1,sum,dp);
}
