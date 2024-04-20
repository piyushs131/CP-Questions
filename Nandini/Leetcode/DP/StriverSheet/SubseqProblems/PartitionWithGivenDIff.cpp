#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
int allSubsets(vector<int> &arr,int ind,int sum,vector<vector<int> > &dp)
{
    if(ind==0)
    {
        if(sum==0 && arr[0]==0) return 2;
        if(sum==0 || sum==arr[0] ) return 1;
        return 0;
    }
    if(dp[ind][sum]!=-1) return dp[ind][sum];

    int notTake = allSubsets(arr,ind-1,sum,dp);
    int take = 0;
    if(sum>=arr[ind]) take = allSubsets(arr,ind-1,sum-arr[ind], dp);

    return dp[ind][sum] =( take+notTake)%mod;
}
int countPartitions(int n, int d, vector<int> &arr) 
{
    int total = 0;
    for(int i=0 ; i<n ; i++)
    total+= arr[i];

    if(total-d<0 || (total-d)%2) return false;
    int s= ( total - d )/2;
    vector<vector<int> > dp(n,vector<int> (s+1,-1));
    return allSubsets(arr,n-1,s,dp);
}


